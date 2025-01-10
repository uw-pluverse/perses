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
package org.perses.fuzzer.compilers

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.shell.Shells
import java.io.File

abstract class AbstractCompilationAction(
  val compilerCommand: ShellCommandOnPath,
  val compileFlags: ImmutableList<String>,
  val versionPrintFlags: ImmutableList<String>,
  private val timeoutSeconds: Int = ICompilationAction.DEFAULT_COMPILATION_TIMEOUT_SECONDS,
) : ICompilationAction {

  init {
    require(timeoutSeconds > 0)
  }

  protected val versionPrintCmd = compilerCommand.normalizedCommand +
    " " + versionPrintFlags.joinToString(" ")

  override fun compile(file: File) = compile(file, Shells.CURRENT_ENV)

  override fun compileWithExtraEnvironment(
    file: File,
    extraEnv: ImmutableMap<String, String>,
  ): ActionResult {
    val currentEnv = Shells.CURRENT_ENV
    val builder = ImmutableMap.builder<String, String>()
    builder.putAll(currentEnv)
    builder.putAll(extraEnv)
    return compile(file, builder.build())
  }

  protected fun compile(file: File, env: ImmutableMap<String, String>): ActionResult {
    require(file.isFile) { file }
    val cmd = constructCompileCmd(file)
    return ActionResult(
      Shells.singleton.run(
        cmd,
        file.absoluteFile.parentFile.toPath(),
        captureOutput = true,
        environment = env,
      ),
      cmd,
    )
  }

  override fun getVersion(): String {
    val result = Shells.singleton.run(
      versionPrintCmd,
      captureOutput = true,
      environment = Shells.CURRENT_ENV,
    )
    check(result.exitCode.isZero()) {
      result.stderr.combinedLines
    }
    return result.stderr.combinedLines + result.stdout.combinedLines
  }

  @VisibleForTesting
  override fun constructCompileCmd(file: File): String {
    val cmd = StringBuilder()
    // run brew install coreutils if you have timeout command not found issue
    cmd.append("${TIMEOUT_CMD.normalizedCommand} -s 9 ")
      .append(timeoutSeconds).append(" ")
      .append(compilerCommand.normalizedCommand).append(" ")
    compileFlags.joinTo(cmd, " ")
    cmd.append(' ')
    cmd.append(file.name)
    return cmd.toString()
  }

  companion object {
    val TIMEOUT_CMD = ShellCommandOnPath("timeout")
  }
}
