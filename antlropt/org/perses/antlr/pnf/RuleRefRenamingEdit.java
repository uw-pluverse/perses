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

import org.perses.antlr.ast.*;

import java.util.ArrayList;
import java.util.Map;
import java.util.Optional;

public class RuleRefRenamingEdit extends AstEdit {

  public static void renameDefMap(
      MutableRuleDefMap defMap,
      RuleNameRegistry.RuleNameHandle oldName,
      RuleNameRegistry.RuleNameHandle newName) {
    RuleRefRenamingEdit edit = new RuleRefRenamingEdit(oldName, newName);
    ArrayList<RuleEditTriple> ruleEditTriples = new ArrayList<>();
    for (Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> entry :
        defMap.entries()) {
      Optional<AbstractPersesRuleElement> result = edit.apply(entry.getValue());
      if (result.isPresent()) {
        ruleEditTriples.add(new RuleEditTriple(entry.getKey(), entry.getValue(), result.get()));
      }
    }
    ruleEditTriples.forEach(triple -> triple.applyTo(defMap));
  }

  private final RuleNameRegistry.RuleNameHandle oldName;
  private final RuleNameRegistry.RuleNameHandle newName;

  public RuleRefRenamingEdit(
      RuleNameRegistry.RuleNameHandle oldName, RuleNameRegistry.RuleNameHandle newName) {
    this.oldName = oldName;
    this.newName = newName;
  }

  @Override
  public Optional<AbstractPersesRuleElement> internalApply(
      AbstractPersesRuleElement element, boolean isRoot) {
    if (element.getTag() != AstTag.RULE_REF) {
      return Optional.empty();
    }
    PersesRuleReferenceAst ref = (PersesRuleReferenceAst) element;
    RuleNameRegistry.RuleNameHandle name = ref.getRuleNameHandle();
    if (!name.equals(oldName)) {
      return Optional.empty();
    }
    return Optional.of(new PersesRuleReferenceAst(newName));
  }
}
