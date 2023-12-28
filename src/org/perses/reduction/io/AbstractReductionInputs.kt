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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractDataKind
import org.perses.program.AbstractReductionFile
import org.perses.program.ScriptFile
import org.perses.reduction.TestScript
import org.perses.util.toImmutableList
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractReductionInputs<K : AbstractDataKind, S : AbstractReductionInputs<K, S>>(
  val testScript: ScriptFile,
  val mainDataKind: K,
  val rootDirectory: Path,
  val programFiles: ImmutableList<out AbstractReductionFile<*, *>>,
) {

  val absoluteRootDirectory: Path = rootDirectory.toAbsolutePath()
  val orig2relativePathPairs: ImmutableList<OrigAndRelativePathPair>

  init {
    check(programFiles.any { it.dataKind == mainDataKind }) { programFiles }
    orig2relativePathPairs = programFiles.asSequence()
      .map { it to it.file.toAbsolutePath() }
      .onEach { check(it.second.startsWith(absoluteRootDirectory)) }
      .map {
        OrigAndRelativePathPair(it.first, absoluteRootDirectory.relativize(it.second))
      }.toImmutableList()
    check(orig2relativePathPairs.size < 5) {
      "Consider using a hash map for many elements. $orig2relativePathPairs"
    }
    check(
      orig2relativePathPairs.asSequence().map { it.relativePath }.distinct().count() ==
        orig2relativePathPairs.size,
    )
  }

  fun writeTestScriptTo(folder: Path): TestScript {
    require(Files.isDirectory(folder)) {
      "$folder is not a directory"
    }
    val script = testScript
    return TestScript(
      scriptFile = folder.resolve(script.baseName),
      scriptTemplate = script,
    )
  }

  fun computeAbsPathListWrt(newFolder: Path): Iterable<Path> {
    return orig2relativePathPairs
      .asSequence()
      .map { newFolder.resolve(it.relativePath) }
      .asIterable()
  }

  fun computeAbsPathWrt(
    origFile: AbstractReductionFile<*, *>,
    newFolder: Path,
  ): Path {
    return newFolder.resolve(orig2relativePathPairs.first { it.origFile == origFile }.relativePath)
  }

  fun relativePathSequence(): Sequence<Path> {
    return orig2relativePathPairs
      .asSequence()
      .map { it.relativePath }
  }

  fun getRelativePathForOrigFile(origFile: AbstractReductionFile<*, *>): Path {
    return orig2relativePathPairs.single { it.origFile === origFile }.relativePath
  }

  data class OrigAndRelativePathPair(
    val origFile: AbstractReductionFile<*, *>,
    val relativePath: Path,
  )
}
