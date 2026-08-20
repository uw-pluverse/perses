#!/usr/bin/env bash

# Longest per-process wall cap in this script is 30s (enforced by `timeout`);
# set the CPU limit to 2x=60s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 60

readonly REDUCTION_STAT_FILE=${REDUCTION_STAT_FILE:-""}
if [[ -n "${REDUCTION_STAT_FILE}" ]]; then
  #  echo "------------------------------------------------------------------------------" >> "/tmp/reductionstatfile.txt"
  #  echo "written reduction stat file '${REDUCTION_STAT_FILE}' " >> "/tmp/reductionstatfile.txt"
  #  echo "------------------------------------------------------------------------------" >> "/tmp/reductionstatfile.txt"
  date +%Y%m%d_%H%M%S_%Z >> "${REDUCTION_STAT_FILE}"
fi

set -o pipefail
set -o nounset

# need to configure this part
WHICH=0    # 0: gcc; 1: clang
GOODCOMP=1 # 0: doesn't compile; 1: compiles
BADCC=("gcc-4.9.0 -O3")
GOODCC=("gcc")
CFILE=small.c
TIMEOUTCC=30

rm -f out*.txt

#############################
# iterate over the good ones
#############################

for cc in "${GOODCC[@]}"; do
  rm -f ./t ./out1.txt

  (timeout -s 9 $TIMEOUTCC $cc $CFILE > out1.txt 2>&1) >&/dev/null
  ret=$?

  if [ $GOODCOMP -eq 1 ]; then # does compile
    if [ $ret -ne 0 ]; then
      exit 1
    fi
  else # does not compile, so make sure it doesn't ICE
    if grep 'internal compiler error: ' out1.txt \
      || grep 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT' out1.txt; then
      exit 1
    fi
  fi
done

#############################
# iterate over the bad ones
#############################

for cc in "${BADCC[@]}"; do
  rm -f ./t ./out2.txt

  (timeout -s 9 $TIMEOUTCC $cc $CFILE > out2.txt 2>&1) >&/dev/null

  if [ $WHICH -eq 1 ]; then # clang
    if ! grep 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT' out2.txt \
      || ! grep 'The annotation should be until the most recent cached token' out2.txt \
      || grep ':[0-9]*: error: ' out2.txt | grep -E -v 'error: expected'; then #conflicting|error: declaration|error: variable'
      exit 1
    fi
  else # gcc
    if ! grep 'internal compiler error: in output_constant_pool_2' out2.txt; then
      exit 1
    fi
  fi
done

exit 0
