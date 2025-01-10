#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in lra_split_hard_reg_for, at lra-assigns.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "_fatal_insn(char const*, rtx_def const*, char const*, int, char const*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lra_split_hard_reg_for()" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "lra(_IO_FILE*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "do_reload" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0