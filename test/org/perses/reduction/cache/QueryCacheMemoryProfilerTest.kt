/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.reduction.cache

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.reduction.cache.QueryCacheMemoryProfiler.Companion.computeMemoryInBytes

@RunWith(JUnit4::class)
class QueryCacheMemoryProfilerTest {

  @Test
  fun testBuiltinTypes() {
    assertThat(computeMemoryInBytes(1)).isEqualTo(16)
    assertThat(computeMemoryInBytes("")).isEqualTo(40)
    assertThat(computeMemoryInBytes("abc")).isEqualTo(48)
  }

  @Test
  fun test_tokenized_program_should_be_ignored() {
    val program = TestUtility.createTokenizedProgramFromString(
      "int a;int b; int c;",
      LanguageC
    )
    assertThat(computeMemoryInBytes(Holder(program))).isEqualTo(16)
    assertThat(computeMemoryInBytes(Holder(program.factory))).isEqualTo(16)
    assertThat(computeMemoryInBytes(Holder(listOf(1, 2, 3, 4)))).isEqualTo(136)
  }

  class Holder<T>(val program: T)
}
