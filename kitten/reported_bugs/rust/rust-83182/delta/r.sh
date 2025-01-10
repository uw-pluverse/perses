#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 rustc mutant.rs &> "${OUTPUT}" ; then 
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: compiler/rustc_mir/src/interpret/validity.rs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'Box<Any>'" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}" ; then
  exit 1
fi
exit 0
