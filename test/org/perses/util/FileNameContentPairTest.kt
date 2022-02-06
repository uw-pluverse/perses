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
package org.perses.util

import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class FileNameContentPairTest {

  val tempDir = Files.createTempDirectory(javaClass.simpleName)

  @After
  fun teardown() {
    MoreFiles.deleteRecursively(tempDir, RecursiveDeleteOption.ALLOW_INSECURE)
  }

  @Test
  fun testWrite() {
    val pair = FileNameContentPair("a.txt", "b")
    val path = tempDir.resolve("subdir")
    Files.createDirectories(path)
    pair.writeToDirectory(path)
    val file = path.resolve("a.txt")
    val actualContent = file.readText()
    assertThat(actualContent).isEqualTo("b")
  }

  @Test
  fun testRead() {
    val file = tempDir.resolve("a.txt")
    file.writeText("b")
    val pair = FileNameContentPair.createFromFile(file)
    assertThat(pair.fileName).isEqualTo("a.txt")
    assertThat(pair.content).isEqualTo("b")
  }
}
