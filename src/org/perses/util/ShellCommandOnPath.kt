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
import java.util.Arrays

/**
 * This class represents a command in the shell.
 */
class ShellCommandOnPath(
  command: String,
  val defaultFlags: ImmutableList<String> = ImmutableList.of()) {

  private val path = Paths.get(command)

  val fileName = path.fileName.toString()

  val command: String

  init {
    this.command = normalizeAndCheckExecutability(command)
  }

  fun runWith(
    extraArguments: ImmutableList<String> = ImmutableList.of(),
    captureOutput: Boolean = true,
    workingDirectory: File = Shell.CURRENT_DIR,
    environment: ImmutableMap<String, String> = Shell.CURRENT_ENV
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

    @JvmStatic
    fun normalizeAndCheckExecutability(cmdName: String): String {
      val cmdPath = Paths.get(cmdName)
      if (cmdPath.isAbsolute) {
        check(Files.isRegularFile(cmdPath)) {
          "The command $cmdName is not a regular file."
        }
        check(Files.isExecutable(cmdPath)) {
          "The command $cmdName is not executable."
        }
        return cmdName
      }
      if (cmdPath.nameCount == 1) {
        val pathEnv = System.getenv("PATH")
        val foundOnPath = Arrays.stream(pathEnv.split(File.pathSeparator.toRegex()).toTypedArray())
          .anyMatch {
            val fullPath = Paths.get(it).resolve(cmdName)
            Files.isRegularFile(fullPath) && fullPath.toFile().canExecute()
          }
        if (foundOnPath) {
          return cmdName
        }
      }
      check(Files.isRegularFile(cmdPath)) {
        "The command $cmdPath is not a regular file."
      }
      check(Files.isExecutable(cmdPath)) {
        "The command $cmdPath is not executable."
      }
      return cmdPath.toAbsolutePath().toString()
    }

  }
}
