#!/usr/bin/env bash

set -o nounset
set -o pipefail

readonly OUTPUT="temp_output.txt"
readonly PROG="hello_for_TRec.py"

if ! python3 "${PROG}" > "${OUTPUT}" 2>&1; then
  exit 1
fi

grep "hello" "${OUTPUT}"
