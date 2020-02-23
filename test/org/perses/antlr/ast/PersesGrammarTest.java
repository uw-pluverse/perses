package org.perses.antlr.ast;

import com.google.common.collect.ImmutableList;
import org.antlr.runtime.RecognitionException;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.java.JavaParserFacade;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class PersesGrammarTest {

  @Test
  public void test_getGrammarName() throws IOException, RecognitionException {
    PersesGrammar cGrammar = new CParserFacade().getPersesGrammar();
    assertThat(cGrammar.getGrammarName()).isEqualTo("OptC");
    ImmutableList<String> ruleNames =
        cGrammar.getRules().stream()
            .filter(AbstractPersesRuleDefAst::isParserRule)
            .map(AbstractPersesRuleDefAst::getRuleNameHandle)
            .map(RuleNameRegistry.RuleNameHandle::get)
            .collect(ImmutableList.toImmutableList());
    assertThat(ruleNames).containsExactlyElementsIn(TestUtility.OPT_C_PARSER_RULE_NAMES);

    PersesGrammar javaGrammar = new JavaParserFacade().getPersesGrammar();
    assertThat(javaGrammar.getGrammarName()).isEqualTo("OptJava8");
  }

  @Test
  public void test_toSourceCode_c_grammar() throws IOException, RecognitionException {
    PersesGrammar cGrammar = new CParserFacade().getPersesGrammar();
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
