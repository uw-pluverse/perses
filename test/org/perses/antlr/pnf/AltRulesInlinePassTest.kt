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
import org.perses.antlr.ast.AbstractPersesAst
import org.perses.antlr.ast.PersesAlternativeBlockAst
import java.util.stream.Collectors

@RunWith(JUnit4::class)
class AltRulesInlinePassTest {
  private var pass = InlineSingleUseAltRulePass()

  @Test
  fun test() {
    val grammar = createPersesGrammarFromString("a : b | c;", "b : d | e;")
    val processed = pass.processGrammar(
      GrammarPair(grammar, lexerGrammar = null),
    ).parserGrammar!!
    val a = processed.getRuleDefinition("a")!!.body
    Truth.assertThat(a).isInstanceOf(PersesAlternativeBlockAst::class.java)
    val altBlock = a as PersesAlternativeBlockAst
    Truth.assertThat(altBlock.alternatives).hasSize(3)
    Truth.assertThat(
      altBlock.alternatives.stream()
        .map(AbstractPersesAst::sourceCode)
        .collect(Collectors.toList()),
    )
      .containsExactly("d", "e", "c")
  }
}
