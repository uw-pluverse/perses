#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o xtrace

if [[ "$#" != 1 ]]; then
  echo "Usage: $0 <log file>"
  exit 1
fi

readonly FILE="$1"

cat "${FILE}"
if ! grep --quiet "Fixpoint iteration finished. delete 0 tokens, ratio=21/56=37.50%" "${FILE}"; then
  exit 1
fi

if ! grep --quiet "\[concurrent_token_slicer@1\] Fixpoint iteration finished, delete 0 tokens, ratio=21/56=37.50" "${FILE}"; then
  exit 1
fi

exit 0
