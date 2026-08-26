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
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict.Companion.INTERESTING
import org.perses.reduction.TestScriptVerdict.Companion.NON_INTERESTING

abstract class AbstractListMinimizerTest<T : Any> {
  protected val dummyHandler = OnBestUpdateHandler<T, String> { _, _ -> }

  protected fun createPropertyTester(
    property: Collection<T>,
    testHistory: MutableList<String>,
    onCandidateRequested: ((Candidate<T>) -> Unit)? = null,
  ): IPropertyTester<T, String> =
    IPropertyTester { configuration ->
      val candidate = configuration.getCandidateOrFail()
      testHistory.add(candidate.joinToString(separator = ""))
      onCandidateRequested?.invoke(configuration)
      ImmediatePropertyTestHandle(
        if (candidate.containsAll(property)) {
          CandidateOutcome.Interesting("", INTERESTING)
        } else {
          CandidateOutcome.Uninteresting.Rejected(NON_INTERESTING)
        },
      )
    }

  protected fun <M : AbstractListMinimizer<T, String>> runMinimizerTest(
    input: ImmutableList<T>,
    property: List<T>,
    expected: List<T>,
    weightProvider: IWeightProvider<T> = IWeightProvider { 1 },
    onBestUpdate: OnBestUpdateHandler<T, String>? = null,
    minimizerFactory: (ListMinimizerArguments<T, String>) -> M,
  ): ImmutableList<String> {
    val testHistory = mutableListOf<String>()
    val propertyTest = createPropertyTester(property, testHistory)

    val minimizer =
      minimizerFactory(
        ListMinimizerArguments(
          needToTestEmpty = true,
          input = input,
          isElementDeletedElsewhere = { false },
          propertyTester = propertyTest,
          onBestUpdateHandler = onBestUpdate ?: dummyHandler,
          descriptionPrefix = "prefix",
          weightProvider = weightProvider,
        ),
      )

    val result = minimizer.reduce()
    assertThat(result).containsExactlyElementsIn(expected).inOrder()
    return ImmutableList.copyOf(testHistory)
  }
}
