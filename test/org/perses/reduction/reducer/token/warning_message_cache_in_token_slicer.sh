#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit


if [[ "${#}" != 3 ]] ; then
  echo "$0 <perses_deploy.jar> <input_file.c> <test_script.sh>"
  exit 1
fi

readonly BIN_PERSES="$(realpath "${1}")"
readonly SOURCE="$(realpath "${2}")"
readonly SCRIPT="$(realpath "${3}")"
readonly ROOT=$(mktemp -d)
trap 'rm -rf ${ROOT}' EXIT

cd "${ROOT}" || exit 1
readonly FILE_SOURCE="${ROOT}/t.c"
cp "${SOURCE}" "${FILE_SOURCE}"
readonly FILE_SCRIPT="${ROOT}/r.sh"
cp "${SCRIPT}" "${FILE_SCRIPT}"
chmod +x "${FILE_SCRIPT}"

readonly FILE_LOG="${ROOT}/log.txt"
readonly PERSES_OPTIONS="--test-script ${FILE_SCRIPT} --input-file ${FILE_SOURCE} \
--query-caching true --enable-token-slicer true"
java -jar "${BIN_PERSES}" --test-script "${FILE_SCRIPT}" --input-file "${FILE_SOURCE}" \
--query-caching true --enable-token-slicer true > "${FILE_LOG}" 2>&1 || true
if grep "A query cache item was created before. This is unexpected." "${FILE_LOG}"; then
  cat "${FILE_LOG}"
  exit 1
else
  echo "No unexpected cache item is created. "
  exit 0
fi
