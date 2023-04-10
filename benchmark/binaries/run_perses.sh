#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
#set -o xtrace

#expect
# UNPATCHED r
# code to be reduced
# STAT FILE

#do
# run perses on file to be reduced with r, collect stats

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${BINARY_DIR}/run_common.sh"

pushd "${TMP}"
readonly START_TIME=$(date +%s)
java ${JVM_FLAGS:=''} -jar "/tmp/binaries/perses_deploy.jar" ${PERSES_FLAGS:=''} \
  --test-script "${TMP_TEST_SCRIPT}" \
  --input-file "${TMP_SOURCE_FILE}" \
  --output-dir "${TMP}" \
  --threads "${THREADS}"

readonly RET_CODE="$?"
readonly END_TIME=$(date +%s)

summarize_results "${TMP_SOURCE_FILE}"
popd

exit "${RET_CODE}"
