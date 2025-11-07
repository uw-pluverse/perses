/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.reduction.reducer.latra.language

import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.reduction.reducer.latra.LatraEmptyHoleBindingException
import org.perses.reduction.reducer.latra.language.AbstractLatraPattern.MatchingLatraPattern
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.toImmutableList

class FromClause(
  pattern: MatchingLatraPattern,
) : AbstractPatternClause(pattern) {
  init {
    ensureHoleNamesAreUnique()
  }

  fun getHoleDefinition(
    holeName: AbstractPatternElement.Hole.HoleName,
  ): AbstractPatternElement.Hole = pattern.holes.single { it.holeName == holeName }

  private fun ensureHoleNamesAreUnique() {
    val visited = mutableSetOf<AbstractPatternElement.Hole.HoleName>()
    pattern.holes.forEach { hole ->
      check(visited.add(hole.holeName)) {
        "Duplicate hole name $hole in pattern $pattern"
      }
    }
  }

  fun resolveHolesIfPossible(
    holeBindingProvider: (
      AbstractPatternElement.Hole.HoleName,
    ) -> ImmutableList<AbstractSparTreeNode>?,
  ): FromClause {
    val elements =
      pattern.elements
        .flatMap { element ->
          when (element) {
            is AbstractPatternElement.Hole -> {
              val latestBinding =
                holeBindingProvider(element.holeName)
                  ?: return@flatMap sequenceOf(element)
              if (latestBinding.isEmpty()) {
                throw LatraEmptyHoleBindingException(
                  "Any bound hole should be bound to at least spar-tree node.",
                )
              }
              latestBinding
                .asSequence()
                .flatMap {
                  it.leafNodeSequence().map { leaf ->
                    AbstractPatternElement.ConcreteToken(leaf.token.asAntlrToken())
                  }
                }
            }
            else -> sequenceOf(element)
          }
        }.toImmutableList()
    return FromClause(MatchingLatraPattern(elements))
  }

  companion object {
    val EMPTY = FromClause(AbstractLatraPattern.EMPTY_MATCHING)

    fun parse(
      patternContent: String,
      parserFacade: AbstractParserFacade,
    ): FromClause =
      FromClause(AbstractLatraPattern.parseMatchingPattern(patternContent, parserFacade))
  }
}
