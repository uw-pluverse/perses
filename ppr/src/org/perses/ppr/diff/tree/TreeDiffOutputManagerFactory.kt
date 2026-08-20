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
package org.perses.ppr.diff.tree

import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.ppr.diff.DiffOriginalReductionInputs
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter
import org.perses.reduction.InputRepresentation
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.util.hashing.EnumShaAlgorithm

/**
 * Writes the seed and variant files for the twin tree-diff reduction.
 *
 * Unlike a regular reduction -- which holds a single tree and pulls every sibling file's content
 * from the supplied content provider (the on-disk result folder) -- ppr keeps both [seedInputRepresentation]
 * and [variantInputRepresentation] live in memory for the whole twin reduction. Each tree is the authoritative
 * source for its own file, so this factory renders both files directly from the trees and ignores
 * the supplied content provider. The seed pass and the variant pass each mutate their own tree
 * while keeping the other tree as fixed context.
 */
class TreeDiffOutputManagerFactory(
  override val originalReductionInputs: DiffOriginalReductionInputs,
  programFormatControl: EnumFormatControl,
  val seedInputRepresentation: InputRepresentation,
  val variantInputRepresentation: InputRepresentation,
  // The mutable file this factory's programs represent. The twin reduction uses one factory per
  // role: one bound to the seed file, one to the variant file.
  private val fileRepresentedByProgram: AbstractReductionFile<*, *>,
  lexerAtnWrapper: LexerAtnWrapper,
  shaAlgorithm: EnumShaAlgorithm,
) : AbstractTokenOutputManagerFactory(
    originalReductionInputs,
    programFormatControl,
    lexerAtnWrapper,
    shaAlgorithm,
  ) {
  override fun createManagerFor(program: TokenizedProgram): AbstractOutputManager =
    OutputManager(program, defaultProgramPrinter)

  // A sibling factory in a different code format: same collaborators (incl. the same represented
  // file), new printer. Enables adaptive code-format selection (see AbstractProgramReductionDriver)
  // for the tree-diff reduction.
  override fun cloneWithCodeFormat(
    codeFormat: EnumFormatControl,
  ): AbstractTokenOutputManagerFactory =
    TreeDiffOutputManagerFactory(
      originalReductionInputs,
      codeFormat,
      seedInputRepresentation,
      variantInputRepresentation,
      fileRepresentedByProgram,
      lexerAtnWrapper,
      shaAlgorithm,
    )

  inner class OutputManager(
    private val program: TokenizedProgram,
    private val printer: AbstractTokenizedProgramPrinter,
  ) : AbstractOutputManager(originalReductionInputs, shaAlgorithm) {
    // The file being reduced is rendered from the live [program]; the other mutable file is rendered
    // from its spar tree's current snapshot. Because the seed pass runs before the variant pass, the
    // seed tree is already reduced by the time the variant pass keeps it as fixed context.
    //
    // Note that both ppr reducers modify seedInputRepresentation and variantInputRepresentation at the same time,
    // but the seed file or the variant file has not been updated yet. So we cannot
    // rely on the otherMutableFileContents for file content. Instead, we need to compute
    // the content from a spartree.
    override fun internalComputeContentForFile(
      origReductionFile: AbstractReductionFile<*, *>,
    ): String =
      when (origReductionFile) {
        fileRepresentedByProgram -> {
          printer.print(program).sourceCode
        }

        originalReductionInputs.seedFile -> {
          printer.print(seedInputRepresentation.tree.programSnapshot.payload).sourceCode
        }

        originalReductionInputs.variantFile -> {
          printer.print(variantInputRepresentation.tree.programSnapshot.payload).sourceCode
        }

        else -> {
          error("unhandled file $origReductionFile")
        }
      }
  }
}
