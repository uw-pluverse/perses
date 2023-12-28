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
package org.perses.program

import com.google.common.base.MoreObjects
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.readBytes
import kotlin.io.path.writeBytes

class FileWithContent(val file: Path) {
  init {
    require(Files.isRegularFile(file)) {
      "The file should be a regular file $file"
    }
  }

  val baseName: String
    get() = file.fileName.toString()

  val parentFile: Path
    get() = file.parent

  private val binaryContent = file.readBytes()

  val textualFileContent: String by lazy { String(binaryContent, Charsets.UTF_8) }

  fun writeTo(path: Path) {
    path.writeBytes(binaryContent)
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("file", file)
      .toString()
  }
}
