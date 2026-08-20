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
package org.perses.reduction.io.token

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.ReductionFolder
import org.perses.util.FileNameContentLinesPair
import org.perses.util.transformToImmutableList
import java.nio.file.Path

/**
 * Precondition: [resultFolder] is already populated with the original inputs (test script, mutable
 * files, dependency files). This manager treats it as the single source of truth -- it reads the
 * initial spar-tree and the sibling-file content from there -- so the caller must populate it before
 * constructing this manager (e.g. via
 * [org.perses.reduction.io.AbstractReductionIOManager.createPopulatedResultFolder]). The `init`
 * block enforces this precondition.
 */
class TokenReductionIOManager(
  workingFolder: Path,
  originalReductionInputs: DefaultLanguageOriginalReductionInputs,
  resultFolder: ReductionFolder,
) : AbstractReductionIOManager<TokenizedProgram, TokenReductionIOManager>(
    workingFolder,
    originalReductionInputs,
    resultFolder,
  ) {
  fun readAndTrimAllBestFiles(): ImmutableList<FileNameContentLinesPair> =
    readAndTrimOutputFiles(resultFolder)

  fun readAndTrimOutputFiles(
    reductionFolder: ReductionFolder,
  ): ImmutableList<FileNameContentLinesPair> =
    reductionFolder
      .sequenceOfLiveMutableFiles()
      .transformToImmutableList { (_, absPath) -> FileNameContentLinesPair.createFromFile(absPath) }

  init {
    // Precondition: this manager reads the program being reduced (and its sibling files) from the
    // result folder, so the caller must populate it first (e.g. via
    // AbstractReductionIOManager.createPopulatedResultFolder). It is built only during the content
    // phase, before the strictly-terminal file-deletion stage, so the folder still holds the full
    // original input set and the populated-everything precondition is the right check. The
    // code-format validation that once lived here moved to AbstractProgramReductionDriver, which now
    // owns the format.
    resultFolder.checkAllInputFilesPopulated()
  }
}
