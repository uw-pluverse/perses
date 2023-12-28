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
package org.perses.antlr.pnf

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility
import org.perses.antlr.GrammarTestingUtility.loadGrammarFromFile

@RunWith(JUnit4::class)
class QuantifiedAstNormalizationPassTest {
  private var starGrammar = GrammarTestingUtility.createPersesGrammarFromString(
    """
    start
    : rule*
    | ID*
    | 'test'*
    | ('A' | 'B')*
    | ('C' | 'D' | 'E')*
    | ('F' | 'G' | another)*
    ;
    """.trimIndent(),
  )

  @Test
  fun testQuantifiedAstNormalizationPass_idempotency_nested_quantified() {
    val persesGrammar = loadGrammarFromFile("nested_quantified.g4")
    val pass = QuantifiedAstNormalizationPass()
    val firstRound = pass.processGrammar(GrammarPair(persesGrammar, lexerGrammar = null))
    val firstRoundParserGrammar = firstRound.parserGrammar!!
    val secondRound = pass.processGrammar(firstRound)
    val secondRoundParserGrammar = secondRound.parserGrammar!!
    assertThat(firstRoundParserGrammar.parserRules.map { it.ruleNameHandle })
      .containsExactlyElementsIn(secondRoundParserGrammar.parserRules.map { it.ruleNameHandle })
    for (ruleName in firstRoundParserGrammar.parserRules.map { it.ruleNameHandle }) {
      assertThat(
        firstRoundParserGrammar.getRuleDefinition(ruleName)!!.body.isEquivalent(
          secondRoundParserGrammar.getRuleDefinition(ruleName)!!.body,
        ),
      ).isTrue()
    }
  }

  @Test
  fun testNormalizingStar() {
    val pass = QuantifiedAstNormalizationPass()
    val newGrammar = pass.processGrammar(GrammarPair(starGrammar, lexerGrammar = null))
    val sourceCode = newGrammar.parserGrammar!!.sourceCode
    println(sourceCode)
    PnfCheckPass().processGrammar(newGrammar)
  }
}
