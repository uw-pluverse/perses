#!/usr/bin/env bash

set -o pipefail
set -o nounset

export GOCACHE=$(mktemp -d) # Build cache for the go compiler. Otherwise, go does not run.

readonly OUTPUT="output.txt.tmp"
readonly SRC="t.sc"
readonly EXE="Hello"

rm "${OUTPUT}" || true

if ! command -v "scalac" ; then
  echo "No scalac on the path"
  exit 1
fi
if ! command -v "scala" ; then
  echo "No scala on the path"
  exit 1
fi

if ! scalac "${SRC}" ; then
  exit 1
fi

scala "${EXE}" &> "${OUTPUT}"

if [[ "${?}" != 0 ]] ; then
  exit 1
fi

if ! grep "Hello, world" "${OUTPUT}" ; then
  exit 1
fi

exit 0
