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
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.delta.AbstractDeltaDebugger.Companion.computePartitionSize
import org.perses.delta.AbstractDeltaDebugger.Companion.partition
import org.perses.reduction.PropertyTestResult
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class AbstractDeltaDebuggerTest {

  companion object {
    val dummyPropertyTest = object : IPropertyTest<String, String> {
      override fun testProperty(
        currentBest: ImmutableList<String>,
        candidate: ImmutableList<String>
      ): AbstractPropertyTestResultWithPayload<String> {
        return PropertyTestResultWithPayload(PropertyTestResult.INTERESTING_RESULT, "dummy")
      }
    }

    val dummyHandler = { _: ImmutableList<String>, _: String -> }
  }

  class DummyDeltaDebugger(
    input: ImmutableList<String>
  ) :
    AbstractDeltaDebugger<String, String>(input, dummyPropertyTest, dummyHandler) {
    override fun reduce() {
      TODO("Not yet implemented")
    }
  }

  @Test
  fun test_throw_on_invalid_input() {
    val string = "s"
    Assert.assertThrows(Exception::class.java) {
      DummyDeltaDebugger(ImmutableList.of(string, string))
    }
  }

  @Test
  fun test_partitionSize() {
    assertThat(computePartitionSize(listSize = 2, numberOfPartitions = 2)).isEqualTo(1)
    assertThat(computePartitionSize(listSize = 4, numberOfPartitions = 2)).isEqualTo(2)
    assertThat(computePartitionSize(listSize = 4, numberOfPartitions = 3)).isEqualTo(1)
  }

  @Test
  fun test_partition_2_partitions() {
    partition("ab", 2).let {
      assertThat(it).containsExactly("a", "b").inOrder()
    }
    partition("abc", 2).let {
      assertThat(it).containsExactly("ab", "c").inOrder()
    }
    partition("abcd", 2).let {
      assertThat(it).containsExactly("ab", "cd").inOrder()
    }
    partition("abcdefgh", 2).let {
      assertThat(it).containsExactly("abcd", "efgh").inOrder()
    }
  }

  private fun partition(s: String, numOfPartitions: Int): ImmutableList<String> {
    val partitions = partition(s.asSequence().toImmutableList(), numOfPartitions)
    return partitions
      .asSequence()
      .map { it.toList() }
      .map { it.joinToString(separator = "") }
      .toImmutableList()
  }

  @Test
  fun test_partition_3_partitions() {
    partition("abc", 3).let {
      assertThat(it).containsExactly("a", "b", "c").inOrder()
    }
    partition("abcd", 3).let {
      assertThat(it).containsExactly("ab", "c", "d").inOrder()
    }
    partition("abcdefgh", 3).let {
      assertThat(it).containsExactly("abc", "def", "gh").inOrder()
    }
  }

  @Test
  fun test_partition_4_partitions() {
    partition("abcd", 4).let {
      assertThat(it).containsExactly("a", "b", "c", "d").inOrder()
    }
    partition("abcde", 4).let {
      assertThat(it).containsExactly("ab", "c", "d", "e").inOrder()
    }
    partition("abcdef", 4).let {
      assertThat(it).containsExactly("ab", "cd", "e", "f").inOrder()
    }
    partition("abcdefg", 4).let {
      assertThat(it).containsExactly("ab", "cd", "ef", "g").inOrder()
    }
  }
}
