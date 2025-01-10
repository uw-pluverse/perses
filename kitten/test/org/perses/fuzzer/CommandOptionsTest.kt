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
package org.perses.fuzzer

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.config.TestingConfiguration
import java.nio.file.Files
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class CommandOptionsTest {

  val tempDir = Files.createTempDirectory(javaClass.simpleName)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testGetFindingFolder() {
    val options = CommandOptions()
    options.compilerFlags.testingConfiguration = TestingConfiguration(
      "RUST",
      seedFolders = listOf(),
      programsUnderTest = listOf(),
    )
    assertThat(options.generalFlags.getFindingFolder().name.lowercase())
      .isEqualTo("default_finding_folder_rust")
    assertThat(options.generalFlags.getTempFolder().name.lowercase())
      .isEqualTo("default_temp_folder_rust")
  }
}
