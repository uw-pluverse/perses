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

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.antlr.ast.PersesAlternativeBlockAst

@RunWith(JUnit4::class)
class InlineSingleUseAltRulePassTest {
  @Test
  fun testWithStartRuleName() {
    val persesGrammar = createPersesGrammarFromString(
      StringBuilder()
        .append("start: b | c | d | f;")
        .append("c: e | d;")
        .append("e: 'e';")
        .append("d: 'e';")
        .append("f: 'm' | 'n';")
        .append("g: f;")
        .toString(),
    )
    run {
      val pass = InlineSingleUseAltRulePass()
      val processed = pass.processGrammar(
        GrammarPair(persesGrammar, lexerGrammar = null),
      ).parserGrammar!!
      val startAlts = (
        processed.getRuleDefinition("start")!!
          .body as PersesAlternativeBlockAst
        ).alternatives
      Truth.assertThat(startAlts).hasSize(4)
      Truth.assertThat(startAlts[0]!!.sourceCode).isEqualTo("b")
      Truth.assertThat(startAlts[1]!!.sourceCode).isEqualTo("e")
      Truth.assertThat(startAlts[2]!!.sourceCode).isEqualTo("d")
      Truth.assertThat(startAlts[3]!!.sourceCode).isEqualTo("f")
    }
  }
}
