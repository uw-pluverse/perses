#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g -Wall -Wextra -c mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in ao_ref_init_from_ptr_and_range, at tree-ssa-alias.c" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "ao_ref_init_from_ptr_and_range" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "maybe_warn_pass_by_reference" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "warn_uninitialized_vars" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0