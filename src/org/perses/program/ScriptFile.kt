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
import java.nio.file.Path

class ScriptFile(file: Path) {

  val fileWithContent = FileWithContent(file)

  val shebang = extractShebang(fileWithContent.textualFileContent).trim()

  val file by fileWithContent::file

  val baseName by fileWithContent::baseName

  val fileContent by fileWithContent::textualFileContent

  val parentFile by fileWithContent::parentFile

  init {
    check(shebang.isNotBlank()) { "Empty shebang in file $file" }
  }

  fun writeTo(path: Path) {
    fileWithContent.writeTo(path)
  }

  private fun extractShebang(fileContent: String): String {
    val length = fileContent.length
    if (length <= 2) {
      return ""
    }
    if (fileContent[0] != '#' || fileContent[1] != '!') {
      return ""
    }
    val result = StringBuilder()
    for (i in 2 until length) {
      if (fileContent[i] == '\n') {
        break
      } else {
        result.append(fileContent[i])
      }
    }
    return result.toString()
  }

  override fun toString(): String {
    return MoreObjects.toStringHelper(this).add("file", fileWithContent.file).toString()
  }
}
