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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.transformToImmutableList

@RunWith(JUnit4::class)
class AdaptiveGainDrivenListMinimizerTest : AbstractWeightedMinimizerTest() {
  @Test
  fun testReductionSmall() {
    testAdaptive(property = listOf(2), expected = listOf(2))
    testAdaptive(property = listOf(1, 10), expected = listOf(1, 10))
    testAdaptive(property = listOf(1, 2, 3, 5, 10), expected = listOf(1, 2, 3, 5, 10))
  }

  @Test
  fun testEmptyResult() {
    testAdaptive(property = listOf(), expected = listOf())
  }

  @Test
  fun testVaryingAnticipatedCount() {
    testAdaptive(property = listOf(5), expected = listOf(5), anticipatedTokenCountInResult = 1)
    testAdaptive(
      property = listOf(1, 2, 3),
      expected = listOf(1, 2, 3),
      anticipatedTokenCountInResult = 3,
    )
  }

  private fun testAdaptive(
    property: List<Int>,
    expected: List<Int>,
    anticipatedTokenCountInResult: Int = 1,
  ): ImmutableList<String> {
    var currentBestElements: ImmutableList<Int> = input

    return runMinimizerTest(
      input = input,
      property = property,
      expected = expected,
      weightProvider = { it },
      onBestUpdate = { newBest, _ ->
        currentBestElements = newBest.transformToImmutableList { it.element }
      },
    ) { args ->
      AdaptiveGainDrivenListMinimizer(
        args.copy(
          adaptiveGainDrivenMinimizerArguments =
            AdaptiveGainDrivenMinimizerArguments(
              getCurrentTotalTokenCount = { currentBestElements.size },
              anticipatedTokenCountInResult = anticipatedTokenCountInResult,
            ),
        ),
      )
    }
  }
}
