#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if ! timeout -s 9 30 rustc -Z parse-only mutant.rs &> /dev/null ; then 
  # syntactically invalid.
  exit 1
fi
if timeout -s 9 30 rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=z -C target-cpu=skylake mutant.rs &> "${OUTPUT}" ; then 
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'assertion failed: body.yield_ty.is_some() && universal_regions.yield_ty.is_some() ||" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: unexpected panic" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}" ; then
  exit 1
fi
exit 0
