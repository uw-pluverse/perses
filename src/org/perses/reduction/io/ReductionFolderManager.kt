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

import org.perses.util.AtomicSequenceGenerator
import org.perses.util.Util
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

class ReductionFolderManager(
  private val originalReductionInputs: AbstractOriginalReductionInputs,
  val rootFolder: Path,
) {
  private val sequenceGenerator =
    AtomicSequenceGenerator(
      start = 0,
      minLengthForPadding = FOLDER_NAME_MIN_LENGTH,
    )

  fun createNextFolder(
    prefix: String = "",
    postfix: String = "",
  ): ReductionFolder {
    val folderName = prefix + sequenceGenerator.next() + postfix
    return ReductionFolder(originalReductionInputs, createDirectory(folderName))
  }

  fun createTempDirectory(
    prefix: String = "",
    postfix: String = "",
  ): Path {
    val directoryName = prefix + sequenceGenerator.next() + postfix
    return createDirectory(directoryName).also { directory ->
      check(Files.isDirectory(directory)) { directory }
      check(Util.isEmptyDirectory(directory)) { directory }
    }
  }

  private fun createDirectory(directoryName: String): Path {
    check(!isRootFolderDeleted()) { "The root folder has been deleted." }
    val directory = rootFolder.resolve(directoryName)
    check(!Files.exists(directory)) { "The directory already exists. $directory" }
    Files.createDirectory(directory)
    check(Files.isDirectory(directory)) { "Failed to create directory $directory" }
    return directory
  }

  private fun isRootFolderDeleted() = !Files.exists(rootFolder)

  @OptIn(ExperimentalPathApi::class)
  fun deleteRootFolder() {
    if (isRootFolderDeleted()) {
      return
    }
    rootFolder.deleteRecursively()
  }

  companion object {
    const val FOLDER_NAME_MIN_LENGTH = 6
  }

  init {
    require(Files.exists(rootFolder)) {
      "The root folder does not exist: $rootFolder"
    }
    require(Files.isDirectory(rootFolder)) {
      "The root folder is not a directory: $rootFolder"
    }
    require(Util.isEmptyDirectory(rootFolder)) {
      "The root folder should be empty: $rootFolder"
    }
  }
}
