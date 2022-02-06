#!/usr/bin/env bash

set -o nounset
set -o pipefail

readonly OUTPUT="temp_output.txt"
readonly PROG="hello.py"

if ! python "${PROG}" > "${OUTPUT}" 2>&1 ; then
  exit 1
fi

grep "hello world" "${OUTPUT}"