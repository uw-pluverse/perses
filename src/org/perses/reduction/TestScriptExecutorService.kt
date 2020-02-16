/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

import java.io.File
import java.io.IOException
import java.util.concurrent.Callable
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors
import java.util.concurrent.FutureTask
import java.util.concurrent.atomic.AtomicInteger
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram

/** An execution service for test script runs.  */
class TestScriptExecutorService(
  tempRootFolder: File,
  private val numOfThreads: Int,
  testScriptFile: SourceFile?,
  sourceFileName: String
) {
  private val executionCounter = AtomicInteger()
  private val executorService: ExecutorService
  private val reductionFolderManager: ReductionFolderManager

  @Throws(IOException::class)
  fun shutdown() {
    executorService.shutdown()
    reductionFolderManager.deleteRootFolder()
  }

  /**
   * FIXME: make this method blocking if there is no available tasks. TODO: output the underlying
   * test script and source file for debugging.
   */
  fun testProgram(
    program: TokenizedProgram,
    keepOrigCodeFormat: Boolean
  ): FutureTestScriptExecutionTask {
    executionCounter.incrementAndGet()
    return try {
      val workingFolder = reductionFolderManager.createNextFolder()
      val result = FutureTestScriptExecutionTask(
        ReductionTestScriptExecutorCallback(workingFolder, program, keepOrigCodeFormat))
      executorService.submit(result)
      result
    } catch (e: IOException) {
      throw RuntimeException(e)
    }
  }

  val scriptExecutionCount: Int
    get() = executionCounter.get()

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
    val program: TokenizedProgram,
    private val keepOrigCodeFormat: Boolean
  ) :
    Callable<TestScript.TestResult> {

    @Throws(Exception::class)
    override fun call(): TestScript.TestResult {
      program.writeToFile(workingDirectory.sourceFilePath, keepOrigCodeFormat)
      val result = workingDirectory.testScript.test()
      workingDirectory.deleteAllOtherFiles()
      return result
    }
  }

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
    // TODO: create the executor outside, and pass it in as a parameter, so that others can use the
//       executor.
    executorService = Executors.newFixedThreadPool(numOfThreads)
    reductionFolderManager = ReductionFolderManager(
      tempRootFolder,
      testScriptFile!!,
      sourceFileName)
  }
}
