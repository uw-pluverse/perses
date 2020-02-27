/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.tree.spar;

import com.google.common.base.Charsets;
import com.google.common.collect.ImmutableList;
import com.google.common.io.Files;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTree;
import org.junit.Assert;
import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.antlr.AntlrGrammarUtil;
import org.perses.grammar.AbstractParserFacade;
import org.perses.grammar.c.CParserFacade;
import org.perses.program.PersesToken;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;

import java.io.File;
import java.io.IOException;
import java.util.List;

import static com.google.common.truth.Truth.assertThat;

/** Test for {@link ParserRuleSparTreeNode} */
@RunWith(JUnit4.class)
public class SparTreeNodeTest {

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_enclosing_expression_1() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("enclosing-expression-1.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t1() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t1.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t2() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t2.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t3() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t3.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t4() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t4.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t5() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t5.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t6() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t6.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t9() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t9.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t10() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t10.c");
  }

  @Test
  public void testExpectedAntlrRuleTypesOfChildren_t8_long_expressions() throws IOException {
    testExpectedAntlrRuleTypesOfChildren("t8-long-expressions.c");
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_0() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 0)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_1() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 1)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_2() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 2)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_3() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 3)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_4() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 4)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_5() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 5)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_6() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 6)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_7() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 7)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_8() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 8)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalGccPrograms_9() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getGccTestFiles(), 10, 9)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_0() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 0)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_1() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 1)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_2() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 2)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_3() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 3)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_4() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 4)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_5() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 5)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_6() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 6)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_7() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 7)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_8() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 8)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testSparTreeCanReconstructOriginalClangPrograms_9() throws IOException {
    TestUtility.partitionAndGet(TestUtility.getClangTestFiles(), 10, 9)
        .forEach(SparTreeNodeTest::testSparTreeCanReconstructOriginalPrograms);
  }

  @Test
  public void testOriginalSparTreeConstruction_00001() throws IOException {
    testOriginalSparTreeConstruction("00001.c");
  }

  @Ignore
  @Test
  public void testOriginalSparTreeConstruction_00007() throws IOException {
    testOriginalSparTreeConstruction("00007.c");
  }

  @Test
  public void testOriginalSparTreeConstruction_08946() throws IOException {
    testOriginalSparTreeConstruction("08946.c");
  }

  @Test
  public void testOriginalSparTreeConstruction_08959() throws IOException {
    testOriginalSparTreeConstruction("08959.c");
  }

  @Test
  public void testOriginalSparTreeConstruction_10852() throws IOException {
    testOriginalSparTreeConstruction("10852.c");
  }

  private static void testSparTreeCanReconstructOriginalPrograms(File file) {
    try {
      CParserFacade cParserFacade = new CParserFacade();
      final ParseTree parseTree = cParserFacade.parseFile(file).getTree();
      final ImmutableList<Token> tokens = AbstractParserFacade.getTokens(parseTree);
      final TokenizedProgramFactory factory = TokenizedProgramFactory.createFactory(tokens);
      final TokenizedProgram expected = AntlrGrammarUtil.convertParseTreeToProgram(parseTree);

      final SparTree sparTree =
          new SparTreeBuilder(cParserFacade.getRuleHierarchy(), factory).build(parseTree);
      final TokenizedProgram real = sparTree.getProgramSnapshot();
      assertThat(toAntlrTokens(real.getTokens()))
          .containsExactlyElementsIn(toAntlrTokens(expected.getTokens()))
          .inOrder();

      SparTreeSimplifier.simplifySingleEntrySingleExitPath(sparTree.getRoot());
      assertThat(SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(sparTree.getRoot()))
          .isTrue();
      final TokenizedProgram afterSESESimplification = sparTree.getProgramSnapshot();
      assertThat(toAntlrTokens(afterSESESimplification.getTokens()))
          .containsExactlyElementsIn(toAntlrTokens(expected.getTokens()))
          .inOrder();
    } catch (IOException e) {
      e.printStackTrace();
      Assert.fail();
    }
  }

  private static void testExpectedAntlrRuleTypesOfChildren(String filename) throws IOException {
    File sourceFile = new File("test_data/misc/" + filename);
    File goldenFile = new File(sourceFile.getParent(), filename + ".spartree.dump.golden.txt");
    final SparTree tree = TestUtility.createSparTreeFromFile(sourceFile);
    SparTreeSimplifier.simplifySingleEntrySingleExitPath(tree);
    final String real = tree.getRoot().printTreeStructure();
    final String expected = Files.asCharSource(goldenFile, Charsets.UTF_8).read();
    assertThat(real).isEqualTo(expected);
  }

  private void testOriginalSparTreeConstruction(String filename) throws IOException {
    File sourceFile = TestUtility.getOneGccTestFile(filename);
    File goldenFile = new File("test_data/misc/" + filename + ".tree_dump.original.golden.txt");
    CParserFacade cParserFacade = new CParserFacade();
    final ParseTree parseTree = cParserFacade.parseFile(sourceFile).getTree();
    final ImmutableList<Token> tokens = AbstractParserFacade.getTokens(parseTree);
    final TokenizedProgramFactory factory = TokenizedProgramFactory.createFactory(tokens);
    final SparTree tree =
        new SparTreeBuilder(cParserFacade.getRuleHierarchy(), factory).build(parseTree);
    final String treeStructure = tree.getRoot().printTreeStructure();
    final String expectedTreeDump = Files.asCharSource(goldenFile, Charsets.UTF_8).read();
    assertThat(treeStructure).isEqualTo(expectedTreeDump);

    final TokenizedProgram program = tree.getProgramSnapshot();
    final TokenizedProgram originalProgram = AntlrGrammarUtil.convertParseTreeToProgram(parseTree);
    assertThat(toAntlrTokens(program.getTokens()))
        .containsExactlyElementsIn(toAntlrTokens(originalProgram.getTokens()));
    SparTreeSimplifier.simplifySingleEntrySingleExitPath(tree.getRoot());
    assertThat(SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(tree.getRoot())).isTrue();
  }

  private static ImmutableList<String> toAntlrTokens(List<PersesToken> tokens) {
    return tokens.stream().map(Token::getText).collect(ImmutableList.toImmutableList());
  }
}
