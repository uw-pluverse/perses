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
package org.perses.program

import java.io.File

class ScriptFile(file: File) : AbstractSourceFile(file) {
  val shebang = extractShebang(fileContent).trim()

  init {
    check(shebang.isNotBlank()) { "Empty shebang in file $file" }
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
}
