package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

// TODO: add more tests for the other methods.
@RunWith(JUnit4::class)
class ShellCommandOnPathTest {

  val cmd = "test/org/kira/framework/shell/fake_executable.sh"

  @Test
  fun testCmdOnPath() {
    val cmd = ShellCommandOnPath("gcc")
    assertThat(cmd.fileName).isEqualTo("gcc")
  }

  @Test
  fun testCmdWithRelativePath() {
    val cmd = ShellCommandOnPath(cmd)
    assertThat(cmd.fileName).isEqualTo("fake_executable.sh")
  }
}
