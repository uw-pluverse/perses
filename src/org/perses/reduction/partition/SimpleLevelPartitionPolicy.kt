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
package org.perses.reduction.partition

import com.google.common.collect.ImmutableList
import org.perses.delta.xfs.Partition
import org.perses.reduction.ReductionLevel
import org.perses.spartree.AbstractSparTreeNode

/** The simplest partitioning algorithm.  */
class SimpleLevelPartitionPolicy : AbstractLevelPartitionPolicy() {
  override fun partition(
    region: ReductionLevel,
    maxSizeOfPartition: Int,
  ): ImmutableList<Partition<AbstractSparTreeNode>> {
    check(maxSizeOfPartition > 0) {
      "max number of nodes in per partition should be positive:$maxSizeOfPartition"
    }
    val nodeCount = region.nodeCount
    if (nodeCount == 0) {
      return ImmutableList.of()
    }
    val builder = ImmutableList.builder<Partition<AbstractSparTreeNode>>()
    var partition = Partition.Builder<AbstractSparTreeNode>(maxSizeOfPartition)
    for (i in nodeCount - 1 downTo 0) {
      if (partition.size == maxSizeOfPartition) {
        builder.add(partition.build())
        partition = Partition.Builder(maxSizeOfPartition)
      }
      partition.addNode(region.getNode(i))
    }
    if (partition.size > 0) {
      builder.add(partition.build())
    }
    return builder.build()
  }
}
