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
package org.perses.reduction.reducer

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.c.LanguageC
import org.perses.grammar.dyck.AdaptiveDyckParserFacade
import org.perses.grammar.dyck.BraceParenthesisBracketDyckParserFacade

@RunWith(JUnit4::class)
class DyckNodeReducerTest {
  private val cFacade =
    SingleParserFacadeFactory
      .builderWithBuiltinLanguages()
      .build()
      .getParserFacadeListForOrNull(LanguageC)!!
      .defaultParserFacade
      .create()

  @Test
  fun realFacadeYieldsAdaptiveDyckWrappingTheRealLexer() {
    val dyck = PersesNodeReducerAnnotations.dyckFacadeFor(cFacade)
    assertThat(dyck).isInstanceOf(AdaptiveDyckParserFacade::class.java)
    assertThat(dyck.underlyingLexerClass).isEqualTo(cFacade.lexerClass)
  }

  @Test
  fun dyckCanonicalStillWrapsTheRealLexerNotTheDyckLexer() {
    // If the file's spine already fell back to Dyck, its lexerClass is the Dyck lexer; the derivation
    // must reach through to the real lexer it wraps, not tokenize with the Dyck lexer again.
    val dyckCanonical = BraceParenthesisBracketDyckParserFacade(cFacade.lexerClass)
    val dyck = PersesNodeReducerAnnotations.dyckFacadeFor(dyckCanonical)
    assertThat(dyck.underlyingLexerClass).isEqualTo(cFacade.lexerClass)
    assertThat(dyck.underlyingLexerClass).isNotEqualTo(dyckCanonical.lexerClass)
  }

  @Test
  fun derivedDyckFacadeParsesBalancedButGrammarIllegalInput() {
    // `{ 4 }` in expression position is balanced but no C production can place it; the derived Dyck
    // facade nests it instead of failing.
    PersesNodeReducerAnnotations
      .dyckFacadeFor(cFacade)
      .parseString("int a = 3 { 4 } ;", errorMode = ParseErrorHandling.STRICT)
  }

  @Test
  fun derivedDyckFacadeParsesUnbalancedInputWithoutError() {
    // The reason this pass uses the adaptive facade: `{` with no `}` leaves the braces unpaired, so
    // the facade demotes them to plain text and the file still parses strictly. A fixed
    // brace+parenthesis+bracket facade has no parse for it at all (see the test below).
    val result =
      PersesNodeReducerAnnotations
        .dyckFacadeFor(cFacade)
        .parseString("int a = 3 { 4 ;", errorMode = ParseErrorHandling.STRICT)
    assertThat(result.hasError).isFalse()
  }

  @Test
  fun tolerantDyckParseRecoversUnbalancedInputInsteadOfNpe() {
    // Unbalanced `{`: the Dyck parser hits EOF mid-construct and ANTLR error recovery fabricates a
    // missing symbol. The Dyck lexer wraps another lexer, so the current token's TokenSource is null,
    // and stock DefaultErrorStrategy.getMissingSymbol NPEs dereferencing it. Tolerant parsing must
    // still recover a tree (with the error recorded), not fail.
    //
    // A fixed facade, because the adaptive one this pass now derives never enables a delimiter kind
    // that does not pair, and so cannot reach the recovery path this guards.
    val result =
      BraceParenthesisBracketDyckParserFacade(cFacade.realLexerClass)
        .parseString("int a = 3 { 4 ;", errorMode = ParseErrorHandling.TOLERANT)
    assertThat(result.hasError).isTrue()
  }
}
