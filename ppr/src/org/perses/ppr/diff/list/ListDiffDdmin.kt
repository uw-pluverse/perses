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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.IPropertyTester
import org.perses.listminimizer.LMPropertyTestResult
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.listminimizer.OnBestUpdateHandler
import org.perses.listminimizer.PristineDeltaDebugger
import org.perses.program.PersesTokenFactory.AbstractPersesToken
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.util.AbstractEditOperation
import org.perses.util.ktInfo
import org.perses.util.transformToImmutableList

class ListDiffDdmin(
  ioManager: ListDiffReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractListDiffReducer(
    nameAndDesc =
      object : AbstractReducerNameAndDesc(
        shortName = ListDiffDdmin::class.simpleName!!,
        description = "DDmin-based diff minimizer.",
      ) {},
    ioManager = ioManager,
    testScriptExecutorService = testScriptExecutorService,
  ) {
  override fun reduce(state: ListDiffReductionState) {
    logger.ktInfo { "Start ${this::class}" }
    val debugger = createPristineDeltaDebugger(state)
    debugger.reduce()
  }

  private fun createPristineDeltaDebugger(
    state: ListDiffReductionState,
  ): PristineDeltaDebugger<AbstractEditOperation<AbstractPersesToken>, Any> {
    val onBestUpdateHandler =
      OnBestUpdateHandler<AbstractEditOperation<AbstractPersesToken>, Any> { newBest, _ ->
        // TODO(cnsun): converting newBest to a new list is not efficient.
        val newBestDiff: ImmutableList<AbstractEditOperation<AbstractPersesToken>> =
          newBest.transformToImmutableList { it.element }
        state.updateBestDiff(newBestDiff)
      }

    val propertyTest =
      IPropertyTester { configuration ->
        val testTask =
          executorService.testProgramAsync(
            TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
            IDENTITY_POST_CHECK,
            ioManager.createOutputManager(configuration.getCandidateOrFail()),
            payload = "dummy payload",
          )
        LMPropertyTestResult.Completed(testTask.getWithTimeoutWarnings(), Any())
      }
    return PristineDeltaDebugger(
      ListMinimizerArguments(
        needToTestEmpty = true,
        input = state.bestDiff,
        propertyTest,
        onBestUpdateHandler,
        descriptionPrefix = this::class.simpleName.toString(),
      ),
    )
  }
}
