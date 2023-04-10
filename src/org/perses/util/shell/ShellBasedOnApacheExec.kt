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
import org.apache.commons.exec.CommandLine
import org.apache.commons.exec.DefaultExecutor
import org.apache.commons.exec.ExecuteException
import org.apache.commons.exec.PumpStreamHandler
import java.io.IOException
import java.io.OutputStream
import java.nio.file.Path

/** Shell to run external commands.  */
class ShellBasedOnApacheExec : AbstractShell() {

  override fun runAndGetExitCode(
    cmd: String,
    workingDirectory: Path,
    stdout: OutputStream,
    stderr: OutputStream,
    environment: ImmutableMap<String, String>,
  ): Int {
    val commandline = CommandLine.parse(cmd)
    val exec = DefaultExecutor()
    exec.workingDirectory = workingDirectory.toFile()
    val streamHandler = PumpStreamHandler(stdout, stderr)
    exec.streamHandler = streamHandler
    logger.atFine().log("%s", commandline)

    return try {
      exec.execute(commandline, environment)
    } catch (e: ExecuteException) {
      logger.atFine().log("error when running cmd %s", cmd)
      logger.atFine().log("cmd stdout: %s", stdout)
      logger.atFine().log("cmd stderr: %s", stderr)
      e.exitValue
    } catch (e: IOException) {
      logger.atSevere().withCause(e).log(
        "Fail to run command in the working directory:'%s', dir='%s'.",
        cmd,
        workingDirectory,
      )
      throw e
    }
  }

  companion object {
    val logger: FluentLogger = FluentLogger.forEnclosingClass()
  }
}
