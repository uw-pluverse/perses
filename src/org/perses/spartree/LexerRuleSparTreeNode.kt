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

import com.google.common.base.MoreObjects
import org.perses.antlr.RuleHierarchyEntry
import org.perses.program.PersesTokenFactory.AbstractPersesToken

class LexerRuleSparTreeNode internal constructor(
  nodeId: Int,
  val token: AbstractPersesToken,
  antlrRule: RuleHierarchyEntry?,
) : AbstractSparTreeNode(nodeId, antlrRule) {
  @PublishedApi
  internal var prev: LexerRuleSparTreeNode? = null

  @PublishedApi
  internal var next: LexerRuleSparTreeNode? = null

  val prevLexerRuleTreeNode: LexerRuleSparTreeNode?
    get() = prev

  val nextLexerRuleTreeNode: LexerRuleSparTreeNode?
    get() = next

  override val labelPrefix: String
    get() = "Token:" + token.lexemeText

  override fun buildTokenIntervalInfoForCurrentNode() {
    // do nothing
  }

  override fun internalCopyCurrentNode(computedNewNodeId: Int): LexerRuleSparTreeNode =
    LexerRuleSparTreeNode(computedNewNodeId, token, antlrRule)

  override fun addChildAtIndex(
    index: Int,
    child: AbstractSparTreeNode,
    payload: AbstractNodePayload,
  ) {
    error("Cannot call this method on a token node.")
  }

  override fun asLexerRule(): LexerRuleSparTreeNode = this

  override fun onChildRemoved(
    index: Int,
    child: AbstractSparTreeNode,
  ) {
    error("Cannot call this method on a token node.")
  }

  override var beginToken: LexerRuleSparTreeNode?
    get() = this
    set(_) = error("Cannot change this")

  override var endToken: LexerRuleSparTreeNode?
    get() = this
    set(_) = error("Cannot change this")

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("token", token)
      .addValue(super.toString())
      .toString()
}
