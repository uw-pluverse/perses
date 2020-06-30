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

import com.google.common.base.MoreObjects;
import com.google.common.base.Preconditions;
import org.checkerframework.checker.nullness.qual.Nullable;
import org.perses.antlr.RuleType;

import java.util.Optional;
import java.util.WeakHashMap;

public class RuleNameRegistry {

  private final WeakHashMap<String, RuleNameHandle> ruleNameMap = new WeakHashMap<>();
  private int idGenerator;

  public RuleNameHandle getOrCreate(String ruleName) {
    RuleNameHandle value = ruleNameMap.get(ruleName);
    if (value == null) {
      value = createOrThrow(ruleName);
    }
    Preconditions.checkState(ruleName.equals(value.ruleName));
    Preconditions.checkState(ruleNameMap.containsKey(ruleName));
    Preconditions.checkState(ruleNameMap.containsValue(value));
    return value;
  }

  public RuleNameHandle createOrThrow(String ruleName) {
    return createOrThrow(ruleName, /*origin=*/ null);
  }

  private RuleNameHandle createOrThrow(String ruleName, @Nullable RuleNameHandle origin) {
    Preconditions.checkArgument(!ruleNameMap.containsKey(ruleName));
    RuleNameHandle value = new RuleNameHandle(ruleName, idGenerator++, origin);
    ruleNameMap.put(ruleName, value);
    return value;
  }

  public Optional<RuleNameHandle> get(String ruleName) {
    return Optional.ofNullable(ruleNameMap.get(ruleName));
  }

  public RuleNameHandle getOrThrow(String ruleName) {
    RuleNameHandle value = ruleNameMap.get(ruleName);
    Preconditions.checkNotNull(value, "no rule '%s' in registry", ruleName);
    return value;
  }

  /** This is just a handle to the rule name. The rule name can be changed. */
  public final class RuleNameHandle implements Comparable<RuleNameHandle> {
    private final String ruleName;
    private final int id;
    private final RuleType type;
    @Nullable private final RuleNameHandle origin;
    private int auxiliaryIdGenerator = 1;

    private RuleNameHandle(String ruleName, int id, @Nullable RuleNameHandle origin) {
      this.ruleName = ruleName;
      this.id = id;
      type = RuleType.determineType(ruleName);
      this.origin = origin;
    }

    public String get() {
      return ruleName;
    }

    public int getId() {
      return id;
    }

    public RuleType getType() {
      return type;
    }

    public RuleNameHandle createAuxiliaryRuleName(RuleType ruleType) {
      if (origin != null) {
        return origin.createAuxiliaryRuleName(ruleType);
      }
      String prefix = ruleType == type ? "" : getDefaultAuxiliaryPrefix(ruleType);
      return createOrThrow(prefix + ruleName + '_' + auxiliaryIdGenerator++, this);
    }

    private String getDefaultAuxiliaryPrefix(RuleType type) {
      switch (type) {
        case KLEENE_PLUS:
        case KLEENE_STAR:
        case OPTIONAL:
        case ALT_BLOCKS:
          return type.getSignaturePrefix();
        case TOKEN:
          return "AUXILIARY__";
        case OTHER_RULE:
          return "auxiliary__";
        default:
          throw new RuntimeException("Cannot reach here");
      }
    }

    @Override
    public int compareTo(RuleNameHandle other) {
      final RuleNameHandle origin = MoreObjects.firstNonNull(this.origin, this);
      final RuleNameHandle otherOrigin = MoreObjects.firstNonNull(other.origin, other);
      final int originCmp = Integer.compare(origin.id, otherOrigin.id);
      if (originCmp != 0) {
        return originCmp;
      }
      return Integer.compare(id, other.id);
    }

    @Override
    public String toString() {
      return MoreObjects.toStringHelper(this).add("id", id).add("name", ruleName).toString();
    }
  }
}
