/*
 * Copyright (C) 2018-2025 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.fuzzer.compiler.javac

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.javac.JavacCrashDetector

@RunWith(JUnit4::class)
class JavacCrashDetectorTest {

  val javaDetector = JavacCrashDetector()

  private fun computeSignature(path: String): List<String> {
    val signatureLines = CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/javac/$path",
      javaDetector,
    )
    return signatureLines
  }

  @Test
  fun test_java_crash1() {
    val signatureLine = computeSignature("bug1.txt")
    assertThat(signatureLine).containsExactly(
      "at jdk.compiler/com.sun.tools.javac.util.Assert.error(Assert.java:162)",
      "at jdk.compiler/com.sun.tools.javac.util.Assert.checkNonNull(Assert.java:137)",
      "at jdk.compiler/com.sun.tools.javac.jvm.CRTable.writeCRT(CRTable.java:107)",
      "at jdk.compiler/com.sun.tools.javac.jvm.ClassWriter.writeCode(ClassWriter.java:1051)",
      "at jdk.compiler/com.sun.tools.javac.jvm.ClassWriter.writeMethod(ClassWriter.java:987)",
      "at jdk.compiler/com.sun.tools.javac.jvm.ClassWriter.writeMethods(ClassWriter.java:1478)",
      "at jdk.compiler/com.sun.tools.javac.jvm.ClassWriter.writeClassFile(ClassWriter.java:1583)",
      "at jdk.compiler/com.sun.tools.javac.jvm.ClassWriter.writeClass(ClassWriter.java:1504)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.genCode(JavaCompiler.java:757)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.generate(JavaCompiler.java:1644)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.generate(JavaCompiler.java:1612)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.compile(JavaCompiler.java:973)",
      "at jdk.compiler/com.sun.tools.javac.main.Main.compile(Main.java:317)",
      "at jdk.compiler/com.sun.tools.javac.main.Main.compile(Main.java:176)",
      "at jdk.compiler/com.sun.tools.javac.Main.compile(Main.java:64)",
      "at jdk.compiler/com.sun.tools.javac.Main.main(Main.java:50)",
    )
  }

  @Test
  fun test_java_crash2() {
    val signatureLine = computeSignature("bug2.txt")
    assertThat(signatureLine).containsExactly(
      "at jdk.compiler/com.sun.tools.javac.util.Assert.error(Assert.java:155)",
      "at jdk.compiler/com.sun.tools.javac.util.Assert.check(Assert.java:46)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitBreak(Gen.java:1707)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCBreak.accept(JCTree.java:1561)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:616)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStats(Gen.java:667)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitBlock(Gen.java:1067)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCBlock.accept(JCTree.java:1026)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:616)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen$3.genLast(Gen.java:1450)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen$3.gen(Gen.java:1446)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genFinalizer(Gen.java:341)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.unwind(Gen.java:353)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.unwindBreak(Gen.java:1747)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitBreak(Gen.java:1735)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCBreak.accept(JCTree.java:1561)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:616)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStats(Gen.java:667)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitBlock(Gen.java:1067)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCBlock.accept(JCTree.java:1026)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:616)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genTry(Gen.java:1479)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitTry(Gen.java:1467)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCTry.accept(JCTree.java:1381)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:616)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStats(Gen.java:667)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitBlock(Gen.java:1067)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCBlock.accept(JCTree.java:1026)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:616)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStats(Gen.java:667)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStats(Gen.java:651)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.handleSwitch(Gen.java:1337)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.doHandleSwitchExpression(Gen.java:1205)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitSwitchExpression(Gen.java:1172)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$" +
        "JCSwitchExpression.accept(JCTree.java:1315)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genExpr(Gen.java:853)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genArgs(Gen.java:872)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitApply(Gen.java:1808)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$" +
        "JCMethodInvocation.accept(JCTree.java:1709)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genExpr(Gen.java:853)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitExec(Gen.java:1702)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$" +
        "JCExpressionStatement.accept(JCTree.java:1519)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:616)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStats(Gen.java:667)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitBlock(Gen.java:1067)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCBlock.accept(JCTree.java:1026)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genStat(Gen.java:630)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genMethod(Gen.java:937)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.visitMethodDef(Gen.java:900)",
      "at jdk.compiler/com.sun.tools.javac.tree.JCTree\$JCMethodDecl.accept(JCTree.java:872)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genDef(Gen.java:595)",
      "at jdk.compiler/com.sun.tools.javac.jvm.Gen.genClass(Gen.java:2345)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.genCode(JavaCompiler.java:756)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.generate(JavaCompiler.java:1635)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.generate(JavaCompiler.java:1603)",
      "at jdk.compiler/com.sun.tools.javac.main.JavaCompiler.compile(JavaCompiler.java:973)",
      "at jdk.compiler/com.sun.tools.javac.main.Main.compile(Main.java:311)",
      "at jdk.compiler/com.sun.tools.javac.main.Main.compile(Main.java:170)",
      "at jdk.compiler/com.sun.tools.javac.Main.compile(Main.java:57)",
      "at jdk.compiler/com.sun.tools.javac.Main.main(Main.java:43)",
    )
  }
}
