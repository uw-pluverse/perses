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
import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.partition.Partition
import org.perses.reduction.reducer.TreeTransformations.createNodeDeletionActionSetFor
import org.perses.reduction.reducer.TreeTransformations.replaceKleeneQualifiedNodeWithKleeneQualifiedChildren
import org.perses.reduction.reducer.TreeTransformations.replaceNodeWithNearestCompatibleChildren
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.ChildHoistingAction
import org.perses.tree.spar.ChildHoistingActionSet
import org.perses.tree.spar.NodeDeletionActionSet
import org.perses.tree.spar.SparTree
import java.util.ArrayList
import java.util.Comparator

/** Perses reducer. The granularity is parse tree nodes, but not level-based.  */
abstract class AbstractPersesNodeReducer protected constructor(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext
) : AbstractNodeReducer(reducerAnnotation, reducerContext) {

  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode
  ): ImmutableList<AbstractSparTreeNode> {
    return when (node.nodeType) {
      RuleType.KLEENE_PLUS -> reduceKleenePlus(tree, node)
      RuleType.KLEENE_STAR, RuleType.OPTIONAL -> reduceKleenStar(tree, node)
      RuleType.OTHER_RULE -> reduceRegularRule(tree, node)
      RuleType.TOKEN -> // TODO: Do nothing.
        ImmutableList.of()
      else -> throw AssertionError("Unhandled node type: $node")
    }
  }

  private fun reduceRegularRule(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode
  ): ImmutableList<AbstractSparTreeNode> {
    val editList = createEditListForRegularRuleNode(tree, regularRuleNode)
    val best = testAllTreeEditsAndReturnTheBest(editList)
    if (!best.isPresent) {
      return ImmutableList.copyOf(regularRuleNode.immutableChildView)
    }
    val edit = best.get().edit
    tree.applyEdit(edit)
    return computePendingNodes(regularRuleNode, edit)
  }

  private fun createEditListForRegularRuleNode(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode
  ): List<AbstractSparTreeEdit> {
    assert(regularRuleNode.antlrRule.get().ruleDef.isParserRule)
    val childCount = regularRuleNode.childCount
    if (childCount == 0) {
      return emptyList()
    }
    val maxEditCount = 100
    val editList = ArrayList<AbstractSparTreeEdit>(maxEditCount)
    if (canBeEpsilon(regularRuleNode)) {
      addDeletionEditToEditListAndLog(
        NodeDeletionActionSet.createByDeleteSingleNode(
          regularRuleNode, "[regular_node]can be epsilon"
        ),
        editList,
        tree
      )
    }
    val kleeneReplacements = replaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
      regularRuleNode, 3
    )
    actionSetProfiler.onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
      kleeneReplacements
    )
    for (action in kleeneReplacements) {
      addEditToEditListAndLog(
        ChildHoistingActionSet.createByReplacingSingleNode(
          action, "[regular_node]kleene replacement"
        ),
        editList,
        tree
      )
    }
    val compatibleReplacements = replaceNodeWithNearestCompatibleChildren(regularRuleNode, 5)
    actionSetProfiler.onReplaceNodeWithNearestCompatibleChildren(compatibleReplacements)
    val remainingQuota = maxEditCount - editList.size
    if (remainingQuota > 0) {
      compatibleReplacements.stream()
        .limit(remainingQuota.toLong())
        .forEach { action: ChildHoistingAction? ->
          addEditToEditListAndLog(
            ChildHoistingActionSet.createByReplacingSingleNode(
              action, "[regular node]compatible replacement"
            ),
            editList,
            tree
          )
        }
    }
    return editList
  }

  /** Perform delta debugging.  */
  private fun reduceKleenStar(
    tree: SparTree,
    kleeneStar: AbstractSparTreeNode
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
    vararg startPartitions: Partition
  )

  private fun reduceKleenePlus(
    tree: SparTree,
    kleenePlus: AbstractSparTreeNode
  ): ImmutableList<AbstractSparTreeNode> {
    val childCount = kleenePlus.childCount
    if (childCount == 0) {
      return ImmutableList.of()
    }
    val editList = ArrayList<AbstractSparTreeEdit>()
    if (canBeEpsilon(kleenePlus)) {
      addDeletionEditToEditListAndLog(
        NodeDeletionActionSet.createByDeleteSingleNode(kleenePlus, "[kleene_plus]can be epsilon"),
        editList,
        tree
      )
    }
    if (childCount > 1) {
      val wholePartition = createPartition(kleenePlus, 1, childCount) // Skip the first.
      addDeletionEditToEditListAndLog(
        createNodeDeletionActionSetFor(
          wholePartition, "[kleene_plus]remove whole except first"
        ),
        editList,
        tree
      )
    }
    val best = testAllTreeEditsAndReturnTheBest(editList)
    if (best.isPresent) {
      val (edit) = best.get()
      tree.applyEdit(edit)
      return computePendingNodes(kleenePlus, edit)
    }
    if (childCount > 1) {
      val halfIndex = (childCount + 1) / 2
      performDelta(
        tree,
        "[kleene_plus]dd",
        createPartition(kleenePlus, 0, halfIndex),
        createPartition(kleenePlus, halfIndex, childCount)
      )
    }
    return ImmutableList.copyOf(kleenePlus.immutableChildView)
  }

  protected enum class TreeNodeComparatorInLeafTokenCount : Comparator<AbstractSparTreeNode> {
    SINGLETON;

    override fun compare(o1: AbstractSparTreeNode, o2: AbstractSparTreeNode): Int {
      val tokenCountCmpResult = o2.leafTokenCount.compareTo(o1.leafTokenCount)
      if (tokenCountCmpResult != 0) {
        return tokenCountCmpResult
      }
      // For determinism.
      val result = o2.nodeId.compareTo(o1.nodeId)
      assert(result != 0) { "Cannot guarantee determinism." }
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
      childIndexTo: Int
    ): Partition {
      assert(childIndexFrom >= 0) { childIndexFrom }
      assert(childIndexFrom < childIndexTo) { "$childIndexFrom, $childIndexTo" }
      assert(childIndexTo <= node.childCount) { childIndexTo.toString() + ", " + node.childCount }
      val builder = Partition.Builder(childIndexTo - childIndexFrom)
      for (i in childIndexFrom until childIndexTo) {
        builder.addNode(node.getChild(i))
      }
      return builder.build()
    }
  }
}
