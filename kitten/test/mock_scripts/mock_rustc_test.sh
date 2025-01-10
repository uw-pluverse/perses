#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o xtrace

if [[ "$#" != 1 ]] ; then
  echo "usage: $0 <mock_rustc.py>"
  exit 1
fi

readonly MOCK=$(realpath "${1}")
readonly TEMP=$(mktemp -d)
trap "rm -rf ${TEMP}" EXIT

cd "${TEMP}"

function test_crash_msg_1() {
  readonly CRASH_RS_1="crash_1.rs"
  cat > "${CRASH_RS_1}" <<-EOF
fn main() {
  println!("trigger crash 1");
}
EOF
  readonly OUTPUT_RS_1="crash_1_rustc_output.txt"
  if "${MOCK}" "${CRASH_RS_1}" &> "${OUTPUT_RS_1}" ; then
    cat "${OUTPUT_RS_1}"
    exit 1
  fi
  if ! grep --quiet "rustc_if_this_changed" "${OUTPUT_RS_1}" ; then
    cat "${OUTPUT_RS_1}"
    exit 1
  fi
}

function test_crash_msg_2() {
  readonly CRASH_RS_2="crash_2.rs"
  cat > "${CRASH_RS_2}" <<-EOF
fn main() {
  println!("trigger crash 2");
}
EOF
  readonly OUTPUT_RS_2="crash_2_rustc_output.txt"
  if "${MOCK}" "${CRASH_RS_2}" &> "${OUTPUT_RS_2}" ; then
    cat "${OUTPUT_RS_2}"
    exit 1
  fi
  if ! grep --quiet "called on invalid type" "${OUTPUT_RS_2}" ; then
    cat "${OUTPUT_RS_2}"
    exit 1
  fi
}

function test_compiler_error() {
  readonly INVALID_RS_3="invalid.rs"
  cat > "${INVALID_RS_3}" <<-EOF
fn main() {
EOF
  readonly OUTPUT_RS_3="compiler_error_3_rustc_output.txt"
  if "${MOCK}" "${INVALID_RS_3}" &> "${OUTPUT_RS_3}" ; then
    cat "${OUTPUT_RS_3}"
    exit 1
  fi
}

function test_compiler_pass() {
  readonly VALID_RS_4="valid.rs"
  echo "fn main() {}" > "${VALID_RS_4}"

  readonly OUTPUT_RS_4="valid_4_rustc_output.txt"
  if ! "${MOCK}" "${VALID_RS_4}" &> "${OUTPUT_RS_4}" ; then
    cat "${OUTPUT_RS_4}"
    exit 1
  fi
}

function test_compiler_version() {
  readonly VERSION_FILE="version.txt"
  if ! "${MOCK}" --verbose --version &> "${VERSION_FILE}" ; then
    exit 1
  fi
  if ! grep --quiet "version" "${VERSION_FILE}" ; then
    exit 1
  fi
}


test_crash_msg_1
test_crash_msg_2
test_compiler_error
test_compiler_pass
test_compiler_version

exit 0
