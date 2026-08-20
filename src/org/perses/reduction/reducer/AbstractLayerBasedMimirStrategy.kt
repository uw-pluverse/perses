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
import org.perses.reduction.semantics.SccGraph
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet

abstract class AbstractLayerBasedMimirStrategy : AbstractMimirStrategy() {
  override fun internalReduce(context: MimirReductionContext) {
    val layersFromTopToBottom = computeLayersFromTopToBottom(context.depGraph)
    internalLayerBasedReduce(context, layersFromTopToBottom)
    if (context.mimirConfig.deleteDefWithAllItsConcreteUses) {
      reduceDefinitionWithAllItsConcreteUses(context, layersFromTopToBottom)
    }
    reduceShadowingVariableDefinitionsForLayersForcibly(context, layersFromTopToBottom)
  }

  protected fun reduceDefinitionWithAllItsConcreteUses(
    context: MimirReductionContext,
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
  ) {
    val contextDescriptionPostfix =
      context.commonPostfix.createByAppending(
        "RemoveDefWithAllConcreteUses",
      )
    val depGraph = context.depGraph
    val definitions =
      getSingleNodesForForcibleDeletion(
        layersFromTopToBottom,
        semanticsProvider = context.semanticsProvider,
        nodePredicate = { true },
      )
    var i = definitions.size - 1
    val nodesInDepGraph =
      mutableSetOf<AbstractSparTreeNode>().also { set ->
        depGraph.allNodes.forEach { node ->
          if (!(node.isPermanentlyDeleted)) {
            set.add(node)
          }
        }
      }
    while (i >= 0) {
      val definition = definitions[i]
      --i
      val builder =
        NodeDeletionActionSet.Builder(
          contextDescription = contextDescriptionPostfix.toString(),
        )
      // need to delete the definition and all concrete use tokens together.
      builder.deleteNode(definition)

      val outgoingEdges = depGraph.getOutgoingEdges(definition)
      val concreteUseTokens = outgoingEdges.flatMap { it.useTokens }
      val failedTokens = mutableListOf<LexerRuleSparTreeNode>()
      for (concreteUseToken in concreteUseTokens) {
        if (concreteUseToken.isPermanentlyDeleted) {
          continue
        }
        val epsilonDeletableNode =
          concreteUseToken.findEpsilonDeletableAncestor(
            stopPredicate = { node ->
              nodesInDepGraph.contains(node)
            },
          )
        if (epsilonDeletableNode != null) {
          builder.deleteNode(epsilonDeletableNode)
        } else {
          failedTokens.add(concreteUseToken)
        }
      }
      // TODO(cnsun): need to try to reduce the failed tokens again.
      if (failedTokens.isNotEmpty()) {
        continue
      }
      val actionSet = builder.build()
      context.testAndApplyDeletionEditIfInteresting(actionSet, context.tree)
    }
  }

  protected abstract fun internalLayerBasedReduce(
    context: MimirReductionContext,
    layersFromTopToBottom: ImmutableList<ImmutableList<SccGraph>>,
  )
}
