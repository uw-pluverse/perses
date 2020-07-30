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

import com.google.common.io.Files
import com.google.common.truth.Truth
import org.junit.After
import org.junit.Assert
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.File
import java.io.IOException
import java.io.UncheckedIOException
import java.nio.charset.StandardCharsets

@RunWith(JUnit4::class)
class ScriptFileTest {
  private var tempFile: File? = null

  @Before
  @Throws(IOException::class)
  fun setup() {
    tempFile = File.createTempFile("prefix_for_" + javaClass.simpleName, ".sh")
    tempFile!!.deleteOnExit()
  }

  @After
  fun teardown() {
    tempFile!!.delete()
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
    return ScriptFile(tempFile!!).shebang
  }

  private fun write(string: String) {
    try {
      Files.asCharSink(tempFile!!, StandardCharsets.UTF_8).write(string)
    } catch (e: IOException) {
      throw UncheckedIOException(e)
    }
  }
}
