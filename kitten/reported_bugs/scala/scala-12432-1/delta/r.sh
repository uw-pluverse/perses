#!/usr/bin/env bash
set -o nounset
set -o pipefail

readonly OUTPUT="temp_compilation_output.tmp.txt"

if timeout -s 9 30 scalac-trunk  mutant.scala &> "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "Exception in thread \"main\" java.lang.AssertionError: assertion failed: no member [33mthis[0m.I2 . ==, members = Scope{" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.runtime.Scala3RunTime\$.assertFailed(Scala3RunTime.scala:8)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.Trees\$Instance.applyOverloaded(Trees.scala:1675)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.tpd\$TreeOps\$.equal\$extension(tpd.scala:962)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.SyntheticMembers.\$anonfun\$12(SyntheticMembers.scala:255)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at scala.collection.immutable.List.map(List.scala:246)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.SyntheticMembers.equalsBody\$1(SyntheticMembers.scala:255)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.SyntheticMembers.syntheticRHS\$1(SyntheticMembers.scala:146)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.SyntheticMembers.syntheticDef\$3\$\$anonfun\$2\$\$anonfun\$1(SyntheticMembers.scala:155)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.transform.SyntheticMembers.synthesizeDef\$\$anonfun\$1(SyntheticMembers.scala:85)" "${OUTPUT}" ; then
  exit 1
fi

if ! grep --quiet --fixed-strings "at dotty.tools.dotc.ast.tpd\$.DefDef(tpd.scala:285)" "${OUTPUT}" ; then
  exit 1
fi
exit 0