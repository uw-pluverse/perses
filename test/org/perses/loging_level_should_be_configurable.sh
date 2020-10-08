#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly FILE="${1}"
readonly NEEDLE="CONFIG"
if grep "${NEEDLE}" "${FILE}" ; then
  exit 0
else
  cat "${FILE}"
  echo "No occurrence of '${NEEDLE}' in ${FILE}"
  exit 1
fi
