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
package org.perses.antlr

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableSet
import org.perses.antlr.ast.AbstractPersesRuleDefAst

class RuleHierarchyInfo internal constructor(
  val ruleDef: AbstractPersesRuleDefAst,
  val immediateSubRuleNames: ImmutableSet<String>,
  private val canBeEpsilon: Boolean
) : Comparable<RuleHierarchyInfo> {

  private var _transitiveSubRules: ImmutableSet<RuleHierarchyInfo>? = null
    get() {
      check(field != null)
      return field
    }
    set(value) {
      require(value != null)
      require(field == null)
      field = value
    }

  var transitiveSubRules: ImmutableSet<RuleHierarchyInfo>
    get() = _transitiveSubRules!!
    set(value) {
      _transitiveSubRules = value
    }

  /** Test whether the current rule is a SUPER rule of the given argument `subrule`  */
  fun isSuperOf(subrule: RuleHierarchyInfo): Boolean {
    return transitiveSubRules.contains(subrule)
  }

  fun canRuleBeEpsilon(): Boolean {
    return canBeEpsilon
  }

  /**
   * Test whether the current rule is EQUAL to or a SUPER rule of the given argument `subrule`
   */
  fun isEqualToOrSuperOf(subrule: RuleHierarchyInfo): Boolean {
    return this == subrule || isSuperOf(subrule)
  }

  val ruleName: String
    get() = ruleDef.ruleNameHandle.ruleName

  override fun compareTo(other: RuleHierarchyInfo): Int {
    return ruleName.compareTo(other.ruleName)
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("ruleName", ruleName).toString()
  }
}
