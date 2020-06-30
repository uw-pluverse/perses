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
package org.perses.reduction

import com.google.common.flogger.FluentLogger
import org.perses.program.ScriptFile
import org.perses.util.Shell
import org.perses.util.TimeSpan
import java.io.File

/** Represents a test script, that specifies the property to preserve during reduction.  */
class TestScript(val scriptFile: File, private val scriptTemplate: ScriptFile) {

  /** @return true if the test script passes.
   */
  fun test(): TestResult {
    val timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis())
    val output = Shell.run(
      "${scriptTemplate.shebang}  ${scriptFile.name}",
      scriptFile.parentFile,
      false
    )
    logger.atFine().log("test script stdout: %s", output.stdout)
    logger.atFine().log("test script stderr: %s", output.stderr)
    val timeSpan = timeSpanBuilder.end(System.currentTimeMillis())
    return TestResult(output.exitCode, timeSpan.elapsedTimeInMillis)
  }

  /** The result of a test, including runtime information, i.e., time, exit code.  */
  class TestResult(val exitCode: Int, val elapsedMilliseconds: Long) {

    val isPass: Boolean
      get() = exitCode == 0

    val isFail: Boolean
      get() = !isPass

    companion object {
      val TRUE_RESULT = TestResult(exitCode = 0, elapsedMilliseconds = 0)
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }

  init {
    scriptTemplate.writeTo(scriptFile)
    check(scriptFile.setExecutable(true)) { "Fail to set executable bit for $scriptFile" }
  }
}
