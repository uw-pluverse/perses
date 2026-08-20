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
package org.perses.grammar.dyck

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.perses.grammar.AbstractLexerAdaptingParserFacade
import org.perses.program.LanguageKind

// The Dyck lexer emits PnfLineAwareDyckParser-typed tokens, so every parser plugged in here
// (line-aware or pristine) must share that token numbering. Both grammars draw their vocabulary from
// the shared DyckTokens lexer grammar to satisfy this; PristineDyckParserFacadeTest guards the invariant.
abstract class AbstractDyckParserFacade(
  language: LanguageKind,
  private val configurationSelector: DyckLexer.ConfigurationSelector,
  // The tolerant-grammar fallback ladder derives the next, more-general Dyck rung from a Dyck facade
  // while keeping the same underlying lexer (see TolerantFallbackParserFacades).
  underlyingLexerClass: Class<out Lexer>,
  pnfParserGrammarFileName: String,
  pnfParserClass: Class<out Parser>,
) : AbstractLexerAdaptingParserFacade(
    language = language,
    antlrGrammar =
      createSeparateAntlrParserGrammarOnly(
        startRuleName = "start",
        antlrParserGrammarFileName = pnfParserGrammarFileName,
        classUnderSamePkg = AbstractDyckParserFacade::class.java,
      ),
    identifierTokenTypes = ImmutableIntArray.of(),
    includeAutoDetectedIdentifierTokenTypes = false,
    lexerClass = DyckLexer::class.java,
    parserClass = pnfParserClass,
    underlyingLexerClass = underlyingLexerClass,
  ) {
  override fun createLexer(inputStream: CharStream): Lexer =
    DyckLexer(createUnderlyingLexer(inputStream), configurationSelector)
}
