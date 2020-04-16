#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

export GOCACHE=$(mktemp -d)
trap "{ rm ${GOCACHE} -rf; }" EXIT

go version | grep "+213845f7b9"
(go build -o /dev/null 29220.go || true) 2>&1 | grep "internal compiler error"
