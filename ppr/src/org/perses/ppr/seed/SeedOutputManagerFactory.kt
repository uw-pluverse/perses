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
package org.perses.ppr.seed
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.ppr.diff.DiffOriginalReductionInputs
import org.perses.program.AbstractPersesToken
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.util.ListAlignment
import org.perses.util.hashing.EnumShaAlgorithm

class SeedOutputManagerFactory(
  override val originalReductionInputs: DiffOriginalReductionInputs,
  programFormatControl: EnumFormatControl,
  val listAlignment: ListAlignment<AbstractPersesToken>,
  lexerAtnWrapper: LexerAtnWrapper,
  shaAlgorithm: EnumShaAlgorithm,
) : AbstractTokenOutputManagerFactory(
    originalReductionInputs,
    programFormatControl,
    lexerAtnWrapper,
    shaAlgorithm,
  ) {
  override fun createManagerFor(program: TokenizedProgram): AbstractOutputManager =
    OutputManager(program, defaultProgramPrinter, listAlignment)

  // A sibling factory in a different code format: same collaborators, new printer. Enables adaptive
  // code-format selection (see AbstractProgramReductionDriver) for the seed reduction.
  override fun cloneWithCodeFormat(
    codeFormat: EnumFormatControl,
  ): AbstractTokenOutputManagerFactory =
    SeedOutputManagerFactory(
      originalReductionInputs,
      codeFormat,
      listAlignment,
      lexerAtnWrapper,
      shaAlgorithm,
    )

  inner class OutputManager(
    private val seedProgram: TokenizedProgram,
    private val printer: AbstractTokenizedProgramPrinter,
    val listAlignment: ListAlignment<AbstractPersesToken>,
  ) : AbstractOutputManager(originalReductionInputs, shaAlgorithm) {
    override fun internalComputeContentForFile(
      origReductionFile: AbstractReductionFile<*, *>,
    ): String =
      when (origReductionFile) {
        originalReductionInputs.seedFile -> {
          printer.print(seedProgram).sourceCode
        }

        originalReductionInputs.variantFile -> {
          // compute variant program by applying the pre-computed diff
          // note that variantTokens is List<AbstractPersesToken.AntlrToken>
          val seedTokens = seedProgram.tokens.toMutableList()
          val variantTokens = listAlignment.computeRevision(seedTokens.map { it.asAntlrToken() })
          val variantTokenizedProgram = TokenizedProgram(variantTokens)

          // write variant program to given folder
          printer.print(variantTokenizedProgram).sourceCode
        }

        else -> {
          error("unhandled file $origReductionFile")
        }
      }
  }
}
