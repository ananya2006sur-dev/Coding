package main

import (
	"context"
	"flag"
	"fmt"
	"net/http"
	"os"
	"os/signal"
	"syscall"
	"time"

	"github.com/ananya/prometheus_producer/config"
	"github.com/ananya/prometheus_producer/handler"
	"github.com/ananya/prometheus_producer/logger"
	"github.com/ananya/prometheus_producer/output"
)

func main() {
	configPath := flag.String("config", "config.yaml", "path to config file")
	flag.Parse()

	cfg, err := config.Load(*configPath)
	if err != nil {
		fmt.Fprintf(os.Stderr, "ERROR: %v\n", err)
		os.Exit(1)
	}

	logger.SetLevel(cfg.LogLevel)
	logger.Info("log level: %s", cfg.LogLevel)

	outputs, err := buildOutputs(cfg)
	if err != nil {
		fmt.Fprintf(os.Stderr, "ERROR: %v\n", err)
		os.Exit(1)
	}
	defer closeOutputs(outputs)

	mux := http.NewServeMux()
	mux.Handle("/receive", handler.NewRemoteWriteHandler(outputs))

	srv := &http.Server{
		Addr:    fmt.Sprintf(":%d", cfg.Server.Port),
		Handler: mux,
	}

	quit := make(chan os.Signal, 1)
	signal.Notify(quit, syscall.SIGINT, syscall.SIGTERM)

	go func() {
		logger.Info("server listening on :%d", cfg.Server.Port)
		if err := srv.ListenAndServe(); err != nil && err != http.ErrServerClosed {
			fmt.Fprintf(os.Stderr, "ERROR: server: %v\n", err)
			os.Exit(1)
		}
	}()

	<-quit
	logger.Info("shutdown signal received")

	ctx, cancel := context.WithTimeout(context.Background(), 15*time.Second)
	defer cancel()
	if err := srv.Shutdown(ctx); err != nil {
		logger.Error("server shutdown: %v", err)
	}

	logger.Info("shutdown complete")
}

func buildOutputs(cfg *config.Config) ([]output.Output, error) {
	var outputs []output.Output

	if cfg.IsActive("kafka") {
		logger.Info("initializing kafka output")
		k, err := output.NewKafkaOutput(&cfg.Outputs.Kafka)
		if err != nil {
			return nil, fmt.Errorf("kafka output: %w", err)
		}
		outputs = append(outputs, k)
		logger.Info("kafka output ready (brokers: %v, topic: %s)", cfg.Outputs.Kafka.Brokers, cfg.Outputs.Kafka.Topic)
	}

	if cfg.IsActive("http") {
		logger.Info("initializing http output")
		h, err := output.NewHTTPOutput(&cfg.Outputs.HTTP)
		if err != nil {
			return nil, fmt.Errorf("http output: %w", err)
		}
		outputs = append(outputs, h)
		logger.Info("http output ready (endpoint: %s)", cfg.Outputs.HTTP.Endpoint)
	}

	if cfg.IsActive("file") {
		logger.Info("initializing file output")
		f, err := output.NewFileOutput(&cfg.Outputs.File)
		if err != nil {
			return nil, fmt.Errorf("file output: %w", err)
		}
		outputs = append(outputs, f)
		logger.Info("file output ready (path: %s)", cfg.Outputs.File.Path)
	}

	if cfg.IsActive("fluentbit") {
		logger.Info("initializing fluentbit output")
		fb, err := output.NewFluentbitOutput(&cfg.Outputs.Fluentbit)
		if err != nil {
			return nil, fmt.Errorf("fluentbit output: %w", err)
		}
		outputs = append(outputs, fb)
		logger.Info("fluentbit output ready (%s:%d tag=%s)", cfg.Outputs.Fluentbit.Host, cfg.Outputs.Fluentbit.Port, cfg.Outputs.Fluentbit.Tag)
	}

	return outputs, nil
}

func closeOutputs(outputs []output.Output) {
	for _, o := range outputs {
		if err := o.Close(); err != nil {
			logger.Error("close %s output: %v", o.Name(), err)
		}
	}
}
