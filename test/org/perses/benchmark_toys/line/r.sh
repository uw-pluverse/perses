#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly FILE="small.line"

grep --quiet "a" "${FILE}" \
  && grep --quiet "g" "${FILE}" \
  && grep --quiet "n" "${FILE}"