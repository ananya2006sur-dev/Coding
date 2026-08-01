package output

import (
	"context"

	"github.com/prometheus/prometheus/prompb"
)

// Output is the interface every output target must implement.
type Output interface {
	Name() string
	Write(ctx context.Context, rawBytes []byte, wr *prompb.WriteRequest) error
	Close() error
}
