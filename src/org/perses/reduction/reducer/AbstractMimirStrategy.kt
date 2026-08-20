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
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReductionConfiguration.MimirConfig
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.reduction.semantics.SccGraph
import org.perses.reduction.semantics.ScopedDependencyGraph
import org.perses.reduction.semantics.SemanticTokenType
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ContextDescription
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

/**
 * The base class for Mimir reduction strategies.
 */
abstract class AbstractMimirStrategy {
  data class MimirReductionContext(
    val kleeneNode: AbstractSparTreeNode?,
    val semanticsProvider: ISemanticsProvider,
    val depGraph: ScopedDependencyGraph,
    val tree: SparTree,
    val fixpointReductionState: FixpointReductionState,
    val commonPostfix: ContextDescription,
    val mimirConfig: MimirConfig,
    val runListMinimizerOverNodes: (
      needToTestEmpty: Boolean,
      tree: SparTree,
      input: ImmutableList<out AbstractSparTreeNode>,
      fixpointReductionState: FixpointReductionState,
      actionsDescriptionPostfix: ContextDescription,
      specifiedMinimizerType: EnumListMinimizerType?,
    ) -> ImmutableList<out AbstractSparTreeNode>,
    val runListMinimizerOverListsOfNodes: (
      needToTestEmpty: Boolean,
      tree: SparTree,
      input: ImmutableList<out ImmutableList<out AbstractSparTreeNode>>,
      fixpointReductionState: FixpointReductionState,
      actionsDescriptionPostfix: ContextDescription,
      specifiedMinimizerType: EnumListMinimizerType?,
    ) -> ImmutableList<ImmutableList<out AbstractSparTreeNode>>,
    val testAndApplyDeletionEditIfInteresting: (
      actionSet: NodeDeletionActionSet,
      tree: SparTree,
    ) -> AbstractSparTreeReducer.EditApplicationResult,
    val testWhetherToUseADifferentMinimizerIfInputIsSmall: (
      input: ImmutableList<*>,
    ) -> EnumListMinimizerType?,
  )

  fun reduce(context: MimirReductionContext) {
    val depGraph = context.depGraph
    if (depGraph.areAllNodesIsolated() || depGraph.areAllLocallyUsedNodesIsolated()) {
      minimizeIsolatedNodes(context)
    } else {
      internalReduce(context)
    }
    optionallyForciblyReduceExternallyUsedNodes(context)
  }

  protected abstract fun internalReduce(context: MimirReductionContext)

  private fun minimizeIsolatedNodes(context: MimirReductionContext) {
    val depGraph = context.depGraph
    val commonPostfix = context.commonPostfix
    val kleeneNode = context.kleeneNode
    val areAllNodesIsolated = depGraph.areAllNodesIsolated()
    val postfix =
      commonPostfix.createByAppending(
        if (areAllNodesIsolated) "NoDepsAmongNodes" else "NoDepsAmongLocalNodes",
      )
    val input =
      if (areAllNodesIsolated) {
        depGraph.allNodesExcludingRepresentativeOfExternalUses
      } else {
        depGraph.nodesOnlyUsedLocally
      }.toImmutableList()
    val needToTestEmpty =
      if (areAllNodesIsolated && kleeneNode != null) {
        kleeneNode.isOptionalRuleNode || kleeneNode.isKleeneStarRuleNode
      } else {
        true
      }
    // We can easily preserve the order of nodes, so that DFS can work better.
    // This might be a slight optimization.
    context.runListMinimizerOverNodes(
      needToTestEmpty,
      context.tree,
      input,
      context.fixpointReductionState,
      postfix,
      context.testWhetherToUseADifferentMinimizerIfInputIsSmall(input),
    )
  }

  protected fun computeLayersFromTopToBottom(
    depGraph: ScopedDependencyGraph,
  ): ImmutableList<ImmutableList<SccGraph>> =
    depGraph.computeLayers().layersFromTopToBottom.transformToImmutableList { layer ->
      layer.elements
        .map { scc ->
          val nodes = scc.vertexSet().toImmutableList()
          val maxPos =
            nodes.maxOf {
              it.endToken!!
                .token
                .asAntlrToken()
                .position
            }
          scc to maxPos
        }.sortedBy { it.second }
        .transformToImmutableList { it.first }
    }

