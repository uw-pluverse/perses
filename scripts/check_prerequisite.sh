#!/usr/bin/env bash

set -o pipefail
set -o nounset

readonly TOOLS=(
    "java"
    "javap"
    "creduce"
    "gcc"
    "clang"
    "clang-format"
    "go"
    "python"
    "ruby"
    "rustc"
    "rustfmt"
    "scala")

missing=""
for tool in "${TOOLS[@]}" ; do
  if ! command -v "${tool}" &> /dev/null ; then
    missing="${missing} ${tool}"
  fi
done

if [[ "${missing}" != "" ]] ; then
  echo "The following tools are missing: ${missing}"
  exit 1
fi

readonly JAVA_VERSION=$(java -version 2>&1 | head -1 | cut -d'"' -f2 | sed '/^1\./s///' | cut -d'.' -f1)
if [[ "${JAVA_VERSION}" -lt "11" ]] ; then
  echo "The minimum java version should be 11. The current version is ${JAVA_VERSION}"
  exit 1
fi
exit 0
