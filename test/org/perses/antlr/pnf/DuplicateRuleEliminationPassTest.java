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

import com.google.common.collect.Iterables;
import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;

@RunWith(JUnit4.class)
public class DuplicateRuleEliminationPassTest {

  @Test
  public void testWithStartRuleName() {
    PersesGrammar persesGrammar =
        GrammarTestingUtility.createPersesGrammarFromString(
            new StringBuilder()
                .append("start: b;")
                .append("c: d;")
                .append("b: 'e';")
                .append("d: 'e';")
                .toString());
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(persesGrammar);
    {
      DuplicateRuleEliminationPass pass = new DuplicateRuleEliminationPass("start");
      ImmutableRuleDefMap processed = pass.process(defMap);
      Truth.assertThat(processed.size()).isEqualTo(2);
      Truth.assertThat(
              Iterables.getOnlyElement(processed.getRuleDefinition("start")).getSourceCode())
          .isEqualTo("b");
      Truth.assertThat(Iterables.getOnlyElement(processed.getRuleDefinition("b")).getSourceCode())
          .isEqualTo("'e'");
    }
    {
      DuplicateRuleEliminationPass pass = new DuplicateRuleEliminationPass("c");
      ImmutableRuleDefMap processed = pass.process(defMap);
      Truth.assertThat(processed.size()).isEqualTo(2);
      Truth.assertThat(
          Iterables.getOnlyElement(processed.getRuleDefinition("c")).getSourceCode())
          .isEqualTo("b");
      Truth.assertThat(Iterables.getOnlyElement(processed.getRuleDefinition("b")).getSourceCode())
          .isEqualTo("'e'");
    }
  }
}
