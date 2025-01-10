#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in fold_convert_loc, at fold-const.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_convert_loc(unsigned int, tree_node*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fold_stmt_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0