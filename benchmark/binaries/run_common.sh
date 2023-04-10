
if [ $# -gt 1 ]; then
  echo "Running with arguments: $0 $@"
else
  echo "Expect arguments $0 TEST_SCRIPT SOURCE_FILE [COMPLETE_STAT_FILE]"
  exit 1
fi

#command line arguments
readonly TEST_SCRIPT=$1
readonly SOURCE_FILE=$2
readonly OUTPUT_DIR=$3
readonly COMPLETE_STAT_FILE=${4:-}
SCRIPT_NAME=$(basename "${TEST_SCRIPT}")
readonly SCRIPT_NAME
SOURCE_NAME=$(basename "${SOURCE_FILE}")
readonly SOURCE_NAME
THREADS=1
readonly THREADS

#set up temp file
readonly TMP=$(mktemp -d)
readonly TMP_TEST_SCRIPT="${TMP}/${SCRIPT_NAME}"
readonly TMP_SOURCE_FILE="${TMP}/${SOURCE_NAME}"
"${BINARY_DIR}/../patch_oracle.py" "${TEST_SCRIPT}" \
    > "${TMP_TEST_SCRIPT}"
chmod +x "${TMP_TEST_SCRIPT}"
cp "${SOURCE_FILE}" "${TMP_SOURCE_FILE}"
readonly REDUCTION_STAT_FILE=$(mktemp)
export REDUCTION_STAT_FILE

#check REDUCTION_STAT_FILE is empty
[[ "0" == "$(wc -l < "${REDUCTION_STAT_FILE}" | sed -e 's/^[ \t]*//')" ]] || exit 1


summarize_results () {
  local -r reduced_file=$1
  local -r reduced_token_count=$("${BINARY_DIR}/run_token_counter.sh" "${reduced_file}")

  if [ -z "${COMPLETE_STAT_FILE}" ]; then
    echo "${REDUCTION_STAT_FILE} ${TEST_SCRIPT} ${SOURCE_FILE}" \
      "'$(wc -l < "${REDUCTION_STAT_FILE}" | sed -e 's/^[ \t]*//') quary'" \
      "'$((END_TIME - START_TIME)) s' '${RET_CODE} code'" \
      "'${reduced_token_count} tokens'"
  else
    echo "${REDUCTION_STAT_FILE}" >> "${COMPLETE_STAT_FILE}"
    echo "${TEST_SCRIPT}" >> "${COMPLETE_STAT_FILE}"
    echo "${SOURCE_FILE}" >> "${COMPLETE_STAT_FILE}"
    echo "$(wc -l < "${REDUCTION_STAT_FILE}" | sed -e 's/^[ \t]*//')" \
      >> "${COMPLETE_STAT_FILE}"
    echo "$((END_TIME - START_TIME))" >> "${COMPLETE_STAT_FILE}"
    echo "${reduced_token_count}" >> "${COMPLETE_STAT_FILE}"
    echo "${RET_CODE}" >> "${COMPLETE_STAT_FILE}"
  fi

  if [ -e $OUTPUT_DIR ]; then
    cp ${reduced_file} $OUTPUT_DIR
    cp ${TMP_TEST_SCRIPT} $OUTPUT_DIR
  else
    echo "Reduced file failed to move (directory not exist)"
  fi

  rm -f "${REDUCTION_STAT_FILE}"
  rm -rf "${TMP}"
}
