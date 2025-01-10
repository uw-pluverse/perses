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

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$AppliedType.tryCompiletimeConstantFold(Types.scala:4081)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$AppliedType.tryNormalize(Types.scala:4057)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$AppliedType.translucentSuperType(Types.scala:4030)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure\$.arrayUpperBound\$1(TypeErasure.scala:303)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure\$.fitsInJVMArray\$1(TypeErasure.scala:317)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure\$.isGenericArrayElement(TypeErasure.scala:325)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure.eraseArray(TypeErasure.scala:673)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure.dotty\$tools\$dotc\$core\$TypeErasure\$\$apply(TypeErasure.scala:591)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeErasure.eraseArray(TypeErasure.scala:674)" "${OUTPUT}" ; then
  exit 1
fi
exit 0