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
import org.perses.grammar.dyck.PristineBraceParenthesisBracketDyckParserFacade

@RunWith(JUnit4::class)
class PristineDyckNodeReducerTest {
  private val cFacade =
    SingleParserFacadeFactory
      .builderWithBuiltinLanguages()
      .build()
      .getParserFacadeListForOrNull(LanguageC)!!
      .defaultParserFacade
      .create()

  @Test
  fun realFacadeYieldsPristineBraceParenBracketDyckWrappingTheRealLexer() {
    val dyck = PersesNodeReducerAnnotations.pristineDyckFacadeFor(cFacade)
    assertThat(dyck).isInstanceOf(PristineBraceParenthesisBracketDyckParserFacade::class.java)
    assertThat(dyck.underlyingLexerClass).isEqualTo(cFacade.lexerClass)
  }

  @Test
  fun dyckCanonicalStillWrapsTheRealLexerNotTheDyckLexer() {
    // If the file's spine already fell back to Dyck, its lexerClass is the Dyck lexer; the derivation
    // must reach through to the real lexer it wraps, not tokenize with the Dyck lexer again.
    val dyckCanonical = PristineBraceParenthesisBracketDyckParserFacade(cFacade.lexerClass)
    val dyck = PersesNodeReducerAnnotations.pristineDyckFacadeFor(dyckCanonical)
    assertThat(dyck.underlyingLexerClass).isEqualTo(cFacade.lexerClass)
    assertThat(dyck.underlyingLexerClass).isNotEqualTo(dyckCanonical.lexerClass)
  }

  @Test
  fun derivedPristineDyckFacadeParsesBalancedButGrammarIllegalInput() {
    // `{ 4 }` in expression position is balanced but no C production can place it; the derived pristine
    // Dyck facade nests it instead of failing.
    PersesNodeReducerAnnotations
      .pristineDyckFacadeFor(cFacade)
      .parseString("int a = 3 { 4 } ;", errorMode = ParseErrorHandling.STRICT)
  }

  @Test
  fun tolerantPristineDyckParseRecoversUnbalancedInputInsteadOfNpe() {
    // Unbalanced `{`: the pristine Dyck parser hits EOF mid-construct and ANTLR error recovery
    // fabricates a missing symbol. Tolerant parsing must still recover a tree (with the error
    // recorded), not fail, so the pass can reduce it.
    val result =
      PersesNodeReducerAnnotations
        .pristineDyckFacadeFor(cFacade)
        .parseString("int a = 3 { 4 ;", errorMode = ParseErrorHandling.TOLERANT)
    assertThat(result.hasError).isTrue()
  }
}
