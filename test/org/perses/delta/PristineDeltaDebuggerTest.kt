/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.delta

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.PropertyTestResult.Companion.INTERESTING_RESULT
import org.perses.reduction.PropertyTestResult.Companion.NON_INTERESTING_RESULT

@RunWith(JUnit4::class)
class PristineDeltaDebuggerTest {

  val input = ImmutableList.of("a", "b", "c", "d", "e")

  val dummyHandler = { _: ImmutableList<String>, _: String ->
  }

  @Test
  fun test_a() {
    test(property = listOf("a"), expected = listOf("a"))
    test(property = listOf("a", "e"), expected = listOf("a", "e")).let { testHistory ->
      assertThat(testHistory).containsExactly(
        // n = 1
        "",
        // n = 2
        "abc", "de", "de", "abc",
        // n = 4
        "ab", "c", "d", "e", "cde", "abde",
        // n = 3
        "ab", "d", "e", "de", "abe",
        // n = 2
        "ab", "e", "e", "ab",
        // n = 3
        "a", "b", "e", "be", "ae",
        // n = 2
        "a", "e", "e", "a"
      ).inOrder()
    }
    test(property = listOf("c"), expected = listOf("c"))
    test(property = listOf("a", "b", "c", "d", "e"), expected = listOf("a", "b", "c", "d", "e"))
    test(property = listOf(), expected = listOf())
  }

  private fun test(property: List<String>, expected: List<String>): ImmutableList<String>? {
    val testHistory = ArrayList<String>()

    val propertyTest = object : IPropertyTest<String, String> {
      override fun testProperty(
        currentBest: ImmutableList<String>,
        candidate: ImmutableList<String>
      ): AbstractPropertyTestResultWithPayload<String> {
        testHistory.add(candidate.joinToString(separator = ""))
        return if (candidate.containsAll(property)) {
          PropertyTestResultWithPayload(INTERESTING_RESULT, "payload")
        } else {
          PropertyTestResultWithPayload(NON_INTERESTING_RESULT, "payload")
        }
      }
    }

    val debugger = PristineDeltaDebugger<String, String>(
      input,
      propertyTest,
      dummyHandler
    )
    debugger.reduce()
    assertThat(debugger.best).isEqualTo(expected)
    return ImmutableList.copyOf(testHistory)
  }
}
