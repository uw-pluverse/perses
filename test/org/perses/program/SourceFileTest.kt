/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class SourceFileTest {

  val origFile = Paths.get("test_data/delta_1/t.c")
  val tempDir = Files.createTempDirectory(this::class.java.simpleName)

  @After
  fun teardown() {
    MoreFiles.deleteRecursively(tempDir, RecursiveDeleteOption.ALLOW_INSECURE)
  }

  @Test
  fun testSourceFile() {
    val source = SourceFile(origFile, LanguageC)
    assertThat(source.baseName).isEqualTo("t.c")
    assertThat(source.fileWithContent.textualFileContent).isEqualTo(origFile.readText())
    assertThat(source.dataKind).isEqualTo(LanguageC)
    assertThat(source.file.toString()).isEqualTo(origFile.toString())
  }

  @Test
  fun testBinaryFile() {
    val file = FileWithContent(origFile)
    val copy = tempDir.resolve("copy")
    file.writeTo(copy)
    assertThat(copy.readText()).isEqualTo(origFile.readText())
  }
}
