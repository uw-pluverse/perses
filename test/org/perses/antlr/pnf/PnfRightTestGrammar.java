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

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableMap;
import org.perses.antlr.GrammarTestingUtility;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.AbstractMap;
import java.util.Map;

public class PnfRightTestGrammar {

  protected final PersesGrammar grammar;
  protected final ImmutableRuleDefMap ruleDefMap;

  protected final RuleNameRegistry.RuleNameHandle a;
  protected final RuleNameRegistry.RuleNameHandle b;
  protected final RuleNameRegistry.RuleNameHandle c;
  protected final RuleNameRegistry.RuleNameHandle d;

  protected final AbstractPersesRuleElement def_a_cb;
  protected final AbstractPersesRuleElement def_a_d;
  protected final AbstractPersesRuleElement def_b_da;
  protected final AbstractPersesRuleElement def_b_cd;
  protected final AbstractPersesRuleElement def_c_c;
  protected final AbstractPersesRuleElement def_d_d;

  protected PnfRightTestGrammar() {
    grammar =
        GrammarTestingUtility.createPersesGrammarFromString(
            "a : c b | d |;", "b : d a | c d;", "c : 'c';", "d : 'd';");
    RuleNameRegistry ruleNameRegistry = grammar.getSymbolTable().getRuleNameRegistry();
    a = ruleNameRegistry.getOrThrow("a");
    b = ruleNameRegistry.getOrThrow("b");
    c = ruleNameRegistry.getOrThrow("c");
    d = ruleNameRegistry.getOrThrow("d");

    ruleDefMap = ImmutableRuleDefMap.create(grammar);
    ImmutableMap<String, AbstractPersesRuleElement> codeToDef =
        ruleDefMap
            .entryStream()
            .map(
                entry ->
                    new AbstractMap.SimpleEntry(entry.getValue().getSourceCode(), entry.getValue()))
            .collect(
                ImmutableMap.toImmutableMap(
                    Map.Entry<String, AbstractPersesRuleElement>::getKey,
                    Map.Entry<String, AbstractPersesRuleElement>::getValue));

    def_a_cb = Preconditions.checkNotNull(codeToDef.get("c b"));
    def_a_d = Preconditions.checkNotNull(codeToDef.get("d"));
    def_b_da = Preconditions.checkNotNull(codeToDef.get("d a"));
    def_b_cd = Preconditions.checkNotNull(codeToDef.get("c d"));
    def_c_c = Preconditions.checkNotNull(codeToDef.get("'c'"));
    def_d_d = Preconditions.checkNotNull(codeToDef.get("'d'"));
  }
}
