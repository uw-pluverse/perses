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
readonly REDUCED_TOKEN_FILE="${TMP}/reduced.c"

pushd "${TMP}"
readonly START_TIME=$(date +%s)
java "${PERSES_XLOG:=''}" -jar "/tmp/binaries/perses_deploy.jar" ${PERSES_EXTRA_FLAGS:=''} \
  --test-script "${TMP_TEST_SCRIPT}" \
  --input-file "${TMP_SOURCE_FILE}" \
  --output-file "${TMP}/reduced.c" \
  --threads "${THREADS}"

readonly RET_CODE="$?"
readonly END_TIME=$(date +%s)

summarize_results
popd

exit "${RET_CODE}"
