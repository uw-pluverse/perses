#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly SIGNATURE='the compiler unexpectedly panicked. this is a bug.'
readonly OUTPUT="compilation_output.txt"
if timeout -s 9 30 /home/cnsun/.cargo/bin/rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=z -C target-cpu=skylake mutant.rs &> "${OUTPUT}" ; then 
  exit 1
fi
if grep --quiet "${SIGNATURE}" "${OUTPUT}" ; then 
  exit 0
else
  exit 1
fi