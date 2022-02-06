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
package org.perses.util

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
  gapVisitor: () -> Unit
) {
  return asSequence().forEachElementAndGap(elementVisitor, gapVisitor)
}

inline fun <T> Sequence<T>.forEachElementAndGap(
  elementVisitor: (T) -> Unit,
  gapVisitor: () -> Unit
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

fun <T> Iterable<T>.toImmutableList(): ImmutableList<T> {
  return ImmutableList.copyOf(this)
}

fun <T> Array<T>.toImmutableList(): ImmutableList<T> {
  return ImmutableList.copyOf(this)
}

operator fun <T> ImmutableList<T>.plus(other: Iterable<T>): ImmutableList<T> {
  val builder = ImmutableList.builderWithExpectedSize<T>(size)
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

inline fun <K, V, T> Sequence<T>.toImmutableMap(
  keyFunc: (T) -> K,
  valueFunc: (T) -> V
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
