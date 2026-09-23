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
class OneMinimalCounterBasedDeltaDebuggerTest : AbstractListMinimizerTest<String>() {
  private val input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h")

  private class Run(
    val result: List<String>,
    val testHistory: List<List<String>>,
  )

  private fun run(
    input: List<String>,
    isInteresting: (List<String>) -> Boolean,
    minimizerFactory: (
      ListMinimizerArguments<String, String>,
    ) -> AbstractListMinimizer<String, String>,
  ): Run {
    val testHistory = mutableListOf<List<String>>()
    val minimizer =
      minimizerFactory(
        ListMinimizerArguments(
          needToTestEmpty = true,
          input = ImmutableList.copyOf(input),
          isElementDeletedElsewhere = { false },
          propertyTester = { configuration ->
            val candidate = configuration.getCandidateOrFail()
            testHistory.add(candidate)
            ImmediatePropertyTestHandle(
              if (isInteresting(candidate)) {
                CandidateOutcome.Interesting("", INTERESTING)
              } else {
                CandidateOutcome.Uninteresting.Rejected(NON_INTERESTING)
              },
            )
          },
          onBestUpdateHandler = dummyHandler,
          descriptionPrefix = "prefix",
        ),
      )
    return Run(result = minimizer.reduce(), testHistory = testHistory)
  }

  /**
   * Interesting iff the candidate contains every element of [required] and, for each (y, x) in
   * [implications], contains x whenever it contains y. Unlike a containment property this is not
   * monotone: x cannot be deleted alone while y is present, but can once y is gone.
   */
  private fun impliedContainment(
    required: List<String>,
    implications: List<Pair<String, String>>,
  ): (List<String>) -> Boolean =
    { candidate ->
      candidate.containsAll(required) &&
        implications.all { (y, x) -> y !in candidate || x in candidate }
    }

  private fun assertOneMinimal(
    result: List<String>,
    isInteresting: (List<String>) -> Boolean,
  ) {
    assertThat(isInteresting(result)).isTrue()
    for (element in result) {
      assertThat(isInteresting(result - element)).isFalse()
    }
  }

  @Test
  fun testRetestsAnElementFoundNecessaryBeforeALaterDeletion() {
    val input = listOf("x", "1", "2", "3", "4")
    val isInteresting = { candidate: List<String> ->
      val digits = candidate.filter { it != "x" }.map { it.toInt() }
      "x" in candidate && digits == (1..digits.size).toList()
    }
    assertThat(run(input, isInteresting) { CounterBasedDeltaDebugger(it) }.result)
      .containsExactly("x", "1")
      .inOrder()
    val run = run(input, isInteresting) { OneMinimalCounterBasedDeltaDebugger(it) }
    assertThat(run.result).containsExactly("x")
    // CDD found x and 1 necessary against [x 1 2] and then deleted 2, so both are retested against
    // [x 1]: x is still necessary, 1 no longer is.
    assertThat(run.testHistory.takeLast(2))
      .containsExactly(listOf("1"), listOf("x"))
      .inOrder()
  }

  @Test
  fun testSearchPerformsExactlyTheTestsOfCdd() {
    val random = Random(20260923)
    repeat(200) {
      val isInteresting =
        impliedContainment(
          required = input.filter { random.nextInt(4) == 0 },
          implications = List(random.nextInt(4)) { input.random(random) to input.random(random) },
        )
      val cdd = run(input, isInteresting) { CounterBasedDeltaDebugger(it) }
      val oneMinimal = run(input, isInteresting) { OneMinimalCounterBasedDeltaDebugger(it) }
      assertThat(oneMinimal.testHistory.take(cdd.testHistory.size))
        .containsExactlyElementsIn(cdd.testHistory)
        .inOrder()
    }
  }

  @Test
  fun testResultIsOneMinimalUnderNonMonotoneProperties() {
    val random = Random(20260923)
    repeat(500) {
      val isInteresting =
        impliedContainment(
          required = input.filter { random.nextInt(4) == 0 },
          implications = List(random.nextInt(6)) { input.random(random) to input.random(random) },
        )
      val run = run(input, isInteresting) { OneMinimalCounterBasedDeltaDebugger(it) }
      assertOneMinimal(run.result, isInteresting)
    }
  }

  @Test
  fun testRandomContainmentPropertiesAreMinimizedExactly() {
    val random = Random(20260923)
    repeat(200) {
      val property = input.filter { random.nextInt(4) == 0 }
      runMinimizerTest(input = input, property = property, expected = property) {
        OneMinimalCounterBasedDeltaDebugger(it)
      }
    }
  }
}
