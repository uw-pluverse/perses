#!/usr/bin/env bash 

if [[ $# == 0 ]] ; then 
  SUFFIX=""
else 
  SUFFIX=$1
fi

set -o pipefail
set -o nounset

readonly PERSES="perses_node_priority_with_dfs_delta"
readonly HDD="hdd"

for subject in $(ls -d clang-* gcc-*) ; do
  echo "Runtime Statistics for ${subject}"
  echo "<<<<<< HDD >>>>>>"
  tail -n 4 ${subject}/exp-${HDD}${SUFFIX}/log.txt
  echo ""
  echo "<<<<<< Perses >>>>>>"
  tail -n 4 ${subject}/exp-${PERSES}${SUFFIX}/log.txt
  echo ""
  echo ""
done

