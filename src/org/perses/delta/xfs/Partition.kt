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
package org.perses.delta.xfs

import com.google.common.collect.ImmutableList
import org.perses.util.Util
import org.perses.util.filterToImmutableList

/**
 * A partition contains a set of SparTreeNodes, and this set should be reduced together. A level in
 * a spar-tree may generate multiple partitions.
 */
class Partition<T>(private var nodes: ImmutableList<T>) {

  init {
    Util.lazyAssert({ nodes.size > 0 }) { "A partition cannot be empty." }
  }

  val first: T
    get() = nodes[0]

  val last: T
    get() = nodes.last()

  val isEmpty: Boolean
    get() = nodes.isEmpty()

  fun size(): Int {
    return nodes.size
  }

  fun getNode(index: Int): T {
    return nodes[index]
  }

  fun asSequence() = nodes.asSequence()

  fun forEach(consumer: (T) -> Unit) {
    nodes.forEach(consumer)
  }

  fun removePermanentlyDeletedNodes(predicateForDeletion: (T) -> Boolean) {
    nodes = nodes.filterToImmutableList(predicateForDeletion)
  }

  fun split(): ImmutableList<Partition<T>> {
    val nodes = nodes
    val size = nodes.size
    Util.lazyAssert { size > 0 }
    if (size <= 1) {
      return emptyPartitionList()
    }
    val halfIndex = (size + 1) / 2
    val first = Builder<T>(halfIndex)
    for (i in 0 until halfIndex) {
      first.addNode(nodes[i])
    }
    val second = Builder<T>(halfIndex)
    for (i in halfIndex until size) {
      second.addNode(nodes[i])
    }
    return ImmutableList.of(first.build(), second.build())
  }

  /** A builder to build a Partition.  */
  class Builder<T>(capacity: Int) {
    private var builder: ImmutableList.Builder<T> = ImmutableList.builderWithExpectedSize<T>(
      capacity,
    )
    var size: Int = 0
      private set

    fun addNode(node: T) {
      ++size
      builder.add(node)
    }

    /** This method builds a partition, and the current builder becomes invalid.  */
    fun build(): Partition<T> {
      return Partition(builder.build())
    }
  }

  companion object {
    fun <T>emptyPartitionList() = ImmutableList.of<T>()
  }
}
