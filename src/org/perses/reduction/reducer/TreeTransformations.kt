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

import com.google.common.collect.ImmutableList
import org.perses.reduction.partition.Partition
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ChildHoistingAction
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.TreeNodeFilterResult
import org.perses.util.toImmutableList

/** Various tree transformations.  */
object TreeTransformations {
  /**
   * Replace the current node with one of its children that has compatible rule type.
   *
   * @return all possible replacements.
   */
  @JvmStatic
  fun replaceNodeWithCompatibleChildren(
    currentNode: AbstractSparTreeNode,
    stopAtFirstCompatible: Boolean,
    maxNodeToCollect: Int,
    maxBfsDepth: Int
  ): ImmutableList<ChildHoistingAction> {
    assert(maxNodeToCollect > 0) {
      "The max number of nodes to collect should be positive: $maxNodeToCollect"
    }
    assert(maxBfsDepth > 0) { "The max BFS depth must be positive: $maxBfsDepth" }
    val antlrRuleForTheChild = currentNode.payload!!.expectedAntlrRuleType
    assert(antlrRuleForTheChild != null) { currentNode.printTreeStructure() }
    val expectedSuperRuleType = antlrRuleForTheChild!!

    val collectedNodes = ArrayList<AbstractSparTreeNode>()
    currentNode.boundedBFSChildren { node, currentDepth ->
      if (currentDepth > maxBfsDepth) {
        return@boundedBFSChildren TreeNodeFilterResult.STOP
      }
      if (collectedNodes.size >= maxNodeToCollect) {
        return@boundedBFSChildren TreeNodeFilterResult.STOP
      }
      val nodeRule = node.antlrRule
        ?: return@boundedBFSChildren TreeNodeFilterResult.CONTINUE
      val matched = expectedSuperRuleType.isEqualToOrSuperOf(nodeRule)
      if (matched) {
        collectedNodes.add(node)
        return@boundedBFSChildren if (stopAtFirstCompatible) {
          TreeNodeFilterResult.STOP
        } else {
          TreeNodeFilterResult.CONTINUE
        }
      }
      if (currentDepth == maxBfsDepth) {
        return@boundedBFSChildren TreeNodeFilterResult.STOP
      }
      return@boundedBFSChildren TreeNodeFilterResult.CONTINUE
    }
    return collectedNodes
      .asSequence()
      .map { ChildHoistingAction(currentNode, it) }
      .toImmutableList()
  }

  /**
   * Replace the current node (which should be Kleene-qualified) with one of its children (which
   * should be Kleene-qualified too).
   *
   * @return all possible replacements
   */
  @JvmStatic
  fun replaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
    currentNode: AbstractSparTreeNode,
    maxBfsDepth: Int
  ): ImmutableList<ChildHoistingAction> {
    assert(maxBfsDepth > 0) { "The max BFS depth must be positive: $maxBfsDepth" }
    val parent = currentNode.parent
      ?: error("The current node is a root node: ${currentNode.printTreeStructure()}")
    if (!parent.isKleeneStarRuleNode && !parent.isKleenePlusRuleNode) {
      return ImmutableList.of()
    }
    assert(parent.isKleeneStarRuleNode || parent.isKleenePlusRuleNode) {
      "The current node must be Kleene-qualified. ${currentNode.printTreeStructure()}"
    }
    val kleeneElementRule = currentNode.payload!!.expectedAntlrRuleType!!

    val replacementList = currentNode.boundedBreadthFirstSearchForFirstQualifiedNodes(
      { node: AbstractSparTreeNode ->
        if (!node.isKleeneStarRuleNode && !node.isKleenePlusRuleNode) {
          return@boundedBreadthFirstSearchForFirstQualifiedNodes false
        }
        if (node.childCount == 0) {
          return@boundedBreadthFirstSearchForFirstQualifiedNodes false
        }
        val childRule = node.asParserRule().getKleeneElementRuleTypeOrThrow()
        kleeneElementRule.isEqualToOrSuperOf(childRule)
      },
      maxBfsDepth
    )
    return if (replacementList.isEmpty()) {
      ImmutableList.of()
    } else replacementList
      .asSequence()
      .map { ChildHoistingAction(currentNode, it) }
      .toImmutableList()
  }

  @JvmStatic
  fun createNodeDeletionActionSetFor(
    partition: Partition,
    actionsDescription: String
  ): NodeDeletionActionSet {
    val actionSet = NodeDeletionActionSet.Builder(actionsDescription)
    partition.forEach { actionSet.deleteNode(it) }
    return actionSet.build()
  }
}
