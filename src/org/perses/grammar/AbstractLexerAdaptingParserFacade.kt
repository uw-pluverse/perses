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
package org.perses.grammar

import com.google.common.primitives.ImmutableIntArray
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Parser
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.grammar.AbstractParserFacade.Companion.getCharStreamConstructorFromLexer
import org.perses.program.LanguageKind

/**
 * A facade whose grammar is language-agnostic and which therefore does not tokenize the source
 * itself: it adapts the *real* language's lexer, re-typing its tokens to its own vocabulary. Dyck
 * and FlatTokenList are both of this kind.
 *
 * Declaring it as a type rather than as an overridable default on [AbstractParserFacade] is what
 * makes the distinction hard to get wrong. Such a facade's own [lexerClass] is the adaptor, not the
 * lexer that decides what the tokens are, so anything needing the file's real tokenization would
 * otherwise have to enumerate the adaptor types at every site -- and would silently miss any adaptor
 * it did not know about. Extending this class supplies [underlyingLexerClass] as a constructor
 * parameter, so a new adaptor cannot inherit a wrong answer by omission.
 */
abstract class AbstractLexerAdaptingParserFacade protected constructor(
  language: LanguageKind,
  antlrGrammar: AbstractAntlrGrammar,
  identifierTokenTypes: ImmutableIntArray,
  includeAutoDetectedIdentifierTokenTypes: Boolean,
  lexerClass: Class<out Lexer>,
  parserClass: Class<out Parser>,
  /** The lexer of the language actually being read, which this facade's grammar adapts. */
  val underlyingLexerClass: Class<out Lexer>,
) : AbstractParserFacade(
    language,
    antlrGrammar,
    identifierTokenTypes,
    includeAutoDetectedIdentifierTokenTypes,
    lexerClass,
    parserClass,
  ) {
  final override val realLexerClass: Class<out Lexer>
    get() = underlyingLexerClass

  /**
   * Instantiates the adapted lexer over [inputStream], for a subclass's [createLexer] to wrap.
   *
   * Deliberately unlike [AbstractParserFacade.createLexer], which attaches a listener that fails on
   * the first lexer error: an adapting facade exists precisely to keep reading input its underlying
   * lexer cannot fully tokenize, so the underlying lexer must be allowed to report errors and carry
   * on. The adaptor decides what to do with the characters that result.
   */
  protected fun createUnderlyingLexer(inputStream: CharStream): Lexer =
    getCharStreamConstructorFromLexer(underlyingLexerClass).newInstance(inputStream)
}
