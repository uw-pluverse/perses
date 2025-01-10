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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractDataKind
import org.perses.program.BinaryReductionFile
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.util.transformToImmutableList
import java.nio.file.Path

class RegularReductionInputs(
  testScript: ScriptFile,
  mainFile: SourceFile,
  dependencyFiles: ImmutableList<BinaryReductionFile>,
) : AbstractSingleFileReductionInputs<LanguageKind, SourceFile, RegularReductionInputs>(
  testScript,
  mainFile,
  otherMutableFiles = ImmutableList.of(),
  immutableDependencyFiles = dependencyFiles,
) {
  init {
    require(mainFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
      "The source file and the test script should reside in the same folder. " +
        "sourceFile:$mainFile, testScript:$testScript"
    }
  }

  companion object {
    inline fun create(
      testScriptPath: Path,
      mainFilePath: Path,
      dependencyFiles: ImmutableList<Path>,
      languageKindComputer: (mainFilePath: Path) -> LanguageKind,
    ): RegularReductionInputs {
      val testScriptAbsPath = testScriptPath.toAbsolutePath()
      val mainFileAbsPath = mainFilePath.toAbsolutePath()
      return RegularReductionInputs(
        testScript = ScriptFile(testScriptAbsPath),
        mainFile = SourceFile(
          mainFileAbsPath,
          languageKind = languageKindComputer(mainFileAbsPath),
        ),
        dependencyFiles = dependencyFiles.transformToImmutableList { path ->
          BinaryReductionFile(path, AbstractDataKind.UnknownDataKind)
        },
      )
    }
  }
}
