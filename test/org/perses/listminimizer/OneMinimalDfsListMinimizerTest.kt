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
import org.perses.listminimizer.xfs.OneMinimalDfsListMinimizer
import org.perses.listminimizer.xfs.UnweightedDfsListMinimizer
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict.Companion.INTERESTING
import org.perses.reduction.TestScriptVerdict.Companion.NON_INTERESTING
import kotlin.random.Random

@RunWith(JUnit4::class)
class OneMinimalDfsListMinimizerTest : AbstractListMinimizerTest<String>() {
  private val input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h")

  private fun minimize(
    input: List<String>,
    isInteresting: (List<String>) -> Boolean,
    minimizerFactory: (
      ListMinimizerArguments<String, String>,
    ) -> AbstractListMinimizer<String, String>,
  ): List<String> =
    minimizerFactory(
      ListMinimizerArguments(
        needToTestEmpty = true,
        input = ImmutableList.copyOf(input),
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

  /**
   * Interesting iff the candidate contains every element of [required] and, for each (y, x) in
   * [implications], contains x whenever it contains y: x cannot be deleted while y is present, but
   * can once y is gone.
   */
  private fun impliedContainment(
    required: List<String>,
    implications: List<Pair<String, String>>,
  ): (List<String>) -> Boolean =
    { candidate ->
      candidate.containsAll(required) &&
        implications.all { (y, x) -> y !in candidate || x in candidate }
    }

  @Test
  fun testRetriesAnElementThatALaterDeletionMadeRemovable() {
    val input = listOf("a", "b", "c", "d")
    val isInteresting =
      impliedContainment(required = listOf("a"), implications = listOf("b" to "d"))
    // DFS tries d alone while b is still present, then deletes b, and never retries d.
    assertThat(minimize(input, isInteresting) { UnweightedDfsListMinimizer(it) })
      .containsExactly("a", "d")
      .inOrder()
    assertThat(minimize(input, isInteresting) { OneMinimalDfsListMinimizer(it) })
      .containsExactly("a")
  }

  @Test
  fun testResultIsOneMinimalUnderNonMonotoneProperties() {
    val random = Random(20260924)
    repeat(500) {
      val isInteresting =
        impliedContainment(
          required = input.filter { random.nextInt(4) == 0 },
          implications = List(random.nextInt(6)) { input.random(random) to input.random(random) },
        )
      val result = minimize(input, isInteresting) { OneMinimalDfsListMinimizer(it) }
      assertThat(isInteresting(result)).isTrue()
      for (element in result) {
        assertThat(isInteresting(result - element)).isFalse()
      }
    }
  }

  @Test
  fun testRandomContainmentPropertiesAreMinimizedExactly() {
    val random = Random(20260924)
    repeat(200) {
      val property = input.filter { random.nextInt(4) == 0 }
      runMinimizerTest(input = input, property = property, expected = property) {
        OneMinimalDfsListMinimizer(it)
      }
    }
  }
}
