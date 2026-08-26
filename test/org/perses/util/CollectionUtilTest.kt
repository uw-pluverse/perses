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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.CollectionUtil.NonEmptyInternal
import org.perses.util.CollectionUtil.clusterIdsIntoRanges
import org.perses.util.CollectionUtil.computeDifference
import org.perses.util.CollectionUtil.mergeContinuousElementsIntoRegions
import org.perses.util.CollectionUtil.removeElementBySwappingLastElement
import org.perses.util.CollectionUtil.removeElementsFromLinkedList
import org.perses.util.CollectionUtil.removeElementsFromList
import org.perses.util.CollectionUtil.removeNullFromList
import java.util.LinkedList
import java.util.function.Predicate

@RunWith(JUnit4::class)
class CollectionUtilTest {
  @Test
  fun testSlideReverseEmptyRange() {
    assertThrows(Exception::class.java) {
      CollectionUtil.slideReverseIfSlideable(
        beginRangeInclusive = 0,
        endRangeExclusive = 0,
        slidingWindowSize = 1,
      )
    }
  }

  @Test
  fun testSlideReverseSingleElement() {
    val result =
      CollectionUtil
        .slideReverseIfSlideable(
          beginRangeInclusive = 0,
          endRangeExclusive = 1,
          slidingWindowSize = 1,
        ).toList()
    assertThat(result).containsExactly(NonEmptyInternal(0, 1))
  }

  @Test
  fun testSlideReverseTwoElements() {
    val result =
      CollectionUtil
        .slideReverseIfSlideable(
          beginRangeInclusive = 1,
          endRangeExclusive = 3,
          slidingWindowSize = 1,
        ).toList()
    assertThat(result)
      .containsExactly(
        NonEmptyInternal(2, 3),
        NonEmptyInternal(1, 2),
      ).inOrder()
  }

  @Test
  fun testSlideReverseThreeElements() {
    val result =
      CollectionUtil
        .slideReverseIfSlideable(
          beginRangeInclusive = 1,
          endRangeExclusive = 4,
          slidingWindowSize = 1,
        ).toList()
    assertThat(result)
      .containsExactly(
        NonEmptyInternal(3, 4),
        NonEmptyInternal(2, 3),
        NonEmptyInternal(1, 2),
      ).inOrder()
  }

  @Test
  fun testSlideReverseNotEnoughElements() {
    val result =
      CollectionUtil
        .slideReverseIfSlideable(
          beginRangeInclusive = 0,
          endRangeExclusive = 2,
          slidingWindowSize = 4,
        ).toList()
    assertThat(result).isEmpty()
  }

  @Test
  fun testSlideReverseInvalidWindowSize() {
    assertThrows(Exception::class.java) {
      CollectionUtil.slideReverseIfSlideable(
        beginRangeInclusive = 0,
        endRangeExclusive = 2,
        slidingWindowSize = 0,
      )
    }
  }

  @Test
  fun testCountElements() {
    assertThat(CollectionUtil.countElementsInList(0, 0)).isEqualTo(0)
    assertThat(CollectionUtil.countElementsInList(1, 0)).isEqualTo(1)
    assertThat(CollectionUtil.countElementsInList(3, 1)).isEqualTo(2)
  }

  @Test
  fun testIteratorNextOrNull() {
    val iterator = listOf(1).iterator()
    assertThat(iterator.nextOrNull()).isEqualTo(1)
    assertThat(iterator.nextOrNull()).isNull()
    assertThat(iterator.nextOrNull()).isNull()
  }

  @Test
  fun testRemoveNullFromList() {
    run {
      val list = ArrayList<Int?>()
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(0)
      list.add(1)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(1)
      list.add(null)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(1)
      list.add(null)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(1)
      list[0] = null
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(0)
    }
    run {
      val list = ArrayList<Int?>()
      list.add(1)
      list.add(2)
      list.add(3)
      list.add(4)
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(4)
      list[1] = null
      removeNullFromList(list)
      assertThat(list.size).isEqualTo(3)
    }
  }

  @Test
  fun testRemoveElementBySwappingLastElement() {
    val list = ArrayList<Int>()
    run {
      list.clear()
      list.add(1)
      removeElementBySwappingLastElement(list, 0)
      assertThat(list.size).isEqualTo(0)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementBySwappingLastElement(list, 0)
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementBySwappingLastElement(list, 1)
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(1)
    }
  }

  @Test
  fun testRemoveElementsFromLinkedList() {
    val list = LinkedList<Int>()
    run {
      list.clear()
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(0)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      removeElementsFromLinkedList(list, Predicate { i: Int -> i == 1 })
      assertThat(list.size).isEqualTo(2)
      assertThat(list[0]).isEqualTo(2)
      assertThat(list[1]).isEqualTo(2)
    }
  }

  @Test
  fun testRemoveElementsFromList() {
    val list = ArrayList<Int>()
    run {
      list.clear()
      list.add(1)
      removeElementsFromList(list) { _, element -> element == 1 }
      assertThat(list.size).isEqualTo(0)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(1)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(1)
      assertThat(list[0]).isEqualTo(2)
    }
    run {
      list.clear()
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      list.add(2)
      list.add(1)
      list.add(1)
      removeElementsFromList(list) { _, i -> i == 1 }
      assertThat(list.size).isEqualTo(2)
      assertThat(list[0]).isEqualTo(2)
      assertThat(list[1]).isEqualTo(2)
    }
  }

