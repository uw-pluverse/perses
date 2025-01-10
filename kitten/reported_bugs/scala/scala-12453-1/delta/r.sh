#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.StackOverflowError" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$TypeProxy.superType" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$TypeProxy.translucentSuperType" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure\$.arrayUpperBound\$1" "${OUTPUT}" ; then
  exit 1
fi
exit 0