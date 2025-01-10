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

class ReportedBugFolder(root: File) : AbstractFlatCrashFolder(root) {

  fun moveReportedCrashToThis(reportedInstance: CrashInstanceFolder) {
    require(reportedInstance.isReported()) {
      reportedInstance.folder
    }
    val reportedFolder = createBugFolder(reportedInstance)
    check(!reportedFolder.exists()) {
      "Name clash: reported=${reportedInstance.folder}, existing report folder: $reportedFolder"
    }
    reportedInstance.move(reportedFolder)
  }

  fun createBugFolder(reported: CrashInstanceFolder): File {
    val reportedBugId = reported.getReportedBugId()
    val language = reported.info().language
    val folder = File(root, "$language-$reportedBugId")
    if (!folder.exists()) {
      return folder
    }

    val existent = CrashInstanceFolder(folder)
    check(existent.readCrashSignature() != reported.readCrashSignature())
    var i = 0
    while (i < 9999) {
      ++i
      val trial = File(root, "$language-$reportedBugId-$i")
      if (trial.exists()) {
        continue
      }
      return trial
    }
    throw RuntimeException("should not reach here.")
  }

  fun getMasterIfDuplicate(crash: CrashInstanceFolder) =
    getAllCrashInstances()
      .asSequence()
      .filter {
        it.info().bugResolution == CrashInstanceFolder.BugResolution.NEW
      }
      .filter {
        it.readCrashSignature() == crash.readCrashSignature()
      }
      .firstOrNull()
}
