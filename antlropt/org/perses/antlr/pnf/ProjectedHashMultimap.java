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
