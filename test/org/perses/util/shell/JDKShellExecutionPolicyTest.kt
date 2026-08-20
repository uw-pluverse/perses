/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.util.shell

import com.google.common.collect.ImmutableMap
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util
import org.perses.util.shell.JDKShellExecutionPolicy
import org.perses.util.shell.Shells.Companion.CURRENT_DIR
import org.perses.util.shell.Shells.Companion.SHEBANG_BASH
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.createFile
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class JDKShellExecutionPolicyTest {
  private val tempDir = Files.createTempDirectory(this::class.qualifiedName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testTrueExitCode() {
    val exitCode =
      JDKShellExecutionPolicy.runAndGetExitCode(
        cmd = "true",
        workingDirectory = CURRENT_DIR,
        environment = Shells.CURRENT_ENV,
        stdout = null,
        stderr = null,
      )
    assertThat(exitCode.isZero()).isTrue()
  }

  @Test
  fun testFalseExitCode() {
    val exitCode =
      JDKShellExecutionPolicy.runAndGetExitCode(
        cmd = "false",
        workingDirectory = CURRENT_DIR,
        environment = Shells.CURRENT_ENV,
        stdout = null,
        stderr = null,
      )
    assertThat(exitCode.isNonZero()).isTrue()
  }

  @Test
  fun testEnvironmentVariables() {
    val script = tempDir.resolve("test_env.sh").createFile()
    Util.setExecutable(script)
    script.writeText(
      """$SHEBANG_BASH
      |if [ "${"$"}{TEST_VAR}" = "expected_value" ]; then
      |  exit 0
      |else
      |  exit 1
      |fi
      """.trimMargin(),
    )

    val environment =
      ImmutableMap
        .builder<String, String>()
        .putAll(Shells.CURRENT_ENV)
        .put("TEST_VAR", "expected_value")
        .build()

    val exitCode =
      JDKShellExecutionPolicy.runAndGetExitCode(
        cmd = script.toString(),
        workingDirectory = CURRENT_DIR,
        environment = environment,
        stdout = null,
        stderr = null,
      )
    assertThat(exitCode.isZero()).isTrue()
  }

  @Test
  fun testWorkingDirectory() {
    val subDir = Files.createDirectory(tempDir.resolve("subdir"))
    val script = tempDir.resolve("test_pwd.sh").createFile()
    Util.setExecutable(script)
    script.writeText(
      """$SHEBANG_BASH
      |if [ "$(pwd)" = "${subDir.toAbsolutePath()}" ]; then
      |  exit 0
      |else
      |  exit 1
      |fi
      """.trimMargin(),
    )

    val exitCode =
      JDKShellExecutionPolicy.runAndGetExitCode(
        cmd = script.toString(),
        workingDirectory = subDir,
        environment = Shells.CURRENT_ENV,
        stdout = null,
        stderr = null,
      )
    assertThat(exitCode.isZero()).isTrue()
  }

  @Test
  fun testClosedStdin() {
    // 'cat' without arguments reads from stdin. If stdin is not closed, it will hang.
    val exitCode =
      JDKShellExecutionPolicy.runAndGetExitCode(
        cmd = "cat",
        workingDirectory = CURRENT_DIR,
        environment = Shells.CURRENT_ENV,
        stdout = null,
        stderr = null,
      )
    // When stdin is closed, 'cat' should finish successfully.
    assertThat(exitCode.isZero()).isTrue()
  }
}
