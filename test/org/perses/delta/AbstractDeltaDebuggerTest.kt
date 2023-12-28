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
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.delta.AbstractDeltaDebugger.OnBestUpdateHandler
import org.perses.delta.PristineDeltaDebugger.Companion.computePartitionSize
import org.perses.delta.PristineDeltaDebugger.Companion.countBasedPartition
import org.perses.reduction.PropertyTestResult
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class AbstractDeltaDebuggerTest {

  companion object {
    val dummyPropertyTest = IPropertyTester<String, String> {
      PropertyTestResultWithPayload(PropertyTestResult.INTERESTING_RESULT, "dummy")
    }

    val dummyHandler =
      OnBestUpdateHandler {
          _: ImmutableList<AbstractDeltaDebugger.ElementWrapper<String>>, _: String ->
      }
  }

  class DummyDeltaDebugger(
    input: ImmutableList<String>,
  ) : AbstractDeltaDebugger<String, String>(
    Arguments(
      needToTestEmpty = true,
      input,
      dummyPropertyTest,
      dummyHandler,
      descriptionPrefix = "",
    ),
  ) {

    override fun reduceNonEmptyInput() {
      TODO("Not yet implemented")
    }
  }

  @Test
  fun testThrowOnInvalidInput() {
    val string = "s"
    Assert.assertThrows(Exception::class.java) {
      DummyDeltaDebugger(ImmutableList.of(string, string))
    }
  }

  @Test
  fun testPartitionSize() {
    assertThat(computePartitionSize(listSize = 2, numberOfPartitions = 2)).isEqualTo(1)
    assertThat(computePartitionSize(listSize = 4, numberOfPartitions = 2)).isEqualTo(2)
    assertThat(computePartitionSize(listSize = 4, numberOfPartitions = 3)).isEqualTo(1)
  }

  @Test
  fun testToList() {
    val base = ImmutableList.of("a", "b", "c")

    PartitionList.Builder(base)
      .createPartition(0, 1)
      .createPartition(1, 3)
      .build().let { list ->
        list.partitions.first().let {
          assertThat(it.elements).containsExactly("a")
          assertThat(list.computeComplementFor(it).input).containsExactly("b", "c")
        }
      }

    PartitionList.Builder(base)
      .createPartition(0, 2)
      .createPartition(2, 3)
      .build().let { list ->
        list.partitions.first().let {
          assertThat(it.elements).containsExactly("a", "b")
          assertThat(list.computeComplementFor(it).input).containsExactly("c")
        }
      }

    PartitionList.Builder(base)
      .createPartition(0, 1)
      .createPartition(1, 2)
      .createPartition(2, 3)
      .build().let { list ->
        list.partitions[1].let {
          assertThat(it.elements).containsExactly("b")
          assertThat(list.computeComplementFor(it).input).containsExactly("a", "c")
        }
      }

    PartitionList.Builder(base)
      .createPartition(0, 2)
      .createPartition(2, 3)
      .build().let { list ->
        list.partitions.last().let {
          assertThat(it.elements).containsExactly("c")
          assertThat(list.computeComplementFor(it).input).containsExactly("a", "b")
        }
      }
  }

  @Test
  fun testPartition2Partitions() {
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
    val partitionsList = countBasedPartition(s.asSequence().toImmutableList(), numOfPartitions)
    return partitionsList
      .partitions
      .map { it.elements }
      .map { it.joinToString(separator = "") }
      .toImmutableList()
  }

  @Test
  fun testPartition3Partitions() {
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
  fun testPartition4Partitions() {
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

  @Test
  fun testConfigurationEqual() {
    ConfigurationBasedOnElementSystemIdentity(ImmutableList.of("a")).let {
      assertThat(it).isEqualTo(it)
    }
    ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(String())).let { a ->
      val b = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(String()))
      assertThat(a).isNotEqualTo(b)
    }
    val element = String()
    ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(element)).let { a ->
      val b = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(element))
      assertThat(a).isEqualTo(b)
    }
  }
}
