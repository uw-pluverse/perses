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
import com.google.common.collect.ImmutableSet
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.TreeNodeFilterResult
import org.perses.spartree.TreeNodeFilterResult.CONTINUE
import org.perses.spartree.TreeNodeFilterResult.STOP
import org.perses.util.SimpleQueue
import kotlin.sequences.forEach

class MimirNodeReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  reductionQueueStrategy: IReductionQueueStrategy,
) : PersesNodeReducer(reducerAnnotation, reducerContext, reductionQueueStrategy) {
  protected val mimirConfig = reducerContext.configuration.mimirConfig
  private val mimirStrategy = MimirStrategyFactory.create(mimirConfig.mimirReductionAlgorithm)

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    super.internalReduce(fixpointReductionState)
    val listenerManager = reducerContext.listenerManager
    val tree = fixpointReductionState.inputRepresentation.tree
    val semanticsProvider = fixpointReductionState.inputRepresentation.semantics
    if (mimirConfig.enableBottomUpReductionAfterMainReductionLoop &&
      semanticsProvider != null
    ) {
      reduceFromLeavesWithZeroedOutDegreeToRoot(
        fixpointReductionState,
        tree,
        listenerManager,
        semanticsProvider,
      )
    }
  }

  private fun collectNodesToFurtherReduceNodesWithZeroedOutDegree(
    semanticsProvider: ISemanticsProvider,
    listenerManager: AsyncReductionListenerManager,
    fixpointReductionState: FixpointReductionState,
  ): Set<AbstractSparTreeNode> {
    val affectedNodesBasedOnDeps = semanticsProvider.computedAffectedDefinitionNodes()
    val nodesWithOutDegreeZeroed =
      ImmutableSet.copyOf(
        affectedNodesBasedOnDeps.nodesOutDegreeZeroed,
      )
    listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        val size = nodesWithOutDegreeZeroed.size
        val nodeIdList =
          if (size == 0) {
            ""
          } else {
            " " + nodesWithOutDegreeZeroed.map { it.nodeId }.sorted().toString()
          }
        buildString {
          append("After the main reduction process:")
          append(" $size nodes$nodeIdList have 0 out-degree; ")
          append("${affectedNodesBasedOnDeps.nodesOutDegreeReduced.size}")
          append(" nodes have reduced out-degree.")
          append(" ${affectedNodesBasedOnDeps.numOfNodesWithUnchangedOutDegree} nodes unchanged.")
        }
      },
    )
    return nodesWithOutDegreeZeroed
  }

  private fun reduceFromLeavesWithZeroedOutDegreeToRoot(
    fixpointReductionState: FixpointReductionState,
    tree: SparTree,
    listenerManager: AsyncReductionListenerManager,
    semanticsProvider: ISemanticsProvider,
  ) {
    val maxBottomUpReductionDepth =
      reducerContext
        .configuration.mimirConfig.bottomUpReductionMaxDepth
    var previousCandidates = setOf<AbstractSparTreeNode>()
    while (true) {
      val currentCandidates =
        collectNodesToFurtherReduceNodesWithZeroedOutDegree(
          semanticsProvider,
          listenerManager,
          fixpointReductionState,
        )
      val candidates = currentCandidates.minus(previousCandidates)
      if (candidates.isEmpty()) {
        break
      }
      val queue =
        SimpleQueue<CandidateWithDepth>().apply {
          candidates.forEach { candidate ->
            add(CandidateWithDepth(node = candidate, depth = 1))
          }
        }
      val visited =
        mutableSetOf<AbstractSparTreeNode>().apply {
          addAll(candidates)
        }
      while (queue.isNotEmpty()) {
        val candidate = queue.remove()
        if (candidate.node.isPermanentlyDeleted) {
          continue
        }
        var parent =
          candidate.node.parent
            ?: error("No parent for node. \n" + candidate.node.printTreeStructure())
        reduceOneNodeWithBoilerplateAndGetPendingNodes(
          fixpointReductionState,
          tree,
          candidate.node,
          listenerManager,
          semanticsProvider,
          queueSize = queue.size,
        )
        // TODO(cnsun): the number 5 here needs to be parameterized.
        if (candidate.depth > maxBottomUpReductionDepth) {
          // Stop the bottom-up traversal at certain depth.
          continue
        }
        while (parent.leafNodeSequence().none() && !parent.isRootNode()) {
          parent = parent.parent ?: error("No parent for node. \n" + parent.printTreeStructure())
        }
        if (!parent.isRootNode() && visited.add(parent)) {
          queue.add(CandidateWithDepth(node = parent, depth = candidate.depth + 1))
        }
      }
      previousCandidates = currentCandidates
    }
  }

  internal data class CandidateWithDepth(
    val node: AbstractSparTreeNode,
    val depth: Int,
  )

  override fun createEditListForRegularRuleNode(
    tree: SparTree,
    regularRuleNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): List<AbstractSparTreeEdit<*>> {
    val dependencyGraph =
      if (mimirConfig.enableMimirForRegularRuleNodes) {
        semanticsProvider?.buildScopedDependencyGraph(listOf(regularRuleNode))
      } else {
        null
      }

    val defTokensUsedExternally =
      dependencyGraph?.getDefTokensUsedExternally(
        ownerTreeNode = regularRuleNode,
      )

    val subtreeEarlyStopCriterion =
      if (dependencyGraph == null ||
        !mimirConfig.enableMimirForRegularRuleNodes ||
        defTokensUsedExternally.isNullOrEmpty()
      ) {
        { _: AbstractSparTreeNode -> CONTINUE }
      } else {
        fun(subtree: AbstractSparTreeNode): TreeNodeFilterResult {
          val semanticTokensUnderTheReplacementNode =
            semanticsProvider!!.getSemanticTokensUnderTreeNode(
              subtree,
            )
          for (defToken in defTokensUsedExternally) {
            if (defToken !in semanticTokensUnderTheReplacementNode) {
              return STOP
            }
          }
          return CONTINUE
        }
      }

    return createEditListForRegularRuleNodeInternal(
      tree = tree,
      regularRuleNode = regularRuleNode,
      semanticsProvider = semanticsProvider,
      fixpointReductionState = fixpointReductionState,
      isNodeDeletable = {
        dependencyGraph == null ||
          dependencyGraph.representativeOfExternalUses == null
      },
      isReplacementValid = { _, replacement ->
        if (dependencyGraph == null || defTokensUsedExternally.isNullOrEmpty()) {
          true
        } else {
          val semanticTokensUnderTheReplacementNode =
            semanticsProvider?.getSemanticTokensUnderTreeNode(
              replacement,
            )
          if (semanticTokensUnderTheReplacementNode == null) {
            true
          } else {
            defTokensUsedExternally.all { it in semanticTokensUnderTheReplacementNode }
          }
        }
      },
      subtreeEarlyStopCriterion = subtreeEarlyStopCriterion,
    )
  }

  override fun minimizeList(
    semanticsProvider: ISemanticsProvider?,
    kleeneNode: AbstractSparTreeNode,
    tree: SparTree,
    fixpointReductionState: FixpointReductionState,
  ) {
    if (semanticsProvider == null) {
      super.minimizeList(semanticsProvider, kleeneNode, tree, fixpointReductionState)
      return
    }

    val depGraph = semanticsProvider.buildScopedDependencyGraph(kleeneNode.immutableChildView)
    mimirStrategy.reduce(
      AbstractMimirStrategy.MimirReductionContext(
        kleeneNode,
        semanticsProvider,
        depGraph,
        tree,
        fixpointReductionState,
        createCommonActionDescriptionPostfix(kleeneNode),
        mimirConfig,
        this::runListMinimizerOverNodes,
        this::runListMinimizerOverListsOfNodes,
        { actionSet, tree -> testAndApplyDeletionEditIfInteresting(actionSet, tree) },
        this::testWhetherToUseADifferentMinimizerIfInputIsSmall,
      ),
    )
  }

  override fun reduceKleenePlus(
    tree: SparTree,
    kleenePlusNode: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): ImmutableList<AbstractSparTreeNode> {
    val dependencyGraph =
      semanticsProvider?.buildScopedDependencyGraph(
        nodes = kleenePlusNode.immutableChildView,
      )
    val locallyUsedNodes =
      if (dependencyGraph == null) {
        kleenePlusNode.immutableChildView
      } else {
        dependencyGraph.nodesOnlyUsedLocally
      }
    return reduceKleenePlusInternal(
      tree = tree,
      kleenePlusNode = kleenePlusNode,
      semanticsProvider = semanticsProvider,
      fixpointReductionState = fixpointReductionState,
      locallyUsedNodes = locallyUsedNodes,
      isNodeDeletable = {
        dependencyGraph == null ||
          dependencyGraph.representativeOfExternalUses == null
      },
    )
  }

  private fun testWhetherToUseADifferentMinimizerIfInputIsSmall(
    input: ImmutableList<*>,
  ): EnumListMinimizerType? =
    if (input.size <= mimirConfig.nodeCountThresholdToUseOneByOne) {
      EnumListMinimizerType.ONE_BY_ONE
    } else {
      null
    }
}
