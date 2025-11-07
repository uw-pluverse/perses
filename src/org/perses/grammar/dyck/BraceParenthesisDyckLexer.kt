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
package org.perses.grammar.dyck

import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Lexer
import org.perses.grammar.AbstractTwinLexerAntlrBridge

class BraceParenthesisDyckLexer(
  underlyingLexer: Lexer,
) : AbstractDyckLexer(underlyingLexer) {
  override fun convertToNewToken(text: String) =
    when (text) {
      "{" -> CommonToken(PnfDyckParser.OPEN_BRACE, text)
      "}" -> CommonToken(PnfDyckParser.CLOSE_BRACE, text)
      "(" -> CommonToken(PnfDyckParser.OPEN_PARENTHESIS, text)
      ")" -> CommonToken(PnfDyckParser.CLOSE_PARENTHESIS, text)
      else -> CommonToken(PnfDyckParser.OTHER, text)
    }

  object BRIDGE : AbstractTwinLexerAntlrBridge(
    lexerClass = BraceParenthesisDyckLexer::class.java,
    parserClass = PnfDyckParser::class.java,
  )

  companion object {
    @JvmField
    val LEXER_WRAPPER = BRIDGE.lexerAtnWrapper
  }
}
