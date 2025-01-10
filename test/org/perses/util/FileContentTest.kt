/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class FileContentTest {

  private val tempDir = Util.createTempDirFor(this::class.java.canonicalName)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testTextFileContent() {
    val text = "Hello, World!"
    val fileContent = AbstractFileContent.TextFileContent(text)
    val filePath = tempDir.resolve("test.txt")
    fileContent.writeToFile(filePath)
    assertThat(fileContent.printableContentIfPossible).isEqualTo(text)
    assertThat(filePath.readText()).isEqualTo(text)
  }

  @Test
  fun testBinaryFileContent() {
    val text = "Hello, World!"
    val filePath = tempDir.resolve("test.bin")
    filePath.writeText(text)

    val fileContent = AbstractFileContent.BinaryFileContent.fromFile(filePath)
    val filePath2 = tempDir.resolve("test2.bin")
    fileContent.writeToFile(filePath2)
    assertThat(filePath.readText()).isEqualTo(filePath2.readText())
    assertThat(filePath.readText()).isEqualTo(text)
    assertThat(fileContent.printableContentIfPossible).startsWith("SHA")
  }
}
