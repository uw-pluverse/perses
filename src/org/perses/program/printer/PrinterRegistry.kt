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

import com.google.common.annotations.VisibleForTesting
import org.antlr.v4.runtime.Lexer
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram

object PrinterRegistry {

  fun getPrinter(
    format: EnumFormatControl,
    lexerAtnWrapper: LexerAtnWrapper<out Lexer>? = null,
  ): AbstractTokenizedProgramPrinter {
    return if (lexerAtnWrapper != null) {
      getPrinter(
        format,
        AbstractTokenizedProgramPrinter.DeducedPositionProvider(lexerAtnWrapper),
      )
    } else {
      getPrinter(
        format,
        AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider.DefaultProvider,
      )
    }
  }

  @VisibleForTesting
  fun getPrinter(
    format: EnumFormatControl,
    tokenPositionProvider: AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider,
  ): AbstractTokenizedProgramPrinter =
    when (format) {
      EnumFormatControl.SINGLE_TOKEN_PER_LINE -> SingleTokenPerLinePrinter
      EnumFormatControl.COMPACT_ORIG_FORMAT ->
        OrigFormatPrinter.getCompactOrigFormat(tokenPositionProvider)
      EnumFormatControl.ORIG_FORMAT ->
        OrigFormatPrinter.getOrigFormat(tokenPositionProvider)
      EnumFormatControl.PYTHON3_FORMAT ->
        PythonPrinter.getOrigFormat(tokenPositionProvider)
      EnumFormatControl.COMPACT_PYTHON3_FORMAT ->
        PythonPrinter.getCompactOrigFormat(tokenPositionProvider)
    }

  fun printToString(
    program: TokenizedProgram,
    format: EnumFormatControl,
    lexerAtnWrapper: LexerAtnWrapper<out Lexer>? = null,
  ) = getPrinter(format, lexerAtnWrapper).print(program).sourceCode

  fun printToStringInOrigFormat(
    program: TokenizedProgram,
    lexerAtnWrapper: LexerAtnWrapper<out Lexer>? = null,
  ) = printToString(program, EnumFormatControl.ORIG_FORMAT, lexerAtnWrapper)

  fun printToStringInCompactFormat(
    program: TokenizedProgram,
    lexerAtnWrapper: LexerAtnWrapper<out Lexer>? = null,
  ) = printToString(program, EnumFormatControl.COMPACT_ORIG_FORMAT, lexerAtnWrapper)

  fun printToStringInSingleLineFormat(program: TokenizedProgram) =
    printToString(program, EnumFormatControl.SINGLE_TOKEN_PER_LINE)

  fun printToStringInPythonFormat(
    program: TokenizedProgram,
    lexerAtnWrapper: LexerAtnWrapper<out Lexer>? = null,
  ) = printToString(program, EnumFormatControl.PYTHON3_FORMAT, lexerAtnWrapper)
}
