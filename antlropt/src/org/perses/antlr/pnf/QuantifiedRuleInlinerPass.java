/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import java.util.Set;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry;

/**
 * start : a ;
 *
 * <p>a: kleene_star__test;
 *
 * <p>kleene_star__test: ID*;
 *
 * <p>The rule "a" is redundant, and can be removed. So the refactored grammar becomes
 *
 * <p>start : kleene_star__test;
 *
 * <p>kleene_star__test: ID*;
 */
@Deprecated
public class QuantifiedRuleInlinerPass extends AbstractPnfPass {
  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    for (RuleNameRegistry.RuleNameHandle ruleName : mutable.keySet()) {
      final Set<AbstractPersesRuleElement> defs = mutable.get(ruleName);
      if (defs.size() != 1) {
        continue;
      }
      final AbstractPersesRuleElement body = Iterables.getOnlyElement(defs);
      if (body.getTag() != AstTag.RULE_REF) {
        continue;
      }
      RuleNameRegistry.RuleNameHandle calledRuleName =
          ((PersesRuleReferenceAst) body).getRuleNameHandle();
      switch (calledRuleName.getType()) {
        case KLEENE_PLUS:
        case KLEENE_STAR:
        case OPTIONAL:
        case TOKEN:
        case OTHER_RULE:
      }
    }
    return null;
  }
}
