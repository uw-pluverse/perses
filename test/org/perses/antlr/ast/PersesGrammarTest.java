/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.antlr.ast;

import com.google.common.collect.ImmutableList;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.java.JavaParserFacade;

import java.util.ArrayList;
import java.util.List;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class PersesGrammarTest {

  @Test
  public void test_getGrammarName() {
    PersesGrammar cGrammar = new CParserFacade().getAntlrGrammar().asCombined().getGrammar();
    assertThat(cGrammar.getGrammarName()).isEqualTo("OptC");
    ImmutableList<String> ruleNames =
        cGrammar.getRules().stream()
            .filter(AbstractPersesRuleDefAst::isParserRule)
            .map(AbstractPersesRuleDefAst::getRuleNameHandle)
            .map(RuleNameRegistry.RuleNameHandle::get)
            .collect(ImmutableList.toImmutableList());
    assertThat(ruleNames).containsExactlyElementsIn(TestUtility.OPT_C_PARSER_RULE_NAMES);

    PersesGrammar javaGrammar = new JavaParserFacade().getAntlrGrammar().asCombined().getGrammar();
    assertThat(javaGrammar.getGrammarName()).isEqualTo("OptJava8");
  }

  @Test
  public void test_toSourceCode_c_grammar() {
    PersesGrammar cGrammar = new CParserFacade().getAntlrGrammar().asCombined().getGrammar();
    PersesGrammar grammarRoundback =
        PersesAstBuilder.loadGrammarFromString(cGrammar.getSourceCode());
    testGrammar(grammarRoundback);
  }

  @Test
  public void testTokenRuleWithSkip() {
    PersesGrammar grammar = createAndTest("lexer_skip.g4");
    System.out.println(grammar.getSourceCode());
  }

  @Test
  public void testMembersInGrammar() {
    PersesGrammar grammar = createAndTest("lexer_with_member.g4");
    final String code = grammar.getSourceCode();
    assertThat(code).contains("@members");
    assertThat(code).contains("@header");
    assertThat(code).contains("package foo;");
    assertThat(code).contains("private String here;");
  }

  @Test
  public void test_PersesEpsilonAst() {
    createAndTest("epsilon.g4");
  }

  @Test
  public void test_PersesTerminalAst() {
    createAndTest("terminal.g4");
  }

  @Test
  public void test_PersesRuleRefAst() {
    createAndTest("rule_ref.g4");
  }

  @Test
  public void test_PersesTokenSetAst() {
    createAndTest("token_set.g4");
  }

  @Test
  public void test_PersesNotAst() {
    createAndTest("not.g4");
  }

  @Test
  public void testParentheses() {
    createAndTest("parentheses.g4");
  }

  @Test
  public void test_PersesAlternativeAst() {
    createAndTest("alternative.g4");
  }

  @Test
  public void test_PersesOptionalAst() {
    createAndTest("optional.g4");
  }

  @Test
  public void test_PersesStarAst() {
    createAndTest("star.g4");
  }

  @Test
  public void test_PersesPlusAst() {
    createAndTest("plus.g4");
  }

  @Test
  public void testLeftRecursion() {
    createAndTest("left_recursion.g4");
  }

  @Test
  public void testHiddenChannel() {
    createAndTest("lexer_hidden_channel.g4");
  }

  @Test
  public void testRangeOperator() {
    createAndTest("lexer_range_operator.g4");
  }

  @Test
  public void testGoLexer() {
    final PersesGrammar grammar = createAndTest("GoLexer.g4");
    final String sourceCode = grammar.getSourceCode();
    assertThat(sourceCode).contains("lexer grammar");
  }

  @Test
  public void testGoParser() {
    final PersesGrammar grammar = createAndTest("GoParser.g4");
    assertThat(grammar.getSourceCode()).contains("parser grammar");
  }

  @Test
  public void testOptions() {
    final PersesGrammar grammar = createAndTest("options.g4");
    final String sourceCode = grammar.getSourceCode();
    assertThat(sourceCode).contains("GoLexer");
    assertThat(sourceCode).contains("GoParserBase");
    assertThat(sourceCode).contains("tokenVocab");
    assertThat(sourceCode).contains("superClass");
  }

  @Test
  public void testSemanticPredicates() {
    createAndTest("semantic_predicate.g4");
  }

  @Test
  public void testNestedAlternativesAreFlattened() {
    createAndTest("nested_alternatives.g4");
  }

  private static PersesGrammar createAndTest(String filename) {
    PersesGrammar grammar = GrammarTestingUtility.loadGrammarFromFile(filename);
    testGrammar(grammar);
    return grammar;
  }

  private static void testGrammar(PersesGrammar grammar) {
    final String grammarContent = grammar.getSourceCode();
    PersesGrammar grammarRoundback = PersesAstBuilder.loadGrammarFromString(grammarContent);
    String actualTreeStructure = grammar.printTreeStructure();
    System.err.println(grammarContent);
    System.err.println(actualTreeStructure);
    String expected = grammarRoundback.printTreeStructure();
    assertThat(actualTreeStructure).isEqualTo(expected);
    assertThat(grammarContent).isEqualTo(grammarRoundback.getSourceCode());

    assertThat(tokenize(grammar)).containsExactlyElementsIn(tokenize(grammarRoundback)).inOrder();
  }

  private static class TokenCollector extends DefaultAstVisitor {
    final ArrayList<String> tokens = new ArrayList<>();

    @Override
    protected void visit(PersesTerminalAst ast) {
      final String text = ast.getText();
      if (text.isEmpty()) {
        return;
      }
      if (text.startsWith("//") || (text.startsWith("/*") && text.endsWith("*/"))) {
        return;
      }
      if (text.equals("(") || text.equals(")")) {
        return;
      }
      tokens.add(text);
    }
  }

  private static List<String> tokenize(PersesGrammar grammar) {
    TokenCollector tokenCollector = new TokenCollector();
    tokenCollector.visit(grammar);
    return tokenCollector.tokens;
  }
}
