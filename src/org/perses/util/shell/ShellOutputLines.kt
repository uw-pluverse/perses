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
package org.perses.util.shell

import com.google.common.collect.ImmutableList
import org.perses.util.Util.lazyAssert
import java.nio.file.Path
import kotlin.io.path.writeText

data class ShellOutputLines(val lines: ImmutableList<String>) {

  init {
    lazyAssert({ !lines.any { it.isNotEmpty() && it.last() == '\n' } }) { lines.toString() }
  }

  /**
   * Returns true if there is a line contains the string.
   */
  fun anyLineContains(needle: String) = lines.any {
    it.contains(needle)
  }

  fun hasLines() = !lines.isEmpty()

  val combinedLines by lazy {
    StringBuilder(lines.map { it.length + 1 }.sum()).apply {
      lines.forEach { line -> append(line).append('\n') }
    }.toString()
  }

  fun writeToFile(file: Path) {
    file.writeText(combinedLines)
  }

  companion object {
    val EMPTY = ShellOutputLines(ImmutableList.of())
  }
}
