#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: symtab_node::verify failed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symtab_node::verify()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symtab_node::verify_symtab_nodes()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symtab_node::checking_verify_symtab_nodes()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::compile()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::finalize_compilation_unit()" "${OUTPUT}" ; then
  exit 1
fi
exit 0