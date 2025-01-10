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
class AbstractProbabilisticDeltaDebuggerTest {
  val input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h")
  val dummyHandler = {
      _: ImmutableList<AbstractListInputMinimizer.ElementWrapper<String>>, _: String ->
  }

  private fun checkOrder(
    list: ImmutableList<String>?,
  ): Boolean {
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
      assertThat(testHistory).containsExactly(
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
      assertThat(testHistory).containsExactly(
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
      assertThat(testHistory).containsExactly(
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
      assertThat(testHistory).containsExactly(
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
  ): ImmutableList<String>? {
    val testHistory = ArrayList<String>()
    val delHistory = ArrayList<String>()

    val propertyTest =
      IPropertyTester<String, String> { configuration ->
        val candidate = configuration.candidate
        val deleted = configuration.deleted
        testHistory.add(candidate.joinToString(separator = ""))
        delHistory.add(deleted.joinToString(separator = ""))
        if (candidate.containsAll(property)) {
          PropertyTestResultWithPayload(INTERESTING_RESULT, "payload")
        } else {
          PropertyTestResultWithPayload(NON_INTERESTING_RESULT, "payload")
        }
      }

    val arguments = AbstractListInputMinimizer.Arguments(
      needToTestEmpty = true,
      input,
      propertyTest,
      dummyHandler,
      descriptionPrefix = "",
    )
    val debugger = if (isProbabilisticDeltaDebugger) {
      PristineProbabilisticDeltaDebugger<String, String>(arguments)
    } else {
      CounterBasedDeltaDebugger<String, String>(arguments)
    }

    val result = debugger.reduce()
    assertThat(result).isEqualTo(expected)
    return ImmutableList.copyOf(testHistory)
  }
}
