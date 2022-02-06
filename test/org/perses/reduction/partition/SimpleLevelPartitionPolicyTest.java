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

package org.perses.reduction.partition;

import static com.google.common.truth.Truth.assertThat;
import static org.junit.Assert.assertEquals;

import java.io.IOException;
import java.nio.file.Paths;
import java.util.List;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.reduction.ReductionLevel;
import org.perses.spartree.AbstractSparTreeNode;
import org.perses.spartree.SparTree;

/** Test for {@link SimpleLevelPartitionPolicy} */
@RunWith(JUnit4.class)
public class SimpleLevelPartitionPolicyTest {

  private final SimpleLevelPartitionPolicy policy = new SimpleLevelPartitionPolicy();
  private final SparTree tree =
      TestUtility.createSparTreeFromFile(Paths.get("test_data/misc/t1.c"));

  public SimpleLevelPartitionPolicyTest() throws IOException {}

  @Test
  public void testEmptyReductionNodeRegion() {
    ReductionLevel region = new ReductionLevel(1);
    assertThat(region.getLevel()).isEqualTo(1);
    {
      List<Partition> result = policy.partition(region, 1);
      assertThat(result).hasSize(0);
    }
    {
      List<Partition> result = policy.partition(region, 2);
      assertThat(result).hasSize(0);
    }
  }

  @Test
  public void testRegionWithOneNode() {
    ReductionLevel region = new ReductionLevel(1);
    final AbstractSparTreeNode node = tree.getRoot();
    region.addNode(node);

    {
      List<Partition> result = policy.partition(region, 1);
      assertThat(result).hasSize(1);
      final Partition partition = result.get(0);
      assertThat(partition.size()).isEqualTo(1);
      assertThat(partition.getFirst()).isEqualTo(node);
      assertThat(partition.getFirst()).isEqualTo(partition.getNode(0));
    }
    {
      List<Partition> result = policy.partition(region, 2);
      assertThat(result).hasSize(1);
      final Partition partition = result.get(0);
      assertThat(partition.size()).isEqualTo(1);
      assertThat(partition.getFirst()).isEqualTo(partition.getNode(0));
      assertThat(partition.getFirst()).isEqualTo(node);
    }
  }

  @Test
  public void regionWithTwoNodes() {
    ReductionLevel region = new ReductionLevel(1);
    final AbstractSparTreeNode node1 = tree.getRoot();
    final AbstractSparTreeNode node2 = tree.getRoot().getChild(0);

    region.addNode(node1);
    region.addNode(node2);

    assertThat(region.getNodeCount()).isEqualTo(2);
    assertThat(region.getNode(0)).isEqualTo(node1);
    assertThat(region.getNode(1)).isEqualTo(node2);
    {
      List<Partition> result = policy.partition(region, 1);
      assertThat(result).hasSize(2);
      assertEquals(2, result.size());
      assertEquals(node2, result.get(0).getFirst());
      assertEquals(node1, result.get(1).getFirst());
    }
    {
      List<Partition> result = policy.partition(region, 2);
      assertEquals(1, result.size());
      final Partition p = result.get(0);
      assertEquals(2, p.size());
      assertEquals(node2, p.getFirst());
      assertEquals(node1, p.getLast());
    }
  }
}
