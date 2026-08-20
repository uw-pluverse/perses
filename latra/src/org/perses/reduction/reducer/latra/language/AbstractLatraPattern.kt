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
package org.perses.reduction.reducer.latra.language

import com.google.common.base.MoreObjects
import com.google.common.base.Objects
import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole.HoleName
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Trivia
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

sealed class AbstractLatraPattern(
  val elements: ImmutableList<AbstractPatternElement>,
) {
  val holes by lazy {
    val builder = ImmutableList.builder<Hole>()
    elements.forEach { element ->
      if (element is Hole) {
        builder.add(element)
      }
    }
    builder.build()
  }

  val nonTriviaElements =
    elements
      .asSequence()
      .filter { it !is Trivia }
      .toImmutableList()

  val originalSourceCode by lazy {
    elements.joinToString(separator = "") { it.originalSourceCode }
  }

  fun replaceHolesWith(holeReplacements: Map<HoleName, String>): String =
    elements.joinToString(separator = "") {
      it.replaceHolesWith(holeReplacements)
    }

  abstract fun replaceHolesWithHoles(holeProvider: (Hole) -> Hole): AbstractLatraPattern

  protected fun replaceHolesInElementsWithHoles(holeProvider: (Hole) -> Hole) =
    elements.transformToImmutableList { element ->
      when (element) {
        is Hole -> holeProvider(element)
        else -> element
      }
    }

  override fun hashCode(): Int = Objects.hashCode(elements, this::class.hashCode())

  override fun equals(other: Any?): Boolean {
    if (other == null) {
      return false
    }
    if (other === this) {
      return true
    }
    if (other !is AbstractLatraPattern) {
      return false
    }
    if (this::class != other::class) {
      return false
    }
    return elements == other.elements
  }

  class MatchingLatraPattern(
    elements: ImmutableList<AbstractPatternElement>,
  ) : AbstractLatraPattern(elements) {
    override fun replaceHolesWithHoles(holeProvider: (Hole) -> Hole): MatchingLatraPattern =
      MatchingLatraPattern(replaceHolesInElementsWithHoles(holeProvider))
  }

  class RewritingLatraPattern(
    elements: ImmutableList<AbstractPatternElement>,
  ) : AbstractLatraPattern(elements) {
    override fun replaceHolesWithHoles(holeProvider: (Hole) -> Hole): RewritingLatraPattern =
      RewritingLatraPattern(replaceHolesInElementsWithHoles(holeProvider))
  }

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .addValue(originalSourceCode)
      .toString()

  fun hasNoHoles(): Boolean = holes.isEmpty()

  companion object {
    val EMPTY_MATCHING = MatchingLatraPattern(ImmutableList.of())
    val EMPTY_REWRITING = RewritingLatraPattern(ImmutableList.of())

    private val holeSyntax = Regex(":\\[\\s*([a-zA-Z_][a-zA-Z0-9_]*)\\s*(\\+?)\\s*]")

    fun findAllHolesIn(patternContent: String): List<MatchResult> =
      holeSyntax.findAll(patternContent).toList()

    fun parseRewritingPattern(
      patternContent: String,
      parserFacade: AbstractParserFacade,
    ): RewritingLatraPattern =
      RewritingLatraPattern(
        PatternElementParser(
          patternContent,
          parserFacade,
          tolerateLexingException = true,
        ).parse(),
      )

    fun parseMatchingPattern(
      patternContent: String,
      parserFacade: AbstractParserFacade,
    ): MatchingLatraPattern =
      MatchingLatraPattern(
        PatternElementParser(
          patternContent,
          parserFacade,
          tolerateLexingException = false,
        ).parse(),
      )
  }
}
