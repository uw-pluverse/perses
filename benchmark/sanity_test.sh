#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

if [[ "$#" -lt "2" || "$#" -gt "4" ]] ; then
  echo "Usage: $0 <test script> <source file> [shadow file]" 1>&2
  exit 1
fi

readonly SOURCE_FILE=$2
readonly TEST_SCRIPT=$1
if [[ "$#" == "3" ]]; then
    readonly SHADOW_FILE=$3
fi

readonly TMP=$(mktemp -d)
cp "${SOURCE_FILE}" "${TMP}"
cp "${TEST_SCRIPT}" "${TMP}"
if [[ "$#" == "3" ]]; then
    cp "${SHADOW_FILE}" "${TMP}"
fi

readonly CURRENT_DIR=$(pwd)
cd "${TMP}"
readonly SCRIPT_NAME=$(basename "${TEST_SCRIPT}")
chmod +x "${SCRIPT_NAME}"

bash -x "./${SCRIPT_NAME}"
readonly RET_CODE="$?"


cd "${CURRENT_DIR}"
exit "${RET_CODE}"
