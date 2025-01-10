#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in convert_move, at expr.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "convert_move(rtx_def*, rtx_def*, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "convert_modes(machine_mode, machine_mode, rtx_def*, int)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assign_parm_setup_reg" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "assign_parms" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "expand_function_start(tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0