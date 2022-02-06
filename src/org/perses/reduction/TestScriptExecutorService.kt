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
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.ReductionFolderManager
import org.perses.util.DaemonThreadPool
import org.perses.util.PerformanceMonitor
import org.perses.util.PerformanceMonitor.IActionOnLongRunningTask
import org.perses.util.TimeUtil
import java.io.Closeable
import java.nio.file.Path
import java.util.concurrent.Callable
import java.util.concurrent.FutureTask
import java.util.concurrent.atomic.AtomicInteger

/** An execution service for test script runs.  */
class TestScriptExecutorService(
  private val reductionFolderManager: ReductionFolderManager,
  val specifiedNumOfThreads: Int,
  scriptExecutionMonitorIntervalMillis: Int
) : Closeable {

  val statistics = Statistics()

  private var executorService = DaemonThreadPool.create(specifiedNumOfThreads)
  private var scriptExecutionMonitor:
    PerformanceMonitor<ReductionTestScriptExecutorCallback>?

  init {
    require(specifiedNumOfThreads > 0) {
      "The number of threads must be positive: $specifiedNumOfThreads"
    }

    val action = object : IActionOnLongRunningTask<ReductionTestScriptExecutorCallback> {
      override fun onLongRunningTask(
        task: ReductionTestScriptExecutorCallback,
        duration: Int,
        threshold: Int
      ) {
        if (logger.atWarning().isEnabled) {
          TimeUtil.formatDateForDisplay(duration.toLong())
          logger.atWarning().log(
            "%s: %s",
            MSG_SCRIPT_RUN_TOO_LONG,
            TimeUtil.formatDateForDisplay(duration.toLong())
          )
        }
      }
    }
    scriptExecutionMonitor = PerformanceMonitor(
      sleepIntervalMillis = scriptExecutionMonitorIntervalMillis,
      actionOnLongRunningTask = action
    )
  }

  fun createNamedReductionFolder(folderName: String) =
    reductionFolderManager.createNamedFolder(folderName)

  @Override
  override fun close() {
    executorService.shutdown()
    reductionFolderManager.deleteRootFolder()
    scriptExecutionMonitor!!.close()

    scriptExecutionMonitor = null
  }

  fun finalize() {
    check(scriptExecutionMonitor == null) {
      "This $this has not been closed."
    }
  }

  /**
   * FIXME: make this method blocking if there is no available tasks.
   */
  fun testProgramAsync(
    preChecke: () -> PropertyTestResult,
    postCheck: (currentResult: PropertyTestResult) -> PropertyTestResult,
    outputManager: AbstractOutputManager
  ): FutureTestScriptExecutionTask {
    statistics.onSubmitTest()
    val workingFolder = reductionFolderManager.createNextFolder()
    val result = FutureTestScriptExecutionTask(
      ReductionTestScriptExecutorCallback(
        workingFolder,
        preChecke,
        postCheck,
        outputManager,
        statistics,
        scriptExecutionMonitor!!
      )
    )
    executorService.submit(result)
    return result
  }

  class FutureTestScriptExecutionTask(
    private val callable: ReductionTestScriptExecutorCallback
  ) : FutureTask<PropertyTestResult>(callable) {
    val workingDirectory: Path
      get() = callable.workingDirectory.folder

    val reductionFolder: ReductionFolder
      get() = callable.workingDirectory
  }

  /** The test script runner for future.  */
  class ReductionTestScriptExecutorCallback(
    val workingDirectory: ReductionFolder,
    private val preChecker: () -> PropertyTestResult,
    private val postChecker: (currentResult: PropertyTestResult) -> PropertyTestResult,
    private val outputManager: AbstractOutputManager,
    private val statistics: Statistics,
    private val runtimePerformanceMonitor:
      PerformanceMonitor<ReductionTestScriptExecutorCallback>
  ) : Callable<PropertyTestResult> {

    override fun call(): PropertyTestResult {
      statistics.onRunPrecheck()
      preChecker().let {
        if (it.isNotInteresting) {
          return it
        }
      }
      statistics.onExecuteScript()
      runtimePerformanceMonitor.onTaskStart(this)
      outputManager.write(workingDirectory)
      val result = workingDirectory.runTestScript()
      workingDirectory.deleteAllOtherFiles()
      runtimePerformanceMonitor.onTaskEnd(this)
      return postChecker(result)
    }
  }

  class Statistics {
    private val submittedTestCounter = AtomicInteger()
    private val preCheckCounterCounter = AtomicInteger()
    private val scriptExecutionCounter = AtomicInteger()

    internal fun onSubmitTest() {
      submittedTestCounter.incrementAndGet()
    }

    internal fun onRunPrecheck() {
      preCheckCounterCounter.incrementAndGet()
    }

    internal fun onExecuteScript() {
      scriptExecutionCounter.incrementAndGet()
    }

    fun getSubmittedTestNumber() = submittedTestCounter.get()
    fun getPrecheckExecutionNumber() = preCheckCounterCounter.get()
    fun getScriptExecutionNumber() = scriptExecutionCounter.get()
  }

  companion object {
    val ALWAYS_TRUE_PRECHECK = { PropertyTestResult(exitCode = 0, elapsedMilliseconds = 0) }
    val IDENTITY_POST_CHECK: (currentResult: PropertyTestResult) -> PropertyTestResult = { it }
    val logger = FluentLogger.forEnclosingClass()
    const val MSG_SCRIPT_RUN_TOO_LONG = "One script execution took too much time"
  }
}
