#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly FILE="HelloJava20.java.txt"

grep "world" "${FILE}" > /dev/null
