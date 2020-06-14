package org.perses.reduction.reducer

import com.google.common.annotations.VisibleForTesting
import org.perses.reduction.AbstractReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.tree.spar.LexerRuleSparTreeNode
import org.perses.tree.spar.NodeDeletionActionSet
import org.perses.tree.spar.SparTree

class TokenSlicer(
  redcucerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  val minTokenCount: Int,
  val maxTokenCount: Int
) :
  AbstractReducer(redcucerAnnotation, reducerContext) {

  init {
    require(minTokenCount > 0 && minTokenCount <= maxTokenCount) {
      "Expecting: 0 < minTokenCount($minTokenCount) <= maxTokneCount($maxTokenCount)."
    }
  }

  // TODO: This algorithm need to be parallelized.
  override fun internalReduce(tree: SparTree) {
    for (tokenCountToSlice in maxTokenCount downTo minTokenCount) {
      var changed: Boolean
      do {
        changed = false
        val tokens = extractLexerRuleNodes(tree)
        for (startIndex in tokens.size - 1 downTo tokenCountToSlice - 1) {
          val nodeDeletionActionSet = createNodeDeletionActionSetReverse(
            tokens, startIndex, tokenCountToSlice
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
          val sourceCodeParsable = configuration.parserFacade.isSourceCodeParsable(treeEdit.program)
        }
      } while (changed)
    }
    TODO("Not yet implemented")
  }

  @VisibleForTesting
  fun createNodeDeletionActionSetReverse(
    tokenList: ArrayList<LexerRuleSparTreeNode>,
    startIndex: Int,
    tokenCountToSlice: Int
  ): NodeDeletionActionSet {
    val actionSetBuilder =
      NodeDeletionActionSet.Builder("token slicer@$tokenCountToSlice")
    val endIndex = startIndex - tokenCountToSlice + 1
    for (i in startIndex downTo endIndex) {
      actionSetBuilder.deleteNode(tokenList[i])
    }
    return actionSetBuilder.build()
  }

  @VisibleForTesting
  fun extractLexerRuleNodes(tree: SparTree): ArrayList<LexerRuleSparTreeNode> {
    val tokens = ArrayList<LexerRuleSparTreeNode>()
    tree.visitRemainingTokens({ tokens.add(it) })
    return tokens
  }
}
