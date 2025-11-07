#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

readonly FILE="t.c"
readonly OUTPUT="temp.txt"
readonly EXE="./temp.out"

gcc "${FILE}" -Wall -Wextra -o "${EXE}" > "${OUTPUT}" 2>&1 || exit 1

if grep "uninitialized" "${OUTPUT}"; then
  exit 1
fi

"${EXE}" > "${OUTPUT}" 2>&1
if [[ "$?" != 1 ]]; then
  exit 1
fi

grep "HIGH" "${FILE}" && grep "hello" "${OUTPUT}"