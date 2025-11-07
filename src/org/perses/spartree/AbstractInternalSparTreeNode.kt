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
package org.perses.spartree

import org.perses.antlr.RuleHierarchyEntry

abstract class AbstractInternalSparTreeNode(
  nodeId: Int,
  antlrRule: RuleHierarchyEntry?,
) : AbstractSparTreeNode(
    nodeId = nodeId,
    antlrRule = antlrRule,
  ) {
  override var beginToken: LexerRuleSparTreeNode? = null

  override var endToken: LexerRuleSparTreeNode? = null

  fun computeLeftmostTokenBasedOnChildren(): LexerRuleSparTreeNode? {
    val size = childCount
    for (i in 0 until size) {
      val child = getChild(i)
      val leftToken = child.beginToken
      if (leftToken != null) {
        return leftToken
      }
    }
    return null
  }

  fun computeRightmostTokenBasedOnChildren(): LexerRuleSparTreeNode? {
    for (i in childCount - 1 downTo 0) {
      val child = getChild(i)
      val rightToken = child.endToken
      if (rightToken != null) {
        return rightToken
      }
    }
    return null
  }

  override fun buildTokenIntervalInfoForCurrentNode() {
    beginToken = computeLeftmostTokenBasedOnChildren()
    endToken = computeRightmostTokenBasedOnChildren()
  }

  override fun onChildRemoved(
    index: Int,
    child: AbstractSparTreeNode,
  ) = Unit
}
