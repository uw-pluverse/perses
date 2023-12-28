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

/** The base class for partitioning a level of spar-tree nodes.  */
abstract class AbstractLevelPartitionPolicy {
  /**
   * Partition the given region into multiple partitions. The partitions are visited from first to
   * last. So when you implement a new policy, take care of the order also.
   */
  abstract fun partition(
    region: ReductionLevel,
    maxSizeOfPartition: Int,
  ): ImmutableList<Partition<AbstractSparTreeNode>>
}
