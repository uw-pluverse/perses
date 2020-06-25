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

import com.google.common.collect.ImmutableSet;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle;

import java.util.Collection;
import java.util.LinkedHashSet;
import java.util.Set;

public class ProjectedHashMultimap {

  private final MutableRuleDefMap map;
  private final LinkedHashSet<RuleNameHandle> projectedKeySet;

  public ProjectedHashMultimap(MutableRuleDefMap map, Collection<RuleNameHandle> projectedKeySet) {
    this.map = map;
    this.projectedKeySet = new LinkedHashSet<>(projectedKeySet);
  }

  public Set<RuleNameHandle> ketSet() {
    return projectedKeySet;
  }

  public Set<AbstractPersesRuleElement> get(RuleNameHandle ruleName) {
    if (!projectedKeySet.contains(ruleName)) {
      return ImmutableSet.of();
    }
    return map.get(ruleName);
  }

  public boolean containsKey(RuleNameHandle ruleName) {
    return projectedKeySet.contains(ruleName);
  }

  public boolean remove(RuleNameHandle key, AbstractPersesRuleElement value) {
    if (!containsKey(key)) {
      return false;
    }
    final boolean result = map.remove(key, value);
    if (!map.containsKey(key)) {
      projectedKeySet.remove(key);
    }
    return result;
  }

  public void put(RuleNameHandle key, AbstractPersesRuleElement value) {
    projectedKeySet.add(key);
    map.put(key, value);
  }
}
