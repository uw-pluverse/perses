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
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict.Companion.INTERESTING
import org.perses.reduction.TestScriptVerdict.Companion.NON_INTERESTING
import kotlin.random.Random

@RunWith(JUnit4::class)
class LithiumMinimizerTest : AbstractListMinimizerTest<String>() {
  private val input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h")

  @Test
  fun testLargestPowerOfTwoSmallerThan() {
    assertThat((1..9).map { LithiumMinimizer.largestPowerOfTwoSmallerThan(it) })
      .containsExactly(1, 1, 2, 2, 4, 4, 4, 4, 8)
      .inOrder()
  }

  @Test
  fun testRandomContainmentPropertiesAreMinimizedExactly() {
    val random = Random(20260923)
    repeat(200) {
      val property = input.filter { random.nextInt(4) == 0 }
      runMinimizerTest(input = input, property = property, expected = property) {
        LithiumMinimizer(it)
      }
    }
  }

  @Test
  fun testResultIsOneMinimalUnderNonMonotoneProperties() {
    val random = Random(20260923)
    repeat(500) {
      val required = input.filter { random.nextInt(4) == 0 }
      val implications = List(random.nextInt(6)) { input.random(random) to input.random(random) }
      // x cannot be deleted while y is present, but can once y is gone.
      val isInteresting = { candidate: List<String> ->
        candidate.containsAll(required) &&
          implications.all { (y, x) -> y !in candidate || x in candidate }
      }
      val result =
        LithiumMinimizer(
          ListMinimizerArguments(
            needToTestEmpty = true,
            input = input,
            isElementDeletedElsewhere = { false },
            propertyTester = { configuration ->
              ImmediatePropertyTestHandle(
                if (isInteresting(configuration.getCandidateOrFail())) {
                  CandidateOutcome.Interesting("", INTERESTING)
                } else {
                  CandidateOutcome.Uninteresting.Rejected(NON_INTERESTING)
                },
              )
            },
            onBestUpdateHandler = dummyHandler,
            descriptionPrefix = "prefix",
          ),
        ).reduce()
      assertThat(isInteresting(result)).isTrue()
      for (element in result) {
        assertThat(isInteresting(result - element)).isFalse()
      }
    }
  }
}
