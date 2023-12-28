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
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesRuleReferenceAst

@RunWith(JUnit4::class)
class ConvertAllAltToRuleReferenceOrTerminalPassTest {

  val pass = ConvertAllAltToRuleReferenceOrTerminalPass()

  @Test
  fun test() {
    val orig = GrammarTestingUtility.createPersesGrammarFromString(
      """
        start: 'a' 'b' 
             | 'c' 'd'
             ;
      """.trimIndent(),
    )
    val processed = pass.processGrammar(
      GrammarPair(orig, lexerGrammar = null),
    ).parserGrammar!!
    val body = processed.getRuleDefinition("start")!!.body
    assertThat(body).isInstanceOf(PersesAlternativeBlockAst::class.java)
    assertThat(body.childCount).isEqualTo(2)
    body.childSequence().forEach {
      assertThat(it).isInstanceOf(PersesRuleReferenceAst::class.java)
    }
  }
}
