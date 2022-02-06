/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import org.perses.program.AbstractTokenizedProgramPrinter
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder

abstract class AbstractOrigFormatPrintingVisitor(
  program: TokenizedProgram,
  private val keepBlankLines: Boolean,
  tokenPositionProvider: AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider,
  tokenPlacementListener: AbstractTokenizedProgramPrinter.AbstractTokenPlacementListener?
) : AbstractOrigFormatVisitor(
  program, tokenPositionProvider, tokenPlacementListener
) {

  private var currentLineNumber = 1

  override fun visitLine(line: List<PersesToken>) {
    if (line.isEmpty()) {
      return
    }

    val lineNumber = tokenPositionProvider.getPosition(line.first()).line
    assert(line.asSequence().map { getLine(it) }.distinct().count() == 1) {
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
    builder: FastStringBuilder
  ) {
    var positionInLineCurrent = startPositionInLine
    line.forEach { token ->
      val tokenPositionInLine = getCharPositionInLine(token)
      check(positionInLineCurrent <= tokenPositionInLine) {
        """This printing algorithm is designed for program reduction only.
            |token: $token
            |  position: ${getCharPositionInLine(token)}
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
        builder.charPositionInLine
      )
      builder.append(token.text)
      positionInLineCurrent += token.text.length
    }
  }
}
