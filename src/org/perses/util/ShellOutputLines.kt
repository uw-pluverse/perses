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

data class ShellOutputLines(val content: ImmutableList<String>) {

  /**
   * Returns true if there is a line contains the string.
   */
  fun anyLineContains(needle: String) = content.asSequence().any {
    it.contains(needle)
  }

  fun hasLines() = !content.isEmpty()

  fun combineLines(): String {
    val builder = StringBuilder()
    content.forEach { builder.append(it).append('\n') }
    return builder.toString()
  }

  fun writeToFile(file: File) {
    Files.asCharSink(file, StandardCharsets.UTF_8).writeLines(content, "\n")
  }

  companion object {
    val EMPTY = ShellOutputLines(ImmutableList.of())
  }
}
