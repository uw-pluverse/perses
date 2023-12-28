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
import com.google.common.io.Closer
import org.perses.program.AbstractDataKind
import org.perses.reduction.AbstractExternalTestScriptExecutionCachePolicy.NullExternalTestScriptExecutionCachePolicy
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.util.TimeUtil.formatDateForDisplay
import org.perses.util.ktInfo
import java.io.Closeable
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractReductionDriver<
  Program,
  Kind : AbstractDataKind,
  IOManager : AbstractReductionIOManager<Program, Kind, IOManager>,
  >(
  protected val ioManager: IOManager,
  specifiedNumOfThreads: Int,
  scriptExecutionTimeoutInSeconds: Long,
  keepWaitingAfterScriptTimeout: Boolean,
  externalTestScriptExecutionCachePolicyCreator:
  () -> AbstractExternalTestScriptExecutionCachePolicy = {
    NullExternalTestScriptExecutionCachePolicy()
  },
) : IReductionDriver {

  private val closer = Closer.create()

  protected val executorService = TestScriptExecutorService(
    ioManager.lazilyInitializedReductionFolderManager,
    specifiedNumOfThreads,
    scriptExecutionTimeoutInSeconds,
    keepWaitingAfterScriptTimeout,
    externalTestScriptExecutionCachePolicyCreator,
  ).also { closer.register(it) }

  override fun close() {
    try {
      closer.close()
    } catch (e: Throwable) {
      // ignore.
      e.printStackTrace()
    }
  }

  protected fun <T : Closeable> registerToClose(toBeClosed: T): T {
    return closer.register(toBeClosed)
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
    val sanityChecker = {
      executorService.testProgramAsyncWithoutPayload(
        preCheck = TestScriptExecutorService.ALWAYS_TRUE_PRECHECK,
        postCheck = TestScriptExecutorService.IDENTITY_POST_CHECK,
        ioManager.createOutputManager(program),
      )
    }
    val future = sanityChecker.invoke()
    check(future.getWithTimeoutWarnings().isInteresting) {
      val flakinessChecker = PropertyFlakinessChecker(
        numberOfTrials = 5,
        initialNumOfUninteresting = 1,
        sanityChecker,
      )
      logger.ktInfo { "The initial sanity check failed." }
      logger.ktInfo {
        "Checking whether the script is flaky. #trials=${flakinessChecker.numberOfTrials}"
      }
      val flakinessCheckResult = flakinessChecker.run().computeResult()

      val cmdOutput = future.workingDirectory.testScript.runAndCaptureOutput()
      logger.atFine().log("The initial sanity check failed. Folder: %s", future.workingDirectory)
      val tempDir = copyFilesToTempDir(future.workingDirectory.folder)
      val message = """The initial sanity check failed. 
        
        ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
        *
        * The script exit code is ${cmdOutput.exitCode} 
        * The files have been saved, and you can check them at:
        *     $tempDir
        * ${flakinessCheckResult.describeResult()}
        ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** *****
        
        ============= stderr =============
        ${cmdOutput.stderr.combinedLines.let { it.ifBlank { "<empty>" } }}
         
        ============= stdout =============
        ${cmdOutput.stdout.combinedLines.let { it.ifBlank { "<empty>" } }} 
      """.lineSequence().map {
        it.trimStart()
      }.joinToString("\n")

      message
    }
  }

  class PropertyFlakinessChecker(
    val numberOfTrials: Int,
    val initialNumOfUninteresting: Int,
    private val sanityChecker: () -> TestScriptExecResult<Any>,
  ) {

    private val results = mutableListOf<PropertyTestResult>()

    init {
      require(numberOfTrials > 0) { numberOfTrials }
    }

    fun run(): PropertyFlakinessChecker {
      check(results.isEmpty()) { "This method can only be called once." }
      (1..numberOfTrials).forEach { _ ->
        results.add(sanityChecker.invoke().getWithTimeoutWarnings())
      }
      check(results.size == numberOfTrials)
      return this
    }

    fun computeResult() = Result(
      numOfInteresting = results.count { it.isInteresting },
      numOfUninteresting = results.count { it.isNotInteresting } + initialNumOfUninteresting,
    )

    data class Result(
      val numOfInteresting: Int,
      val numOfUninteresting: Int,
    ) {

      init {
        require(numOfInteresting >= 0)
        require(numOfUninteresting >= 0)
      }

      val totalNumber: Int
        get() = numOfInteresting + numOfUninteresting

      val isFlaky = numOfInteresting != 0 && numOfUninteresting != 0

      fun describeResult(): String {
        return buildString {
          append("The property test is")
          if (!isFlaky) {
            append(" not")
          }
          append(" flaky. ")
          append("#total runs: $totalNumber")
          append(", #interesting: $numOfInteresting, #uninteresting: $numOfUninteresting")
        }
      }
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
