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
package org.perses.fuzzer.config

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compilers.c.GccCrashDetector
import java.nio.file.Files
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class TestingConfigurationTest {

  private val tempDir = Files.createTempDirectory(javaClass.simpleName)

  val seedFolderA = SeedFolder(
    tempDir.resolve("seed_folder_a").apply {
      Files.createDirectory(this)
    }.toString(),
    ArrayList<String>().apply {
      add(".cc")
      add(".hh")
    },
  )

  val seedFolderB = SeedFolder(
    tempDir.resolve("seed_folder_b").apply {
      Files.createDirectory(this)
    }.toString(),
    ArrayList<String>().apply {
      add(".c")
      add(".h")
    },
  )

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun test() {
    val file = tempDir.resolve("temp.txt")
    val config = TestingConfiguration(
      language = "RUST",
      seedFolders = listOf(seedFolderA, seedFolderB),
      programsUnderTest = listOf(
        ProgramUnderTest(
          command = "gcc",
          flagsToTest = listOf(
            CmdFlags(listOf("-g", "-O3")),
            CmdFlags(listOf("-s")),
          ),
          versionFlags = CmdFlags(listOf("-v")),
          crashDetectorClassName = GccCrashDetector::class.java.canonicalName,
        ),
      ),
    )
    config.writeToYamlFile(file)
    val another = TestingConfiguration.readFrom(file)
    assertThat(config).isEqualTo(another)
    assertThat(config).isNotSameInstanceAs(another)
  }
}
