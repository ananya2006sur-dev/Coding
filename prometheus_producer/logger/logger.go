package logger

import (
	"fmt"
	"os"
	"strings"
	"time"
)

type Level int

const (
	DEBUG Level = iota
	INFO
	WARN
	ERROR
)

var levelNames = map[Level]string{
	DEBUG: "DEBUG",
	INFO:  "INFO",
	WARN:  "WARN",
	ERROR: "ERROR",
}

var active Level = INFO

func SetLevel(s string) {
	switch strings.ToUpper(s) {
	case "DEBUG":
		active = DEBUG
	case "INFO":
		active = INFO
	case "WARN":
		active = WARN
	case "ERROR":
		active = ERROR
	}
}

func log(level Level, format string, args ...any) {
	if level < active {
		return
	}
	ts := time.Now().UTC().Format(time.RFC3339)
	msg := fmt.Sprintf(format, args...)
	fmt.Fprintf(os.Stderr, "%s [%s] %s\n", ts, levelNames[level], msg)
}

func Debug(format string, args ...any) { log(DEBUG, format, args...) }
func Info(format string, args ...any)  { log(INFO, format, args...) }
func Warn(format string, args ...any)  { log(WARN, format, args...) }
func Error(format string, args ...any) { log(ERROR, format, args...) }
