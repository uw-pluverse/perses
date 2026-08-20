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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.grammar.dyck.AdaptiveDyckParserFacade
import org.perses.grammar.dyck.BraceDyckParserFacade
import org.perses.grammar.dyck.BraceParenthesisDyckParserFacade
import org.perses.grammar.line.LineParserFacade
import org.perses.grammar.onetoken.OneTokenParserFacade

@RunWith(JUnit4::class)
class TolerantFallbackParserFacadesTest {
  private val factory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
  private val cFacade =
    factory.getParserFacadeListForOrNull(LanguageC)!!.defaultParserFacade.create()

  private fun AbstractParserFacade.parses(source: String): Boolean =
    try {
      parseString(source, errorMode = ParseErrorHandling.STRICT)
      true
    } catch (e: Exception) {
      false
    }

  // The fallback ladder materialized by walking the successor relation from [start].
  private fun ladder(start: AbstractParserFacade): List<AbstractParserFacade> =
    buildList {
      var next = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(start)
      while (next != null) {
        add(next)
        next = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(next)
      }
    }

  @Test
  fun theLadderIsOneRungBelowTheRealGrammar() {
    assertThat(ladder(cFacade).map { it::class.java })
      .containsExactly(AdaptiveDyckParserFacade::class.java)
  }

  @Test
  fun theDyckRungWrapsTheRealLexerAndIsTheFloor() {
    val dyck = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(cFacade)!!
    assertThat((dyck as AdaptiveDyckParserFacade).underlyingLexerClass)
      .isEqualTo(cFacade.lexerClass)
    assertThat(TolerantFallbackParserFacades.nextTolerantFallbackOrNull(dyck)).isNull()
  }

  @Test
  fun terminalGrammarsHaveNoSuccessor() {
    // Neither is reachable as a fallback any more, but either can be the starting facade.
    assertThat(
      TolerantFallbackParserFacades.nextTolerantFallbackOrNull(LineParserFacade()),
    ).isNull()
    assertThat(
      TolerantFallbackParserFacades.nextTolerantFallbackOrNull(OneTokenParserFacade()),
    ).isNull()
  }

  @Test
  fun anExplicitlySelectedFixedDyckFacadeFallsBackToTheAdaptiveOne() {
    // A user can still pick a fixed Dyck facade with --parser-facade-class-name; it is not a floor,
    // and its successor reaches through to the real lexer rather than re-tokenizing with the Dyck one.
    val fixed = BraceDyckParserFacade(cFacade.lexerClass)
    val next = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(fixed)
    assertThat(next).isInstanceOf(AdaptiveDyckParserFacade::class.java)
    assertThat(
      (next as AdaptiveDyckParserFacade).underlyingLexerClass,
    ).isEqualTo(cFacade.lexerClass)
  }

  @Test
  fun balancedButInvalidProgramFallsToDyck() {
    // `if ()` has an empty condition: balanced delimiters, but not valid C.
    val source = "if ( ) { }"
    assertThat(cFacade.parses(source)).isFalse()
    val first = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(cFacade)!!
    assertThat(first).isInstanceOf(AdaptiveDyckParserFacade::class.java)
    assertThat(first.parses(source)).isTrue()
  }

  @Test
  fun theDyckRungAlsoCatchesWhatUsedToFallThroughToLine() {
    // Unbalanced `(` and `{`: no fixed Dyck facade parses this, which is what the Line rung existed
    // for. The adaptive rung demotes both kinds and reads it as lines instead.
    val source = "int f( {"
    val dyck = ladder(cFacade).single()
    assertThat(BraceParenthesisDyckParserFacade(cFacade.lexerClass).parses(source)).isFalse()
    assertThat(BraceDyckParserFacade(cFacade.lexerClass).parses(source)).isFalse()
    assertThat(dyck.parses(source)).isTrue()
  }

  @Test
  fun lineGrammarParsesArbitraryAndEmptyInput() {
    val line = LineParserFacade()
    assertThat(line.parses("")).isTrue()
    assertThat(line.parses("\n\n")).isTrue()
    assertThat(line.parses("@#% anything at all <> ][ )(")).isTrue()
  }
}
