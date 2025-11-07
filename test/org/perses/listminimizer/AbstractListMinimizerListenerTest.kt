/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.listminimizer

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.listminimizer.AbstractListMinimizerListener.Companion.clusterIdsIntoRanges

@RunWith(JUnit4::class)
class AbstractListMinimizerListenerTest {
  // Helper function to easily create a list of ElementWrappers from integers
  private fun createElementsFromIndices(indices: List<Int>): List<ElementWrapper<*>> =
    indices.map {
      ElementWrapper(
        index = it,
        element = "",
        elementPayload = "",
      )
    }

  private fun createClustersFromInput(indices: List<Int>): String {
    val input = createElementsFromIndices(indices)
    return "[" + clusterIdsIntoRanges(input).joinToString(separator = ",") + "]"
  }

  @Test
  fun clusterIdsIntoRanges_withEmptyList_returnsEmptyArrayString() {
    val result = createClustersFromInput(emptyList())
    assertThat(result).isEqualTo("[]")
  }

  @Test
  fun clusterIdsIntoRanges_withSingleElement_returnsSingleElementInArray() {
    val result = createClustersFromInput(listOf(5))
    assertThat(result).isEqualTo("[5]")
  }

  @Test
  fun clusterIdsIntoRanges_withFullyConsecutiveList_returnsSingleRange() {
    val result = createClustersFromInput(listOf(1, 2, 3, 4, 5))
    assertThat(result).isEqualTo("[1-5]")
  }

  @Test
  fun clusterIdsIntoRanges_withNoConsecutiveNumbers_returnsAllSingleElements() {
    val result = createClustersFromInput(listOf(1, 3, 5, 7))
    assertThat(result).isEqualTo("[1,3,5,7]")
  }

  @Test
  fun clusterIdsIntoRanges_withMixedSinglesAndRanges_returnsCorrectString() {
    val result = createClustersFromInput(listOf(1, 2, 4, 6, 7, 8, 10))
    assertThat(result).isEqualTo("[1-2,4,6-8,10]")
  }

  @Test
  fun clusterIdsIntoRanges_withRangeAtTheBeginning_isHandledCorrectly() {
    val result = createClustersFromInput(listOf(1, 2, 3, 5, 7))
    assertThat(result).isEqualTo("[1-3,5,7]")
  }

  @Test
  fun clusterIdsIntoRanges_withRangeAtTheEnd_isHandledCorrectly() {
    val result = createClustersFromInput(listOf(1, 3, 5, 6, 7))
    assertThat(result).isEqualTo("[1,3,5-7]")
  }

  @Test
  fun clusterIdsIntoRanges_withSimpleTwoElementRange_isHandledCorrectly() {
    val result = createClustersFromInput(listOf(10, 11))
    assertThat(result).isEqualTo("[10-11]")
  }

  @Test
  fun clusterIdsIntoRanges_withNegativeAndZeroNumbers_isHandledCorrectly() {
    val result = createClustersFromInput(listOf(0, 2, 4, 5))
    assertThat(result).isEqualTo("[0,2,4-5]")
  }

  @Test
  fun clusterIdsIntoRanges_withSingleLongRange_isHandledCorrectly() {
    val result = createClustersFromInput(listOf(100, 101, 102, 103, 104, 105))
    assertThat(result).isEqualTo("[100-105]")
  }
}
