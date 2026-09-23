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
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict.Companion.INTERESTING
import org.perses.reduction.TestScriptVerdict.Companion.NON_INTERESTING
import kotlin.random.Random

@RunWith(JUnit4::class)
class DeferredRestartDeltaDebuggerTest : AbstractListMinimizerTest<String>() {
  private val input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h")

  private fun test(
    property: List<String>,
    expected: List<String>,
  ): List<String> =
    runMinimizerTest(input = input, property = property, expected = expected) {
      DeferredRestartDeltaDebugger(it)
    }

  @Test
  fun testResultIsExactlyTheProperty() {
    test(property = listOf(), expected = listOf())
    test(property = listOf("a"), expected = listOf("a"))
    test(property = listOf("h"), expected = listOf("h"))
    test(property = input, expected = input)
    test(property = listOf("b", "g"), expected = listOf("b", "g"))
  }

  @Test
  fun testCoarseSweepsDoNotRestart() {
    assertThat(test(property = listOf("a", "e"), expected = listOf("a", "e")))
      .containsExactly(
        "",
        // S = 4
        "efgh",
        "abcd",
        // S = 2: a successful deletion does not restart the sweep.
        "cdefgh",
        "abefgh",
        "abgh",
        "abef",
        // Single-element sweep #1 deletes b and f.
        "bef",
        "aef",
        "af",
        "ae",
        // Single-element sweep #2 reaches the fixpoint.
        "e",
        "a",
      ).inOrder()
  }

  @Test
  fun testBlocksAreBalanced() {
    val history =
      runMinimizerTest(
        input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g"),
        property = listOf("a"),
        expected = listOf("a"),
      ) {
        DeferredRestartDeltaDebugger(it)
      }
    assertThat(history)
      .containsExactly(
        "",
        // S = 3 cuts 7 elements into [a b c] [d e] [f g], not [a b c] [d e f] [g].
        "defg",
        "abcfg",
        "abc",
        // Single-element sweep #1; sweep #2 has nothing but the whole list to delete.
        "bc",
        "ac",
        "a",
      ).inOrder()
  }

  @Test
  fun testRandomContainmentPropertiesAreMinimizedExactly() {
    val random = Random(20260922)
    repeat(200) {
      val property = input.filter { random.nextInt(4) == 0 }
      test(property = property, expected = property)
    }
  }

  /**
   * A causal chain: digit k is removable only once digit k+1 is gone, so each forward
   * single-element sweep removes only the last remaining digit.
   */
  private fun runOnCausalChain(restartBudget: Int): List<String> {
    val chainInput = ImmutableList.of("x", "1", "2", "3", "4")
    val minimizer =
      DeferredRestartDeltaDebugger(
        ListMinimizerArguments(
          needToTestEmpty = true,
          input = chainInput,
          isElementDeletedElsewhere = { false },
          propertyTester = { configuration ->
            val candidate = configuration.getCandidateOrFail()
            val digits = candidate.filter { it != "x" }.map { it.toInt() }
            ImmediatePropertyTestHandle(
              if ("x" in candidate && digits == (1..digits.size).toList()) {
                CandidateOutcome.Interesting("", INTERESTING)
              } else {
                CandidateOutcome.Uninteresting.Rejected(NON_INTERESTING)
              },
            )
          },
          onBestUpdateHandler = dummyHandler,
          descriptionPrefix = "prefix",
          // Skip the coarse sweeps so that only the single-element sweeps work on the chain.
          deferredRestartDeltaDebuggerArguments =
            DeferredRestartDeltaDebuggerArguments(
              restartBudget = restartBudget,
              maxPartitionSize = 1,
            ),
        ),
      )
    return minimizer.reduce()
  }

  @Test
  fun testUnboundedRestartBudgetResolvesCausalChain() {
    assertThat(runOnCausalChain(restartBudget = Int.MAX_VALUE)).containsExactly("x")
  }

  @Test
  fun testRestartBudgetBoundsSingleElementSweeps() {
    assertThat(
      runOnCausalChain(restartBudget = 0),
    ).containsExactly("x", "1", "2", "3", "4").inOrder()
    assertThat(runOnCausalChain(restartBudget = 1)).containsExactly("x", "1", "2", "3").inOrder()
    assertThat(runOnCausalChain(restartBudget = 3)).containsExactly("x", "1").inOrder()
  }

  @Test
  fun testInvalidArgumentsAreRejected() {
    assertThrows(IllegalArgumentException::class.java) {
      DeferredRestartDeltaDebuggerArguments(restartBudget = -1)
    }
    assertThrows(IllegalArgumentException::class.java) {
      DeferredRestartDeltaDebuggerArguments(minPartitionSize = 0)
    }
    assertThrows(IllegalArgumentException::class.java) {
      DeferredRestartDeltaDebuggerArguments(maxPartitionSize = 2, minPartitionSize = 3)
    }
  }
}
