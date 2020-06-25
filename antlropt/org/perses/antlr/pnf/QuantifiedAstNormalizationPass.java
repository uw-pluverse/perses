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

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.LinkedHashMultimap;
import org.perses.antlr.RuleType;
import org.perses.antlr.ast.AbstractPersesQuantifiedAst;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstEdit;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesRuleReferenceAst;
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle;

import java.util.Map;
import java.util.Optional;

import static com.google.common.base.Preconditions.checkState;

public class QuantifiedAstNormalizationPass extends AbstractPnfPass {
  @Override
  public ImmutableRuleDefMap process(ImmutableRuleDefMap grammar) {
    MutableRuleDefMap mutable = grammar.createMutable();
    LinkedHashMultimap<RuleNameHandle, AbstractPersesRuleElement> toRemove =
        LinkedHashMultimap.create();
    LinkedHashMultimap<RuleNameHandle, AbstractPersesRuleElement> toAdd =
        LinkedHashMultimap.create();

    for (Map.Entry<RuleNameHandle, AbstractPersesRuleElement> rule : mutable.entries()) {
      final RuleNameHandle ruleName = rule.getKey();
      final AbstractPersesRuleElement def = rule.getValue();
      FactorQuantifiedEdit factorEdit = new FactorQuantifiedEdit(ruleName);
      Optional<AbstractPersesRuleElement> newDef = factorEdit.apply(def);
      if (newDef.isPresent()) {
        toRemove.put(ruleName, def);
        toAdd.put(ruleName, newDef.get());
        factorEdit.newRules.entries().forEach(entry -> toAdd.put(entry.getKey(), entry.getValue()));
      } else {
        checkState(factorEdit.newRules.isEmpty(), factorEdit.newRules);
      }
    }
    toRemove.entries().forEach(entry -> mutable.remove(entry.getKey(), entry.getValue()));
    toAdd.entries().forEach(entry -> mutable.put(entry.getKey(), entry.getValue()));
    return grammar.createWithParserDefs(mutable);
  }

  /** Factors out the quantified parts to conform to the perses normal form. */
  @VisibleForTesting
  static final class FactorQuantifiedEdit extends AstEdit {

    private final RuleNameHandle currentRuleName;
    private final MutableRuleDefMap newRules = new MutableRuleDefMap();

    FactorQuantifiedEdit(RuleNameHandle currentRuleName) {
      this.currentRuleName = currentRuleName;
    }

    public Iterable<Map.Entry<RuleNameHandle, AbstractPersesRuleElement>> getNewRules() {
      return newRules.entries();
    }

    @Override
    protected Optional<AbstractPersesRuleElement> internalApply(
        final AbstractPersesRuleElement element, boolean isRoot) {
      final AstTag tag = element.getTag();
      switch (tag) {
        case PLUS:
        case STAR:
        case OPTIONAL:
          checkState(element.getChildCount() == 1);
          final AbstractPersesRuleElement child = element.getChild(0);
          AbstractPersesRuleElement newBody;
          if (isTerminalOrRuleRef(child)) {
            newBody = element;
          } else {
            checkState(!(child instanceof AbstractPersesQuantifiedAst));
            RuleNameHandle childRuleName =
                currentRuleName.createAuxiliaryRuleName(RuleType.OTHER_RULE);
            newRules.putAndAutoDecomposeAltBlock(childRuleName, child);
            newBody =
                element.createWithNewChildren(
                    ImmutableList.of(new PersesRuleReferenceAst(childRuleName)));
          }
          if (isRoot && currentRuleName.getType() == PnfUtil.getRuleTypeIfQuantifiedOrThrow(tag)) {
            // No need to change.
            return newBody == element ? Optional.empty() : Optional.of(newBody);
          }
          checkState(
              currentRuleName.getType() == RuleType.OTHER_RULE,
              "The rule [%s] has type %s",
              currentRuleName,
              currentRuleName.getType());
          final RuleNameHandle kleeneRuleName =
              currentRuleName.createAuxiliaryRuleName(PnfUtil.getRuleTypeIfQuantifiedOrThrow(tag));
          newRules.put(kleeneRuleName, newBody);
          return Optional.of(new PersesRuleReferenceAst(kleeneRuleName));
      }
      return Optional.empty();
    }

    private static boolean isTerminalOrRuleRef(AbstractPersesRuleElement ast) {
      AstTag tag = ast.getTag();
      return tag == AstTag.RULE_REF || tag == AstTag.TERMINAL;
    }
  }
}
