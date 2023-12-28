/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
import it.unimi.dsi.fastutil.ints.IntArrayList
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC

@RunWith(JUnit4::class)
class CompactProgramEncodingTest {

  private val program = TestUtility.createTokenizedProgramFromString(
    "int a, b;",
    LanguageC,
  )

  @Test
  fun testIntervalEncoding() {
    val intervals = IntArrayList()
    intervals.add(0)
    intervals.add(1)
    val encoding = CompactProgramEncoding.createIntervalEncoding(program, intervals, 1)
    assertThat(encoding.encodingSize()).isEqualTo(2)
  }

  @Test
  fun testCompressedEncoding() {
    val intervals = IntArrayList()
    intervals.add(0)
    intervals.add(1)

    intervals.add(1)
    intervals.add(2)

    intervals.add(2)
    intervals.add(3)

    val compressedEncoding = CompactProgramEncoding.createCompressedEncoding(program, intervals, 3)
    assertThat(compressedEncoding.encodingSize()).isEqualTo(3)

    val intervalEncoding = CompactProgramEncoding.createIntervalEncoding(program, intervals, 3)
    assertThat(intervalEncoding.encodingSize()).isEqualTo(6)
  }
}
