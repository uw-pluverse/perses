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
package org.perses.fuzzer.compiler.solidity

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.solidity.SolidityCrashDetector

@RunWith(JUnit4::class)
class SolidityCrashDetectorTest {

  val detector = SolidityCrashDetector()

  private fun computeSignature(path: String): List<String> {
    return CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/solidity/$path",
      detector,
    )
  }

  @Test
  fun test_asan() {
    val signature = computeSignature("mock_crash_asan.txt")
    assertThat(signature).containsExactly(
      "AddressSanitizer:DEADLYSIGNAL",
      "ERROR: AddressSanitizer: stack-overflow on address",
      "SUMMARY: AddressSanitizer: stack-overflow",
      "jerryscript/jerry-core/ecma/base/ecma-helpers.c",
      "in ecma_find_named_property",
    )
  }

  @Test
  fun test_ubsan() {
    val signature = computeSignature("mock_crash_ubsan.txt")
    assertThat(signature).containsExactly(
      "jerryscript/jerry-core/vm/vm.c",
      "runtime error: left shift of",
      "by",
      "places cannot be represented in type 'int'",
    )
  }

  @Test
  fun test_crash_output_1() {
    val signature = computeSignature("solc_crash_1.txt")
    assertThat(signature).containsExactly(
      "Internal compiler error during compilation:",
      "/solidity/libsolidity/ast/Types.h",
      "Throw in function virtual unsigned int " +
        "solidity::frontend::Type::calldataEncodedSize(bool) const",
      "Dynamic exception type: boost::wrapexcept<solidity::langutil::InternalCompilerError>",
      "std::exception::what:",
      "[solidity::util::tag_comment*] =",
    )
  }
}
