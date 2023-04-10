#!/bin/bash

# need to configure this part 
BADCC1=("clang-3.4.2 -m32 -O2") # compilation failures
BADCC2=() # exec failures 
BADCC3=() # wrong results 
GOODCC=("clang-3.6.0 -m32 -O2") 
TIMEOUTBAD=10
TIMEOUTCC=3
TIMEOUTEXE=2
TIMEOUTCCOMP=8
CFLAG="-o t"
CLANGFC="clang-7.1.0 -m32 -O0 -Wall -fwrapv -ftrapv -fsanitize=undefined"



#################################################################################
CFILE=small.c

### check for undefined behaviors first (from creduce scripts) 

rm -f out*.txt 

if 
  clang-7.1.0 -pedantic -Wall -Wsystem-headers -O0 -c $CFILE  >out.txt 2>&1 &&\
  ! grep 'conversions than data arguments' out.txt &&\
  ! grep 'incompatible redeclaration' out.txt &&\
  ! grep 'ordered comparison between pointer' out.txt &&\
  ! grep 'eliding middle term' out.txt &&\
  ! grep 'end of non-void function' out.txt &&\
  ! grep 'invalid in C99' out.txt &&\
  ! grep 'specifies type' out.txt &&\
  ! grep 'should return a value' out.txt &&\
  ! grep 'uninitialized' out.txt &&\
  ! grep 'incompatible pointer to' out.txt &&\
  ! grep 'incompatible integer to' out.txt &&\
  ! grep 'type specifier missing' out.txt &&\
  gcc-7.1.0 -Wall -Wextra -Wsystem-headers -O0 $CFILE >outa.txt 2>&1 &&\
  ! grep uninitialized outa.txt &&\
  ! grep 'division by zero' outa.txt &&\
  ! grep 'without a cast' outa.txt &&\
  ! grep 'control reaches end' outa.txt &&\
  ! grep 'return type defaults' outa.txt &&\
  ! grep 'cast from pointer to integer' outa.txt &&\
  ! grep 'useless type name in empty declaration' outa.txt &&\
  ! grep 'no semicolon at end' outa.txt &&\
  ! grep 'type defaults to' outa.txt &&\
  ! grep 'too few arguments for format' outa.txt &&\
  ! grep 'incompatible pointer' outa.txt &&\
  ! grep 'ordered comparison of pointer with integer' outa.txt &&\
  ! grep 'declaration does not declare anything' outa.txt &&\
  ! grep 'expects type' outa.txt &&\
  ! grep 'pointer from integer' outa.txt &&\
  ! grep 'incompatible implicit' outa.txt &&\
  ! grep 'excess elements in struct initializer' outa.txt &&\
  ! grep 'return type of \‘main\’ is not \‘int\’' outa.txt &&\
  ! grep 'comparison between pointer and integer' outa.txt #&&\
#  frama-c -val-signed-overflow-alarms -val -stop-at-first-alarm -no-val-show-progress -machdep x86_64 -obviously-terminates -precise-unions $CFILE >out_framac.txt 2>&1 &&\
#  ! egrep -i '(user error|assert)' out_framac.txt >/dev/null 2>&1
then 
    : # do nothing 
else 
    exit 1 
fi 

#
# compcert first 
#

timeout -s 9 $TIMEOUTCCOMP ccomp -interp -fall $CFILE >& /dev/null
ret=$? 
if [ $ret != 0 ] ; then 
    exit 1 
fi

###################################################
# @ clangtkfc @ -O0 to check for undefined behavior  
###################################################

rm -f ./t ./out*.txt 
timeout -s 9 $TIMEOUTCC $CLANGFC $CFLAG $CFILE >& /dev/null
ret=$? 

if [ $ret != 0 ] ; then 
    # interesting, save a copy  
    cp $CFILE $DIR/`date +%j:%T`-compile-$CFILE
    exit 1 
fi 

(timeout -s 9 $TIMEOUTEXE ./t >out0.txt 2>&1) >&/dev/null
ret=$? 

if [ $ret != 0 ] ; then 
    cp $CFILE $DIR/`date +%j:%T`-exe-$CFILE
    exit 1 
fi 

if grep -q "runtime error" out0.txt ; then 
    cp $CFILE $DIR/`date +%j:%T`-result-$CFILE
    exit 1
fi 

#############################
# iterate over the good ones 
#############################


for cc in "${GOODCC[@]}" ; do 
    rm -f ./t ./out1.txt 

    timeout -s 9 $TIMEOUTCC $cc $CFLAG $CFILE >& /dev/null
    ret=$? 
    if [ $ret != 0 ] ; then 
    exit 1 
    fi

    # execute 
    (timeout -s 9 $TIMEOUTEXE ./t >out1.txt 2>&1) >&/dev/null
    ret=$? 
    if [ $ret != 0 ] ; then 
    exit 1 
    fi 
    
    # compare with reference: out0.txt 
    if ! diff -q out0.txt out1.txt >/dev/null ; then
    exit 1
    fi    
done

#############################
# iterate over the bad ones 
#############################

for cc in "${BADCC1[@]}" ; do 
    rm -f ./t ./out2.txt 

    # compile 
    timeout -s 9 $TIMEOUTBAD $cc $CFLAG $CFILE >& /dev/null
    ret=$? 
    if [ $ret -ne 137 ] ; then 
    exit 1
    fi
done

for cc in "${BADCC2[@]}" ; do 
    rm -f ./t ./out2.txt 

    # compile 
    timeout -s 9 $TIMEOUTCC $cc $CFLAG $CFILE >& /dev/null
    ret=$? 
    if [ $ret -ne 0 ] ; then 
    exit 1 
    fi

    # execute 
    (timeout -s 9 $TIMEOUTEXE ./t >out2.txt 2>&1) >&/dev/null
    ret=$? 
    if [ $ret -ne 137 ] ; then 
    exit 1 
    fi 
done

for cc in "${BADCC3[@]}" ; do 
    rm -f ./t ./out2.txt 

    # compile 
    timeout -s 9 $TIMEOUTCC $cc $CFLAG $CFILE >& /dev/null
    ret=$? 
    if [ $ret != 0 ] ; then 
    exit 1 
    fi

    # execute 
    (timeout -s 9 $TIMEOUTEXE ./t >out2.txt 2>&1) >&/dev/null
    ret=$? 
    if [ $ret != 0 ] ; then 
    exit 1 
    fi 
    
    # compare with reference: out0.txt 
    if diff -q out0.txt out2.txt >/dev/null ; then
    exit 1
    fi    
done

# now we have passed everything, return 0
exit 0 
