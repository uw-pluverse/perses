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
package org.perses.spartree

import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParseErrorHandling

object SparTreeParserUtility {
  @JvmStatic
  fun buildSparTree(
    sourceCode: String,
    parserFacade: AbstractParserFacade,
    specifiedSparTreeNodeFactory: SparTreeNodeFactory?,
    simplifyTree: Boolean,
    canonicalTokenCountComputer: () -> Int?,
    enableNodeActionSetCache: Boolean = false,
    // With TOLERANT, a syntactically invalid [sourceCode] still yields a spar-tree: unparseable
    // fragments become error-node token leaves and fabricated tokens are dropped by SparTreeBuilder.
    errorMode: ParseErrorHandling,
    // A parse of [sourceCode] already produced by [parserFacade] (e.g. during facade resolution). When
    // given, it is reused instead of parsing again; the caller guarantees it matches [sourceCode].
    precomputedParseTree: ParseTreeWithParser? = null,
  ): SparTree {
    val factoryFacade = specifiedSparTreeNodeFactory?.parserFacade
    if (factoryFacade != null) {
      check(parserFacade.javaClass == factoryFacade.javaClass) {
        "Parser facade class mismatch: expected ${factoryFacade.javaClass.name}, " +
          "got ${parserFacade.javaClass.name}"
      }
    }
    val parseTree =
      precomputedParseTree ?: parserFacade.parseString(sourceCode, errorMode = errorMode)
    val sparTreeNodeFactory =
      specifiedSparTreeNodeFactory
        ?: SparTreeNodeFactory(parserFacade)
    return SparTreeBuilder(
      sparTreeNodeFactory,
      parseTree,
      simplifyTree = simplifyTree,
      canonicalTokenCountComputer = canonicalTokenCountComputer,
      enableNodeActionSetCache = enableNodeActionSetCache,
    ).result
  }
}
