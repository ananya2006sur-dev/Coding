package config

import (
	"fmt"
	"os"
	"strings"

	"gopkg.in/yaml.v3"
)

type Config struct {
	Server   ServerConfig  `yaml:"server"`
	LogLevel string        `yaml:"log_level"`
	Outputs  OutputsConfig `yaml:"outputs"`
}

type ServerConfig struct {
	Port int `yaml:"port"`
}

type OutputsConfig struct {
	Active    []string       `yaml:"active"`
	Kafka     KafkaConfig    `yaml:"kafka"`
	HTTP      HTTPConfig     `yaml:"http"`
	File      FileConfig     `yaml:"file"`
	Fluentbit FluentbitConfig `yaml:"fluentbit"`
}

type KafkaConfig struct {
	Brokers  []string    `yaml:"brokers"`
	Topic    string      `yaml:"topic"`
	Protocol string      `yaml:"protocol"`
	SSL      KafkaSSL    `yaml:"ssl"`
}

type KafkaSSL struct {
	CAPem   string `yaml:"ca_pem"`
	CertPem string `yaml:"cert_pem"`
	KeyPem  string `yaml:"key_pem"`
}

type HTTPConfig struct {
	Endpoint string `yaml:"endpoint"`
}

type FileConfig struct {
	Path string `yaml:"path"`
}

type FluentbitConfig struct {
	Host string `yaml:"host"`
	Port int    `yaml:"port"`
	Tag  string `yaml:"tag"`
}

func Load(path string) (*Config, error) {
	data, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("cannot read config file %q: %w", path, err)
	}

	var cfg Config
	if err := yaml.Unmarshal(data, &cfg); err != nil {
		return nil, fmt.Errorf("cannot parse config file %q: %w", path, err)
	}

	if err := validate(&cfg); err != nil {
		return nil, err
	}

	return &cfg, nil
}

func validate(cfg *Config) error {
	if cfg.Server.Port < 1 || cfg.Server.Port > 65535 {
		return fmt.Errorf("server.port %d is invalid; must be 1–65535", cfg.Server.Port)
	}

	level := strings.ToUpper(cfg.LogLevel)
	switch level {
	case "DEBUG", "INFO", "WARN", "ERROR":
		cfg.LogLevel = level
	case "":
		cfg.LogLevel = "INFO"
	default:
		return fmt.Errorf("log_level %q is invalid; must be one of DEBUG, INFO, WARN, ERROR", cfg.LogLevel)
	}

	if len(cfg.Outputs.Active) == 0 {
		return fmt.Errorf("outputs.active must contain at least one output method")
	}

	for _, name := range cfg.Outputs.Active {
		switch strings.ToLower(name) {
		case "kafka":
			if err := validateKafka(&cfg.Outputs.Kafka); err != nil {
				return fmt.Errorf("kafka output is active but config is incomplete: %w", err)
			}
		case "http":
			if cfg.Outputs.HTTP.Endpoint == "" {
				return fmt.Errorf("http output is active but outputs.http.endpoint is not set")
			}
		case "file":
			if cfg.Outputs.File.Path == "" {
				return fmt.Errorf("file output is active but outputs.file.path is not set")
			}
			if !strings.HasPrefix(cfg.Outputs.File.Path, "/") && !isAbsWindowsPath(cfg.Outputs.File.Path) {
				return fmt.Errorf("file output path %q must be an absolute path", cfg.Outputs.File.Path)
			}
		case "fluentbit":
			fb := cfg.Outputs.Fluentbit
			if fb.Host == "" {
				return fmt.Errorf("fluentbit output is active but outputs.fluentbit.host is not set")
			}
			if fb.Port < 1 || fb.Port > 65535 {
				return fmt.Errorf("fluentbit output is active but outputs.fluentbit.port %d is invalid", fb.Port)
			}
			if fb.Tag == "" {
				return fmt.Errorf("fluentbit output is active but outputs.fluentbit.tag is not set")
			}
		default:
			return fmt.Errorf("unknown output method %q in outputs.active", name)
		}
	}

	return nil
}

func validateKafka(k *KafkaConfig) error {
	if len(k.Brokers) == 0 {
		return fmt.Errorf("outputs.kafka.brokers must contain at least one broker")
	}
	if k.Topic == "" {
		return fmt.Errorf("outputs.kafka.topic is not set")
	}
	proto := strings.ToLower(k.Protocol)
	if proto != "ssl" && proto != "plain" {
		return fmt.Errorf("outputs.kafka.protocol must be \"ssl\" or \"plain\", got %q", k.Protocol)
	}
	if proto == "ssl" {
		if k.SSL.CAPem == "" {
			return fmt.Errorf("outputs.kafka.ssl.ca_pem is not set")
		}
		if k.SSL.CertPem == "" {
			return fmt.Errorf("outputs.kafka.ssl.cert_pem is not set")
		}
		if k.SSL.KeyPem == "" {
			return fmt.Errorf("outputs.kafka.ssl.key_pem is not set")
		}
	}
	return nil
}

// isAbsWindowsPath returns true for paths like C:\... or C:/...
func isAbsWindowsPath(p string) bool {
	return len(p) >= 3 && p[1] == ':' && (p[2] == '/' || p[2] == '\\')
}

// IsActive returns true if the named output method is in outputs.active.
func (c *Config) IsActive(name string) bool {
	for _, a := range c.Outputs.Active {
		if strings.EqualFold(a, name) {
			return true
		}
	}
	return false
}
