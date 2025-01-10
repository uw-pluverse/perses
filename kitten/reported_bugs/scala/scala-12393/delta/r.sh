#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.AssertionError: assertion failed: duplicate attachment for key dotty.tools.dotc.util.Property\$Key@761e788f" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed(Scala3RunTime.scala:8)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.util.Attachment\$Container.pushAttachment(Attachment.scala:120)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.util.Attachment\$Container.pushAttachment\$(Attachment.scala:101)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.Trees\$Tree.pushAttachment(Trees.scala:56)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Namer.record\$1(Namer.scala:343)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Namer.expand(Namer.scala:346)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.typer.Namer.index\$\$anonfun\$1(Namer.scala:648)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.function.JProcedure1.apply(JProcedure1.java:15)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.function.JProcedure1.apply(JProcedure1.java:10)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.collection.immutable.List.foreach(List.scala:333)" "${OUTPUT}" ; then
  exit 1
fi
exit 0