/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class RccConfigEncodingTest {
  private val baseElements = ImmutableList.of("a", "b", "c", "d", "e")
  private val baseProgram =
    baseElements.indices
      .map { index ->
        ElementWrapper(index, baseElements[index], "payload")
      }.let { ImmutableList.copyOf(it) }

  private val cache = RccConfigCache(baseProgram)

  @Test
  fun test() {
    test(ImmutableList.of("a", "b", "c", "d", "e"), intArrayOf(0, 5))
    test(ImmutableList.of("a", "b", "c", "d"), intArrayOf(0, 4))
    test(ImmutableList.of("a", "b", "c"), intArrayOf(0, 3))
    test(ImmutableList.of("a", "b"), intArrayOf(0, 2))
    test(ImmutableList.of("a"), intArrayOf(0, 1))
    test(ImmutableList.of(), intArrayOf())
    test(ImmutableList.of("b", "c", "d", "e"), intArrayOf(1, 5))
    test(ImmutableList.of("c", "d", "e"), intArrayOf(2, 5))
    test(ImmutableList.of("d", "e"), intArrayOf(3, 5))
    test(ImmutableList.of("e"), intArrayOf(4, 5))
    test(ImmutableList.of("a", "c", "d", "e"), intArrayOf(0, 1, 2, 5))
    test(ImmutableList.of("a", "c", "e"), intArrayOf(0, 1, 2, 3, 4, 5))
    test(ImmutableList.of("a", "b", "e"), intArrayOf(0, 2, 4, 5))
  }

  private fun test(
    lexemes: ImmutableList<String>,
    expectedIntervals: IntArray,
  ) {
    val config =
      lexemes
        .map { lexeme ->
          baseProgram.find { it.element == lexeme }!!
        }.let { ImmutableList.copyOf(it) }

    val encoding = cache.encode(config)!!
    assertThat(encoding.intervalsFromEncoding).isEqualTo(expectedIntervals)

    val restored = cache.decode(baseProgram, encoding)
    assertThat(restored.map { it.element }).containsExactlyElementsIn(lexemes).inOrder()
  }

  @Test
  fun test_hashCode_equal() {
    val config1 = ImmutableList.of(baseProgram[0], baseProgram[1])
    val config2 = ImmutableList.of(baseProgram[0], baseProgram[2])

    val encoding1 = cache.encode(config1)!!
    val encoding2 = cache.encode(config2)!!

    assertThat(encoding1).isNotEqualTo(encoding2)
    assertThat(encoding1.hashCode()).isNotEqualTo(encoding2.hashCode())

    val encoding1Again = cache.encode(config1)!!
    assertThat(encoding1).isEqualTo(encoding1Again)
    assertThat(encoding1.hashCode()).isEqualTo(encoding1Again.hashCode())
  }
}
