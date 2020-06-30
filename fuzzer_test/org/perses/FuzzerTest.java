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
package org.perses.fuzzer;

import org.antlr.v4.runtime.tree.ParseTree;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.c.PnfCParserFacade;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import static com.google.common.truth.Truth.assertThat;

/** Test for testing fuzzer. */
@RunWith(JUnit4.class)
public class FuzzerTest {

  private static final CParserFacade C_PARSER_FACADE = new CParserFacade();

  private void testOneCFile(String pathname) throws IOException {

      final File testFile = new File(pathname);
      final ArrayList<String> origTokens =
          TestUtility.extractTokens(C_PARSER_FACADE.parseWithOrigCParser(testFile).getTree());

      final ParseTree treeByOpt = Fuzzer.generateParseTree(pathname);
      assertThat(origTokens)
          .containsExactlyElementsIn(TestUtility.extractTokens(treeByOpt))
          .inOrder();


  }

  @Test
  public void fuzzerBasicTest() throws IOException {
    testOneCFile("test_data/c_programs/gcc_testsuite/06002.c");
  }
}
