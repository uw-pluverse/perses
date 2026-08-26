#!/usr/bin/env bash
set -o nounset
grep -q "if" t.c || exit 1
grep -q "b" t.c || exit 1
exit 0
