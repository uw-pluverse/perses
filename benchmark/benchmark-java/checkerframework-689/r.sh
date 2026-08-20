#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate run run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300

[ -e output.txt ] && rm output.txt

if [ -z "${CHECKER_1_9_13}" ]; then
  echo "Error: CHECKER_1_9_13 is not set."
  exit 1
fi

if [ -z "${JDK8_DIR}" ]; then
  echo "Error: JDK8_DIR is not set."
  exit 1
fi

"${JDK8_DIR}/bin/java" -jar "${CHECKER_1_9_13}/checker.jar" -processor guieffect -AprintErrorStack AbstractList.java > output.txt 2>&1
grep "error: SourceChecker.typeProcess: unexpected Throwable (AssertionError) while processing .*AbstractList.java" output.txt && echo "Found pattern." && exit 0
echo "Did not find pattern." && exit 1
