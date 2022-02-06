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
package org.perses.program

import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.readText
import kotlin.io.path.writeText

abstract class AbstractSourceFile(val file: Path) {
  val fileContent: String

  val baseName: String
    get() = file.fileName.toString()

  val parentFile: Path
    get() = file.parent

  fun writeTo(path: Path) = path.writeText(fileContent)

  init {
    require(Files.isRegularFile(file)) {
      "The file should be a regular file $file"
    }
    fileContent = file.readText()
  }
}
