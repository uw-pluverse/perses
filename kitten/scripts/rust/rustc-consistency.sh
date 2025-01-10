#!/usr/bin/env bash

set -o pipefail
set -o nounset

function echoerr {
  echo $@ 1>&2
}

readonly CMD_OBJDUMP="objdump --disassemble-all "
function disassemble {
  object_file="${1}"
  output="${2}"
  sections=$(objdump --section-headers "${object_file}" | grep ".text" | awk '{ print $2 }')
  rm -f "${output}" &> /dev/null || true
  for section in ${sections} ; do
    ${CMD_OBJDUMP} --section="${section}" "${object_file}" >> "${output}"
  done
}

if [[ "$#" != 1 ]] ; then
  echoerr "Usage: ${0} <rust-file>"
fi

readonly RUSTC="rustc +nightly"

if [[ "${1}" == "--verbose-version" ]] ; then 
  $RUSTC --verbose --version
  exit 0
fi

readonly RUST_FILE="${1}"
readonly RUST_DIR="$(dirname ${RUST_FILE})"

readonly RUST_FILE_AS_LIB="${RUST_DIR}/rust_file_as_lib.rs"
readonly RANDOM_UUID=$(cat /proc/sys/kernel/random/uuid | tr - _)
sed -r -e "s/fn\s+main\s*\(/pub fn main_${RANDOM_UUID}\(/g" "${RUST_FILE}" > "${RUST_FILE_AS_LIB}"

readonly OBJECT_FILE="${RUST_DIR}/temp_compilation_consistency_lib.o"
readonly DEFAULT_FLAGS="--emit obj --crate-type lib -C link-dead-code -C opt-level=3 -Z mir-opt-level=3 -Z new-llvm-pass-manager=yes -Z unsound-mir-opts=yes -Z polonius=yes -Z polymorphize=yes"
readonly DEBUG_FLAGS="-C debuginfo=2"
readonly TIMEOUT=30
readonly DIS_NO_DEBUG_FILE="${RUST_DIR}/objdump_no_debug.txt"
readonly DIS_DEBUG_FILE="${RUST_DIR}/objdump_debug.txt"
rm -f "${DIS_NO_DEBUG_FILE}" "${DIS_DEBUG_FILE}" &> /dev/null || true

rm -rf "${OBJECT_FILE}" > /dev/null 2>&1 || true
timeout -s 9 "${TIMEOUT}" ${RUSTC} ${DEFAULT_FLAGS} "-o" "${OBJECT_FILE}" "${RUST_FILE_AS_LIB}" || exit 1
disassemble "${OBJECT_FILE}" "${DIS_NO_DEBUG_FILE}" || exit 2

rm -rf "${OBJECT_FILE}" > /dev/null 2>&1 || true
timeout -s 9 "${TIMEOUT}" ${RUSTC} ${DEFAULT_FLAGS} ${DEBUG_FLAGS} "-o" "${OBJECT_FILE}" "${RUST_FILE_AS_LIB}" || exit 3
disassemble "${OBJECT_FILE}" "${DIS_DEBUG_FILE}" || exit 4

if ! diff "${DIS_NO_DEBUG_FILE}" "${DIS_DEBUG_FILE}" ; then
  echoerr "thread compilation consistency modulo debug info panicked"
  exit 134
fi
exit 0



