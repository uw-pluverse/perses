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

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.EditTestPayload
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.TestScriptExecutorService.Companion.IDENTITY_POST_CHECK
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.util.Util.lazyAssert
import org.perses.util.shell.ExitCode

class TokenSlicer(
  reducerContext: ReducerContext,
  val minSlicingGranularity: Int,
  val maxSlicingGranularity: Int,
) : AbstractTokenReducer(META, reducerContext) {

  init {
    require(minSlicingGranularity in 1..maxSlicingGranularity) {
      "0 < minTokenCount($minSlicingGranularity) <= maxTokneCount($maxSlicingGranularity)."
    }
  }

  // TODO: This algorithm need to be parallelized.
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    for (tokenSlicingGranularity in maxSlicingGranularity downTo minSlicingGranularity) {
      val tokens = tree.remainingLexerRuleNodes
      val startEvent = fixpointReductionState
        .fixpointIterationStartEvent
        .createTokenSlicingStartEvent(
          currentTimeMillis = System.currentTimeMillis(),
          programSize = tree.programSnapshot.tokenCount(),
          tokenSlicingGranularity = tokenSlicingGranularity,
        )
      listenerManager.onSlicingTokensStart(startEvent)
      for (startIndex in tokens.size - 1 downTo tokenSlicingGranularity - 1) {
        if (tokens[startIndex].isPermanentlyDeleted) {
          continue
        }
        val nodeDeletionActionSet = createNodeDeletionActionSetReverse(
          tokens,
          startIndex,
          tokenSlicingGranularity,
        )
        if (nodeActionSetCache.isCachedOrCacheIt(nodeDeletionActionSet)) {
          listenerManager.onNodeEditActionSetCacheHit(nodeDeletionActionSet)
          continue
        }
        val treeEdit = tree.createNodeDeletionEdit(nodeDeletionActionSet)
        val testProgram = treeEdit.program
        val cachedResult = queryCache.getCachedResult(testProgram)
        if (cachedResult.isHit()) {
          val testResult = cachedResult.asCacheHit().testResult
          lazyAssert({ testResult.isNotInteresting }) { "Only failed programs can be cached." }
          listenerManager.onTestResultCacheHit(testResult, testProgram, treeEdit)
          continue
        }
        val parserFacade = configuration.parserFacade
        val future = executorService.testProgramAsync(
          if (testProgram.tokenCount() <= 150) { // TODO: need to tune the threshold.
            {
              if (parserFacade.isSourceCodeParsable(
                  PrinterRegistry.getPrinter(ioManager.getDefaultProgramFormat())
                    .print(testProgram).sourceCode,
                )
              ) {
                PropertyTestResult(exitCode = ExitCode.ZERO, elapsedMilliseconds = -1)
              } else {
                PropertyTestResult(exitCode = INVALID_SYNTAX_EXIT_CODE, elapsedMilliseconds = -1)
              }
            }
          } else {
            TestScriptExecutorService.ALWAYS_TRUE_PRECHECK
          },
          IDENTITY_POST_CHECK,
          ioManager.createOutputManager(testProgram),
          EditTestPayload(treeEdit, cachedResult.asCacheMiss()),
        )
        val best = analyzeResultsAndGetBest(
          listOf(future),
        )
        if (best != null) {
          tree.applyEdit(best.payload!!.edit)
        }
      }

      val endEvent = startEvent.createEndEvent(
        currentTimeMillis = System.currentTimeMillis(),
        programSize = tree.programSnapshot.tokenCount(),
      )
      listenerManager.onSlicingTokensEnd(endEvent)
    }
  }

  companion object {

    // TODO: fix the typo here.
    const val NAME = "token_sclier"

    @JvmStatic
    val META = object : ReducerAnnotation(
      shortName = NAME,
      description = "",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
        return ImmutableList.of(
          TokenSlicer(
            reducerContext,
            minSlicingGranularity = 1,
            maxSlicingGranularity = 14,
          ),
        )
      }
    }

    @VisibleForTesting
    val INVALID_SYNTAX_EXIT_CODE = ExitCode(99)

    @VisibleForTesting
    fun createNodeDeletionActionSetReverse(
      tokenList: List<LexerRuleSparTreeNode>,
      inclusiveEndIndex: Int,
      tokenCountToDelete: Int,
    ): NodeDeletionActionSet {
      val inclusiveStartIndex = inclusiveEndIndex - tokenCountToDelete + 1
      check(inclusiveStartIndex >= 0) { inclusiveStartIndex }
      val subList = tokenList.subList(inclusiveStartIndex, inclusiveEndIndex + 1)
      subList.forEach {
        lazyAssert({ !it.isPermanentlyDeleted }) { it }
      }
      return NodeDeletionActionSet.createByDeletingNodes(
        subList,
        "token slicer@$tokenCountToDelete",
      )
    }
  }
}
