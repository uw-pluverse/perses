#!/usr/bin/env bash

set -o nounset

readonly FILE="mutant.rs"

readonly BUGGY_RUSTC_VERSION="1.20.0"
readonly CORRECT_RUSTC_VERSION="1.47.0"
readonly CORRECT_RUSTC_VERSION_2="1.47.0"
rustup toolchain install "${BUGGY_RUSTC_VERSION}" --force
rustup toolchain install "${CORRECT_RUSTC_VERSION}" --force
rustup toolchain install "${CORRECT_RUSTC_VERSION_2}" --force

if ! command -v valgrind > /dev/null ; then
  echo "valgrind is not installed"
  exit 100
fi

readonly EXE_WRONG="./wrong.out"
if ! timeout -s 9 60 rustup run "${BUGGY_RUSTC_VERSION}" rustc -o "${EXE_WRONG}" "${FILE}"; then
  exit 1
fi

readonly EXE_CORRECT="./correct.out"
if ! timeout -s 9 60 rustup run "${CORRECT_RUSTC_VERSION}" rustc -o "${EXE_CORRECT}" "${FILE}" ; then
  exit 1
fi

readonly EXE_CORRECT_2="./correct_2.out"
if ! timeout -s 9 60 rustup run "${CORRECT_RUSTC_VERSION_2}" rustc -o "${EXE_CORRECT_2}" "${FILE}" ; then
  exit 1
fi

readonly OUTPUT_WRONG="wrong_output.txt"

if (timeout -s 9 30 valgrind "${EXE_WRONG}") &> "${OUTPUT_WRONG}" ; then
  exit 1
fi

readonly OUTPUT_CORRECT_1="correct_output.txt"
readonly OUTPUT_CORRECT_2="correct_output_2.txt"
if ! timeout -s 9 30 valgrind "${EXE_CORRECT}"; then
  exit 1
fi

timeout -s 9 30 "${EXE_CORRECT}"  &> "${OUTPUT_CORRECT_1}" 

if ! timeout -s 9 30 valgrind  "${EXE_CORRECT_2}" ; then
  exit 1
fi
timeout -s 9 30 "${EXE_CORRECT_2}" &> "${OUTPUT_CORRECT_2}" 

if ! diff "${OUTPUT_CORRECT_1}" "${OUTPUT_CORRECT_2}" ; then
  exit 1
fi

exit 0

