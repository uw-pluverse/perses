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

class LatraGeneralTreeEdit internal constructor(
  tree: SparTree,
  actionSet: LatraGeneralActionSet,
) : AbstractSparTreeEdit<AbstractTreeEditAction>(actionSet, tree) {

  override fun computeProgram(tree: SparTree): TokenizedProgram {
    return tree.customizeProgram(TokenizedProgramConstructor(actionSet))
  }

  override fun internalApplyToTree() {
    actionSet.actions.forEach { action ->
      lazyAssert { !action.targetNode.isPermanentlyDeleted }
      action.apply()
    }
  }

  private class TokenizedProgramConstructor(
    private val actionSet: AbstractActionSet<AbstractTreeEditAction>,
  ) : AbstractTokenizedProgramCustomizer(actionSet) {
    override fun visit(
      node: AbstractSparTreeNode,
    ): List<AbstractSparTreeNode> {
      lazyAssert { !node.isPermanentlyDeleted }
      if (node.isPermanentlyDeleted) {
        return emptyList()
      }
      if (targets.contains(node)) {
        when (val action = actionSet.getActionForTarget(node)) {
          is NodeReplacementAction -> {
            addTokenIntervalToResult(action.replacingNode)
          }

          is NodeDeletionAction -> Unit

          else -> {
            error("Unsupported action: $action")
          }
        }
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
