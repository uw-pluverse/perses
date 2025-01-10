/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
import org.apache.commons.exec.ExecuteWatchdog
import org.apache.commons.exec.PumpStreamHandler
import org.perses.util.ktFine
import org.perses.util.ktSevere
import java.io.IOException
import java.io.OutputStream
import java.lang.RuntimeException
import java.nio.file.Path
import java.nio.file.Paths
import java.time.Duration

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

    val SHEBANG_BASH = "#!/usr/bin/env bash"

    @JvmStatic
    val ABSOLUTE_CURRENT_DIR: Path = Paths.get(".").toAbsolutePath()
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun createNewEnvironmentVar(key: String, value: String): ImmutableMap<String, String> =
      ImmutableMap.builder<String, String>().put(key, value).putAll(CURRENT_ENV).build()

    fun runAndGetExitCode(
      cmd: String,
      workingDirectory: Path,
      stdout: OutputStream,
      stderr: OutputStream,
      environment: ImmutableMap<String, String>,
    ): ExitCode {
      val commandline = CommandLine.parse(cmd)
      val pumpStreamHandler = PumpStreamHandler(stdout, stderr)
      val exec = DefaultExecutor.builder().setExecuteStreamHandler(pumpStreamHandler)
        .setWorkingDirectory(workingDirectory.toFile()).get().also {
          it.watchdog = ForciblyProcessDestroyerWatchDog(pumpStreamHandler)
        }
      logger.ktFine { commandline.toString() }

      return try {
        ExitCode(exec.execute(commandline, environment))
      } catch (e: ExecuteException) {
        val exceptionExitCode = e.exitValue
        if (exceptionExitCode == DefaultExecutor.INVALID_EXITVALUE) {
          val exceptionMessage = """The execution of the process '$cmd' is interrupted.
            |cmd stdout: $stdout
            |cmd stderr: $stderr
          """.trimMargin()
          logger.ktFine { exceptionMessage }
          throw RuntimeException(exceptionMessage, e)
        } else {
          ExitCode(exceptionExitCode)
        }
      } catch (e: IOException) {
        val exceptionMessage =
          """Fail to run command in the working directory:'$cmd', dir='$workingDirectory'.
            |$e
          """.trimMargin()
        logger.ktSevere { exceptionMessage + e }
        throw RuntimeException(exceptionMessage, e)
      }
    }
  }

  @Suppress("DEPRECATION")
  class ForciblyProcessDestroyerWatchDog(
    private val pumpStreamHandler: PumpStreamHandler,
  ) : ExecuteWatchdog(ExecuteWatchdog.INFINITE_TIMEOUT) {
    override fun stop() {
      ExecuteWatchdog::class.java.getDeclaredField("process").let {
        it.isAccessible = true
        it.get(this) as Process?
      }?.let { process ->
        if (process.isAlive) {
          /*
           * If this process cannot be destroyed, then forcibly destroy it.
           *
           * Do not try to close the streams of the process, because these streams
           * are used and locked by the StreamPumper.
           *
           * Also, note that BufferedInputStream.read() is blocking and is not interruptable.
           */
          process.descendants().use { stream ->
            stream.forEach { descendant ->
              if ((descendant.isAlive)) {
                descendant.destroy() // Try to shut down the process cleanly first.
                if (descendant.isAlive) {
                  descendant.destroyForcibly()
                }
              }
            }
          }
          process.destroyForcibly()
          // Set up the stop timeout, so that the stream pumping threads can be stopped. Otherwise,
          // all these pumping threads will be blocked on BufferedOutputStream.read()
          pumpStreamHandler.setStopTimeout(Duration.ofMillis(1))
        }
      }
      super.stop()
    }
  }
}
