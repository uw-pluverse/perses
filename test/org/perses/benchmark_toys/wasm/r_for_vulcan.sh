#!/usr/bin/env bash

set -o errexit
set -o pipefail
set -o nounset

wat2wasm t_for_vulcan.wat -o t.wasm || exit 1
wasmedge --force-interpreter t.wasm > temp-output.txt || exit 1
grep --quiet "hello" temp-output.txt