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
import org.perses.antlr.GrammarTestingUtility.loadGrammarFromFile
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.pnf.MutableGrammar.Companion.createParserRulesFrom
import java.util.stream.Collectors

@RunWith(JUnit4::class)
class RuleDefMapTest {
  @Test
  fun test_toPersesGrammar_terminal() {
    test_toPersesGrammar("terminal.g4")
  }

  @Test
  fun test_toPersesGrammar_alternative() {
    test_toPersesGrammar("alternative.g4")
  }

  @Test
  fun test_toPersesGrammar_pnf_test() {
    test_toPersesGrammar("pnf_test.g4")
  }

  @Test
  fun test_toPersesGrammar_postfix_expression_in_c() {
    test_toPersesGrammar("postfix_expression_in_c.g4")
  }

  companion object {
    private fun test_toPersesGrammar(antlrFileName: String) {
      val persesGrammar = loadGrammarFromFile(antlrFileName)
      val mutableGrammar = createParserRulesFrom(persesGrammar)
      val grammarRoundback = persesGrammar.copyWithNewParserRuleDefs(
        mutableGrammar.toParserRuleAstList(),
      )
      val originalDefs = persesGrammar.flattenedAllRules.stream()
        .sorted(Comparator.comparing(AbstractPersesRuleDefAst::ruleNameHandle))
        .collect(Collectors.toList())
      val afterDefs = grammarRoundback.flattenedAllRules.stream()
        .sorted(Comparator.comparing(AbstractPersesRuleDefAst::ruleNameHandle))
        .collect(Collectors.toList())
      Truth.assertThat(
        originalDefs.stream()
          .map(AbstractPersesRuleDefAst::ruleNameHandle)
          .collect(Collectors.toList()),
      )
        .containsExactlyElementsIn(
          afterDefs.stream()
            .map(AbstractPersesRuleDefAst::ruleNameHandle)
            .collect(Collectors.toList()),
        )
        .inOrder()
      var i = 0
      val size = originalDefs.size
      while (i < size) {
        val orig = originalDefs[i].body
        val after = afterDefs[i].body
        Truth.assertThat(orig.javaClass).isEqualTo(after.javaClass)
        if (orig.tag === AstTag.ALTERNATIVE_BLOCK) {
          val origAlternatives = (orig as PersesAlternativeBlockAst)
            .alternatives.stream()
            .map(AbstractPersesRuleElement::sourceCode)
            .sorted()
            .collect(Collectors.toList())
          val afterAlternatives = (after as PersesAlternativeBlockAst)
            .alternatives.stream()
            .map(AbstractPersesRuleElement::sourceCode)
            .sorted()
            .collect(Collectors.toList())
          Truth.assertThat(origAlternatives).containsExactlyElementsIn(afterAlternatives)
        } else {
          Truth.assertThat(orig).isSameInstanceAs(after)
        }
        ++i
      }
    }
  }
}
