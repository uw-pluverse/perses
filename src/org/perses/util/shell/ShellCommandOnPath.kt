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
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.perses.util.toImmutableList
import java.io.File.pathSeparator
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
/**
 * This class represents a command in the shell.
 */
data class ShellCommandOnPath(
  val originalCommand: String,
  val defaultFlags: ImmutableList<String> = ImmutableList.of(),
) {

  val fileName = Paths.get(originalCommand).fileName.toString()

  val normalizedCommand: String = normalizeAndCheckExecutability(originalCommand)

  fun runWith(
    extraArguments: ImmutableList<String> = ImmutableList.of(),
    captureOutput: Boolean = true,
    workingDirectory: Path = Shells.CURRENT_DIR,
    environment: ImmutableMap<String, String> = Shells.CURRENT_ENV,
  ): CmdOutput {
    val cmd = StringBuilder()
    cmd.append(normalizedCommand).append(' ')
    defaultFlags.joinTo(cmd, separator = " ")
    cmd.append(' ')
    extraArguments.joinTo(cmd, separator = " ")
    return Shells.singleton.run(cmd.toString(), workingDirectory, captureOutput, environment)
  }

  fun interface IShellCommandOnPathCreator {
    fun tryCreate(): ShellCommandOnPath?
  }

  companion object {

    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun tryCreating(
      command: String,
      defaultFlags: ImmutableList<String> = ImmutableList.of(),
    ) =
      try {
        ShellCommandOnPath(command, defaultFlags)
      } catch (e: Exception) {
        null
      }

    @JvmStatic
    fun tryCreating(
      command: String,
      vararg defaultFlags: String,
    ) = tryCreating(command, ImmutableList.copyOf(defaultFlags))

    val ELEMENTS_ON_ENV_PATH = System.getenv("PATH")
      .split(pathSeparator.toRegex())
      .toTypedArray()
      .asSequence()
      .map { Paths.get(it) }
      .toImmutableList()

    @JvmStatic
    fun normalizeAndCheckExecutability(cmdName: String): String {
      val cmdPath = Paths.get(cmdName)
      if (cmdPath.isAbsolute) {
        if (Files.isSymbolicLink(cmdPath)) {
          check(Files.isRegularFile(cmdPath)) {
            "The symbol link $cmdName exists, but the source is not a regular file."
          }
        }
        check(Files.isRegularFile(cmdPath)) {
          "The command $cmdName is not a regular file."
        }
        check(Files.isExecutable(cmdPath)) {
          "The command $cmdName is not executable."
        }
        return cmdName
      }
      val pathEnv = System.getenv("PATH")
      if (cmdPath.nameCount == 1 && isCmdOnPATH(cmdName, ELEMENTS_ON_ENV_PATH)) {
        return cmdName
      }
      if (Files.isSymbolicLink(cmdPath)) {
        check(Files.isRegularFile(cmdPath)) {
          "The symbol link $cmdPath exists, but the source is not a regular file."
        }
      }
      check(Files.isRegularFile(cmdPath)) {
        "The command $cmdPath is not a regular file. PATH=$pathEnv"
      }
      check(Files.isExecutable(cmdPath)) {
        "The command $cmdPath is not executable."
      }
      return cmdPath.toAbsolutePath().toString()
    }

    internal fun isCmdOnPATH(cmdName: String, elementsOnEnvPath: ImmutableList<Path>): Boolean {
      return elementsOnEnvPath.any {
        if (Files.isRegularFile(it)) {
          it.endsWith(cmdName)
        } else {
          val fullPath = it.resolve(cmdName)
          // TODO: better way to test whether a file is executable.
          Files.isRegularFile(fullPath) && Files.isExecutable(fullPath)
        }
      }
    }
  }
}
