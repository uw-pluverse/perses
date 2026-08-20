#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate go build run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300

set -o pipefail
set -o nounset
set -o errexit

export GOCACHE=$(mktemp -d)
trap "{ rm ${GOCACHE} -rf; }" EXIT

go version | grep "+1650f1ba0b"

(go run 30606.go || true) 2>&1 | grep -P "signal SIGSEGV"
