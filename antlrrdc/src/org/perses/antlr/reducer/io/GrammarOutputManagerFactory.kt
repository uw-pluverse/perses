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
package org.perses.antlr.reducer.io

import com.google.common.collect.ImmutableList
import org.perses.antlr.AntlrCompiler
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.reducer.codegen.GrammarMainStubFactory
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.SuppliedContentOutputManager
import org.perses.util.AutoDeletableFolder
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Files
import java.nio.file.Path

class GrammarOutputManagerFactory(
  override val originalReductionInputs: SeparateGrammarOriginalReductionInput,
  val startRuleName: String,
  val jarFileName: String,
  val testPrograms: ImmutableList<Path>,
  shaAlgorithm: EnumShaAlgorithm,
) : AbstractOutputManagerFactory<PersesGrammar>(originalReductionInputs, shaAlgorithm) {
  // Grammar reduction reduces only the parser grammar; the lexer (the only other mutable file) is
  // fixed, so its content is captured once here and supplied to every output manager.
  private val otherMutableFileContents =
    originalReductionInputs.mutableFileContentsExcluding(
      fileExcluded = originalReductionInputs.parserFile,
    )

  override fun createManagerFor(program: PersesGrammar): AbstractOutputManager =
    OutputManager(program)

  override fun createOutputManagerForOriginalInput(): AbstractOutputManager {
    val originalProgram =
      PersesAstBuilder.loadGrammarFromString(
        originalReductionInputs.parserFile.textualFileContent,
      )
    return createManagerFor(originalProgram)
  }

  inner class OutputManager(
    program: PersesGrammar,
  ) : SuppliedContentOutputManager(
      originalReductionInputs,
      shaAlgorithm,
      // The parser grammar being reduced is the represented file; the lexer comes from the fixed
      // content captured at construction.
      fileRepresentedByProgram = originalReductionInputs.parserFile,
      otherMutableFileContents = otherMutableFileContents,
      renderFileRepresentedByProgram = { program.sourceCode },
    ) {
    override fun writeMore(folder: ReductionFolder) {
      val parserFile = folder.computeAbsPathForOrigFile(originalReductionInputs.parserFile)
      val lexerFile = folder.computeAbsPathForOrigFile(originalReductionInputs.lexerFile)
      val jarFilePath = folder.path.resolve(jarFileName)
      AutoDeletableFolder(
        folder.path.resolve("temp_antlr_compiler_folder"),
      ).use {
        val compiler =
          AntlrCompiler.createFromFiles(
            parserFile = parserFile,
            lexerFile = lexerFile,
            startRuleName = startRuleName,
            workingDirectory = it.file,
            stubFactory = GrammarMainStubFactory(testPrograms = testPrograms),
            packageName = "org.perses.antlr",
            jarFileCustomizer = {},
          )
        val jarFile = compiler.run()
        jarFile.copyTo(jarFilePath)
      }
      check(Files.isRegularFile(parserFile))
      check(Files.isRegularFile(lexerFile))
      check(Files.isRegularFile(jarFilePath))
    }
  }
}
