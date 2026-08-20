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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractDataKind
import org.perses.program.AbstractReductionFile
import org.perses.program.BinaryReductionFile
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.util.transformToImmutableList
import java.nio.file.Path

/**
 * Reduction inputs whose files belong to a programming [LanguageKind] (the common case). Narrows
 * [initiallyDeterminedMainDataKind] to [LanguageKind] so callers can use its code-format machinery
 * without casts.
 *
 * Usable as-is for reducing a set of source files together against a single test: there is no
 * distinguished main file; every source file is mutable. Subclasses add extra structure on top
 * (e.g. a seed/variant file pair).
 */
open class DefaultLanguageOriginalReductionInputs(
  testScript: ScriptFile,
  mutableFiles: ImmutableList<out AbstractReductionFile<*, *>>,
  immutableDependencyFiles: ImmutableList<BinaryReductionFile>,
) : AbstractOriginalReductionInputs(testScript, mutableFiles, immutableDependencyFiles) {
  override val initiallyDeterminedMainDataKind: LanguageKind
    get() = mutableFiles.first().dataKind as LanguageKind

  companion object {
    inline fun create(
      testScriptPath: Path,
      sourceFilePaths: ImmutableList<Path>,
      dependencyFiles: ImmutableList<Path>,
      languageKindComputer: (filePath: Path) -> LanguageKind,
    ): DefaultLanguageOriginalReductionInputs {
      val testScript = ScriptFile(testScriptPath.toAbsolutePath())
      val sourceFiles =
        sourceFilePaths.transformToImmutableList { path ->
          val absPath = path.toAbsolutePath()
          SourceFile(absPath, languageKind = languageKindComputer(absPath))
        }
      return DefaultLanguageOriginalReductionInputs(
        testScript = testScript,
        mutableFiles = sourceFiles,
        immutableDependencyFiles =
          dependencyFiles.transformToImmutableList { path ->
            BinaryReductionFile(path, AbstractDataKind.UnknownDataKind)
          },
      )
    }
  }
}
