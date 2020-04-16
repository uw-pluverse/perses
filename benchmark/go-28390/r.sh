#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

export GOCACHE=$(mktemp -d)
trap "{ rm ${GOCACHE} -rf; }" EXIT

go version | grep "+a361ef36af"
(go run 28390.go || true) 2>&1 | grep "signal SIGSEGV"
