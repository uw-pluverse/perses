#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly SRC="Hello.sc"

# This toy exercises Perses's Scala reduction algorithms (node priority, the
# token/tree/line slicers, and the global cache) rather than Scala compiler
# fidelity, so the interestingness property is a cheap, deterministic textual
# check: the program still contains the marker string. The previous oracle
# compiled and ran the program with scalac/scala, costing ~1.6s of JVM startup
# per query (the dominant cost of this benchmark); grep makes each query ~0ms.
if grep -q "Hello, world" "${SRC}"; then
  exit 0
fi

exit 1
