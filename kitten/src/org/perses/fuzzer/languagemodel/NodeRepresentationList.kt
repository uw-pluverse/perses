/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer.languagemodel

import com.google.common.primitives.ImmutableLongArray
import it.unimi.dsi.fastutil.longs.LongArrayList

// TODO(Zhenyang): the entire file needs testing.
@JvmInline
value class MutableNodeRepresentationList internal constructor(
  @PublishedApi internal val nodes: LongArrayList,
) {

  fun add(node: NodeRepresentation) {
    nodes.add(node.longValue)
  }

  @Suppress("NOTHING_TO_INLINE")
  inline fun get(index: Int): NodeRepresentation = NodeRepresentation(nodes.getLong(index))

  inline fun forEachWithIndex(action: (index: Int, node: NodeRepresentation) -> Unit) {
    for (i in 0 until nodes.size) {
      action(i, get(i))
    }
  }

  val size: Int
    get() = nodes.size

  companion object {
    fun create(capacity: Int = 10): MutableNodeRepresentationList {
      return MutableNodeRepresentationList(LongArrayList(capacity))
    }
  }
}

class NodeRepresentationList(@PublishedApi internal val nodes: ImmutableLongArray) {
  private val hashCode = nodes.hashCode()

  inline val size: Int
    get() = nodes.length()

  @Suppress("NOTHING_TO_INLINE")
  inline operator fun get(index: Int): NodeRepresentation = NodeRepresentation(nodes[index])

  override fun hashCode(): Int {
    return hashCode
  }

  override fun equals(other: Any?): Boolean {
    if (other == null || other !is NodeRepresentationList) {
      return false
    }
    return nodes == other.nodes
  }

  override fun toString(): String {
    val body = (0 until nodes.length()).joinToString(separator = ", ") { get(it).toString() }
    return buildString {
      append('[')
      append(body)
      append(']')
    }
  }

  class Builder(initialSize: Int = 10) {
    private val builder = ImmutableLongArray.builder(initialSize)
    var size: Int = 0
      private set

    @Suppress("NOTHING_TO_INLINE")
    private inline fun addLongValue(node: Long) {
      builder.add(node)
      ++size
    }

    fun add(node: NodeRepresentation) {
      addLongValue(node.longValue)
    }

    fun addAll(list: NodeRepresentationList) {
      list.nodes.forEach { addLongValue(it) }
    }

    fun addSubListOf(
      list: NodeRepresentationList,
      startIndexInclusive: Int,
      endIndexExclusive: Int,
    ) {
      assert(startIndexInclusive <= endIndexExclusive)
      for (i in startIndexInclusive until endIndexExclusive) {
        addLongValue(list[i].longValue)
      }
    }

    fun build() = NodeRepresentationList(builder.build())
  }
}
