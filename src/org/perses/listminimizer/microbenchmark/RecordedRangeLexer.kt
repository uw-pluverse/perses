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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Token
import org.perses.grammar.AbstractLexerAdaptor
import org.perses.grammar.flattokenlist.FlatTokenListLexer
import org.perses.grammar.flattokenlist.PnfFlatTokenList
import org.perses.util.Interval
import org.antlr.v4.runtime.misc.Interval as AntlrInterval

/**
 * Emits each recorded token span of the text as one `TOKEN` of the FlatTokenList grammar, with
 * the line and column it has in the text: no language, no lexer rules. The text between spans is
 * the printer's spaces and newlines and is dropped; printing each token at its position puts it
 * back, which is why nothing else may lie between spans.
 *
 * Offsets, like ANTLR's, count code points.
 *
 * @param tokenSpans non-empty, ascending and non-overlapping, within the stream, and separated by
 *   spaces and newlines only
 */
class RecordedRangeLexer(
  inputStream: CharStream,
  private val tokenSpans: List<Interval>,
) : AbstractLexerAdaptor(inputStream) {
  init {
    tokenSpans.forEach { span ->
      require(
        span.leftInclusive >= 0 && span.length > 0,
      ) { "A token span must not be empty: $span" }
    }
    tokenSpans.zipWithNext().forEach { (previous, next) ->
      require(previous.rightExclusive <= next.leftInclusive) {
        "The token spans must be ascending and must not overlap: $previous, then $next."
      }
    }
    require(tokenSpans.isEmpty() || tokenSpans.last().rightExclusive <= inputStream.size()) {
      "The last token span ${tokenSpans.last()} ends outside the text, which has " +
        "${inputStream.size()} code point(s)."
    }
  }

  override fun computeAllTokens(): ImmutableList<Token> {
    val stream = inputStream
    val text =
      if (stream.size() ==
        0
      ) {
        ""
      } else {
        stream.getText(AntlrInterval.of(0, stream.size() - 1))
      }
    val builder = ImmutableList.builder<Token>()
    var line = 1
    var column = 0
    var codePointIndex = 0
    var textIndex = 0

    fun advanceTo(
      end: Int,
      isGap: Boolean,
    ) {
      while (codePointIndex < end) {
        val codePoint = text.codePointAt(textIndex)
        require(!isGap || codePoint == ' '.code || codePoint == '\n'.code) {
          "Only spaces and newlines may separate recorded tokens, but code point " +
            "$codePointIndex is '${String(Character.toChars(codePoint))}'."
        }
        if (codePoint == '\n'.code) {
          ++line
          column = 0
        } else {
          ++column
        }
        textIndex += Character.charCount(codePoint)
        ++codePointIndex
      }
    }

    for (span in tokenSpans) {
      advanceTo(span.leftInclusive, isGap = true)
      val tokenLine = line
      val tokenColumn = column
      val tokenStartInText = textIndex
      advanceTo(span.rightExclusive, isGap = false)
      builder.add(
        CommonToken(PnfFlatTokenList.TOKEN, text.substring(tokenStartInText, textIndex)).apply {
          this.line = tokenLine
          charPositionInLine = tokenColumn
          startIndex = span.leftInclusive
          stopIndex = span.rightExclusive - 1
        },
      )
    }
    advanceTo(stream.size(), isGap = true)
    return builder.build()
  }

  companion object {
    /** Required by [AbstractLexerAdaptor]; the grammar is FlatTokenList's, whose wrapper serves. */
    @JvmField
    val LEXER_WRAPPER = FlatTokenListLexer.LEXER_WRAPPER
  }
}
