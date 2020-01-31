#!/usr/bin/env bash

set -o pipefail
set -o nounset

# need to configure this part
WHICH=0     # 0: gcc; 1: clang
GOODCOMP=1  # 0: doesn't compile; 1: compiles
BADCC=("gcc-4.8 -O3 -c")
GOODCC=("gcc-7.1.0 -c")
CFILE=small.c
TIMEOUTCC=30

rm -f out*.txt

#############################
# iterate over the good ones
#############################

for cc in "${GOODCC[@]}" ; do
  rm -f ./t ./out1.txt
  
  (timeout -s 9 $TIMEOUTCC $cc $CFILE > out1.txt 2>&1) >& /dev/null
  ret=$?
  
  if [ $GOODCOMP -eq 1 ] ; then # does compile
    if [ $ret -ne 0 ] ; then
      exit 1
    fi
  else # does not compile, so make sure it doesn't ICE
    if grep 'internal compiler error: ' out1.txt ||\
    grep 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT' out1.txt
    then
      exit 1
    fi
  fi
done

#############################
# iterate over the bad ones
#############################

for cc in "${BADCC[@]}" ; do
  rm -f ./t ./out2.txt
  
  (timeout -s 9 $TIMEOUTCC $cc $CFILE > out2.txt 2>&1) >& /dev/null
  
  if [ $WHICH -eq 1 ] ; then # clang
    if ! grep 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT' out2.txt ||\
    ! grep 'The annotation should be until the most recent cached token' out2.txt ||\
    grep ':[0-9]*: error: ' out2.txt | grep -E -v 'error: expected'  #conflicting|error: declaration|error: variable'
    then
      exit 1
    fi
  else # gcc
    if ! grep 'internal compiler error: in get_expr_operands' out2.txt 
    then
      exit 1
    fi
  fi
done

exit 0
