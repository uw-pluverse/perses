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

@RunWith(JUnit4::class)
class AbstractProbabilisticDeltaDebuggerTest : AbstractListMinimizerTest<String>() {
  val input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h")

  private fun checkOrder(list: List<String>?): Boolean {
    var currVal = 0
    for (str in list!!) {
      for (c in str) {
        if (currVal > c.code) {
          return false
        }
        currVal = c.code
      }
      currVal = 0
    }
    return true
  }

  @Test
  fun testPristineProbabilisticDeltaDebuggerA() {
    test(property = listOf("a"), expected = listOf("a"), true)
    test(
      property = listOf("a", "b", "c", "d", "e"),
      expected = listOf("a", "b", "c", "d", "e"),
      true,
    )
    test(property = listOf("c", "h"), expected = listOf("c", "h"), true).let { testHistory ->
      assertThat(testHistory)
        .containsExactly(
          "",
          "efgh",
          "abcd",
          "cdefgh",
          "efgh",
          "cdgh",
          "cd",
          "dgh",
          "cgh",
          "ch",
          "c",
        ).inOrder()
    }

    test(property = listOf("c", "h"), expected = listOf("c", "h"), true).let { delHistory ->
      assert(checkOrder(delHistory))
    }
  }

  @Test
  fun testPristineProbabilisticDeltaDebuggerB() {
    test(property = listOf("f"), expected = listOf("f"), true)
  }

  @Test
  fun testPristineProbabilisticDeltaDebuggerC() {
    test(property = listOf(), expected = listOf(), true)
  }

  @Test
  fun testCounterBasedDeltaDebuggerA() {
    test(property = listOf("a"), expected = listOf("a"), false)
    test(
      property = listOf("a", "b", "c", "d", "e"),
      expected = listOf("a", "b", "c", "d", "e"),
      false,
    )
    test(property = listOf("c", "h"), expected = listOf("c", "h"), false).let { testHistory ->
      assertThat(testHistory)
        .containsExactly(
          "",
          "efgh",
          "abcd",
          "cdefgh",
          "efgh",
          "cdgh",
          "cd",
          "dgh",
          "cgh",
          "ch",
          "c",
        ).inOrder()
    }

    test(property = listOf("c", "h"), expected = listOf("c", "h"), false).let { delHistory ->
      assert(checkOrder(delHistory))
    }
  }

  @Test
  fun testCounterBasedDeltaDebuggerB() {
    test(property = listOf("f"), expected = listOf("f"), false)
  }

  @Test
  fun testCounterBasedDeltaDebuggerC() {
    test(property = listOf(), expected = listOf(), false)
  }

  @Test
  fun testCounterBasedDeltaDebuggerD() {
    test(
      property = listOf("c", "d", "h"),
      expected = listOf("c", "d", "h"),
      false,
    ).let { testHistory ->
      assertThat(testHistory)
        .containsExactly(
          "",
          "efgh",
          "abcd",
          "cdefgh",
          "efgh",
          "cdgh",
          "cd",
          "dgh",
          "cgh",
          "cdh",
          "cd",
        ).inOrder()
    }
  }

  @Test
  fun testCounterBasedDeltaDebuggerE() {
    test(
      property = listOf("a", "c", "e", "f"),
      expected = listOf("a", "c", "e", "f"),
      false,
    ).let { testHistory ->
      assertThat(testHistory)
        .containsExactly(
          "",
          "efgh",
          "abcd",
          "cdefgh",
          "abefgh",
          "abcdgh",
          "abcdef",
          "bcdef",
          "acdef",
          "adef",
          "acef",
          "acf",
          "ace",
        ).inOrder()
    }
  }

  private fun test(
    property: List<String>,
    expected: List<String>,
    isProbabilisticDeltaDebugger: Boolean,
  ): List<String> {
    val delHistory = mutableListOf<String>()

    return runMinimizerTest(
      input = input,
      property = property,
      expected = expected,
    ) { args ->
      val originalPropertyTester = args.propertyTester
      val wrapperPropertyTester =
        IPropertyTester<String, String> { configuration ->
          val result = originalPropertyTester.testProperty(configuration)
          delHistory.add(configuration.deletedElements.joinToString(separator = ""))
          result
        }

      if (isProbabilisticDeltaDebugger) {
        PristineProbabilisticDeltaDebugger<String, String>(
          args.copy(propertyTester = wrapperPropertyTester),
        )
      } else {
        CounterBasedDeltaDebugger<String, String>(args.copy(propertyTester = wrapperPropertyTester))
      }
    }
  }
}
