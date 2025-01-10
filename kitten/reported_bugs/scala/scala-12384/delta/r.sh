#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.ClassCastException: dotty.tools.dotc.core.Types\$Range cannot be cast to dotty.tools.dotc.core.Types\$TypeBounds" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.collection.immutable.List.mapConserve(List.scala:472)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$HKTypeLambda.newLikeThis\$\$anonfun\$1(Types.scala:3801)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$HKTypeLambda.<init>(Types.scala:3757)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$HKTypeLambda\$.apply(Types.scala:3863)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$HKTypeLambda.newLikeThis(Types.scala:3802)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$HKTypeLambda.newLikeThis(Types.scala:3797)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$HKTypeLambda.newLikeThis(Types.scala:3796)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$LambdaType.derivedLambdaType(Types.scala:3353)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$LambdaType.derivedLambdaType\$(Types.scala:3296)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Types\$HKLambda.derivedLambdaType(Types.scala:3369)" "${OUTPUT}" ; then
  exit 1
fi
exit 0