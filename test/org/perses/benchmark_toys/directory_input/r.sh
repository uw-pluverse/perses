#!/usr/bin/env bash

set -o nounset

# The two source files live under input/ (passed to Perses as a single --input directory) and the
# dependency under deps/ (passed as a single --deps directory). Requiring the dependency token here
# makes the --deps directory load-bearing: if it were not staged into the reduction folder, even the
# initial interestingness check would fail.
grep -q 'KEEP_A' input/a.c || exit 1
grep -q 'KEEP_B' input/b.c || exit 1
grep -q 'DEP_PRESENT' deps/dep.h || exit 1

exit 0
