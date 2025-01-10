#!/usr/bin/env bash

set -o nounset
set -o pipefail

readonly ERROR_CODE=100
echo "PATH: $PATH"
if [[ "$#" != 2 ]]; then
  echo "Usage: ${0} <source file> <result folder>"
  exit "${ERROR_CODE}"
fi

readonly FILE="${1}"
[[ -f "${FILE}" ]] || exit "${ERROR_CODE}"

readonly RESULT_FOLDER="${2}"
mkdir -p "${RESULT_FOLDER}"
[[ -d "${RESULT_FOLDER}" ]] || exit "${ERROR_CODE}"



if timeout -s 9 60 gcc-trunk -c -O3 -g "${FILE}" && \
   timeout -s 9 60 clang-trunk -c -O3 -g "${FILE}" ; then

  readonly PID="$$"
  readonly SAVED_FILE_PATH="${RESULT_FOLDER}/$(date +"%y-%m-%d_%H-%M-%s")_${PID}_${RANDOM}.c"
  cp "${FILE}" "${SAVED_FILE_PATH}"
fi
