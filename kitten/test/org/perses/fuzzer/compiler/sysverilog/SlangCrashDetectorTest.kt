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
package org.perses.fuzzer.compiler.sysverilog

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.sysverilog.SlangCrashDetector

@RunWith(JUnit4::class)
class SlangCrashDetectorTest {

  val detector = SlangCrashDetector()

  private fun computeSignature(path: String): List<String> {
    return CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/sysverilog/$path",
      detector,
    )
  }

  @Test
  fun test_ice_1() {
    val signature = computeSignature("slang_ice_1.txt")
    assertThat(signature).containsExactly(
      "internal compiler error: Assertion '!arg.isError()' failed",
      "Type.cpp",
      "function: slang::Diagnostic &slang::operator<<(slang::Diagnostic &, const slang::Type &)",
    )
  }
}
