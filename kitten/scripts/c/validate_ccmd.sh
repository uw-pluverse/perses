#!/usr/bin/env bash

set -o nounset
set -o pipefail

function echoerr {
  echo "$@" 1>&2
}

function print_usage_and_exit {
  echoerr "Usage: ${0} <source file> [<output file>]"
  exit 1
}
if [[ "$#" == 0 ]]; then
  print_usage_and_exit
fi

readonly FILE="$(realpath "${1}")"
[[ -f "${FILE}" ]] || exit "${ERROR_CODE}"

readonly DIR_NAME="$(dirname "${FILE}")"
if [[ "$#" == 2 ]] ; then
  readonly OUTPUT="${2}"
elif [[ "$#" == 1 ]] ; then
  readonly OUTPUT="${DIR_NAME}/default_output.a"
else
  print_usage_and_exit
fi

readonly TEMP=$(mktemp -d)
trap "rm -rf ${TEMP}" EXIT
readonly FILE_NAME="t.c"
cp "${FILE}" "${TEMP}/${FILE_NAME}"

readonly CURRENT_DIR=$(pwd)

cd "${TEMP}"
readonly COMPILERS=("gcc-trunk" "clang-trunk")
readonly OPT_LEVELS=("-O0" "-O1" "-Os" "-O2" "-O3")
readonly OUTPUT="temp.out"
readonly DIS_NO_G_FILE_NAME="no_g.txt"
readonly DIS_G_FILE_NAME="g.txt"
readonly PID="$$"

for compiler in "${COMPILERS[@]}"; do
  if ! timeout -s 9 30 "${compiler}" -c "${FILE_NAME}" -o "${OUTPUT}"; then
    echo "Un-compilable program by ${compiler}"
    continue
  fi
  for opt in "${OPT_LEVELS[@]}"; do
    echo "Optimization level ${opt}"

    rm -rf "${OUTPUT}" || true
    cmd_no_g="timeout -s 9 30 "${compiler}" "${FILE_NAME}" "${opt}" -o "${OUTPUT}""
    ${cmd_no_g}
    if ! ${cmd_no_g} ; then
      echo "fail to run command: ${cmd_no_g} "
      continue
    fi
    objdump --disassemble --section=.text "${OUTPUT}" > "${DIS_NO_G_FILE_NAME}"

    rm -rf "${OUTPUT}" || true
    cmd_g="timeout -s 9 30 "${compiler}" "${FILE_NAME}" "${opt}" -g3 -o "${OUTPUT}""
    if ! ${cmd_g} ; then
      echo "fail to run command: ${cmd_g}"
      continue
    fi

    objdump --disassemble --section=.text "${OUTPUT}" > "${DIS_G_FILE_NAME}"

    if ! diff --brief "${DIS_NO_G_FILE_NAME}" "${DIS_G_FILE_NAME}" ; then
      echoerr "internal compiler error: found compilation inconsistencies: ${cmd_g}"
      rm -rf "${OUTPUT}" || true
      exit 139
    fi
  done
done
exit 0
