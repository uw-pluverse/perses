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

import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram

object PrinterRegistry {

  fun getPrinter(format: EnumFormatControl) =
    when (format) {
      EnumFormatControl.SINGLE_TOKEN_PER_LINE -> SingleTokenPerLinePrinter
      EnumFormatControl.COMPACT_ORIG_FORMAT -> OrigFormatPrinter.COMPACT_ORIG_FORMAT
      EnumFormatControl.ORIG_FORMAT -> OrigFormatPrinter.ORIG_FORMAT
      EnumFormatControl.PYTHON3_FORMAT -> PythonPrinter.ORIG_FORMAT
      EnumFormatControl.COMPACT_PYTHON3_FORMAT -> PythonPrinter.COMPACT_ORIG_FORMAT
    }

  fun printToString(program: TokenizedProgram, format: EnumFormatControl) =
    getPrinter(format).print(program).sourceCode

  fun printToStringInOrigFormat(program: TokenizedProgram) =
    printToString(program, EnumFormatControl.ORIG_FORMAT)

  fun printToStringInCompactFormat(program: TokenizedProgram) =
    printToString(program, EnumFormatControl.COMPACT_ORIG_FORMAT)

  fun printToStringInSingleLineFormat(program: TokenizedProgram) =
    printToString(program, EnumFormatControl.SINGLE_TOKEN_PER_LINE)

  fun printToStringInPythonFormat(program: TokenizedProgram) =
    printToString(program, EnumFormatControl.PYTHON3_FORMAT)
}
