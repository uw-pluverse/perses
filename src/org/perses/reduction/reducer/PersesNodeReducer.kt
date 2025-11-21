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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.TreeTransformations.findCompatibleDescendants
import org.perses.reduction.reducer.TreeTransformations.findCompatibleKleeneDescendantsForKleeneQuantifiedNode
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractSparTreeNode.Companion.canBeEpsilon
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeReplacementAction
import org.perses.spartree.NodeReplacementActionSet
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.Util.lazyAssert
import org.perses.util.ktFine
import org.perses.util.toImmutableList

/** Perses reducer. The granularity is parse tree nodes, but not level-based.  */
open class PersesNodeReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  reductionQueueStrategy: IReductionQueueStrategy,
) : AbstractNodeReducer(
    reducerAnnotation = reducerAnnotation,
    reducerContext = reducerContext,
    reductionQueueStrategy = reductionQueueStrategy,
    requiresParsableTree = true,
  ) {
  protected val nodeReducerConfiguation =
    reducerContext.configuration.persesNodeReducerConfig

  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> =
    when (node) {
      is LexerRuleSparTreeNode -> ImmutableList.of()
      is ParserRuleSparTreeNode ->
        when (node.ruleType) {
          RuleType.KLEENE_PLUS -> reduceKleenePlus(tree, node, fixpointReductionState)
          RuleType.KLEENE_STAR, RuleType.OPTIONAL ->
            reduceKleeneStar(
              tree,
              node,
              fixpointReductionState,
            )
          RuleType.ALT_BLOCKS, RuleType.OTHER_RULE -> reduceRegularRule(tree, node)
          else -> error("unhandled type: ${node.ruleType}")
        }

      else -> error("unhandled type: ${node::class}")
    }

  private fun reduceRegularRule(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    // TODO(cnsun): make testAllTreeEditsAndReturnTheBest take a list of futures.
    logger.ktFine {
      "The node has ${regularRuleNode.leafTokenCount} tokens under."
    }
    val editList =
      createEditListForRegularRuleNode(tree, regularRuleNode).toList()
    val best =
      testAllTreeEditsAndReturnTheBest(editList)
        ?: return ImmutableList.copyOf(regularRuleNode.immutableChildView)
    val edit = best.edit
    tree.applyEdit(edit)
    return computePendingNodes(regularRuleNode, edit)
  }

  private fun createEditListForRegularRuleNode(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
  ): List<AbstractSparTreeEdit<*>> {
    lazyAssert({ regularRuleNode.antlrRule!!.ruleDef.isParserRule }) {
      regularRuleNode.antlrRule!!.ruleDef
    }
    val childCount = regularRuleNode.childCount
    if (childCount == 0) {
      return emptyList()
    }
    val maxEditCount = nodeReducerConfiguation.maxEditCountForRegularRuleNode
    val result = java.util.ArrayList<AbstractSparTreeEdit<*>>(maxEditCount)
    if (canBeEpsilon(regularRuleNode)) {
      // This should be the best edit that can delete the most tokens.
      val edit =
        optionallyCreateDeletionEditAndLog(
          NodeDeletionActionSet.createByDeleteSingleNode(
            regularRuleNode,
            "[regular_node]can be epsilon",
          ),
          tree,
        )
      if (edit != null) {
        result.add(edit)
        if (result.size >= maxEditCount) {
          return result
        }
      }
    }
    val actionSetProfiler = reducerContext.actionSetProfiler
    findCompatibleKleeneDescendantsForKleeneQuantifiedNode(
      kleeneQuantifiedCurrentNode = regularRuleNode,
      maxBfsDepth = 3,
    ).forEach { replacement ->
      val action =
        NodeReplacementAction(targetNode = regularRuleNode, replacingNode = replacement)
      actionSetProfiler.onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant(action)
      val edit =
        optionallyCreateReplacementEditAndLog(
          NodeReplacementActionSet.createByReplacingSingleNode(
            action,
            "[regular_node]kleene replacement",
          ),
          tree,
        )
      if (edit != null) {
        result.add(edit)
        if (result.size >= maxEditCount) {
          return result
        }
      }
    }
    findCompatibleDescendants(
      currentNode = regularRuleNode,
      stopAtFirstCompatible = nodeReducerConfiguation.stopAtFirstCompatibleChildren,
      maxBfsDepth = nodeReducerConfiguation.maxBfsDepthForRegularRuleNode,
    ).forEach {
      val action = NodeReplacementAction(targetNode = regularRuleNode, replacingNode = it)
      actionSetProfiler.onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant(action)
      val edit =
        optionallyCreateReplacementEditAndLog(
          NodeReplacementActionSet.createByReplacingSingleNode(
            action,
            "[regular node]compatible replacement",
          ),
          tree,
        )
      if (edit != null) {
        result.add(edit)
        if (result.size >= maxEditCount) {
          return result
        }
      }
    }

    return result
  }

  /** Perform delta debugging.  */
  private fun reduceKleeneStar(
    tree: SparTree,
    kleeneStar: AbstractSparTreeNode,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> {
    val childCount = kleeneStar.childCount
    if (childCount == 0) {
      return ImmutableList.of()
    }
    runListMinimizerOverNodes(
      tree = tree,
      fixpointReductionState = fixpointReductionState,
      input = kleeneStar.immutableChildView.toImmutableList(),
      actionsDescriptionPostfix = "[kleene_star:${kleeneStar.ruleName}]",
    )
    return if (kleeneStar.isPermanentlyDeleted) {
      ImmutableList.of()
    } else {
      ImmutableList.copyOf(kleeneStar.immutableChildView)
    }
  }

  private fun reduceKleenePlus(
    tree: SparTree,
    kleenePlus: AbstractSparTreeNode,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> {
    val childCount = kleenePlus.childCount
    if (childCount == 0) {
      return ImmutableList.of()
    }
    val kleeneActionSetPrefix = "[kleene_plus:${kleenePlus.ruleName}]"
    val editList = ArrayList<AbstractSparTreeEdit<*>>()
    if (canBeEpsilon(kleenePlus)) {
      optionallyCreateDeletionEditAndLog(
        NodeDeletionActionSet.createByDeleteSingleNode(
          kleenePlus,
          "${kleeneActionSetPrefix}can be epsilon",
        ),
        tree,
      )?.let { editList.add(it) }
    }
    if (childCount > 1) {
      // Skip the first element
      val wholePartition = kleenePlus.immutableChildView.drop(1).toImmutableList()
      optionallyCreateDeletionEditAndLog(
        NodeDeletionActionSet
          .Builder(
            "${kleeneActionSetPrefix}remove whole except first",
          ).deleteNodes(wholePartition)
          .build(),
        tree,
      )?.let { editList.add(it) }
    }
    val best = testAllTreeEditsAndReturnTheBest(editList)
    if (best != null) {
      tree.applyEdit(best.edit)
      return computePendingNodes(kleenePlus, best.edit)
    }
    if (childCount > 1) {
      runListMinimizerOverNodes(
        // Cannot delete all elements at once as this is kleene-plus.
        tree = tree,
        fixpointReductionState = fixpointReductionState,
        input = kleenePlus.immutableChildView.toImmutableList(),
        actionsDescriptionPostfix = kleeneActionSetPrefix,
      )
    }
    return ImmutableList.copyOf(kleenePlus.immutableChildView)
  }
}
