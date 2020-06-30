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
package org.perses.antlr.pnf;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class PnfPassManagerTest extends PnfLeftTestGrammar {

  private PnfPassManager manager;
  private PnfPassManager.Listener listener =
      new PnfPassManager.Listener() {
        @Override
        protected void start(PersesGrammar grammar, String startRuleName) {
          System.err.println("Starting...");
          System.err.println(grammar.getSourceCode());
        }

        @Override
        protected void beforePass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {
          super.beforePass(grammar, passClass, iteration);
        }

        @Override
        protected void afterPass(ImmutableRuleDefMap grammar, Class<?> passClass, int iteration) {
          System.err.println("After pass " + passClass);
          System.err.println(grammar.getPersesGrammar().getSourceCode());
        }
      };

  @Before
  public void setup() {
    manager = new PnfPassManager();
  }

  @Test
  public void testPassManager() {
    // No test so far.
  }

  @Test
  public void testConvertC() {
    PersesGrammar grammar = GrammarTestingUtility.loadGrammarFromFile("C.g4");
    PersesGrammar processed = manager.process(grammar, "compilationUnit");
    System.out.println(processed.getSourceCode());
  }

  @Test
  public void testConvertPrimaryExprOfGo_shouldNotCrash() {
    PersesGrammar grammar =
        GrammarTestingUtility.loadGrammarFromFile("nested_alt_block_from_go.g4");
    final PersesGrammar processed = manager.process(grammar, "primaryExpr", listener);
    final String sourceCode = processed.getSourceCode();
    System.err.println(sourceCode);
  }


  @Test
  public void testConvertGoParser_shouldNotCrash() {
    PersesGrammar grammar =
        GrammarTestingUtility.loadGrammarFromFile("GoParser.g4");
    final PersesGrammar processed = manager.process(grammar, "primaryExpr", listener);
    final String sourceCode = processed.getSourceCode();
    System.err.println(sourceCode);
  }
}
