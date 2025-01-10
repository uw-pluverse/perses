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
package org.perses.fuzzer.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class DeltaFolderTest {

  private val workingDir = Files.createTempDirectory(this::class.java.name)

  @After
  fun teardown() {
    workingDir.deleteRecursively()
  }

  @Test
  fun testDeltaFolderInfo() {
    val info = DeltaFolder.DeltaFolderInfo(
      scriptFileName = "r.sh",
      programFileName = "t.c",
      reducedFileName = "reduced.c",
      buggyCompilerVersionFileName = "compiler_version.txt",
    )

    val file = workingDir.resolve("info.properties")
    info.saveTo(file.toFile())
    val fileContent = file.readText()
    assertThat(fileContent).contains("script_file")
    assertThat(fileContent).contains("source_file")
    assertThat(fileContent).contains("reduced_file")
    assertThat(fileContent).contains("buggy_compiler_version_file")
    val other = DeltaFolder.DeltaFolderInfo.readFrom(file.toFile())
    assertThat(info).isEqualTo(other)
  }
}
