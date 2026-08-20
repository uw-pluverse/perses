#!/usr/bin/env bash
set -o nounset
make clean >/dev/null 2>&1
rm -f prog
make >/dev/null 2>&1 || exit 1
./prog | grep -q INTERESTING || exit 1
exit 0
