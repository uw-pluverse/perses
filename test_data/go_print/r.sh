#!/usr/bin/env bash

set -o errexit
set -o pipefail
set -o nounset

readonly OUTPUT="output.txt.tmp"
readonly SRC="small.go"

rm "${OUTPUT}" || true

go run "${SRC}" &> "${OUTPUT}"

if [[ "${?}" != 0 ]] ; then
  exit 1
fi

if ! grep "golang" "${OUTPUT}" ; then
  exit 1
fi

exit 0
