#!/usr/bin/env bash

# Longest per-process wall cap in this script is 30s (enforced by `timeout`);
# set the CPU limit to 2x=60s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 60
readonly WHICH=0
readonly GOODCOMP=1
BADCC=('gcc-5.1 -c -O3')
GOODCC=('gcc-4.9 -c ')
CFILE=small.c

set -o pipefail
set -o nounset

# need to configure this part
# WHICH=1     # 0: gcc; 1: clang; 2: CompCert
# GOODCOMP=0  # 0: doesn't compile; 1: compiles
# BADCC=("clang-7.1.0 -c")
# GOODCC=("g++-6.1 -std=c++11 -c")
# CFILE=small.c
# ICE_MSG=compiler crashing message
readonly TIMEOUTCC=30
readonly CFLAG=""
rm -f out*.txt

#############################
# use indent to sanitize the program
#############################
readonly INDENT_TEMP_OUTPUT="temp.indent.output.tmp"
if ! indent ${CFILE} -o ${INDENT_TEMP_OUTPUT}; then
  exit 1
fi

#############################
# iterate over the good ones
#############################

for cc in "${GOODCC[@]}"; do
  rm -f ./t ./out1.txt

  (timeout -s 9 $TIMEOUTCC $cc $CFLAG $CFILE > out1.txt 2>&1) >&/dev/null
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
    if grep ':[0-9]*: error: ' out1.txt \
      | grep -F -v -f ${GOOD_INCLUSIVE_ERROR_MSG_FILE}; then
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
      || ! grep "${ICE_MSG}" out2.txt; then
      exit 1
    fi
  elif [ $WHICH -eq 0 ]; then # gcc
    if ! grep 'internal compiler error: ' out2.txt; then
      exit 1
    fi
  elif [ $WHICH -eq 2 ]; then # CompCert
    if ! grep "Fatal error: " out2.txt \
      || ! grep "${ICE_MSG}" out2.txt; then
      exit 1
    fi
  else
    echo "the variable WHICH is not defined"
    exit 1
  fi
done

exit 0
