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
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.Parameterized
import org.perses.util.DaemonThreadPool
import org.perses.util.FileSystemUtil
import org.perses.util.shell.ShellCommandOnPath.Companion.normalizeAndCheckExecutability
import org.perses.util.shell.Shells.Companion.CURRENT_ENV
import org.perses.util.shell.Shells.Companion.SHEBANG_BASH
import org.perses.util.shell.Shells.Companion.apacheExecSingleton
import org.perses.util.shell.Shells.Companion.createNewEnvironmentVar
import org.perses.util.shell.Shells.Companion.jdkBasedSingleton
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.createFile
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText
import kotlin.time.Duration.Companion.seconds

@RunWith(Parameterized::class)
class ShellTest(
  private val shell: Shells,
) {
  private val tempDir = Files.createTempDirectory(this::class.qualifiedName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun lsExists() {
    val normalized = normalizeAndCheckExecutability("ls")
    assertThat(normalized).isEqualTo("ls")
  }

  @Test
  fun doesNotExist() {
    Assert.assertThrows(IllegalStateException::class.java) {
      normalizeAndCheckExecutability("this_shell_cmd_does_not_exist")
    }
  }

  @Test
  fun localScript() {
    val tempFile = tempDir.resolve("run.sh").createFile()
    FileSystemUtil.setExecutable(tempFile)
    check(Files.isExecutable(tempFile))
    tempFile.toFile().deleteOnExit()

    val normalized = normalizeAndCheckExecutability(tempFile.toString())
    assertThat(normalized).isEqualTo(tempFile.toString())
  }

  @Test
  fun localRelativeScript() {
    val cmd = "test/org/perses/util/shell/fake_creduce.sh"
    val normalized = normalizeAndCheckExecutability(cmd)
    assertThat(normalized).contains(cmd)
  }

  @Test
  fun noCaptureOutput() {
    val cmd = "echo 'hello'"
    val cmdOutput = shell.run(cmd, captureOutput = false, environment = CURRENT_ENV)
    assertThat(cmdOutput.stdout.hasLines()).isFalse()
    assertThat(cmdOutput.stderr.hasLines()).isFalse()
  }

  @Test
  fun captureOutput() {
    val cmd = "echo 'hello'"
    val cmdOutput = shell.run(cmd, captureOutput = true, environment = CURRENT_ENV)
    assertThat(cmdOutput.stdout.hasLines()).isTrue()
    assertThat(cmdOutput.stderr.hasLines()).isFalse()
  }

  @Test
  fun testSettingEnvironmentVariable() {
    val script = tempDir.resolve("test_script.sh").createFile()
    FileSystemUtil.setExecutable(script)
    assertThat(Files.isExecutable(script)).isTrue()

    script.writeText(
      """$SHEBANG_BASH 
      |echo "${"$"}{TEST_ENV_VALUE}"
      """.trimMargin(),
    )

    val cmdOutput =
      shell.run(
        script.toString(),
        captureOutput = true,
        environment = createNewEnvironmentVar("TEST_ENV_VALUE", "hello world"),
      )
    assertThat(cmdOutput.stdout.combinedLines.trim()).isEqualTo("hello world")
  }

  @Test
  fun testRunningProcessShouldBeKilledInsteadOfBeingInterrupted() {
    verifyProcessKilling(captureOutput = true)
  }

  @Test
  fun testRunningProcessShouldBeKilledWhenOutputIsNotCaptured() {
    verifyProcessKilling(captureOutput = false)
  }

  private fun verifyProcessKilling(captureOutput: Boolean) {
    val suffix = if (captureOutput) "" else "_no_capture"
    val markFile = tempDir.resolve("mark_file$suffix.sh")
    assertThat(Files.exists(markFile)).isFalse()

    val scriptBodyForRunningForever =
      """
      |trap "SIGINT ignored" SIGINT
      |trap "SIGTERM ignored" SIGTERM
      |sleep 9999999
      """.trimMargin()

    val grandChildScript =
      tempDir.resolve("run-forever-grandchild$suffix.sh").also {
        it.writeText(
          """
          |$SHEBANG_BASH
          |$scriptBodyForRunningForever
          """.trimMargin(),
        )
        FileSystemUtil.setExecutable(it)
      }
    val childScript =
      tempDir.resolve("run-forever-child$suffix.sh").also {
        it.writeText(
          """
          |$SHEBANG_BASH
          |$grandChildScript & # running in the background.
          |$scriptBodyForRunningForever
          """.trimMargin(),
        )
        FileSystemUtil.setExecutable(it)
      }
    FileSystemUtil.setExecutable(childScript)
    val mainScript =
      tempDir.resolve("run-forever-main$suffix.sh").also {
        it.writeText(
          """
          |$SHEBANG_BASH
          |touch $markFile
          |$childScript & # running in the background
          |$scriptBodyForRunningForever
          """.trimMargin(),
        )
      }
    FileSystemUtil.setExecutable(mainScript)
    val thread =
      DaemonThreadPool.createSingleThreadPool(
        creatorObject = this,
      )
    try {
      val future =
        thread.submit {
          try {
            shell.run(
              cmd = mainScript.toString(),
              captureOutput = captureOutput,
              environment = CURRENT_ENV,
            )
          } catch (e: InterruptedException) {
            e.printStackTrace()
          }
        }
      Thread.sleep(2.seconds.inWholeMilliseconds) // to make sure the mark file is created.
      assertThat(Files.exists(markFile)).isTrue()
      apacheExecSingleton
        .run(
          cmd = "ps aux",
          captureOutput = true,
          environment = CURRENT_ENV,
        ).stdout.combinedLines
        .let {
          assertThat(it).contains(mainScript.toString())
          assertThat(it).contains(childScript.toString())
          assertThat(it).contains(grandChildScript.toString())
        }
      future.cancel(true) // The argument true means to interrupt the thread.
    } finally {
      // Timeout here if the task cannot be cancelled.
      DaemonThreadPool.waitInfinitelyToShutdown(thread)
    }

    apacheExecSingleton
      .run(
        cmd = "ps aux",
        captureOutput = true,
        environment = CURRENT_ENV,
      ).stdout.combinedLines
      .let {
        // Get all the running processes in the system.
        assertThat(it).doesNotContain(mainScript.toString())
        assertThat(it).doesNotContain(childScript.toString())
        assertThat(it).doesNotContain(grandChildScript.toString())
      }
  }

  companion object {
    @JvmStatic
    @Parameterized.Parameters(name = "{0}")
    fun parameters() =
      listOf(
        arrayOf(apacheExecSingleton),
        arrayOf(jdkBasedSingleton),
      )
  }
}
