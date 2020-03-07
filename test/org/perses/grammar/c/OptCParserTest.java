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
package org.perses.grammar.c;

import com.google.common.collect.ImmutableList;
import com.google.common.truth.Truth;
import org.antlr.v4.runtime.tree.ParseTree;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import static com.google.common.truth.Truth.assertThat;

/** Test for testing the optimized C grammar. */
@RunWith(JUnit4.class)
public class OptCParserTest {

  private static final CParserFacade C_PARSER_FACADE = new CParserFacade();
  private static final PnfCParserFacade PNF_C_PARSER_FACADE = new PnfCParserFacade();

  private static void testOneCFile(File testFile) {
    try {
      final ArrayList<String> origTokens =
          TestUtility.extractTokens(C_PARSER_FACADE.parseWithOrigCParser(testFile).getTree());
      {
        final ParseTree treeByOpt = C_PARSER_FACADE.parseFile(testFile).getTree();
        assertThat(origTokens)
            .containsExactlyElementsIn(TestUtility.extractTokens(treeByOpt))
            .inOrder();
      }
      {
        final ParseTree treeByPnfc = PNF_C_PARSER_FACADE.parseFile(testFile).getTree();
        assertThat(origTokens)
            .containsExactlyElementsIn(TestUtility.extractTokens(treeByPnfc))
            .inOrder();
      }

    } catch (Throwable e) {
      e.printStackTrace();
      Assert.fail();
    }
  }

  @Test
  public void testOptimizedCParserWithOriginalCParserOnClang() throws IOException {
    TestUtility.getGccTestFiles().forEach(OptCParserTest::testOneCFile);
  }

  @Test
  public void testOptimizedCParserWithOriginalCParserOnGcc() throws IOException {
    TestUtility.getGccTestFiles().forEach(OptCParserTest::testOneCFile);
  }

  @Test
  public void testNumOfGccTestFiles() {
    Truth.assertThat(TestUtility.getGccTestFiles().size()).isEqualTo(10850);
    Truth.assertThat(TestUtility.getClangTestFiles().size()).isEqualTo(1807);
  }

  @Test
  public void testIntegrityOfOptimizedCParser() {
    final PersesGrammar persesGrammar = C_PARSER_FACADE.getAntlrGrammar().asCombined().getGrammar();

    final ImmutableList<String> ruleNames =
        persesGrammar.getRules().stream()
            .filter(AbstractPersesRuleDefAst::isParserRule)
            .map(AbstractPersesRuleDefAst::getRuleNameHandle)
            .map(RuleNameRegistry.RuleNameHandle::get)
            .collect(ImmutableList.toImmutableList());
    assertThat(ruleNames).containsExactlyElementsIn(TestUtility.OPT_C_PARSER_RULE_NAMES);
  }
}
