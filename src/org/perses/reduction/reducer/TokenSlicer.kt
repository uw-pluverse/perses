package org.perses.reduction.reducer

import com.google.common.annotations.VisibleForTesting
import org.perses.reduction.AbstractReducer
import org.perses.reduction.AbstractReductionEvent
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScript
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
        val cachedResult = queryCache.getCachedResult(treeEdit.program)
        if (cachedResult.isPresent) {
          assert(cachedResult.get().isFail) { "Only failed programs can be cached." }
          listenerManager.onTestResultCacheHit(cachedResult.get(), treeEdit.program, treeEdit)
          continue
        }
        if (!configuration.parserFacade.isSourceCodeParsable(treeEdit.program)) {
          cacheTestResult(
            treeEdit.program,
            TestScript.TestResult(exitCode = INVALID_SYNTAX_EXIT_CODE, elapsedMilliseconds = -1)
          )
          continue
        }
        val futureTestScriptExecutionTask = testProgramAsynchronously(treeEdit.program)
        val best = analyzeResultsAndGetBest(
          listOf(
            FutureExecutionResultInfo(
              treeEdit,
              treeEdit.program,
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
