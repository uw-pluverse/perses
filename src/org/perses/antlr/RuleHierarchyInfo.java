/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.antlr;

import com.google.common.collect.ImmutableSet;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;

public final class RuleHierarchyInfo implements Comparable<RuleHierarchyInfo> {

  private final boolean canBeEpsilon;
  private final AbstractPersesRuleDefAst ruleDef;
  private final ImmutableSet<String> immediateSubRuleNames;
  private ImmutableSet<RuleHierarchyInfo> transitiveSubRules;

  RuleHierarchyInfo(
      AbstractPersesRuleDefAst ruleDef,
      ImmutableSet<String> immediateSubRuleNames,
      boolean canBeEpsilon) {
    this.ruleDef = ruleDef;
    this.immediateSubRuleNames = immediateSubRuleNames;
    this.canBeEpsilon = canBeEpsilon;
  }

  /** Test whether the current rule is a SUPER rule of the given argument {@code subrule} */
  public boolean isSuperOf(final RuleHierarchyInfo subrule) {
    assert transitiveSubRules != null : "The transitive subrule set has not been built";
    return this.transitiveSubRules.contains(subrule);
  }

  public AbstractPersesRuleDefAst getRuleDef() {
    return ruleDef;
  }

  public boolean canRuleBeEpsilon() {
    return canBeEpsilon;
  }

  /**
   * Test whether the current rule is EQUAL to or a SUPER rule of the given argument {@code subrule}
   */
  public boolean isEqualToOrSuperOf(final RuleHierarchyInfo subrule) {
    return this.equals(subrule) || this.isSuperOf(subrule);
  }

  public ImmutableSet<String> getImmediateSubRuleNames() {
    return immediateSubRuleNames;
  }

  public ImmutableSet<RuleHierarchyInfo> getTransitiveSubRules() {
    assert transitiveSubRules != null : "This field has not been set";
    return transitiveSubRules;
  }

  void setTransitiveSubRules(final ImmutableSet<RuleHierarchyInfo> transitiveSubRules) {
    assert this.transitiveSubRules == null : "Already set";
    this.transitiveSubRules = transitiveSubRules;
  }

  public String getRuleName() {
    return ruleDef.getRuleNameHandle().get();
  }

  @Override
  public int compareTo(RuleHierarchyInfo o) {
    return this.getRuleName().compareTo(o.getRuleName());
  }

  @Override
  public String toString() {
    return getRuleName();
  }
}
