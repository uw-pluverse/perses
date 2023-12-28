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
package org.perses.delta

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.delta.PristineDeltaDebugger.Companion.countBasedPartition

@RunWith(JUnit4::class)
class PartitionTest {

  private val baseList: ImmutableList<Int> = ImmutableList.of(0, 1, 2, 3)

  @Test
  fun testEquivalence() {
    run {
      val list = countBasedPartition(baseList, numOfPartitions = 1)
      val other = countBasedPartition(baseList, numOfPartitions = 2)
      assertThat(list.isEquivalentTo(other)).isFalse()
    }
    run {
      val list = countBasedPartition(baseList, numOfPartitions = 2)
      val other = countBasedPartition(baseList, numOfPartitions = 2)
      assertThat(list.isEquivalentTo(other)).isTrue()
    }
    run {
      val list = countBasedPartition(ImmutableList.of(0, 1, 2, 3), numOfPartitions = 2)
      val other = countBasedPartition(baseList, numOfPartitions = 2)
      assertThat(list.isEquivalentTo(other)).isTrue()
    }
  }

  @Test
  fun testPartitionSize1() {
    val listBuilder = PartitionList.Builder<Int>(baseList)
    listBuilder.createPartition(0, 1)
    listBuilder.createPartition(1, 2)
    listBuilder.createPartition(2, 3)
    listBuilder.createPartition(3, 4)
    val partitionList = listBuilder.build()
    partitionList.partitions[0].let {
      assertThat(it.elements).containsExactly(0).inOrder()
      assertThat(partitionList.computeComplementFor(it).input).containsExactly(1, 2, 3).inOrder()
    }

    partitionList.partitions[1].let {
      assertThat(it.elements).containsExactly(1).inOrder()
      assertThat(partitionList.computeComplementFor(it).input).containsExactly(0, 2, 3).inOrder()
    }

    partitionList.partitions[2].let {
      assertThat(it.elements).containsExactly(2).inOrder()
      assertThat(partitionList.computeComplementFor(it).input).containsExactly(0, 1, 3).inOrder()
    }

    partitionList.partitions[3].let {
      assertThat(it.elements).containsExactly(3).inOrder()
      assertThat(partitionList.computeComplementFor(it).input).containsExactly(0, 1, 2).inOrder()
    }
  }

  @Test
  fun testPartitionSizeFull() {
    val listBuilder = PartitionList.Builder<Int>(baseList)
    listBuilder.createPartition(0, 4)
    val list = listBuilder.build()
    list.partitions.single().let {
      assertThat(it.elements).containsExactly(0, 1, 2, 3).inOrder()
      assertThat(list.computeComplementFor(it).input).isEmpty()
    }
  }

  @Test
  fun testPartitionSize2() {
    val listBuilder = PartitionList.Builder(baseList)
    listBuilder.createPartition(0, 2)
    PartitionList.Builder(baseList)
      .createPartition(0, 2)
      .createPartition(2, 4)
      .build()
      .let { list ->
        list.partitions.first().let {
          assertThat(it.elements).containsExactly(0, 1).inOrder()
          assertThat(list.computeComplementFor(it).input).containsExactly(2, 3).inOrder()
        }
      }

    PartitionList.Builder(baseList)
      .createPartition(0, 1)
      .createPartition(1, 3)
      .createPartition(3, 4)
      .build().let { list ->
        list.partitions[1].let {
          assertThat(it.elements).containsExactly(1, 2).inOrder()
          assertThat(list.computeComplementFor(it).input).containsExactly(0, 3).inOrder()
        }
      }

    PartitionList.Builder(baseList)
      .createPartition(0, 2)
      .createPartition(2, 4)
      .build().let { list ->
        list.partitions.last().let {
          assertThat(it.elements).containsExactly(2, 3).inOrder()
          assertThat(list.computeComplementFor(it).input).containsExactly(0, 1).inOrder()
        }
      }
  }
}
