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
package org.perses.util

import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.readText
import kotlin.io.path.writeText

class FileNameContentPair(
  val fileName: String,
  val content: String
) {

  fun writeToDirectory(dir: Path): Path {
    check(Files.isDirectory(dir))
    val path = dir.resolve(fileName)
    path.writeText(content)
    return path
  }

  companion object {

    @JvmStatic
    fun createFromFile(file: Path) =
      FileNameContentPair(
        fileName = file.fileName.toString(),
        content = file.readText()
      )
  }
}
