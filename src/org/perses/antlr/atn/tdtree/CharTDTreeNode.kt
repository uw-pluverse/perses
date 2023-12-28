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
import org.perses.spartree.ErrorMessage

class CharTDTreeNode(
  nodeId: Int,
  val char: Char,
) : AbstractTDTreeNode(nodeId) {

  override fun checkNodeIntegrity(): ErrorMessage {
    val builder = ImmutableList.builder<String>()
    if (childCount != 0) {
      builder.add("Should not have any children.")
    }
    return ErrorMessage(builder.build())
  }

  override fun internalCopyCurrentNode(computedNewNodeId: Int): AbstractTDTreeNode {
    return CharTDTreeNode(computedNewNodeId, char)
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("char", char)
      .toString()
  }
}
