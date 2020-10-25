#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if !  timeout -s 9 30 rustc -Z parse-only mutant.rs &> /dev/null ; then
  # make sure the source file is syntactically correct.
  exit 1
fi

if timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=z -C target-cpu=skylake mutant.rs &> "${OUTPUT}" ; then 
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: compiler/rustc_middle/src/ty/sty.rs:2150:18: tuple_fields called on non-tuple" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'Box<Any>', compiler/rustc_errors/src/lib.rs:945:9" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}" ; then
  exit 1
fi
exit 0
