#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

if [[ "$#" -eq "0" ]]; then
  echo "Usage: $0 <test script> <files...>" 1>&2
  exit 1
fi

readonly TEST_SCRIPT=$1
# The test script and every input file share a directory in the source tree; that directory is the
# root the files' layout is relative to. Stage each file under TMP at its path relative to this root
# so that a file in a subdirectory (e.g. src/a.c) keeps that subdirectory, matching how the reducer
# lays the files out. For a flat layout the relative path is just the basename, so this is a no-op.
readonly SCRIPT_DIR=$(dirname "${TEST_SCRIPT}")

readonly TMP=$(mktemp -d)
for file in "$@"; do
  # Check if the file exists
  if [ -f "${file}" ]; then
    echo "Processing file: ${file}"
    rel="${file#${SCRIPT_DIR}/}"
    dest="${TMP}/${rel}"
    mkdir -p "$(dirname "${dest}")"
    cp "${file}" "${dest}"
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
