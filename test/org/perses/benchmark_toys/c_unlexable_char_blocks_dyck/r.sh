#!/usr/bin/env bash
#
# Interesting iff the MARKER survives. Deliberately needs no compiler: the point of this
# toy is the parse, not the semantics, and a grep oracle keeps it deterministic anywhere.

set -o nounset
set -o pipefail

grep -q "MARKER" t.c
