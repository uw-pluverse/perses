#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in maybe_canonicalize_mem_ref_addr, at gimple-fold.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "maybe_canonicalize_mem_ref_addr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_stmt_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "substitute_and_fold_dom_walker::before_dom_children(basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "dom_walker::walk(basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "substitute_and_fold_engine::substitute_and_fold(basic_block_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_early_vrp" "${OUTPUT}" ; then
  exit 1
fi
exit 0