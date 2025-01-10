#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly VERSION="nightly-2020-11-03"
rustup toolchain install "${VERSION}" --force

readonly OUTPUT="temp_compilation_output.tmp.txt"

if ! rustup run "${VERSION}" rustc -Z parse-only mutant.rs ; then
  exit 1
fi

if timeout -s 9 30 rustup run "${VERSION}" rustc --crate-type=staticlib -C debuginfo=2 -C opt-level=1 -C target-cpu=skylake mutant.rs &> "${OUTPUT}" ; then 
  exit 1
fi

if ! grep --quiet --fixed-strings "error: internal compiler error: /rustc/338f939a8d77061896cd0a1ca87a2c6d1f4ec359/compiler/rustc_middle/src/ty/sty.rs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "thread 'rustc' panicked at 'Box<Any>'" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "note: the compiler unexpectedly panicked. this is a bug." "${OUTPUT}" ; then
  exit 1
fi
exit 0
