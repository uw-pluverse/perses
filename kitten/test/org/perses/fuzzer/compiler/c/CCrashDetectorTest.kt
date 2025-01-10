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
package org.perses.fuzzer.compiler.c

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.c.ClangCrashDetector
import org.perses.fuzzer.compilers.c.GccCrashDetector

@RunWith(JUnit4::class)
class CCrashDetectorTest {

  val gccDetector = GccCrashDetector()

  private fun computeSignature(path: String): List<String> {
    val signatureLines = CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/c/$path",
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
  fun test_clang_crash_output_1() {
    val signatureLines = computeClangSignature("clang_crash_output_1.txt")
    assertThat(signatureLines).containsExactly(
      "clang::TypeInfo clang::ASTContext::getTypeInfoImpl(const clang::Type*) " +
        "const: Assertion `llvm::isPowerOf2_32(Align) && \"Alignment must be power of 2\"' failed.",
      "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:",
      "PLEASE submit a bug report to",
    )
  }

  @Test
  fun test_clang_crash_output_2() {
    val signatureLines = computeClangSignature("clang_crash_output_2.txt")
    assertThat(signatureLines).containsExactly(
      "fatal error: error in backend: Cannot select: intrinsic %llvm.thread.pointer",
      "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:",
      "PLEASE submit a bug report to",
    )
  }

  @Test
  fun test_clang_crash_output_3() {
    val signatureLines = computeClangSignature("clang_crash_output_3.txt")
    assertThat(signatureLines).containsExactly(
      "UNREACHABLE executed at",
      "llvm-project/clang/lib/AST/ASTContext.cpp",
      "PLEASE ATTACH THE FOLLOWING FILES TO THE BUG REPORT:",
      "PLEASE submit a bug report to",
    )
  }

  @Test
  fun test_clang_crash_output_4() {
    val signatureLines = computeClangSignature("clang_crash_output_4.txt")
    assertThat(signatureLines).containsExactly(
      "const T* clang::Type::castAs() const [with T = clang::PointerType]: " +
        "Assertion `isa<T>(CanonicalType)' failed.",
      "PLEASE submit a bug report to",
    )
  }

  @Test
  fun test_ice() {
    val signatureLines = computeSignature("crash_output_1.txt")
    assertThat(signatureLines).containsExactly(
      "internal compiler error: in get_or_insert_ctor_field, at cp/constexpr.c",
      "get_or_insert_ctor_field",
      "cxx_eval_bare_aggregate",
      "cxx_eval_constant_expression",
    )
  }

  @Test
  fun test_segfault() {
    val signature = computeSignature("crash_output_2.txt")
    assertThat(signature).hasSize(1)
    assertThat(signature.first())
      .isEqualTo(
        "internal compiler error: Segmentation fault signal terminated program cc1",
      )
  }

  @Test
  fun test_segfault_4() {
    val signature = computeSignature("crash_output_4.txt")
    assertThat(signature).containsExactly(
      "internal compiler error: Segmentation fault",
      "crash_signal",
      "is_gimple_variable",
      "is_gimple_id",
    )
  }

  @Test
  fun test_segfault_with_stacktrace() {
    val signature = computeSignature("crash_output_3.txt")
    assertThat(signature).containsExactly(
      "internal compiler error: Segmentation fault",
      "crash_signal",
      "is_gimple_variable",
      "is_gimple_id",
    )
  }

  @Test
  fun testFCompareDebug() {
    val signature = gccDetector.detectCrashSignatureFromStderr(
      listOf(
        """
      error: t.c: '-fcompare-debug' failure
        """.trimIndent(),
      ),
    )
    assertThat(signature).hasSize(1)
    assertThat(signature.single()).isEqualTo("-fcompare-debug")
  }
}
