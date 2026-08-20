#!/usr/bin/env bash

# No in-script `timeout` wall cap here, so set a conservative CPU ceiling:
# ample for a legitimate javac/gradle run, but bounded so a runaway process is
# reaped by the kernel via RLIMIT_CPU instead of spinning indefinitely. Unlike
# `timeout`, RLIMIT_CPU is inherited by descendants and survives reparenting.
# The value below is in CPU seconds (ulimit -t sets RLIMIT_CPU).
ulimit -t 300

#check if defined cf is the right version (1.9.13)
#elsewise make a copy appear (divine wget)
[ -e output.txt ] && rm output.txt
#export CHECKER_1_9_13=/home/gradle/rq4/checker-framework-1.9.13
export   CORRETTO_8=/home/gradle/rq4/amazon-corretto-8/bin/java
#because perses incorrectly treats >>> and >> as individual greater than signs
#they need to be placed on the same line again for the checker to accept it

if [ -z "${CHECKER_1_9_13}" ]; then
  echo "Error: CHECKER_1_9_13 is not set."
  exit 1
fi

if [ -z "${JDK8_DIR}" ]; then
  echo "Error: JDK8_DIR is not set."
  exit 1
fi

#sed -zi 's/>\n/>/g' Collections.java

"${JDK8_DIR}/bin/java" -jar "${CHECKER_1_9_13}/checker.jar" -processor formatter -AprintErrorStack Collections.java > output.txt 2>&1

grep "error: SourceChecker.typeProcess: unexpected Throwable (NullPointerException) while processing Collections.java" output.txt && echo "Found pattern." && exit 0
echo "Did not find pattern." && exit 1
