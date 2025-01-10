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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import org.perses.program.BinaryReductionFile
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.io.AbstractReductionInputs
import java.nio.file.Path

class ListDiffReductionInputs(
  testScript: ScriptFile,
  val seedFile: SourceFile,
  val variantFile: SourceFile,
  immutableDependencyFiles: ImmutableList<BinaryReductionFile>,
) : AbstractReductionInputs<LanguageKind, ListDiffReductionInputs>(
  testScript,
  initiallyDeterminedMainDataKind = seedFile.dataKind,
  rootDirectory = seedFile.parentFile,
  mutableFiles = ImmutableList.of(seedFile, variantFile),
  immutableDependencyFiles = immutableDependencyFiles,
) {

  init {
    require(seedFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
      "The seed file and the test script should reside in the same folder. " +
        "seedFile:$seedFile, testScript:$testScript"
    }
  }
  companion object {
    fun create(
      seedPath: Path,
      variantPath: Path,
      testScriptPath: Path,
      immutableDependencyFiles: ImmutableList<BinaryReductionFile>,
      languageKindComputer: (seedAbsPath: Path) -> LanguageKind,
    ): ListDiffReductionInputs {
      val absoluteSeedFilePath: Path = seedPath.toAbsolutePath()
      val absoluteVariantFilePath: Path = variantPath.toAbsolutePath()
      val languageKind = languageKindComputer(absoluteSeedFilePath)

      val seedFile = SourceFile(absoluteSeedFilePath, languageKind)
      val variantFile = SourceFile(absoluteVariantFilePath, languageKind)
      val testScript = ScriptFile(testScriptPath.toAbsolutePath())

      return ListDiffReductionInputs(
        testScript = testScript,
        seedFile = seedFile,
        variantFile = variantFile,
        immutableDependencyFiles,
      )
    }
  }
}
