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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.reduction.ReductionLevel
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import java.nio.file.Paths

/** Test for [SimpleLevelPartitionPolicy]  */
@RunWith(JUnit4::class)
class SimpleLevelPartitionPolicyTest {
  private val policy: SimpleLevelPartitionPolicy = SimpleLevelPartitionPolicy()
  private val tree: SparTree = TestUtility.createSparTreeFromFile(
    Paths.get("test_data/misc/t1.c"),
  )

  @Test
  fun testEmptyReductionNodeRegion() {
    val region = ReductionLevel(1)
    assertThat(region.level).isEqualTo(1)
    run {
      val result = policy.partition(region, 1)
      assertThat(result).hasSize(0)
    }
    run {
      val result = policy.partition(region, 2)
      assertThat(result).hasSize(0)
    }
  }

  @Test
  fun testRegionWithOneNode() {
    val region = ReductionLevel(1)
    val node: AbstractSparTreeNode = tree.root
    region.addNode(node)
    run {
      val result = policy.partition(region, 1)
      assertThat(result).hasSize(1)
      val partition = result[0]
      assertThat(partition.size()).isEqualTo(1)
      assertThat(partition.first).isEqualTo(node)
      assertThat(partition.first).isEqualTo(partition.getNode(0))
    }
    run {
      val result = policy.partition(region, 2)
      assertThat(result).hasSize(1)
      val partition = result[0]
      assertThat(partition.size()).isEqualTo(1)
      assertThat(partition.first).isEqualTo(partition.getNode(0))
      assertThat(partition.first).isEqualTo(node)
    }
  }

  @Test
  fun regionWithTwoNodes() {
    val region = ReductionLevel(1)
    val node1: AbstractSparTreeNode = tree.root
    val node2: AbstractSparTreeNode = tree.root.getChild(0)
    region.addNode(node1)
    region.addNode(node2)
    assertThat(region.nodeCount).isEqualTo(2)
    assertThat(region.getNode(0)).isEqualTo(node1)
    assertThat(region.getNode(1)).isEqualTo(node2)
    run {
      val result = policy.partition(region, 1)
      assertThat(result).hasSize(2)
      assertThat(result[0].first).isEqualTo(node2)
      assertThat(result[1].first).isEqualTo(node1)
    }
    run {
      val result = policy.partition(region, 2)
      assertThat(result).hasSize(1)
      val p = result[0]
      assertThat(p.size()).isEqualTo(2)
      assertThat(p.first).isEqualTo(node2)
      assertThat(p.last).isEqualTo(node1)
    }
  }
}
