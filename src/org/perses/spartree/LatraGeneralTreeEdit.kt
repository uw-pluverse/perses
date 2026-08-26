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
package org.perses.spartree

import org.perses.util.lazyAssert
import org.perses.program.TokenizedProgram
import org.perses.util.lazyAssert

class LatraGeneralTreeEdit internal constructor(
  tree: SparTree,
  actionSet: LatraGeneralActionSet,
) : AbstractSparTreeEdit<AbstractTargetedTreeEditAction>(actionSet, tree) {
  override fun internalComputeProgram(tree: SparTree): TokenizedProgram =
    tree.customizeProgram(TokenizedProgramConstructor(actionSet))

  override val structureDescriptionPrefix: String
    get() = "LatraEdit"

  override fun internalApplyToTree() {
    actionSet.actions.forEach { action ->
      lazyAssert { !action.targetNode.isPermanentlyDeleted }
      action.apply()
    }
  }

  override fun computeDeletedTokens(): AbstractDeletedTokens =
    AbstractDeletedTokens.Unsupported(this::class.java)

  private class TokenizedProgramConstructor(
    private val actionSet: AbstractActionSet<AbstractTargetedTreeEditAction>,
  ) : AbstractTokenizedProgramCustomizer(actionSet) {
    override fun visit(node: AbstractSparTreeNode): List<AbstractSparTreeNode> {
      lazyAssert { !node.isPermanentlyDeleted }
      if (node.isPermanentlyDeleted) {
        return emptyList()
      }
      if (targets.contains(node)) {
        when (val action = actionSet.getActionForTarget(node)) {
          is NodeReplacementAction -> {
            addTokenIntervalToResult(action.replacingNode)
          }

          is NodeDeletionAction -> {
            // Do nothing
          }

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
