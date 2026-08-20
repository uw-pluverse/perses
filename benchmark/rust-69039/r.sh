#!/usr/bin/env bash

# Longest per-process wall cap in this script is 60s (enforced by `timeout`);
# set the CPU limit to 2x=120s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 120

set -o nounset

readonly FILE="mutant.rs"

readonly BUGGY_RUSTC_VERSION="nightly-2020-02-10"
readonly CORRECT_RUSTC_VERSION="nightly-2020-11-05"
rustup toolchain install "${BUGGY_RUSTC_VERSION}" --force
rustup toolchain install "${CORRECT_RUSTC_VERSION}" --force

readonly EXE_WRONG="./wrong.out"
if ! timeout -s 9 60 rustup run "${BUGGY_RUSTC_VERSION}" rustc -o "${EXE_WRONG}" "${FILE}"; then
  exit 1
fi

readonly EXE_CORRECT="./correct.out"
if ! timeout -s 9 60 rustup run "${CORRECT_RUSTC_VERSION}" rustc -o "${EXE_CORRECT}" "${FILE}"; then
  exit 1
fi

readonly EXE_CORRECT_2="./correct_2.out"
if ! timeout -s 9 60 rustup run "${CORRECT_RUSTC_VERSION}" rustc -Z mir-opt-level=2 -o "${EXE_CORRECT_2}" "${FILE}"; then
  exit 1
fi

readonly OUTPUT_WRONG="wrong_output.txt"

if (echo -e "a\nb" | timeout -s 9 30 "${EXE_WRONG}") &> "${OUTPUT_WRONG}"; then
  exit 1
fi

if ! grep "Segmentation fault" "${OUTPUT_WRONG}"; then
  exit 1
fi

readonly OUTPUT_CORRECT_1="correct_output.txt"
readonly OUTPUT_CORRECT_2="correct_output_2.txt"
if ! timeout -s 9 30 echo -e "a\nb" | "${EXE_CORRECT}" &> "${OUTPUT_CORRECT_1}"; then
  exit 1
fi

if ! timeout -s 9 30 echo -e "a\nb" | "${EXE_CORRECT_2}" &> "${OUTPUT_CORRECT_2}"; then
  exit 1
fi

if ! diff "${OUTPUT_CORRECT_1}" "${OUTPUT_CORRECT_2}"; then
  exit 1
fi

exit 0
