/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.listminimizer.localexhaust

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.listminimizer.AbstractListMinimizerTest
import org.perses.listminimizer.LocalExhaustMinimizerArguments

@RunWith(JUnit4::class)
class LocalExhaustWindowedMinimizerTest : AbstractListMinimizerTest<Int>() {
  private val input: ImmutableList<Int> = ImmutableList.of(1, 2, 3, 4, 5)

  private fun runTest(
    property: List<Int>,
    expected: List<Int>,
    windowSize: Int,
    input: ImmutableList<Int> = this.input,
  ): ImmutableList<String> =
    runMinimizerTest(input = input, property = property, expected = expected) { args ->
      LocalExhaustWindowedMinimizer(
        args.copy(localExhaustMinimizerArguments = LocalExhaustMinimizerArguments(windowSize)),
      )
    }

  @Test
  fun testEmptyPropertyDeletesEntireInput() {
    runTest(property = listOf(), expected = listOf(), windowSize = 3)
  }

  @Test
  fun testDeletesDisjointPairThatCoOccurInOneWindow() {
    // 2 and 4 are not adjacent, but window [2,3,4] contains both, so the pattern that
    // deletes exactly {2,4} is enumerated and succeeds.
    runTest(property = listOf(1, 3, 5), expected = listOf(1, 3, 5), windowSize = 3)
  }

  @Test
  fun testDeletesAdjacentPair() {
    runTest(property = listOf(1, 4, 5), expected = listOf(1, 4, 5), windowSize = 3)
  }

  @Test
  fun testNeverDeletesASingleElement() {
    // 3 is the only removable element. Because the minimizer only enumerates deletion
    // patterns of >= 2 elements per window, a lone element can never be removed, so the
    // input is returned unchanged.
    runTest(property = listOf(1, 2, 4, 5), expected = listOf(1, 2, 3, 4, 5), windowSize = 3)
  }

  @Test
  fun testElementStrandedByWindowSizeSurvives() {
    // With window 3, {3,4,5} are removed together; 2 is then stranded because the only
    // remaining window [1,2] would have to delete the still-needed element 1.
    runTest(property = listOf(1), expected = listOf(1, 2), windowSize = 3)
  }

  @Test
  fun testLargerWindowRemovesTheStrandedElement() {
    // Window 5 fits {2,3,4,5} into a single window, so all of them are removed at once.
    runTest(property = listOf(1), expected = listOf(1), windowSize = 5)
  }

  @Test
  fun testMissingLocalExhaustArgumentsFailsFast() {
    val exception =
      Assert.assertThrows(IllegalStateException::class.java) {
        runMinimizerTest(input = input, property = listOf(1), expected = listOf(1)) { args ->
          LocalExhaustWindowedMinimizer(args)
        }
      }
    assertThat(exception).hasMessageThat().contains("must be non-null")
  }
}
