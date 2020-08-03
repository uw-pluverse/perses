package org.perses.util

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
    Shell.ensureCommandExecutable("ls", File("."))
  }

  @Test
  fun doesNotExist() {
    Assert.assertThrows(IllegalStateException::class.java) {
      Shell.ensureCommandExecutable("this_shell_cmd_does_not_exist", File("."))
    }
  }
}