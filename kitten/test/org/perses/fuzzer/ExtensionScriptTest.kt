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
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ExtensionScriptTest {

  private val tempDir = Files.createTempDirectory(javaClass.simpleName)
  private val scriptResultFolder = tempDir.resolve("script_result_folder")
  private val scriptResultFile = scriptResultFolder.resolve("result.txt")

  private val scriptFile = tempDir.resolve("test.sh").apply {
    this.writeText(
      """#!/usr/bin/env bash
      FILE=${'$'}1
      FOLDER=${'$'}2
      echo "hello" > ${'$'}{FOLDER}/result.txt
      """.trimIndent(),
    )
    Util.setExecutable(this)
  }

  private val failingScriptFile = tempDir.resolve("test-failing.sh").apply {
    this.writeText(
      """#!/usr/bin/env bash
      exit 100
      """.trimIndent(),
    )
    Util.setExecutable(this)
  }

  private val tempFile = tempDir.resolve("temp.txt").apply {
    Files.createFile(this)
  }

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun test_null_extension_script() {
    val script = NullExtensionScript()
    script.run(Paths.get(".")) // Does not crash.
  }

  @Test
  fun test_extension_script_pass() {
    assertThat(Files.isRegularFile(scriptResultFile)).isFalse()
    val script = ExtensionScript(scriptFile, scriptResultFolder)
    script.run(tempFile)
    assertThat(Files.isRegularFile(scriptResultFile)).isTrue()
    assertThat(scriptResultFile.readText(StandardCharsets.UTF_8)).contains("hello")
  }

  @Test
  fun test_extension_script_fail() {
    val script = ExtensionScript(failingScriptFile, scriptResultFolder)
    Assert.assertThrows(Throwable::class.java) {
      script.run(tempFile)
    }
  }
}
