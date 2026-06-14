package output

import (
	"context"
	"encoding/json"
	"fmt"
	"os"
	"path/filepath"
	"sync"

	"github.com/ananya/prometheus_producer/config"
	"github.com/prometheus/prometheus/prompb"
)

type FileOutput struct {
	mu   sync.Mutex
	file *os.File
}

type fileTimeSeries struct {
	Labels  []fileLabel   `json:"labels"`
	Samples []fileSample  `json:"samples"`
}

type fileLabel struct {
	Name  string `json:"name"`
	Value string `json:"value"`
}

type fileSample struct {
	Value     float64 `json:"value"`
	Timestamp int64   `json:"timestamp"`
}

func NewFileOutput(cfg *config.FileConfig) (*FileOutput, error) {
	dir := filepath.Dir(cfg.Path)
	info, err := os.Stat(dir)
	if err != nil {
		return nil, fmt.Errorf("file output: parent directory %q does not exist: %w", dir, err)
	}
	if !info.IsDir() {
		return nil, fmt.Errorf("file output: %q is not a directory", dir)
	}

	// Verify writability with a probe.
	probe, err := os.OpenFile(cfg.Path, os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0o644)
	if err != nil {
		return nil, fmt.Errorf("file output: cannot open %q for writing: %w", cfg.Path, err)
	}

	return &FileOutput{file: probe}, nil
}

func (f *FileOutput) Name() string { return "file" }

func (f *FileOutput) Write(_ context.Context, _ []byte, wr *prompb.WriteRequest) error {
	f.mu.Lock()
	defer f.mu.Unlock()

	for _, ts := range wr.Timeseries {
		rec := fileTimeSeries{
			Labels:  make([]fileLabel, 0, len(ts.Labels)),
			Samples: make([]fileSample, 0, len(ts.Samples)),
		}
		for _, l := range ts.Labels {
			rec.Labels = append(rec.Labels, fileLabel{Name: l.Name, Value: l.Value})
		}
		for _, s := range ts.Samples {
			rec.Samples = append(rec.Samples, fileSample{Value: s.Value, Timestamp: s.Timestamp})
		}

		line, err := json.Marshal(rec)
		if err != nil {
			return fmt.Errorf("file output: marshal timeseries: %w", err)
		}
		line = append(line, '\n')

		if _, err := f.file.Write(line); err != nil {
			return fmt.Errorf("file output: write: %w", err)
		}
	}
	return nil
}

func (f *FileOutput) Close() error {
	f.mu.Lock()
	defer f.mu.Unlock()
	return f.file.Close()
}
