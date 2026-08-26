/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.TreeTransformations.findCompatibleDescendants
import org.perses.reduction.reducer.TreeTransformations.findCompatibleKleeneDescendantsForKleeneQuantifiedNode
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ContextDescription
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeReplacementAction
import org.perses.spartree.NodeReplacementActionSet
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.TreeNodeFilterResult.CONTINUE
import org.perses.util.ktFine
import org.perses.util.lazyAssert
import org.perses.util.toImmutableList

/** Perses reducer. The granularity is parse tree nodes, but not level-based.  */
open class PersesNodeReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  reductionQueueStrategy: IReductionQueueStrategy,
  // These two are constructor values rather than subclass overrides so that specialized node reducers
  // (the BFS variants, Dyck) stay concrete classes -- an anonymous `object :` subclass has a null
  // KClass.simpleName, which the list minimizer dereferences with `!!`.
  //
  // The list minimizer to reduce node lists with, or null to keep the configured default.
  private val defaultListMinimizerType: EnumListMinimizerType? = null,
  // The facade to reparse under before reducing (e.g. a Dyck facade), or null to reduce on the
  // canonical tree.
  private val preferredParserFacade: AbstractParserFacade? = null,
) : AbstractNodeReducer(
    reducerAnnotation = reducerAnnotation,
    reducerContext = reducerContext,
    reductionQueueStrategy = reductionQueueStrategy,
  ) {
  override fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    defaultListMinimizerType ?: super.computeDefaultListMinimizerType()

  override fun getPreferredParserFacade(): AbstractParserFacade? = preferredParserFacade

  override fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): List<AbstractSparTreeNode> {
    if (node.isTokenNode()) {
      return ImmutableList.of()
    }
    check(node is ParserRuleSparTreeNode) {
      "Unhandled node type: ${node::class}"
    }

    return try {
      when (node.ruleType) {
        RuleType.KLEENE_PLUS -> {
          if (persesConfig.enableReducingKleeneOptionalNode) {
            reduceKleenePlus(
              tree,
              kleenePlusNode = node,
              semanticsProvider = semanticsProvider,
              fixpointReductionState,
            )
          } else {
            node.immutableChildView
          }
        }

        RuleType.KLEENE_STAR, RuleType.OPTIONAL -> {
          if (persesConfig.enableReducingKleeneOptionalNode) {
            reduceKleeneStar(
              tree,
              kleeneStarNode = node,
              semanticsProvider = semanticsProvider,
              fixpointReductionState,
            )
          } else {
            node.immutableChildView
          }
        }

        RuleType.ALT_BLOCKS, RuleType.OTHER_RULE -> {
          if (persesConfig.enableReducingRegularRuleNode) {
            reduceRegularRuleNode(
              tree,
              regularRuleNode = node,
              semanticsProvider,
              fixpointReductionState,
            )
          } else {
            node.immutableChildView
          }
        }

        else -> {
          error("unhandled type: ${node.ruleType}")
        }
      }
    } catch (e: Exception) {
      throw RuntimeException(
        """
        | The node being reduced is ${node.nodeId}
        |${node.printTreeStructure()} 
        """.trimMargin(),
        e,
      )
    }
  }

  private fun reduceRegularRuleNode(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> {
    // TODO(cnsun): make testAllTreeEditsAndReturnTheBest take a list of futures.
    //      Followup: why do we want to have this design to make it accept futures?
    // The good thing about returning a list of futures is that the success rate of compatible
    // replacement and "can be epsilon" is high, amounts for the most successful operation
    // in perses.
    logger.ktFine {
      "The node has ${regularRuleNode.leafTokenCount} tokens under."
    }
    val editList =
      createEditListForRegularRuleNode(
        tree,
        regularRuleNode,
        semanticsProvider,
        fixpointReductionState,
      ).toList()
    val best =
      testAllTreeEditsAndReturnTheBest(editList)
        ?: return ImmutableList.copyOf(regularRuleNode.immutableChildView)
    val edit = best.edit
    applyEditToTree(payload = best)
    return computePendingNodes(regularRuleNode, edit)
  }

  /**
   * TODO(cnsun): this needs testing.
   */
  protected open fun createEditListForRegularRuleNode(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): List<AbstractSparTreeEdit<*>> =
    createEditListForRegularRuleNodeInternal(
      tree = tree,
      regularRuleNode = regularRuleNode,
      semanticsProvider = semanticsProvider,
      fixpointReductionState = fixpointReductionState,
      isNodeDeletable = { true },
      isReplacementValid = { _, _ -> true },
      subtreeEarlyStopCriterion = { CONTINUE },
    )

  protected fun createEditListForRegularRuleNodeInternal(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
    isNodeDeletable: (AbstractSparTreeNode) -> Boolean,
    isReplacementValid: (AbstractSparTreeNode, AbstractSparTreeNode) -> Boolean,
    subtreeEarlyStopCriterion: (AbstractSparTreeNode) -> org.perses.spartree.TreeNodeFilterResult,
  ): List<AbstractSparTreeEdit<*>> {
    lazyAssert(
      test = { regularRuleNode.antlrRule!!.ruleDef.isParserRule },
      message = { regularRuleNode.antlrRule!!.ruleDef },
    )
    if (regularRuleNode.childCount == 0) {
      return emptyList()
    }
    val maxEditCount = persesConfig.maxEditCountForRegularRuleNode
    val result = java.util.ArrayList<AbstractSparTreeEdit<*>>(maxEditCount)
    if (regularRuleNode.canBeEpsilon() && isNodeDeletable(regularRuleNode)) {
      // This should be the best edit that can delete the most tokens.
      val edit =
        optionallyCreateDeletionEditAndLog(
          actionSet =
            NodeDeletionActionSet.createByDeleteSingleNode(
              regularRuleNode,
              contextDescription = "[regular_node]can be epsilon",
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

    if (persesConfig.enableLiteralReplacementForRegularRuleNode &&
      isNodeDeletable(regularRuleNode)
    ) {
      createTreeEditForLiteralReplacement(
        tree,
        allNodesToBeDeleted = ImmutableList.of(regularRuleNode),
        actionSetDescriptionPrefix = "[regular_node]literal replacement:",
        fixpointReductionState,
      )?.let { edit ->
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
      subtreeEarlyStopCriterion = subtreeEarlyStopCriterion,
    ).forEach { replacement ->
      if (!isReplacementValid(regularRuleNode, replacement)) {
        return@forEach
      }
      // TODO(cnsun): need to consider whether the semantic tokens are affected. If the important
      //    semantic tokens are deleted, we should be careful whether we should proceed with the
      //    replacement.
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
      stopAtFirstCompatible = persesConfig.stopAtFirstCompatibleChildren,
      maxBfsDepth = persesConfig.maxBfsDepthForRegularRuleNode,
      subtreeEarlyStopCriterion = subtreeEarlyStopCriterion,
    ).forEach { replacement ->
      if (!isReplacementValid(regularRuleNode, replacement)) {
        return@forEach
      }
      val action = NodeReplacementAction(targetNode = regularRuleNode, replacingNode = replacement)
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

  private fun reduceKleeneStar(
    tree: SparTree,
    kleeneStarNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> {
    val childCount = kleeneStarNode.childCount
    if (childCount == 0) {
      return ImmutableList.of()
    }
    minimizeList(semanticsProvider, kleeneStarNode, tree, fixpointReductionState)

    return if (kleeneStarNode.isPermanentlyDeleted) {
      ImmutableList.of()
    } else {
      ImmutableList.copyOf(kleeneStarNode.immutableChildView)
    }
  }

  protected open fun minimizeList(
    semanticsProvider: ISemanticsProvider?,
    kleeneNode: AbstractSparTreeNode,
    tree: SparTree,
    fixpointReductionState: FixpointReductionState,
  ) {
    val commonPostfix = createCommonActionDescriptionPostfix(kleeneNode)
    // This is Perses only, with Mimir disabled (no semantic information is provided).
    // Just use the regular way to reduce the nodes.
    runListMinimizerOverNodes(
      needToTestEmpty = true,
      tree = tree,
      fixpointReductionState = fixpointReductionState,
      input = kleeneNode.immutableChildView.toImmutableList(),
      actionsDescriptionPostfix = commonPostfix,
    )
  }

  protected fun createCommonActionDescriptionPostfix(
    kleeneNode: AbstractSparTreeNode,
  ): ContextDescription {
    val nodeType =
      when {
        kleeneNode.isKleenePlusRuleNode -> "kleene_plus"
        kleeneNode.isKleeneStarRuleNode -> "kleene_star"
        kleeneNode.isOptionalRuleNode -> "optional"
        else -> "unknown"
      }
    return ContextDescription.of(
      ImmutableList.of(nodeType, kleeneNode.ruleName ?: "<null-rule-name>"),
    )
  }

  protected open fun reduceKleenePlus(
    tree: SparTree,
    kleenePlusNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> =
    reduceKleenePlusInternal(
      tree = tree,
      kleenePlusNode = kleenePlusNode,
      semanticsProvider = semanticsProvider,
      fixpointReductionState = fixpointReductionState,
      locallyUsedNodes = kleenePlusNode.immutableChildView,
      isNodeDeletable = { true },
    )

  protected fun reduceKleenePlusInternal(
    tree: SparTree,
    kleenePlusNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
    locallyUsedNodes: Collection<AbstractSparTreeNode>,
    isNodeDeletable: (AbstractSparTreeNode) -> Boolean,
  ): ImmutableList<AbstractSparTreeNode> {
    if (kleenePlusNode.childCount == 0) {
      return ImmutableList.of()
    }
    val kleeneActionSetPrefix = "[kleene_plus:${kleenePlusNode.ruleName}]"
    val editList = ArrayList<AbstractSparTreeEdit<*>>()
    if (kleenePlusNode.canBeEpsilon()) {
      val message = kleeneActionSetPrefix + "can be epsilon"
      val actionSet =
        if (isNodeDeletable(kleenePlusNode)) {
          NodeDeletionActionSet.createByDeleteSingleNode(
            kleenePlusNode,
            contextDescription = message,
          )
        } else if (locallyUsedNodes.isNotEmpty()) {
          val ratio = "$({locallyUsedNodes.size}/${kleenePlusNode.childCount})"
          NodeDeletionActionSet.createByDeletingNodes(
            nodes = locallyUsedNodes,
            contextDescription =
              "$message (only locally used nodes, $ratio)",
          )
        } else {
          null
        }
      if (actionSet != null) {
        optionallyCreateDeletionEditAndLog(actionSet, tree)?.let { editList.add(it) }
      }
    }
    if (kleenePlusNode.childCount > 1 && locallyUsedNodes.isNotEmpty()) {
      // TODO(cnsun): need to experiment whether we can iterate through the list, and delete
      //   the complement of each element.
      val (wholePartition, descriptSuffix) =
        if (locallyUsedNodes.size == kleenePlusNode.childCount) {
          // Skip the first element, as the first does not fail semantics, such as var def.
          kleenePlusNode.immutableChildView.let {
            it.subList(
              1,
              it.size,
            )
          } to "all except first"
        } else {
          locallyUsedNodes to "locally used nodes"
        }

      check(wholePartition.isNotEmpty()) { "The whole partition is empty." }
      optionallyCreateDeletionEditAndLog(
        actionSet =
          NodeDeletionActionSet
            .Builder(
              "${kleeneActionSetPrefix}remove $descriptSuffix",
            ).deleteNodes(wholePartition)
            .build(),
        tree = tree,
      )?.let { editList.add(it) }
    }
    val best = testAllTreeEditsAndReturnTheBest(editList)
    if (best != null) {
      applyEditToTree(payload = best)
    }
    kleenePlusNode.immutableChildView.let { children ->
      if (children.isNotEmpty()) {
        minimizeList(
          semanticsProvider,
          kleenePlusNode,
          tree,
          fixpointReductionState,
        )
      }
    }
    return ImmutableList.copyOf(kleenePlusNode.immutableChildView)
  }
}
