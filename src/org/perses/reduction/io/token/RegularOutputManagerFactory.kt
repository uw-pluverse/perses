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
package org.perses.reduction.io.token

import org.antlr.v4.runtime.Lexer
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.AbstractLazySourceCode
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.RegularReductionInputs

class RegularOutputManagerFactory(
  private val reductionInputs: RegularReductionInputs,
  programFormatControl: EnumFormatControl,
  lexerAtnWrapper: LexerAtnWrapper<out Lexer>,
) : AbstractTokenOutputManagerFactory(
  programFormatControl,
  lexerAtnWrapper,
) {

  override fun createManagerFor(program: TokenizedProgram): AbstractOutputManager {
    return OutputManager(program, defaultProgramPrinter)
  }

  override fun createManagerFor(
    program: TokenizedProgram,
    format: EnumFormatControl,
  ): AbstractOutputManager {
    return OutputManager(program, PrinterRegistry.getPrinter(format, lexerAtnWrapper))
  }

  inner class OutputManager(
    private val program: TokenizedProgram,
    private val programPrinter: AbstractTokenizedProgramPrinter,
  ) : AbstractOutputManager(reductionInputs) {

    val sourceCode: AbstractLazySourceCode by lazy {
      programPrinter.print(program)
    }

    override fun internalComputeContentForFile(
      origReductionFile: AbstractReductionFile<*, *>,
    ): String {
      check(origReductionFile === reductionInputs.mainFile)
      return sourceCode.sourceCode
    }
  }
}
