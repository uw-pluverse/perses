/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.reduction.partition

import com.google.common.base.MoreObjects
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.util.Util
import java.util.stream.Stream

/**
 * A partition contains a set of SparTreeNodes, and this set should be reduced together. A level in
 * a spar-tree may generate multiple partitions.
 */
class Partition(private val nodes: ArrayList<AbstractSparTreeNode>) {

  init {
    assert(nodes.size > 0) { "A partition cannot be empty." }
  }

  val first: AbstractSparTreeNode
    get() = nodes[0]

  val last: AbstractSparTreeNode
    get() = nodes[nodes.size - 1]

  val isEmpty: Boolean
    get() = nodes.isEmpty()

  fun stream(): Stream<AbstractSparTreeNode> {
    return nodes.stream()
  }

  fun size(): Int {
    return nodes.size
  }

  fun getNode(index: Int): AbstractSparTreeNode {
    return nodes[index]
  }

  fun forEach(consumer: (AbstractSparTreeNode) -> Unit) {
    nodes.forEach(consumer)
  }

  fun removePermanentlyDeletedNodes() {
    Util.removeElementsFromList(nodes) { it.isPermanentlyDeleted }
  }

  fun split(): Array<Partition> {
    val nodes = nodes
    val size = nodes.size
    assert(size > 0)
    if (size <= 1) {
      return EMPTY_PARTITION_ARRAY
    }
    val halfIndex = (size + 1) / 2
    val first = Builder(halfIndex)
    for (i in 0 until halfIndex) {
      first.addNode(nodes[i])
    }
    val second = Builder(halfIndex)
    for (i in halfIndex until size) {
      second.addNode(nodes[i])
    }
    return arrayOf(first.build(), second.build())
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(Partition::class.java)
      .add(
        "nodes",
        nodes.asSequence().map { it.nodeId }.sorted().asSequence())
      .toString()
  }

  /** A builder to build a Partition.  */
  class Builder(capacity: Int) {
    private var nodes: ArrayList<AbstractSparTreeNode>? = ArrayList(capacity)
    fun addNode(node: AbstractSparTreeNode) {
      assert(nodes != null) { "This builder has been used" }
      nodes!!.add(node)
    }

    fun size(): Int {
      return nodes!!.size
    }

    /** This method builds a partition, and the current builder becomes invalid.  */
    fun build(): Partition {
      assert(nodes != null) { "The builder has been used." }
      val result = Partition(nodes!!)
      nodes = null
      return result
    }
  }

  companion object {
    val EMPTY_PARTITION_ARRAY = emptyArray<Partition>()
  }
}
