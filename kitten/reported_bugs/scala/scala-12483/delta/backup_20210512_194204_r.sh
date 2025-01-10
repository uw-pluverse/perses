#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.AssertionError: assertion failed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Boxing\$.unbox" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Boxing\$.adaptToType" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Typer.adapt" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typedExpr" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.Erasure\$Typer.typedTypeApply" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typedUnnamed\$1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typedUnadapted" "${OUTPUT}" ; then
  exit 1
fi
exit 0