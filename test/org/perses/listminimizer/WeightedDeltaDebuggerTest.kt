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
import org.perses.reduction.PropertyTestResult

@RunWith(JUnit4::class)
class WeightedDeltaDebuggerTest {

  val input: ImmutableList<Int> = ImmutableList.of(1, 2, 3, 5, 10)

  val dummyHandler = { _:
  ImmutableList<AbstractListInputMinimizer.ElementWrapper<Int>>,
      _: String,
    ->
  }

  @Test
  fun testA() {
    testWdd(property = listOf(), expected = listOf())
    testWdd(property = listOf(1, 2, 3, 5, 10), expected = listOf(1, 2, 3, 5, 10))
    testWdd(property = listOf(1), expected = listOf(1))
    testWdd(property = listOf(3), expected = listOf(3))
    testWdd(property = listOf(2, 5, 10), expected = listOf(2, 5, 10)).let { testHistory ->
      assertThat(testHistory).containsExactly(
        "",
        "1235", "10", "10", "1235",
        "123", "5", "510", "12310",
        "12", "3", "3510", "12510", "510",
        "1", "2", "2510", "510",
        "510", "210", "25",
      ).inOrder()
    }
  }

  @Test
  fun testCache() {
    testWdd(property = listOf(), expected = listOf())
    testWdd(
      property = listOf(1, 2, 3, 5, 10),
      expected = listOf(1, 2, 3, 5, 10),
      enableCache = true,
    )
    testWdd(property = listOf(2), expected = listOf(2))
    testWdd(
      property = listOf(2, 5, 10),
      expected = listOf(2, 5, 10),
      enableCache = true,
    ).let { testHistory ->
      assertThat(testHistory).containsExactly(
        "",
        "1235", "10",
        "123", "5", "510", "12310",
        "12", "3", "3510", "12510",
        "1", "2", "2510",
        "210", "25",
      ).inOrder()
    }
  }

  private fun testWdd(
    property: List<Int>,
    expected: List<Int>,
    enableCache: Boolean = false,
  ): ImmutableList<String> {
    val testHistory = ArrayList<String>()

    val propertyTest =
      IPropertyTester<Int, String> { configuration ->
        val candidate = configuration.candidate
        testHistory.add(candidate.joinToString(""))
        if (candidate.containsAll(property)) {
          PropertyTestResultWithPayload(PropertyTestResult.INTERESTING_RESULT, "")
        } else {
          PropertyTestResultWithPayload(PropertyTestResult.NON_INTERESTING_RESULT, "")
        }
      }

    val debugger = WeightedDeltaDebugger(
      AbstractListInputMinimizer.Arguments(
        needToTestEmpty = true,
        input = input,
        propertyTester = propertyTest,
        onBestUpdateHandler = dummyHandler,
        descriptionPrefix = "prefix",
        weightProvider = { it },
      ),
      enableCache = enableCache,
    )

    val result = debugger.reduce()
    assertThat(result).isEqualTo(expected)
    return ImmutableList.copyOf(testHistory)
  }
}
