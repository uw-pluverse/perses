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
    val cmdOutput = Shell.run(cmd, captureOutput = false)
    assertThat(cmdOutput.stdout.hasLines()).isFalse()
    assertThat(cmdOutput.stderr.hasLines()).isFalse()
  }

  @Test
  fun captureOutput() {
    val cmd = "echo 'hello'"
    val cmdOutput = Shell.run(cmd, captureOutput = true)
    assertThat(cmdOutput.stdout.hasLines()).isTrue()
    assertThat(cmdOutput.stderr.hasLines()).isFalse()
  }
}
