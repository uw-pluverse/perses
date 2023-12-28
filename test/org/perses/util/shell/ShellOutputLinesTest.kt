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

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class ShellOutputLinesTest {

  val list: ShellOutputLines

  init {
    val content =
      """0
        |a
        |b
        |c
      """.trimMargin()
    val stream = ShellOutputStream()
    content.forEach { stream.write(it.code) }
    stream.close()
    list = stream.toOutputStringList()
  }

  @Test
  fun test_containsString() {
    Truth.assertThat(list.anyLineContains("a")).isTrue()
    Truth.assertThat(list.anyLineContains("A")).isFalse()
  }

  @Test
  fun test_hasFourLines() {
    Truth.assertThat(list.lines).hasSize(4)
  }

  @Test
  fun test_writeToFile() {
    val file = Files.createTempFile("test_shell_output_lines_test", ".txt")
    list.writeToFile(file)
    val readText = file.readText(StandardCharsets.UTF_8)
    Truth.assertThat(readText.trim()).isEqualTo(list.combinedLines.trim())
  }
}
