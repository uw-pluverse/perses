#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.AssertionError: assertion failed: class FileZipArchive has non-class parent: val <none>" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed(Scala3RunTime.scala:8)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$ClassDenotation.traverse\$1(SymDenotations.scala:1822)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$ClassDenotation.computeBaseData(SymDenotations.scala:1827)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$BaseDataImpl.apply(SymDenotations.scala:2798)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$ClassDenotation.baseData(SymDenotations.scala:1798)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.SymDenotations\$ClassDenotation.baseClasses(SymDenotations.scala:1805)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.NamerOps\$.memberExists\$1(NamerOps.scala:139)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.core.NamerOps\$.addConstructorProxies\$\$anonfun\$1(NamerOps.scala:143)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.function.JProcedure1.apply(JProcedure1.java:15)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.function.JProcedure1.apply(JProcedure1.java:10)" "${OUTPUT}" ; then
  exit 1
fi
exit 0