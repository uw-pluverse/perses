#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate javac/gradle run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300

[ -e output.txt ] && rm output.txt

if [ -z "${JDK8_DIR}" ]; then
  echo "Error: JDK8_DIR is not set."
  exit 1
fi

# JDK-8319461 is a javac type-inference bug reproduced by compiling these sources with JDK 8's javac.
"${JDK8_DIR}/bin/javac" $(find . -name "*.java") > output.txt 2>&1

grep -qE 'PropertyFactoryManager\.java:[0-9]+: error: incompatible types' output.txt \
  && grep -qE 'equality constraints: P' output.txt \
  && echo "Found pattern." && exit 0
echo "Did not find pattern." && exit 1
