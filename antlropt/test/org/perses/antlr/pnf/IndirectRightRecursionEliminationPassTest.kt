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
import org.perses.antlr.pnf.RuleTransitionGraph.Companion.createForRightmostTransition

@RunWith(JUnit4::class)
class IndirectRightRecursionEliminationPassTest : PnfRightTestGrammar() {
  private var pass = IndirectRightRecursionEliminationPass()

  @Test
  fun testGetLastIfRuleRef() {
    val registry = RuleNameRegistry()
    val name = registry.getOrCreate("a")
    val ref = create(name)
    assertThat(pass.getRuleRefToInline(ref)).isEqualTo(name)
    val terminal = PersesTerminalAst("t", 0)
    run {
      val seqWithFirstAsRef = PersesSequenceAst(ImmutableList.of(ref, terminal))
      assertThat(pass.getRuleRefToInline(seqWithFirstAsRef)).isNull()
    }
    run {
      val seqWithoutFirstAsRef = PersesSequenceAst(ImmutableList.of(terminal, ref))
      assertThat(pass.getRuleRefToInline(seqWithoutFirstAsRef)).isNotNull()
      assertThat(pass.getRuleRefToInline(seqWithoutFirstAsRef)!!)
        .isEqualTo(ref.ruleNameHandle)
    }
    assertThat(pass.getRuleRefToInline(terminal)).isNull()
  }

  @Test
  fun testComputeScc() {
    val graph = createForRightmostTransition(grammar)
    val sccSet = getSortedSccList(graph)
    assertThat(sccSet).hasSize(3)
    assertThat(sccSet[0].vertexSet()).containsExactly(a, b)
    assertThat(sccSet[1].vertexSet()).containsExactly(c)
    assertThat(sccSet[2].vertexSet()).containsExactly(d)
  }

  @Test
  fun test_transformRightForScc() {
    val grammars: List<Set<RuleNameRegistry.RuleNameHandle>> = getSortedSccList(
      createForRightmostTransition(grammar),
    ).asSequence()
      .map { it.vertexSet() }
      .toList()

    val g = grammars[0]
    val result = MutableGrammar.createParserRulesFrom(grammar)
    pass.transformForScc(ProjectedHashMultimap(result, g))
    assertThat(result.ruleNameSequence().sorted().toList()).containsAtLeast(a, b)
    run {
      val defs = result.getAltBlock(a)
      assertThat(defs).hasSize(2)
      assertThat(defs).containsAtLeast(def_a_cb, def_a_d)
      assertThat(defs.filter { it.tag == AstTag.EPSILON }).hasSize(0)
    }
    run {
      val defs = result.getAltBlock(b)
      assertThat(defs).hasSize(3)
      val defsStrings = defs
        .asSequence()
        .map { it.sourceCode }
        .sorted()
        .toList()
      assertThat(defsStrings).containsExactly("d c b", "d d", "c d")
    }
  }
}
