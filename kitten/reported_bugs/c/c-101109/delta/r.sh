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

if ! grep --quiet --fixed-strings "tree_check(tree_node*, char const*, int, char const*, tree_code)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "default_elf_asm_named_section(char const*, unsigned int, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "switch_to_section(section*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assemble_start_function(tree_node*, char const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "rest_of_handle_final" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0