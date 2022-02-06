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
package org.perses.reduction.reducer.token

import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.FutureExecutionResultInfo
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.ReductionListenerManager
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractNodeActionSetCache
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree

abstract class AbstractSlicingTask(
  val tree: SparTree,
  private val nodeActionSetCache: AbstractNodeActionSetCache,
  private val listenerManager: ReductionListenerManager,
  private val queryCache: AbstractQueryCache,
  private val ioManager: TokenReductionIOManager,
  private val configuration: ReductionConfiguration,
  private val methodToTestProgramAsynchronously: (
    preCheck: () -> PropertyTestResult,
    postCheck: (existingResult: PropertyTestResult) -> PropertyTestResult,
    outputManager: AbstractOutputManager
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
    if (cachedResult.isHit()) {
      val testResult = cachedResult.asCacheHit().testResult
      check(testResult.isNotInteresting) { "Only failed programs can be cached." }
      listenerManager.onTestResultCacheHit(testResult, testProgram, treeEdit)
      return false
    }

    val future = methodToTestProgramAsynchronously(
      ALWAYS_TRUE_PRECHECK,
      createParsabilityPostCheck(testProgram),
      ioManager.createOutputManager(testProgram)
    )
    check(futureResult == null)
    futureResult = FutureExecutionResultInfo(
      treeEdit,
      cachedResult.asCacheMiss(),
      future
    )
    return true
  }

  private fun createParsabilityPostCheck(
    testProgram: TokenizedProgram
  ): (existingResult: PropertyTestResult) -> PropertyTestResult =
    { existing ->
      if (existing.isNotInteresting || isProgramParsable(testProgram)) {
        existing
      } else {
        PropertyTestResult(
          exitCode = INVALID_SYNTAX_EXIT_CODE,
          elapsedMilliseconds = -1
        )
      }
    }

  private fun isProgramParsable(testProgram: TokenizedProgram) =
    configuration.parserFacade.isSourceCodeParsable(
      PrinterRegistry.getPrinter(ioManager.getDefaultProgramFormat())
        .print(testProgram).sourceCode
    )

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
