#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly CLASS="Hello"
readonly FILE="${CLASS}.java"

javac "${FILE}" || exit 1
readonly OUTPUT="temp.txt"
java "${CLASS}" > "${OUTPUT}" 2>&1 || exit 1

grep "world" "${OUTPUT}" > /dev/null
