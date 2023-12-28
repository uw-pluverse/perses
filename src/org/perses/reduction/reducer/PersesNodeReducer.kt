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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.delta.AbstractDeltaDebugger
import org.perses.delta.AbstractDeltaDebugger.Arguments
import org.perses.delta.DeltaDebuggerFactory
import org.perses.delta.EnumDeltaDebuggerType
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.SparTreeDdminPayload
import org.perses.reduction.reducer.PersesNodeReducer.IDeltaDebuggerStrategy.SelectableDeltaDebuggerStrategy
import org.perses.reduction.reducer.TreeTransformations.findCompatibleDescendants
import org.perses.reduction.reducer.TreeTransformations.findCompatibleKleeneDescendantsForKleeneQuantifiedNode
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ChildHoistingActionSet
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeReplacementAction
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.Util.lazyAssert
import org.perses.util.toImmutableList
import java.util.concurrent.Future

/** Perses reducer. The granularity is parse tree nodes, but not level-based.  */
open class PersesNodeReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  reductionQueueStrategy: IReductionQueueStrategy,
  private val deltaDebuggerStrategy: IDeltaDebuggerStrategy = SelectableDeltaDebuggerStrategy {
    reducerContext.configuration.defaultDeltaDebuggerTypeForKleene
  },
) : AbstractNodeReducer(
  reducerAnnotation,
  reducerContext,
  reductionQueueStrategy,
  requiresParsableTree = true,
) {

  protected val nodeReducerConfiguation =
    reducerContext.configuration.persesNodeReducerConfig

  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    return when (node) {
      is LexerRuleSparTreeNode -> ImmutableList.of()
      is ParserRuleSparTreeNode -> when (node.ruleType) {
        RuleType.KLEENE_PLUS -> reduceKleenePlus(tree, node)
        RuleType.KLEENE_STAR, RuleType.OPTIONAL -> reduceKleenStar(tree, node)
        RuleType.ALT_BLOCKS, RuleType.OTHER_RULE -> reduceRegularRule(tree, node)
        else -> error("unhandled type: ${node.ruleType}")
      }
      else -> error("unhandled type: ${node::class}")
    }
  }

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
      val action = NodeReplacementAction(targetNode = regularRuleNode, it)
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
      val action = NodeReplacementAction(targetNode = regularRuleNode, replacingNode = it)
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
    performDelta(
      needToTestEmpty = true,
      tree,
      "[kleene_star:${kleeneStar.ruleName}]",
      kleeneStar.immutableChildView.toImmutableList(),
    )
    return if (kleeneStar.isPermanentlyDeleted) {
      ImmutableList.of()
    } else {
      ImmutableList.copyOf(kleeneStar.immutableChildView)
    }
  }

  private fun performDelta(
    needToTestEmpty: Boolean,
    tree: SparTree,
    actionsDescription: String,
    nodes: ImmutableList<AbstractSparTreeNode>,
  ) {
    require(nodes.isNotEmpty())
    val arguments = createDeltaArguments(
      needToTestEmpty,
      tree,
      actionsDescription,
      nodes,
    )
    val deltaDebugger = deltaDebuggerStrategy.createDeltaDebugger(arguments)
    deltaDebugger.reduce()
  }

  private fun reduceKleenePlus(
    tree: SparTree,
    kleenePlus: AbstractSparTreeNode,
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
        NodeDeletionActionSet.Builder(
          "${kleeneActionSetPrefix}remove whole except first",
        ).deleteNodes(wholePartition).build(),
        tree,
      )?.let { editList.add(it) }
    }
    val best = testAllTreeEditsAndReturnTheBest(editList)
    if (best != null) {
      tree.applyEdit(best.edit)
      return computePendingNodes(kleenePlus, best.edit)
    }
    if (childCount > 1) {
      performDelta(
        needToTestEmpty = false, // Cannot delete all elements at once as this is kleene-plus.
        tree,
        kleeneActionSetPrefix,
        kleenePlus.immutableChildView.toImmutableList(),
      )
    }
    return ImmutableList.copyOf(kleenePlus.immutableChildView)
  }
  fun interface IDeltaDebuggerStrategy {
    fun createDeltaDebugger(
      args: Arguments<AbstractSparTreeNode, SparTreeDdminPayload>,
    ): AbstractDeltaDebugger<AbstractSparTreeNode, SparTreeDdminPayload>

    class SelectableDeltaDebuggerStrategy(
      val typeProvider: () -> EnumDeltaDebuggerType,
    ) : IDeltaDebuggerStrategy {
      override fun createDeltaDebugger(
        args: Arguments<AbstractSparTreeNode, SparTreeDdminPayload>,
      ): AbstractDeltaDebugger<AbstractSparTreeNode, SparTreeDdminPayload> {
        return DeltaDebuggerFactory.create(typeProvider.invoke(), args)
      }
    }

    class SimpleDeltaDebuggerStrategy(
      val type: EnumDeltaDebuggerType,
    ) : IDeltaDebuggerStrategy {
      override fun createDeltaDebugger(
        args: Arguments<AbstractSparTreeNode, SparTreeDdminPayload>,
      ): AbstractDeltaDebugger<AbstractSparTreeNode, SparTreeDdminPayload> {
        return DeltaDebuggerFactory.create(type, args)
      }
    }
  }
}
