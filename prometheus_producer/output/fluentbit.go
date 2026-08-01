package output

import (
	"context"
	"fmt"
	"net"
	"time"

	"github.com/ananya/prometheus_producer/config"
	"github.com/fluent/fluent-logger-golang/fluent"
	"github.com/prometheus/prometheus/prompb"
)

type FluentbitOutput struct {
	logger *fluent.Fluent
	tag    string
}

func NewFluentbitOutput(cfg *config.FluentbitConfig) (*FluentbitOutput, error) {
	// Reachability check before opening persistent connection.
	addr := net.JoinHostPort(cfg.Host, fmt.Sprintf("%d", cfg.Port))
	conn, err := net.DialTimeout("tcp", addr, 5*time.Second)
	if err != nil {
		return nil, fmt.Errorf("fluentbit output: cannot reach %s: %w", addr, err)
	}
	conn.Close()

	f, err := fluent.New(fluent.Config{
		FluentHost:    cfg.Host,
		FluentPort:    cfg.Port,
		Async:         false,
		MarshalAsJSON: true,
	})
	if err != nil {
		return nil, fmt.Errorf("fluentbit output: create client: %w", err)
	}

	return &FluentbitOutput{logger: f, tag: cfg.Tag}, nil
}

func (fb *FluentbitOutput) Name() string { return "fluentbit" }

func (fb *FluentbitOutput) Write(_ context.Context, _ []byte, wr *prompb.WriteRequest) error {
	for _, ts := range wr.Timeseries {
		labels := make(map[string]string, len(ts.Labels))
		for _, l := range ts.Labels {
			labels[l.Name] = l.Value
		}

		samples := make([]map[string]any, 0, len(ts.Samples))
		for _, s := range ts.Samples {
			samples = append(samples, map[string]any{
				"value":     s.Value,
				"timestamp": s.Timestamp,
			})
		}

		record := map[string]any{
			"labels":  labels,
			"samples": samples,
		}

		if err := fb.logger.Post(fb.tag, record); err != nil {
			return fmt.Errorf("fluentbit output: post: %w", err)
		}
	}
	return nil
}

func (fb *FluentbitOutput) Close() error {
	return fb.logger.Close()
}
