/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import java.io.OutputStream
import java.nio.file.Path
import java.nio.file.Paths

abstract class AbstractShell {
  fun run(
    cmd: String,
    captureOutput: Boolean,
    environment: ImmutableMap<String, String>,
  ): CmdOutput {
    return run(cmd, CURRENT_DIR, captureOutput, environment)
  }

  fun run(
    cmd: String,
    workingDirectory: Path,
    captureOutput: Boolean,
    environment: ImmutableMap<String, String>,
  ): CmdOutput {
    val stdout: AbstractShellOutputStream
    val stderr: AbstractShellOutputStream

    if (!captureOutput) {
      stdout = NullShellOutputStream
      stderr = NullShellOutputStream
    } else {
      stdout = ShellOutputStream()
      stderr = ShellOutputStream()
    }
    val exitCode = stdout.use {
      stderr.use {
        runAndGetExitCode(cmd, workingDirectory, stdout, stderr, environment)
      }
    }
    return CmdOutput(exitCode, stdout.toOutputStringList(), stderr.toOutputStringList())
  }

  protected abstract fun runAndGetExitCode(
    cmd: String,
    workingDirectory: Path,
    stdout: OutputStream,
    stderr: OutputStream,
    environment: ImmutableMap<String, String>,
  ): Int

  companion object {
    @JvmStatic
    val singleton: AbstractShell = ShellBasedOnApacheExec()

    @JvmStatic
    val CURRENT_ENV: ImmutableMap<String, String> = ImmutableMap.copyOf(System.getenv())

    @JvmStatic
    val CURRENT_DIR: Path = Paths.get(".")

    @JvmStatic
    val ABSOLUTE_CURRENT_DIR: Path = Paths.get(".").toAbsolutePath()
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun createNewEnvironmentVar(key: String, value: String): ImmutableMap<String, String> =
      ImmutableMap.builder<String, String>()
        .put(key, value).putAll(CURRENT_ENV).build()
  }
}
