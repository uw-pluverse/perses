#!/usr/bin/env bash

set -o pipefail
set -o nounset

# A writable Go build cache is required because the default location
# (~/.cache/go-build) is not writable in the build sandbox. Anchor it to a
# stable directory (rather than a fresh `mktemp -d` that is deleted on every
# call) so that `go run` reuses compiled artifacts across the many
# interestingness-test invocations of a single reduction. This is ~25x faster
# per query after the first and does not change the test's verdict.
export GOCACHE="${TMPDIR:-/tmp}/perses_go_build_cache"
export GOPATH="${TMPDIR:-/tmp}/perses_go_path"
mkdir -p "${GOCACHE}" "${GOPATH}"

readonly OUTPUT="output.txt.tmp"
readonly SRC="small.go"

rm "${OUTPUT}" || true

if ! command -v "go"; then
  echo "No go on the path"
  exit 1
fi
go run "${SRC}" &> "${OUTPUT}"

if [[ "${?}" != 0 ]]; then
  exit 1
fi

if ! grep "gola" "${OUTPUT}"; then
  exit 1
fi

exit 0
