/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction

import com.google.common.base.Strings
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import org.perses.program.ScriptFile
import org.perses.util.Util
import java.io.File
import java.util.concurrent.atomic.AtomicInteger

class ReductionFolderManager(
  private val rootFolder: File,
  val testScriptTemplate: ScriptFile,
  private val sourceFileName: String
) {
  private val sequenceGenerator = AtomicInteger()

  fun createNextFolder(): ReductionFolder {
    check(!isRootFolderDeleted()) { "The root folder has been deleted." }
    val folderId = sequenceGenerator.getAndIncrement()
    val folderName = Strings.padStart(folderId.toString(), FOLDER_NAME_MIN_LENGTH, '0')
    return createNamedFolder(folderName)
  }

  fun createNamedFolder(folderName: String): ReductionFolder {
    val folder = File(rootFolder, folderName)
    check(!folder.exists()) { "The folder already exists. $folder" }
    check(folder.mkdir()) { "Failed to create folder $folder" }
    return ReductionFolder(folder, testScriptTemplate, sourceFileName)
  }

  private fun isRootFolderDeleted() = !rootFolder.exists()

  fun deleteRootFolder() {
    if (isRootFolderDeleted()) {
      return
    }
    MoreFiles.deleteRecursively(rootFolder.toPath(), RecursiveDeleteOption.ALLOW_INSECURE)
  }

  companion object {
    const val FOLDER_NAME_MIN_LENGTH = 6
  }

  init {
    require(rootFolder.exists()) {
      "The root folder does not exist: $rootFolder"
    }
    require(rootFolder.isDirectory) {
      "The root folder is not a directory: $rootFolder"
    }
    require(Util.isEmptyDirectory(rootFolder.toPath())) {
      "The root folder should be empty: $rootFolder"
    }
  }
}
