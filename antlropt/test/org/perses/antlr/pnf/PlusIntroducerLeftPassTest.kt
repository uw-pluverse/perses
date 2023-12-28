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
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.antlr.GrammarTestingUtility.createSeqOfTerminals
import org.perses.antlr.GrammarTestingUtility.createTerminalList
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.TransformDecision
import org.perses.antlr.pnf.PlusIntroducerLeftPass.PlusIntroducerEdit.Companion.match
import org.perses.antlr.pnf.PlusIntroducerLeftPass.PlusIntroducerEdit.Companion.reverseMatch

@RunWith(JUnit4::class)
class PlusIntroducerLeftPassTest : PnfLeftTestGrammar() {
  @Test
  fun testProcess() {
    run {
      val grammar = createPersesGrammarFromString("start:C D a;", "a:(C D)*;")
      val pass = PlusIntroducerLeftPass()
      val newGrammar = pass.processGrammar(
        GrammarPair(grammar, lexerGrammar = null),
      ).parserGrammar!!
      assertThat(newGrammar.getRuleDefinition("start")!!.body.sourceCode)
        .isEqualTo("kleene_plus__a_1")
      assertThat(
        newGrammar.getRuleDefinition("kleene_plus__a_1")!!.body.sourceCode,
      ).isEqualTo("(C D)+")
    }
    run {
      val grammar = createPersesGrammarFromString("start:a C D f;", "a:(C D)*;")
      val pass = PlusIntroducerLeftPass()
      val newGrammar = pass.processGrammar(
        GrammarPair(grammar, lexerGrammar = null),
      ).parserGrammar!!
      assertThat(newGrammar.getRuleDefinition("start")!!.body.sourceCode)
        .isEqualTo("kleene_plus__a_1 f")
      assertThat(
        newGrammar.getRuleDefinition("kleene_plus__a_1")!!.body.sourceCode,
      ).isEqualTo("(C D)+")
    }
  }

  @Test
  fun testMatch() {
    val seq = createSeqOfTerminals("a", "b")
    var toMatch: ImmutableList<AbstractPersesRuleElement> = createTerminalList("a", "b")
    assertThat(match(seq, -1, toMatch)).isFalse()
    assertThat(match(seq, 0, toMatch)).isTrue()
    assertThat(match(seq, 1, toMatch)).isFalse()
    toMatch = createTerminalList("a")
    assertThat(match(seq, 0, toMatch)).isTrue()
    assertThat(match(seq, 1, toMatch)).isFalse()
    toMatch = createTerminalList("b")
    assertThat(match(seq, 0, toMatch)).isFalse()
    assertThat(match(seq, 1, toMatch)).isTrue()
    toMatch = createTerminalList("a", "b", "c")
    assertThat(match(seq, -1, toMatch)).isFalse()
    assertThat(match(seq, 0, toMatch)).isFalse()
    assertThat(match(seq, 1, toMatch)).isFalse()
    assertThat(match(seq, 2, toMatch)).isFalse()
  }

  @Test
  fun testReverseMatch() {
    val seq = createSeqOfTerminals("a", "b")
    var toMatch = createTerminalList("a", "b")
    assertThat(reverseMatch(seq, -1, toMatch)).isFalse()
    assertThat(reverseMatch(seq, 0, toMatch)).isFalse()
    assertThat(reverseMatch(seq, 1, toMatch)).isTrue()
    toMatch = createTerminalList("a")
    assertThat(reverseMatch(seq, 0, toMatch)).isTrue()
    assertThat(reverseMatch(seq, 1, toMatch)).isFalse()
    toMatch = createTerminalList("b")
    assertThat(reverseMatch(seq, 0, toMatch)).isFalse()
    assertThat(reverseMatch(seq, 1, toMatch)).isTrue()
    toMatch = createTerminalList("a", "b", "c")
    assertThat(reverseMatch(seq, -1, toMatch)).isFalse()
    assertThat(reverseMatch(seq, 0, toMatch)).isFalse()
    assertThat(reverseMatch(seq, 1, toMatch)).isFalse()
    assertThat(reverseMatch(seq, 2, toMatch)).isFalse()
  }

  @Test
  fun testTransformStarToPlus_for_sequence() {
    for (startRuleDef in ImmutableList.of("start : C D a f;", "start : a C D f;")) {
      val grammar = createPersesGrammarFromString(startRuleDef!!, "a: (C  D)*;")
      val registry = grammar.symbolTable.ruleNameRegistry
      val edit = PlusIntroducerLeftPass.PlusIntroducerEdit(grammar)
      val start = edit.internalApply(
        grammar.getRuleDefinition("start")!!.body,
        isRoot = true,
      )
        as TransformDecision.Replace
      assertThat(start.newValue.sourceCode).isEqualTo("kleene_plus__a_1 f")
      val kleene_plus__a_1 = edit.toAdd[registry.getOrThrow("kleene_plus__a_1")]
      assertThat(kleene_plus__a_1).hasSize(1)
      assertThat(kleene_plus__a_1.single().sourceCode).isEqualTo("(C D)+")
    }
  }

  @Test
  fun testTransformStarToPlus_for_terminals() {
    for (startRuleDef in ImmutableList.of("start : D a f;", "start : a D f;")) {
      val grammar = createPersesGrammarFromString(startRuleDef!!, "a: D*;")
      val registry = grammar.symbolTable.ruleNameRegistry
      val edit = PlusIntroducerLeftPass.PlusIntroducerEdit(grammar)
      val start = edit.internalApply(
        grammar.getRuleDefinition("start")!!.body,
        isRoot = true,
      )
        as TransformDecision.Replace
      assertThat(start.newValue.sourceCode).isEqualTo("kleene_plus__a_1 f")
      val kleene_plus__a_1 = edit.toAdd[registry.getOrThrow("kleene_plus__a_1")]
      assertThat(kleene_plus__a_1).hasSize(1)
      assertThat(kleene_plus__a_1.single().sourceCode).isEqualTo("D+")
    }
  }

  @Test
  fun testGetStarIfIsKlleneStarRule() {
    val grammar = createPersesGrammarFromString(
      "r1 : a | b;",
      "r2 : a*;",
      "r3: a* b;",
      "r4: a+;",
    )
    val edit = PlusIntroducerLeftPass.PlusIntroducerEdit(grammar)
    val ruleNameRegistry = grammar.symbolTable.ruleNameRegistry
    val r1 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r1"))
    assertThat(r1).isNull()
    val r2 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r2"))!!
    assertThat(r2).isNotNull()
    assertThat(r2).isInstanceOf(PersesStarAst::class.java)
    assertThat(r2.body.sourceCode).isEqualTo("a")
    val r3 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r3"))
    assertThat(r3).isNull()
    val r4 = edit.getStarIfIsKleeneStarRule(ruleNameRegistry.getOrThrow("r4"))
    assertThat(r4).isNull()
  }
}
