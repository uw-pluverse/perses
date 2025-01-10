#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o xtrace
export PS4='+($(basename ${BASH_SOURCE}):${LINENO}): ${FUNCNAME[0]:+${FUNCNAME[0]}(): }'

readonly CURRENT_DIR=$(pwd)
readonly TEST_SCRIPT="${CURRENT_DIR}/kitten/scripts/c/validate_ccmd.sh"

readonly TEMP_DIR=$(mktemp -d)
trap "rm -rf ${TEMP_DIR} || true" EXIT
readonly DUMMY_FILE="${TEMP_DIR}/t.c"
touch "${DUMMY_FILE}"

readonly OLD_PATH="${PATH}"
export PATH="${CURRENT_DIR}/kitten/scripts/c/mock_compilers/ccmd_buggy:${OLD_PATH}"

# Test 1, without output file
"${TEST_SCRIPT}" "${DUMMY_FILE}"
exit_code=$?
if [[ "${exit_code}" != 139 ]] || [[ -f "${TEMP_DIR}/default_output.a" ]] ; then
  echo "test failed."
  exit 1
fi

# Test 2, with output file
"${TEST_SCRIPT}" "${DUMMY_FILE}" "${TEMP_DIR}/a.out"
exit_code=$?
if [[ "${exit_code}" != 139 ]] || [[ -f "${TEMP_DIR}/a.out" ]] ; then
  echo "test failed."
  exit 1
fi


readonly OLD_PATH="${PATH}"
export PATH="${CURRENT_DIR}/kitten/scripts/c/mock_compilers/ccmd_correct:${OLD_PATH}"
# Test 3, with output file
"${TEST_SCRIPT}" "${DUMMY_FILE}"
exit_code=$?
if [[ "${exit_code}" != 0 ]] || [[ ! -f "${TEMP_DIR}/default_output.a" ]] ; then
  tree "${TEMP_DIR}"
  echo "test failed."
  exit 1
fi

# Test 2, with output file
"${TEST_SCRIPT}" "${DUMMY_FILE}" "${TEMP_DIR}/a.out"
exit_code=$?
if [[ "${exit_code}" != 0 ]] || [[ ! -f "${TEMP_DIR}/a.out" ]] ; then
  echo "test failed."
  exit 1
fi

echo "test passed"
exit 0
