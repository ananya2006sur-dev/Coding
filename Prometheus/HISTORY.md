# Prometheus Remote Write Tester — History

## 2026-06-14 — Initial Build

**Purpose:** Lightweight Go tool to test `prometheus_producer` by sending synthetic metrics via Prometheus Remote Write protocol.

**What was built:**
- `main.go` — sends three synthetic metrics (gauge, counter, sine wave) to a configurable remote write endpoint
- `go.mod` / `go.sum` — Go module with dependencies on `prometheus/prometheus`, `gogo/protobuf`, and `golang/snappy`
- Binary: `prometheus-rw-tester.exe` (~9.5 MB)

**Key decisions:**
- Uses `github.com/prometheus/prometheus/prompb` for the `WriteRequest` protobuf type — identical wire format to a real Prometheus server
- Uses `gogo/protobuf` for marshalling (required by `prompb`, not `google.golang.org/protobuf`)
- Snappy compression + `Content-Encoding: snappy` header matches the Prometheus remote write spec (version 0.1.0)

**Dependencies:**

| Package | Version | Role |
|---|---|---|
| `github.com/prometheus/prometheus` | v0.53.1 | `prompb.WriteRequest` type |
| `github.com/gogo/protobuf` | v1.3.2 | Protobuf marshalling |
| `github.com/golang/snappy` | v0.0.4 | Compression |

**Metrics sent:**

| Metric name | Type | Value pattern | Labels |
|---|---|---|---|
| `test_gauge` | gauge | Sawtooth 0→148.5, repeats every 100 batches | `job=rw_tester, instance=local` |
| `test_counter_total` | counter | Monotonically increasing (`batch * 10`) | `job=rw_tester, instance=local` |
| `test_sine` | gauge | Sine wave, range 0–100 | `job=rw_tester, instance=local` |

**CLI flags:**

| Flag | Default | Description |
|---|---|---|
| `-addr` | `http://localhost:9201/api/v1/write` | Remote write endpoint URL |
| `-interval` | `5s` | Delay between batches |
| `-count` | `0` (run forever) | Stop after N batches (0 = infinite) |

**Example usage:**
```bash
# Run forever against a remote host
.\prometheus-rw-tester.exe -addr http://192.168.1.100:9201/api/v1/write

# Send 20 batches every 2 seconds
.\prometheus-rw-tester.exe -addr http://192.168.1.100:9201/api/v1/write -interval 2s -count 20
```
