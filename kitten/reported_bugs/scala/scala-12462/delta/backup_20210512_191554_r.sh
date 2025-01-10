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

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed(Scala3RunTime.scala:8)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers\$BCInnerClassGen.assertClassNotArrayNotPrimitive(BCodeHelpers.scala:247)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers\$BCInnerClassGen.getClassBTypeAndRegisterInnerClass(BCodeHelpers.scala:265)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers\$BCInnerClassGen.getClassBTypeAndRegisterInnerClass\$(BCodeHelpers.scala:210)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeSkelBuilder\$PlainSkelBuilder.getClassBTypeAndRegisterInnerClass(BCodeSkelBuilder.scala:63)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers\$BCInnerClassGen.internalName(BCodeHelpers.scala:237)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers\$BCInnerClassGen.internalName\$(BCodeHelpers.scala:210)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeSkelBuilder\$PlainSkelBuilder.internalName(BCodeSkelBuilder.scala:63)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeBodyBuilder\$PlainBodyBuilder.genCallMethod(BCodeBodyBuilder.scala:1136)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeBodyBuilder\$PlainBodyBuilder.genApply(BCodeBodyBuilder.scala:793)" "${OUTPUT}" ; then
  exit 1
fi
exit 0