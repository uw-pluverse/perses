#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.AssertionError: assertion failed: class Int" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers\$BCInnerClassGen.assertClassNotArrayNotPrimitive" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers\$BCInnerClassGen.getClassBTypeAndRegisterInnerClass" "${OUTPUT}" ; then
  exit 1
fi
exit 0