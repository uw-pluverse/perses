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

import com.google.common.collect.ImmutableBiMap
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import com.google.common.primitives.ImmutableIntArray
import java.util.Random

fun <T> Random.sample(list: List<T>): T {
  val size = list.size
  require(size > 0)
  return list[nextInt(size)]
}

inline fun <T> Iterable<T>.forEachElementAndGap(
  elementVisitor: (T) -> Unit,
  gapVisitor: () -> Unit,
) = asSequence().forEachElementAndGap(elementVisitor, gapVisitor)

inline fun <T> Sequence<T>.forEachElementAndGap(
  elementVisitor: (T) -> Unit,
  gapVisitor: () -> Unit,
) {
  val iterator = iterator()
  if (!iterator.hasNext()) {
    return
  }
  val first = iterator.next()
  elementVisitor(first)
  while (iterator.hasNext()) {
    gapVisitor()
    elementVisitor(iterator.next())
  }
}

fun Iterable<Int>.toImmutableIntArray(): ImmutableIntArray = this.asSequence().toImmutableIntArray()

fun Sequence<Int>.toImmutableIntArray(): ImmutableIntArray =
  fold(ImmutableIntArray.builder()) { builder, e ->
    builder.add(e)
  }.build()

inline fun <T : Any, V : Any> Set<T>.transformToImmutableSet(
  transform: (T) -> V,
): ImmutableSet<V> =
  fold(ImmutableSet.builderWithExpectedSize<V>(size)) { builder, e ->
    builder.add(transform(e))
  }.build()

inline fun <T : Any, V : Any> List<T>.transformToImmutableList(
  transform: (T) -> V,
): ImmutableList<V> =
  fold(ImmutableList.builderWithExpectedSize<V>(size)) { builder, e ->
    builder.add(transform(e))
  }.build()

inline fun <T : Any> List<T>.filterToImmutableList(
  crossinline predicateForDeletion: (T) -> Boolean,
): ImmutableList<T> = asSequence().filter { !predicateForDeletion(it) }.toImmutableList()

inline fun <T : Any, V : Any> Sequence<T>.transformToImmutableList(
  transform: (T) -> V,
): ImmutableList<V> =
  fold(ImmutableList.builder<V>()) { builder, e ->
    builder.add(transform(e))
  }.build()

inline fun <T : Any, V : Any> Iterable<T>.transformToImmutableList(transform: (T) -> V) =
  asSequence().transformToImmutableList(
    transform,
  )

fun <T : Any> ImmutableList<T>.excludesRegion(
  leftIndexInclusive: Int,
  rightIndexExclusive: Int,
): ImmutableList<T> {
  val baseListSize = size
  if (leftIndexInclusive == 0) {
    return subList(rightIndexExclusive, baseListSize)
  }
  if (rightIndexExclusive == baseListSize) {
    return subList(0, leftIndexInclusive)
  }
  val regionSize = rightIndexExclusive - leftIndexInclusive
  val expectedSize = baseListSize - regionSize
  val result = ImmutableList.builderWithExpectedSize<T>(expectedSize)
  for (i in 0 until leftIndexInclusive) {
    result.add(get(i))
  }
  for (i in rightIndexExclusive until baseListSize) {
    result.add(get(i))
  }
  return result.build().also {
    lazyAssert({ it.size == expectedSize }) {
      "${it.size}, $expectedSize"
    }
  }
}

inline fun <T, R : Comparable<R>> Iterable<T>.isSortedAscendinglyBy(
  crossinline selector: (T) -> R?,
): Boolean {
  val iterator = iterator()
  if (!iterator.hasNext()) {
    return true
  }
  val comparator = compareBy(selector)
  var prev = iterator.next()
  while (iterator.hasNext()) {
    val current = iterator.next()
    if (comparator.compare(prev, current) > 0) {
      return false
    }
    prev = current
  }
  return true
}

fun <T : Comparable<T>> Iterable<T>.isSortedAscendingly(): Boolean = isSortedAscendinglyBy { it }

fun <T : Any> Iterable<T>.toImmutableList(): ImmutableList<T> =
  if (this is ImmutableList) {
    this
  } else {
    ImmutableList.copyOf(this)
  }

fun <T : Any> Array<T>.toImmutableList(): ImmutableList<T> = ImmutableList.copyOf(this)

