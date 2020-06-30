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

import com.google.common.collect.ImmutableList;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.AbstractPersesAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;

import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class AltRulesInlinePassTest {

  private InlineSingleUseAltRulePass pass;

  @Before
  public void setup() {
    pass = new InlineSingleUseAltRulePass();
  }

  @Test
  public void test() {
    PersesGrammar grammar =
        GrammarTestingUtility.createPersesGrammarFromString("a : b | c;", "b : d | e;");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    ImmutableRuleDefMap processed = pass.process(defMap);
    ImmutableList<AbstractPersesRuleElement> a = processed.getRuleDefinition("a");
    assertThat(a).hasSize(3);
    assertThat(a.stream().map(AbstractPersesAst::getSourceCode).collect(Collectors.toList()))
        .containsExactly("d", "e", "c");
  }
}
