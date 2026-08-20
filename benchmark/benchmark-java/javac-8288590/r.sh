#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate javac/gradle run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300

[ -e output.txt ] && rm output.txt

if [ -z "${JDK17_DIR}" ]; then
  echo "Error: JDK17_DIR is not set."
  exit 1
fi

# JDK-8288590 is a javac type-inference bug that reproduces only on JDK 17.0.9 (fixed later).
# -XX:hashCode=2 forces a deterministic identity hashCode so the order-dependent failure is reliable.
export _JAVA_OPTIONS="-XX:+UnlockExperimentalVMOptions -XX:hashCode=2"

"${JDK17_DIR}/bin/javac" $(find . -name "*.java") > output.txt 2>&1

grep -qE 'FieldSupport\.java:[0-9]+: error: incompatible types: inference variable .* has incompatible bounds' output.txt \
  && grep -qE 'equality constraints: Object,A' output.txt \
  && echo "Found pattern." && exit 0
echo "Did not find pattern." && exit 1
