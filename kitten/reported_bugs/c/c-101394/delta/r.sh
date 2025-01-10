#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: SSA corruption" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "fail_abnormal_edge_coalesce" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "coalesce_partitions" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "coalesce_ssa_name(_var_map*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "remove_ssa_form" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "rewrite_out_of_ssa(ssaexpand*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0