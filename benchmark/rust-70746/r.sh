#!/usr/bin/env bash

# Longest per-process wall cap in this script is 30s (enforced by `timeout`);
# set the CPU limit to 2x=60s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 60
set -o nounset
set -o pipefail

readonly RUSTC_VERSION="1.42.0"

readonly OUTPUT="temp_compilation_output.tmp.txt"

if ! timeout -s 9 30 rustc -Z parse-only mutant.rs &> /dev/null; then
  # make sure the source file is syntactically correct.
  exit 1
fi

if timeout -s 9 30 rustup run "${RUSTC_VERSION}" rustc mutant.rs &> "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: src/librustc/traits/codegen/mod.rs" "${OUTPUT}"; then
  exit 1
fi

if ! grep --quiet --fixed-strings "[FulfillmentError(Obligation(predicate=Binder(TraitPredicate(<dyn Callback<T1, Output = ()> as std::ops::FnMut<(usize,)>>))" "${OUTPUT}"; then
  exit 1
fi

exit 0
