/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.reduction.reducer.latra

import com.google.common.hash.HashCode
import it.unimi.dsi.fastutil.ints.Int2ObjectMap
import org.perses.reduction.reducer.latra.language.AbstractPatternElementBindings
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.DeepCopyResult
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap

/**
 * This class represents a match between
 * @param subtreeRoot is the root Node of matched subtree in input tree
 * @param holeBindings maps the hole in pattern tree to its corresponding node in input tree
 *
 */
data class SparTreeHoleMatch(
  val subtreeRoot: AbstractSparTreeNode,
  val holeBindings: AbstractPatternElementBindings.NonScopedBindings,
) {
  fun portToTreeCopy(treeCopy: DeepCopyResult<SparTree, AbstractSparTreeNode>): SparTreeHoleMatch =
    SparTreeHoleMatch(
      subtreeRoot = treeCopy.getCopyNode(subtreeRoot)!!,
      holeBindings = holeBindings.portToAnotherTree(treeCopy),
    )

  // TODO(cnsun): needs testing.
  fun portToTreeBasedOnNodeId(
    id2NodeMap: Int2ObjectMap<AbstractSparTreeNode>,
  ): SparTreeHoleMatch? {
    val newSubtreeRoot = id2NodeMap[this.subtreeRoot.nodeId] ?: return null
    val newHoleBindings =
      holeBindings.holeBindings.entries
        .map { entry ->
          entry.key to
            entry.value
              .map { node -> id2NodeMap[node.nodeId] ?: return null }
              .toImmutableList()
        }.toImmutableMap()
    val newConcreteTokenBindings =
      holeBindings.concreteTokenBindings.entries
        .map { entry ->
          val newNode = id2NodeMap[entry.value.nodeId] ?: return null
          if (newNode !is LexerRuleSparTreeNode) {
            return null
          }
          entry.key to newNode
        }.toImmutableMap()
    return SparTreeHoleMatch(
      newSubtreeRoot,
      AbstractPatternElementBindings.NonScopedBindings(
        holeBindings = newHoleBindings,
        concreteTokenBindings = newConcreteTokenBindings,
      ),
    )
  }

  fun printMatchInfo(): String {
    val shortHash =
      if (subtreeRoot.isPermanentlyDeleted) {
        ",deleted"
      } else {
        ""
      }
    return "subroot(id=${subtreeRoot.nodeId},#${subtreeRoot.leafTokenCount}$shortHash)"
  }

  fun isStillValid(): Boolean =
    holeBindings.holeBindings.all { binding ->
      binding.value.all { node -> !node.isPermanentlyDeleted }
    } &&
      holeBindings.concreteTokenBindings.all { binding ->
        !binding.value.isPermanentlyDeleted
      }

  @Deprecated("Do not use.")
  val signature: Signature by lazy {
    Signature(
      EnumShaAlgorithm.SHA256.hashString(
        subtreeRoot.leafNodeSequence().joinToString(separator = "\n") { it.token.lexemeText },
      ),
    )
  }

  data class Signature(
    val sha256HashCode: HashCode,
  )
}
