/*
 * Copyright (C) 2018-2024 University of Waterloo.
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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util
import java.nio.file.Files.createFile
import java.nio.file.Files.createTempDirectory
import java.nio.file.Paths
import kotlin.io.path.createSymbolicLinkPointingTo
import kotlin.io.path.deleteRecursively

// TODO: add more tests for the other methods.
@RunWith(JUnit4::class)
class ShellCommandOnPathTest {

  val tempDir = createTempDirectory(javaClass.simpleName)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testCmdOnPath() {
    val cmd = ShellCommandOnPath("gcc")
    assertThat(cmd.fileName).isEqualTo("gcc")
    assertThat(cmd.runWith(ImmutableList.of("--version")).exitCode.intValue).isEqualTo(0)
  }

  @Test
  fun testCmdWithDefaultArguments() {
    val cmd = ShellCommandOnPath("gcc", defaultFlags = ImmutableList.of("--version"))
    val cmdOutput = cmd.runWith()
    assertThat(cmdOutput.exitCode.intValue).isEqualTo(0)
  }

  @Test
  fun testCmdWithRelativePath() {
    val cmd = ShellCommandOnPath("test/org/perses/util/shell/fake_executable.sh")
    assertThat(cmd.fileName).isEqualTo("fake_executable.sh")
    val output = cmd.runWith(ImmutableList.of(), captureOutput = true)
    assertThat(output.exitCode.intValue).isEqualTo(0)
    assertThat(Paths.get(cmd.normalizedCommand).isAbsolute).isTrue()
  }

  @Test
  fun testFieldsOfCmd() {
    val cmd = ShellCommandOnPath("ls")
    assertThat(cmd.fileName).isEqualTo("ls")
    assertThat(Paths.get(cmd.normalizedCommand).isAbsolute).isFalse()
  }

  @Test
  fun testShouldPrintPATHOnFailure() {
    val exception: Exception = Assert.assertThrows(Exception::class.java) {
      ShellCommandOnPath("does-not-exist")
    }
    assertThat(exception.message).contains(System.getenv("PATH"))
  }

  @Test
  fun testPathOnPATHIsARegularFile() {
    val script = tempDir.resolve("temp.sh").apply {
      createFile(this)
    }
    Util.setExecutable(script)
    assertThat(
      ShellCommandOnPath.isCmdOnPATH(
        cmdName = script.fileName.toString(),
        ImmutableList.of(script),
      ),
    ).isTrue()
  }

  @Test
  fun testSymLinkIsRegularFile() {
    val script = tempDir.resolve("temp.sh").apply {
      createFile(this)
    }
    Util.setExecutable(script)

    Paths.get("tempSymLink").createSymbolicLinkPointingTo(script)
    assertThat(
      ShellCommandOnPath.normalizeAndCheckExecutability("tempSymLink"),
    ).isEqualTo("tempSymLink")
  }

  @Test
  fun testSymLinkIsNotRegularFile() {
    Paths.get("temp").createSymbolicLinkPointingTo(Paths.get("tempSymLink.sh"))
    val exception: Exception = Assert.assertThrows(Exception::class.java) {
      ShellCommandOnPath.normalizeAndCheckExecutability("temp")
    }
    assertThat(exception.message).contains(
      "The symbol link temp exists, but the source is not a regular file.",
    )
  }
}
