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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.PersesTokenFactory.PersesToken

@RunWith(JUnit4::class)
class IntervalArrayExpanderTest {

  private val tokens = TestUtility.createTokenizedProgramFromString(
    """
    int a, b, c, d;
    """.trimIndent(),
    LanguageC,
  ).tokens

  @Test
  fun test_iterator_empty_interval() {
    val iter = IntervalArrayExpander.expand(intArrayOf())
    assertThat(iter.hasNext()).isFalse()
    assertThat(iter.hasNext()).isFalse()
    Assert.assertThrows(Throwable::class.java) {
      iter.nextInt()
    }
  }

  @Test
  fun test_iterator_two_elements() {
    val iter = IntervalArrayExpander.expand(intArrayOf(0, 2))
    assertThat(iter.hasNext()).isTrue()
    assertThat(iter.nextInt()).isEqualTo(0)

    assertThat(iter.hasNext()).isTrue()
    assertThat(iter.nextInt()).isEqualTo(1)

    assertThat(iter.hasNext()).isFalse()
  }

  @Test
  fun test_iterator_four_elements() {
    val iter = IntervalArrayExpander.expand(intArrayOf(0, 2, 1, 2))

    assertThat(iter.hasNext()).isTrue()
    assertThat(iter.nextInt()).isEqualTo(0)

    assertThat(iter.hasNext()).isTrue()
    assertThat(iter.nextInt()).isEqualTo(1)

    assertThat(iter.hasNext()).isTrue()
    assertThat(iter.nextInt()).isEqualTo(1)

    assertThat(iter.hasNext()).isFalse()
  }

  @Test
  fun test_iterator_one_element() {
    Assert.assertThrows(Throwable::class.java) { IntervalArrayExpander.expand(intArrayOf(0)) }
  }

  @Test
  fun test_iterator_three_elements() {
    Assert.assertThrows(Throwable::class.java) { IntervalArrayExpander.expand(intArrayOf(0, 1, 2)) }
  }

  @Test
  fun testEmptyInterval() {
    val iter = IntervalArrayExpander.expand(intArrayOf(), tokens)
    assertThat(iter.hasNext()).isFalse()
  }

  @Test
  fun testOneElementInterval() {
    val iter = IntervalArrayExpander.expand(intArrayOf(0, 1), tokens)
    val result = toLexemeList(iter)
    assertThat(result).hasSize(1)
    assertThat(result.first()).isEqualTo("int")
  }

  @Test
  fun testTwoElementsInterval() {
    val iter = IntervalArrayExpander.expand(intArrayOf(0, 2), tokens)
    val result = toLexemeList(iter)
    assertThat(result)
      .containsExactly("int", "a").inOrder()
  }

  @Test
  fun testTwoIntervals() {
    val iter = IntervalArrayExpander.expand(intArrayOf(0, 1, 2, 3), tokens)
    val result = toLexemeList(iter)
    assertThat(result).hasSize(2)
    assertThat(result).containsExactly("int", ",")
  }

  fun toLexemeList(iter: Iterator<PersesToken>) =
    ImmutableList.copyOf(iter).asSequence().map { it.text }.toList()
}
