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
package org.perses.grammar

import org.perses.program.LanguageKind
import org.perses.util.toImmutableList

/**
 * The extFactory is preferred over the builtin one.
 */
class CompositeParserFacadeFactory(
  private val builtinFactory: AbstractParserFacadeFactory,
  private val extFactory: AbstractParserFacadeFactory,
) : AbstractParserFacadeFactory() {

  override fun languageSequence(): Sequence<LanguageKind> {
    return extFactory.languageSequence() + builtinFactory.languageSequence()
  }

  override fun getParserFacadeListForOrNull(languageKind: LanguageKind): ParserFacadeList? {
    val resultCandidates = listOfNotNull(
      extFactory.getParserFacadeListForOrNull(languageKind),
      builtinFactory.getParserFacadeListForOrNull(languageKind),
    ).flatMap { it.sequenceOfCreators() }
    if (resultCandidates.isEmpty()) {
      return null
    }
    return ParserFacadeList(
      defaultParserFacade = resultCandidates.first(),
      otherParserFacades = resultCandidates.drop(1).toImmutableList(),
    )
  }
}
