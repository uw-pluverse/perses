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
package org.perses.spartree

import org.perses.program.TokenizedProgram
import org.perses.util.Util.lazyAssert

class NodeDeletionTreeEdit internal constructor(
  tree: SparTree,
  actionSet: NodeDeletionActionSet,
) : AbstractSparTreeEdit<NodeDeletionAction>(actionSet, tree) {

  init {
    require(!actionSet.isEmpty) { "The passed-in action set is empty." }
  }

  override fun internalApplyToTree() {
    actionSet.actions.forEach { action ->
      action.apply()
    }
  }

  override fun computeProgram(tree: SparTree): TokenizedProgram {
    return tree.customizeProgram(TokenizedProgramConstructor(actionSet))
  }

  private class TokenizedProgramConstructor(
    actionSet: AbstractActionSet<NodeDeletionAction>,
  ) : AbstractTokenizedProgramCustomizer(actionSet) {

    override fun visit(node: AbstractSparTreeNode): List<AbstractSparTreeNode> {
      lazyAssert { !node.isPermanentlyDeleted }
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
}
