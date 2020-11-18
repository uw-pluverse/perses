/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction.reducer

import org.perses.program.TokenizedProgram
import org.perses.reduction.AbstractTestScriptExecutionCache
import org.perses.reduction.FutureExecutionResultInfo
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.ReductionListenerManager
import org.perses.reduction.TestScript
import org.perses.reduction.TestScriptExecutorService
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.NodeDeletionActionSet
import org.perses.tree.spar.SparTree

abstract class AbstractSlicingTask(
  val tree: SparTree,
  private val nodeActionSetCache: AbstractNodeActionSetCache,
  private val listenerManager: ReductionListenerManager,
  private val queryCache: AbstractTestScriptExecutionCache,
  private val configuration: ReductionConfiguration,
  private val methodToTestProgramAsynchronously: (
    precheck: () -> TestScript.TestResult,
    program: TokenizedProgram
  ) -> TestScriptExecutorService.FutureTestScriptExecutionTask
) {

  protected var futureResult: FutureExecutionResultInfo? = null

  abstract fun tryAsyncRunPreconditionCheck(): Boolean

  abstract fun createNodeDeletionActionSet(): NodeDeletionActionSet

  fun tryAsyncRun(): Boolean {
    check(futureResult == null)

    if (!tryAsyncRunPreconditionCheck()) {
      return false
    }

    val nodeDeletionActionSet = createNodeDeletionActionSet()

    if (nodeActionSetCache.isCachedOrCacheIt(nodeDeletionActionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(nodeDeletionActionSet)
      return false
    }

    val treeEdit = tree.createNodeDeletionEdit(nodeDeletionActionSet)
    val testProgram = treeEdit.program
    val cachedResult = queryCache.getCachedResult(testProgram)
    if (cachedResult.isPresent) {
      check(cachedResult.get().isFail) { "Only failed programs can be cached." }
      listenerManager.onTestResultCacheHit(cachedResult.get(), testProgram, treeEdit)
      return false
    }

    val future = methodToTestProgramAsynchronously.invoke(
      if (testProgram.tokenCount() <= 150) { // TODO: need to tune the threshold.
        {
          if (configuration.parserFacade.isSourceCodeParsable(
              testProgram.toCompactSourceCode()
            )
          ) {
            TestScript.TestResult(exitCode = 0, elapsedMilliseconds = -1)
          } else {
            TestScript.TestResult(
              exitCode = INVALID_SYNTAX_EXIT_CODE,
              elapsedMilliseconds = -1
            )
          }
        }
      } else {
        TestScriptExecutorService.ALWAYS_TRUE_PRECHECK
      },
      testProgram
    )
    check(futureResult == null)
    futureResult = FutureExecutionResultInfo(
      treeEdit,
      testProgram,
      future
    )
    return true
  }

  fun cancel() {
    if (futureResult != null) {
      futureResult!!.cancel()
      futureResult = null
    }
  }

  fun waitAndApplyEditIfSuccess(): Boolean {
    check(futureResult != null)
    val best = analyzeResultsAndGetBest(listOf(futureResult!!)) ?: return false
    tree.applyEdit(best.edit)
    futureResult = null
    return true
  }

  abstract fun analyzeResultsAndGetBest(
    futureResult: List<FutureExecutionResultInfo>
  ): FutureExecutionResultInfo?

  companion object {
    val INVALID_SYNTAX_EXIT_CODE = 99
  }
}
