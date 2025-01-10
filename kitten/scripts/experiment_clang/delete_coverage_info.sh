#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit

if [[ "$#" != "1" ]] ; then
  echo "$0 <dir contains gcda files>"
  exit 1
fi

readonly TARGET_DIR="$(readlink -f $1)"

find $TARGET_DIR -type f -name "*.gcda" -delete
