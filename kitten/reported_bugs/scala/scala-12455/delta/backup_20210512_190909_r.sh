#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.util.NoSuchElementException: head of empty list" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.collection.immutable.Nil\$.head(List.scala:629)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.collection.immutable.Nil\$.head(List.scala:628)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$SymDenotation.recurWithParamss\$1(SymDenotations.scala:312)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$SymDenotation.paramSymss(SymDenotations.scala:329)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.paramSymWithMethodTree\$3(Typer.scala:3326)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.issueErrors\$1\$\$anonfun\$1\$\$anonfun\$1(Typer.scala:3338)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.reporting.NoExplanation.msg(Message.scala:133)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.reporting.Message.message(Message.scala:88)" "${OUTPUT}" ; then
  exit 1
fi
exit 0