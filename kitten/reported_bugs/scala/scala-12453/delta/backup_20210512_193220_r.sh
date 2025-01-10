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

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$AppliedType.tryCompiletimeConstantFold" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$AppliedType.tryNormalize" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$AppliedType.translucentSuperType" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure\$.arrayUpperBound\$1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure\$.fitsInJVMArray\$1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure\$.isGenericArrayElement" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure.eraseArray" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure.dotty\$tools\$dotc\$core\$TypeErasure\$\$apply" "${OUTPUT}" ; then
  exit 1
fi
exit 0