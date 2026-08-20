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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.util.Util

/**
 * Note that this class should not be a data class, as we need the default hashCode() and equals().
 */
class NodeContainerForListMinimizer(
  val nodes: ImmutableList<out AbstractSparTreeNode>,
) {
  init {
    require(nodes.isNotEmpty()) { "The nodes should not be empty" }
    Util.lazyAssert(
      test = {
        nodes.none { it.isPermanentlyDeleted }
      },
      message = {
        "There are nodes already deleted. ${nodes.filter { it.isPermanentlyDeleted }}"
      },
    )
  }

  val tokenCount: Int
    get() {
      return nodes.sumOf {
        if (it.isPermanentlyDeleted) {
          0
        } else {
          it.leafTokenCount
        }
      }
    }

  fun areAllNodesPermanentlyDeleted(): Boolean = nodes.all { it.isPermanentlyDeleted }

  override fun toString(): String {
    val builder = StringBuilder()
    val size = nodes.size
    for (i in 0 until size) {
      val node = nodes[i]
      if (size > 1) {
        if (i > 0) {
          builder.append(", ")
        }
        builder.append(i).append('.')
      }
      when (node) {
        is ParserRuleSparTreeNode -> {
          val position =
            node.endToken?.let { endToken ->
              endToken.token
                .asAntlrToken()
                .position
                .toConcisePosition()
            } ?: "N.A."
          val id = node.nodeId
          builder.append("parser($id,#tokens=${node.leafTokenCount},last-pos=$position)")
        }

        is LexerRuleSparTreeNode -> {
          val id = node.nodeId
          val position =
            node.token
              .asAntlrToken()
              .position
              .toConcisePosition()
          builder.append("lexer($id,pos=$position)")
        }

        else -> builder.append(node)
      }
    }
    return builder.toString()
  }

  companion object {
    fun of(node: AbstractSparTreeNode) =
      NodeContainerForListMinimizer(nodes = ImmutableList.of(node))
  }
}
