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
package org.perses.delta

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class PartitionTest {

  val baseList = ImmutableList.of(0, 1, 2, 3)

  @Test
  fun test_partition_size_1() {
    Partition(baseList, startIndex = 0, endIndexExclusive = 1).let {
      assertThat(it.toList()).containsExactly(0).inOrder()
      assertThat(it.computeComplement()).containsExactly(1, 2, 3).inOrder()
    }

    Partition(baseList, startIndex = 1, endIndexExclusive = 2).let {
      assertThat(it.toList()).containsExactly(1).inOrder()
      assertThat(it.computeComplement()).containsExactly(0, 2, 3).inOrder()
    }

    Partition(baseList, startIndex = 2, endIndexExclusive = 3).let {
      assertThat(it.toList()).containsExactly(2).inOrder()
      assertThat(it.computeComplement()).containsExactly(0, 1, 3).inOrder()
    }

    Partition(baseList, startIndex = 3, endIndexExclusive = 4).let {
      assertThat(it.toList()).containsExactly(3).inOrder()
      assertThat(it.computeComplement()).containsExactly(0, 1, 2).inOrder()
    }
  }

  @Test
  fun test_partition_size_full() {
    Partition(baseList, startIndex = 0, endIndexExclusive = 4).let {
      assertThat(it.toList()).containsExactly(0, 1, 2, 3).inOrder()
      assertThat(it.computeComplement()).isEmpty()
    }
  }

  @Test
  fun test_partition_size_2() {
    Partition(baseList, startIndex = 0, endIndexExclusive = 2).let {
      assertThat(it.toList()).containsExactly(0, 1).inOrder()
      assertThat(it.computeComplement()).containsExactly(2, 3).inOrder()
    }
    Partition(baseList, startIndex = 1, endIndexExclusive = 3).let {
      assertThat(it.toList()).containsExactly(1, 2).inOrder()
      assertThat(it.computeComplement()).containsExactly(0, 3).inOrder()
    }
    Partition(baseList, startIndex = 2, endIndexExclusive = 4).let {
      assertThat(it.toList()).containsExactly(2, 3).inOrder()
      assertThat(it.computeComplement()).containsExactly(0, 1).inOrder()
    }
  }
}
