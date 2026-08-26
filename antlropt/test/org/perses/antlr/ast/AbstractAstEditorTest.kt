/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.antlr.ast

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString

@RunWith(JUnit4::class)
class AbstractAstEditorTest {
  private val grammar =
    createPersesGrammarFromString(
      "start : a b ;",
      "onlyB : b ;",
      "either : a | b ;",
      "inOptional : a (b c)? d ;",
      "a : 'x' ;",
      "b : 'y' ;",
      "c : 'z' ;",
      "d : 'w' ;",
    )

  private fun bodyOf(
    grammar: PersesGrammar,
    ruleName: String,
  ) = grammar.getRuleDefinition(ruleName)!!.body.sourceCode.replace(Regex("\\s+"), " ").trim()

  @Test
  fun testEditorWithoutOverridesRebuildsAnEquivalentGrammar() {
    val edited = object : AbstractAstEditor() {}.bottomUpApply(grammar)
    assertThat(edited).isNotSameInstanceAs(grammar)
    assertThat(edited.isEquivalent(grammar)).isTrue()
  }

  @Test
  fun testReturningNullDeletesTheNode() {
    val nameB = grammar.symbolTable.ruleNameRegistry.getOrThrow("b")
    val deleteB =
      object : AbstractAstEditor() {
        override fun visit(
          ast: PersesRuleReferenceAst,
          newChildren: ImmutableList<AbstractPersesRuleElement>,
        ): AbstractPersesRuleElement? = if (ast.ruleNameHandle == nameB) null else ast
      }
    val edited = deleteB.bottomUpApply(grammar)
    assertThat(bodyOf(edited, "start")).isEqualTo("a")
    assertThat(edited.getRuleDefinition("onlyB")).isNull()
    assertThat(bodyOf(edited, "either")).isEqualTo("a?")
    assertThat(bodyOf(edited, "inOptional")).isEqualTo("a c? d")
    assertThat(bodyOf(edited, "b")).isEqualTo("'y'")
  }

  @Test
  fun testReturningANewNodeReplacesIt() {
    val registry = grammar.symbolTable.ruleNameRegistry
    val nameB = registry.getOrThrow("b")
    val refC = PersesRuleReferenceAst.create(registry.getOrThrow("c"))
    val bToC =
      object : AbstractAstEditor() {
        override fun visit(
          ast: PersesRuleReferenceAst,
          newChildren: ImmutableList<AbstractPersesRuleElement>,
        ): AbstractPersesRuleElement = if (ast.ruleNameHandle == nameB) refC else ast
      }
    val edited = bToC.bottomUpApply(grammar)
    assertThat(bodyOf(edited, "start")).isEqualTo("a c")
    assertThat(bodyOf(edited, "onlyB")).isEqualTo("c")
    assertThat(bodyOf(edited, "either")).isEqualTo("a | c")
    assertThat(bodyOf(edited, "inOptional")).isEqualTo("a (c c)? d")
  }
}
