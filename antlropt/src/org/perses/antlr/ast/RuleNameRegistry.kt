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
package org.perses.antlr.ast

import com.google.common.base.MoreObjects
import org.perses.antlr.RuleType
import java.util.WeakHashMap

class RuleNameRegistry {

  private val ruleNameMap = WeakHashMap<String, RuleNameHandle>()

  private var idGenerator = 0

  fun getOrCreate(ruleName: String): RuleNameHandle {
    var value = ruleNameMap[ruleName]
    if (value == null) {
      value = createOrThrow(ruleName)
    }
    check(ruleName == value.ruleName)
    check(ruleNameMap.containsKey(ruleName))
    check(ruleNameMap.containsValue(value))
    return value
  }

  fun createOrThrow(ruleName: String): RuleNameHandle {
    return createOrThrow(ruleName, origin = null)
  }

  private fun createOrThrow(ruleName: String, origin: RuleNameHandle?): RuleNameHandle {
    require(!ruleNameMap.containsKey(ruleName))
    val value = RuleNameHandle(ruleName, idGenerator++, origin)
    ruleNameMap[ruleName] = value
    return value
  }

  operator fun get(ruleName: String): RuleNameHandle? {
    return ruleNameMap[ruleName]
  }

  fun getOrThrow(ruleName: String): RuleNameHandle {
    val value = ruleNameMap[ruleName]
    check(value != null) { "no rule $ruleName in registry" }
    return value
  }

  /** This is just a handle to the rule name. The rule name can be changed.  */
  inner class RuleNameHandle internal constructor(
    val ruleName: String,
    val id: Int,
    val origin: RuleNameHandle?,
  ) : Comparable<RuleNameHandle> {

    private var auxiliaryIdGenerator = 1

    fun createAuxiliaryRuleName(ruleType: RuleType): RuleNameHandle {
      if (origin != null) {
        return origin.createAuxiliaryRuleName(ruleType)
      }
      val suffix = "${ruleName}_${auxiliaryIdGenerator++}"
      return createOrThrow(ruleType.addPrefixIfMissing(suffix), this)
    }

    override fun compareTo(other: RuleNameHandle): Int {
      val origin = MoreObjects.firstNonNull(origin, this)
      val otherOrigin = MoreObjects.firstNonNull(other.origin, other)
      val originCmp = Integer.compare(origin.id, otherOrigin.id)
      return if (originCmp != 0) {
        originCmp
      } else {
        Integer.compare(id, other.id)
      }
    }

    override fun toString(): String {
      return MoreObjects.toStringHelper(this).add("id", id).add("name", ruleName).toString()
    }
  }
}
