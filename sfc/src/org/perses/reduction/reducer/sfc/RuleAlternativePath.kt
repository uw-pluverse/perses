/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.reduction.reducer.sfc

import com.google.common.collect.ImmutableList
import org.perses.antlr.GrammarHierarchy
import org.perses.antlr.RuleHierarchyEntry
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesTerminalAst

/**
 * The alternatives a grammar takes to derive one rule from another: the index of the branch
 * chosen at every alternative block on the way, outermost first.
 *
 * Structure Form Conversion reads such a path as a measure of canonicality (Definition 3.1 of
 * the paper): of two structures usable in the same place, the one whose path is smaller in
 * lexicographic order comes from the alternatives the grammar spells first, and is the more
 * canonical. The path is the *smallest* one, so a rule derivable in several ways is measured by
 * its most canonical derivation rather than by whichever one a search happens to find first.
 */
class RuleAlternativePath(
  private val grammar: GrammarHierarchy,
) {
  /**
   * The smallest path from [fromRule] to [toRule], empty when they are the same rule, and null
   * when the grammar cannot derive one from the other on its own.
   */
  fun findSmallestPath(
    fromRule: RuleHierarchyEntry,
    toRule: RuleHierarchyEntry,
  ): ImmutableList<Int>? = findSmallestPath(fromRule, toRule, HashSet())

  private fun findSmallestPath(
    fromRule: RuleHierarchyEntry,
    toRule: RuleHierarchyEntry,
    rulesOnTheWay: MutableSet<RuleHierarchyEntry>,
  ): ImmutableList<Int>? {
    if (fromRule == toRule) {
      return ImmutableList.of()
    }
    if (!fromRule.isEqualToOrSuperOf(toRule) || !rulesOnTheWay.add(fromRule)) {
      return null
    }
    val path = findSmallestPathInElement(fromRule.ruleDef.body, toRule, rulesOnTheWay)
    rulesOnTheWay.remove(fromRule)
    return path
  }

  private fun findSmallestPathInElement(
    element: AbstractPersesRuleElement,
    toRule: RuleHierarchyEntry,
    rulesOnTheWay: MutableSet<RuleHierarchyEntry>,
  ): ImmutableList<Int>? =
    when (element) {
      is PersesAlternativeBlockAst ->
        element.alternatives
          .asSequence()
          .mapIndexedNotNull { alternativeIndex, alternative ->
            findSmallestPathInElement(alternative, toRule, rulesOnTheWay)
              ?.let { prependIndex(alternativeIndex, it) }
          }.minWithOrNull(LEXICOGRAPHIC_ORDER)
      is PersesRuleReferenceAst ->
        findSmallestPath(
          grammar.getRuleHierarchyEntryWithNameOrThrow(element.ruleNameHandle.ruleName),
          toRule,
          rulesOnTheWay,
        )
      is PersesTerminalAst ->
        if (grammar.getRuleHierarchyEntryOrNull(element.text) == toRule) {
          ImmutableList.of()
        } else {
          null
        }
      else ->
        element
          .childSequence()
          .mapNotNull { findSmallestPathInElement(it, toRule, rulesOnTheWay) }
          .minWithOrNull(LEXICOGRAPHIC_ORDER)
    }

  private fun prependIndex(
    alternativeIndex: Int,
    path: ImmutableList<Int>,
  ): ImmutableList<Int> =
    ImmutableList
      .builder<Int>()
      .add(alternativeIndex)
      .addAll(path)
      .build()

  companion object {
    /**
     * Compares two paths the way a dictionary compares words: the first index they differ at
     * decides, and a path that is a prefix of another comes first.
     */
    val LEXICOGRAPHIC_ORDER: Comparator<List<Int>> =
      Comparator { left, right ->
        val commonLength = minOf(left.size, right.size)
        var index = 0
        while (index < commonLength) {
          val difference = left[index].compareTo(right[index])
          if (difference != 0) {
            return@Comparator difference
          }
          ++index
        }
        left.size.compareTo(right.size)
      }
  }
}
