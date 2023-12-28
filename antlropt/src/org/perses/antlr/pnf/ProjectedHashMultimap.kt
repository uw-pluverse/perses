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
package org.perses.antlr.pnf

import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

class ProjectedHashMultimap(
  private val grammar: MutableGrammar,
  projectedKeySet: Collection<RuleNameHandle>,
) {

  private val projectedKeySet = LinkedHashSet(projectedKeySet)

  fun ketSet(): Set<RuleNameHandle> {
    return projectedKeySet
  }

  operator fun get(ruleName: RuleNameHandle): MutableAltBlock? {
    return if (!projectedKeySet.contains(ruleName)) {
      null
    } else {
      grammar.getAltBlock(ruleName)
    }
  }

  fun containsKey(ruleName: RuleNameHandle) = projectedKeySet.contains(ruleName)

  fun remove(key: RuleNameHandle, value: AbstractPersesRuleElement): Boolean {
    if (!containsKey(key)) {
      return false
    }
    val result = grammar.getAltBlock(key).removeAlt(value)
    if (!grammar.containsRule(key)) {
      projectedKeySet.remove(key)
    }
    return result
  }

  fun put(key: RuleNameHandle, value: AbstractPersesRuleElement) {
    projectedKeySet.add(key)
    grammar.getAltBlock(key).addIfNotEquivalent(value)
  }
}
