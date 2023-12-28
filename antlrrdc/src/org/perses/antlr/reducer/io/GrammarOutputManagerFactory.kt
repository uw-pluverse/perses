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
package org.perses.antlr.reducer.io

import com.google.common.collect.ImmutableList
import org.perses.antlr.AntlrCompiler
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.reducer.codegen.GrammarMainStubFactory
import org.perses.program.AbstractReductionFile
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.reduction.io.ReductionFolder
import org.perses.util.AutoDeletableFolder
import java.nio.file.Files
import java.nio.file.Path

class GrammarOutputManagerFactory(
  val reductionInputs: SeparateGrammarReductionInput,
  val startRuleName: String,
  val jarFileName: String,
  val testPrograms: ImmutableList<Path>,
) : AbstractOutputManagerFactory<PersesGrammar>() {

  override fun createManagerFor(program: PersesGrammar): AbstractOutputManager {
    return OutputManager(program)
  }

  inner class OutputManager(
    private val program: PersesGrammar,
  ) : AbstractOutputManager(reductionInputs) {

    override fun internalComputeContentForFile(
      origReductionFile: AbstractReductionFile<*, *>,
    ): String {
      return when (origReductionFile) {
        reductionInputs.mainFile -> {
          program.sourceCode
        }
        reductionInputs.lexerFile -> {
          reductionInputs.lexerFile.textualFileContent
        }
        else -> error("unhandled file $origReductionFile")
      }
    }

    override fun writeMore(folder: ReductionFolder) {
      val parserFile = folder.computeAbsPathForOrigFile(reductionInputs.mainFile)
      val lexerFile = folder.computeAbsPathForOrigFile(reductionInputs.lexerFile)
      val jarFilePath = folder.folder.resolve(jarFileName)
      AutoDeletableFolder(
        folder.folder.resolve("temp_antlr_compiler_folder"),
      ).use {
        val compiler = AntlrCompiler.createFromFiles(
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
