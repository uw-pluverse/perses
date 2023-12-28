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
package org.perses.program.printer

import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder
import org.perses.util.Util.lazyAssert

abstract class AbstractOrigFormatPrintingVisitor(
  program: TokenizedProgram,
  private val keepBlankLines: Boolean,
  tokenPositionProvider: AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider,
  tokenPlacementListener: AbstractTokenizedProgramPrinter.AbstractTokenPlacementListener?,
) : AbstractOrigFormatVisitor(
  program,
  tokenPositionProvider,
  tokenPlacementListener,
) {

  private var currentLineNumber = 1

  override fun visitLine(line: List<PersesToken>) {
    if (line.isEmpty()) {
      return
    }

    val lineNumber = tokenPositionProvider.getLine(line.first())
    lazyAssert({
      line.asSequence().map {
        tokenPositionProvider.getLine(it)
      }.distinct().count() == 1
    }) {
      line
    }
    val builder = result
    while (lineNumber > currentLineNumber) {
      if (keepBlankLines || (builder.isNotEmpty() && builder.lastChar() != '\n')) {
        builder.append('\n')
      }
      ++currentLineNumber
    }
    printNonEmptyLine(line, builder)
    builder.append('\n')
    ++currentLineNumber
  }

  protected abstract fun printNonEmptyLine(line: List<PersesToken>, builder: FastStringBuilder)

  protected fun printNonEmptyLine(
    startPositionInLine: Int,
    line: List<PersesToken>,
    builder: FastStringBuilder,
  ) {
    var positionInLineCurrent = startPositionInLine
    var previousTokenInLine: PersesToken? = null
    line.forEach { token ->
      var tokenPositionInLine = tokenPositionProvider
        .getCharPositionInLine(token, positionInLineCurrent, null)
      // Only deduce a proper position when the position extracted from token is unavailable
      if (positionInLineCurrent > tokenPositionInLine) {
        tokenPositionInLine = tokenPositionProvider
          .getCharPositionInLine(token, positionInLineCurrent, previousTokenInLine)
      }
      check(positionInLineCurrent <= tokenPositionInLine) {
        """This printing algorithm is designed for program reduction only.
            |token: $token
            |  positionInLineCurrent: $positionInLineCurrent
            |  tokenPositionInLine: $tokenPositionInLine
            |program:
            |${program.tokens.joinToString("\n") { it.text + ":" + it.type }}
        """.trimMargin()
      }
      while (positionInLineCurrent < tokenPositionInLine) {
        ++positionInLineCurrent
        builder.append(' ')
      }
      tokenPlacementListener?.onTokenPlacement(
        token,
        builder.currentLineNo,
        builder.charPositionInLine,
      )
      builder.append(token.text)
      positionInLineCurrent += token.text.length
      previousTokenInLine = token
    }
  }
}
