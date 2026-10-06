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
 * The FlatTokenList facade over a [RecordedRangeLexer]: a tree with one leaf per recorded token
 * and per gap between ranges, built from the recorded text and the recorded elements alone. Its
 * language is [LanguageRecordedRanges], so a driver built on it prints verbatim.
 *
 * The underlying lexer class the base class asks for is the range lexer itself: this facade never
 * lexes with a language's rules, and nothing of the recorded language enters the evaluation through
 * it. The base class's own instantiation of that class is unreachable, since [createLexer] is the
 * only way a lexer is made here.
 */
class RecordedRangeParserFacade(
  sourceCode: String,
  elements: List<RecordedElement>,
) : FlatTokenListParserFacade(
    underlyingLexerClass = RecordedRangeLexer::class.java,
    language = LanguageRecordedRanges,
  ) {
  /**
   * Where [sourceCode] is cut: at [elements]' ranges, a range of n tokens into n pieces -- its two
   * ends plus n - 1 cuts inside it, placed arbitrarily since the element is only ever deleted whole
   * -- and each gap between ranges one piece. So every range begins and ends at a leaf boundary by
   * construction, and an element's leaf count is its recorded weight.
   *
   * Ranges must not overlap: an element's leaves are its weight, and a token under two elements
   * would be weighed twice. No recorded corpus has an overlap.
   */
  private val cutOffsets: IntArray = cutOffsetsOf(sourceCode, elements)

  override fun createLexer(inputStream: CharStream): Lexer =
    RecordedRangeLexer(inputStream, cutOffsets)

  companion object {
    private fun cutOffsetsOf(
      sourceCode: String,
      elements: List<RecordedElement>,
    ): IntArray {
      val length = sourceCode.codePointCount(0, sourceCode.length)
      val ranges = elements.flatMap { it.ranges }.sortedBy { it.leftInclusive }
      ranges.zipWithNext().forEach { (previous, next) ->
        require(previous.rightExclusive <= next.leftInclusive) {
          "The ranges $previous and $next overlap; an element's leaves are its weight."
        }
      }
      val cuts = sortedSetOf(0, length)
      ranges.forEach { range ->
        require(range.rightExclusive <= length) {
          "The range $range is outside the text, which has $length code point(s)."
        }
        // One leaf per token: the first tokenCount - 1 pieces are one code point each and the last
        // takes the rest of the range, which is always possible because a range holds at least as
        // many code points as tokens. Where the cuts fall does not matter -- the element is only
        // ever deleted whole -- but how many there are does, since the leaf count is the weight.
        for (cut in range.leftInclusive..range.leftInclusive + range.tokenCount - 1) {
          cuts.add(cut)
        }
        cuts.add(range.rightExclusive)
      }
      return cuts.toIntArray()
    }
  }
}
