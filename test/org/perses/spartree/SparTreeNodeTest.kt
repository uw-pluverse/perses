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
package org.perses.spartree

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.antlr.AntlrGrammarUtil
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.LanguageC
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgramFactory
import java.io.IOException
import java.nio.file.Path
import java.nio.file.Paths

/**
 * TODO: we need better tests here. Most of the tests here are golden tests.
 *
 */
@RunWith(JUnit4::class)
class SparTreeNodeTest {

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_enclosing_expression_1() {
    testExpectedAntlrRuleTypesOfChildren("enclosing-expression-1.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t1() {
    testExpectedAntlrRuleTypesOfChildren("t1.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t2() {
    testExpectedAntlrRuleTypesOfChildren("t2.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t3() {
    testExpectedAntlrRuleTypesOfChildren("t3.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t4() {
    testExpectedAntlrRuleTypesOfChildren("t4.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t5() {
    testExpectedAntlrRuleTypesOfChildren("t5.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t6() {
    testExpectedAntlrRuleTypesOfChildren("t6.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t9() {
    testExpectedAntlrRuleTypesOfChildren("t9.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t10() {
    testExpectedAntlrRuleTypesOfChildren("t10.c")
  }

  @Test
  fun testExpectedAntlrRuleTypesOfChildren_t8_long_expressions() {
    testExpectedAntlrRuleTypesOfChildren("t8-long-expressions.c")
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_0() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 0)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_1() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 1)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_2() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 2)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_3() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 3)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_4() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 4)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_5() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 5)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_6() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 6)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_7() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 7)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_8() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 8)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalGccPrograms_9() {
    TestUtility.partitionAndGet(TestUtility.gccTestFiles, 10, 9)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_0() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 0)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_1() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 1)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_2() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 2)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_3() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 3)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_4() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 4)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_5() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 5)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_6() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 6)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_7() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 7)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_8() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 8)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testSparTreeCanReconstructOriginalClangPrograms_9() {
    TestUtility.partitionAndGet(TestUtility.clangTestFiles, 10, 9)
      .forEach { testSparTreeCanReconstructOriginalPrograms(it) }
  }

  @Test
  fun testOriginalSparTreeConstruction_00001() {
    testOriginalSparTreeConstruction("00001.c")
  }

  @Ignore
  @Test
  fun testOriginalSparTreeConstruction_00007() {
    testOriginalSparTreeConstruction("00007.c")
  }

  @Test
  fun testOriginalSparTreeConstruction_08946() {
    testOriginalSparTreeConstruction("08946.c")
  }

  @Test
  fun testOriginalSparTreeConstruction_08959() {
    testOriginalSparTreeConstruction("08959.c")
  }

  @Test
  fun testOriginalSparTreeConstruction_10852() {
    testOriginalSparTreeConstruction("10852.c")
  }

  @Test
  fun testClang00052IsUTF8() {
    testSparTreeCanReconstructOriginalPrograms(
      Paths.get("test_data/c_programs/clang_testsuite/00052.c"),
    )
  }

  @Test
  fun testCopyChildren() {
    val tree = TestUtility.createSparTreeFromString(
      """
      int a = 0;
      int b = 0;
      """.trimIndent(),
      LanguageC,
    )
    val root = tree.root
    assertThat(root.childCount).isEqualTo(1)
    val child = root.getChild(0)
    assertThat(child.childCount).isEqualTo(2)

    val first = child.getChild(0)
    val second = child.getChild(1)

    assertThat(child.copyChildren()).containsExactly(first, second).inOrder()
    assertThat(child.copyAndReverseChildren()).containsExactly(second, first).inOrder()
  }

  private fun testOriginalSparTreeConstruction(filename: String) {
    val sourceFile = TestUtility.getOneGccTestFile(filename)
    val cParserFacade = CParserFacade()
    val parseTree = cParserFacade.parseFile(sourceFile)
    val tokens = AbstractParserFacade.getTokens(parseTree.tree)
    val factory = TokenizedProgramFactory.createFactory(tokens, cParserFacade.language)
    val sparTreeNodeFactory = SparTreeNodeFactory(
      cParserFacade.metaTokenInfoDb,
      factory,
      cParserFacade.ruleHierarchy,
    )
    val tree = SparTreeBuilder(sparTreeNodeFactory, parseTree).result
    tree.root.printTreeStructure()
    val program = tree.programSnapshot
    val originalProgram = AntlrGrammarUtil.convertParseTreeToProgram(
      parseTree.tree,
      cParserFacade.language,
    )
    assertThat(toAntlrTokens(program.tokens))
      .containsExactlyElementsIn(toAntlrTokens(originalProgram.tokens))
    SparTreeSimplifier.simplifySingleEntrySingleExitPath(tree.root)
    assertThat(SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(tree.root)).isTrue()
  }

  companion object {
    private fun testSparTreeCanReconstructOriginalPrograms(file: Path) {
      try {
        val cParserFacade = CParserFacade()
        val parseTree = cParserFacade.parseFile(file)
        val tokens = AbstractParserFacade.getTokens(parseTree.tree)
        val language = cParserFacade.language
        val factory = TokenizedProgramFactory.createFactory(tokens, language)
        val expected = AntlrGrammarUtil.convertParseTreeToProgram(parseTree.tree, language)
        val sparTreeNodeFactory = SparTreeNodeFactory(
          cParserFacade.metaTokenInfoDb,
          factory,
          cParserFacade.ruleHierarchy,
        )
        val sparTree = SparTreeBuilder(sparTreeNodeFactory, parseTree).result
        val real = sparTree.programSnapshot
        assertThat(toAntlrTokens(real.tokens))
          .containsExactlyElementsIn(toAntlrTokens(expected.tokens))
          .inOrder()
        SparTreeSimplifier.simplifySingleEntrySingleExitPath(sparTree.root)
        assertThat(SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(sparTree.root))
          .isTrue()
        val afterSESESimplification = sparTree.programSnapshot
        assertThat(toAntlrTokens(afterSESESimplification.tokens))
          .containsExactlyElementsIn(toAntlrTokens(expected.tokens))
          .inOrder()
      } catch (e: IOException) {
        e.printStackTrace()
        Assert.fail(file.toString())
      }
    }

    private fun testExpectedAntlrRuleTypesOfChildren(filename: String) {
      val sourceFile = Paths.get("test_data/misc/$filename")
      val tree = TestUtility.createSparTreeFromFile(sourceFile)
      SparTreeSimplifier.simplifySingleEntrySingleExitPath(tree)
    }

    private fun toAntlrTokens(tokens: List<PersesToken>): ImmutableList<String?> {
      return tokens.stream().map { it.text }.collect(ImmutableList.toImmutableList())
    }
  }
}
