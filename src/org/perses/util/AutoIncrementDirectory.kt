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
package org.perses.util

import java.nio.file.Files
import java.nio.file.Path

class AutoIncrementDirectory(
  val defaultDirName: String,
) {

  private val dirNamePrefix = "${defaultDirName}_"
  private val dirNamePattern = Regex("${dirNamePrefix}\\d+")

  fun computeAndCreate(workingDir: Path): Path {
    val dir = getResultDirectoryPath(workingDir)
    check(!Files.exists(dir))
    Files.createDirectory(dir)
    return dir
  }

  private fun getResultDirectoryPath(workingDir: Path): Path {
    val maxId = Files.newDirectoryStream(workingDir).use { directoryStream ->
      directoryStream.asSequence()
        .map { it.fileName.toString().trim() }
        .filter { dirNamePattern.matches(it) }
        .map { it.substring(dirNamePrefix.length) }
        .map { Integer.parseInt(it) }
        .maxOrNull()
    }
    if (maxId != null) {
      return workingDir.resolve("${dirNamePrefix}${maxId + 1}")
    }
    val defaultDir = workingDir.resolve(defaultDirName)
    return if (Files.exists(defaultDir)) {
      workingDir.resolve("${dirNamePrefix}1")
    } else {
      defaultDir
    }.apply {
      check(!Files.exists(this))
    }
  }

  companion object {
    fun computeAndCreate(workingDir: Path, defaultDirName: String) =
      AutoIncrementDirectory(defaultDirName).computeAndCreate(workingDir)
  }
}
