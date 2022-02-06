#!/usr/bin/env bash

set -o pipefail
set -o nounset

export GOCACHE=$(mktemp -d) # Build cache for the go compiler. Otherwise, go does not run.
export GOPATH=${GOCACHE}/go
trap "{ rm ${GOCACHE} -rf; }" EXIT

readonly OUTPUT="output.txt.tmp"
readonly SRC="small.go"

rm "${OUTPUT}" || true

if ! command -v "go" ; then
  echo "No go on the path"
  exit 1
fi
go run "${SRC}" &> "${OUTPUT}"

if [[ "${?}" != 0 ]] ; then
  exit 1
fi

if ! grep "golang" "${OUTPUT}" ; then
  exit 1
fi

exit 0
