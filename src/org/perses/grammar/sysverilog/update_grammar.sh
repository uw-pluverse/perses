#!/usr/bin/env bash

set -o pipefail
set -o nounset
set -o errexit
set -o xtrace

readonly BASE_URL="https://raw.githubusercontent.com/alainmarcel/Surelog/master/grammar/"
readonly FILES=("SV3_1aLexer.g4" "SV3_1aParser.g4")

for file in "${FILES[@]}" ; do
  rm -rf "${file}" &> /dev/null || true
  wget "${BASE_URL}/${file}" > /dev/null
done

readonly LICENSE="LICENSE"
rm -rf "${LICENSE}" &> /dev/null || true
wget "https://raw.githubusercontent.com/alainmarcel/Surelog/master/LICENSE" > /dev/null
