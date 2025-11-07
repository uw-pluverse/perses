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
package org.perses.reduction.reducer.token

import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.EditTestPayload
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecResult
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import org.perses.reduction.TreeEditWithItsResult
import org.perses.reduction.cache.AbstractProgramEncoding
import org.perses.reduction.io.AbstractOutputManager
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.FileNameContentPair
import org.perses.util.shell.ExitCode
import org.perses.util.transformToImmutableList

/**
 * TODO(cnsun): this needs to be merged into the list minimizer framework.
 */
abstract class AbstractSlicingTask(
  val tree: SparTree,
  private val reducerContext: ReducerContext,
  private val methodToTestProgramAsynchronously: (
    preCheck: TestScriptExecutorService.IPreCheck<EditTestPayload>,
    postCheck: TestScriptExecutorService.IPostCheck<EditTestPayload>,
    outputManager: AbstractOutputManager,
    payload: EditTestPayload,
  ) -> TestScriptExecResult<EditTestPayload>,
) {
  protected var future: TestScriptExecResult<EditTestPayload>? = null

  protected abstract fun tryAsyncRunPreconditionCheck(): Boolean

  protected abstract fun createNodeDeletionActionSet(): NodeDeletionActionSet

  enum class EnumAsyncRunResult {
    PRECONDITION_FAIL,
    CACHE_HIT,
    TEST_SUBMITTED,
  }

  fun tryAsyncRun(visitedCacheKeys: HashSet<AbstractProgramEncoding<*>>): EnumAsyncRunResult {
    check(future == null)

    if (!tryAsyncRunPreconditionCheck()) {
      return EnumAsyncRunResult.PRECONDITION_FAIL
    }

    val nodeDeletionActionSet = createNodeDeletionActionSet()
    val listenerManager = reducerContext.listenerManager
    val nodeActionSetCache = reducerContext.nodeActionSetCache
    if (nodeActionSetCache.isCachedOrCacheIt(nodeDeletionActionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(nodeDeletionActionSet)
      return EnumAsyncRunResult.CACHE_HIT
    }

    val treeEdit = tree.createNodeDeletionEdit(nodeDeletionActionSet)
    val testProgram = treeEdit.program
    val outputManager = reducerContext.ioManager.createOutputManager(testProgram)
    val cachedResult =
      reducerContext.queryCache.getCachedResult(
        testProgram,
        outputManager = outputManager,
      )
    if (cachedResult.isHit()) {
      listenerManager.onTestResultCacheHit(
        testProgram,
        treeEdit,
        outputCreator = {
          outputManager.fileContentList
            .transformToImmutableList {
              FileNameContentPair(
                fileName = it.fileName.baseName,
                content = it.content,
              )
            }
        },
      )
      return EnumAsyncRunResult.CACHE_HIT
    }

    if (cachedResult.hasEncoding() && !visitedCacheKeys.add(cachedResult.getEncodingOrFail())) {
      // the same program was submitted to async test already.
      return EnumAsyncRunResult.CACHE_HIT
    }

    check(future == null)
    future =
      methodToTestProgramAsynchronously(
        ALWAYS_TRUE_PRECHECK,
        createParsabilityPostCheck(testProgram),
        outputManager,
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
          elapsedMillis = -1,
        )
      }
    }

  private fun isProgramParsable(testProgram: TokenizedProgram) =
    reducerContext.configuration.parserFacade.isSourceCodeParsable(
      PrinterRegistry
        .getPrinter(reducerContext.ioManager.getDefaultProgramFormat())
        .print(testProgram)
        .sourceCode,
    )

  fun cancel() {
    future?.let {
      it.cancelWithInterruption()
      future = null
    }
  }

  fun waitToGetTheBestEditIfSuccess(): TreeEditWithItsResult? {
    val localFuture = future
    check(localFuture != null) { "The future is null." }
    val best = analyzeResultAndGetBest(localFuture) ?: return null
    localFuture.close()
    future = null
    return best
  }

  abstract fun analyzeResultAndGetBest(
    futureResult: TestScriptExecResult<EditTestPayload>,
  ): TreeEditWithItsResult?

  companion object {
    val INVALID_SYNTAX_EXIT_CODE = ExitCode(99)
  }
}
