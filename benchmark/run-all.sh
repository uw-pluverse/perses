#!/usr/bin/env bash

set -o pipefail
set -o nounset

if [[ $# != 1 ]] ; then
  echo "Usage: $0 <iteration count>"
  exit 1
fi

readonly MAX_ITERATION=$1

readonly PERSES="perses_node_priority_with_dfs_delta"
readonly HDD="hdd"
readonly JVM_FLAGS="-Xmx11G"

export JVM_FLAGS

for iteration in $(seq $MAX_ITERATION) ; do
  for subject in $(ls -d clang-* gcc-*) ; do
    echo "running an experiment with $subject"
    echo "running hdd"
    ./run-exp.sh "$HDD-iteration-${iteration}" $subject "perses.sh --fixpoint true --alg $HDD "
    echo "running perses"
    ./run-exp.sh "$PERSES-iteration-${iteration}" $subject "perses.sh --fixpoint true --alg $PERSES "
  done
done

