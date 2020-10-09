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
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import java.io.File
import java.nio.file.Files
import java.nio.file.Paths

/**
 * This class represents a command in the shell.
 */
data class ShellCommandOnPath(
  val command: String,
  val defaultFlags: ImmutableList<String> = ImmutableList.of()) {

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

  fun runWith(
    extraArguments: ImmutableList<String>,
    workingDirectory: File,
    captureOutput: Boolean, environment:
    ImmutableMap<String, String>
  ): Shell.CmdOutput {

    val cmd = StringBuilder()
    cmd.append(command).append(' ')
    defaultFlags.joinTo(cmd, separator = " ")
    cmd.append(' ')
    extraArguments.joinTo(cmd, separator = " ")
    return Shell.run(cmd.toString(), workingDirectory, captureOutput, environment)
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
