#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate javac/gradle run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300

[ -e output.txt ] && rm output.txt

if [ -z "${GRADLE_DIR}" ]; then
  echo "Error: GRADLE_DIR is not set."
  exit 1
fi

if [ -z "${JDK21_DIR}" ]; then
  echo "Error: JDK21_DIR is not set."
  exit 1
fi

# NullAway runs as an Error Prone plugin inside javac; Error Prone needs a modern JDK to run.
export JAVA_HOME="${JDK21_DIR}"

"${GRADLE_DIR}/bin/gradle" --no-daemon compileJava > output.txt 2>&1

grep -F '[NullAway] dereferenced expression cs is @Nullable' output.txt && echo "Found pattern." && exit 0
echo "Did not find pattern." && exit 1
