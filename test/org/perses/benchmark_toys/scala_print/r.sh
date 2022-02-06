#!/usr/bin/env bash

set -o pipefail
set -o nounset
ulimit -t 60

readonly OUTPUT="output.txt.tmp"
readonly SRC="Hello.sc"
readonly EXE="Hello"

rm "${OUTPUT}" || true

if ! command -v "scalac" ; then
  echo "No scalac on the path"
  exit 2
fi
if ! command -v "scala" ; then
  echo "No scala on the path"
  exit 3
fi

# scalac interacts with stty, and can suspend if it runs in the background.
if ! scalac "${SRC}" < /dev/null ; then
  exit 4
fi

scala -nc "${EXE}" < /dev/null &> "${OUTPUT}"

# shellcheck disable=SC2181
if [[ "${?}" != 0 ]] ; then
  exit 5
fi

if ! grep "Hello, world" "${OUTPUT}" ; then
  exit 6
fi

exit 0
