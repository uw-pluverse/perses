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
package org.perses.program.printer

import org.perses.program.PersesTokenFactory
import org.perses.program.PersesTokenFactory.AbstractPersesToken
import org.perses.program.PersesTokenFactory.PersesAntlrToken
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder

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

  private fun getLineNumber(line: List<AbstractPersesToken>): Int? =
    line.firstOrNull { it is PersesAntlrToken }?.let {
      tokenPositionProvider.getLine(it)
    }

  override fun visitLine(line: List<AbstractPersesToken>) {
    if (line.isEmpty()) {
      return
    }

    val lineNumber: Int? = getLineNumber(line)
    if (lineNumber == null) {
      printNonEmptyLine(line, result)
      ++currentLineNumber
      return
    }
    val builder = result
    while (lineNumber > currentLineNumber) {
      if (keepBlankLines || (builder.isNotEmpty() && builder.lastCharOrThrow() != '\n')) {
        builder.append('\n')
      }
      ++currentLineNumber
    }
    printNonEmptyLine(line, builder)
    builder.append('\n')
    ++currentLineNumber
  }

  protected abstract fun printNonEmptyLine(
    line: List<AbstractPersesToken>,
    builder: FastStringBuilder,
  )

  private fun computeMinSpacingBetweenAntlrTokens(
    line: List<AbstractPersesToken>,
    tokenIndex: Int,
  ): Int {
    if (tokenIndex == 0) {
      return 0
    }
    val token = line[tokenIndex]
    if (token !is PersesAntlrToken) {
      return 0
    }
    val prev = line[tokenIndex - 1]
    if (prev !is PersesAntlrToken) {
      return 0
    }
    val prevEndPosition = prev.position.charPositionInLine + prev.text.length
    return (token.position.charPositionInLine - prevEndPosition).coerceAtLeast(0)
  }

  protected fun printNonEmptyLine(
    startPositionInLine: Int,
    line: List<AbstractPersesToken>,
    builder: FastStringBuilder,
  ) {
    var positionInLineCurrent = startPositionInLine
    var previousTokenInLine: AbstractPersesToken? = null
    for ((tokenIndex, token) in line.withIndex()) {
      if (token is PersesTokenFactory.PersesPlainText) {
        tokenPlacementListener?.onTokenPlacement(
          token,
          builder.currentLineNo,
          builder.charPositionInLine,
        )
        builder.append(token.lexemeText)
        continue
      }
      var computedTokenPositionInLine =
        tokenPositionProvider
          .getCharPositionInLine(token, positionInLineCurrent, null)
      // Only deduce a proper position when the position extracted from token is unavailable
      if (positionInLineCurrent > computedTokenPositionInLine) {
        computedTokenPositionInLine =
          tokenPositionProvider
            .getCharPositionInLine(token, positionInLineCurrent, previousTokenInLine)
      }
      val minimumSpacingBasedOnTokenPositions =
        computeMinSpacingBetweenAntlrTokens(line, tokenIndex)
      computedTokenPositionInLine =
        computedTokenPositionInLine.coerceAtLeast(
          positionInLineCurrent + minimumSpacingBasedOnTokenPositions,
        )
      check(positionInLineCurrent <= computedTokenPositionInLine) {
        """This printing algorithm is designed for program reduction only.
            |token: $token
            |  positionInLineCurrent: $positionInLineCurrent
            |  tokenPositionInLine: $computedTokenPositionInLine
            |program:
            |${program.tokens.joinToString(
          "\n",
        ) { it.lexemeText }}
        """.trimMargin()
      }

      while (positionInLineCurrent < computedTokenPositionInLine) {
        ++positionInLineCurrent
        builder.append(' ')
      }
      tokenPlacementListener?.onTokenPlacement(
        token,
        builder.currentLineNo,
        builder.charPositionInLine,
      )
      builder.append(token.lexemeText)
      positionInLineCurrent += token.lexemeText.length
      previousTokenInLine = token
    }
  }
}
