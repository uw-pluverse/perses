/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

import com.google.common.base.Preconditions
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.File

@RunWith(JUnit4::class)
class ShellTest {

  @Test
  fun lsExists() {
    val normalized = Shell.normalizeAndCheckExecutability("ls")
    assertThat(normalized).isEqualTo("ls")
  }

  @Test
  fun doesNotExist() {
    Assert.assertThrows(IllegalStateException::class.java) {
      Shell.normalizeAndCheckExecutability("this_shell_cmd_does_not_exist")
    }
  }

  @Test
  fun localScript() {
    val tempFile = File.createTempFile("test", "run.sh")
    Preconditions.checkState(tempFile.setExecutable(true))
    tempFile.deleteOnExit()

    val normalized = Shell.normalizeAndCheckExecutability(tempFile.toString())
    assertThat(normalized).isEqualTo(tempFile.toString())
  }

  @Test
  fun localRelativeScript() {
    val cmd = "test/org/perses/util/fake_creduce.sh"
    val normalized = Shell.normalizeAndCheckExecutability(cmd)
    assertThat(normalized).contains(cmd)
  }

  @Test
  fun noCaptureOutput() {
    val cmd = "echo 'hello'"
    val cmdOutput = Shell.run(cmd, captureOutput = false, environment = Shell.CURRENT_ENV)
    assertThat(cmdOutput.stdout.hasLines()).isFalse()
    assertThat(cmdOutput.stderr.hasLines()).isFalse()
  }

  @Test
  fun captureOutput() {
    val cmd = "echo 'hello'"
    val cmdOutput = Shell.run(cmd, captureOutput = true, environment = Shell.CURRENT_ENV)
    assertThat(cmdOutput.stdout.hasLines()).isTrue()
    assertThat(cmdOutput.stderr.hasLines()).isFalse()
  }

  @Test
  fun testSettingEnvironmentVariable() {
    val script = File.createTempFile("temp", "test_script.sh")
    script.deleteOnExit()
    assertThat(script.setExecutable(true)).isTrue()
    script.writeText(
      """#!/usr/bin/env bash 
      |echo "${"$"}{TEST_ENV_VALUE}"
    """.trimMargin()
    )

    val cmdOutput = Shell.run(
      script.toString(),
      captureOutput = true,
      environment = Shell.createNewEnvironmentVar("TEST_ENV_VALUE", "hello world")
    )
    assertThat(cmdOutput.stdout.combineLines().trim()).isEqualTo("hello world")
  }
}