  protected fun minimizeOneLayer(
    context: MimirReductionContext,
    currentLayer: ImmutableList<SccGraph>,
    layerIndex: Int,
    isBottomLayer: Boolean,
  ) {
    var input: ImmutableList<ImmutableList<AbstractSparTreeNode>>
    val descriptionPostfix: ContextDescription
    if (isBottomLayer) {
      input =
        currentLayer
          .map { group: SccGraph ->
            group.vertexSet().filter { isAliveAndNonEmpty(it) }.toImmutableList()
          }.filter { it.isNotEmpty() }
          .toImmutableList()
      descriptionPostfix = context.commonPostfix.createByAppending("LayerBottom")
    } else {
      input =
        currentLayer
          .map { scc: SccGraph ->
            context.depGraph
              .getForwardReachableNodesFrom(scc)
              .asSequence()
              .flatMap { it.vertexSet().asSequence() }
              .filter { isAliveAndNonEmpty(it) }
              .sortedBy { it.nodeId }
              .toImmutableList()
          }.filter { it.isNotEmpty() }
          .toImmutableList()
      descriptionPostfix = context.commonPostfix.createByAppending("Layer-Top-$layerIndex")
    }

    input =
      deleteOverlappingClusters(
        input,
        context.tree,
        descriptionPostfix,
        context.testAndApplyDeletionEditIfInteresting,
      )

    context.runListMinimizerOverListsOfNodes(
      isBottomLayer,
      context.tree,
      input,
      context.fixpointReductionState,
      descriptionPostfix,
      context.testWhetherToUseADifferentMinimizerIfInputIsSmall(input),
    )
  }

  private fun deleteOverlappingClusters(
    input: ImmutableList<ImmutableList<AbstractSparTreeNode>>,
    tree: SparTree,
    descriptionPostfix: ContextDescription,
    testAndApplyDeletionEditIfInteresting: (
      actionSet: NodeDeletionActionSet,
      tree: SparTree,
    ) -> AbstractSparTreeReducer.EditApplicationResult,
  ): ImmutableList<ImmutableList<AbstractSparTreeNode>> {
    val clusterCount = input.size
    if (clusterCount <= 1) {
      return input
    }
    val isOverlapping = BooleanArray(clusterCount)
    val nodeToFirstClusterIndex = mutableMapOf<AbstractSparTreeNode, Int>()

    for (clusterIndex in 0 until clusterCount) {
      val cluster = input[clusterIndex]
      for (node in cluster) {
        val firstIndex = nodeToFirstClusterIndex.putIfAbsent(node, clusterIndex)
        if (firstIndex != null && firstIndex != clusterIndex) {
          isOverlapping[clusterIndex] = true
          isOverlapping[firstIndex] = true
        }
      }
    }

    var hasOverlaps = false
    for (clusterIndex in 0 until clusterCount) {
      if (!isOverlapping[clusterIndex]) {
        continue
      }
      hasOverlaps = true
      val partition = input[clusterIndex].filter { !it.isPermanentlyDeleted }
      if (partition.isEmpty()) {
        continue
      }
      testAndApplyDeletionEditIfInteresting(
        NodeDeletionActionSet.createByDeletingNodes(
          partition,
          contextDescription =
            descriptionPostfix
              .createByAppending(
                "OverlappingCluster$clusterIndex",
              ).toString(),
        ),
        tree,
      )
    }

    if (!hasOverlaps) {
      return input
    }

    val resultBuilder = ImmutableList.builder<ImmutableList<AbstractSparTreeNode>>()
    for (clusterIndex in 0 until clusterCount) {
      if (!isOverlapping[clusterIndex]) {
        resultBuilder.add(input[clusterIndex])
      }
    }
    return resultBuilder.build()
  }

  private fun isAliveAndNonEmpty(node: AbstractSparTreeNode): Boolean =
    !node.isPermanentlyDeleted && node.leafNodeSequence().any()

  protected fun getSingleVariableDefNodesForForcibleDeletion(
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
    semanticsProvider: ISemanticsProvider,
  ): ImmutableList<out AbstractSparTreeNode> =
    getSingleNodesForForcibleDeletion(
      layersFromTopToBottom,
      semanticsProvider,
      nodePredicate = { node ->
        val semanticTokenNodes = semanticsProvider.getSemanticTokensUnderTreeNode(node)
        val isVariable =
          semanticTokenNodes.all { lexNode ->
            // Only care about variable nodes, as only variables can shadow other definitions.
            semanticsProvider.getSemanticTokenTypeFor(lexNode) == SemanticTokenType.VARIABLE
          }
        isVariable
      },
    )

  protected fun getSingleNodesForForcibleDeletion(
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
    semanticsProvider: ISemanticsProvider,
    nodePredicate: (AbstractSparTreeNode) -> Boolean,
  ): ImmutableList<out AbstractSparTreeNode> {
    if (layersFromTopToBottom.isEmpty()) {
      return ImmutableList.of()
    }
    val bottomLayer = layersFromTopToBottom.last()
    val candidates = linkedSetOf<AbstractSparTreeNode>()
    for (layer in layersFromTopToBottom) {
      val isBottomLayer = layer === bottomLayer
      for (scc in layer) {
        val vertexSet = scc.vertexSet()
        if (isBottomLayer && vertexSet.size <= 1) {
          // We have tried to delete this single node already.
          continue
        }
        for (vertex in vertexSet) {
          if (vertex.isPermanentlyDeleted) {
            continue
          }
          if (nodePredicate.invoke(vertex)) {
            candidates.add(vertex)
          }
        }
      }
    }
    return candidates
      .map {
        it to
          it.endToken!!
            .token
            .asAntlrToken()
            .position
      }.sortedBy { it.second }
      .transformToImmutableList { it.first }
  }

