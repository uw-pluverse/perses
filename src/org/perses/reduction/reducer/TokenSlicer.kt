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

import com.google.common.annotations.VisibleForTesting
import org.perses.reduction.AbstractReducer
import org.perses.reduction.AbstractReductionEvent
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScript.TestResult
import org.perses.reduction.TestScriptExecutorService
import org.perses.tree.spar.LexerRuleSparTreeNode
import org.perses.tree.spar.NodeDeletionActionSet
import org.perses.tree.spar.SparTree

class TokenSlicer(
  reducerContext: ReducerContext,
  val minSlicingGranularity: Int,
  val maxSlicingGranularity: Int
) :
  AbstractReducer(META, reducerContext) {

  init {
    require(minSlicingGranularity in 1..maxSlicingGranularity) {
      "0 < minTokenCount($minSlicingGranularity) <= maxTokneCount($maxSlicingGranularity)."
    }
  }

  // TODO: This algorithm need to be parallelized.
  override fun internalReduce(tree: SparTree) {
    for (tokenSlicingGranularity in maxSlicingGranularity downTo minSlicingGranularity) {
      val tokens = extractLexerRuleNodes(tree)
      val startEvent = AbstractReductionEvent.TokenSlicingStartEvent(
        System.currentTimeMillis(), tree.programSnapshot.tokenCount(), tokenSlicingGranularity
      )
      listenerManager.onSlicingTokensStart(startEvent)
      for (startIndex in tokens.size - 1 downTo tokenSlicingGranularity - 1) {
        if (tokens[startIndex].isPermanentlyDeleted) {
          continue
        }
        val nodeDeletionActionSet = createNodeDeletionActionSetReverse(
          tokens, startIndex, tokenSlicingGranularity
        )
        if (nodeActionSetCache.isCachedOrCacheIt(nodeDeletionActionSet)) {
          listenerManager.onNodeEditActionSetCacheHit(nodeDeletionActionSet)
          continue
        }
        val treeEdit = tree.createNodeDeletionEdit(nodeDeletionActionSet)
        val testProgram = treeEdit.program
        val cachedResult = queryCache.getCachedResult(testProgram)
        if (cachedResult.isPresent) {
          assert(cachedResult.get().isFail) { "Only failed programs can be cached." }
          listenerManager.onTestResultCacheHit(cachedResult.get(), testProgram, treeEdit)
          continue
        }
        val parserFacade = configuration.parserFacade
        val futureTestScriptExecutionTask = testProgramAsynchronously(
          if (testProgram.tokenCount() <= 150) { // TODO: need to tune the threshold.
            {
              if (parserFacade.isSourceCodeParsable(testProgram.toCompactSourceCode())) {
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
      val endEvent = AbstractReductionEvent.TokenSlicingEndEvent(
        System.currentTimeMillis(), tree.programSnapshot.tokenCount(), startEvent
      )
      listenerManager.onSlicingTokensEnd(endEvent)
    }
  }

  companion object {

    const val NAME = "token_sclier"

    @JvmStatic
    val META = object : ReducerAnnotation() {
      override fun shortName() = NAME

      override fun description() = ""

      override fun create(reducerContext: ReducerContext) = TokenSlicer(
        reducerContext,
        minSlicingGranularity = 1, maxSlicingGranularity = 14
      )
    }

    @VisibleForTesting
    val INVALID_SYNTAX_EXIT_CODE = 99

    @VisibleForTesting
    fun extractLexerRuleNodes(tree: SparTree): ArrayList<LexerRuleSparTreeNode> {
      val tokens = ArrayList<LexerRuleSparTreeNode>()
      tree.visitRemainingTokens { tokens.add(it) }
      return tokens
    }

    @VisibleForTesting
    fun createNodeDeletionActionSetReverse(
      tokenList: List<LexerRuleSparTreeNode>,
      startIndex: Int,
      tokenCountToSlice: Int
    ): NodeDeletionActionSet {
      val actionSetBuilder =
        NodeDeletionActionSet.Builder("token slicer@$tokenCountToSlice")
      val endIndex = startIndex - tokenCountToSlice + 1
      check(endIndex >= 0) { endIndex }
      for (i in startIndex downTo endIndex) {
        assert(!tokenList[i].isPermanentlyDeleted) { tokenList[i] }
        actionSetBuilder.deleteNode(tokenList[i])
      }
      return actionSetBuilder.build()
    }
  }
}
