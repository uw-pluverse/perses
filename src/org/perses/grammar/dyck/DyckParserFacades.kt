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

import org.antlr.v4.runtime.Lexer

class BraceDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguageBraceDyck,
    configurationSelector = DyckLexer.BRACE,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfLineAwareDyckParser.g4",
    pnfParserClass = PnfLineAwareDyckParser::class.java,
  )

class BraceParenthesisDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguageBraceParenthesisDyck,
    configurationSelector = DyckLexer.BRACE_PARENTHESIS,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfLineAwareDyckParser.g4",
    pnfParserClass = PnfLineAwareDyckParser::class.java,
  )

class BraceParenthesisBracketDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguageBraceParenthesisBracketDyck,
    configurationSelector = DyckLexer.BRACE_PARENTHESIS_BRACKET,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfLineAwareDyckParser.g4",
    pnfParserClass = PnfLineAwareDyckParser::class.java,
  )

class PristineBraceDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguagePristineBraceDyck,
    configurationSelector = DyckLexer.BRACE,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfPristineDyckParser.g4",
    pnfParserClass = PnfPristineDyckParser::class.java,
  )

class PristineBraceParenthesisDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguagePristineBraceParenthesisDyck,
    configurationSelector = DyckLexer.BRACE_PARENTHESIS,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfPristineDyckParser.g4",
    pnfParserClass = PnfPristineDyckParser::class.java,
  )

class PristineBraceParenthesisBracketDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguagePristineBraceParenthesisBracketDyck,
    configurationSelector = DyckLexer.BRACE_PARENTHESIS_BRACKET,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfPristineDyckParser.g4",
    pnfParserClass = PnfPristineDyckParser::class.java,
  )

/**
 * The delimiter kinds are chosen per input rather than baked into the facade, so a file whose braces
 * (or parentheses, or brackets) do not nest still parses -- the offending kind is demoted to plain
 * text and the kinds that do nest keep their structure. See [AdaptiveDyckConfigurationSelector].
 */
class AdaptiveDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguageAdaptiveDyck,
    configurationSelector = AdaptiveDyckConfigurationSelector,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfLineAwareDyckParser.g4",
    pnfParserClass = PnfLineAwareDyckParser::class.java,
  )

/** The pristine (line-oblivious) counterpart of [AdaptiveDyckParserFacade]. */
class PristineAdaptiveDyckParserFacade(
  underlyingLexerClass: Class<out Lexer>,
) : AbstractDyckParserFacade(
    language = LanguagePristineAdaptiveDyck,
    configurationSelector = AdaptiveDyckConfigurationSelector,
    underlyingLexerClass = underlyingLexerClass,
    pnfParserGrammarFileName = "PnfPristineDyckParser.g4",
    pnfParserClass = PnfPristineDyckParser::class.java,
  )