  protected fun reduceShadowingVariableDefinitionsForLayersForcibly(
    context: MimirReductionContext,
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
  ) {
    if (!context.mimirConfig.mimirReductionAlgorithm.deleteShadowing) {
      return
    }
    val input: ImmutableList<out AbstractSparTreeNode> =
      getSingleVariableDefNodesForForcibleDeletion(layersFromTopToBottom, context.semanticsProvider)
    reduceShadowingVariableDefinitionsForcibly(
      context,
      input,
    )
  }

  protected fun getConcreteUsesForDef(
    def: AbstractSparTreeNode,
    depGraph: ScopedDependencyGraph,
    parentsOfNodesInDepGraph: Set<AbstractSparTreeNode>,
  ): ImmutableList<AbstractSparTreeNode> {
    val result = ImmutableList.builder<AbstractSparTreeNode>()
    result.add(def)

    val outgoingEdges = depGraph.getOutgoingEdges(def)
    val concreteUseTokens = outgoingEdges.flatMap { it.useTokens }
    val failedTokens = mutableListOf<LexerRuleSparTreeNode>()
    for (concreteUseToken in concreteUseTokens) {
      if (concreteUseToken.isPermanentlyDeleted) {
        continue
      }
      val epsilonDeletableNode =
        concreteUseToken.findEpsilonDeletableAncestor(
          stopPredicate = { node ->
            parentsOfNodesInDepGraph.contains(node)
          },
        )
      if (epsilonDeletableNode != null) {
        result.add(epsilonDeletableNode)
      } else {
        failedTokens.add(concreteUseToken)
      }
    }
    // TODO(cnsun): need to try to reduce the failed tokens again.
    if (failedTokens.isNotEmpty()) {
      result.addAll(failedTokens)
    }
    return result.build()
  }

  private fun optionallyForciblyReduceExternallyUsedNodes(context: MimirReductionContext) {
    if (!context.mimirConfig.mimirReductionAlgorithm.deleteShadowing) {
      return
    }
    val externallyUsedNodes = context.depGraph.nodesUsedExternally
    // TODO(cnsun)
    val size = externallyUsedNodes.size
    if (size == 0) {
      return
    }
//    val depGraph = context.depGraph
//    val parentsOfNodesInDepGraph = depGraph.allNodes.mapNotNull { it.parent }.toSet()
    val description = context.commonPostfix.createByAppending("ForciblyDeleteExternallyUsed")
    for (i in 0 until size) {
      val externallyUsedDef = externallyUsedNodes[i]

      // The following code can only delete function parameters and the use of function parameters.
//      val concreteUsesWithDef =
//        getConcreteUsesForDef(
//          externallyUsedDef,
//          depGraph = depGraph,
//          parentsOfNodesInDepGraph = parentsOfNodesInDepGraph,
//        )
//      context.testAndApplyDeletionEditIfInteresting(
//        NodeDeletionActionSet.createByDeletingNodes(
//          nodes = concreteUsesWithDef,
//          contextDescription =
//            context.commonPostfix
//              .createByAppending(
//                "ForciblyDeleteExternallyUsedWithUses",
//              ).toString(),
//        ),
//        context.tree,
//      )
//      if (externallyUsedDef.isPermanentlyDeleted) {
//        continue
//      }
      context.testAndApplyDeletionEditIfInteresting
      val semanticTokenNodes =
        context.semanticsProvider.getSemanticTokensUnderTreeNode(
          externallyUsedDef,
        )
      val allAllVariables =
        semanticTokenNodes.all { node ->
          val tokenType = context.semanticsProvider.getSemanticTokenTypeFor(node)
          tokenType == SemanticTokenType.VARIABLE
        }
      if (!allAllVariables) {
        continue
      }
      context.testAndApplyDeletionEditIfInteresting(
        NodeDeletionActionSet.createByDeleteSingleNode(
          externallyUsedDef,
          contextDescription = description.toString(),
        ),
        context.tree,
      )
    }
  }

  protected fun reduceShadowingVariableDefinitionsForcibly(
    context: MimirReductionContext,
    input: ImmutableList<out AbstractSparTreeNode>,
  ) {
    if (!context.mimirConfig.mimirReductionAlgorithm.deleteShadowing) {
      return
    }
    if (input.isEmpty()) {
      return
    }
    // TODO(cnsun): need to rename the description.
    val description = context.commonPostfix.createByAppending("ForciblyDeleteDefNode")
    context.runListMinimizerOverNodes(
      false,
      context.tree,
      input,
      context.fixpointReductionState,
      description,
      // Use ONE_BY_ONE as this minimization pass is mainly for 1-minimality.
      EnumListMinimizerType.ONE_BY_ONE,
    )
  }
}
