#!/usr/bin/env bash

GOODCC=("clang -O0 -m64 -w -fwrapv -ftrapv -fsanitize=undefined"
        "clang -O1 -m64 -w -fwrapv -ftrapv -fsanitize=undefined"
        "clang -O2 -m64 -w -fwrapv -ftrapv -fsanitize=undefined"
        "clang -O3 -m64 -w -fwrapv -ftrapv -fsanitize=undefined"
        "clang -O0 -m64 -w -fwrapv -ftrapv -fsanitize=address"
        )
readonly TIMEOUTCC=10
readonly TIMEOUTEXE=2
readonly CFILE=small.c
readonly EXE="test.out"

rm -f out*.txt 

if 
  clang -pedantic -Wall -Wsystem-headers -O0 -c $CFILE  >out.txt 2>&1 &&\
  ! grep 'conversions than data arguments' out.txt &&\
  ! grep 'incompatible redeclaration' out.txt &&\
  ! grep 'ordered comparison between pointer' out.txt &&\
  ! grep 'eliding middle term' out.txt &&\
  ! grep 'end of non-void function' out.txt &&\
  ! grep 'invalid in C99' out.txt &&\
  ! grep 'specifies type' out.txt &&\
  ! grep 'should return a value' out.txt &&\
  ! grep 'incompatible pointer to' out.txt &&\
  ! grep 'incompatible integer to' out.txt &&\
  ! grep 'type specifier missing' out.txt
then 
    : # do nothing 
else 
    exit 1 
fi 

#############################
# iterate over the good ones 
#############################


for cc in "${GOODCC[@]}" ; do 
    rm -f "${EXE}" ./out1.txt

    timeout -s 9 $TIMEOUTCC $cc -o "${EXE}" "${CFILE}" >& /dev/null
    ret=$? 
    if [ $ret != 0 ] ; then 
	    exit 1
    fi

    # execute 
    (timeout -s 9 $TIMEOUTEXE ./${EXE} >out1.txt 2>&1) >&/dev/null
    ret=$? 
    if [ $ret != 0 ] ; then 
	    exit 1
    fi 

    if ! grep "checksum = A3477CE8" out1.txt >/dev/null ; then
	    exit 1
    fi    
done

# now we have passed everything, return 0
exit 0 
