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
package org.perses.util

import com.google.common.collect.ImmutableBiMap
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import com.google.common.primitives.ImmutableIntArray
import org.perses.util.Util.lazyAssert
import java.util.Random

fun <T> Random.sample(list: List<T>): T {
  val size = list.size
  require(size > 0)
  return list[nextInt(size)]
}

inline fun <T> Iterable<T>.forEachElementAndGap(
  elementVisitor: (T) -> Unit,
  gapVisitor: () -> Unit,
) {
  return asSequence().forEachElementAndGap(elementVisitor, gapVisitor)
}

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

fun Sequence<Int>.toImmutableIntArray(): ImmutableIntArray {
  return fold(ImmutableIntArray.builder()) { builder, e ->
    builder.add(e)
    builder
  }.build()
}

fun <T, V> List<T>.transformToImmutableList(transform: (T) -> V): ImmutableList<V> {
  return fold(ImmutableList.builderWithExpectedSize<V>(size)) { builder, e ->
    builder.add(transform(e))
    builder
  }.build()
}

fun <T> List<T>.filterToImmutableList(predicateForDeletion: (T) -> Boolean): ImmutableList<T> {
  return asSequence().filter { !predicateForDeletion(it) }.toImmutableList()
}

fun <T, V> Sequence<T>.transformToImmutableList(transform: (T) -> V): ImmutableList<V> {
  return fold(ImmutableList.builder<V>()) { builder, e ->
    builder.add(transform(e))
    builder
  }.build()
}

fun <T, V> Iterable<T>.transformToImmutableList(
  transform: (T) -> V,
) = asSequence().transformToImmutableList(
  transform,
)

fun <T> ImmutableList<T>.excludesRegion(
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

fun <T : Comparable<T>> Iterable<T>.isSortedAscendingly(): Boolean {
  return isSortedAscendinglyBy { it }
}

fun <T> Iterable<T>.toImmutableList(): ImmutableList<T> {
  return ImmutableList.copyOf(this)
}

fun <T> Array<T>.toImmutableList(): ImmutableList<T> {
  return ImmutableList.copyOf(this)
}

operator fun <T> ImmutableList<T>.plus(other: Iterable<T>): ImmutableList<T> {
  val sizeOther = if (other is Collection<T>) {
    other.size
  } else {
    1
  }
  val builder = ImmutableList.builderWithExpectedSize<T>(size + sizeOther)
  builder.addAll(this)
  builder.addAll(other)
  return builder.build()
}

fun <T> Sequence<T>.toImmutableList(): ImmutableList<T> {
  return fold(ImmutableList.builder<T>()) { builder, e ->
    builder.add(e)
  }.build()
}

fun <T> Sequence<T>.toImmutableSet(): ImmutableSet<T> {
  return fold(ImmutableSet.builder<T>()) { builder, e ->
    builder.add(e)
  }.build()
}

fun <K, V> Sequence<Map.Entry<K, V>>.toImmutableMap(): ImmutableMap<K, V> {
  return fold(ImmutableMap.builder<K, V>()) { builder, e ->
    builder.put(e.key, e.value)
  }.build()
}

fun <K, V> Iterable<Pair<K, V>>.toImmutableMap(): ImmutableMap<K, V> {
  return fold(ImmutableMap.builder<K, V>()) { builder, e ->
    builder.put(e.first, e.second)
  }.build()
}

fun <K, V> Sequence<Pair<K, V>>.toImmutableBiMap(): ImmutableBiMap<K, V> {
  return fold(ImmutableBiMap.builder<K, V>()) { builder, pair ->
    builder.put(pair.first, pair.second)
  }.build()
}

inline fun <K, V, T> Sequence<T>.toImmutableMap(
  keyFunc: (T) -> K,
  valueFunc: (T) -> V,
): ImmutableMap<K, V> {
  return fold(ImmutableMap.builder<K, V>()) { builder, t ->
    builder.put(keyFunc(t), valueFunc(t))
  }.build()
}

@JvmName("toImmutableMapPair")
fun <K, V> Sequence<Pair<K, V>>.toImmutableMap(): ImmutableMap<K, V> {
  return fold(ImmutableMap.builder<K, V>()) { builder, e ->
    builder.put(e.first, e.second)
  }.build()
}

fun CharSequence.removeWhitespaces() = this.filterNot { it.isWhitespace() }

fun CharSequence.containsNoWhitespace(): Boolean {
  return none { it.isWhitespace() }
}

/**
 * Make when() statement exhaustive.
 *
 * Reference: https://blog.karumi.com/kotlin-android-development-6-months-into-it/
 */
@Suppress("unused")
val Any?.exhaustive
  get() = Unit
