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
import org.perses.antlr.GrammarTestingUtility.computeAltblockRuleName
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.antlr.ast.PersesAlternativeBlockAst

@RunWith(JUnit4::class)
class MultiAltBlockExtractionPassTest {

  private var pass = MultiAltBlockExtractionPass()

  @Test
  fun test_python3_argument() {
    val origGrammar = createPersesGrammarFromString(
      """
        argument: 
                'test' 'comp_for'? |
                'test' '=' 'test' |
                '**' 'test' | 
                '*' 'test' 
                ;
      """.trimIndent(),
    )
    val processedGrammar = pass.processGrammar(
      GrammarPair(parserGrammar = origGrammar, lexerGrammar = null),
    ).parserGrammar!!
    val alts = processedGrammar.parserRules.find {
      it.ruleNameHandle.ruleName == "altnt_block__argument_1"
    }!!.body as PersesAlternativeBlockAst
    assertThat(alts.childCount).isEqualTo(3)
    // Note that the following order matters here. The pass should respecti the original alt order.
    assertThat(alts.getChild(0).sourceCode.trim()).isEqualTo("'test' '='")
    assertThat(alts.getChild(1).sourceCode.trim()).isEqualTo("'**'")
    assertThat(alts.getChild(2).sourceCode.trim()).isEqualTo("'*'")
  }

  @Test
  fun e2eTest_3_alternatives() {
    val origGrammar = createPersesGrammarFromString(
      """
      s : a c d | a b d | a e d;
      """.trimIndent(),
    )
    val processedGrammar = pass.processGrammar(
      GrammarPair(parserGrammar = origGrammar, lexerGrammar = null),
    ).parserGrammar!!
    val auxRuleName = computeAltblockRuleName("s_1")
    /*
     * DO NOT MODIFY THE ORDER OF ALTERNATIVES.
     *
     * Note that the auxiliary rule should be exactly 'c | b'.
     * The order of the two alternatives should be exactly the
     * same as that in its original grammar.
     */
    val goldenGrammar = createPersesGrammarFromString(
      """
      s : a $auxRuleName d;
      $auxRuleName : c | b | e; 
      """.trimIndent(),
    )
    GrammarTestingUtility.checkWithGoldenGrammar(
      processedGrammar.sourceCode,
      goldenGrammar.sourceCode,
    )
  }
}
