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

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Lexer
import org.perses.grammar.AbstractParserFacade
import org.perses.program.LanguageKind

abstract class AbstractDyckParserFacade(
  language: LanguageKind,
  dyckLexerClass: Class<out Lexer>,
  protected val underlyingLexerClass: Class<out Lexer>,
) : AbstractParserFacade(
    language = language,
    antlrGrammar =
      createSeparateAntlrParserGrammarOnly(
        startRuleName = "start",
        antlrParserGrammarFileName = "PnfDyckParser.g4",
        classUnderSamePkg = AbstractDyckParserFacade::class.java,
      ),
    identifierTokenTypes = ImmutableIntArray.of(),
    lexerClass = dyckLexerClass,
    parserClass = PnfDyckParser::class.java,
  ) {
  override fun createLexer(inputStream: CharStream): Lexer {
    val underlyingLexer =
      getCharStreamConstructorFromLexer(underlyingLexerClass).newInstance(inputStream)
    return lexerClass.getDeclaredConstructor(Lexer::class.java).newInstance(underlyingLexer)
  }
}
