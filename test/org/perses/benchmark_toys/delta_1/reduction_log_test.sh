#!/usr/bin/env bash

set -o nounset
set -o pipefail

if [[ "$#" != 1 ]]; then
  echo "Usage: $0 <log file>"
  exit 1
fi

readonly FILE="$1"

if ! grep --quiet 'FixPt\[1\]' "${FILE}" ; then
  echo "No Fixpoint information is printed."
  exit 1
fi

if grep --quiet 'FixPt\[0\]' "${FILE}"; then
  echo "Fixpoint iterations should start with 1, but not 0"
  exit 1
fi

grep --quiet 'node_priority-dfs' "${FILE}" || exit 1

awk '/FixPt\[1\]/,/FixPt\[2\]/' "${FILE}" | grep --quiet 'FixPt\[2\]'
