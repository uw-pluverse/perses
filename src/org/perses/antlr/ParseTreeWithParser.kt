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
package org.perses.antlr

import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.tree.ParseTree
import org.perses.util.toImmutableList

/**
 * One syntax error ANTLR reported while parsing. Populated only for an error-tolerant parse; a strict
 * or clean parse leaves [ParseTreeWithParser.syntaxErrors] empty.
 */
data class SyntaxError(
  val line: Int,
  val column: Int,
  val message: String,
  val offendingSymbol: Any?,
)

data class ParseTreeWithParser(
  val tree: ParseTree,
  val parser: Parser,
  val lexer: Lexer,
  // Empty for a strict/clean parse; non-empty only when the tree was recovered by tolerant parsing.
  val syntaxErrors: List<SyntaxError> = emptyList(),
) {
  val hasError: Boolean
    get() = syntaxErrors.isNotEmpty()

  val lazyAllTokens by lazy {
    lexer.reset()
    lexer.allTokens
      .filter {
        it.channel == Token.DEFAULT_CHANNEL && it.type != Token.EOF
      }.toImmutableList()
  }

  /**
   * TODO(cnsun): Note that this method does not work for Python, as Python introduces
   *   extra tokens in the parse tree.
   */
  fun isInputCompletelyConsumed(): Boolean {
    val tokensInTree = ParseTreeUtil.getTokens(tree)
    val treeIterator = tokensInTree.iterator()
    val inputIterator = lazyAllTokens.iterator()

    while (treeIterator.hasNext() && inputIterator.hasNext()) {
      val treeToken = treeIterator.next()
      val inputToken = inputIterator.next()
      check(treeToken.text == inputToken.text) {
        """
          | $tokensInTree
          | $lazyAllTokens
        """.trimMargin()
      }
    }
    while (treeIterator.hasNext()) {
      val token = treeIterator.next()
      check(token.type == Token.EOF) {
        """$token
          |$tokensInTree
        """.trimMargin()
      }
    }
    while (inputIterator.hasNext()) {
      val token = inputIterator.next()
      if (token.type != Token.EOF) {
        // unprocessed input tokens found.
        return false
      }
    }
    return true
  }
}
