#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o xtrace

readonly FILE="t.c"
readonly OUTPUT="temp.txt"
readonly EXE="./temp.out"

gcc "${FILE}" -Wall -Wextra -o "${EXE}" > "${OUTPUT}" 2>&1 || exit 1

if grep "uninitialized" "${OUTPUT}" ; then
  exit 1
fi

"${EXE}" > "${OUTPUT}" 2>&1
if [[ "$?" != 99 ]] ; then
  exit 1
fi

readonly OCCURRENCE=3
if [[ "$(grep -c "var" "${FILE}")" != "${OCCURRENCE}" ]] ; then
  exit 1
fi

if [[ "$(grep -c ";" "${FILE}")" != "${OCCURRENCE}" ]] ; then
  exit 1
fi

if grep "^ *fun.*var" "${FILE}" || grep '^ *var *;$' "${FILE}" ; then
  exit 0
else
  exit 1
fi
