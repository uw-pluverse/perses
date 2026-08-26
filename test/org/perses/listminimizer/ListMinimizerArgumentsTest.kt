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
import org.perses.reduction.TestScriptVerdict.Companion.NON_INTERESTING
import kotlin.reflect.KClass

@RunWith(JUnit4::class)
class ListMinimizerArgumentsTest {
  private val wrappers =
    ImmutableList.of(
      ElementWrapper(index = 0, element = "a", elementPayload = Any()),
      ElementWrapper(index = 1, element = "b", elementPayload = Any()),
    )

  private val candidate =
    Candidate.DeletionsFromOriginal(
      original = wrappers,
      deleted_ = ImmutableList.of(wrappers[1]),
    )

  private fun argumentsWith(tester: IPropertyTester<String, String>) =
    ListMinimizerArguments(
      needToTestEmpty = false,
      input = ImmutableList.of("a", "b"),
      isElementDeletedElsewhere = { false },
      propertyTester = tester,
      onBestUpdateHandler = OnBestUpdateHandler<String, String> { _, _ -> },
      descriptionPrefix = "prefix",
    )

  /**
   * The wrapper exists to notify the listener, and it does so on [PropertyTestHandle.get] rather
   * than at submission, so a speculative test that is cancelled before being read is never reported
   * as a query.
   */
  @Test
  fun testSubmitPropertyNotifiesTheListenerOnGetRatherThanOnSubmission() {
    val observed = mutableListOf<CandidateOutcome<*>>()
    val listener =
      object : AbstractListMinimizerListener() {
        override fun startReduction(
          originalInput: List<ElementWrapper<*>>,
          listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
          descriptionPrefix: String,
        ) {
        }

        override fun endReduction(
          minimizationResult: List<ElementWrapper<*>>,
          listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
          sizeOfOriginalInput: Int,
        ) {
        }

        override fun onBestUpdate(newBest: List<ElementWrapper<*>>) {
        }

        override fun onPropertyTest(
          configuration: Candidate<*>,
          result: CandidateOutcome<*>,
          sizeOfOriginalList: Int,
          sizeOfCurrentMinimizationResult: Int,
        ) {
          observed.add(result)
        }

        override fun log(msg: () -> String) {
        }

        override fun close() {
        }
      }
    val outcome = CandidateOutcome.Uninteresting.Rejected(NON_INTERESTING)
    val arguments =
      argumentsWith { _ -> ImmediatePropertyTestHandle(outcome) }
        .copy(listener = listener)

    val handle = arguments.submitProperty(candidate, sizeOfCurrentMinimizationResult = 2)
    assertThat(observed).isEmpty()

    assertThat(handle.get()).isSameInstanceAs(outcome)
    assertThat(observed).containsExactly(outcome)
  }
}
