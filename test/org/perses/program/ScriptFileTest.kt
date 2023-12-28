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

import com.google.common.truth.Truth
import org.junit.After
import org.junit.Assert
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.IOException
import java.io.UncheckedIOException
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ScriptFileTest {
  private lateinit var tempFile: Path

  @Before
  @Throws(IOException::class)
  fun setup() {
    tempFile = Files.createTempFile("prefix_for_" + javaClass.simpleName, ".sh")
    tempFile.toFile().deleteOnExit()
  }

  @After
  fun teardown() {
    tempFile.toFile().delete()
  }

  @Test
  fun testEmptyShebangForEmptyFile() {
    write("")
    Assert.assertThrows(java.lang.IllegalStateException::class.java) {
      readShebang()
    }
  }

  @Test
  fun testEmptyShebangForNoShebang() {
    write("#")
    Assert.assertThrows(java.lang.IllegalStateException::class.java) {
      readShebang()
    }
    write("!")
    Assert.assertThrows(java.lang.IllegalStateException::class.java) {
      readShebang()
    }
    write("#\nt")
    Assert.assertThrows(java.lang.IllegalStateException::class.java) {
      readShebang()
    }
    write("#!\nt")
    Assert.assertThrows(java.lang.IllegalStateException::class.java) {
      readShebang()
    }
  }

  @Test
  fun testShebangWithWhitespacesTrimmed() {
    write("#!/usr/bin/env bash      \na")
    Truth.assertThat(readShebang()).isEqualTo("/usr/bin/env bash")
  }

  private fun readShebang(): String {
    return ScriptFile(tempFile).shebang
  }

  private fun write(string: String) {
    try {
      tempFile.writeText(string, StandardCharsets.UTF_8)
    } catch (e: IOException) {
      throw UncheckedIOException(e)
    }
  }
}
