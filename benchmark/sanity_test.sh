#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

if [[ "$#" -eq "0" ]] ; then
  echo "Usage: $0 <test script> <files...>" 1>&2
  exit 1
fi

readonly TEST_SCRIPT=$1

readonly TMP=$(mktemp -d)
for file in "$@" ; do
  # Check if the file exists
  if [ -f "${file}" ]; then
    echo "Processing file: ${file}"
    cp "${file}" "${TMP}"
  else
    echo "File not found: ${file}" 1>&2
    exit 1
  fi
done

readonly CURRENT_DIR=$(pwd)
cd "${TMP}"
readonly SCRIPT_NAME=$(basename "${TEST_SCRIPT}")
chmod +x "${SCRIPT_NAME}"

bash -x "./${SCRIPT_NAME}"
readonly RET_CODE="$?"

cd "${CURRENT_DIR}"
exit "${RET_CODE}"
