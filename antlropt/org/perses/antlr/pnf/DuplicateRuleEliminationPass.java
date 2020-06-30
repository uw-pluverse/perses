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
import com.google.common.collect.LinkedHashMultimap;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class DuplicateRuleEliminationPass extends AbstractPnfPass {

  private final String startRuleName;

  public DuplicateRuleEliminationPass(String startRuleName) {
    this.startRuleName = startRuleName;
  }

  @Override
  public ImmutableRuleDefMap process(final ImmutableRuleDefMap origGrammar) {
    final RuleNameRegistry.RuleNameHandle startRuleName =
        origGrammar
            .getPersesGrammar()
            .getSymbolTable()
            .getRuleNameRegistry()
            .getOrThrow(this.startRuleName);
    ImmutableRuleDefMap grammar = origGrammar;
    while (true) {
      PersesGrammar persesGrammar = grammar.getPersesGrammar();
      List<Set<AbstractPersesRuleDefAst>> candidates = searchForCandidates(persesGrammar);
      if (candidates.isEmpty()) {
        break;
      }
      MutableRuleDefMap mutable = grammar.createMutable();
      for (Set<AbstractPersesRuleDefAst> rules : candidates) {
        Preconditions.checkArgument(rules.size() > 1);
        final List<AbstractPersesRuleDefAst> sortedRules =
            rules.stream()
                .filter(def -> !def.getRuleNameHandle().equals(startRuleName))
                .sorted(Comparator.comparing(AbstractPersesRuleDefAst::getRuleNameHandle))
                .collect(Collectors.toList());
        RuleNameRegistry.RuleNameHandle canonicalName;
        List<AbstractPersesRuleDefAst> others;
        if (sortedRules.size() == rules.size()) {
          canonicalName = sortedRules.get(0).getRuleNameHandle();
          others = sortedRules.subList(1, sortedRules.size());
        } else {
          Preconditions.checkState(sortedRules.size() + 1 == rules.size());
          canonicalName = startRuleName;
          others = sortedRules;
        }
        for (AbstractPersesRuleDefAst other : others) {
          RuleNameRegistry.RuleNameHandle oldRuleName = other.getRuleNameHandle();
          mutable.removeAll(oldRuleName);
          RuleRefRenamingEdit.renameDefMap(mutable, oldRuleName, canonicalName);
        }
      }
      grammar = grammar.createWithParserDefs(mutable);
    }
    return grammar;
  }

  private static List<Set<AbstractPersesRuleDefAst>> searchForCandidates(
      PersesGrammar persesGrammar) {
    LinkedHashMultimap<String, AbstractPersesRuleDefAst> map = LinkedHashMultimap.create();
    persesGrammar.getRules().stream()
        .filter(AbstractPersesRuleDefAst::isParserRule) // Not a fragment.
        .forEach(rule -> map.put(rule.getBody().getSourceCode(), rule));
    ArrayList<Set<AbstractPersesRuleDefAst>> duplicateRules = new ArrayList<>();
    for (String sourceCode : map.keySet()) {
      Set<AbstractPersesRuleDefAst> ruleDefinitions = map.get(sourceCode);
      if (ruleDefinitions.size() > 1) {
        duplicateRules.add(ruleDefinitions);
      }
    }
    return duplicateRules;
  }
}
