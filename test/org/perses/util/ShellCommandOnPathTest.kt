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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

// TODO: add more tests for the other methods.
@RunWith(JUnit4::class)
class ShellCommandOnPathTest {

  @Test
  fun testCmdOnPath() {
    val cmd = ShellCommandOnPath("gcc")
    assertThat(cmd.fileName).isEqualTo("gcc")
    assertThat(cmd.runWith(ImmutableList.of("--version")).exitCode).isEqualTo(0)
  }

  @Test
  fun testCmdWithDefaultArguments() {
    val cmd = ShellCommandOnPath("gcc", defaultFlags = ImmutableList.of("--version"))
    val cmdOutput = cmd.runWith()
    assertThat(cmdOutput.exitCode).isEqualTo(0)
  }

  @Test
  fun testCmdWithRelativePath() {
    val cmd = ShellCommandOnPath("test/org/perses/util/fake_executable.sh")
    assertThat(cmd.fileName).isEqualTo("fake_executable.sh")
    val output = cmd.runWith(ImmutableList.of(), captureOutput = true)
    assertThat(output.exitCode).isEqualTo(0)
  }
}
