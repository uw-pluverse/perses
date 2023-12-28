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
import org.apache.commons.exec.CommandLine
import java.nio.file.Path

abstract class AbstractShellDiscardingOutputPolicy {

  abstract fun runAndGetExitCode(
    cmd: String,
    workingDirectory: Path,
    environment: ImmutableMap<String, String>,
  ): ExitCode

  object ApacheExecShellDiscardingOutputPolicy : AbstractShellDiscardingOutputPolicy() {
    override fun runAndGetExitCode(
      cmd: String,
      workingDirectory: Path,
      environment: ImmutableMap<String, String>,
    ): ExitCode {
      return Shells.runAndGetExitCode(
        cmd,
        workingDirectory,
        stdout = NullShellOutputStream,
        stderr = NullShellOutputStream,
        environment,
      )
    }
  }

  object JDKShellDiscardingOutputPolicy : AbstractShellDiscardingOutputPolicy() {
    override fun runAndGetExitCode(
      cmd: String,
      workingDirectory: Path,
      environment: ImmutableMap<String, String>,
    ): ExitCode {
      val commandLine = CommandLine.parse(cmd).let {
        val builder = ImmutableList.builderWithExpectedSize<String>(1 + it.arguments.size)
        builder.add(it.executable)
        it.arguments.forEach { arg -> builder.add(arg) }
        builder.build()
      }
      val processBuilder = ProcessBuilder(commandLine)
      processBuilder.redirectError(ProcessBuilder.Redirect.DISCARD)
      processBuilder.redirectOutput(ProcessBuilder.Redirect.DISCARD)
      processBuilder.directory(workingDirectory.toFile())
      processBuilder.environment().putAll(environment)
      return ExitCode(processBuilder.start().waitFor())
    }
  }
}
