# Prometheus Remote Write Producer — Design Document

## Overview

`prometheus_producer` is a Go application that acts as a Prometheus Remote Write receiver. It accepts incoming metric payloads via the Prometheus Remote Write protocol and fans them out to one or more configurable output targets: Kafka, HTTP, File, and Fluentbit Forward.

---

## Directory Structure

```
prometheus_producer/
├── main.go
├── config/
│   └── config.go          # Config struct + loader
├── handler/
│   └── remote_write.go    # HTTP handler for /receive
├── output/
│   ├── output.go          # Output interface + fan-out dispatcher
│   ├── kafka.go           # Kafka async producer
│   ├── http.go            # HTTP POST output
│   ├── file.go            # File output
│   └── fluentbit.go       # Fluentbit Forward output
├── logger/
│   └── logger.go          # Leveled logger
├── config.yaml            # Application configuration file
├── go.mod
├── go.sum
└── DESIGN.md
```

---

## Configuration File (`config.yaml`)

The application reads all runtime parameters from `config.yaml` (path configurable via `--config` CLI flag, default `./config.yaml`).

```yaml
server:
  port: 9090                         # Port to listen for Prometheus Remote Write requests

log_level: INFO                      # One of: DEBUG, INFO, WARN, ERROR

outputs:
  active:                            # List of active output methods
    - kafka
    - http
    # - file
    # - fluentbit

  kafka:
    brokers:
      - "broker1.example.com:9092"
      - "broker2.example.com:9092"
    topic: "prometheus-metrics"
    protocol: ssl                    # "ssl" or "plain"
    ssl:
      ca_pem: "/etc/certs/ca.pem"
      cert_pem: "/etc/certs/client.pem"
      key_pem: "/etc/certs/client.key.pem"

  http:
    endpoint: "http://downstream.example.com/ingest"

  file:
    path: "/var/log/prometheus_producer/metrics.log"

  fluentbit:
    host: "127.0.0.1"
    port: 24224
    tag: "prometheus.metrics"
```

### Configuration Rules

| Field | Required when | Notes |
|---|---|---|
| `server.port` | Always | Must be a valid TCP port (1–65535) |
| `log_level` | Always | Case-insensitive; defaults to `INFO` if omitted |
| `outputs.active` | Always | At least one entry required |
| `outputs.kafka.*` | `kafka` in `active` | All sub-fields required including SSL fields if `protocol: ssl` |
| `outputs.http.endpoint` | `http` in `active` | Must be a valid URL |
| `outputs.file.path` | `file` in `active` | Must be an absolute path |
| `outputs.fluentbit.host/port/tag` | `fluentbit` in `active` | All three required |

---

## Startup Validation

On startup, before binding any port, the application performs the following checks in order:

1. Parse and validate `config.yaml`. Any YAML syntax error → log to stderr + exit(1).
2. Validate `server.port` is in range.
3. Validate `log_level` is one of the four allowed values.
4. For each entry in `outputs.active`, verify that the corresponding configuration block is present and complete. If any required field is missing → write descriptive error to **stderr** → `exit(1)`.
5. For Kafka: attempt to create the async producer connection. If the topic does not exist on the brokers, log a `WARN` and continue (do not exit).
6. For File: verify the parent directory exists and is writable. If not → stderr + exit(1).
7. For Fluentbit: verify the host/port are resolvable/reachable with a short dial timeout. Failure → stderr + exit(1).

The application **only starts listening** after all validations pass.

---

## Logging

### Levels (in ascending severity)

| Level | Value | Usage |
|---|---|---|
| `DEBUG` | 0 | Detailed internal state, per-message tracing |
| `INFO`  | 1 | Startup, shutdown, configuration summary |
| `WARN`  | 2 | Non-fatal anomalies (e.g. Kafka topic missing) |
| `ERROR` | 3 | Failures that affect output but not uptime |

Only one level is active at a time. Messages at the configured level **and above** are emitted; messages below are suppressed.

### Format

```
2026-06-14T10:23:45Z [INFO]  Server listening on :9090
2026-06-14T10:23:45Z [WARN]  Kafka topic "prometheus-metrics" not found on brokers
2026-06-14T10:23:46Z [ERROR] HTTP output failed: connection refused
```

All log output goes to **stderr**.

---

## HTTP Server — Prometheus Remote Write Endpoint

| Property | Value |
|---|---|
| Method | `POST` |
| Path | `/receive` |
| Content-Type | `application/x-protobuf` |
| Encoding | Snappy-compressed Protobuf (`prometheus.WriteRequest`) |

### Request Handling Flow

```
Client (Prometheus / any RW sender)
        │
        ▼
  POST /receive
        │
        ▼
  Decompress (snappy)
        │
        ▼
  Unmarshal Protobuf  →  prometheus.WriteRequest
        │
        ▼
  Fan-out dispatcher  ──────────────────────────────┐
        │                                            │
        ▼                                            ▼
  [active output 1]                        [active output N]
  (goroutines, non-blocking)
        │
        ▼
  Respond 204 No Content
```

The handler responds `204 No Content` as soon as the fan-out goroutines are launched. Output errors are logged but do not affect the HTTP response to Prometheus.

---

## Output Targets

### 1. Kafka

