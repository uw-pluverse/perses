#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate javac/gradle run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300
[ -e output.txt ] && rm output.txt
if [ -z "${CHECKER_3_42_0}" ]; then echo "Error: CHECKER_3_42_0 is not set."; exit 1; fi
if [ -z "${JDK8_DIR}" ]; then echo "Error: JDK8_DIR is not set."; exit 1; fi
# Checker Framework 3.x rejects the default JDK 17; use the bundled JDK 8 for the spawned javac.
export PATH="${JDK8_DIR}/bin:${PATH}"
"${JDK8_DIR}/bin/java" -jar "${CHECKER_3_42_0}/checker.jar" -J-da -processor org.checkerframework.checker.nullness.NullnessChecker -AprintErrorStack \
  $(find . -name "*.java") > output.txt 2>&1
grep -E 'error: StructuralEqualityComparer: unexpected combination:' output.txt && echo "Found pattern." && exit 0
echo "Did not find pattern." && exit 1
