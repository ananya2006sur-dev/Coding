package main

import (
	"bytes"
	"flag"
	"fmt"
	"log"
	"math"
	"net/http"
	"time"

	"github.com/golang/snappy"
	"github.com/gogo/protobuf/proto"
	"github.com/prometheus/prometheus/prompb"
)

func main() {
	addr := flag.String("addr", "http://localhost:9201/api/v1/write", "Remote write endpoint (e.g. http://1.2.3.4:9201/api/v1/write)")
	interval := flag.Duration("interval", 5*time.Second, "How often to send metrics")
	count := flag.Int("count", 0, "Number of batches to send (0 = run forever)")
	flag.Parse()

	log.Printf("Sending metrics to %s every %s", *addr, *interval)

	client := &http.Client{Timeout: 10 * time.Second}

	for i := 0; *count == 0 || i < *count; i++ {
		if err := sendMetrics(client, *addr, i); err != nil {
			log.Printf("ERROR batch %d: %v", i, err)
		} else {
			log.Printf("OK    batch %d sent", i)
		}
		if *count == 0 || i < *count-1 {
			time.Sleep(*interval)
		}
	}
}

func sendMetrics(client *http.Client, addr string, batch int) error {
	now := time.Now().UnixMilli()

	// Sawtooth wave so values change visibly each batch.
	gaugeVal := float64(batch%100) * 1.5
	counterVal := float64(batch) * 10

	req := &prompb.WriteRequest{
		Timeseries: []prompb.TimeSeries{
			makeTS("test_gauge", map[string]string{"job": "rw_tester", "instance": "local"}, gaugeVal, now),
			makeTS("test_counter_total", map[string]string{"job": "rw_tester", "instance": "local"}, counterVal, now),
			makeTS("test_sine", map[string]string{"job": "rw_tester", "instance": "local"},
				50+50*math.Sin(float64(batch)*0.3), now),
		},
	}

	data, err := proto.Marshal(req)
	if err != nil {
		return fmt.Errorf("marshal: %w", err)
	}
	compressed := snappy.Encode(nil, data)

	httpReq, err := http.NewRequest(http.MethodPost, addr, bytes.NewReader(compressed))
	if err != nil {
		return fmt.Errorf("new request: %w", err)
	}
	httpReq.Header.Set("Content-Encoding", "snappy")
	httpReq.Header.Set("Content-Type", "application/x-protobuf")
	httpReq.Header.Set("X-Prometheus-Remote-Write-Version", "0.1.0")

	resp, err := client.Do(httpReq)
	if err != nil {
		return fmt.Errorf("http: %w", err)
	}
	defer resp.Body.Close()

	if resp.StatusCode/100 != 2 {
		return fmt.Errorf("server returned %s", resp.Status)
	}
	return nil
}

func makeTS(name string, labels map[string]string, value float64, tsMs int64) prompb.TimeSeries {
	lbls := []prompb.Label{{Name: "__name__", Value: name}}
	for k, v := range labels {
		lbls = append(lbls, prompb.Label{Name: k, Value: v})
	}
	return prompb.TimeSeries{
		Labels:  lbls,
		Samples: []prompb.Sample{{Value: value, Timestamp: tsMs}},
	}
}
