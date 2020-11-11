#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly RUSTC_VERSION="1.42.0"

readonly OUTPUT="temp_compilation_output.tmp.txt"

if !  timeout -s 9 30 rustc -Z parse-only mutant.rs &> /dev/null ; then
  # make sure the source file is syntactically correct.
  exit 1
fi

if timeout -s 9 30 rustup run "${RUSTC_VERSION}" rustc mutant.rs &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: src/librustc/traits/codegen/mod.rs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "[FulfillmentError(Obligation(predicate=Binder(TraitPredicate(<dyn Callback<T1, Output = ()> as std::ops::FnMut<(usize,)>>))" "${OUTPUT}" ; then
  exit 1
fi

exit 0
