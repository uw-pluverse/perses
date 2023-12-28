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
package org.perses.grammar.c

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.TestUtility.clangTestFiles
import org.perses.TestUtility.extractTokenTexts
import org.perses.TestUtility.gccTestFiles
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.RuleNameRegistry
import java.nio.file.Path
import java.nio.file.Paths

/** Test for testing the optimized C grammar.  */
@RunWith(JUnit4::class)
class OptCParserTest {
  @Test
  fun testAsmStmt_Issue16() {
    val file = Paths.get("test_data/c_programs/gcc_testsuite/06002.c")
    C_PARSER_FACADE.parseFile(file)
    PNF_C_PARSER_FACADE.parseFile(file)
  }

  /** https://gcc.gnu.org/onlinedocs/gcc/Local-Register-Variables.html#Local-Register-Variables  */
  @Test
  fun testRegisterVariableWithAsm() {
    val file = Paths.get("test_data/c_programs/clang_testsuite/00374.c")
    PNF_C_PARSER_FACADE.parseFile(file)
    ORIG_C_PARSER_FACADE.parseFile(file)
    C_PARSER_FACADE.parseFile(file)
  }

  @Test
  fun testOptimizedCParserWithOriginalCParserOnClang() {
    gccTestFiles.forEach { testOneCFile(it) }
  }

  @Test
  fun testOptimizedCParserWithOriginalCParserOnGcc() {
    gccTestFiles.forEach { testOneCFile(it) }
  }

  @Test
  fun testNumOfGccTestFiles() {
    assertThat(gccTestFiles.size).isEqualTo(10850)
    assertThat(clangTestFiles.size).isEqualTo(1799)
  }

  @Test
  fun testIntegrityOfOptimizedCParser() {
    val persesGrammar = C_PARSER_FACADE.antlrGrammar.asCombined().grammar
    val ruleNames = persesGrammar.flattenedAllRules.stream()
      .filter(AbstractPersesRuleDefAst::isParserRule)
      .map(AbstractPersesRuleDefAst::ruleNameHandle)
      .map(RuleNameRegistry.RuleNameHandle::ruleName)
      .collect(ImmutableList.toImmutableList())
    assertThat(ruleNames).containsExactlyElementsIn(TestUtility.OPT_C_PARSER_RULE_NAMES)
  }

  companion object {
    private val C_PARSER_FACADE = CParserFacade()
    private val ORIG_C_PARSER_FACADE = OrigCParserFacade()
    private val PNF_C_PARSER_FACADE = PnfCParserFacade()
    private fun testOneCFile(testFile: Path) {
      val origTokens = extractTokenTexts(ORIG_C_PARSER_FACADE.parseFile(testFile).tree)
      run {
        val treeByOpt = C_PARSER_FACADE.parseFile(testFile).tree
        assertThat(origTokens)
          .containsExactlyElementsIn(extractTokenTexts(treeByOpt))
          .inOrder()
      }
      run {
        val treeByPnfc = PNF_C_PARSER_FACADE.parseFile(testFile).tree
        assertThat(origTokens)
          .containsExactlyElementsIn(extractTokenTexts(treeByPnfc))
          .inOrder()
      }
    }
  }
}
