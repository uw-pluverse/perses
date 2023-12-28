/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableSet
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.protobuf.GrammarHierarchyOuterClass
import org.perses.util.toImmutableSet

class RuleHierarchyEntry internal constructor(
  val ruleDef: AbstractPersesRuleDefAst,
  val immediateSubRuleNames: ImmutableSet<String>,
  val immediateStringLiterals: ImmutableSet<String>,
  private val canBeEpsilon: Boolean,
) : Comparable<RuleHierarchyEntry> {

  private var _transitiveSubRules: ImmutableSet<RuleHierarchyEntry>? = null
    get() {
      check(field != null)
      return field
    }
    set(value) {
      require(value != null)
      require(field == null)
      field = value
    }

  private var _transitiveStringLiterals: ImmutableSet<String>? = null
    get() {
      check(field != null)
      return field
    }
    set(value) {
      require(value != null)
      require(field == null)
      field = value
    }

  var transitiveSubRules: ImmutableSet<RuleHierarchyEntry>
    get() = _transitiveSubRules!!
    internal set(value) {
      _transitiveSubRules = value
      _transitiveStringLiterals = value.asSequence()
        .flatMap { it.immediateStringLiterals }
        .plus(immediateStringLiterals)
        .toImmutableSet()
    }

  var transitiveStringLiterals: ImmutableSet<String>
    get() = _transitiveStringLiterals!!
    private set(value) {
      _transitiveStringLiterals = value
    }

  /** Test whether the current rule is a SUPER rule of the given argument `subrule`  */
  fun isSuperOf(subrule: RuleHierarchyEntry): Boolean {
    return transitiveSubRules.contains(subrule)
  }

  fun canRuleBeEpsilon(): Boolean {
    return canBeEpsilon
  }

  /**
   * Test whether the current rule is EQUAL to or a SUPER rule of the given argument `subrule`
   */
  fun isEqualToOrSuperOf(subrule: RuleHierarchyEntry): Boolean {
    return this == subrule || isSuperOf(subrule)
  }

  val ruleName: String
    get() = ruleDef.ruleNameHandle.ruleName

  override fun compareTo(other: RuleHierarchyEntry): Int {
    return ruleName.compareTo(other.ruleName)
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("ruleName", ruleName).toString()
  }

  fun toProtoRuleHierarchyEntry(): GrammarHierarchyOuterClass.RuleHierarchyEntry {
    val builder = GrammarHierarchyOuterClass.RuleHierarchyEntry.newBuilder()
    builder.ruleName = ruleName
    builder.canBeEpsilon = canBeEpsilon
    immediateSubRuleNames.asSequence().sorted().forEach { builder.addImmediateSubRuleNames(it) }
    immediateStringLiterals.asSequence().sorted().forEach { builder.addImmediateStringLiterals(it) }
    transitiveSubRules.asSequence()
      .map { it.ruleName }
      .sorted()
      .forEach { builder.addTransitiveSubRuleNames(it) }
    transitiveStringLiterals.asSequence()
      .sorted()
      .forEach { builder.addTransitiveStringLiterals(it) }
    return builder.build()
  }
}
