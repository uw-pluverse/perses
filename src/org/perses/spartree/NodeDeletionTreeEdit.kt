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
package org.perses.spartree

import org.perses.program.TokenizedProgram

class NodeDeletionTreeEdit internal constructor(
  tree: SparTree,
  actionSet: NodeDeletionActionSet
) : AbstractSparTreeEdit<NodeDeletionAction>(actionSet, computeProgram(tree, actionSet)) {

  init {
    require(!actionSet.isEmpty)
  }

  private class TokenizedProgramConstructor(
    actionSet: NodeDeletionActionSet
  ) : AbstractTokenizedProgramCustomizer(actionSet) {

    override fun visit(node: AbstractSparTreeNode): List<AbstractSparTreeNode> {
      assert(!node.isPermanentlyDeleted)
      if (node.isPermanentlyDeleted) {
        return emptyList()
      }
      if (targets.contains(node)) {
        return emptyList()
      }
      if (pathsToRootExcludingTargets.contains(node)) {
        return node.immutableChildView
      }
      addTokenIntervalToResult(node)
      return emptyList()
    }
  }

  companion object {
    private fun computeProgram(
      tree: SparTree,
      actionSet: NodeDeletionActionSet
    ): TokenizedProgram {
      return tree.customizeProgram(TokenizedProgramConstructor(actionSet))
    }
  }
}
