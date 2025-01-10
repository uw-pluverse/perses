#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in replace_reg, at reg-stack.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "replace_reg" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "compare_for_stack_reg" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "subst_stack_regs_pat" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "subst_stack_regs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "convert_regs_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "convert_regs_2" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "convert_regs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "reg_to_stack" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "rest_of_handle_stack_regs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0