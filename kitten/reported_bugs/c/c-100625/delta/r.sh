#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -fgimple -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: Segmentation fault" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "crash_signal" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "contains_struct_check(tree_node*, tree_node_structure_enum, char const*, int, char const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "stmt_starts_bb_p" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "make_blocks_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "make_blocks" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "build_gimple_cfg" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute_build_cfg" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0
