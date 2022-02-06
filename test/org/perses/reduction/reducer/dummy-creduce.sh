#!/usr/bin/env bash

set -o xtrace
set -o nounset
set -o pipefail
set -o errexit

[[ "$#" == 2 ]] || exit 1

readonly SCRIPT="$1"
readonly FILE="$2"

[[ -x "${SCRIPT}" ]] || exit 1
[[ -f "${FILE}" ]] || exit 1

"./${SCRIPT}" || exit 1

cat > "${FILE}" << EOF
int printf(const char*, ...);
int main() {
  printf("world\n");
}
EOF

exit 0