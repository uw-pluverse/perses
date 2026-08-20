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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.perses.util.Util
import org.perses.util.shell.Shells.Companion.SHEBANG_BASH
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

class ProcessUtilTest {
  private val tempDir = Files.createTempDirectory(this::class.qualifiedName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun killAlreadyExitedProcess() {
    val process = ProcessBuilder("true").start()
    process.waitFor()
    assertThat(process.isAlive).isFalse()
    // Should not throw any exception
    ProcessUtil.killProcessAndDescendants(process)
  }

  @Test
  fun killSingleRunningProcess() {
    val process = ProcessBuilder("sleep", "99999").start()
    assertThat(process.isAlive).isTrue()
    ProcessUtil.killProcessAndDescendants(process)
    process.waitFor()
    assertThat(process.isAlive).isFalse()
  }

  @Test
  fun killProcessTree() {
    val grandchildScript =
      tempDir.resolve("grandchild.sh").also {
        it.writeText(
          """
        |$SHEBANG_BASH
        |sleep 999999
          """.trimMargin(),
        )
        Util.setExecutable(it)
      }
    val childScript =
      tempDir.resolve("child.sh").also {
        it.writeText(
          """
        |$SHEBANG_BASH
        |$grandchildScript &
        |sleep 999999
          """.trimMargin(),
        )
        Util.setExecutable(it)
      }
    val mainProcess = ProcessBuilder("bash", childScript.toString()).start()
    assertThat(mainProcess.isAlive).isTrue()

    // Give some time for children to start
    Thread.sleep(1000)

    ProcessUtil.killProcessAndDescendants(mainProcess)
    mainProcess.waitFor()
    assertThat(mainProcess.isAlive).isFalse()

    // Verify descendants are also gone
    val psOutput =
      ProcessBuilder("ps", "aux")
        .start()
        .inputStream
        .bufferedReader()
        .readText()
    assertThat(psOutput).doesNotContain(childScript.toString())
    assertThat(psOutput).doesNotContain(grandchildScript.toString())
  }
}
