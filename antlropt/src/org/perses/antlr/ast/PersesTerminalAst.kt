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
package org.perses.antlr.ast

import com.google.common.base.MoreObjects
import org.antlr.v4.parse.ANTLRLexer
import org.antlr.v4.parse.ANTLRParser
import org.perses.antlr.RuleType
import org.perses.util.ast.Indent
import java.io.PrintStream

class PersesTerminalAst(
  val text: String,
  val tokenType: Int,
) : AbstractPersesTerminalAst() {

  init {
    require(text.isNotEmpty()) { text }
  }

  val isTokenRef: Boolean
    get() = tokenType == ANTLRParser.TOKEN_REF

  override fun createWithNewChildren(
    newChildren: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    require(newChildren.isEmpty()) { newChildren }
    return PersesTerminalAst(text, tokenType)
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    stream.print(text)
  }

  fun isStringLiteral(): Boolean {
    val result = text[0] == '\''
    check(!result || (text.length > 1 && text[text.length - 1] == '\''))
    return result
  }

  fun isWildcardDot(): Boolean {
    return text == "."
  }

  fun getStringLiteralOrThrow(): String {
    check(isStringLiteral()) { text }
    return text.substring(1, endIndex = text.length - 1)
  }

  fun isEOF(): Boolean {
    val result = text == "EOF"
    check(!result || tokenType == ANTLRLexer.TOKEN_REF)
    return result
  }

  override val extraLabelForTreeStructurePrinting: String
    get() = super.extraLabelForTreeStructurePrinting + ", token=" + text

  override val tag = AstTag.TERMINAL

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("text", text).add("type", tokenType).toString()
  }

  override fun extraEquivalenceTest(other: AbstractPersesRuleElement): Boolean {
    val ast = other as PersesTerminalAst
    return text == ast.text && tokenType == ast.tokenType
  }

  companion object {

    fun createTokenReference(lexerRuleName: String): PersesTerminalAst {
      require(RuleType.isLexerRule(lexerRuleName)) { lexerRuleName }
      return PersesTerminalAst(lexerRuleName, tokenType = ANTLRParser.TOKEN_REF)
    }
  }
}
