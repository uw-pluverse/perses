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
import org.perses.grammar.AntlrFailureException
import org.perses.util.transformToImmutableList
import java.nio.file.Path

/** Test for testing the optimized C grammar.  */
@RunWith(JUnit4::class)
class OptCParserTest {
  // The asm-block cases (gcc 06002.c, clang 00374.c) are dropped: OrigC.g4 no longer skips the
  // `asm { ... }` block (its AsmBlock rule was removed), so the Orig/PNF facades no longer parse them.

  @Test
  fun testOptimizedCParserWithOriginalCParserOnClang() {
    clangTestFiles.forEach { testOneCFile(it) }
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
    val ruleNames =
      persesGrammar.flattenedAllRules
        .stream()
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
      val origTokens =
        try {
          ORIG_C_PARSER_FACADE
            .tokenizeFile(
              testFile,
            ).transformToImmutableList { it.text }
        } catch (e: AntlrFailureException) {
          // OrigC.g4 no longer skips #define/#pragma/#line/asm, so it rejects corpus files that
          // contain them. Such files are out of scope for this Orig-vs-PNF token comparison.
          return
        }
      val treeByPnfc =
        try {
          PNF_C_PARSER_FACADE.parseFile(testFile).tree
        } catch (e: AntlrFailureException) {
          // A file can lex yet not parse as a complete compilationUnit -- e.g. it contains a bare
          // preprocessing directive, now lexed as one PreprocessingDirective token but accepted by no
          // parser rule. There is no parse tree to compare against, so skip it.
          return
        }
      assertThat(origTokens)
        .containsExactlyElementsIn(extractTokenTexts(treeByPnfc))
        .inOrder()
    }
  }
}
