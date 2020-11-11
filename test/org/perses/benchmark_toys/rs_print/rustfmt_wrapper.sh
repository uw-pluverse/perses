#!/usr/bin/env bash

set -o pipefail
set -o nounset

if [[ "$#" != 2 ]] ; then
  echo "USAGE: $0 <input> <output>"
  exit 1
fi

ALTS=("rustfmt"
  "rustfmt +1.47.0"
  "rustfmt +1.46.0"
  "rustfmt +1.45.0"
  "rustfmt +1.44.0"
  "rustfmt +1.43.0"
  "rustfmt +1.42.0"
  "rustfmt +1.41.0"
  "rustfmt +1.40.0"
  "rustfmt +1.39.0"
  "rustfmt +1.38.0"
  "rustfmt +1.37.0"
  "rustfmt +1.36.0"
  "rustfmt +1.35.0"
  "rustfmt +1.34.0"
  "rustfmt +1.33.0"
  "rustfmt +1.32.0"
  "rustfmt +1.31.0"
  "rustfmt +1.30.0"
  "rustfmt +1.29.0"
  "rustfmt +1.28.0"
  "rustfmt +1.27.0"
)

readonly TMP=$(mktemp)
trap "rm ${TMP}" TRAP
cp "${1}" "${TMP}"
for alt in "${ALTS[@]}" ; do
  if ${alt} "${TMP}" ; then
    cp "${TMP}" "${2}"
    exit 0
  fi
done
exit 1