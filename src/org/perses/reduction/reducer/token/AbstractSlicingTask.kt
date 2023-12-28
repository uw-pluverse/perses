/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.EditTestPayload
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.TestScriptExecResult
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.cache.AbstractProgramEncoding
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractNodeActionSetCache
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.shell.ExitCode

abstract class AbstractSlicingTask(
  val tree: SparTree,
  private val nodeActionSetCache: AbstractNodeActionSetCache,
  private val listenerManager: AsyncReductionListenerManager,
  private val queryCache: AbstractQueryCache,
  private val ioManager: TokenReductionIOManager,
  private val configuration: ReductionConfiguration,
  private val methodToTestProgramAsynchronously: (
    preCheck: TestScriptExecutorService.IPreCheck<EditTestPayload>,
    postCheck: TestScriptExecutorService.IPostCheck<EditTestPayload>,
    outputManager: AbstractOutputManager,
    payload: EditTestPayload,
  ) -> TestScriptExecResult<EditTestPayload>,
) {

  protected var future: TestScriptExecResult<EditTestPayload>? = null

  abstract fun tryAsyncRunPreconditionCheck(): Boolean

  abstract fun createNodeDeletionActionSet(): NodeDeletionActionSet

  enum class EnumAsyncRunResult {
    PRECONDITION_FAIL,
    CACHE_HIT,
    TEST_SUBMITTED,
  }

  fun tryAsyncRun(
    visitedCacheKeys: HashSet<AbstractProgramEncoding<*>>,
  ): EnumAsyncRunResult {
    check(future == null)

    if (!tryAsyncRunPreconditionCheck()) {
      return EnumAsyncRunResult.PRECONDITION_FAIL
    }

    val nodeDeletionActionSet = createNodeDeletionActionSet()

    if (nodeActionSetCache.isCachedOrCacheIt(nodeDeletionActionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(nodeDeletionActionSet)
      return EnumAsyncRunResult.CACHE_HIT
    }

    val treeEdit = tree.createNodeDeletionEdit(nodeDeletionActionSet)
    val testProgram = treeEdit.program
    val cachedResult = queryCache.getCachedResult(testProgram)
    if (cachedResult.isHit()) {
      val testResult = cachedResult.asCacheHit().testResult
      check(testResult.isNotInteresting) { "Only failed programs can be cached." }
      listenerManager.onTestResultCacheHit(testResult, testProgram, treeEdit)
      return EnumAsyncRunResult.CACHE_HIT
    }

    if (cachedResult.hasEncoding() && !visitedCacheKeys.add(cachedResult.getEncodingOrFail())) {
      // the same program was submitted to async test already.
      return EnumAsyncRunResult.CACHE_HIT
    }

    check(future == null)
    future = methodToTestProgramAsynchronously(
      ALWAYS_TRUE_PRECHECK,
      createParsabilityPostCheck(testProgram),
      ioManager.createOutputManager(testProgram),
      EditTestPayload(treeEdit, cachedResult.asCacheMiss()),
    )
    return EnumAsyncRunResult.TEST_SUBMITTED
  }

  private fun createParsabilityPostCheck(
    testProgram: TokenizedProgram,
  ): (existingResult: PropertyTestResult, payload: EditTestPayload) -> PropertyTestResult =
    { existing, _ ->
      if (existing.isNotInteresting || isProgramParsable(testProgram)) {
        existing
      } else {
        PropertyTestResult(
          exitCode = INVALID_SYNTAX_EXIT_CODE,
          elapsedMilliseconds = -1,
        )
      }
    }

  private fun isProgramParsable(testProgram: TokenizedProgram) =
    configuration.parserFacade.isSourceCodeParsable(
      PrinterRegistry.getPrinter(ioManager.getDefaultProgramFormat())
        .print(testProgram).sourceCode,
    )

  fun cancel() {
    future?.let {
      it.cancelWithInterruption()
      future = null
    }
  }

  fun waitAndApplyEditIfSuccess(): Boolean {
    check(future != null)
    val best = analyzeResultsAndGetBest(listOf(future!!)) ?: return false
    tree.applyEdit(best.payload!!.edit)
    future = null
    return true
  }

  abstract fun analyzeResultsAndGetBest(
    futureResult: List<TestScriptExecResult<EditTestPayload>>,
  ): TestScriptExecResult<EditTestPayload>?

  companion object {
    val INVALID_SYNTAX_EXIT_CODE = ExitCode(99)
  }
}
