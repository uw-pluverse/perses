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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.util.AbstractEditOperation
import org.perses.util.ListAlignment

class ListDiffOutputManagerFactory(
  private val reductionInputs: ListDiffReductionInputs,
  private val seedProgram: TokenizedProgram,
  val originalListAlignment: ListAlignment<PersesToken>,
  val originalDiff: List<AbstractEditOperation<PersesToken>>,
  programFormatControl: EnumFormatControl,
  lexerAtnWrapper: LexerAtnWrapper<out Lexer>,
) : AbstractOutputManagerFactory<
  ImmutableList<AbstractEditOperation<PersesToken>>,
  >() {

  protected val defaultProgramPrinter =
    PrinterRegistry.getPrinter(programFormatControl, lexerAtnWrapper)

  override fun createManagerFor(
    program: ImmutableList<AbstractEditOperation<PersesToken>>,
  ): AbstractOutputManager {
    return OutputManager(program, defaultProgramPrinter, seedProgram)
  }

  inner class OutputManager(
    private val diff: ImmutableList<AbstractEditOperation<PersesToken>>,
    private val printer: AbstractTokenizedProgramPrinter,
    private val seedProgram: TokenizedProgram,
  ) : AbstractOutputManager(reductionInputs) {

    override fun internalComputeContentForFile(
      origReductionFile: AbstractReductionFile<*, *>,
    ): String {
      return when (origReductionFile) {
        reductionInputs.seedFile -> {
          printer.print(seedProgram).sourceCode
        }
        reductionInputs.variantFile -> {
          // only Insert and Replace are considered as diff, Delete is not considered because
          // deletion of Delete is equivalent to inserting new tokens to variant,
          // which violates monotonicity of program size.
          val deletedDiff = originalDiff - diff

          val newListAlignment = removeDeletedOperations(deletedDiff, originalListAlignment)
          val newListAlignmentWithoutReplace = ListAlignment.splitReplace(newListAlignment)

          // compute the variant program
          val variantTokens = newListAlignmentWithoutReplace.computeRevision(seedProgram.tokens)
          val variantTokenizedProgram = TokenizedProgram(variantTokens, seedProgram.factory)

          // write variant program to given folder
          printer.print(variantTokenizedProgram).sourceCode
        }
        else -> error("unhandled file $origReductionFile")
      }
    }

    // remove deleted operations to derive a new listAlignment
    // Note that Replace need to be replaced by Keep
    fun removeDeletedOperations(
      deletedDiff: List<AbstractEditOperation<PersesToken>>,
      originalListAlignment: ListAlignment<PersesToken>,
    ): ListAlignment<PersesToken> {
      val newAlignment = ImmutableList.builder<AbstractEditOperation<PersesToken>>()
      var idx = 0
      for (t in originalListAlignment.alignment) {
        if (idx < deletedDiff.size && t == deletedDiff[idx]) {
          if (t is AbstractEditOperation.Replace) {
            newAlignment.add(AbstractEditOperation.Keep(t.base))
          }
          ++idx
        } else {
          newAlignment.add(t)
        }
      }

      return ListAlignment(newAlignment.build())
    }
  }
}