- **Library**: `github.com/IBM/sarama` (successor to `Shopify/sarama`)
- **Producer mode**: Async producer (`sarama.AsyncProducer`)
- **Acknowledgement**: `config.Producer.RequiredAcks = sarama.NoResponse` — pure fire-and-forget
- **Success/Error channels**: Both are drained by a background goroutine but **neither triggers any action** (no retry, no logging of individual message success/failure)
- **Topic existence check**: Performed once at startup using the Kafka metadata API. If the topic is absent, a `WARN` is logged and the application continues. The async producer will silently drop messages destined for a non-existent topic.
- **SSL/TLS**: When `protocol: ssl`, the `sarama.Config.Net.TLS` is populated from the PEM files specified in config. Plain text requires no TLS config.
- **Serialization**: The raw snappy-compressed protobuf bytes from the Remote Write request are written as the Kafka message `Value`. The `Key` is empty.

#### SSL Config Details

| Config field | Source |
|---|---|
| `Net.TLS.Enable` | `true` when `protocol: ssl` |
| `Net.TLS.Config.RootCAs` | Loaded from `ssl.ca_pem` |
| `Net.TLS.Config.Certificates` | Loaded from `ssl.cert_pem` + `ssl.key_pem` |
| `Net.SASL.Enable` | `false` (not required by design) |

---

### 2. HTTP

- **Method**: `POST`
- **Body**: Raw snappy-compressed protobuf bytes (same as received)
- **Headers**:
  - `Content-Type: application/x-protobuf`
  - `Content-Encoding: snappy`
- **Client**: `net/http` with a configurable timeout (hardcoded default: 10 s)
- **Error handling**: On non-2xx response or network error, log at `ERROR` level; do not retry; do not affect other outputs.

---

### 3. File

- **Mode**: Append-only (`os.OpenFile` with `O_APPEND | O_CREATE | O_WRONLY`)
- **Format**: One JSON object per line (newline-delimited JSON / NDJSON). Each line represents one `TimeSeries` from the `WriteRequest`:

```json
{"labels":[{"name":"__name__","value":"up"},{"name":"job","value":"node"}],"samples":[{"value":1,"timestamp":1718356800000}]}
```

- **Serialization**: The `prometheus.WriteRequest` protobuf is decoded in memory and each `TimeSeries` is marshalled to JSON individually.
- **File handle**: Opened once at startup and kept open for the lifetime of the process. Closed on graceful shutdown (`SIGINT` / `SIGTERM`).
- **Error handling**: Write errors logged at `ERROR`; file output failures do not affect other outputs.

---

### 4. Fluentbit Forward

- **Protocol**: [Fluent Forward Protocol v1](https://github.com/fluent/fluentd/wiki/Forward-Protocol-Specification-v1) over TCP
- **Library**: `github.com/fluent/fluent-logger-golang/fluent`
- **Tag**: Value from `outputs.fluentbit.tag` in config
- **Payload**: Each `TimeSeries` from the `WriteRequest` is sent as a separate Forward message. The record is a `map[string]interface{}` with keys `labels` and `samples`.
- **Connection**: A persistent TCP connection is maintained. The fluent-logger-golang library handles reconnection automatically.
- **Error handling**: Send errors logged at `ERROR`; failure on one series does not stop others.

---

## Fan-out Dispatcher

```go
type Output interface {
    Name() string
    Write(ctx context.Context, data []byte, wr *prompb.WriteRequest) error
}
```

The dispatcher holds a slice of active `Output` implementations populated at startup. On each incoming request it launches one goroutine per output:

```go
for _, out := range outputs {
    go func(o Output) {
        if err := o.Write(ctx, rawBytes, writeRequest); err != nil {
            logger.Error("output %s failed: %v", o.Name(), err)
        }
    }(out)
}
```

This ensures one slow or failing output never blocks others or the HTTP response.

---

## Graceful Shutdown

On `SIGINT` or `SIGTERM`:
1. Stop accepting new HTTP connections (`http.Server.Shutdown` with a 15 s deadline).
2. Close the Kafka async producer (flushes internal buffer, closes connection).
3. Close the file handle.
4. Close the Fluentbit TCP connection.
5. Log `INFO: shutdown complete` and exit(0).

---

## Dependencies (`go.mod`)

| Package | Purpose |
|---|---|
| `github.com/prometheus/prometheus` | `prompb.WriteRequest` protobuf types |
| `github.com/golang/snappy` | Snappy decompression |
| `google.golang.org/protobuf` | Protobuf marshal/unmarshal |
| `github.com/IBM/sarama` | Kafka async producer |
| `github.com/fluent/fluent-logger-golang` | Fluentbit Forward output |
| `gopkg.in/yaml.v3` | Config file parsing |

---

## Error & Exit Code Summary

| Situation | Behaviour | Exit code |
|---|---|---|
| Missing/malformed config file | Log to stderr | 1 |
| Active output missing config | Log to stderr | 1 |
| File output parent dir not writable | Log to stderr | 1 |
| Fluentbit host unreachable at startup | Log to stderr | 1 |
| Kafka topic not found at startup | `WARN` to stderr, continue | — |
| Kafka write failure (runtime) | `ERROR` log | — |
| HTTP output write failure (runtime) | `ERROR` log | — |
| File write failure (runtime) | `ERROR` log | — |
| Fluentbit send failure (runtime) | `ERROR` log | — |
| SIGINT / SIGTERM | Graceful shutdown | 0 |

---

## Non-Goals (Out of Scope for This Design)

- Metric filtering or transformation before forwarding
- Retry logic / dead-letter queue for failed outputs
- TLS on the inbound HTTP listener
- Authentication on the inbound HTTP listener
- Prometheus metrics about the producer itself