operator fun <T : Any> ImmutableList<T>.plus(other: Iterable<T>): ImmutableList<T> {
  val sizeOther =
    if (other is Collection<T>) {
      other.size
    } else {
      1
    }
  val builder = ImmutableList.builderWithExpectedSize<T>(size + sizeOther)
  builder.addAll(this)
  builder.addAll(other)
  return builder.build()
}

fun <T : Any> Sequence<T>.toImmutableList(): ImmutableList<T> =
  fold(ImmutableList.builder<T>()) { builder, e ->
    builder.add(e)
  }.build()

fun <T : Any> Iterable<T>.toImmutableSet(): ImmutableSet<T> = ImmutableSet.copyOf(this)

fun <T : Any> Sequence<T>.toImmutableSet(): ImmutableSet<T> =
  fold(ImmutableSet.builder<T>()) { builder, e ->
    builder.add(e)
  }.build()

fun <K : Any, V : Any> Sequence<Map.Entry<K, V>>.toImmutableMap(): ImmutableMap<K, V> =
  fold(ImmutableMap.builder<K, V>()) { builder, e ->
    builder.put(e.key, e.value)
  }.build()

@JvmName("toImmutableMapFromPairs")
fun <K : Any, V : Any> Iterable<Pair<K, V>>.toImmutableMap(): ImmutableMap<K, V> =
  fold(ImmutableMap.builder<K, V>()) { builder, e ->
    builder.put(e.first, e.second)
  }.build()

// TODO(cnsun): needs test.
fun <K : Any, V : Any> Map<K, V>.toImmutableMap(): ImmutableMap<K, V> = entries.toImmutableMap()

// TODO(cnsun): needs tests
@JvmName("toImmutableMapFromEntries")
fun <K : Any, V : Any> Iterable<Map.Entry<K, V>>.toImmutableMap(): ImmutableMap<K, V> =
  fold(ImmutableMap.builder<K, V>()) { builder, entry ->
    builder.put(entry.key, entry.value)
  }.build()

fun <K : Any, V : Any, T> Iterable<T>.toImmutableMap(
  keyFunc: (T) -> K,
  valueFunc: (T) -> V,
): ImmutableMap<K, V> =
  fold(ImmutableMap.builder<K, V>()) { builder, e ->
    builder.put(keyFunc(e), valueFunc(e))
  }.build()

fun <K : Any, V : Any> Sequence<Pair<K, V>>.toImmutableBiMap(): ImmutableBiMap<K, V> =
  fold(ImmutableBiMap.builder<K, V>()) { builder, pair ->
    builder.put(pair.first, pair.second)
  }.build()

inline fun <K : Any, V : Any, T> Sequence<T>.toImmutableMap(
  keyFunc: (T) -> K,
  valueFunc: (T) -> V,
): ImmutableMap<K, V> =
  fold(ImmutableMap.builder<K, V>()) { builder, t ->
    builder.put(keyFunc(t), valueFunc(t))
  }.build()

@JvmName("toImmutableMapPair")
fun <K : Any, V : Any> Sequence<Pair<K, V>>.toImmutableMap(): ImmutableMap<K, V> =
  fold(ImmutableMap.builder<K, V>()) { builder, e ->
    builder.put(e.first, e.second)
  }.build()

fun <T : Any> ImmutableList<T>.combine(element: T): ImmutableList<T> =
  ImmutableList.builderWithExpectedSize<T>(this.size + 1).let {
    it.addAll(this)
    it.add(element)
    it.build()
  }

fun CharSequence.removeWhitespaces() = this.filterNot { it.isWhitespace() }

fun CharSequence.containsNoWhitespace(): Boolean = none { it.isWhitespace() }

fun String.padBothEnds(
  desiredLength: Int,
  padChar: Char = ' ',
): String {
  require(desiredLength > 0) { desiredLength }

  val originalLength = this.length

  if (originalLength >= desiredLength) {
    return this // No padding needed or string is already longer
  }

  val totalPadding = desiredLength - originalLength
  val leftPadding = totalPadding / 2
  val rightPadding = totalPadding - leftPadding

  return buildString {
    repeat(leftPadding) { append(padChar) }
    append(this@padBothEnds)
    repeat(rightPadding) { append(padChar) }
  }
}

/**
 * Make when() statement exhaustive.
 *
 * Reference: https://blog.karumi.com/kotlin-android-development-6-months-into-it/
 */
@Suppress("unused")
val Any?.exhaustive
  get() = Unit
