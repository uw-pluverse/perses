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

import com.google.common.base.MoreObjects
import com.google.common.base.Preconditions
import com.google.common.flogger.FluentLogger
import org.apache.commons.exec.CommandLine
import org.apache.commons.exec.DefaultExecutor
import org.apache.commons.exec.ExecuteException
import org.apache.commons.exec.PumpStreamHandler
import java.io.ByteArrayOutputStream
import java.io.File
import java.io.IOException
import java.io.OutputStream
import java.io.UncheckedIOException
import java.nio.file.Files
import java.nio.file.Paths
import java.util.Arrays

/** Shell to run external commands.  */
object Shell {

  fun run(cmd: String, captureOutput: Boolean): CmdOutput {
    return run(cmd, CURRENT_DIR, captureOutput)
  }

  fun run(cmd: String?, workingDirectory: File?, captureOutput: Boolean): CmdOutput {
    val stdout = if (captureOutput) ByteArrayOutputStream() else EMPTY_OUTPUT_STREAM
    val stderr = if (captureOutput) ByteArrayOutputStream() else EMPTY_OUTPUT_STREAM
    val commandline = CommandLine.parse(cmd)
    val exec = DefaultExecutor()
    exec.workingDirectory = workingDirectory
    val streamHandler = PumpStreamHandler(stdout, stderr)
    exec.streamHandler = streamHandler
    val exitCode: Int
    exitCode = try {
      logger.atFine().log("%s", commandline)
      exec.execute(commandline)
    } catch (e: ExecuteException) {
      logger.atFine().log("error when running cmd %s", cmd)
      logger.atFine().log("cmd stdout: %s", stdout)
      logger.atFine().log("cmd stderr: %s", stderr)
      e.exitValue
    } catch (e: IOException) {
      logger.atSevere().withCause(e).log(
        "Fail to run command in the working directory:'%s', dir='%s'.", cmd, workingDirectory)
      throw UncheckedIOException(e)
    }
    return CmdOutput(exitCode, stdout.toString(), stderr.toString())
  }

  @JvmStatic
  fun normalizeAndCheckExecutability(cmdName: String?): String? {
    val cmdPath = Paths.get(cmdName)
    if (cmdPath.isAbsolute) {
      Preconditions.checkState(Files.isRegularFile(cmdPath), "The command %s is not a regular file.", cmdName)
      Preconditions.checkState(Files.isExecutable(cmdPath), "The command %s is not executable.", cmdName)
      return cmdName
    }
    if (cmdPath.nameCount == 1) {
      val pathEnv = System.getenv("PATH")
      val foundOnPath = Arrays.stream(pathEnv.split(File.pathSeparator.toRegex()).toTypedArray())
        .anyMatch { it: String? ->
          val fullPath = Paths.get(it).resolve(cmdName)
          Files.isRegularFile(fullPath) && fullPath.toFile().canExecute()
        }
      if (foundOnPath) {
        return cmdName
      }
    }
    Preconditions.checkState(Files.isRegularFile(cmdPath), "The command %s is not a regular file.", cmdPath)
    Preconditions.checkState(Files.isExecutable(cmdPath), "The command %s is not executable.", cmdPath)
    return cmdPath.toAbsolutePath().toString()
  }

  class CmdOutput internal constructor(val exitCode: Int, val stdout: String, val stderr: String) {

    override fun toString(): String {
      return MoreObjects.toStringHelper(this)
        .add("exitCode", exitCode)
        .add("stdout", stdout)
        .add("stderr", stderr)
        .toString()
    }

  }

  private val logger = FluentLogger.forEnclosingClass()

  private val CURRENT_DIR = File(".")

  private val EMPTY_OUTPUT_STREAM: OutputStream = object : OutputStream() {
    override fun write(b: Int) {
      // Discard all the input.
    }

    override fun write(b: ByteArray) {
      // Discard all the input.
    }

    override fun write(b: ByteArray, off: Int, len: Int) {
      // Discard all the input.
    }

    override fun toString(): String {
      return "From a NullOutputStream."
    }
  }

}