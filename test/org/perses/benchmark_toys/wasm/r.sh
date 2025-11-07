#!/usr/bin/env bash

set -o errexit
set -o pipefail
set -o nounset

wat2wasm t.wat -o temp.wasm || exit 1
wasmedge --force-interpreter temp.wasm > temp-output.txt || exit 1
grep --quiet "hello" temp-output.txt