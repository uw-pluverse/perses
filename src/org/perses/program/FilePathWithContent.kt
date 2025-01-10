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
package org.perses.program

import com.google.common.base.MoreObjects
import org.perses.util.AbstractFileContent.BinaryFileContent
import java.nio.file.Files
import java.nio.file.Path

class FilePathWithContent(val file: Path) {
  init {
    require(Files.isRegularFile(file)) {
      "The file should be a regular file $file"
    }
  }

  val baseName: String
    get() = file.fileName.toString()

  val parentFile: Path
    get() = file.parent

  val binaryContent by lazy {
    BinaryFileContent.fromFile(file)
  }

  val textualFileContent by lazy {
    binaryContent.asTextFileContent.text
  }

  fun writeTo(path: Path) {
    binaryContent.writeToFile(path)
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("file", file)
      .toString()
  }
}
