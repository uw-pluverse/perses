#!/bin/bash

# Longest per-process wall cap in this script is 20s (enforced by `timeout`);
# set the CPU limit to 2x=40s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 40
BADCC1=()
BADCC2=()
BADCC3=("clang-3.8.0 -Os")
MODE=("-m32")

# need to configure this part
#BADCC1=("clang-7.1.0 -O3")  # compilation failures
#BADCC2=() # exec failures
#BADCC3=() # wrong results
#MODE=-m64

readonly GOODCC=("gcc-4.8.0 -O0" "clang-7.1.0 -m32 -O1")
readonly TIMEOUTCC=20
readonly TIMEOUTEXE=2
readonly TIMEOUTCCOMP=10
# flag to control whether to use CompCert to validate the test program.
readonly USE_COMPCERT=true
readonly CFILE=small.c
readonly CFLAG="-o t"
readonly CLANGFC="clang-7.1.0 -w -m64 -O0 -Wall -fwrapv -ftrapv -fsanitize=undefined,address"

#################################################################################

### check for undefined behaviors first (from creduce scripts)

rm -f out*.txt

if
  timeout -s 9 $TIMEOUTCC clang-7.1.0 -Wfatal-errors -pedantic -Wall -Wsystem-headers -O0 -c $CFILE > out.txt 2>&1 \
    && ! grep -q 'conversions than data arguments' out.txt \
    && ! grep -q 'incompatible redeclaration' out.txt \
    && ! grep -q 'ordered comparison between pointer' out.txt \
    && ! grep -q 'eliding middle term' out.txt \
    &&
    #! grep -q 'end of non-void function' out.txt &&\
    ! grep -q 'invalid in C99' out.txt \
    && ! grep -q 'specifies type' out.txt \
    && ! grep -q 'should return a value' out.txt \
    &&
    #! grep -q 'uninitialized' out.txt &&\
    ! grep -q 'incompatible pointer to' out.txt \
    && ! grep -q 'incompatible integer to' out.txt \
    && ! grep -q 'type specifier missing' out.txt \
    && timeout -s 9 $TIMEOUTCC gcc-7.1.0 -Wfatal-errors -Wall -Wextra -Wsystem-headers -O0 $CFILE > outa.txt 2>&1 \
    &&
    #  ! grep -q uninitialized outa.txt &&\
    ! grep -q 'division by zero' outa.txt \
    && ! grep -q 'without a cast' outa.txt \
    &&
    #! grep -q 'control reaches end' outa.txt &&\
    ! grep -q 'return type defaults' outa.txt \
    && ! grep -q 'cast from pointer to integer' outa.txt \
    && ! grep -q 'useless type name in empty declaration' outa.txt \
    && ! grep -q 'no semicolon at end' outa.txt \
    && ! grep -q 'type defaults to' outa.txt \
    && ! grep -q 'too few arguments for format' outa.txt \
    && ! grep -q 'incompatible pointer' outa.txt \
    && ! grep -q 'ordered comparison of pointer with integer' outa.txt \
    && ! grep -q 'declaration does not declare anything' outa.txt \
    && ! grep -q 'expects type' outa.txt \
    && ! grep -q 'pointer from integer' outa.txt \
    &&
    #  ! grep -q 'incompatible implicit' outa.txt &&\
    ! grep -q 'excess elements in struct initializer' outa.txt \
    && ! grep -q 'return type of \‘main\’ is not \‘int\’' outa.txt \
    && ! grep -q 'comparison between pointer and integer' outa.txt #&&\
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
if $USE_COMPCERT; then
  timeout -s 9 $TIMEOUTCCOMP ccomp -interp -fall $CFILE >&/dev/null
  ret=$?
  if [ $ret != 0 ]; then
    exit 1
  fi
fi
# The MemorySanitizer stage that used to sit here was dropped: `ccomp -interp` above
# already rejects uninitialized reads, and does so strictly more aggressively than MSan
# (it is stuck even on `<undef> & 0`, which MSan considers defined). The MSan runtime
# also fails to map its shadow memory under ASLR at random, which made this oracle
# non-deterministic. See internal_doc/taotie_c_benchmark_determinism.md.

###################################################
# @ clangtkfc @ -O0 to check for undefined behavior
###################################################

rm -f ./t ./out*.txt
timeout -s 9 $TIMEOUTCC $CLANGFC $CFLAG $CFILE > /dev/null
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

(timeout -s 9 $TIMEOUTEXE ./t > out0.txt 2>&1) >&/dev/null
ret=$?

if [ $ret != 0 ]; then
  exit 1
fi

if grep -q "runtime error" out0.txt; then
  exit 1
fi

#############################
# iterate over the good ones
#############################

#for cc in "${GOODCC[@]}" ; do
for ((i = 0; i < ${#GOODCC[@]}; ++i)); do
  cc=${GOODCC[$i]}
  rm -f ./t ./out1.txt

  timeout -s 9 $TIMEOUTCC $cc $CFLAG $CFILE >&/dev/null
  ret=$?
  if [ $ret != 0 ]; then
    exit 1
  fi

  # execute
  (timeout -s 9 $TIMEOUTEXE ./t > out1.txt 2>&1) >&/dev/null
  ret=$?
  if [ $ret != 0 ]; then
    exit 1
  fi

  if [[ "$i" == 0 ]]; then
    mv out1.txt out0.txt
    continue
  fi

  # compare with reference: out0.txt
  if ! diff -q out0.txt out1.txt > /dev/null; then
    exit 1
  fi
done

#############################
# iterate over the bad ones
#############################

for cc in "${BADCC1[@]}"; do
  for mode in "${MODE[@]}"; do
    rm -f ./t ./out2.txt

    # compile
    (timeout -s 9 $TIMEOUTCC $cc $CFLAG $mode $CFILE > out2.txt 2>&1) >&/dev/null
    if ! grep -q 'internal compiler error' out2.txt \
      && ! grep -q 'PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT' out2.txt \
      && ! grep -q 'clang: error: linker command failed with exit code 1 (use -v to see invocation)' out2.txt; then
      exit 1
    fi
  done
done

for cc in "${BADCC2[@]}"; do
  for mode in "${MODE[@]}"; do
    rm -f ./t ./out2.txt

    # compile
    timeout -s 9 $TIMEOUTCC $cc $CFLAG $mode $CFILE >&/dev/null
    ret=$?
    if [ $ret -ne 0 ]; then
      exit 1
    fi

    # execute
    (timeout -s 9 $TIMEOUTEXE ./t > out2.txt 2>&1) >&/dev/null
    ret=$?
    if [ $ret -ne 137 ]; then
      exit 1
    fi
  done
done

for cc in "${BADCC3[@]}"; do
  for mode in "${MODE[@]}"; do
    rm -f ./t ./out2.txt

    # compile
    timeout -s 9 $TIMEOUTCC $cc $CFLAG $mode $CFILE >&/dev/null
    ret=$?
    if [ $ret != 0 ]; then
      exit 1
    fi

    # execute
    (timeout -s 9 $TIMEOUTEXE ./t > out2.txt 2>&1) >&/dev/null
    ret=$?
    if [ $ret != 0 ]; then
      exit 1
    fi

    # compare with reference: out0.txt
    if diff -q out0.txt out2.txt > /dev/null; then
      exit 1
    fi
  done
done

# now we have passed everything, return 0
exit 0
