#!/usr/bin/env bash

set -o pipefail
set -o nounset

# need to configure this part
WHICH=0     # 0: gcc; 1: clang
GOODCOMP=1  # 0: doesn't compile; 1: compiles
BADCC=("gcc-6.1.0 -O3")
GOODCC=("gcc-4.8.0 -O0 -c")
CFILE=small.c
TIMEOUTCC=10

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
  if [[ $? != 137 ]] ; then 
    exit 1
  fi
  
done

exit 0
