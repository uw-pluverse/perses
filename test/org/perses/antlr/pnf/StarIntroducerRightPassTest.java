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
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class StarIntroducerRightPassTest extends PnfRightTestGrammar {

  private StarRightIntroducerPass pass;

  @Before
  public void setup() {
    pass = new StarRightIntroducerPass();
  }

  @Test
  public void testStarIntroducerRightPass_pnf_grammar() {
    PersesGrammar grammar =
        GrammarTestingUtility.createPersesGrammarFromString(
            new StringBuilder()
                .append("a: c b | d | ;")
                .append("b: c d | d | d c b | d d ;")
                .append("c: 'c';")
                .append("d: 'd';")
                .toString());
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    ImmutableRuleDefMap result = pass.process(defMap);
    grammar = result.getPersesGrammar();

    AbstractPersesRuleDefAst b = grammar.getRuleDefinition("b").get();
    AbstractPersesRuleElement bBody = b.getBody();
    assertThat(bBody.getChildCount()).isEqualTo(2);
    assertThat(bBody.getChild(0).getSourceCode()).isEqualTo("kleene_star__b_1");
    assertThat(bBody.getChild(1).getSourceCode()).isEqualTo("b_3");

    AbstractPersesRuleDefAst kleene_star__b_1 = grammar.getRuleDefinition("kleene_star__b_1").get();
    AbstractPersesRuleElement kleeneBody = kleene_star__b_1.getBody();
    assertThat(kleeneBody.getSourceCode()).isEqualTo("b_2*");

    AbstractPersesRuleDefAst b_2 = grammar.getRuleDefinition("b_2").get();
    assertThat(b_2.getBody().getSourceCode()).isEqualTo("d c");

    AbstractPersesRuleElement b_3 = grammar.getRuleDefinition("b_3").get().getBody();
    assertThat(b_3.getChildCount()).isEqualTo(3);
    assertThat(b_3.getChild(0).getSourceCode()).isEqualTo("c d");
    assertThat(b_3.getChild(1).getSourceCode()).isEqualTo("d");
    assertThat(b_3.getChild(2).getSourceCode()).isEqualTo("d d");
  }
}
