/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

package org.perses.reduction.partition;

import com.google.common.collect.ImmutableList;
import org.perses.reduction.ReductionLevel;

/** The simplest partitioning algorithm. */
public class SimpleLevelPartitionPolicy extends AbstractLevelPartitionPolicy {

  @Override
  public ImmutableList<Partition> partition(
      ReductionLevel reductionLevel, int maxNumOfNodesPerPartition) {
    assert maxNumOfNodesPerPartition > 0
        : "max number of nodes in per partition should be positive:" + maxNumOfNodesPerPartition;

    final int nodeCount = reductionLevel.getNodeCount();
    if (nodeCount == 0) {
      return ImmutableList.of();
    }
    final ImmutableList.Builder<Partition> builder = ImmutableList.builder();
    Partition.Builder partition = new Partition.Builder(maxNumOfNodesPerPartition);
    for (int i = nodeCount - 1; i >= 0; --i) {
      if (partition.size() == maxNumOfNodesPerPartition) {
        builder.add(partition.build());
        partition = new Partition.Builder(maxNumOfNodesPerPartition);
      }
      partition.addNode(reductionLevel.getNode(i));
    }
    if (partition.size() > 0) {
      builder.add(partition.build());
    }
    return builder.build();
  }
}
