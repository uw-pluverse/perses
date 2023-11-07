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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import org.perses.delta.AbstractPropertyTestResultWithPayload
import org.perses.delta.IPropertyTester
import org.perses.delta.PristineDeltaDebugger
import org.perses.delta.PropertyTestResultWithPayload
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.util.AbstractEditOperation
import org.perses.util.ktInfo

class ListDiffDdmin(
  ioManager: ListDiffReductionIOManager,
  testScriptExecutorService: TestScriptExecutorService,
) : AbstractListDiffReducer(
  ioManager,
  testScriptExecutorService,
) {

  override fun reduce(state: ListDiffReductionState) {
    logger.ktInfo { "Start ${this::class}" }
    val debugger = createPristineDeltaDebugger(state)
    debugger.reduce()
  }

  fun createPristineDeltaDebugger(
    state: ListDiffReductionState,
  ): PristineDeltaDebugger<AbstractEditOperation<PersesToken>, Any> {
    val onBestUpdateHandler =
      {
          newBest: ImmutableList<AbstractEditOperation<PersesToken>>, _: Any,
        ->
        state.updateBestDiff(newBest)
      }

    val propertyTest = object :
      IPropertyTester<AbstractEditOperation<PersesToken>, Any> {
      override fun testProperty(
        currentBest: ImmutableList<AbstractEditOperation<PersesToken>>,
        candidate: ImmutableList<AbstractEditOperation<PersesToken>>,
      ): AbstractPropertyTestResultWithPayload<Any> {
        val testTask = executorService.testProgramAsync(
          TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
          IDENTITY_POST_CHECK,
          ioManager.createOutputManager(candidate),
          payload = "dummy payload",
        )
        return PropertyTestResultWithPayload(testTask.getWithTimeoutWarnings(), Any())
      }
    }
    return PristineDeltaDebugger(
      state.bestDiff,
      propertyTest,
      onBestUpdateHandler,
    )
  }
}
