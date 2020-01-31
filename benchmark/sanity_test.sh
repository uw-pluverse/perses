#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

if [[ "$#" != "2" ]] ; then
  echo "Usage: $0 <test script> <source file>" 1>&2
  exit 1
fi

readonly SOURCE_FILE=$2
readonly TEST_SCRIPT=$1

readonly TMP=$(mktemp -d)
cp "${SOURCE_FILE}" "${TMP}"
cp "${TEST_SCRIPT}" "${TMP}"

readonly CURRENT_DIR=$(pwd)
cd "${TMP}"
readonly SCRIPT_NAME=$(basename "${TEST_SCRIPT}")
chmod +x "${SCRIPT_NAME}"

bash -x "./${SCRIPT_NAME}"
readonly RET_CODE="$?"


cd "${CURRENT_DIR}"
exit "${RET_CODE}"
