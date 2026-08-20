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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.Vocabulary
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.RuleNode
import org.antlr.v4.runtime.tree.TerminalNode
import java.util.ArrayDeque

object ParseTreeUtil {
  @JvmStatic
  fun getParserRuleIndex(tree: RuleNode) = tree.ruleContext.ruleIndex

  @JvmStatic
  fun getParserRuleName(
    tree: RuleNode,
    parser: Parser,
  ): String {
    val ruleIndex = getParserRuleIndex(tree)
    return parser.ruleNames[ruleIndex]
  }

  @JvmStatic
  fun getSymbolicTokenTypeName(
    tree: TerminalNode,
    lexerVocabulary: Vocabulary,
  ): String? = getSymbolicTokenTypeName(tree.symbol, lexerVocabulary)

  @JvmStatic
  fun getSymbolicTokenTypeName(
    token: Token,
    lexerVocabulary: Vocabulary,
  ): String? = lexerVocabulary.getSymbolicName(token.type)

  fun getTokens(tree: ParseTree): ImmutableList<Token> {
    val builder = ImmutableList.builderWithExpectedSize<Token>(500)
    val stack = ArrayDeque<ParseTree>()
    stack.push(tree)
    while (stack.size > 0) {
      val current = stack.pop()
      if (current is TerminalNode) {
        builder.add(current.symbol)
        continue
      }
      for (i in current.childCount - 1 downTo 0) {
        stack.push(current.getChild(i))
      }
    }
    return builder.build()
  }
}
