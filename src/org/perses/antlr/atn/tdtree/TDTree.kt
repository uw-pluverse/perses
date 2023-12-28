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
package org.perses.antlr.atn.tdtree

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.spartree.TreeNodeFilterResult
import org.perses.util.toImmutableSet

class TDTree {

  private var nodeIdGenerator = 0

  fun nextId() = ++nodeIdGenerator

  val root = SequenceTDTreeNode(nodeId = nextId())

  fun createCharNode(char: Char): CharTDTreeNode {
    return CharTDTreeNode(nodeId = nextId(), char)
  }

  fun createOptionalTDTreeNode(): OptionalTDTreeNode {
    return OptionalTDTreeNode(nodeId = nextId())
  }

  fun deleteNodes(nodesToDelete: Set<AbstractTDTreeNode>) {
    root.preOrderVisit {
      if (nodesToDelete.contains(it)) {
        it.delete()
        ImmutableList.of()
      } else {
        it.immutableChildView
      }
    }
  }

  fun removeNodesWithNoCharLeaves(): TDTree {
    root.postOrderVisit {
      if (it is CharTDTreeNode) {
        return@postOrderVisit
      }
      it.cleanDeletedImmediateChildren()
      if (it.hasNoChild()) {
        it.delete()
      }
    }
    return this
  }

  fun createPlusTDTreeNode(): PlusTDTreeNode = PlusTDTreeNode(nodeId = nextId())

  fun createStarTDTreeNode(): StarTDTreeNode {
    return StarTDTreeNode(nodeId = nextId())
  }

  fun toLexeme(
    blanketedNodes: Set<AbstractTDTreeNode> = HashSet(),
  ): String {
    return root.toLexeme(blanketedNodes)
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("lexeme", toLexeme()).toString()
  }

  fun deletableNodesFromTopToBottomSequence(): Sequence<Set<AbstractTDTreeNode>> {
    return sequence {
      root.boundedBFSChildren { node, _ ->
        when (node) {
          is PlusTDTreeNode -> {
            val value = node.immutableChildView
              .asSequence()
              .drop(1)
              .toImmutableSet()
              .also { check(it.size == node.childCount - 1) }
            if (value.isNotEmpty()) {
              yield(value)
            }
          }
          is OptionalTDTreeNode,
          is StarTDTreeNode,
          -> {
            yield(setOf(node))
          }
          is AlternativeBlockTDTreeNode,
          is CharTDTreeNode,
          is SequenceTDTreeNode,
          -> {
            when (node.parent) {
              is PlusTDTreeNode,
              is StarTDTreeNode,
              is OptionalTDTreeNode,
              -> yield(setOf(node))
              else -> Unit
            }
          }
        }
        TreeNodeFilterResult.CONTINUE
      }
    }
  }
}
