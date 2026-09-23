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
class WeightedDeferredRestartDeltaDebuggerTest : AbstractWeightedMinimizerTest() {
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
      WeightedDeferredRestartDeltaDebugger(it)
    }

  @Test
  fun testResultIsExactlyTheProperty() {
    test(property = listOf(), expected = listOf())
    test(property = listOf(1), expected = listOf(1))
    test(property = listOf(10), expected = listOf(10))
    test(property = input, expected = input)
    test(property = listOf(1, 10), expected = listOf(1, 10))
  }

  @Test
  fun testEverySurvivingBlockIsHalvedByWeight() {
    assertThat(test(property = listOf(2, 5, 10), expected = listOf(2, 5, 10)))
      .containsExactly(
        "",
        // [1 2 3 5 10] (weight 21) halves into [1 2 3 5] [10].
        "10",
        "1235",
        // [1 2 3 5] (weight 11) halves into [1 2 3] [5]; [10] cannot be split.
        "510",
        "12310",
        "1235",
        // [1 2 3] (weight 6) halves into [1 2] [3]; deleting 3 does not restart the sweep.
        "3510",
        "12510",
        "1210",
        "125",
        // [1 2] would halve only into singletons, so the single-element sweeps take over.
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
  fun testRandomWeightsAndPropertiesAreMinimizedExactly() {
    val random = Random(20260922)
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
