#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: Segmentation fault" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "crash_signal" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gsi_insert_seq_nodes_before" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ix86_gimple_fold_builtin(gimple_stmt_iterator*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "gimple_fold_call" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_stmt_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_stmt" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_sequence" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_gimple_bind" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lower_function_body" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0