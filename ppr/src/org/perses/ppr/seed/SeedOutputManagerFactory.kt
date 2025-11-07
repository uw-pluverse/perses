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
package org.perses.ppr.seed

import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.PersesTokenFactory.AbstractPersesToken
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.util.ListAlignment
import org.perses.util.hashing.EnumShaAlgorithm

class SeedOutputManagerFactory(
  private val reductionInputs: SeedReductionInputs,
  programFormatControl: EnumFormatControl,
  val listAlignment: ListAlignment<AbstractPersesToken>,
  lexerAtnWrapper: LexerAtnWrapper,
  val shaAlgorithmType: EnumShaAlgorithm,
) : AbstractTokenOutputManagerFactory(programFormatControl, lexerAtnWrapper) {
  override fun createManagerFor(
    program: TokenizedProgram,
    format: EnumFormatControl,
  ): AbstractOutputManager =
    OutputManager(
      program,
      PrinterRegistry.getPrinter(format, lexerAtnWrapper),
      listAlignment,
    )

  override fun createManagerFor(program: TokenizedProgram): AbstractOutputManager =
    OutputManager(program, defaultProgramPrinter, listAlignment)

  inner class OutputManager(
    private val seedProgram: TokenizedProgram,
    private val printer: AbstractTokenizedProgramPrinter,
    val listAlignment: ListAlignment<AbstractPersesToken>,
  ) : AbstractOutputManager(reductionInputs, shaAlgorithmType) {
    override fun internalComputeContentForFile(
      origReductionFile: AbstractReductionFile<*, *>,
    ): String =
      when (origReductionFile) {
        reductionInputs.seedFile -> {
          printer.print(seedProgram).sourceCode
        }
        reductionInputs.variantFile -> {
          // compute variant program by applying the pre-computed diff
          // note that variantTokens is List<PersesAntlrToken>
          val seedTokens = seedProgram.tokens.toMutableList()
          val variantTokens = listAlignment.computeRevision(seedTokens.map { it.asAntlrToken() })
          val variantTokenizedProgram = TokenizedProgram(variantTokens, seedProgram.factory)

          // write variant program to given folder
          printer.print(variantTokenizedProgram).sourceCode
        }
        else -> error("unhandled file $origReductionFile")
      }
  }
}
