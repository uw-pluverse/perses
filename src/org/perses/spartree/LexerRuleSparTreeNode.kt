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

import com.google.common.base.MoreObjects
import com.google.common.escape.CharEscaperBuilder
import org.perses.antlr.RuleHierarchyEntry
import org.perses.program.AbstractPersesToken

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
    get() = "Token:" + escaper.escape(token.lexemeText)

  override fun buildTokenIntervalInfoForCurrentNode() {
    rawLeafTokenCount = 1
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

  override fun deleteCurrentNode() {
    super.deleteCurrentNode()
    prev = null
    next = null
  }

  override fun asLexerRule(): LexerRuleSparTreeNode = this

  override fun onChildRemoved(
    index: Int,
    child: AbstractSparTreeNode,
  ) {
    error("Cannot call this method on a token node.")
  }

  override var beginToken: LexerRuleSparTreeNode?
    get() {
      check(!isPermanentlyDeleted) {
        "The current node $this is already deleted."
      }
      return this
    }
    set(value) {
      check(value == null) {
        "Can only set this value to null."
      }
    }

  override var endToken: LexerRuleSparTreeNode?
    get() {
      check(!isPermanentlyDeleted) {
        "The current node $this is already deleted."
      }
      return this
    }
    set(value) {
      check(value == null) {
        "Can only set this value to null."
      }
    }

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("token", token)
      .addValue(super.toString())
      .toString()

  companion object {
    private val escaper =
      CharEscaperBuilder()
        .addEscape('\n', "\\n")
        .addEscape('\t', "\\t")
        .addEscape('\r', "\\r")
        .toEscaper()
  }
}
