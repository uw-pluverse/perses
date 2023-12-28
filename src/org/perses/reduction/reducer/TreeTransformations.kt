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

import org.perses.delta.xfs.Partition
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.TreeNodeFilterResult
import org.perses.util.Util.lazyAssert

/** Various tree transformations.  */
object TreeTransformations {
  /**
   * Replace the current node with one of its children that has compatible rule type.
   *
   * @return all possible replacements.
   */
  @JvmStatic
  fun findCompatibleDescendants(
    currentNode: AbstractSparTreeNode,
    stopAtFirstCompatible: Boolean,
    maxBfsDepth: Int,
  ): Sequence<AbstractSparTreeNode> {
    lazyAssert({ maxBfsDepth > 0 }) { "The max BFS depth must be positive: $maxBfsDepth" }
    val antlrRuleForTheChild = currentNode.payload!!.expectedAntlrRuleType
    lazyAssert({ antlrRuleForTheChild != null }) { currentNode.printTreeStructure() }
    val expectedSuperRuleType = antlrRuleForTheChild!!

    return sequence {
      currentNode.boundedBFSChildren { node, currentDepth ->
        if (currentDepth > maxBfsDepth) {
          return@boundedBFSChildren TreeNodeFilterResult.STOP
        }
        val nodeRule = node.antlrRule
          ?: return@boundedBFSChildren TreeNodeFilterResult.CONTINUE
        val matched = expectedSuperRuleType.isEqualToOrSuperOf(nodeRule)
        if (matched) {
          yield(node)
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
    }
  }

  /**
   * Replace the current node (which should be Kleene-qualified) with one of its children (which
   * should be Kleene-qualified too).
   *
   * @return all possible replacements
   */
  @JvmStatic
  fun findCompatibleKleeneDescendantsForKleeneQuantifiedNode(
    kleeneQuantifiedCurrentNode: AbstractSparTreeNode,
    maxBfsDepth: Int,
  ): Sequence<AbstractSparTreeNode> {
    lazyAssert({ maxBfsDepth > 0 }) { "The max BFS depth must be positive: $maxBfsDepth" }
    val parent = kleeneQuantifiedCurrentNode.parent
      ?: error(
        "The current node is a root node: ${kleeneQuantifiedCurrentNode.printTreeStructure()}",
      )
    if (!parent.isKleeneStarRuleNode && !parent.isKleenePlusRuleNode) {
      return emptySequence()
    }
    lazyAssert({ parent.isKleeneStarRuleNode || parent.isKleenePlusRuleNode }) {
      "The current node must be Kleene-qualified. " +
        kleeneQuantifiedCurrentNode.printTreeStructure()
    }
    val kleeneElementRule = kleeneQuantifiedCurrentNode
      .payload!!.expectedAntlrRuleType!!

    return kleeneQuantifiedCurrentNode.boundedBreadthFirstSearchForFirstQualifiedNodes(
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
      maxBfsDepth,
    )
  }

  @JvmStatic
  fun createNodeDeletionActionSetFor(
    partition: Partition<AbstractSparTreeNode>,
    actionsDescription: String,
  ): NodeDeletionActionSet {
    val actionSet = NodeDeletionActionSet.Builder(actionsDescription)
    partition.forEach { actionSet.deleteNode(it) }
    return actionSet.build()
  }
}
