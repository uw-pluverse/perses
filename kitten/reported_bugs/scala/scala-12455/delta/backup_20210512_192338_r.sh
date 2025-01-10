#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.collection.immutable.Nil\$.head" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$SymDenotation.recurWithParamss\$1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$SymDenotation.paramSymss" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.paramSymWithMethodTree\$3" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.issueErrors\$1\$\$anonfun\$1\$\$anonfun\$1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.reporting.NoExplanation.msg" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.reporting.Message.message" "${OUTPUT}" ; then
  exit 1
fi
exit 0