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

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ShellOutputStreamTest {

  @Test
  fun `new stream should return empty string`() {
    val stream = ShellOutputStream()
    stream.close()
    val content = stream.toOutputStringList().lines
    assertThat(content).isEmpty()
  }

  @Test
  fun `test stream should be closed before used`() {
    Assert.assertThrows(
      IllegalStateException::class.java,
    ) { ShellOutputStream().toOutputStringList() }
  }

  @Test
  fun `test output a string list`() {
    val string =
      """0
                   |1
                   |2
                   |3
                   |4
                   |5
                   |
      """.trimMargin()
    val stream = ShellOutputStream()
    for (c in string) {
      stream.write(c.code)
    }
    stream.close()
    val content = stream.toOutputStringList()
    assertThat(content.combinedLines.trim()).isEqualTo(string.trim())
  }
}
