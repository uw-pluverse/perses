#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly SRC="t.sc"

# This fixture is used by reducer functional/unit tests (token slicer, delta
# debugging, ...) to exercise the reduction algorithms, not Scala compiler
# fidelity. The interestingness property is therefore a cheap, deterministic
# textual check -- the program still contains the marker string -- instead of
# compiling and running with scalac/scala, which cost ~1.5s of JVM startup per
# query and dominated these tests' runtime.
if grep -q "Hello, world" "${SRC}"; then
  exit 0
fi

exit 1
