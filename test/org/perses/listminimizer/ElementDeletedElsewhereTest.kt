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

/**
 * [ListMinimizerArguments.isElementDeletedElsewhere] is how a tester says an element is gone for
 * good, so the minimizer should stop carrying it. latra relies on this for a match whose nodes an
 * earlier accepted edit removed; the spar-tree reducer relies on it for a permanently deleted node.
 *
 * The path had no test, which is why [AbstractListMinimizer.updateBest] carries a TODO saying so.
 */
@RunWith(JUnit4::class)
class ElementDeletedElsewhereTest {
  private val input = ImmutableList.of("a", "b", "c", "d", "e")

  /**
   * Runs a minimization, returning the result together with every wrapper the tester ever saw and
   * every list announced to [ListMinimizerArguments.onBestUpdate].
   *
   * The wrappers come from the candidates rather than from the announcements, because a pruned
   * element is deliberately absent from what is announced.
   */
  private fun reduceReportingDeletedElsewhere(
    property: Collection<String>,
    deletedElsewhere: Set<String>,
  ): Reduction {
    val wrappersSeen = mutableMapOf<String, ElementWrapper<String>>()
    val announced = mutableListOf<List<ElementWrapper<String>>>()
    val minimizer =
      PristineDeltaDebugger(
        ListMinimizerArguments(
          needToTestEmpty = true,
          input = input,
          isElementDeletedElsewhere = { it in deletedElsewhere },
          propertyTester = { configuration ->
            (configuration.candidateWrappers + configuration.deletedWrappers).forEach {
              wrappersSeen[it.element] = it
            }
            ImmediatePropertyTestHandle(
              if (configuration.getCandidateOrFail().containsAll(property)) {
                CandidateOutcome.Interesting("", INTERESTING)
              } else {
                CandidateOutcome.Uninteresting.Rejected(NON_INTERESTING)
              },
            )
          },
          onBestUpdateHandler =
            OnBestUpdateHandler<String, String> { newBest, _ ->
              announced.add(newBest.toList())
            },
          descriptionPrefix = "prefix",
        ),
      )
    return Reduction(minimizer.reduce(), wrappersSeen, announced)
  }

  private class Reduction(
    val result: ImmutableList<out String>,
    val wrappersSeen: Map<String, ElementWrapper<String>>,
    val announced: List<List<ElementWrapper<String>>>,
  )

  @Test
  fun testAnElementDeletedElsewhereIsDroppedFromTheResult() {
    // "e" is required by the property, so without this mechanism it would survive to the end.
    val reduction =
      reduceReportingDeletedElsewhere(
        property = listOf("a", "e"),
        deletedElsewhere = setOf("e"),
      )

    assertThat(reduction.result).doesNotContain("e")
  }

  @Test
  fun testTheDroppedElementIsMarkedDeletedSoOtherMinimizersSkipIt() {
    // SpeculativeGreedyDriver checks ElementWrapper.deleted before committing a candidate, so the
    // flag has to be set and not merely filtered out of the list.
    val reduction =
      reduceReportingDeletedElsewhere(
        property = listOf("a", "e"),
        deletedElsewhere = setOf("e"),
      )

    val staleWrapper = reduction.wrappersSeen.getValue("e")
    assertThat(staleWrapper.deleted).isTrue()
  }

  /**
   * onBestUpdate announces the list the minimizer kept, not the one a successful candidate
   * proposed. Announcing the latter would hand a handler an element the minimizer had just
   * discarded -- ppr's handler stores what it is given as its best diff.
   */
  @Test
  fun testOnBestUpdateAnnouncesTheKeptListRatherThanTheProposedOne() {
    val reduction =
      reduceReportingDeletedElsewhere(
        property = listOf("a", "e"),
        deletedElsewhere = setOf("e"),
      )

    assertThat(reduction.announced).isNotEmpty()
    assertThat(reduction.announced.flatten().map { it.element }).doesNotContain("e")
  }

  @Test
  fun testNothingIsDroppedWhenTheTesterReportsNothingDeletedElsewhere() {
    val reduction =
      reduceReportingDeletedElsewhere(
        property = listOf("a", "e"),
        deletedElsewhere = emptySet(),
      )

    assertThat(reduction.result).containsExactly("a", "e").inOrder()
  }
}
