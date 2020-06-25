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
package org.perses.antlr.ast;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;

import java.util.LinkedHashSet;
import java.util.List;
import java.util.stream.Collectors;

public class RuleEpsilonComputer {

  public static EpsilonInfo computeEpsilonableRules(
      ImmutableList<AbstractPersesRuleDefAst> grammar) {
    RuleEpsilonComputer computer = new RuleEpsilonComputer(grammar);
    computer.compute();
    ImmutableSet.Builder<AbstractPersesRuleDefAst> builder = ImmutableSet.builder();
    for (AbstractPersesRuleDefAst rule : grammar) {
      if (computer.containsEpsilon(rule)) {
        builder.add(rule);
      }
    }
    return new EpsilonInfo(builder.build(), computer.getEpsilonableElements());
  }

  private final LinkedHashSet<AbstractPersesRuleElement> epsilonable = new LinkedHashSet<>();
  private final ImmutableMap<String, AbstractPersesRuleDefAst> nameToRuleMap;

  private RuleEpsilonComputer(ImmutableList<AbstractPersesRuleDefAst> grammar) {
    final ImmutableMap.Builder<String, AbstractPersesRuleDefAst> builder = ImmutableMap.builder();
    for (AbstractPersesRuleDefAst ruleDefAst : grammar) {
      builder.put(ruleDefAst.getRuleNameHandle().get(), ruleDefAst);
    }
    nameToRuleMap = builder.build();
  }

  public boolean containsEpsilon(AbstractPersesRuleDefAst rule) {
    return epsilonable.contains(rule.getBody());
  }

  public ImmutableSet<AbstractPersesRuleElement> getEpsilonableElements() {
    return ImmutableSet.copyOf(epsilonable);
  }

  public void compute() {
    final EpsilonComputingVisitor visitor = new EpsilonComputingVisitor();

    int prevSize;
    do {
      prevSize = epsilonable.size();
      List<AbstractPersesRuleDefAst> rules =
          nameToRuleMap.values().stream()
              .filter(def -> !epsilonable.contains(def.getBody()))
              .collect(Collectors.toList());
      for (AbstractPersesRuleDefAst rule : rules) {
        final AbstractPersesRuleElement body = rule.getBody();
        visitor.postorder(body);
      }
    } while (prevSize < epsilonable.size());
  }

  private class EpsilonComputingVisitor extends DefaultAstVisitor {

    @Override
    protected void visit(PersesSequenceAst ast) {
      final int count = ast.getChildCount();
      for (int i = 0; i < count; ++i) {
        if (!epsilonable.contains(ast.getChild(i))) {
          return;
        }
      }
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesPlusAst ast) {
      if (epsilonable.contains(ast.getBody())) {
        epsilonable.add(ast);
      }
    }

    @Override
    protected void visit(PersesStarAst ast) {
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesOptionalAst ast) {
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesLexerSkipCommandAst ast) {
      if (epsilonable.contains(ast.getBody())) {
        epsilonable.add(ast);
      }
    }

    @Override
    protected void visit(PersesLexerChannelCommandAst ast) {
      if (epsilonable.contains(ast.getBody())) {
        epsilonable.add(ast);
      }
    }

    @Override
    protected void visit(PersesEpsilonAst ast) {
      epsilonable.add(ast);
    }

    @Override
    protected void visit(PersesAlternativeBlockAst ast) {
      final int count = ast.getChildCount();
      for (int i = 0; i < count; ++i) {
        if (epsilonable.contains(ast.getChild(i))) {
          epsilonable.add(ast);
          break;
        }
      }
    }

    @Override
    protected void visit(PersesRuleReferenceAst ast) {
      AbstractPersesRuleDefAst def = nameToRuleMap.get(ast.getRuleNameHandle().get());
      if (epsilonable.contains(def.getBody())) {
        epsilonable.add(ast);
      }
    }
  }
}
