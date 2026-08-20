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
import com.google.common.collect.ImmutableList
import org.perses.program.AbstractPersesToken

class DescendantHoistingTreeEdit internal constructor(
  tree: SparTree,
  actionSet: NodeReplacementActionSet,
) : AbstractNodeReplacementTreeEdit(tree, actionSet) {
  init {
    require(actionSet.actions.size == 1) {
      "Only single action is allowed for not."
    }
  }

  override fun computeDeletedTokens(): AbstractDeletedTokens.DeletedTokens {
    val result = ImmutableList.builder<AbstractPersesToken.AntlrToken>()
    val action = actionSet.actions.single()
    val target = action.targetNode
    val replacement = action.replacingNode
    val exclusionStart = replacement.beginToken!!
    var token = target.beginToken
    while (token != null && token !== exclusionStart) {
      result.add(token.token.asAntlrToken())
      token = token.next
    }
    token = replacement.endToken!!.next
    val exclusionEnd = target.endToken!!.next
    while (token != null && token !== exclusionEnd) {
      result.add(token.token.asAntlrToken())
      token = token.next
    }
    return AbstractDeletedTokens.DeletedTokens(result.build())
  }

  override val structureDescriptionPrefix: String
    get() = "HoistEdit"

  override fun internalApplyToTree() {
    val action = actionSet.actions.single()
    action.replacingNode.let { descendantToHoist ->
      checkNotNull(descendantToHoist.parent) {
        "The replacing child has no parent. This action is for hoisting a descendant. " +
          "You may want to use ${AnyNodeReplacementTreeEdit::class} instead"
      }
      descendantToHoist.parent!!.removeChild(descendantToHoist)
      check(descendantToHoist.parent == null)
    }
    action.apply()
  }
}
