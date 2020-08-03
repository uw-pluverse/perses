package org.perses.util

import com.google.common.base.Preconditions
import com.google.common.truth.Truth
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.File
import java.lang.IllegalStateException

@RunWith(JUnit4::class)
class ShellTest {
  @Test
  fun lsExists() {
    val normalized = Shell.normalizeAndCheckExecutability("ls")
    Truth.assertThat(normalized).isEqualTo("ls")
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
    Truth.assertThat(normalized).isEqualTo(tempFile.toString())
  }

  @Test
  fun localRelativeScript() {
    val cmd = "test/org/perses/util/fake_creduce.sh"
    val normalized = Shell.normalizeAndCheckExecutability(cmd)
    Truth.assertThat(normalized).contains(cmd)
  }
}
