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
package org.perses.fuzzer.compiler.go

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.c.ClangCrashDetector
import org.perses.fuzzer.compilers.c.GccCrashDetector

@RunWith(JUnit4::class)
class GoCrashDetectorTest {

  val gccDetector = GccCrashDetector()

  private fun computeSignature(path: String): List<String> {
    val signatureLines = CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/go/$path",
      gccDetector,
    )
    return signatureLines
  }

  private fun computeClangSignature(path: String): List<String> {
    val signatureLines = CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/c/$path",
      ClangCrashDetector(),
    )
    return signatureLines
  }

  @Test
  fun test_ice() {
    val signatureLines = computeSignature("go-47723-bug.txt")
    assertThat(signatureLines).containsExactly(
      "internal compiler error: .dict already has a location",
    )
  }
}
