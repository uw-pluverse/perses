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

import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.apache.commons.exec.CommandLine
import org.apache.commons.exec.DefaultExecutor
import org.apache.commons.exec.ExecuteException
import org.apache.commons.exec.PumpStreamHandler
import java.io.IOException
import java.io.OutputStream
import java.nio.file.Path
import java.nio.file.Paths

class Shells(
  private val shellPolicyDiscardingOutput: AbstractShellDiscardingOutputPolicy,
) {
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
    return if (captureOutput) {
      val stdout = ShellOutputStream()
      val stderr = ShellOutputStream()
      val exitCode = stdout.use {
        stderr.use {
          runAndGetExitCode(
            cmd,
            workingDirectory,
            stdout,
            stderr,
            environment,
          )
        }
      }
      CmdOutput(
        exitCode,
        stdout = stdout.toOutputStringList(),
        stderr = stderr.toOutputStringList(),
      )
    } else {
      val exitCode = shellPolicyDiscardingOutput.runAndGetExitCode(
        cmd,
        workingDirectory,
        environment,
      )
      CmdOutput(exitCode, ShellOutputLines.EMPTY, ShellOutputLines.EMPTY)
    }
  }

  companion object {
    @JvmStatic
    val singleton: Shells = Shells(
      AbstractShellDiscardingOutputPolicy.ApacheExecShellDiscardingOutputPolicy,
    )

    @JvmField
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

    fun runAndGetExitCode(
      cmd: String,
      workingDirectory: Path,
      stdout: OutputStream,
      stderr: OutputStream,
      environment: ImmutableMap<String, String>,
    ): ExitCode {
      val commandline = CommandLine.parse(cmd)
      val exec = DefaultExecutor()
      exec.workingDirectory = workingDirectory.toFile()
      val streamHandler = PumpStreamHandler(stdout, stderr)
      exec.streamHandler = streamHandler
      logger.atFine().log("%s", commandline)

      return try {
        ExitCode(exec.execute(commandline, environment))
      } catch (e: ExecuteException) {
        logger.atFine().log("error when running cmd %s", cmd)
        logger.atFine().log("cmd stdout: %s", stdout)
        logger.atFine().log("cmd stderr: %s", stderr)
        ExitCode(e.exitValue)
      } catch (e: IOException) {
        logger.atSevere().withCause(e).log(
          "Fail to run command in the working directory:'%s', dir='%s'.",
          cmd,
          workingDirectory,
        )
        throw e
      }
    }
  }
}
