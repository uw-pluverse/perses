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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.TestScript
import org.perses.util.toImmutableList
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractReductionInputs(
  val testScript: ScriptFile,
  val mainLanguage: LanguageKind,
  val rootDirectory: Path,
  files: ImmutableList<SourceFile>
) {

  val absoluteRootDirectory = rootDirectory.toAbsolutePath()
  val orig2relativePathPairs: ImmutableList<OrigAndRelativePathPair>

  init {
    check(files.any { it.languageKind == mainLanguage }) { files }
    orig2relativePathPairs = files.asSequence()
      .map { it to it.file.toAbsolutePath() }
      .onEach { check(it.second.startsWith(absoluteRootDirectory)) }
      .map {
        OrigAndRelativePathPair(it.first, absoluteRootDirectory.relativize(it.second))
      }.toImmutableList()
  }

  fun writeTestScriptTo(folder: Path): TestScript {
    require(Files.isDirectory(folder)) {
      "$folder is not a directory"
    }
    val script = testScript
    return TestScript(
      scriptFile = folder.resolve(script.baseName),
      scriptTemplate = script
    )
  }

  fun computeAbsolutePathListWRT(newFolder: Path): Iterable<Path> {
    return orig2relativePathPairs
      .asSequence()
      .map { newFolder.resolve(it.relativePath) }
      .asIterable()
  }

  fun relativePathSequence(): Sequence<Path> {
    return orig2relativePathPairs
      .asSequence()
      .map { it.relativePath }
  }

  fun getRelativePathForOrigFile(origFile: SourceFile): Path {
    return orig2relativePathPairs.first { it.origFile === origFile }.relativePath
  }

  data class OrigAndRelativePathPair(
    val origFile: SourceFile,
    val relativePath: Path
  )
}
