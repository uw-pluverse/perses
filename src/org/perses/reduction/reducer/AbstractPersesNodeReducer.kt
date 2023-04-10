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
package org.perses.reduction.reducer

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.partition.Partition
import org.perses.reduction.reducer.TreeTransformations.createNodeDeletionActionSetFor
import org.perses.reduction.reducer.TreeTransformations.findCompatibleDescendants
import org.perses.reduction.reducer.TreeTransformations.findCompatibleKleeneDescendantsForKleeneQuantifiedNode
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ChildHoistingAction
import org.perses.spartree.ChildHoistingActionSet
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Util.lazyAssert
import java.util.concurrent.Future

/** Perses reducer. The granularity is parse tree nodes, but not level-based.  */
abstract class AbstractPersesNodeReducer protected constructor(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractNodeReducer(reducerAnnotation, reducerContext) {

  protected val nodeReducerConfiguation =
    reducerContext.configuration.persesNodeReducerConfig

  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    return when (node.nodeType) {
      RuleType.KLEENE_PLUS -> reduceKleenePlus(tree, node)
      RuleType.KLEENE_STAR, RuleType.OPTIONAL -> reduceKleenStar(tree, node)
      RuleType.ALT_BLOCKS, RuleType.OTHER_RULE -> reduceRegularRule(tree, node)
      RuleType.TOKEN -> ImmutableList.of() // TODO: Do nothing.
    }
  }

  override fun requiresParsableTree() = true

  private fun reduceRegularRule(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    // TODO(cnsun): make testAllTreeEditsAndReturnTheBest take a list of futures.
    val editList = createEditListForRegularRuleNode(tree, regularRuleNode)
      .asSequence()
      .map { it.get() }
      .filterNotNull()
      .toList()
    val best = testAllTreeEditsAndReturnTheBest(editList)
      ?: return ImmutableList.copyOf(regularRuleNode.immutableChildView)
    val edit = best.edit
    tree.applyEdit(edit)
    return computePendingNodes(regularRuleNode, edit)
  }

  private fun createEditListForRegularRuleNode(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
  ): List<Future<AbstractSparTreeEdit<*>?>> {
    lazyAssert({ regularRuleNode.antlrRule!!.ruleDef.isParserRule }) {
      regularRuleNode.antlrRule!!.ruleDef
    }
    val childCount = regularRuleNode.childCount
    if (childCount == 0) {
      return emptyList()
    }
    val maxEditCount = nodeReducerConfiguation.maxEditCountForRegularRuleNode
    val editList = ArrayList<Future<AbstractSparTreeEdit<*>?>>(maxEditCount)
    if (canBeEpsilon(regularRuleNode)) {
      editList.add(
        asyncCreateTreeEdit {
          optionallyCreateDeletionEditAndLog(
            NodeDeletionActionSet.createByDeleteSingleNode(
              regularRuleNode,
              "[regular_node]can be epsilon",
            ),
            tree,
          )
        },
      )
    }
    findCompatibleKleeneDescendantsForKleeneQuantifiedNode(
      regularRuleNode,
      3,
    ).forEach {
      val action = ChildHoistingAction(targetNode = regularRuleNode, it)
      actionSetProfiler.onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant(action)
      editList.add(
        asyncCreateTreeEdit {
          optionallyCreateReplacementEditAndLog(
            ChildHoistingActionSet.createByReplacingSingleNode(
              action,
              "[regular_node]kleene replacement",
            ),
            tree,
          )
        },
      )
    }
    findCompatibleDescendants(
      currentNode = regularRuleNode,
      stopAtFirstCompatible = nodeReducerConfiguation.stopAtFirstCompatibleChildren,
      maxBfsDepth = nodeReducerConfiguation.maxBfsDepthForRegularRuleNode,
    ).forEach {
      val action = ChildHoistingAction(targetNode = regularRuleNode, replacingChild = it)
      actionSetProfiler.onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant(action)
      editList.add(
        asyncCreateTreeEdit {
          optionallyCreateReplacementEditAndLog(
            ChildHoistingActionSet.createByReplacingSingleNode(
              action,
              "[regular node]compatible replacement",
            ),
            tree,
          )
        },
      )
    }
    return editList
  }

  private inline fun asyncCreateTreeEdit(
    crossinline creator: () -> AbstractSparTreeEdit<*>?,
  ): Future<AbstractSparTreeEdit<*>?> {
    return executorService.submitGenericTask {
      val result = creator()
      result?.program // early compute the program.
      result
    }
  }

  /** Perform delta debugging.  */
  private fun reduceKleenStar(
    tree: SparTree,
    kleeneStar: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    val childCount = kleeneStar.childCount
    if (childCount == 0) {
      return ImmutableList.of()
    }
    // FIXME: the best program is not saved.
    performDelta(tree, "[kleene_star]dd", createPartition(kleeneStar, 0, childCount))
    return if (kleeneStar.isPermanentlyDeleted) {
      ImmutableList.of()
    } else {
      ImmutableList.copyOf(kleeneStar.immutableChildView)
    }
  }

  protected abstract fun performDelta(
    tree: SparTree,
    actionsDescription: String,
    vararg startPartitions: Partition,
  )

  private fun reduceKleenePlus(
    tree: SparTree,
    kleenePlus: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    val childCount = kleenePlus.childCount
    if (childCount == 0) {
      return ImmutableList.of()
    }
    val editList = ArrayList<AbstractSparTreeEdit<*>>()
    if (canBeEpsilon(kleenePlus)) {
      optionallyCreateDeletionEditAndLog(
        NodeDeletionActionSet.createByDeleteSingleNode(kleenePlus, "[kleene_plus]can be epsilon"),
        tree,
      )?.let { editList.add(it) }
    }
    if (childCount > 1) {
      val wholePartition = createPartition(kleenePlus, 1, childCount) // Skip the first.
      optionallyCreateDeletionEditAndLog(
        createNodeDeletionActionSetFor(
          wholePartition,
          "[kleene_plus]remove whole except first",
        ),
        tree,
      )?.let { editList.add(it) }
    }
    val best = testAllTreeEditsAndReturnTheBest(editList)
    if (best != null) {
      tree.applyEdit(best.edit)
      return computePendingNodes(kleenePlus, best.edit)
    }
    if (childCount > 1) {
      val halfIndex = (childCount + 1) / 2
      performDelta(
        tree,
        "[kleene_plus]dd",
        createPartition(kleenePlus, 0, halfIndex),
        createPartition(kleenePlus, halfIndex, childCount),
      )
    }
    return ImmutableList.copyOf(kleenePlus.immutableChildView)
  }

  object TreeNodeComparatorInLeafTokenCount : Comparator<AbstractSparTreeNode> {
    private val comparator = compareByDescending<AbstractSparTreeNode> { it.leafTokenCount }
      .thenByDescending { it.nodeId }

    override fun compare(o1: AbstractSparTreeNode, o2: AbstractSparTreeNode): Int {
      val result = comparator.compare(o1, o2)
      lazyAssert({ result != 0 }) { "Cannot guarantee determinism." }
      return result
    }
  }

  companion object {

    /**
     * Create a partition from the tree node, by including the children in the range [childIndexFrom,
     * childIndexTo)
     */
    @JvmStatic
    @VisibleForTesting
    fun createPartition(
      node: AbstractSparTreeNode,
      childIndexFrom: Int,
      childIndexTo: Int,
    ): Partition {
      lazyAssert({ childIndexFrom >= 0 }) { childIndexFrom }
      lazyAssert({ childIndexFrom < childIndexTo }) { "$childIndexFrom, $childIndexTo" }
      lazyAssert({ childIndexTo <= node.childCount }) {
        childIndexTo.toString() + ", " + node.childCount
      }
      val builder = Partition.Builder(childIndexTo - childIndexFrom)
      for (i in childIndexFrom until childIndexTo) {
        builder.addNode(node.getChild(i))
      }
      return builder.build()
    }
  }
}
