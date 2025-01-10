#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" dotty.tools.dotc.ast.Trees\$UnAssignedTypeException: type of Ident(R) is not assigned" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.Trees\$Tree.tpe(Trees.scala:79)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.tpd\$.tpes(tpd.scala:1166)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.TypeOps\$.boundsViolations(TypeOps.scala:551)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Checking\$.checkBounds(Checking.scala:73)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Checking\$.checkAppliedType(Checking.scala:112)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.PostTyper\$PostTyperTransformer.transform(PostTyper.scala:385)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.Trees\$Instance\$TreeMap.transform(Trees.scala:1389)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.MacroTransform\$Transformer.transform(MacroTransform.scala:60)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.PostTyper\$PostTyperTransformer.transform(PostTyper.scala:433)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.Trees\$Instance\$TreeMap.transform(Trees.scala:1410)" "${OUTPUT}" ; then
  exit 1
fi
exit 0