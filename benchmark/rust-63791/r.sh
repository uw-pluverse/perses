#!/usr/bin/env bash

set -o nounset
set -o pipefail

readonly FILE="mutant.rs"

readonly RUSTC_VERSION="1.34.0"
readonly CORRECT_RUSTC_VERSION="1.33.0"
rustup toolchain install "${RUSTC_VERSION}"
rustup toolchain install "${CORRECT_RUSTC_VERSION}"

readonly EXTRA_FLAGS="-C opt-level=3"

readonly EXE_WRONG="./wrong.out"
if ! timeout -s 9 60 rustup run "${RUSTC_VERSION}" rustc -C target-cpu=haswell ${EXTRA_FLAGS} -o "${EXE_WRONG}" "${FILE}"; then
  exit 1
fi

readonly EXE_CORRECT="./correct.out"
if ! timeout -s 9 60 rustup run "${RUSTC_VERSION}" rustc -C target-cpu=ivybridge ${EXTRA_FLAGS} -o "${EXE_CORRECT}" "${FILE}" ; then
  exit 1
fi

readonly EXE_CORRECT_2="./correct_2.out"
if ! timeout -s 9 60 rustup run "${CORRECT_RUSTC_VERSION}" rustc -C target-cpu=haswell ${EXTRA_FLAGS} -o "${EXE_CORRECT_2}" "${FILE}" ; then
  exit 1
fi

readonly OUTPUT_WRONG="wrong_output.txt"
readonly OUTPUT_CORRECT_1="correct_output.txt"
readonly OUTPUT_CORRECT_2="correct_output_2.txt"

if (timeout -s 9 30 "${EXE_WRONG}") &> "${OUTPUT_WRONG}" ; then
  exit 1
fi

if ! timeout -s 9 30 "${EXE_CORRECT}" &> "${OUTPUT_CORRECT_1}" ; then
  exit 1
fi

if ! timeout -s 9 30 "${EXE_CORRECT_2}" &> "${OUTPUT_CORRECT_2}" ; then
  exit 1
fi

if ! diff -q "${OUTPUT_CORRECT_1}" "${OUTPUT_CORRECT_2}" ; then 
  exit 1
fi

if diff -q "${OUTPUT_WRONG}" "${OUTPUT_CORRECT_1}" ; then
  exit 1
fi

exit 0

