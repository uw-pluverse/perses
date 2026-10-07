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
package org.perses.program.printer
import org.perses.program.AbstractPersesToken
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder

abstract class AbstractOrigFormatPrintingVisitor(
  program: TokenizedProgram,
  private val keepBlankLines: Boolean,
  tokenPositionProvider: AbstractTokenPositionProvider,
  tokenPlacementListener: AbstractTokenPlacementListener?,
) : AbstractOrigFormatVisitor(
    program,
    tokenPositionProvider,
    tokenPlacementListener,
  ) {
  /** The source line the output is on, counting the newlines inside lexed tokens' own text. */
  private var currentLineNumber = 1

  /** How the last printed line ended, which decides how the next line starts. */
  private enum class LastLineEnding {
    /**
     * No line break is owed: nothing printed yet, the line's last lexed token ended in a newline,
     * or the line held plain text only.
     */
    NO_LINE_BREAK_OWED,

    /** The line still owes its line break, emitted before the next line starts or at the end. */
    LINE_BREAK_OWED,

    /**
     * As [LINE_BREAK_OWED], but the line ends after a lexed token that spans lines, such as XML's
     * whitespace between elements or a multi-line string. A next line starting on the source line
     * where that token ended continues the output line from the real column; starting a new one
     * would print the token's newline twice.
     *
     * Only lexed tokens count. Plain-text tokens, such as the line breaks Latra writes into a
     * rewrite, have no source position for a next line to continue from.
     */
    LINE_BREAK_OWED_AFTER_A_LEXED_TOKEN_SPANNING_LINES,
  }

  private var lastLineEnding = LastLineEnding.NO_LINE_BREAK_OWED

  private fun getLineNumber(line: List<AbstractPersesToken>): Int? =
    line.firstOrNull { it is AbstractPersesToken.AntlrToken }?.let {
      tokenPositionProvider.getLine(it)
    }

  private fun emitOwedLineBreak(builder: FastStringBuilder) {
    if (lastLineEnding != LastLineEnding.NO_LINE_BREAK_OWED) {
      builder.append('\n')
      ++currentLineNumber
      lastLineEnding = LastLineEnding.NO_LINE_BREAK_OWED
    }
  }

  override fun visitLine(line: List<AbstractPersesToken>) {
    if (line.isEmpty()) {
      return
    }
    val builder = result
    val lineNumber: Int? = getLineNumber(line)
    if (lineNumber == null) {
      emitOwedLineBreak(builder)
      printNonEmptyLine(line, builder)
      ++currentLineNumber
      return
    }
    if (lastLineEnding == LastLineEnding.LINE_BREAK_OWED_AFTER_A_LEXED_TOKEN_SPANNING_LINES &&
      lineNumber == currentLineNumber
    ) {
      printNonEmptyLine(
        startPositionInLine = builder.charPositionInLine,
        line = line,
        builder = builder,
      )
    } else {
      emitOwedLineBreak(builder)
      while (lineNumber > currentLineNumber) {
        if (keepBlankLines || (builder.isNotEmpty() && builder.lastCharOrThrow() != '\n')) {
          builder.append('\n')
        }
        ++currentLineNumber
      }
      printNonEmptyLine(line, builder)
    }
    val newlinesInLexedTokens =
      line.sumOf { token ->
        if (token is AbstractPersesToken.AntlrToken) token.lexemeText.count { it == '\n' } else 0
      }
    currentLineNumber += newlinesInLexedTokens
    val lastToken: AbstractPersesToken = line.last()
    lastLineEnding =
      when {
        lastToken is AbstractPersesToken.AntlrToken && lastToken.lexemeText.endsWith('\n') ->
          LastLineEnding.NO_LINE_BREAK_OWED
        newlinesInLexedTokens > 0 ->
          LastLineEnding.LINE_BREAK_OWED_AFTER_A_LEXED_TOKEN_SPANNING_LINES
        else -> LastLineEnding.LINE_BREAK_OWED
      }
  }

  override fun onVisitEnd() {
    emitOwedLineBreak(result)
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
    if (token !is AbstractPersesToken.AntlrToken) {
      return 0
    }
    val prev = line[tokenIndex - 1]
    if (prev !is AbstractPersesToken.AntlrToken) {
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
      if (token is AbstractPersesToken.PlainText) {
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
      val text = token.lexemeText
      builder.append(text)
      val lastNewline = text.lastIndexOf('\n')
      positionInLineCurrent =
        if (lastNewline < 0) positionInLineCurrent + text.length else text.length - lastNewline - 1
      previousTokenInLine = token
    }
  }
}
