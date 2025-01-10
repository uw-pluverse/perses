#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.AssertionError: assertion failed: isType called on not-a-Type val <none>" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.Symbols\$Symbol.asType" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.TypeAssigner.assignType\$\$anonfun\$6" "${OUTPUT}" ; then
  exit 1
fi
exit 0