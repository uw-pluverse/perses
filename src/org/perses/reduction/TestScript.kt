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
package org.perses.reduction

import com.google.common.flogger.FluentLogger
import org.perses.program.ScriptFile
import org.perses.util.TimeSpan
import org.perses.util.Util
import org.perses.util.shell.CmdOutput
import org.perses.util.shell.Shells.Companion.CURRENT_ENV
import org.perses.util.shell.Shells.Companion.singleton
import java.nio.file.Files
import java.nio.file.Path

/** Represents a test script, that specifies the property to preserve during reduction.  */
class TestScript(val scriptFile: Path, private val scriptTemplate: ScriptFile) {

  /** @return true if the test script passes.
   */
  fun test(): PropertyTestResult {
    val timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis())
    val output = singleton.run(
      "${scriptTemplate.shebang}  ${scriptFile.fileName}",
      scriptFile.parent,
      captureOutput = false,
      environment = CURRENT_ENV,
    )
    logger.atFine().log("test script stdout: %s", output.stdout)
    logger.atFine().log("test script stderr: %s", output.stderr)
    val timeSpan = timeSpanBuilder.end(System.currentTimeMillis())
    return PropertyTestResult(output.exitCode, timeSpan.elapsedTimeInMillis)
  }

  fun runAndCaptureOutput(): CmdOutput {
    return singleton.run(
      "${scriptTemplate.shebang}  ${scriptFile.fileName}",
      scriptFile.parent,
      captureOutput = true,
      environment = CURRENT_ENV,
    )
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }

  init {
    scriptTemplate.writeTo(scriptFile)
    Util.setExecutable(scriptFile)
    check(Files.isExecutable(scriptFile)) { "Fail to set executable bit for $scriptFile" }
  }
}
