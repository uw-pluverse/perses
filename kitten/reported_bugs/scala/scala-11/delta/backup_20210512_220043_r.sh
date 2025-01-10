#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" scala.MatchError: MacroTree(Ident(???)) (of class dotty.tools.dotc.ast.untpd\$MacroTree)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.desugar\$.apply" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typedUnnamed\$1" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Typer.typedUnadapted" "${OUTPUT}" ; then
  exit 1
fi
exit 0