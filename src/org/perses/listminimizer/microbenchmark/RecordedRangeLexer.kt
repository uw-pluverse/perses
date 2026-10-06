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
import org.antlr.v4.runtime.misc.Interval
import org.perses.grammar.AbstractLexerAdaptor
import org.perses.grammar.flattokenlist.FlatTokenListLexer
import org.perses.grammar.flattokenlist.PnfFlatTokenList

/**
 * Cuts the text at the given offsets and emits each piece as one `TOKEN` of the FlatTokenList
 * grammar: no language, no lexer rules. A recorded program is tokenized this way for evaluation, so
 * the pieces are exactly the recorded ranges and the gaps between them, and the file re-assembles
 * from the pieces' text verbatim.
 *
 * Offsets, like ANTLR's, count code points; that is the unit the recorded ranges are in.
 *
 * @param cutOffsets strictly increasing, starting at 0 and ending at the stream's size
 */
class RecordedRangeLexer(
  inputStream: CharStream,
  private val cutOffsets: IntArray,
) : AbstractLexerAdaptor(inputStream) {
  init {
    require(cutOffsets.isNotEmpty() && cutOffsets.first() == 0) {
      "The cut offsets must start at 0: ${cutOffsets.toList()}"
    }
    require(cutOffsets.last() == inputStream.size()) {
      "The cut offsets must end at the text's length ${inputStream.size()}: ${cutOffsets.toList()}"
    }
    require(cutOffsets.asSequence().zipWithNext().all { (a, b) -> a < b }) {
      "The cut offsets must be strictly increasing: ${cutOffsets.toList()}"
    }
  }

  override fun computeAllTokens(): ImmutableList<Token> {
    val stream = inputStream
    val text = if (stream.size() == 0) "" else stream.getText(Interval.of(0, stream.size() - 1))
    val builder = ImmutableList.builder<Token>()
    var line = 1
    var column = 0
    var codePointIndex = 0
    var textIndex = 0
    for (pieceIndex in 0 until cutOffsets.size - 1) {
      val start = cutOffsets[pieceIndex]
      val end = cutOffsets[pieceIndex + 1]
      val pieceLine = line
      val pieceColumn = column
      val pieceStartInText = textIndex
      while (codePointIndex < end) {
        val codePoint = text.codePointAt(textIndex)
        if (codePoint == '\n'.code) {
          ++line
          column = 0
        } else {
          ++column
        }
        textIndex += Character.charCount(codePoint)
        ++codePointIndex
      }
      builder.add(
        CommonToken(PnfFlatTokenList.TOKEN, text.substring(pieceStartInText, textIndex)).apply {
          this.line = pieceLine
          charPositionInLine = pieceColumn
          startIndex = start
          stopIndex = end - 1
        },
      )
    }
    return builder.build()
  }

  companion object {
    /** Required by [AbstractLexerAdaptor]; the grammar is FlatTokenList's, whose wrapper serves. */
    @JvmField
    val LEXER_WRAPPER = FlatTokenListLexer.LEXER_WRAPPER
  }
}
