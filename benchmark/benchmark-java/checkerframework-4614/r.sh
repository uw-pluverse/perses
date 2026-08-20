#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate javac/gradle run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300

set -o nounset

if [ -z "${CHECKER_3_12}" ]; then
  echo "Error: CHECKER_3_12 is not set."
  exit 1
fi

if [ -z "${JDK8_DIR}" ]; then
  echo "Error: JDK8_DIR is not set."
  exit 1
fi

# Checker Framework 3.x rejects the default JDK 17; use the bundled JDK 8 for the spawned javac.
export PATH="${JDK8_DIR}/bin:${PATH}"

"${JDK8_DIR}/bin/java" -jar "${CHECKER_3_12}/checker.jar" -processor nullness -AprintErrorStack Version.java > output.txt 2>&1

grep -F "required: Entry<@KeyFor(\"[error for expression: ()java.util.Map<java.lang.String,java.lang.String>.getAllVersionInformation(); error: Invalid '()java.util.Map<java.lang.String,java.lang.String>.getAllVersionInformation()' because the expression did not parse. Error message: Encountered unexpected token: \"java\" <IDENTIFIER>]\") String, String>" output.txt && echo "Found pattern." && exit 0
echo "Did not find pattern." && exit 1
