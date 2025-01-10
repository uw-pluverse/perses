#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: tree check: expected string_cst, have ne_expr in get_attr_len, at multiple_target.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_check_failed(tree_node const*, char const*, int, char const*, ...)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "tree_check(tree_node*, char const*, int, char const*, tree_code)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "get_attr_len" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_target_clones" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ipa_target_clone" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0