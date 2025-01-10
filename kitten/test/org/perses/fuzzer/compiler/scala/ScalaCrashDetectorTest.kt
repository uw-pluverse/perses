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
package org.perses.fuzzer.compiler.scala

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.scala.ScalaCrashDetector

@RunWith(JUnit4::class)
class ScalaCrashDetectorTest {

  val detector = ScalaCrashDetector()

  @Test
  fun test_noncrash_output_1() {
    val signature = computeSignature("noncrash_output_1.txt")
    assertThat(signature).isEmpty()
  }

  @Test
  fun test_noncrash_output_2() {
    val signature = computeSignature("noncrash_output_2.txt")
    assertThat(signature).isEmpty()
  }

  @Test
  fun test_crash_output_1() {
    val signatureLines = computeSignature("crash_output_1.txt")
    assertThat(signatureLines).isNotEmpty()
    assertThat(signatureLines)
      .containsExactly(
        "Exception in thread \"main\" java.lang.NoClassDefFoundError: " +
          "Could not initialize class dotty.tools.dotc.reporting.ExpectedTokenButFound",
        "at dotty.tools.dotc.parsing.Parsers${'$'}Parser.accept",
        "at dotty.tools.dotc.parsing.Parsers${'$'}Parser.enclosed",
        "at dotty.tools.dotc.parsing.Parsers${'$'}Parser.inBraces",
      )
      .inOrder()
  }

  @Test
  fun test_crash_output_2() {
    val signatureLines = computeSignature("crash_output_2.txt")
    assertThat(signatureLines).isNotEmpty()
    assertThat(signatureLines).containsExactly(
      "java.lang.StackOverflowError while compiling mutant.scala",
      "Exception in thread \"main\" java.lang.StackOverflowError",
    ).inOrder()
  }

  @Test
  fun test_crash_output_3() {
    val signature = computeSignature("crash_output_3.txt")

    assertThat(signature).containsExactly(
      "Exception in thread \"main\" java.lang.AssertionError: assertion failed: " +
        "no companion Test${'$'} in dotty.tools.dotc.core.Scopes${'$'}MutableScope",
      "at scala.runtime.Scala3RunTime${'$'}.assertFailed",
      "at dotty.tools.dotc.core.Decorators${'$'}.assertingErrorsReported",
      "at dotty.tools.dotc.core.NamerOps${'$'}.findModuleBuddy",
    ).inOrder()
  }

  @Test
  fun testSystemHashcodeSplit() {
    val result = ScalaCrashDetector
      .splitOnSystemHashCode(
        "dotty.tools.dotc.core.Scopes${'$'}MutableScope@41522537",
      )
      .toList()
    assertThat(result).hasSize(1)
    assertThat(result).containsExactly(
      "dotty.tools.dotc.core.Scopes${'$'}MutableScope",
    ).inOrder()
  }

  fun computeSignature(fileName: String): List<String> {
    return CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/scala/$fileName",
      detector,
    )
  }
}
