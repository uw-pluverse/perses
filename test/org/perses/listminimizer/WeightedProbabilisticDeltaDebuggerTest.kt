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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.PropertyTestResult.Companion.INTERESTING_RESULT
import org.perses.reduction.PropertyTestResult.Companion.NON_INTERESTING_RESULT

@RunWith(JUnit4::class)
class WeightedProbabilisticDeltaDebuggerTest {

  private val input = ImmutableList.of(1, 2, 3, 5, 10)

  @Test
  fun testEmpty() {
    testWProbDD(property = listOf(), expected = listOf())
    testWProbDD(property = listOf(1, 2, 3, 5, 10), expected = listOf(1, 2, 3, 5, 10))
    testWProbDD(property = listOf(1), expected = listOf(1))
    testWProbDD(property = listOf(1, 5, 10), expected = listOf(1, 5, 10)).let { testHistory ->
      assertThat(testHistory).containsExactly(
        "",
        "123",
        "1235",
        "1210",
        "1510",
        "110",
        "510",
      ).inOrder()
    }
  }

  private fun testWProbDD(
    property: List<Int>,
    expected: List<Int>,
  ): ImmutableList<String> {
    val testHistory = mutableListOf<String>()
    val delHistory = mutableListOf<String>()

    val propertyTest =
      IPropertyTester<Int, String> { configuration ->
        val candidate = configuration.candidate
        val deleted = configuration.deleted
        testHistory.add(candidate.joinToString(""))
        delHistory.add(deleted.joinToString(""))
        if (candidate.containsAll(property)) {
          PropertyTestResultWithPayload(INTERESTING_RESULT, "")
        } else {
          PropertyTestResultWithPayload(NON_INTERESTING_RESULT, "")
        }
      }

    val debugger = WeightedProbabilisticDeltaDebugger(
      AbstractListInputMinimizer.Arguments(
        needToTestEmpty = true,
        input = input,
        propertyTester = propertyTest,
        onBestUpdateHandler = { _, _ -> },
        descriptionPrefix = "prefix",
        weightProvider = { it },
      ),
      terminationThreshold = 1.0,
      initialProbability = 0.25,
    )

    val result = debugger.reduce()
    assertThat(result).isEqualTo(expected)
    return ImmutableList.copyOf(testHistory)
  }
}