  @Test
  fun testVisitDifference() {
    // TODO: test it here.
    val superList = listOf("a", "b", "c", "d")
    val a = superList[0]
    val b = superList[1]
    val c = superList[2]
    val d = superList[3]

    assertThat(computeDifference(superList, listOf(a))).containsExactly(b, c, d).inOrder()
    assertThat(computeDifference(superList, listOf())).containsExactly(a, b, c, d).inOrder()
    assertThat(computeDifference(superList, listOf(b))).containsExactly(a, c, d).inOrder()
    assertThat(computeDifference(superList, listOf(c))).containsExactly(a, b, d).inOrder()
    assertThat(computeDifference(superList, listOf(b, d))).containsExactly(a, c).inOrder()
  }

  private val euqalizer = { a: Int, b: Int -> a == b }

  @Test
  fun testMergeContinuousElementsIntoRegionsEmpty() {
    val list = mergeContinuousElementsIntoRegions(listOf(), euqalizer)
    assertThat(list).isEmpty()
  }

  private fun testmergeContinuousElementsIntoRegions(
    list: List<Int>,
    vararg expected: ImmutableList<Int>,
  ) {
    assertThat(mergeContinuousElementsIntoRegions(list, euqalizer))
      .containsExactly(*expected)
      .inOrder()
  }

  @Test
  fun test_mergeContinuousElementsIntoRegions_distinct() {
    testmergeContinuousElementsIntoRegions(listOf(1), ImmutableList.of(1))
    testmergeContinuousElementsIntoRegions(listOf(1, 2), ImmutableList.of(1), ImmutableList.of(2))
    testmergeContinuousElementsIntoRegions(
      listOf(1, 2, 3),
      ImmutableList.of(1),
      ImmutableList.of(2),
      ImmutableList.of(3),
    )
  }

  @Test
  fun test_mergeContinuousElementsIntoRegions_duplicate() {
    testmergeContinuousElementsIntoRegions(listOf(1, 1), ImmutableList.of(1, 1))
    testmergeContinuousElementsIntoRegions(
      listOf(1, 1, 2),
      ImmutableList.of(1, 1),
      ImmutableList.of(2),
    )
    testmergeContinuousElementsIntoRegions(
      listOf(1, 1, 2, 2, 1, 1),
      ImmutableList.of(1, 1),
      ImmutableList.of(2, 2),
      ImmutableList.of(1, 1),
    )
    testmergeContinuousElementsIntoRegions(
      listOf(1, 2, 2),
      ImmutableList.of(1),
      ImmutableList.of(2, 2),
    )
  }

  private fun testSlideReverse(
    list: ImmutableList<Int>,
    slidingWindowSize: Int,
    vararg expected: NonEmptyInternal,
  ) {
    val copy = ArrayList<NonEmptyInternal>()
    CollectionUtil.slideReverseIfSlideable(list, slidingWindowSize).forEach {
      copy.add(it.interval)
    }
    assertThat(copy).containsExactly(*expected)
  }

  @Test
  fun test_slideReverse_invalid() {
    assertThrows(Throwable::class.java) {
      CollectionUtil.slideReverseIfSlideable(ImmutableList.of<Int>(), 0)
    }
  }

  @Test
  fun test_slideReverse_size_1() {
    val list = ImmutableList.of(1)
    testSlideReverse(list, slidingWindowSize = 1, NonEmptyInternal(0, 1))
    testSlideReverse(list, slidingWindowSize = 2)
  }

  @Test
  fun test_slideReverse_size_2() {
    val list = ImmutableList.of(1, 2)
    testSlideReverse(list, 1, NonEmptyInternal(1, 2), NonEmptyInternal(0, 1))
    testSlideReverse(list, 2, NonEmptyInternal(0, 2))
    testSlideReverse(list, 3)
  }

  @Test
  fun test_slideReverse_size_3() {
    val list = ImmutableList.of(1, 2, 3)
    testSlideReverse(
      list,
      1,
      NonEmptyInternal(2, 3),
      NonEmptyInternal(1, 2),
      NonEmptyInternal(0, 1),
    )
    testSlideReverse(
      list,
      2,
      NonEmptyInternal(1, 3),
      NonEmptyInternal(0, 2),
    )
    testSlideReverse(
      list,
      3,
      NonEmptyInternal(0, 3),
    )
    testSlideReverse(list, 4)
  }

  @Test
  fun testClusterIdsIntoRange() {
    val idExtractor = { id: Int -> id }
    clusterIdsIntoRanges(listOf(1), idExtractor).let {
      assertThat(it).containsExactly("1")
    }
    clusterIdsIntoRanges(listOf(1, 2), idExtractor).let {
      assertThat(it).containsExactly("1-2")
    }
    clusterIdsIntoRanges(listOf(1, 2, 3), idExtractor).let {
      assertThat(it).containsExactly("1-3")
    }
    clusterIdsIntoRanges(listOf(1, 3, 4, 5), idExtractor).let {
      assertThat(it).containsExactly("1", "3-5")
    }
  }
}
