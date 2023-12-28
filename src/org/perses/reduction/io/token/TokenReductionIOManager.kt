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

import com.google.common.collect.ImmutableList
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.AbstractSingleFileReductionInputs
import org.perses.reduction.io.ReductionFolder
import org.perses.util.FileNameContentPair
import org.perses.util.toImmutableList
import java.nio.file.Path
import kotlin.io.path.readText

class TokenReductionIOManager(
  workingFolder: Path,
  reductionInputs: AbstractSingleFileReductionInputs<LanguageKind, SourceFile, *>,
  outputManagerFactory: AbstractTokenOutputManagerFactory,
  outputDirectory: Path?,
) : AbstractReductionIOManager<TokenizedProgram, LanguageKind, TokenReductionIOManager>(
  workingFolder,
  reductionInputs,
  outputManagerFactory,
  outputDirectory,
) {

  private val concreteOutputManagerFactory: AbstractTokenOutputManagerFactory
    get() = outputManagerFactory as AbstractTokenOutputManagerFactory

  fun updateBestResultInOrigFormat(program: TokenizedProgram) {
    concreteOutputManagerFactory.createManagerFor(
      program,
      reductionInputs.mainDataKind.origCodeFormatControl,
    ).write(resultFolder)
  }

  fun readAndTrimAllBestFiles(): ImmutableList<FileNameContentPair> {
    return readAndTrimOutputFiles(resultFolder)
  }

  fun readAndTrimOutputFiles(reductionFolder: ReductionFolder): ImmutableList<FileNameContentPair> {
    return reductionInputs.orig2relativePathPairs
      .asSequence()
      .map {
        FileNameContentPair.createFromFile(
          file = reductionFolder.folder.resolve(it.relativePath),
        )
      }.toImmutableList().also { check(it.isNotEmpty()) }
  }

  fun readBestMainFile(): String {
    val concreteInputs = getConcreteReductionInputs()
    return resultFolder.folder.resolve(concreteInputs.relativePathForMainFile).readText()
  }

  fun getDefaultProgramFormat() = concreteOutputManagerFactory.defaultProgramFormatControl

  init {
    val languageKind = reductionInputs.mainDataKind
    require(languageKind.isCodeFormatAllowed(getDefaultProgramFormat())) {
      "The language $languageKind requires format sensitivity, " +
        "but the reducer is not told to keep its original format. " +
        "${getDefaultProgramFormat()}"
    }
  }

  override fun getConcreteReductionInputs(): AbstractSingleFileReductionInputs<
    LanguageKind,
    SourceFile,
    *,
    > {
    @Suppress("UNCHECKED_CAST")
    return reductionInputs as AbstractSingleFileReductionInputs<LanguageKind, SourceFile, *>
  }
}
