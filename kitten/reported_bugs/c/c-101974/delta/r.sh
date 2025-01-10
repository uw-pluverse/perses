#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 gcc-trunk -O3 -g3 -c -Wall -Wextra mutant.c &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "internal compiler error: in from_mode_char, at attribs.h" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "attr_access::from_mode_char(char)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "init_attr_rdwr_indices(hash_map<rdwr_access_hash, attr_access, simple_hashmap_traits<default_hash_traits<rdwr_access_hash>, attr_access> >*, tree_node*)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "append_access_attr" "${OUTPUT}" ; then
  exit 1
fi
exit 0