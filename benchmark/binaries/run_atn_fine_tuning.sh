#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

readonly BINARY_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "${BINARY_DIR}/run_common.sh"

# run perses with TokenReplacementReducer
pushd "${TMP}"
readonly START_TIME=$(date +%s)
java ${JVM_FLAGS:=''} -jar "/tmp/binaries/atn_perses_main_deploy.jar" ${PERSES_FLAGS:=''} \
  --test-script "${TMP_TEST_SCRIPT}" \
  --input-file "${TMP_SOURCE_FILE}" \
  --output-dir "${TMP}" \
  --threads "${THREADS}" \
  --query-caching false \
  --on-demand-reducer-classes "org.perses.reduction.reducer.AtnFineTuningTokenReducer"

readonly RET_CODE="$?"
readonly END_TIME=$(date +%s)

summarize_results "${TMP_SOURCE_FILE}"
popd

exit "${RET_CODE}"
