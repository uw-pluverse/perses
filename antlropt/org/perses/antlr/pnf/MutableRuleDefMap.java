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
import com.google.common.collect.ImmutableListMultimap;
import com.google.common.collect.LinkedHashMultimap;
import org.perses.antlr.ast.AbstractPersesRuleElement;
import org.perses.antlr.ast.AstTag;
import org.perses.antlr.ast.PersesAlternativeBlockAst;
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle;

import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.function.BiConsumer;

import static com.google.common.base.Preconditions.checkArgument;

public final class MutableRuleDefMap {
  private final LinkedHashMultimap<RuleNameHandle, AbstractPersesRuleElement> defMap;

  public MutableRuleDefMap(
      ImmutableListMultimap<RuleNameHandle, AbstractPersesRuleElement> defMap) {
    this.defMap = LinkedHashMultimap.create(defMap);
  }

  public MutableRuleDefMap() {
    defMap = LinkedHashMultimap.create();
  }

  public void validate() {
    for (Map.Entry<RuleNameHandle, AbstractPersesRuleElement> entry : defMap.entries()) {
      Preconditions.checkState(
          entry.getValue().getTag() != AstTag.ALTERNATIVE_BLOCK,
          "key=%s, value=%s",
          entry.getKey(),
          entry.getValue());
    }
  }

  public ImmutableListMultimap<RuleNameHandle, AbstractPersesRuleElement> toImmutable() {
    return ImmutableListMultimap.copyOf(defMap);
  }

  public Set<AbstractPersesRuleElement> get(RuleNameHandle key) {
    return defMap.get(key);
  }

  public Set<Map.Entry<RuleNameHandle, AbstractPersesRuleElement>> entries() {
    return defMap.entries();
  }

  public Set<AbstractPersesRuleElement> removeAll(Object key) {
    return defMap.removeAll(key);
  }

  public boolean put(RuleNameHandle key, AbstractPersesRuleElement value) {
    checkArgument(!(value instanceof PersesAlternativeBlockAst), "key=%s, value=%s", key, value);
    return defMap.put(key, value);
  }

  public boolean putAndAutoDecomposeAltBlock(RuleNameHandle key, AbstractPersesRuleElement value) {
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
      BiConsumer<? super RuleNameHandle, ? super AbstractPersesRuleElement> action) {
    defMap.forEach(action);
  }

  public boolean isEmpty() {
    return defMap.isEmpty();
  }

  public boolean putAll(RuleNameHandle key, Iterable<? extends AbstractPersesRuleElement> values) {
    for (AbstractPersesRuleElement v : values) {
      checkArgument(!(v instanceof PersesAlternativeBlockAst), "key=%s, value=%s", key, v);
    }
    return defMap.putAll(key, values);
  }

  public boolean remove(Object key, Object value) {
    return defMap.remove(key, value);
  }

  public Set<RuleNameHandle> keySet() {
    return defMap.keySet();
  }
}
