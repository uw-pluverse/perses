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
import org.perses.TestUtility
import org.perses.antlr.GrammarTestingUtility
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.java.JavaParserFacade
import java.nio.file.Paths
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class PersesGrammarTest {
  @Test
  fun testGetGrammarName() {
    val cGrammar = CParserFacade().antlrGrammar.asCombined().grammar
    assertThat(cGrammar.grammarName).isEqualTo("OptC")
    val ruleNames = cGrammar.flattenedAllRules.stream()
      .filter { obj: AbstractPersesRuleDefAst -> obj.isParserRule }
      .map { it.ruleNameHandle.ruleName }
      .collect(ImmutableList.toImmutableList())
    assertThat(ruleNames).containsExactlyElementsIn(TestUtility.OPT_C_PARSER_RULE_NAMES)
    val javaGrammar = JavaParserFacade().antlrGrammar.asCombined().grammar
    assertThat(javaGrammar.grammarName).isEqualTo("PnfOrigJava8")
  }

  @Test
  fun testToSourceCodeCgrammar() {
    val cGrammar = CParserFacade().antlrGrammar.asCombined().grammar
    val grammarRoundback = PersesAstBuilder.loadGrammarFromString(cGrammar.sourceCode)
    testGrammar(grammarRoundback)
  }

  @Test
  fun testTokenRuleWithSkip() {
    val grammar = createAndTest("lexer_skip.g4")
    println(grammar.sourceCode)
  }

  @Test
  fun testMembersInGrammar() {
    val grammar = createAndTest("lexer_with_member.g4")
    val code = grammar.sourceCode
    assertThat(code).contains("@members")
    assertThat(code).contains("@header")
    assertThat(code).contains("package foo;")
    assertThat(code).contains("private String here;")
  }

  @Test
  fun testLexerMembersInGrammar() {
    val grammar = createAndTest("lexer_member.g4")
    val code = grammar.sourceCode
    assertThat(code).contains("@lexer::members")
    assertThat(code).contains("private int i;")
  }

  @Test
  fun testComputeAntlrBaseFileName() {
    val grammar = createAndTest("lexer_member.g4")
    assertThat(grammar.computeAntlrBaseFileName()).isEqualTo("lexer_member.g4")
  }

  @Test
  fun testLexerSemanticPredicate() {
    val grammar = createAndTest("lexer_semantic_predicate.g4")
    val code = grammar.sourceCode
    assertThat(code).contains("false")
  }

  @Test
  fun testPersesEpsilonAst() {
    createAndTest("epsilon.g4")
  }

  @Test
  fun testPersesTerminalAst() {
    createAndTest("terminal.g4")
  }

  @Test
  fun testPersesRuleRefAst() {
    createAndTest("rule_ref.g4")
  }

  @Test
  fun testPersesTokenSetAst() {
    createAndTest("token_set.g4")
  }

  @Test
  fun testPersesNotAst() {
    createAndTest("not.g4")
  }

  @Test
  fun testParentheses() {
    createAndTest("parentheses.g4")
  }

  @Test
  fun testPersesAlternativeAst() {
    createAndTest("alternative.g4")
  }

  @Test
  fun testPersesOptionalAst() {
    createAndTest("optional.g4")
  }

  @Test
  fun testPersesStarAst() {
    createAndTest("star.g4")
  }

  @Test
  fun testPersesPlusAst() {
    createAndTest("plus.g4")
  }

  @Test
  fun testLeftRecursion() {
    createAndTest("left_recursion.g4")
  }

  @Test
  fun testHiddenChannel() {
    createAndTest("lexer_hidden_channel.g4")
  }

  @Test
  fun testSystemVerilogParser() {
    val string = Paths.get("src/org/perses/grammar/sysverilog/SV3_1aParser.g4").readText()

    // This should not crash.
    PersesAstBuilder.loadGrammarFromString(string)
  }

  @Test
  fun testChannels() {
    val grammar = createAndTest("lexer_channels.g4")
    val sourceCode = grammar.sourceCode
    assertThat(sourceCode).contains("channels")
    assertThat(sourceCode).contains("WSCHANNEL")
    assertThat(sourceCode).contains("MYHIDDEN")
  }

  @Test
  fun testJavaScriptParser() {
    createAndTest("JavaScriptParser.g4")
  }

  @Test
  fun testElementOptions() {
    val grammar = createAndTest("assoc_right.g4")
    val sourceCode = grammar.sourceCode
    assertThat(sourceCode).contains("<")
    assertThat(sourceCode).contains(">")
    assertThat(sourceCode).contains("assoc")
    assertThat(sourceCode).contains("right")
    assertThat(sourceCode).contains("=")
  }

  @Test
  fun testRangeOperator() {
    createAndTest("lexer_range_operator.g4")
  }

  @Test
  fun testGoLexer() {
    val grammar = createAndTest("GoLexer.g4")
    val sourceCode = grammar.sourceCode
    assertThat(sourceCode).contains("lexer grammar")
  }

  @Test
  fun testGoParser() {
    val grammar = createAndTest("GoParser.g4")
    assertThat(grammar.sourceCode).contains("parser grammar")
  }

  @Test
  fun testOptions() {
    val grammar = createAndTest("options.g4")
    val sourceCode = grammar.sourceCode
    assertThat(sourceCode).contains("GoLexer")
    assertThat(sourceCode).contains("GoParserBase")
    assertThat(sourceCode).contains("tokenVocab")
    assertThat(sourceCode).contains("superClass")
  }

  @Test
  fun testRuleElementLabel() {
    val grammar = createAndTest("rule_element_label.g4")
    val sourceCode = grammar.sourceCode
    assertThat(sourceCode).contains("left")
    assertThat(sourceCode).contains("right")
    assertThat(sourceCode)
      .contains("left=exp '+' middle=exp+ '*'+ right+=~ID")
  }

  @Test
  fun testLexerFragment() {
    val grammar = createAndTest("lexer_fragment.g4")
    val sourceCode = grammar.getChild(0).sourceCode
    assertThat(sourceCode).contains("fragment")
    assertThat(sourceCode).contains("DIGIT")
  }

  @Test
  fun testAction() {
    val grammar = createAndTest("action.g4")
    val sourceCode = grammar.sourceCode
    assertThat(sourceCode).contains("{System.out.println(\"found a decl\");}")
  }

  @Test
  fun testRuleAttribute() {
    val grammar = createAndTest("rule_attribute_args.g4")
    val sourceCode = grammar.sourceCode
    assertThat(sourceCode)
      .contains("[int a, int b] returns [int result] locals [int c, int d]")
  }

  @Test
  fun testRuleArguments() {
    val grammar = createAndTest("rule_arguments.g4")
    val sourceCode = grammar.sourceCode
    GrammarTestingUtility.checkWithGoldenGrammar(
      sourceCode,
      """
      // Auto-generated by Perses AST.
      // DO NOT MODIFY.      
      grammar rule_arguments;
      
      start
          : arg[true]
          ;
      
      arg [boolean t]
          : 't'
          ;
      """.trimIndent(),
    )
  }

  @Test
  fun testSolidityParser() {
    createAndTest("Solidity.g4")
  }

  @Test
  fun testSemanticPredicates() {
    createAndTest("semantic_predicate.g4")
  }

  @Test
  fun testNestedAlternativesAreFlattened() {
    createAndTest("nested_alternatives.g4")
  }

  private class TokenCollector : DefaultAstVisitor() {
    val tokens = ArrayList<String?>()
    override fun visit(ast: PersesTerminalAst) {
      val text = ast.text
      if (text.isEmpty()) {
        return
      }
      if (text.startsWith("//") || text.startsWith("/*") && text.endsWith("*/")) {
        return
      }
      if (text == "(" || text == ")") {
        return
      }
      tokens.add(text)
    }
  }

  companion object {
    private fun createAndTest(filename: String): PersesGrammar {
      val grammar = GrammarTestingUtility.loadGrammarFromFile(filename)
      testGrammar(grammar)
      return grammar
    }

    private fun testGrammar(grammar: PersesGrammar) {
      val grammarContent = grammar.sourceCode
      val grammarRoundback = PersesAstBuilder.loadGrammarFromString(grammarContent)
      val actualTreeStructure = grammar.printTreeStructure()
      System.err.println(grammarContent)
      System.err.println(actualTreeStructure)
      val expected = grammarRoundback.printTreeStructure()
      assertThat(actualTreeStructure).isEqualTo(expected)
      assertThat(grammarContent).isEqualTo(grammarRoundback.sourceCode)
      assertThat(tokenize(grammar)).containsExactlyElementsIn(tokenize(grammarRoundback)).inOrder()
    }

    private fun tokenize(grammar: PersesGrammar): List<String?> {
      val tokenCollector = TokenCollector()
      tokenCollector.preorderGrammar(grammar)
      return tokenCollector.tokens
    }
  }
}
