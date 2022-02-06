#!/usr/bin/env bash

set -o nounset
set -o pipefail

if [[ "$#" != 1 ]] ; then
  echo "Usage: $0 <log file>"
  exit 1
fi

readonly FILE="$1"

if grep --quiet 'Fixpoint\[0\]' "${FILE}" ; then
  echo "Fixpoint iterations should start with 1, but not 0"
  exit 1
fi

grep --quiet 'perses_node_priority_with_dfs_delta' "${FILE}" || exit 1

awk '/Fixpoint\[1\]/,/Fixpoint\[2\]/' "${FILE}" | grep --quiet 'Fixpoint\[2\]'