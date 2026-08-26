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
import java.util.IdentityHashMap
import java.util.LinkedList
import java.util.concurrent.ConcurrentHashMap
import java.util.function.Predicate

@Suppress("NOTHING_TO_INLINE")
inline fun <T> Iterator<T>.nextOrNull(): T? =
  if (hasNext()) {
    next()
  } else {
    null
  }

object CollectionUtil {
  @JvmStatic
  @Suppress("NOTHING_TO_INLINE")
  fun countElementsInList(
    endIndexExclusive: Int,
    startIndexInclusive: Int,
  ): Int = endIndexExclusive - startIndexInclusive

  @JvmStatic
  fun <T> removeElementsFromLinkedList(
    list: LinkedList<T>?,
    removalCondition: Predicate<T>,
  ) {
    if (list.isNullOrEmpty()) {
      return
    }
    val iterator = list.iterator()
    while (iterator.hasNext()) {
      val t = iterator.next()
      if (removalCondition.test(t)) {
        iterator.remove()
      }
    }
  }

  fun <T> swap(
    list: ArrayList<T>,
    i: Int,
    j: Int,
  ) {
    val temp = list[i]
    list[i] = list[j]
    list[j] = temp
  }

  @JvmStatic
  fun <T> createConcurrentSet(): MutableSet<T> = ConcurrentHashMap.newKeySet()

  @JvmStatic
  fun <T> removeElementBySwappingLastElement(
    list: ArrayList<T>,
    index: Int,
  ) {
    require(list.isNotEmpty())
    val last = list.size - 1
    if (index != last) {
      swap(list, index, last)
    }
    list.removeAt(last)
  }

  @JvmStatic
  inline fun <T> removeElementsFromList(
    list: MutableList<T>,
    criterionToKeep: (index: Int, value: T) -> Boolean,
  ) {
    if (list.isEmpty()) {
      return
    }
    var start = 0
    val size = list.size
    for (i in 0 until size) {
      val element = list[i]
      if (criterionToKeep(i, element)) {
        continue
      }
      if (start != i) list[start] = element
      ++start
    }
    for (i in size - 1 downTo start) {
      list.removeAt(i)
    }
  }

  @JvmStatic
  fun <T : Any> mergeContinuousElementsIntoRegions(
    list: List<T>,
    equalizer: (T, T) -> Boolean,
  ): ImmutableList<ImmutableList<T>> {
    if (list.isEmpty()) {
      return ImmutableList.of()
    }
    val result = ImmutableList.builder<ImmutableList<T>>()
    var currentRegion = ImmutableList.builder<T>()
    var prev = list.first()
    currentRegion.add(prev)
    for (i in 1..list.size) {
      if (i == list.size) {
        result.add(currentRegion.build())
        break
      }
      val current = list[i]
      if (equalizer(prev, current)) {
        currentRegion.add(current)
      } else {
        result.add(currentRegion.build())
        currentRegion = ImmutableList.builder()
        currentRegion.add(current)
      }
      prev = current
    }
    return result.build()
  }

  data class NonEmptySublist<T : Any>(
    val interval: NonEmptyInternal,
    val originalList: ImmutableList<T>,
  ) {
    val elements = originalList.subList(interval.inclusiveStart, interval.exclusiveEnd)

    init {
      lazyAssert { elements.size == interval.size() }
    }
  }

  data class NonEmptyInternal(
    val inclusiveStart: Int,
    val exclusiveEnd: Int,
  ) {
    init {
      lazyAssert({ inclusiveStart < exclusiveEnd }) {
        "$inclusiveStart, $exclusiveEnd"
      }
    }

    fun size() = exclusiveEnd - inclusiveStart

    fun isInRange(value: Int) = value in inclusiveStart until exclusiveEnd

    companion object {
      // TODO(cnsun): needs tests.
      fun <T : Any> ImmutableList<T>.sublist(interval: NonEmptyInternal): ImmutableList<T> =
        subList(interval.inclusiveStart, interval.exclusiveEnd)
    }
  }

  @JvmStatic
  fun <T : Any> slideReverseIfSlideable(
    list: ImmutableList<T>,
    slidingWindowSize: Int,
  ): Sequence<NonEmptySublist<T>> {
    require(slidingWindowSize > 0) { slidingWindowSize }
    return slideReverseIfSlideable(
      beginRangeInclusive = 0,
      endRangeExclusive = list.size,
      slidingWindowSize,
    ).map { NonEmptySublist(it, list) }
  }

  @JvmStatic
  fun slideReverseIfSlideable(
    beginRangeInclusive: Int,
    endRangeExclusive: Int,
    slidingWindowSize: Int,
  ): Sequence<NonEmptyInternal> {
    require(endRangeExclusive > beginRangeInclusive)
    require(slidingWindowSize > 0) { slidingWindowSize }
    return sequence {
      for (endIndex in endRangeExclusive downTo beginRangeInclusive + slidingWindowSize) {
        val startIndex = endIndex - slidingWindowSize
        lazyAssert({ endIndex > startIndex })
        yield(NonEmptyInternal(startIndex, endIndex))
      }
    }
  }

  @JvmStatic
  fun <T> removeNullFromList(list: ArrayList<T?>) {
    removeElementsFromList(list) { _, element -> element == null }
  }

  @JvmStatic
  fun <T : Any> computeDifference(
    superList: List<T>,
    subList: List<T>,
  ): ImmutableList<T> {
    val builder = ImmutableList.builder<T>()
    visitDifference(superList, subList) { builder.add(it) }
    return builder.build()
  }

  @JvmStatic
  inline fun <T> visitDifference(
    superList: List<T>,
    subList: List<T>,
    visitor: (T) -> Unit,
  ) {
    lazyAssert { countDistinctObjects(superList) == superList.size }
    lazyAssert { countDistinctObjects(subList) == subList.size }
    var subIndex = 0
    val subSize = subList.size
    for (element in superList) {
      if (subIndex >= subSize) {
        visitor.invoke(element)
        continue
      }
      if (element === subList[subIndex]) {
        ++subIndex
      } else {
        visitor.invoke(element)
      }
    }
    check(subIndex == subSize) {
      """subIndex=$subIndex, subSize=$subSize
        |superList=$superList
        |subList=$subList
      """.trimMargin()
    }
  }

  @JvmStatic
  fun <T> countDistinctObjects(collection: Collection<T>): Int {
    val map = IdentityHashMap<T, T>(collection.size)
    for (t in collection) {
      map[t] = t
    }
    return map.size
  }

  inline fun <T> clusterIdsIntoRanges(
    list: List<T>,
    idExtractor: (T) -> Int,
  ): List<String> {
    val size = list.size
    if (size == 0) {
      return ImmutableList.of()
    }
    val result = mutableListOf<String>()
    var i = 0
    while (i < size) {
      val start = idExtractor(list[i])
      var end = start
      while ((i + 1) < size && idExtractor(list[i + 1]) == idExtractor(list[i]) + 1) {
        end = idExtractor(list[i + 1])
        ++i
      }
      if (start == end) {
        result.add(start.toString())
      } else {
        result.add("$start-$end")
      }
      ++i
    }
    return result
  }
}
