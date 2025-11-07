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
package org.perses.ppr.diff.tree

import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.SparTreeWithParsability
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.util.hashing.EnumShaAlgorithm

class TreeDiffOutputManagerFactory(
  private val reductionInputs: TreeDiffReductionInputs,
  programFormatControl: EnumFormatControl,
  val variantSparTree: SparTreeWithParsability,
  lexerAtnWrapper: LexerAtnWrapper,
  private val shaAlgorithm: EnumShaAlgorithm,
) : AbstractTokenOutputManagerFactory(programFormatControl, lexerAtnWrapper) {
  override fun createManagerFor(
    program: TokenizedProgram,
    format: EnumFormatControl,
  ): AbstractOutputManager =
    OutputManager(program, PrinterRegistry.getPrinter(format, lexerAtnWrapper))

  override fun createManagerFor(program: TokenizedProgram): AbstractOutputManager =
    OutputManager(program, defaultProgramPrinter)

  inner class OutputManager(
    private val program: TokenizedProgram,
    private val printer: AbstractTokenizedProgramPrinter,
  ) : AbstractOutputManager(reductionInputs, shaAlgorithm) {
    override fun internalComputeContentForFile(
      origReductionFile: AbstractReductionFile<*, *>,
    ): String =
      when (origReductionFile) {
        reductionInputs.seedFile -> {
          printer.print(program).sourceCode
        }
        reductionInputs.variantFile -> {
          printer.print(variantSparTree.programSnapshot).sourceCode
        }
        else -> error("unhandled file $origReductionFile")
      }
  }
}
