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
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.Token
import org.antlr.v4.tool.Grammar
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesTerminalAst
import java.nio.file.Paths
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class OutlineImplicitTokenDefPassTest {

  val pass = OutlineImplicitTokenDefPass()

  @Test
  fun testImplicitTokenDefCollector() {
    val grammar = GrammarTestingUtility.createPersesGrammarFromString("start: 'a';")
    val collector = OutlineImplicitTokenDefPass.ImplicitTokenDefCollector()
    collector.preorderGrammar(grammar)
    assertThat(collector.implicitDefs.map { it.sourceCode }).containsExactly("'a'")
  }

  @Test
  fun testOutlineStringLiteralForCombinedWithLexerRules() {
    val parserGrammar = GrammarTestingUtility.createPersesGrammarFromString(
      "start: ID 'a' ;",
      "ID: 'b' ; ",
    )
    val pairBefore = GrammarPair(parserGrammar, lexerGrammar = null)
    val pairAfter = pass.processGrammar(pairBefore)
    assertThat(pairAfter.lexerGrammar).isNull()

    val parserGrammarAfter = pairAfter.parserGrammar!!
    val lexerRules = parserGrammarAfter.lexerRules.flattenedLexerRules
    val lexerRuleNames = lexerRules.map { it.ruleNameHandle.ruleName }
    assertThat(lexerRuleNames).hasSize(2)
    assertThat(lexerRuleNames).contains("ID")
    val auxLexerRuleName = lexerRuleNames.filter { it != "ID" }.single()
    assertThat(parserGrammarAfter.getRuleDefinition(auxLexerRuleName)!!.body.sourceCode).isEqualTo(
      "'a'",
    )
    (parserGrammarAfter.getRuleDefinition("start")!!.body as PersesSequenceAst).let {
      assertThat(it.childCount).isEqualTo(2)
      assertThat(it.firstChild.sourceCode).isEqualTo("ID")
      assertThat(it.firstChild).isInstanceOf(PersesTerminalAst::class.java)
      assertThat(it.lastChild.sourceCode).isEqualTo(auxLexerRuleName)
      assertThat(it.lastChild).isInstanceOf(PersesTerminalAst::class.java)
    }
  }

  @Test
  fun testOutlineStringLiteralForSingleRule() {
    val parserGrammar = GrammarTestingUtility.createPersesGrammarFromString("start: 'a' ; ")
    val pairBefore = GrammarPair(parserGrammar, lexerGrammar = null)
    assertThat(pairBefore.parserGrammar).isNotNull()
    assertThat(pairBefore.parserGrammar!!.lexerRules.flattenedLexerRules).isEmpty()

    val pairAfter = pass.processGrammar(pairBefore)
    assertThat(pairAfter.lexerGrammar).isNull()
    val parserGrammarAfter = pairAfter.parserGrammar!!
    val lexerRuleName: String
    parserGrammarAfter.parserRules.single().let {
      assertThat(it.ruleNameHandle.ruleName).isEqualTo("start")
      assertThat(it.body.sourceCode).isNotEqualTo("'a'")
      lexerRuleName = it.body.sourceCode
    }
    val lexerRules = pairAfter.parserGrammar!!.lexerRules
    lexerRules.flattenedLexerRules.single().let {
      assertThat(it.ruleNameHandle.ruleName).isEqualTo(lexerRuleName)
      assertThat(it.body.sourceCode).isEqualTo("'a'")
      assertThat(it.body).isInstanceOf(PersesTerminalAst::class.java)
    }
  }

  @Test
  fun testLiteralDoesNotBecomeIdentifier() {
    val parserGrammarBefore = PersesAstBuilder.loadGrammarFromString(
      Paths.get("src/org/perses/grammar/c/OrigC.g4").readText(),
    )
    val program = "__attribute__ a int"
    val parserGrammarAfter = pass.processGrammar(
      GrammarPair(
        parserGrammarBefore,
        lexerGrammar = null,
      ),
    ).parserGrammar!!

    val interpreters = listOf(parserGrammarBefore, parserGrammarAfter)
      .map {
        Grammar(it.sourceCode).createLexerInterpreter(
          CharStreams.fromString(program),
        )
      }
    check(interpreters.size == 2)

    val list = interpreters.map { lexerInterpreter ->
      CommonTokenStream(lexerInterpreter).let { stream ->
        stream.fill()
        stream.tokens
          .filter { token -> token.type != Token.EOF }
          .map { token -> lexerInterpreter.vocabulary.getSymbolicName(token.type) }
          .distinct() // calling distinct is important.
      }
    }
    assertThat(list).hasSize(2)
    val before = list.first()
    val after = list.last()
    assertThat(before).isNotEqualTo(after)
    assertThat(before).containsAtLeast("Identifier", "Int")
    assertThat(after).containsAtLeast("Identifier", "Int")
    assertThat(before).hasSize(3)
    assertThat(after).hasSize(3)

    val lexerInterpreterAfter = Grammar(
      parserGrammarAfter.sourceCode,
    ).createLexerInterpreter(
      CharStreams.fromString(program),
    )
    val tokensAfter = CommonTokenStream(lexerInterpreterAfter).let {
      it.fill()
      it.tokens.filter { it.type != Token.EOF }
    }.map { lexerInterpreterAfter.vocabulary.getSymbolicName(it.type) }.distinct()
    assertThat(tokensAfter).hasSize(3)

    val interpreterBefore = interpreters.first()
    val interpreterAfter = interpreters.last()
    assertThat(interpreterBefore.ruleNames.filter { it.startsWith("T__") }).isNotEmpty()
    assertThat(interpreterAfter.ruleNames.filter { it.startsWith("T__") }).isEmpty()
  }
}
