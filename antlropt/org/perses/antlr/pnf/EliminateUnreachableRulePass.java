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

import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.DefaultAstVisitor;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.ArrayDeque;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.stream.Collectors;

public class EliminateUnreachableRulePass extends AbstractPnfPass {

  private final String entryRuleName;

  public EliminateUnreachableRulePass(String entryRuleName) {
    this.entryRuleName = entryRuleName;
  }

  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    LinkedHashSet<RuleNameRegistry.RuleNameHandle> usedRules = new LinkedHashSet<>();
    final LinkedHashSet<RuleNameRegistry.RuleNameHandle> visited = new LinkedHashSet<>();
    final ArrayDeque<RuleNameRegistry.RuleNameHandle> worklist = new ArrayDeque<>();
    RuleNameRegistry.RuleNameHandle rootRuleName =
        grammar
            .getOriginalGrammar()
            .getSymbolTable()
            .getRuleNameRegistry()
            .getOrThrow(entryRuleName);
    usedRules.add(rootRuleName);
    worklist.addLast(rootRuleName);
    while (worklist.size() > 0) {
      final RuleNameRegistry.RuleNameHandle name = worklist.pollLast();
      if (visited.contains(name)) {
        continue;
      } else {
        visited.add(name);
      }
      for (AbstractPersesRuleElement def : grammar.getRuleDefinition(name)) {
        RuleNameCollector collector = new RuleNameCollector();
        collector.preorder(def);
        usedRules.addAll(collector.usedRules);
        worklist.addAll(collector.usedRules);
      }
    }
    if (usedRules.isEmpty()) {
      return grammar;
    }
    MutableRuleDefMap mutable =
        grammar.createMutable();
    List<RuleNameRegistry.RuleNameHandle> unusedRuleNames =
        mutable.keySet().stream()
            .filter(name -> !usedRules.contains(name))
            .collect(Collectors.toList());
    for (RuleNameRegistry.RuleNameHandle unusedRuleName : unusedRuleNames) {
      mutable.removeAll(unusedRuleName);
    }
    return grammar.createWithParserDefs(mutable);
  }

  private static class RuleNameCollector extends DefaultAstVisitor {
    final LinkedHashSet<RuleNameRegistry.RuleNameHandle> usedRules = new LinkedHashSet<>();

    @Override
    protected void visit(PersesRuleReferenceAst ast) {
      usedRules.add(ast.getRuleNameHandle());
    }
  }
}
