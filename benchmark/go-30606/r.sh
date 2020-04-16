#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

export GOCACHE=$(mktemp -d)
trap "{ rm ${GOCACHE} -rf; }" EXIT

go version | grep "+1650f1ba0b"

(go run 30606.go || true) 2>&1 | grep -P "signal SIGSEGV"
