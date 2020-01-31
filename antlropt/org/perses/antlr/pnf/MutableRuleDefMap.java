package org.perses.antlr.pnf;

import com.google.common.base.Preconditions;
import com.google.common.collect.HashMultimap;
import com.google.common.collect.ImmutableSetMultimap;
import com.google.common.collect.LinkedHashMultimap;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesAlternativeBlockAst;
import org.perses.antlr.ast.RuleNameRegistry;

import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.function.BiConsumer;

import static com.google.common.base.Preconditions.checkArgument;

public final class MutableRuleDefMap {
  private final LinkedHashMultimap<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> defMap;

  public MutableRuleDefMap(
      ImmutableSetMultimap<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> defMap) {
    this.defMap = LinkedHashMultimap.create(defMap);
  }

  public MutableRuleDefMap() {
    defMap = LinkedHashMultimap.create();
  }

  public void validate() {
    for (Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> entry :
        defMap.entries()) {
      Preconditions.checkState(
          entry.getValue().getTag() != AstTag.ALTERNATIVE_BLOCK,
          "key=%s, value=%s",
          entry.getKey(),
          entry.getValue());
    }
  }

  public ImmutableSetMultimap<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>
      toImmutable() {
    return ImmutableSetMultimap.copyOf(defMap);
  }

  public Set<AbstractPersesRuleElement> get(RuleNameRegistry.RuleNameHandle key) {
    return defMap.get(key);
  }

  public Set<Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement>> entries() {
    return defMap.entries();
  }

  public Set<AbstractPersesRuleElement> removeAll(Object key) {
    return defMap.removeAll(key);
  }

  public boolean put(RuleNameRegistry.RuleNameHandle key, AbstractPersesRuleElement value) {
    checkArgument(!(value instanceof PersesAlternativeBlockAst), "key=%s, value=%s", key, value);
    return defMap.put(key, value);
  }

  public boolean putAndAutoDecomposeAltBlock(
      RuleNameRegistry.RuleNameHandle key, AbstractPersesRuleElement value) {
    if (value.getTag() == AstTag.ALTERNATIVE_BLOCK) {
      boolean result = false;
      for (int i = 0, size = value.getChildCount(); i < size; ++i) {
        if (putAndAutoDecomposeAltBlock(key, value.getChild(i))) {
          result = true;
        }
      }
      return result;
    } else {
      return defMap.put(key, value);
    }
  }

  public int size() {
    return defMap.size();
  }

  public boolean containsKey(Object key) {
    return defMap.containsKey(key);
  }

  public Collection<AbstractPersesRuleElement> values() {
    return defMap.values();
  }

  public void forEach(
      BiConsumer<? super RuleNameRegistry.RuleNameHandle, ? super AbstractPersesRuleElement>
          action) {
    defMap.forEach(action);
  }

  public boolean isEmpty() {
    return defMap.isEmpty();
  }

  public boolean putAll(
      RuleNameRegistry.RuleNameHandle key, Iterable<? extends AbstractPersesRuleElement> values) {
    for (AbstractPersesRuleElement v : values) {
      checkArgument(!(v instanceof PersesAlternativeBlockAst), "key=%s, value=%s", key, v);
    }
    return defMap.putAll(key, values);
  }

  public boolean remove(Object key, Object value) {
    return defMap.remove(key, value);
  }

  public Set<RuleNameRegistry.RuleNameHandle> keySet() {
    return defMap.keySet();
  }
}
