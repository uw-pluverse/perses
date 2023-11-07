#!/usr/bin/env bash

set -o nounset
set -o pipefail

if [[ "$#" != 1 ]] ; then
  echo "Usage: $0 <log file>"
  exit 1
fi

readonly FILE="$1"

if grep --quiet 'Fixpoint\[\(0\|[2-9][0-9]*\)\]' "${FILE}" ; then
  echo "Fixpoint is disabled for each individual reducer, so the iteration number should only be 1"
  exit 1
fi

if ! grep --quiet 'Reduction algorithm is perses_node_priority_with_dfs_delta' "${FILE}" ; then
  echo "Reduction algorithm should be perses_node_priority_with_dfs_delta"
  exit 1
fi

if ! grep --quiet 'Start tree-based diff reduction on both trees' "${FILE}" ; then
  echo "tree-based diff reduction is missing"
  exit 1
fi

if ! grep --quiet 'Start list-based diff reduction on seed' "${FILE}" ; then
  echo "list-based diff reduction on seed is missing"
  exit 1
fi

if ! grep --quiet 'Start list-based diff reduction on variant' "${FILE}" ; then
  echo "list-based diff reduction on variant is missing"
  exit 1
fi

if ! grep --quiet 'Start commonality reduction, from seed to variant' "${FILE}" ; then
  echo "commonality reduction is missing"
  exit 1
fi

exit 0
