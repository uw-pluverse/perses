#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly FILE="${1}"

if grep "perses version" "${FILE}" && \
    grep "Built on" "${FILE}" ; then
  exit 0
else
  cat "${FILE}"
  echo "No keywords are found in ${FILE}"
  exit 1
fi