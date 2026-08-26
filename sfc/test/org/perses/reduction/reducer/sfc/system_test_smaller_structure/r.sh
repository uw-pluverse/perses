#!/usr/bin/env bash

set -o nounset
set -o pipefail

# The reduction has to keep a conditional whose condition mentions both a and b.
grep -q "if" t.c || exit 1
grep -q "a" t.c || exit 1
grep -q "b" t.c || exit 1
exit 0
