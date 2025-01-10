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
package org.perses.fuzzer.compiler

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compilers.ICompilerCrashDetector.CrashSignature

@RunWith(JUnit4::class)
class CrashSignatureTest {

  @Test
  fun testEquality() {
    val s1 = CrashSignature.build(listOf("a", "b"))
    val s2 = CrashSignature.build(listOf("a", "b"))
    assertThat(s1).isEqualTo(s2)
    assertThat(s1.hashCode()).isEqualTo(s2.hashCode())
  }

  @Test
  fun testInequality() {
    val s1 = CrashSignature.build(listOf("a", "b"))
    val s2 = CrashSignature.build(listOf("b"))
    assertThat(s1).isNotEqualTo(s2)
    assertThat(s1.hashCode()).isNotEqualTo(s2.hashCode())
  }
}
