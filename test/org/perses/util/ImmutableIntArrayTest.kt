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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ImmutableIntArrayTest {
  @Test
  fun testOfAndAccessors() {
    val array = ImmutableIntArray.of(10, 20, 30)
    assertThat(array.size).isEqualTo(3)
    assertThat(array.lastIndex).isEqualTo(2)
    assertThat(array.isEmpty()).isFalse()
    assertThat(array.isNotEmpty()).isTrue()
    assertThat(array[0]).isEqualTo(10)
    assertThat(array[1]).isEqualTo(20)
    assertThat(array[2]).isEqualTo(30)
  }

  @Test
  fun testEmpty() {
    assertThat(ImmutableIntArray.EMPTY.size).isEqualTo(0)
    assertThat(ImmutableIntArray.EMPTY.isEmpty()).isTrue()
    assertThat(ImmutableIntArray.of()).isEqualTo(ImmutableIntArray.EMPTY)
    assertThat(ImmutableIntArray.copyOf(IntArray(0))).isEqualTo(ImmutableIntArray.EMPTY)
    assertThat(ImmutableIntArray.copyOf(emptyList())).isEqualTo(ImmutableIntArray.EMPTY)
  }

  @Test
  fun testForEach() {
    val collected = ArrayList<Int>()
    ImmutableIntArray.of(1, 2, 3).forEach { collected.add(it) }
    assertThat(collected).containsExactly(1, 2, 3).inOrder()
  }

  @Test
  fun testIndexOfAndContains() {
    val array = ImmutableIntArray.of(5, 7, 5, 9)
    assertThat(array.indexOf(5)).isEqualTo(0)
    assertThat(array.lastIndexOf(5)).isEqualTo(2)
    assertThat(array.indexOf(42)).isEqualTo(-1)
    assertThat(array.lastIndexOf(42)).isEqualTo(-1)
    assertThat(array.contains(9)).isTrue()
    assertThat(array.contains(42)).isFalse()
  }

  @Test
  fun testSubArray() {
    val array = ImmutableIntArray.of(1, 2, 3, 4, 5)
    assertThat(array.subArray(1, 4).contentEquals(ImmutableIntArray.of(2, 3, 4))).isTrue()
    assertThat(array.subArray(2, 2)).isEqualTo(ImmutableIntArray.EMPTY)
    assertThat(array.subArray(0, 5).contentEquals(array)).isTrue()
  }

  @Test
  fun testCopyOfIntArrayIsDefensive() {
    val source = intArrayOf(1, 2, 3)
    val array = ImmutableIntArray.copyOf(source)
    source[0] = 99
    assertThat(array[0]).isEqualTo(1)
  }

  @Test
  fun testOfVarargIsDefensive() {
    val source = intArrayOf(1, 2, 3)
    val array = ImmutableIntArray.of(*source)
    source[0] = 99
    assertThat(array[0]).isEqualTo(1)
  }

  @Test
  fun testToIntArrayIsDefensive() {
    val array = ImmutableIntArray.of(1, 2, 3)
    val out = array.toIntArray()
    out[0] = 99
    assertThat(array[0]).isEqualTo(1)
    assertThat(out).isEqualTo(intArrayOf(99, 2, 3))
  }

  @Test
  fun testBuilder() {
    val array =
      ImmutableIntArray
        .builder()
        .add(1)
        .addAll(intArrayOf(2, 3))
        .addAll(listOf(4, 5))
        .addAll(ImmutableIntArray.of(6, 7))
        .build()
    assertThat(array.contentEquals(ImmutableIntArray.of(1, 2, 3, 4, 5, 6, 7))).isTrue()
    assertThat(array.size).isEqualTo(7)
  }

  @Test
  fun testBuilderGrowsBeyondInitialCapacity() {
    val builder = ImmutableIntArray.builder(2)
    repeat(100) { builder.add(it) }
    val array = builder.build()
    assertThat(array.size).isEqualTo(100)
    assertThat(array[0]).isEqualTo(0)
    assertThat(array[99]).isEqualTo(99)
  }

  @Test
  fun testBuilderReuseAfterBuildDoesNotMutateBuiltInstance() {
    val builder = ImmutableIntArray.builder(3)
    builder.add(1).add(2).add(3)
    val firstExactFit = builder.build()
    // Append more, forcing reallocation; the first build must be unaffected.
    builder.add(4)
    val second = builder.build()
    assertThat(firstExactFit.contentEquals(ImmutableIntArray.of(1, 2, 3))).isTrue()
    assertThat(second.contentEquals(ImmutableIntArray.of(1, 2, 3, 4))).isTrue()
  }

  @Test
  fun testEmptyBuilder() {
    assertThat(ImmutableIntArray.builder().build()).isEqualTo(ImmutableIntArray.EMPTY)
  }

  @Test
  fun testContentEqualsAndContentHashCode() {
    val a = ImmutableIntArray.of(1, 2, 3)
    val b = ImmutableIntArray.copyOf(intArrayOf(1, 2, 3))
    val c = ImmutableIntArray.of(1, 2, 4)
    assertThat(a.contentEquals(b)).isTrue()
    assertThat(a.contentHashCode()).isEqualTo(b.contentHashCode())
    assertThat(a.contentEquals(c)).isFalse()
  }

  @Test
  fun testEqualityIsIdentityBased() {
    // Documented limitation: a value class cannot override equals/hashCode, so distinct
    // instances with equal contents are not `==`. Use contentEquals/compareTo for content.
    val a = ImmutableIntArray.of(1, 2, 3)
    val b = ImmutableIntArray.copyOf(intArrayOf(1, 2, 3))
    assertThat(a == b).isFalse()
    assertThat(a == a).isTrue()
    assertThat(a.compareTo(b)).isEqualTo(0)
    // The empty array is a shared singleton, so identity equality still holds for it.
    assertThat(ImmutableIntArray.of() == ImmutableIntArray.EMPTY).isTrue()
  }

  @Test
  fun testToString() {
    assertThat(ImmutableIntArray.of(1, 2, 3).toString()).isEqualTo("[1, 2, 3]")
    assertThat(ImmutableIntArray.EMPTY.toString()).isEqualTo("[]")
  }

  @Test
  fun testCompareToLexicographically() {
    assertThat(ImmutableIntArray.of(1, 2).compareTo(ImmutableIntArray.of(1, 2))).isEqualTo(0)
    // Prefix sorts before the longer array.
    assertThat(ImmutableIntArray.of(1, 2) < ImmutableIntArray.of(1, 2, 3)).isTrue()
    // Element difference dominates length.
    assertThat(ImmutableIntArray.of(1, 2, 3) < ImmutableIntArray.of(1, 3)).isTrue()
    assertThat(ImmutableIntArray.of(2) > ImmutableIntArray.of(1, 9, 9)).isTrue()
    assertThat(ImmutableIntArray.EMPTY < ImmutableIntArray.of(0)).isTrue()
  }

  @Test
  fun testIsComponentwiseGreaterThanOrEqualTo() {
    val base = ImmutableIntArray.of(2, 2)
    // Equal and strictly-greater-everywhere both satisfy >=.
    assertThat(base.isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(2, 2))).isTrue()
    assertThat(base.isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(1, 1))).isTrue()
    assertThat(base.isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(2, 1))).isTrue()
    // Smaller in even one component breaks dominance.
    assertThat(base.isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(2, 3))).isFalse()
    assertThat(base.isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(3, 3))).isFalse()
    // Partial order: mutually non-dominating vectors, unlike lexicographical compareTo.
    val a = ImmutableIntArray.of(2, 1)
    val b = ImmutableIntArray.of(1, 2)
    assertThat(a.isComponentwiseGreaterThanOrEqualTo(b)).isFalse()
    assertThat(b.isComponentwiseGreaterThanOrEqualTo(a)).isFalse()
    assertThat(a > b).isTrue() // compareTo (total order) still ranks them
    // Single element behaves like a scalar >=.
    assertThat(ImmutableIntArray.of(5).isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(3)))
      .isTrue()
    assertThat(ImmutableIntArray.of(3).isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(5)))
      .isFalse()
  }

  @Test
  fun testIsComponentwiseGreaterThanOrEqualToRequiresEqualLengths() {
    val thrown =
      try {
        ImmutableIntArray.of(1, 2).isComponentwiseGreaterThanOrEqualTo(ImmutableIntArray.of(1))
        false
      } catch (e: IllegalArgumentException) {
        true
      }
    assertThat(thrown).isTrue()
  }

  @Test
  fun testSortedOrder() {
    val unsorted =
      listOf(
        ImmutableIntArray.of(1, 3),
        ImmutableIntArray.of(1, 2, 3),
        ImmutableIntArray.EMPTY,
        ImmutableIntArray.of(1, 2),
        ImmutableIntArray.of(2),
      )
    // Map to lists for comparison, since equality is identity-based (see testEqualityIsIdentityBased).
    assertThat(unsorted.sorted().map { it.toIntArray().toList() })
      .containsExactly(
        emptyList<Int>(),
        listOf(1, 2),
        listOf(1, 2, 3),
        listOf(1, 3),
        listOf(2),
      ).inOrder()
  }
}
