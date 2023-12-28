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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.util.Util
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.absolute
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class SourceFileTest {

  val origFile = Paths.get("test_data/delta_1/t.c")
  val tempDir = Files.createTempDirectory(this::class.java.simpleName)
  val source = SourceFile(origFile, LanguageC)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testSourceFile() {
    assertThat(source.baseName).isEqualTo("t.c")
    assertThat(source.fileWithContent.textualFileContent).isEqualTo(origFile.readText())
    assertThat(source.dataKind).isEqualTo(LanguageC)
    assertThat(source.file.toString()).isEqualTo(origFile.toString())
  }

  @Test
  fun testWriteToDirectory() {
    val dir = tempDir.resolve("testWriteToDirectory")
    Util.ensureDirExists(dir)
    assertThat(Util.isEmptyDirectory(dir)).isTrue()
    val result = source.writeToDirectory(dir)
    assertThat(Util.isEmptyDirectory(dir)).isFalse()
    assertThat(dir.toFile().listFiles()).hasLength(1)
    val file = dir.resolve(source.baseName)
    assertThat(Files.isRegularFile(file)).isTrue()
    assertThat(file.readText()).isEqualTo(source.textualFileContent)
    assertThat(file.absolute()).isEqualTo(result.absolute())
  }

  @Test
  fun testBinaryFile() {
    val file = FileWithContent(origFile)
    val copy = tempDir.resolve("copy")
    file.writeTo(copy)
    assertThat(copy.readText()).isEqualTo(origFile.readText())
  }
}
