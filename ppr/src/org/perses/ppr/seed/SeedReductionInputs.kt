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
package org.perses.ppr.seed

import com.google.common.collect.ImmutableList
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.io.AbstractSingleFileReductionInputs
import java.nio.file.Path

class SeedReductionInputs(
  testScript: ScriptFile,
  val seedFile: SourceFile,
  val variantFile: SourceFile,
) : AbstractSingleFileReductionInputs<LanguageKind, SourceFile, SeedReductionInputs>(
  testScript,
  mainFile = seedFile,
  otherMutableFiles = ImmutableList.of(variantFile),
  immutableDependencyFiles = ImmutableList.of(),
) {

  init {
    require(seedFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
      "The seed file and the test script should reside in the same folder. " +
        "seedFile:$seedFile, testScript:$testScript"
    }
    require(variantFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
      "The variant file and the test script should reside in the same folder. " +
        "variantFile:$variantFile, testScript:$testScript"
    }
  }

  companion object {
    inline fun create(
      seedPath: Path,
      variantPath: Path,
      testScriptPath: Path,
      languageKindComputer: (Path) -> LanguageKind,
    ): SeedReductionInputs {
      val languageKind = languageKindComputer(seedPath)
      val seedFile = SourceFile(seedPath, languageKind)
      val variantFile = SourceFile(variantPath, languageKind)
      val testScript = ScriptFile(testScriptPath.toAbsolutePath())
      return SeedReductionInputs(
        testScript = testScript,
        seedFile = seedFile,
        variantFile = variantFile,
      )
    }
  }
}
