#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.AssertionError: assertion failed: Non-sensical cast between unrelated types ErasedValueType(I0, Double) and ErasedValueType(I0, Double)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed(Scala3RunTime.scala:8)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Boxing\$.cast(Erasure.scala:335)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Boxing\$.unbox(Erasure.scala:303)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Boxing\$.adaptToType(Erasure.scala:379)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Typer.adapt(Erasure.scala:1065)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typed(Typer.scala:2813)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typed(Typer.scala:2817)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typedExpr(Typer.scala:2933)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Typer.\$anonfun\$4(Erasure.scala:850)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Decorators\$ListDecorator\$.zipWithConserve\$extension(Decorators.scala:153)" "${OUTPUT}" ; then
  exit 1
fi
exit 0