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

import org.perses.program.EnumFormatControl
import org.perses.program.ScriptFile
import org.perses.program.TokenizedProgram
import java.io.Closeable
import java.io.File
import java.util.concurrent.Callable
import java.util.concurrent.Executors
import java.util.concurrent.FutureTask
import java.util.concurrent.atomic.AtomicInteger

/** An execution service for test script runs.  */
class TestScriptExecutorService(
  tempRootFolder: File,
  private val numOfThreads: Int,
  testScriptFile: ScriptFile,
  sourceFileName: String
) : Closeable {

  companion object {
    val ALWAYS_TRUE_PRECHECK = { TestScript.TestResult(exitCode = 0, elapsedMilliseconds = 0) }
  }

  val statistics = Statistics()

  // TODO: create the executor outside, and pass it in as a parameter, so that others can use the
  //       executor.
  private var executorService = Executors.newFixedThreadPool(numOfThreads)
  private var reductionFolderManager: ReductionFolderManager?

  init {
    require(numOfThreads > 0) {
      "The number of threads must be positive: $numOfThreads"
    }
    require(sourceFileName.indexOf('/') < 0 || sourceFileName.indexOf('\\') < 0) {
      "Invalid source file name. It should be the name only: $sourceFileName"
    }
    if (!tempRootFolder.exists()) {
      check(tempRootFolder.mkdir()) { "Failed to create folder $tempRootFolder" }
    }
    assert(tempRootFolder.isDirectory) {
      "The temp root folder is not a directory: $tempRootFolder"
    }

    reductionFolderManager = ReductionFolderManager(
      tempRootFolder,
      testScriptFile,
      sourceFileName
    )
  }

  fun createNamedReductionFolder(folderName: String) =
    reductionFolderManager!!.createNamedFolder(folderName)

  @Override
  override fun close() {
    executorService?.shutdown()
    reductionFolderManager?.deleteRootFolder()

    executorService = null
    reductionFolderManager = null
  }

  fun finalize() {
    check(executorService == null && reductionFolderManager == null) {
      "This $this has not been closed."
    }
  }

  /**
   * FIXME: make this method blocking if there is no available tasks.
   */
  fun testProgram(
    prechecker: () -> TestScript.TestResult,
    program: TokenizedProgram,
    keepOrigCodeFormat: EnumFormatControl
  ): FutureTestScriptExecutionTask {
    statistics.onSubmitTest()
    val workingFolder = reductionFolderManager!!.createNextFolder()
    val result = FutureTestScriptExecutionTask(
      ReductionTestScriptExecutorCallback(
        workingFolder, prechecker,
        program, keepOrigCodeFormat, statistics
      )
    )
    executorService.submit(result)
    return result
  }

  class FutureTestScriptExecutionTask(
    private val callable: ReductionTestScriptExecutorCallback
  ) :
    FutureTask<TestScript.TestResult>(callable) {
    val workingDirectory: File
      get() = callable.workingDirectory.folder

    val program: TokenizedProgram
      get() = callable.program
  }

  /** The test script runner for future.  */
  class ReductionTestScriptExecutorCallback(
    val workingDirectory: ReductionFolder,
    private val prechecker: () -> TestScript.TestResult,
    val program: TokenizedProgram,
    private val keepOrigCodeFormat: EnumFormatControl,
    private val statistics: Statistics
  ) :
    Callable<TestScript.TestResult> {

    override fun call(): TestScript.TestResult {
      statistics.onRunPrecheck()
      val precheckResult = prechecker.invoke()
      if (precheckResult.isFail) {
        return precheckResult
      }
      statistics.onExecuteScript()
      program.writeToFile(workingDirectory.sourceFilePath, keepOrigCodeFormat)
      val result = workingDirectory.testScript.test()
      workingDirectory.deleteAllOtherFiles()
      return result
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
}
