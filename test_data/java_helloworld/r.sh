#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly SRC="t.java"

# This fixture is used by reducer functional tests (HDD, the perses node reducer,
# ...) to exercise the reduction algorithms, not Java compiler fidelity. The
# interestingness property is therefore a cheap, deterministic textual check --
# the program still contains the marker string -- instead of compiling and
# running with javac/java, which cost JVM startup per query and dominated these
# tests' runtime.
if grep -q "hello world" "${SRC}"; then
  exit 0
fi

exit 1
