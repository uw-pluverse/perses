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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.apache.commons.exec.CommandLine
import java.io.OutputStream
import java.nio.file.Files
import java.nio.file.Path

object JDKShellExecutionPolicy : AbstractShellExecutionPolicy() {
  override fun runAndGetExitCode(
    cmd: String,
    workingDirectory: Path,
    environment: ImmutableMap<String, String>,
    stdout: OutputStream?,
    stderr: OutputStream?,
  ): ExitCode {
    val commandLine =
      CommandLine.parse(cmd).let {
        val builder = ImmutableList.builderWithExpectedSize<String>(1 + it.arguments.size)
        builder.add(it.executable)
        it.arguments.forEach { arg -> builder.add(arg) }
        builder.build()
      }

    val stdoutFile =
      if (stdout != null) {
        Files.createTempFile("perses-shell-stdout", ".log")
      } else {
        null
      }

    val stderrFile =
      if (stderr != null) {
        Files.createTempFile("perses-shell-stderr", ".log")
      } else {
        null
      }

    try {
      val processBuilder = ProcessBuilder(commandLine)
      processBuilder.directory(workingDirectory.toFile())
      processBuilder.environment().putAll(environment)

      if (stdoutFile != null) {
        processBuilder.redirectOutput(ProcessBuilder.Redirect.to(stdoutFile.toFile()))
      } else {
        processBuilder.redirectOutput(ProcessBuilder.Redirect.DISCARD)
      }

      if (stderrFile != null) {
        processBuilder.redirectError(ProcessBuilder.Redirect.to(stderrFile.toFile()))
      } else {
        processBuilder.redirectError(ProcessBuilder.Redirect.DISCARD)
      }

      val process = processBuilder.start()
      // Close the stdin, so that the child processes will not hang there waiting for input.
      process.outputStream.close()

      val exitCode =
        try {
          ExitCode(process.waitFor())
        } catch (e: InterruptedException) {
          ProcessUtil.killProcessAndDescendants(process)
          throw e
        }

      // Read results back
      stdoutFile?.let { path ->
        Files.newInputStream(path).use { it.copyTo(stdout!!) }
      }
      stderrFile?.let { path ->
        Files.newInputStream(path).use { it.copyTo(stderr!!) }
      }

      return exitCode
    } finally {
      stdoutFile?.let { Files.deleteIfExists(it) }
      stderrFile?.let { Files.deleteIfExists(it) }
    }
  }
}
