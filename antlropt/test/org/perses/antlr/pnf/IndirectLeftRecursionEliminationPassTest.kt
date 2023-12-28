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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility.getSortedSccList
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesRuleReferenceAst.Companion.create
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.RuleNameRegistry

@RunWith(JUnit4::class)
class IndirectLeftRecursionEliminationPassTest : PnfLeftTestGrammar() {

  private var pass: IndirectLeftRecursionEliminationPass = IndirectLeftRecursionEliminationPass()

  @Test
  fun testGetFirstIfIsRuleRef() {
    val registry = RuleNameRegistry()
    val name = registry.getOrCreate("a")
    val ref = create(name)
    assertThat(pass.getRuleRefToInline(ref)).isEqualTo(name)
    val terminal = PersesTerminalAst("t", 0)
    run {
      val seqWithFirstAsRef = PersesSequenceAst(ImmutableList.of(ref, terminal))
      assertThat(pass.getRuleRefToInline(seqWithFirstAsRef)).isEqualTo(name)
    }
    run {
      val seqWithoutFirstAsRef = PersesSequenceAst(ImmutableList.of(terminal, ref))
      assertThat(pass.getRuleRefToInline(seqWithoutFirstAsRef)).isNull()
    }
    assertThat(pass.getRuleRefToInline(terminal)).isNull()
  }

  @Test
  fun test_inlineFirstRuleRef() {
    run {
      val ele = pass.inlineRuleRef(edge_ad, edge_a)
      assertThat(ele).isInstanceOf(PersesSequenceAst::class.java)
      val seq = ele as PersesSequenceAst
      assertThat(seq.childCount).isEqualTo(2)
      assertThat(seq.getChild(0).sourceCode).isEqualTo(edge_a.sourceCode)
      assertThat(seq.getChild(1).sourceCode).isEqualTo("d")
    }
  }

  @Test
  fun testComputeScc() {
    val sccSet = getSortedSccList(graph)
    assertThat(sccSet).hasSize(3)
    run {
      val scc = sccSet[0]
      assertThat(scc.vertexSet()).containsExactly(a, b)
      assertThat(scc.outgoingEdgesOf(a)).containsExactly(edge_a)
      assertThat(scc.outgoingEdgesOf(b)).containsExactly(edge_ad)
    }
    run {
      val scc = sccSet[1]
      assertThat(scc.vertexSet()).containsExactly(c)
      assertThat(scc.outDegreeOf(c)).isEqualTo(0)
    }
    run {
      val scc = sccSet[2]
      assertThat(scc.vertexSet()).containsExactly(d)
      assertThat(scc.outDegreeOf(d)).isEqualTo(0)
    }
  }

  @Test
  fun test_transformLeftForScc() {
    val grammars: List<Set<RuleNameRegistry.RuleNameHandle>> = getSortedSccList(graph)
      .asSequence()
      .map { it.vertexSet() }
      .toList()
    run {
      val g = grammars[0]
      val result = MutableGrammar.createParserRulesFrom(grammar)
      pass.transformForScc(ProjectedHashMultimap(result, g))
      assertThat(result.ruleNameSequence().sorted().toList()).containsAtLeast(a, b)
      run {
        val defs = result.getAltBlock(a)
        assertThat(defs).hasSize(1)
        assertThat(defs).contains(edge_a)
        assertThat(defs.filter { it.tag == AstTag.EPSILON }).hasSize(0)
      }
      run {
        val defs = result.getAltBlock(b)
        assertThat(defs).hasSize(2)
        val defStrings = defs
          .asSequence()
          .map { it.sourceCode }
          .sorted()
          .toList()
        assertThat(defStrings).containsExactly("c d", "(b c | d)? d")
      }
    }
    run {
      val g = grammars[1]
      val result = MutableGrammar.createParserRulesFrom(grammar)
      pass.transformForScc(ProjectedHashMultimap(result, g))
      val defs = result.getAltBlock(c)
      assertThat(defs).hasSize(1)
      assertThat(defs.iterator().next().sourceCode).isEqualTo("'c'")
    }
    run {
      val g = grammars[2]
      val result = MutableGrammar.createParserRulesFrom(grammar)
      pass.transformForScc(ProjectedHashMultimap(result, g))
      assertThat(
        result
          .getAltBlock(d)
          .asSequence()
          .map { it.sourceCode }
          .toList(),
      )
        .containsExactly("'d'")
    }
  }
}
