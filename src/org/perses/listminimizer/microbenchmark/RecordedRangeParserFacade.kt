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
package org.perses.listminimizer.microbenchmark

import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Lexer
import org.perses.grammar.flattokenlist.FlatTokenListParserFacade

/**
 * The FlatTokenList facade over a [RecordedRangeLexer]: a tree with one leaf per recorded range
 * and per gap between ranges, built from the text alone.
 *
 * The underlying lexer class the base class asks for is the range lexer itself: this facade never
 * lexes with a language's rules, and nothing of the recorded language enters the evaluation through
 * it. The base class's own instantiation of that class is unreachable, since [createLexer] is the
 * only way a lexer is made here.
 */
class RecordedRangeParserFacade(
  private val cutOffsets: IntArray,
) : FlatTokenListParserFacade(underlyingLexerClass = RecordedRangeLexer::class.java) {
  override fun createLexer(inputStream: CharStream): Lexer =
    RecordedRangeLexer(inputStream, cutOffsets)
}
