package output

import (
	"context"
	"crypto/tls"
	"crypto/x509"
	"fmt"
	"os"

	"github.com/IBM/sarama"
	"github.com/ananya/prometheus_producer/config"
	"github.com/ananya/prometheus_producer/logger"
	"github.com/prometheus/prometheus/prompb"
)

type KafkaOutput struct {
	producer sarama.AsyncProducer
	topic    string
}

func NewKafkaOutput(cfg *config.KafkaConfig) (*KafkaOutput, error) {
	scfg := sarama.NewConfig()
	scfg.Producer.RequiredAcks = sarama.NoResponse
	scfg.Producer.Return.Successes = false
	scfg.Producer.Return.Errors = false

	if cfg.Protocol == "ssl" {
		tlsCfg, err := buildTLSConfig(cfg)
		if err != nil {
			return nil, fmt.Errorf("kafka TLS config: %w", err)
		}
		scfg.Net.TLS.Enable = true
		scfg.Net.TLS.Config = tlsCfg
	}

	// Check topic existence before starting producer.
	if err := checkKafkaTopic(cfg.Brokers, cfg.Topic, scfg); err != nil {
		logger.Warn("kafka topic %q not found on brokers: %v — messages will be dropped", cfg.Topic, err)
	}

	producer, err := sarama.NewAsyncProducer(cfg.Brokers, scfg)
	if err != nil {
		return nil, fmt.Errorf("failed to create kafka async producer: %w", err)
	}

	// Drain internal channels in the background (fire-and-forget).
	go func() {
		for range producer.Successes() {
		}
	}()
	go func() {
		for range producer.Errors() {
		}
	}()

	return &KafkaOutput{producer: producer, topic: cfg.Topic}, nil
}

func (k *KafkaOutput) Name() string { return "kafka" }

func (k *KafkaOutput) Write(_ context.Context, rawBytes []byte, _ *prompb.WriteRequest) error {
	msg := &sarama.ProducerMessage{
		Topic: k.topic,
		Value: sarama.ByteEncoder(rawBytes),
	}
	k.producer.Input() <- msg
	return nil
}

func (k *KafkaOutput) Close() error {
	return k.producer.Close()
}

func buildTLSConfig(cfg *config.KafkaConfig) (*tls.Config, error) {
	caCert, err := os.ReadFile(cfg.SSL.CAPem)
	if err != nil {
		return nil, fmt.Errorf("read ca_pem %q: %w", cfg.SSL.CAPem, err)
	}
	pool := x509.NewCertPool()
	if !pool.AppendCertsFromPEM(caCert) {
		return nil, fmt.Errorf("failed to parse CA certificate from %q", cfg.SSL.CAPem)
	}

	clientCert, err := tls.LoadX509KeyPair(cfg.SSL.CertPem, cfg.SSL.KeyPem)
	if err != nil {
		return nil, fmt.Errorf("load cert/key pair: %w", err)
	}

	return &tls.Config{
		RootCAs:      pool,
		Certificates: []tls.Certificate{clientCert},
	}, nil
}

func checkKafkaTopic(brokers []string, topic string, scfg *sarama.Config) error {
	client, err := sarama.NewClient(brokers, scfg)
	if err != nil {
		return fmt.Errorf("could not connect to brokers: %w", err)
	}
	defer client.Close()

	topics, err := client.Topics()
	if err != nil {
		return fmt.Errorf("could not list topics: %w", err)
	}
	for _, t := range topics {
		if t == topic {
			return nil
		}
	}
	return fmt.Errorf("topic not present")
}
