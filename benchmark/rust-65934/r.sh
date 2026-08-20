#!/usr/bin/env bash

# Longest per-process wall cap in this script is 30s (enforced by `timeout`);
# set the CPU limit to 2x=60s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 60
set -o nounset
set -o pipefail

readonly VERSION="nightly-2019-10-30"
rustup toolchain install "${VERSION}" --force || exit 1

readonly OUTPUT="temp_compilation_output.tmp.txt"

if ! timeout -s 9 30 rustup run "${VERSION}" rustc -Z parse-only mutant.rs; then
  exit 1
fi

if timeout -s 9 30 rustup run "${VERSION}" rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=z -C target-cpu=skylake mutant.rs &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error:" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "broken MIR in DefId" "${OUTPUT}"; then
  exit 1
fi

exit 0
