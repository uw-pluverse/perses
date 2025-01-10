#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: Segmentation fault" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "crash_signal" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_optimize_slp(vec_info*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_slp_analyze_bb_1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_slp_region" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_slp_bbs" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "vect_slp_function(function*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "execute" "${OUTPUT}" ; then
  exit 1
fi
exit 0