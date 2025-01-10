#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: output_operand: invalid expression as operand" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "output_operand_lossage(char const*, ...)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "output_addr_const(_IO_FILE*, rtx_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assemble_integer_with_op(char const*, rtx_def*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "default_assemble_integer(rtx_def*, unsigned int, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assemble_integer(rtx_def*, unsigned int, unsigned int, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "output_constant" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assemble_variable_contents" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assemble_variable(tree_node*, int, int, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "varpool_node::assemble_decl()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::output_variables()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::compile()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "symbol_table::finalize_compilation_unit()" "${OUTPUT}" ; then
  exit 1
fi
exit 0