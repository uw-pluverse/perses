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
package org.perses.util

import com.google.common.collect.ImmutableList
import com.google.common.io.Files
import java.io.File
import java.nio.charset.StandardCharsets

data class ShellOutputLines(val lines: ImmutableList<String>) {

  /**
   * Returns true if there is a line contains the string.
   */
  fun anyLineContains(needle: String) = lines.any {
    it.contains(needle)
  }

  fun hasLines() = !lines.isEmpty()

  val combinedLines by lazy {
    StringBuilder(lines.map { it.length + 1 }.sum()).apply {
      lines.forEach{line -> append(line).append('\n')}
    }.toString()
  }

  fun writeToFile(file: File) {
    Files.asCharSink(file, StandardCharsets.UTF_8).writeLines(lines, "\n")
  }

  companion object {
    val EMPTY = ShellOutputLines(ImmutableList.of())
  }
}
