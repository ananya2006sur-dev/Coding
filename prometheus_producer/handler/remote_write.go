package handler

import (
	"io"
	"net/http"

	"github.com/gogo/protobuf/proto"
	"github.com/golang/snappy"
	"github.com/ananya/prometheus_producer/logger"
	"github.com/ananya/prometheus_producer/output"
	"github.com/prometheus/prometheus/prompb"
)

type RemoteWriteHandler struct {
	outputs []output.Output
}

func NewRemoteWriteHandler(outputs []output.Output) *RemoteWriteHandler {
	return &RemoteWriteHandler{outputs: outputs}
}

func (h *RemoteWriteHandler) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "method not allowed", http.StatusMethodNotAllowed)
		return
	}

	compressed, err := io.ReadAll(r.Body)
	if err != nil {
		logger.Error("remote_write: read body: %v", err)
		http.Error(w, "cannot read body", http.StatusBadRequest)
		return
	}
	defer r.Body.Close()

	rawBytes, err := snappy.Decode(nil, compressed)
	if err != nil {
		logger.Error("remote_write: snappy decode: %v", err)
		http.Error(w, "cannot decompress body", http.StatusBadRequest)
		return
	}

	var wr prompb.WriteRequest
	if err := proto.Unmarshal(rawBytes, &wr); err != nil {
		logger.Error("remote_write: protobuf unmarshal: %v", err)
		http.Error(w, "cannot unmarshal protobuf", http.StatusBadRequest)
		return
	}

	logger.Debug("remote_write: received %d timeseries", len(wr.Timeseries))

	ctx := r.Context()
	for _, out := range h.outputs {
		go func(o output.Output) {
			if err := o.Write(ctx, compressed, &wr); err != nil {
				logger.Error("%s output error: %v", o.Name(), err)
			}
		}(out)
	}

	w.WriteHeader(http.StatusNoContent)
}
