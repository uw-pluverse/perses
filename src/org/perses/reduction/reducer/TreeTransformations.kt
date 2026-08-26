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

import org.perses.util.lazyAssert
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.TreeNodeFilterResult
import org.perses.spartree.TreeNodeFilterResult.CONTINUE
import org.perses.util.lazyAssert

/** Various tree transformations.  */
object TreeTransformations {
  /**
   * Replace the current node with one of its children that has compatible rule type.
   *
   * @return all possible replacements.
   */
  @JvmStatic
  inline fun findCompatibleDescendants(
    currentNode: AbstractSparTreeNode,
    stopAtFirstCompatible: Boolean,
    maxBfsDepth: Int,
    crossinline subtreeEarlyStopCriterion: (
      AbstractSparTreeNode,
    ) -> TreeNodeFilterResult = { CONTINUE },
  ): Sequence<AbstractSparTreeNode> {
    lazyAssert({ maxBfsDepth > 0 }) { "The max BFS depth must be positive: $maxBfsDepth" }
    val antlrRuleForTheChild = currentNode.payload!!.expectedAntlrRuleType
    lazyAssert({ antlrRuleForTheChild != null }) { currentNode.printTreeStructure() }
    val expectedSuperRuleType = antlrRuleForTheChild!!

    return currentNode.boundedBreadthFirstSearchToSelectNodes(
      selectionPredicate = { node ->
        val nodeRule = node.antlrRule
        if (nodeRule == null) {
          false
        } else if (expectedSuperRuleType.isEqualToOrSuperOf(nodeRule)) {
          true
        } else {
          false
        }
      },
      stopAtFirstSelectionPerPath = stopAtFirstCompatible,
      maxBfsDepth = maxBfsDepth,
      subtreeEarlyStopCriterion = subtreeEarlyStopCriterion,
    )
  }

  /**
   * Replace the current node (which should be Kleene-qualified) with one of its children (which
   * should be Kleene-qualified too).
   *
   * @return all possible replacements
   */
  @JvmStatic
  inline fun findCompatibleKleeneDescendantsForKleeneQuantifiedNode(
    kleeneQuantifiedCurrentNode: AbstractSparTreeNode,
    maxBfsDepth: Int,
    crossinline subtreeEarlyStopCriterion: (AbstractSparTreeNode) -> TreeNodeFilterResult,
  ): Sequence<AbstractSparTreeNode> {
    check(maxBfsDepth > 0) { "The max BFS depth must be positive: $maxBfsDepth" }
    val parent =
      kleeneQuantifiedCurrentNode.parent
        ?: error(
          "The current node is a root node: ${kleeneQuantifiedCurrentNode.printTreeStructure()}",
        )
    if (!parent.isKleeneStarRuleNode && !parent.isKleenePlusRuleNode) {
      return emptySequence()
    }
    check(parent.isKleeneStarRuleNode || parent.isKleenePlusRuleNode) {
      "The current node must be Kleene-qualified. " +
        kleeneQuantifiedCurrentNode.printTreeStructure()
    }
    val kleeneElementRule =
      kleeneQuantifiedCurrentNode
        .payload!!
        .expectedAntlrRuleType!!

    return kleeneQuantifiedCurrentNode.boundedBreadthFirstSearchToSelectNodes(
      selectionPredicate = { node: AbstractSparTreeNode ->
        if (!node.isKleeneStarRuleNode && !node.isKleenePlusRuleNode) {
          return@boundedBreadthFirstSearchToSelectNodes false
        }
        if (node.childCount == 0) {
          return@boundedBreadthFirstSearchToSelectNodes false
        }
        val childRule = node.asParserRule().getKleeneElementRuleTypeOrThrow()
        kleeneElementRule.isEqualToOrSuperOf(childRule)
      },
      stopAtFirstSelectionPerPath = true,
      maxBfsDepth = maxBfsDepth,
      subtreeEarlyStopCriterion = subtreeEarlyStopCriterion,
    )
  }
}
