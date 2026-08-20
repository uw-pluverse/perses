/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
import java.nio.file.Path
import java.nio.file.Paths

class Shells(
  private val policy: AbstractShellExecutionPolicy,
) {
  fun run(
    cmd: String,
    captureOutput: Boolean,
    workingDirectory: Path = CURRENT_DIR,
    environment: ImmutableMap<String, String> = CURRENT_ENV,
  ): CmdOutput {
    val stdout = if (captureOutput) ShellOutputStream() else null
    val stderr = if (captureOutput) ShellOutputStream() else null

    val exitCode =
      try {
        policy.runAndGetExitCode(
          cmd,
          workingDirectory,
          environment,
          stdout,
          stderr,
        )
      } finally {
        stdout?.close()
        stderr?.close()
      }

    return CmdOutput(
      exitCode,
      stdout?.toOutputStringList() ?: ShellOutputLines.EMPTY,
      stderr?.toOutputStringList() ?: ShellOutputLines.EMPTY,
    )
  }

  companion object {
    @JvmStatic
    val apacheExecSingleton: Shells =
      Shells(
        ApacheExecShellExecutionPolicy,
      )

    @JvmStatic
    val jdkBasedSingleton: Shells =
      Shells(
        JDKShellExecutionPolicy,
      )

    @JvmStatic
    val defaultSingleton = jdkBasedSingleton

    @JvmField
    val CURRENT_ENV: ImmutableMap<String, String> = ImmutableMap.copyOf(System.getenv())

    @JvmStatic
    val CURRENT_DIR: Path = Paths.get(".")

    val SHEBANG_BASH = "#!/usr/bin/env bash"

    @JvmStatic
    val ABSOLUTE_CURRENT_DIR: Path = Paths.get(".").toAbsolutePath()
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun createNewEnvironmentVar(
      key: String,
      value: String,
    ): ImmutableMap<String, String> =
      ImmutableMap
        .builder<String, String>()
        .put(key, value)
        .putAll(CURRENT_ENV)
        .build()
  }
}
