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
package org.perses.reduction.io.token

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.AbstractSingleFileReductionInputs
import org.perses.reduction.io.ReductionFolder
import org.perses.util.toImmutableList
import java.nio.file.Path
import kotlin.io.path.readText

class TokenReductionIOManager(
  workingFolder: Path,
  reductionInputs: AbstractSingleFileReductionInputs,
  outputManagerFactory: AbstractTokenOutputManagerFactory,
  outputDirectory: Path?
) : AbstractReductionIOManager<TokenizedProgram, TokenReductionIOManager>(
  workingFolder, reductionInputs, outputManagerFactory, outputDirectory
) {

  private val concreteOutputManagerFactory: AbstractTokenOutputManagerFactory
    get() = outputManagerFactory as AbstractTokenOutputManagerFactory

  fun updateBestResultInOrigFormat(program: TokenizedProgram) {
    concreteOutputManagerFactory.createManagerFor(
      program, reductionInputs.mainLanguage.origCodeFormatControl
    ).write(resultFolder)
  }

  fun readAndTrimAllBestFiles(): ImmutableList<String> {
    return readAndTrimOutputFiles(resultFolder)
  }

  fun readAndTrimOutputFiles(reductionFolder: ReductionFolder): ImmutableList<String> {
    return reductionInputs.orig2relativePathPairs
      .asSequence()
      .map { reductionFolder.folder.resolve(it.relativePath).readText().trim() }
      .toImmutableList().also { check(it.isNotEmpty()) }
  }

  fun readBestMainFile(): String {
    val concreteInputs = getConcreteReductionInputs()
    return resultFolder.folder.resolve(concreteInputs.relativePathForMainFile).readText()
  }

  fun getDefaultProgramFormat() = concreteOutputManagerFactory.defaultProgramFormatControl

  init {
    val languageKind = reductionInputs.mainLanguage
    require(languageKind.isCodeFormatAllowed(getDefaultProgramFormat())) {
      "The language $languageKind requires format sensitivity, " +
        "but the reducer is not told to keep its original format. " +
        "${getDefaultProgramFormat()}"
    }
  }

  override fun getConcreteReductionInputs(): AbstractSingleFileReductionInputs {
    return reductionInputs as AbstractSingleFileReductionInputs
  }
}
