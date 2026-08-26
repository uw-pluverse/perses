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
package org.perses.reduction.reducer.sfc

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeReplacementActionSet
import org.perses.spartree.SparTree
import java.util.ArrayDeque

/**
 * Algorithm 3 of the SFC paper: visit the tree in BFS order and offer each subtree to the
 * property test as one structure form conversion of it after another, until one is accepted.
 *
 * The traversal then continues below the replacement rather than below the subtree it replaced,
 * since the replacement is what the program now holds. A subclass decides which conversions to
 * offer and in which order, which is the only difference between replacing a subtree with a
 * smaller structure and replacing it with a more canonical one.
 */
abstract class AbstractStructureFormConversionReducer(
  reducerAnnotation: NonDeletionBasedReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractNonDeletionBasedReducer(reducerAnnotation, reducerContext) {
  private val converter =
    StructureFormConverter(
      reducerContext.configuration.canonicalParserFacade,
      reducerContext.sparTreeNodeFactory,
    )

  protected val sfcConfig = reducerContext.configuration.sfcConfig

  /** The conversions of [node] this reducer offers, in the order it wants them tried. */
  internal abstract fun candidatesFor(
    node: AbstractSparTreeNode,
  ): ImmutableList<StructureFormConverter.Candidate>

  /**
   * Every conversion of [node], for a subclass to choose from. A subtree of one token converts
   * into nothing, and one of many tokens is left alone: the number of structures a subtree
   * converts into grows with the subtrees under it that can be reused.
   */
  protected fun conversionsOf(
    node: AbstractSparTreeNode,
    shrinkOversizedCandidates: Boolean = false,
  ): Sequence<StructureFormConverter.Candidate> =
    if (node.leafTokenCount !in 2..sfcConfig.subtreeTokenCountLimit) {
      emptySequence()
    } else {
      converter.convert(node, shrinkOversizedCandidates = shrinkOversizedCandidates)
    }

  final override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    mutationHistory.add(tree.programSnapshot.payload)
    val worklist = ArrayDeque<AbstractSparTreeNode>()
    tree.realRoot.forEachChild(worklist::addLast)
    while (worklist.isNotEmpty()) {
      val node = worklist.removeFirst()
      // An accepted replacement can delete a subtree that is already on the worklist.
      if (node.isPermanentlyDeleted) {
        continue
      }
      val replacement = replaceWithAcceptedCandidate(node, tree, fixpointReductionState)
      (replacement ?: node).forEachChild(worklist::addLast)
    }
  }

  private fun replaceWithAcceptedCandidate(
    node: AbstractSparTreeNode,
    tree: SparTree,
    fixpointReductionState: FixpointReductionState,
  ): AbstractSparTreeNode? {
    for (candidate in candidatesFor(node)) {
      val edit =
        tree.createAnyNodeReplacementEdit(
          NodeReplacementActionSet.createByReplacingSingleNode(
            targetNode = node,
            replacingNode = candidate.tree,
            contextDescription =
              "replace a node ${node.ruleName} with a structure of " +
                "the rule ${candidate.template.rule.ruleName}",
          ),
        )
      val payload =
        ignoreCachedEditsThenFindBestWrtProperty(listOf(edit), fixpointReductionState)
          ?: continue
      applyEditToTree(payload)
      return candidate.tree
    }
    return null
  }
}
