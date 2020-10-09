package org.perses.util

import com.google.common.flogger.FluentLogger
import java.io.File
import java.nio.file.Files
import java.nio.file.Paths

/**
 * This class represents a command in the shell.
 */
data class ShellCommandOnPath(
  val command: String) {

  private val path = Paths.get(command)

  val fileName = path.fileName.toString()

  init {
    checkCommandExecutability()
  }

  private fun checkCommandExecutability() {
    if (path.isAbsolute) {
      check(Files.isRegularFile(path)) { "The command $command does not exist" }
      check(path.toFile().canExecute()) { "The command $command is not executable" }
      return
    }
    if (path.nameCount != 1) {
      logger.atWarning().log("The command is a relative path, and will NOT be checked: %s", path)
    } else {
      val pathEnv = System.getenv("PATH")
      val result = pathEnv.split(File.pathSeparatorChar).asSequence().any {
        val fullpath = Paths.get(it).resolve(command)
        Files.isRegularFile(fullpath) && fullpath.toFile().canExecute()
      }
      check(result) { "The command $command cannot be found on PATH. $pathEnv" }
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
