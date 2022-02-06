#!/usr/bin/env bash

set -o pipefail
set -o nounset
ulimit -t 60

readonly SRC="hello.sv"

grep --quiet 'Hello world' "${SRC}"