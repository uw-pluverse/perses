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
package org.perses.fuzzer

import java.io.File

class DuplicateBugFolder(
  root: File,
  val reportedBugFolder: ReportedBugFolder,
) : AbstractFlatCrashFolder(root) {

  init {
    if (!root.exists()) {
      check(root.mkdirs())
    }
    check(root.isDirectory) {
      root
    }
  }

  fun moveToThisFolderIfDuplicate(crash: CrashInstanceFolder): Boolean {
    val master = reportedBugFolder.getMasterIfDuplicate(crash) ?: return false

    val dupFolderName = "dup-${master.getReportedBugId()}-${crash.folder.name}"
    val dupFolder = File(root, dupFolderName)
    check(!dupFolder.exists()) {
      dupFolder
    }
    crash.move(dupFolder)
    return true
  }

  companion object {
    val DUP_FOLDER_PREFIX = "dup-"
    fun computeDuplicateFolderName(masterReportId: Int, crashFolderName: String): String {
      require(!crashFolderName.startsWith(DUP_FOLDER_PREFIX)) {
        crashFolderName
      }
      return "dup-$masterReportId-$crashFolderName"
    }
  }
}
