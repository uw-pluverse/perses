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
import org.perses.antlr.RuleHierarchyEntry
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractTreeNode

/**
 * Finds the structures of a subtree that a new subtree may reuse, following the principles of the
 * SFC paper: only structures of the original subtree are reused (1), each at most once (2), in
 * their original order (3), and the highest-level ones are preferred (4).
 */
object StructureReuseFinder {
  /**
   * The subtrees strictly under [subtreeRootToConvert] that a new subtree may reuse where
   * [requiredSymbol] is expected, in the order they are spelled. [subtreeRootToConvert] itself is
   * never one of them: it is what the new subtree replaces.
   *
   * Only the highest ones are returned -- highest as in closest to the root, the same axis as
   * [org.perses.spartree.AbstractTreeNode.findLowestAncestor]. Once a subtree is reusable, the
   * subtrees below it are not, because the paper prefers the highest-level structures
   * (Principle 4).
   *
   * [isReuseAllowed] is a veto the caller adds on top of those rules, asked once per candidate
   * subtree, which is passed by its root node: a subtree it rejects is never reused, even where
   * the grammar would allow it. Identifier Elimination will pass "does not contain this
   * identifier use", so that the new subtree drops that use.
   */
  fun findHighestReusableSubtreesUnder(
    subtreeRootToConvert: AbstractSparTreeNode,
    requiredSymbol: RuleHierarchyEntry,
    isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean,
  ): ImmutableList<AbstractSparTreeNode> {
    val result = ImmutableList.builder<AbstractSparTreeNode>()
    subtreeRootToConvert.preOrderVisit { candidate ->
      val reusable =
        candidate !== subtreeRootToConvert &&
          canStructureBeRewrittenTo(candidate, requiredSymbol) &&
          isReuseAllowed(candidate)
      if (reusable) {
        result.add(candidate)
      }
      // A node spanning the whole subtree is that subtree's own structure rather than a
      // sub-structure of it, so the search continues below it. Perses trees are full of such
      // nodes, one per rule of a chain that derives a single symbol at every step.
      if (reusable && candidate.leafTokenCount < subtreeRootToConvert.leafTokenCount) {
        emptyList()
      } else {
        candidate.immutableChildView
      }
    }
    return result.build()
  }

  /**
   * The highest subtree strictly under [subtreeRoot] that can stand where [requiredSymbol] is
   * expected, or null when nothing under it can. Used to shrink a reused subtree to a smaller
   * piece of itself when reusing it whole would not make the candidate smaller.
   */
  fun findFirstReusableDescendantOf(
    subtreeRoot: AbstractSparTreeNode,
    requiredSymbol: RuleHierarchyEntry,
    isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean,
  ): AbstractSparTreeNode? {
    val queue = ArrayDeque<AbstractSparTreeNode>()
    subtreeRoot.forEachChild(queue::addLast)
    while (queue.isNotEmpty()) {
      val candidate = queue.removeFirst()
      if (candidate.leafTokenCount < subtreeRoot.leafTokenCount &&
        canStructureBeRewrittenTo(candidate, requiredSymbol) &&
        isReuseAllowed(candidate)
      ) {
        return candidate
      }
      candidate.forEachChild(queue::addLast)
    }
    return null
  }

  /**
   * Whether [structure] is grammatically valid where [requiredSymbol] is expected: the rule the
   * structure was parsed as is [requiredSymbol] itself, or can be rewritten to it transitively.
   */
  private fun canStructureBeRewrittenTo(
    structure: AbstractSparTreeNode,
    requiredSymbol: RuleHierarchyEntry,
  ): Boolean {
    val ruleOfStructure = structure.antlrRule ?: return false
    return requiredSymbol.isEqualToOrSuperOf(ruleOfStructure)
  }

  /**
   * Whether the two subtrees share any node, which for tree nodes means that one of the two
   * roots is reachable from the other by walking down the tree: two subtrees of a tree either
   * nest or are disjoint. A node overlaps itself.
   *
   * Equivalently, and as computed here, the lowest common ancestor of the two roots is one of
   * them rather than a node strictly above both.
   *
   * Overlapping subtrees cannot both be reused in one new subtree: reusing a subtree together
   * with a node reachable from it would spell that node twice, and filling two holes with one
   * subtree would spell it twice as well. The paper reuses each structure at most once
   * (Principle 2).
   */
  fun doSubtreesOverlap(
    oneSubtreeRoot: AbstractSparTreeNode,
    anotherSubtreeRoot: AbstractSparTreeNode,
  ): Boolean {
    val lowestAncestor =
      AbstractTreeNode.findLowestAncestorPair(oneSubtreeRoot, anotherSubtreeRoot)
    return lowestAncestor === oneSubtreeRoot || lowestAncestor === anotherSubtreeRoot
  }
}
