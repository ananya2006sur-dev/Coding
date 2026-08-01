package output

import (
	"bytes"
	"context"
	"fmt"
	"net/http"
	"time"

	"github.com/ananya/prometheus_producer/config"
	"github.com/prometheus/prometheus/prompb"
)

type HTTPOutput struct {
	endpoint string
	client   *http.Client
}

func NewHTTPOutput(cfg *config.HTTPConfig) (*HTTPOutput, error) {
	return &HTTPOutput{
		endpoint: cfg.Endpoint,
		client:   &http.Client{Timeout: 10 * time.Second},
	}, nil
}

func (h *HTTPOutput) Name() string { return "http" }

func (h *HTTPOutput) Write(ctx context.Context, rawBytes []byte, _ *prompb.WriteRequest) error {
	req, err := http.NewRequestWithContext(ctx, http.MethodPost, h.endpoint, bytes.NewReader(rawBytes))
	if err != nil {
		return fmt.Errorf("build request: %w", err)
	}
	req.Header.Set("Content-Type", "application/x-protobuf")
	req.Header.Set("Content-Encoding", "snappy")

	resp, err := h.client.Do(req)
	if err != nil {
		return fmt.Errorf("POST to %s: %w", h.endpoint, err)
	}
	defer resp.Body.Close()

	if resp.StatusCode < 200 || resp.StatusCode >= 300 {
		return fmt.Errorf("POST to %s returned HTTP %d", h.endpoint, resp.StatusCode)
	}
	return nil
}

func (h *HTTPOutput) Close() error { return nil }
