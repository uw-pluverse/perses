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

/**
 * What every drdd variant must satisfy regardless of how it cuts blocks. The exact test sequences
 * each variant performs are pinned by the golden_test_list_minimizer_trace_* goldens instead.
 */
@RunWith(JUnit4::class)
class DeferredRestartDeltaDebuggerTest : AbstractListMinimizerTest<Int>() {
  private val drddTypes =
    listOf(
      EnumListMinimizerType.DRDD,
      EnumListMinimizerType.WDRDD,
      EnumListMinimizerType.PRISTINE_DRDD,
      EnumListMinimizerType.PRISTINE_WDRDD,
    )

  @Test
  fun testResultIsExactlyTheProperty() {
    val random = Random(20260923)
    for (type in drddTypes) {
      repeat(100) {
        val input = ImmutableList.copyOf((1..random.nextInt(1, 40)).toList())
        val weights = input.associateWith { random.nextInt(1, 20) }
        val property =
          when (it) {
            0 -> listOf()
            1 -> input
            else -> input.filter { random.nextInt(5) == 0 }
          }
        runMinimizerTest(
          input = input,
          property = property,
          expected = property,
          weightProvider = { element -> weights.getValue(element) },
        ) { arguments ->
          ListMinimizerFactory.create(type, arguments)
        }
      }
    }
  }

  @Test
  fun testUnitWeightsMakePristineWdrddPerformExactlyTheTestsOfPristineDrdd() {
    val random = Random(20260923)
    repeat(100) {
      val input = ImmutableList.copyOf((1..random.nextInt(1, 40)).toList())
      val property = input.filter { random.nextInt(5) == 0 }
      val histories =
        listOf(
          EnumListMinimizerType.PRISTINE_WDRDD,
          EnumListMinimizerType.PRISTINE_DRDD,
        ).map { type ->
          runMinimizerTest(input = input, property = property, expected = property) { arguments ->
            ListMinimizerFactory.create(type, arguments)
          }
        }
      assertThat(histories[0]).containsExactlyElementsIn(histories[1]).inOrder()
    }
  }

  /**
   * A causal chain: digit k is removable only once digit k+1 is gone, so each forward
   * single-element sweep removes only the last remaining digit.
   */
  private fun runOnCausalChain(
    type: EnumListMinimizerType,
    restartBudget: Int,
  ): List<Int> {
    val xMarker = 0
    val minimizer =
      ListMinimizerFactory.create(
        type,
        ListMinimizerArguments(
          needToTestEmpty = true,
          input = ImmutableList.of(xMarker, 1, 2, 3, 4),
          isElementDeletedElsewhere = { false },
          propertyTester = { configuration ->
            val candidate = configuration.getCandidateOrFail()
            val digits = candidate.filter { it != xMarker }
            ImmediatePropertyTestHandle(
              if (xMarker in candidate && digits == (1..digits.size).toList()) {
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
    for (type in drddTypes) {
      assertThat(runOnCausalChain(type, restartBudget = Int.MAX_VALUE)).containsExactly(0)
    }
  }

  @Test
  fun testRestartBudgetBoundsSingleElementSweeps() {
    for (type in drddTypes) {
      assertThat(runOnCausalChain(type, restartBudget = 0))
        .containsExactly(0, 1, 2, 3, 4)
        .inOrder()
      assertThat(runOnCausalChain(type, restartBudget = 1)).containsExactly(0, 1, 2, 3).inOrder()
      assertThat(runOnCausalChain(type, restartBudget = 3)).containsExactly(0, 1).inOrder()
    }
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
