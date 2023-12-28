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
package org.perses.antlr.ast

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility.createPersesGrammarFromString
import org.perses.antlr.GrammarTestingUtility.createTerminalList

@RunWith(JUnit4::class)
class PersesAstTest {
  @Test
  fun testChildrenOfAltBlockAreKeptInInitOrder() {
    val childrenA = createTerminalList("a", "b")
    val a = PersesAlternativeBlockAst(childrenA)
    val childrenB = createTerminalList("b", "a")
    val b = PersesAlternativeBlockAst(childrenB)
    assertThat(a.getChild(0).sourceCode).isEqualTo(b.getChild(1).sourceCode)
    assertThat(a.getChild(1).sourceCode).isEqualTo(b.getChild(0).sourceCode)
    assertThat(a.isEquivalent(b)).isTrue()
  }

  @Test
  fun testChildrenOfTokenSetKeptInInitOrder() {
    val childrenA = createTerminalList("A", "B").stream()
      .map { it as AbstractPersesTerminalAst }
      .collect(ImmutableList.toImmutableList())
    val a = PersesTokenSetAst(childrenA)
    val childrenB = createTerminalList("B", "A").stream()
      .map { it as AbstractPersesTerminalAst }
      .collect(ImmutableList.toImmutableList())
    val b = PersesTokenSetAst(childrenB)
    assertThat(a.getChild(0).sourceCode).isEqualTo(b.getChild(1).sourceCode)
    assertThat(a.getChild(1).sourceCode).isEqualTo(b.getChild(0).sourceCode)
    assertThat(a.isEquivalent(b)).isTrue()
  }

  @Test
  fun testBlockComment() {
    val grammar = createPersesGrammarFromString(
      "BlockComment: '/*' .*? '*/' -> skip ;",
    )
    val body = grammar.getRuleDefinition("BlockComment")!!.body
    assertThat(body).isInstanceOf(PersesLexerCommandAst::class.java)
    val child = body.getChild(0)
    assertThat(child).isInstanceOf(PersesSequenceAst::class.java)
    assertThat(child.childCount).isEqualTo(3)
    val first = child.getChild(0)
    assertThat(first.sourceCode).isEqualTo("'/*'")
    val second = child.getChild(1)
    assertThat(second.sourceCode).isEqualTo(".*?")
    val third = child.getChild(2)
    assertThat(third.sourceCode).isEqualTo("'*/'")
  }

  @Test
  fun testPersesLexerCommandAstMultipleCommands() {
    val grammar = createPersesGrammarFromString(
      "TOKEN: i -> popMode, skip;",
    )
    assertThat(grammar.sourceCode).contains("i -> popMode, skip")
  }

  @Test
  fun testPushMode() {
    val grammar = createPersesGrammarFromString(
      """
      XMLDeclOpen : '<' -> pushMode(INSIDE) ;
      """.trimIndent(),
    )
    val body = grammar.getRuleDefinition("XMLDeclOpen")!!.body
    assertThat(body.sourceCode.trim()).isEqualTo("'<' -> pushMode(INSIDE)")
  }

  @Test
  fun testTokenSpecifications() {
    val grammar = createPersesGrammarFromString(
      """
        tokens { INDENT, DEDENT }
      """.trimIndent(),
    )
    val code = grammar.sourceCode
    assertThat(code.trim().replace(Regex("\\s"), ""))
      .contains("tokens {INDENT, DEDENT}".replace("\\s".toRegex(), ""))
  }

  @Test
  fun testPersesParserAttributes() {
    createPersesGrammarFromString("start locals [int a = 0] : 'a';").parserRules.single()
      .attributes.let { attributes ->
        assertThat(attributes.hasArguments()).isFalse()
        assertThat(attributes.hasLocals()).isTrue()
        assertThat(attributes.hasReturn()).isFalse()
        attributes.locals!!.let { locals ->
          assertThat(locals.sourceCode).isEqualTo("int a = 0")
        }
        assertThat(attributes.isEmpty()).isFalse()
        assertThat(attributes.isNotEmpty()).isTrue()
      }
    createPersesGrammarFromString("start returns [int a] : 'a';").parserRules.single()
      .attributes.let { attributes ->
        assertThat(attributes.hasArguments()).isFalse()
        assertThat(attributes.hasLocals()).isFalse()
        assertThat(attributes.hasReturn()).isTrue()
        attributes.returns!!.let {
          assertThat(it.sourceCode).isEqualTo("int a")
        }
        assertThat(attributes.isEmpty()).isFalse()
        assertThat(attributes.isNotEmpty()).isTrue()
      }
    createPersesGrammarFromString("start[int a]:'a';").parserRules.single()
      .attributes.let { attributes ->
        assertThat(attributes.hasReturn()).isFalse()
        assertThat(attributes.hasLocals()).isFalse()
        assertThat(attributes.hasArguments()).isTrue()
        attributes.arguments!!.let {
          assertThat(it.sourceCode).isEqualTo("int a")
        }
        assertThat(attributes.isEmpty()).isFalse()
        assertThat(attributes.isNotEmpty()).isTrue()
      }
  }
}
