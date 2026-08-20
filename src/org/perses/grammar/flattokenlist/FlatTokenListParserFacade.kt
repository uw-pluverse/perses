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
package org.perses.grammar.flattokenlist

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Lexer
import org.perses.grammar.AbstractLexerAdaptingParserFacade

/**
 * Parses any input into a flat list of tokens under the `start : TOKEN* EOF` grammar, reusing the
 * target language's real lexer via [FlatTokenListLexer]. The real lexer class is threaded in so the
 * same tokenization the canonical facade produced is replayed here; see [underlyingLexerClass].
 */
class FlatTokenListParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractLexerAdaptingParserFacade(
    language = LanguageFlatTokenList,
    antlrGrammar =
      createSeparateAntlrParserGrammarOnly(
        startRuleName = "start",
        antlrParserGrammarFileName = "PnfFlatTokenList.g4",
        classUnderSamePkg = FlatTokenListParserFacade::class.java,
      ),
    identifierTokenTypes = ImmutableIntArray.of(),
    includeAutoDetectedIdentifierTokenTypes = false,
    lexerClass = FlatTokenListLexer::class.java,
    parserClass = PnfFlatTokenList::class.java,
    underlyingLexerClass = underlyingLexerClass,
  ) {
  override fun createLexer(inputStream: CharStream): Lexer =
    FlatTokenListLexer(createUnderlyingLexer(inputStream))
}
