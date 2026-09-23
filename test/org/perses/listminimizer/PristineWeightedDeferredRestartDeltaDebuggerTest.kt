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
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import kotlin.random.Random

@RunWith(JUnit4::class)
class PristineWeightedDeferredRestartDeltaDebuggerTest : AbstractWeightedMinimizerTest() {
  private fun test(
    property: List<Int>,
    expected: List<Int>,
    input: ImmutableList<Int> = this.input,
    weightProvider: IWeightProvider<Int> = IWeightProvider { it },
  ): ImmutableList<String> =
    runMinimizerTest(
      input = input,
      property = property,
      expected = expected,
      weightProvider = weightProvider,
    ) {
      PristineWeightedDeferredRestartDeltaDebugger(it)
    }

  @Test
  fun testBlocksAreFilledUpToTheGranularity() {
    assertThat(test(property = listOf(2, 5, 10), expected = listOf(2, 5, 10)))
      .containsExactly(
        "",
        // W = 10 of total weight 21: blocks [1 2 3] [5] [10].
        "510",
        "12310",
        "1235",
        // W = 5: blocks [1 2] [3] [5] [10]; deleting 3 does not restart the sweep.
        "3510",
        "12510",
        "1210",
        "125",
        // W = 2 would cut only singletons, so the single-element sweeps take over.
        "2510",
        "510",
        "210",
        "25",
        "510",
        "210",
        "25",
      ).inOrder()
  }

  @Test
  fun testUnitWeightsPerformExactlyTheTestsOfPristineDrdd() {
    val random = Random(20260923)
    repeat(100) {
      val input = ImmutableList.copyOf((1..random.nextInt(1, 40)).toList())
      val property = input.filter { random.nextInt(5) == 0 }
      val weightedHistory =
        test(property = property, expected = property, input = input, weightProvider = { 1 })
      val unweightedHistory =
        runMinimizerTest(input = input, property = property, expected = property) {
          PristineDeferredRestartDeltaDebugger(it)
        }
      assertThat(weightedHistory).containsExactlyElementsIn(unweightedHistory).inOrder()
    }
  }

  @Test
  fun testRandomWeightsAndPropertiesAreMinimizedExactly() {
    val random = Random(20260923)
    repeat(100) {
      val input = ImmutableList.copyOf((1..random.nextInt(1, 40)).toList())
      val weights = input.associateWith { random.nextInt(1, 20) }
      val property = input.filter { random.nextInt(5) == 0 }
      test(
        property = property,
        expected = property,
        input = input,
        weightProvider = { weights.getValue(it) },
      )
    }
  }
}
