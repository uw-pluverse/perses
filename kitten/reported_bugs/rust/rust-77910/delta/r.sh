#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=1 -C target-cpu=skylake mutant.rs &> "${OUTPUT}" ; then 
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'assertion failed: !bounds.has_escaping_bound_vars()', compiler/rustc_typeck/src/check/method/mod.rs:388:9" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: unexpected panic" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: trimmed_def_paths constructed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'no warnings or errors encountered even though \`delayed_good_path_bugs\` issued', compiler/rustc_errors/src/lib.rs:961:13" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread panicked while panicking. aborting." "${OUTPUT}" ; then
  exit 1
fi
exit 0