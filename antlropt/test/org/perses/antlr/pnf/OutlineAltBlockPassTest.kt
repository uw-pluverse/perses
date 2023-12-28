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
import org.perses.antlr.GrammarTestingUtility
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesSequenceAst

class OutlineAltBlockPassTest {

  val pass = OutlineAltBlockPass()

  @Test
  fun test() {
    val orig = GrammarTestingUtility.createPersesGrammarFromString(
      """
        start: ( 'a' | 'b' ) ( 'c' | 'd' ) 'e'*
              ;
      """.trimIndent(),
    )
    val processed = pass.processGrammar(
      GrammarPair(orig, lexerGrammar = null),
    ).parserGrammar!!
    val body = processed.getRuleDefinition("start")!!.body
    assertThat(body).isInstanceOf(PersesSequenceAst::class.java)
    assertThat(body.childCount).isEqualTo(3)
    var ruleElement = processed.parserRules.find {
      it.ruleNameHandle.ruleName == "altnt_block__start_1"
    }!!.body as PersesAlternativeBlockAst
    assertThat(ruleElement.childCount).isEqualTo(2)
    assertThat(ruleElement.getChild(0).sourceCode.trim()).isEqualTo("'a'")
    assertThat(ruleElement.getChild(1).sourceCode.trim()).isEqualTo("'b'")
    ruleElement = processed.parserRules.find {
      it.ruleNameHandle.ruleName == "altnt_block__start_2"
    }!!.body as PersesAlternativeBlockAst
    assertThat(ruleElement.childCount).isEqualTo(2)
    assertThat(ruleElement.getChild(0).sourceCode.trim()).isEqualTo("'c'")
    assertThat(ruleElement.getChild(1).sourceCode.trim()).isEqualTo("'d'")
  }
}
