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
package org.perses.reduction

import com.google.common.flogger.FluentLogger
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.util.TimeUtil.formatDateForDisplay
import org.perses.util.ktInfo
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractReductionDriver
<Program, IOManager : AbstractReductionIOManager<Program, IOManager>>(
  protected val ioManager: IOManager,
  specifiedNumOfThreads: Int,
  scriptExecutionMonitorIntervalMillis: Int
) : IReductionDriver {

  protected val executorService = TestScriptExecutorService(
    ioManager.createReductionFolderManager(),
    specifiedNumOfThreads,
    scriptExecutionMonitorIntervalMillis
  )

  override fun close() {
    try {
      executorService.close()
    } catch (e: Throwable) {
      // ignore.
      e.printStackTrace()
    }
  }

  protected fun printStartTime() {
    logger.ktInfo {
      "The reduction process started at ${formatDateForDisplay(System.currentTimeMillis())}"
    }
  }

  protected fun sanityCheck(program: Program) {
    // TODO: this should be done in the output directory.
    logger.atFinest().log("sanity checking...")
    /**
     * TODO: need two steps of sanity check:
     *     (1) use the original source program and test script.
     *     This ensures the test script is correct.
     *
     *     (2) use the spar-tree. This ensures the Antlr parser works correctly.
     *
     */
    val future = executorService.testProgramAsync(
      preChecke = TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
      postCheck = TestScriptExecutorService.IDENTITY_POST_CHECK,
      ioManager.createOutputManager(program)
    )
    check(future.get().isInteresting) {
      val cmdOutput = future.reductionFolder.testScript.runAndCaptureOutput()
      logger.atFine().log("The initial sanity check failed. Folder: %s", future.workingDirectory)
      val tempDir = copyFilesToTempDir(future.workingDirectory)
      val message = """The initial sanity check failed. 
        
        ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
        *
        * The script exit code is ${cmdOutput.exitCode} 
        * The files have been saved, and you can check them at:
        *     $tempDir
        *
        ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
        
        ============= stderr =============
        ${cmdOutput.stderr.combinedLines.let { it.ifBlank { "<empty>" } }}
         
        ============= stdout =============
        ${cmdOutput.stdout.combinedLines.let { it.ifBlank { "<empty>" } }} 
      """.lineSequence().map { it.trimStart() }.joinToString("\n")

      message
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    protected fun copyFilesToTempDir(directory: Path): Path {
      val tempDir = Files.createTempDirectory("perses_failure_")
      Files.newDirectoryStream(directory).use {
        for (file in it) {
          if (Files.isRegularFile(file)) {
            Files.copy(file, tempDir.resolve(file.fileName))
          }
        }
      }
      return tempDir
    }
  }
}
