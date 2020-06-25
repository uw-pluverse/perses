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

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.stream.Collectors;

@RunWith(JUnit4.class)
public class EliminateUnreachableRulePassTest {

  @Test
  public void test() {
    PersesGrammar grammar =
        GrammarTestingUtility.createPersesGrammarFromString("start:a;", "a:ID;", "b:ID;");
    ImmutableRuleDefMap defMap = ImmutableRuleDefMap.create(grammar);
    Truth.assertThat(
            defMap.getParserRuleNames().stream()
                .map(RuleNameRegistry.RuleNameHandle::get)
                .collect(Collectors.toList()))
        .containsExactly("start", "a", "b");
    EliminateUnreachableRulePass pass = new EliminateUnreachableRulePass("start");
    ImmutableRuleDefMap processedMap = pass.process(defMap);
    Truth.assertThat(
            processedMap.getParserRuleNames().stream()
                .map(RuleNameRegistry.RuleNameHandle::get)
                .collect(Collectors.toList()))
        .containsExactly("start", "a");
  }
}
