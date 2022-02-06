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
package org.perses.antlr

import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.tree.RuleNode
import org.antlr.v4.runtime.tree.TerminalNode

object ParseTreeUtil {

  @JvmStatic
  fun getRuleName(tree: RuleNode, parser: Parser): String {
    val ruleIndex = tree.ruleContext.ruleIndex
    return parser.ruleNames[ruleIndex]
  }

  @JvmStatic
  fun getTokenName(tree: TerminalNode, lexer: Lexer): String? {
    val tokenType = tree.symbol.type
    return lexer.vocabulary.getSymbolicName(tokenType)
  }

  @JvmStatic
  fun getTokenName(token: Token, lexer: Lexer): String? {
    return lexer.vocabulary.getSymbolicName(token.type)
  }
}
