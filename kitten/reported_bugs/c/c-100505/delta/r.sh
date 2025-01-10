#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in record_in_finally_tree, at tree-eh.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "record_in_finally_tree" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "collect_finally_tree_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0