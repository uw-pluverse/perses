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
package org.perses.fuzzer.compiler.javascript

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.javascript.JerryScriptCrashDetector

@RunWith(JUnit4::class)
class JerryScriptCrashDetectorTest {

  val jerryDetector = JerryScriptCrashDetector()

  private fun computeSignature(path: String): List<String> {
    val signatureLines = CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/javascript/$path",
      jerryDetector,
    )
    return signatureLines
  }

  @Test
  fun test_jerry_crash_ubsan() {
    val signatureLine = computeSignature("jerry_crash_ubsan.txt")
    assertThat(signatureLine).containsExactly(
      "jerryscript/jerry-core/vm/vm.c",
      "runtime error: left shift of",
      "by",
      "places cannot be represented in type 'int'",
    )
  }

  @Test
  fun test_jerry_crash_asan() {
    val signatureLine = computeSignature("jerry_crash_asan.txt")
    assertThat(signatureLine).containsExactly(
      "AddressSanitizer:DEADLYSIGNAL",
      "ERROR: AddressSanitizer: stack-overflow on address",
      "SUMMARY: AddressSanitizer: stack-overflow",
      "jerryscript/jerry-core/ecma/base/ecma-helpers.c",
      "in ecma_find_named_property",
    )
  }
}
