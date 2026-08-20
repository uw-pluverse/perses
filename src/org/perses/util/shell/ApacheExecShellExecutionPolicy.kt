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
import org.apache.commons.exec.CommandLine
import org.apache.commons.exec.DefaultExecutor
import org.apache.commons.exec.ExecuteException
import org.apache.commons.exec.ExecuteWatchdog
import org.apache.commons.exec.PumpStreamHandler
import org.perses.util.ktFine
import java.io.IOException
import java.io.OutputStream
import java.nio.file.Files
import java.nio.file.Path
import java.time.Duration

object ApacheExecShellExecutionPolicy : AbstractShellExecutionPolicy() {
  override fun runAndGetExitCode(
    cmd: String,
    workingDirectory: Path,
    environment: ImmutableMap<String, String>,
    stdout: OutputStream?,
    stderr: OutputStream?,
  ): ExitCode {
    val finalStdout = stdout ?: NullShellOutputStream
    val finalStderr = stderr ?: NullShellOutputStream
    val commandline = CommandLine.parse(cmd)
    val pumpStreamHandler = PumpStreamHandler(finalStdout, finalStderr)
    val exec =
      DefaultExecutor
        .builder()
        .setExecuteStreamHandler(pumpStreamHandler)
        .setWorkingDirectory(workingDirectory.toFile())
        .get()
        .also {
          it.watchdog = ForciblyProcessDestroyerWatchDog(pumpStreamHandler)
        }
    logger.ktFine { commandline.toString() }

    return try {
      ExitCode(exec.execute(commandline, environment))
    } catch (e: ExecuteException) {
      val exceptionExitCode = e.exitValue
      if (exceptionExitCode == DefaultExecutor.INVALID_EXITVALUE) {
        val exceptionMessage =
          """The execution of the process '$cmd' is interrupted.
          |cmd stdout: $finalStdout
          |cmd stderr: $finalStderr
          """.trimMargin()
        logger.ktFine { exceptionMessage }
        throw RuntimeException(exceptionMessage, e)
      } else {
        ExitCode(exceptionExitCode)
      }
    } catch (e: IOException) {
      if (!Files.isDirectory(workingDirectory)) {
        throw WorkingDirectoryDoesNotExistException(workingDirectory, cmd, e)
      }
      val exceptionMessage =
        """Fail to run command in the working directory:'$cmd', dir='$workingDirectory'.
          |$e
        """.trimMargin()
      throw RuntimeException(exceptionMessage, e)
    }
  }
}

class WorkingDirectoryDoesNotExistException(
  workingDirectory: Path,
  cmd: String,
  cause: Exception,
) : IOException(
    "The working directory for command '$cmd' does not exist: $workingDirectory",
    cause,
  )

@Suppress("DEPRECATION")
class ForciblyProcessDestroyerWatchDog(
  private val pumpStreamHandler: PumpStreamHandler,
) : ExecuteWatchdog(ExecuteWatchdog.INFINITE_TIMEOUT) {
  override fun stop() {
    ExecuteWatchdog::class.java
      .getDeclaredField("process")
      .let {
        it.isAccessible = true
        it.get(this) as Process?
      }?.let { process ->
        if (process.isAlive) {
          ProcessUtil.killProcessAndDescendants(process)
          // Set up the stop timeout, so that the stream pumping threads can be stopped. Otherwise,
          // all these pumping threads will be blocked on BufferedOutputStream.read()
          pumpStreamHandler.setStopTimeout(Duration.ofMillis(1))
        }
      }
    super.stop()
  }
}
