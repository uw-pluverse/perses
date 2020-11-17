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

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractReducer
import org.perses.reduction.AbstractReductionEvent
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScript.TestResult
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.reducer.TokenSlicer.Companion.INVALID_SYNTAX_EXIT_CODE
import org.perses.reduction.reducer.TokenSlicer.Companion.createNodeDeletionActionSetReverse
import org.perses.reduction.reducer.TokenSlicer.Companion.extractLexerRuleNodes
import org.perses.tree.spar.LexerRuleSparTreeNode
import org.perses.tree.spar.SparTree

class ConcurrentTokenSlicer(
  reducerContext: ReducerContext,
  val minSlicingGranularity: Int,
  val maxSlicingGranularity: Int
) : AbstractReducer(META, reducerContext) {

  init {
    require(minSlicingGranularity in 1..maxSlicingGranularity) {
      "0 < minTokenCount($minSlicingGranularity) <= maxTokneCount($maxSlicingGranularity)."
    }
  }

  // TODO: This algorithm need to be parallelized.
  override fun internalReduce(tree: SparTree) {
    for (tokenSlicingGranularity in maxSlicingGranularity downTo minSlicingGranularity) {
      sliceTreeForGivenGranularity(tree, tokenSlicingGranularity)
    }
  }

  private fun sliceTreeForGivenGranularity(tree: SparTree, tokenSlicingGranularity: Int) {
    val tokens = extractLexerRuleNodes(tree)
    val slicingStartEvent = AbstractReductionEvent.TokenSlicingStartEvent(
      System.currentTimeMillis(), tree.programSnapshot.tokenCount(), tokenSlicingGranularity
    )
    listenerManager.onSlicingTokensStart(slicingStartEvent)
    for (startIndex in tokens.size - 1 downTo tokenSlicingGranularity - 1) {
      SlicingTask(tokens, startIndex, tokenSlicingGranularity, tree).run()
    }
    listenerManager.onSlicingTokensEnd(
      AbstractReductionEvent.TokenSlicingEndEvent(
        System.currentTimeMillis(), tree.programSnapshot.tokenCount(), slicingStartEvent
      )
    )
  }

  inner class SlicingTask(
    val tokens: ImmutableList<LexerRuleSparTreeNode>,
    val startIndex: Int,
    val tokenSlicingGranularity: Int,
    val tree: SparTree
  ) {

    fun run() {
      if (tokens[startIndex].isPermanentlyDeleted) {
        return
      }
      val nodeDeletionActionSet = createNodeDeletionActionSetReverse(
        tokens, startIndex, tokenSlicingGranularity
      )
      if (nodeActionSetCache.isCachedOrCacheIt(nodeDeletionActionSet)) {
        listenerManager.onNodeEditActionSetCacheHit(nodeDeletionActionSet)
        return
      }
      val treeEdit = tree.createNodeDeletionEdit(nodeDeletionActionSet)
      val testProgram = treeEdit.program
      val cachedResult = queryCache.getCachedResult(testProgram)
      if (cachedResult.isPresent) {
        check(cachedResult.get().isFail) { "Only failed programs can be cached." }
        listenerManager.onTestResultCacheHit(cachedResult.get(), testProgram, treeEdit)
        return
      }
      val futureTestScriptExecutionTask = testProgramAsynchronously(
        if (testProgram.tokenCount() <= 150) { // TODO: need to tune the threshold.
          {
            if (configuration.parserFacade.isSourceCodeParsable(
                testProgram.toCompactSourceCode()
              )
            ) {
              TestResult(exitCode = 0, elapsedMilliseconds = -1)
            } else {
              TestResult(exitCode = INVALID_SYNTAX_EXIT_CODE, elapsedMilliseconds = -1)
            }
          }
        } else {
          TestScriptExecutorService.ALWAYS_TRUE_PRECHECK
        },
        testProgram
      )
      val best = analyzeResultsAndGetBest(
        listOf(
          FutureExecutionResultInfo(
            treeEdit,
            testProgram,
            futureTestScriptExecutionTask
          )
        )
      )
      if (best.isPresent) {
        tree.applyEdit(best.get().edit)
      }
    }
  }

  companion object {

    const val NAME = "concurrent_token_sclier"

    @JvmStatic
    val META = object : ReducerAnnotation() {
      override fun shortName() = NAME

      override fun description() = ""

      override fun create(reducerContext: ReducerContext) = ConcurrentTokenSlicer(
        reducerContext,
        minSlicingGranularity = 1, maxSlicingGranularity = 14
      )
    }
  }
}
