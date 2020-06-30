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

import com.google.common.collect.ImmutableList
import org.perses.reduction.partition.Partition
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.ChildHoistingAction
import org.perses.tree.spar.NodeDeletionActionSet

/** Various tree transformations.  */
object TreeTransformations {
  /**
   * Replace the current node with one of its children that has compatible rule type.
   *
   * @return all possible replacements.
   */
  @JvmStatic
  fun replaceNodeWithNearestCompatibleChildren(
    currentNode: AbstractSparTreeNode,
    maxBfsDepth: Int
  ): ImmutableList<ChildHoistingAction> {
    assert(maxBfsDepth > 0) { "The max BFS depth must be positive: $maxBfsDepth" }
    val parentInfo = currentNode.parentInfo
      ?: error("This is a root node: " + currentNode.printTreeStructure())
    val antlrRuleForTheChild = parentInfo.antlrRuleForTheChild
    assert(antlrRuleForTheChild.isPresent) { currentNode.printTreeStructure() }
    val expectedSuperRuleType = antlrRuleForTheChild.get()
    val replacements = currentNode.boundedBreadthFirstSearchForFirstQualifiedNodes(
      { node: AbstractSparTreeNode ->
        val nodeRule = node.antlrRule
        if (!nodeRule.isPresent) {
          return@boundedBreadthFirstSearchForFirstQualifiedNodes false
        }
        expectedSuperRuleType.isEqualToOrSuperOf(nodeRule.get())
      },
      maxBfsDepth
    )
    return replacements.stream()
      .map { node: AbstractSparTreeNode? -> ChildHoistingAction(currentNode, node) }
      .collect(ImmutableList.toImmutableList())
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
    val parentInfo = currentNode.parentInfo
      ?: error("The current node is a root node: " + currentNode.printTreeStructure())
    val parent: AbstractSparTreeNode = parentInfo.node
    if (!parent.isKleeneStarRuleNode && !parent.isKleenePlusRuleNode) {
      return ImmutableList.of()
    }
    assert(parent.isKleeneStarRuleNode || parent.isKleenePlusRuleNode) {
      "The current node must be Kleene-qualified." + currentNode.printTreeStructure()
    }
    val kleeneElementRule = parent.kleeneElementRule
    assert(kleeneElementRule == currentNode.parentInfo!!.antlrRuleForTheChild.get()) {
      (
        currentNode
          .toString() + ": " +
          kleeneElementRule +
          " vs " +
          currentNode.parentInfo!!.antlrRuleForTheChild
        )
    }
    val replacementList = currentNode.boundedBreadthFirstSearchForFirstQualifiedNodes(
      { node: AbstractSparTreeNode ->
        if (!node.isKleeneStarRuleNode && !node.isKleenePlusRuleNode) {
          return@boundedBreadthFirstSearchForFirstQualifiedNodes false
        }
        val childRule = node.kleeneElementRule
        kleeneElementRule.isEqualToOrSuperOf(childRule)
      },
      maxBfsDepth
    )
    return if (replacementList.isEmpty()) {
      ImmutableList.of()
    } else replacementList.stream()
      .map { node: AbstractSparTreeNode? -> ChildHoistingAction(currentNode, node) }
      .collect(ImmutableList.toImmutableList())
  }

  @JvmStatic
  fun createNodeDeletionActionSetFor(
    partition: Partition,
    actionsDescription: String?
  ): NodeDeletionActionSet {
    val actionSet = NodeDeletionActionSet.Builder(actionsDescription)
    partition.forEach { actionSet.deleteNode(it) }
    return actionSet.build()
  }
}
