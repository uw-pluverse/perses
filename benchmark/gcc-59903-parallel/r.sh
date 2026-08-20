#!/bin/bash

# Longest per-process wall cap in this script is 30s (enforced by `timeout`);
# set the CPU limit to 2x=60s so real runs finish, but a process that outlives
# `timeout` (e.g. a compiler grandchild orphaned when its driver was SIGKILLed) is
# reaped by the kernel via RLIMIT_CPU, which `timeout` cannot reach across reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 60

# Configuration (mirrored from r.sh)
BADCC=("gcc-4.8.2 -m32 -O3")
GOODCC=("ccomp -fall")
TIMEOUTCC=10
TIMEOUT=30
CFILE=small.c
CFLAG="-o t"
CLANGFC="clang-7.1.0 -O0 -Wall -fwrapv -ftrapv -fsanitize=undefined,address"

WORK_DIR=$(pwd)
CFILE_ABS="$WORK_DIR/$CFILE"

# Track temporary directories for cleanup
CLEANUP_DIRS=()
cleanup() {
    for dir in "${CLEANUP_DIRS[@]}"; do
        rm -rf "$dir"
    done
}
trap cleanup EXIT

# ------------------------------------------------------------------------------
# Task Definitions
# ------------------------------------------------------------------------------

# Sanity check for Clang warnings
check_sanity_clang() {
    timeout -s 9 $TIMEOUTCC clang-7.1.0 -pedantic -Wall -Wsystem-headers -O0 -c $CFILE > out.txt 2>&1 \
        && ! grep -q -E 'conversions than data arguments|incompatible redeclaration|ordered comparison between pointer|eliding middle term|end of non-void function|invalid in C99|specifies type|should return a value|incompatible pointer to|incompatible integer to|type specifier missing' out.txt
}

# Sanity check for GCC warnings
check_sanity_gcc() {
    timeout -s 9 $TIMEOUTCC gcc-7.1.0 -Wall -Wextra -Wsystem-headers -O0 $CFILE > outa.txt 2>&1 \
        && ! grep -q -E 'division by zero|without a cast|control reaches end|return type defaults|cast from pointer to integer|useless type name in empty declaration|no semicolon at end|type defaults to|too few arguments for format|incompatible pointer|ordered comparison of pointer with integer|declaration does not declare anything|expects type|pointer from integer|incompatible implicit|excess elements in struct initializer|comparison between pointer and integer' outa.txt
}

# Reference generation (out0.txt)
check_reference() {
    timeout -s 9 $TIMEOUT $CLANGFC $CFLAG $CFILE >&/dev/null \
        && { timeout -s 9 $TIMEOUT ./t > out0.txt 2>&1 ; } >&/dev/null
}

# Good compiler check
check_good_cc() {
    local cc="$1"
    local ref_file="$2"
    
    if [[ $cc == ccomp* ]]; then
        timeout -s 9 $TIMEOUT $cc -interp $CFLAG $CFILE >&/dev/null || return 1
    fi

    timeout -s 9 $TIMEOUT $cc $CFLAG $CFILE >&/dev/null \
        && { timeout -s 9 $TIMEOUT ./t > out1.txt 2>&1 ; } >&/dev/null \
        && diff -q "$ref_file" out1.txt > /dev/null
}

# Bad compiler check (ICE)
check_bad_cc() {
    local cc="$1"
    timeout -s 9 $TIMEOUT $cc $CFLAG $CFILE > out.txt 2>&1
    grep 'internal compiler error' out.txt > /dev/null
}

# ------------------------------------------------------------------------------
# Orchestration
# ------------------------------------------------------------------------------

# Launch a function in a temp directory
launch() {
    local label=$1
    shift
    local tmp_dir=$(mktemp -d "/tmp/parallel_r_$label.XXXXXX")
    CLEANUP_DIRS+=("$tmp_dir")
    
    (
        cp "$CFILE_ABS" "$tmp_dir/"
        cd "$tmp_dir" || exit 1
        "$@"
    ) &
    LAST_PID=$!
}

wait_all() {
    local pids=("$@")
    local count=${#pids[@]}
    while [ $count -gt 0 ]; do
        wait -n
        local status=$?
        if [ $status -ne 0 ]; then
            kill "${pids[@]}" 2>/dev/null
            exit 1
        fi
        ((count--))
    done
}

# Phase 1: Sanity + Baseline
# Note: we need the baseline 'out0.txt' for the next phase.
baseline_dir=$(mktemp -d "/tmp/parallel_r_baseline.XXXXXX")
CLEANUP_DIRS+=("$baseline_dir")

(
    cp "$CFILE_ABS" "$baseline_dir/"
    cd "$baseline_dir" || exit 1
    check_reference
) & pid_ref=$!

pids=($pid_ref)
launch sanity_clang check_sanity_clang
pids+=($LAST_PID)
launch sanity_gcc check_sanity_gcc
pids+=($LAST_PID)

wait_all "${pids[@]}"

# If we are here, baseline is ready in $baseline_dir/out0.txt
REF_FILE="$baseline_dir/out0.txt"

# Phase 2: Good/Bad Compiler Checks
pids=()
for cc in "${GOODCC[@]}"; do
    launch "good_cc_${cc// /-}" check_good_cc "$cc" "$REF_FILE"
    pids+=($LAST_PID)
done
for cc in "${BADCC[@]}"; do
    launch "bad_cc_${cc// /-}" check_bad_cc "$cc"
    pids+=($LAST_PID)
done

wait_all "${pids[@]}"

exit 0
