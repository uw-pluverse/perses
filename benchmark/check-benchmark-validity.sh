#!/usr/bin/env bash
# Check the subjects in the benchmark folder can pass the initial test. 

set -o pipefail
set -o nounset

for subject in $(ls -d clang-* gcc-* ) ; do
  echo "Checking subject $subject"
  if ! (cd $subject ; ./r.sh) &> /dev/null ; then
    echo "The subject $subject failed the initial testing"
    exit 1
  fi 
done


