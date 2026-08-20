#!/usr/bin/env bash

# A dummy C-Reduce that simulates a crash: it leaves an interesting (reduced)
# file behind but then exits with a non-zero status. CReduceReducer should still
# salvage this partial result because it is interesting.

set -o xtrace
set -o nounset
set -o pipefail

[[ "$#" == 2 ]] || exit 1

readonly SCRIPT="$1"
readonly FILE="$2"

[[ -x "${SCRIPT}" ]] || exit 1
[[ -f "${FILE}" ]] || exit 1

cat > "${FILE}" << EOF
int printf(const char*, ...);
int main() {
  printf("world\n");
}
EOF

# Simulate C-Reduce crashing after it has already reduced the file.
exit 1
