#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers.abort(BCodeHelpers.scala:937)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeHelpers.abort\$(BCodeHelpers.scala:41)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.GenBCodePipeline.abort(GenBCode.scala:81)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeBodyBuilder\$PlainBodyBuilder.genLoad(BCodeBodyBuilder.scala:319)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeBodyBuilder\$PlainBodyBuilder.genLoad(BCodeBodyBuilder.scala:270)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeBodyBuilder\$PlainBodyBuilder.genLoadQualifier(BCodeBodyBuilder.scala:987)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeBodyBuilder\$PlainBodyBuilder.genTypeApply(BCodeBodyBuilder.scala:623)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.backend.jvm.BCodeBodyBuilder\$PlainBodyBuilder.genLoad(BCodeBodyBuilder.scala:437)" "${OUTPUT}" ; then
  exit 1
fi
exit 0