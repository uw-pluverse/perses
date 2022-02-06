#!/usr/bin/env bash

set -o pipefail
set -o nounset
ulimit -t 60

readonly SRC="hello.php"

grep --quiet 'hello world' "${SRC}"