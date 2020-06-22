package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.NodeDeletionActionSet
import org.perses.tree.spar.SparTree
import java.util.ArrayDeque

class TreeSlicer(
  reducerContext: ReducerContext
) : AbstractNodeReducer(META, reducerContext) {

  override fun createReductionQueue() =
    ArrayDeque<AbstractSparTreeNode>(DEFAULT_INITIAL_QUEUE_CAPACITY)

  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode
  ): ImmutableList<AbstractSparTreeNode> {
    val actionSet = NodeDeletionActionSet.createByDeleteSingleNode(node, NAME)

    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
      return node.copyAndReverseChildren()
    }
    val treeEdit = tree.createNodeDeletionEdit(actionSet)
    val testProgram = treeEdit.program
    val parserFacade = configuration.parserFacade
    if (!parserFacade.isSourceCodeParsable(testProgram.toCompactSourceCode())) {
      return node.copyAndReverseChildren()
    }
    val best = testAllTreeEditsAndReturnTheBest(ImmutableList.of(treeEdit))
    if (!best.isPresent) {
      return node.copyAndReverseChildren()
    } else {
      val edit = best.get().edit
      tree.applyEdit(edit)
      return computePendingNodes(node, edit).reverse()
    }
  }

  companion object {
    const val NAME = "tree_slicer"

    @JvmStatic
    val META = object : ReducerAnnotation() {
      override fun shortName() = NAME
      override fun description() = ""
      override fun create(reducerContext: ReducerContext) = TreeSlicer(reducerContext)
    }
  }
}
