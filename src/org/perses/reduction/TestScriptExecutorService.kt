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
import com.google.common.util.concurrent.ListenableFuture
import org.perses.reduction.TestScriptExecutorService.AbstractOutputManagerCreatorResult.ProceedResult
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.ReductionFolderManager
import org.perses.util.DaemonThreadPool
import java.io.Closeable
import java.util.concurrent.Callable
import java.util.concurrent.CancellationException
import java.util.concurrent.atomic.AtomicInteger

/** An execution service for test script runs.  */
class TestScriptExecutorService(
  private val reductionFolderManager: ReductionFolderManager,
  val specifiedNumOfThreads: Int,
  private val scriptExecutionTimeoutInSeconds: Long,
  private val scriptExecutionKeepTryingAfterTimeout: Boolean = true,
) : Closeable {

  val statistics = Statistics()

  private val scriptExecutorService = DaemonThreadPool.create(specifiedNumOfThreads)
  private val outputManagerCreatorService = DaemonThreadPool.create(specifiedNumOfThreads)
  private val genericThreadPool = DaemonThreadPool.create(specifiedNumOfThreads)

  init {
    require(specifiedNumOfThreads > 0) {
      "The number of threads must be positive: $specifiedNumOfThreads"
    }
  }

  fun createNamedReductionFolder(folderName: String) =
    reductionFolderManager.createNamedFolder(folderName)

  fun <T> submitGenericTask(task: () -> T) = genericThreadPool.submit(task)

  @Override
  override fun close() {
    DaemonThreadPool.shutdownOrThrow(scriptExecutorService)
    DaemonThreadPool.shutdownOrThrow(outputManagerCreatorService)
    reductionFolderManager.deleteRootFolder()
  }

  fun interface IPostCheck<Payload> {
    fun perform(currentResult: PropertyTestResult, payload: Payload): PropertyTestResult
  }

  fun interface IPreCheck<Payload : Any> {
    fun perform(payload: Payload): PropertyTestResult
  }

  fun <Payload : Any> testProgramAsync(
    preCheck: IPreCheck<Payload>,
    postCheck: IPostCheck<Payload>,
    outputManager: AbstractOutputManager,
    payload: Payload,
  ): TestScriptExecResult<Payload> {
    return testProgramAsync(preCheck, postCheck) {
      ProceedResult(outputManager, payload)
    }
  }

  fun testProgramAsyncWithoutPayload(
    preCheck: IPreCheck<Any>,
    postCheck: IPostCheck<Any>,
    outputManager: AbstractOutputManager,
  ): TestScriptExecResult<Any> {
    return testProgramAsync(preCheck, postCheck) {
      ProceedResult(outputManager, DUMMY_PAYLOAD)
    }
  }

  sealed class AbstractOutputManagerCreatorResult<Payload : Any> {

    class EmptyResult<Payload : Any> : AbstractOutputManagerCreatorResult<Payload>()

    class ProceedResult<Payload : Any>(
      val outputManager: AbstractOutputManager,
      val payload: Payload,
    ) : AbstractOutputManagerCreatorResult<Payload>()

    class StopResult<Payload : Any>(
      val payload: Payload,
    ) : AbstractOutputManagerCreatorResult<Payload>()
  }

  fun <Payload : Any> testProgramAsync(
    preCheck: IPreCheck<Payload>,
    postCheck: IPostCheck<Payload>,
    outputManagerCreator: () -> AbstractOutputManagerCreatorResult<Payload>,
  ): TestScriptExecResult<Payload> {
    val outputManagerCreatorFuture = createRestrictedFuture(
      outputManagerCreatorService.submit(
        Callable { outputManagerCreator() },
      ),
    )

    statistics.onSubmitTest()
    val workingDirectory = reductionFolderManager.createNextFolder()
    val testScriptExecFuture = createRestrictedFuture(
      scriptExecutorService.submit(
        Callable<PropertyTestResult?> {
          if (outputManagerCreatorFuture.isCancelled()) {
            return@Callable null
          }
          val outputManagerWithPayload = try {
            when (val t = outputManagerCreatorFuture.getWithTimeoutWarnings()) {
              is ProceedResult -> t
              else -> return@Callable null
            }
          } catch (e: Exception) {
            when (e) {
              is CancellationException, is InterruptedException -> return@Callable null
              else -> throw e
            }
          }
          statistics.onRunPrecheck()
          preCheck.perform(outputManagerWithPayload.payload).let {
            if (it.isNotInteresting) {
              return@Callable it
            }
          }
          statistics.onExecuteScript()
          outputManagerWithPayload.outputManager.write(workingDirectory)
          val result = workingDirectory.runTestScript()
          workingDirectory.deleteAllOtherFiles()
          return@Callable postCheck.perform(result, outputManagerWithPayload.payload)
        },
      ),
    )
    return TestScriptExecResult(
      workingDirectory,
      outputManagerCreatorFuture = outputManagerCreatorFuture,
      testScriptExecFuture = testScriptExecFuture,
    )
  }

  private fun <T> createRestrictedFuture(future: ListenableFuture<T>): RestrictedFuture<T> {
    return RestrictedFuture(
      future,
      defaultTimeoutInSeconds = scriptExecutionTimeoutInSeconds,
      defaultKeepTrying = scriptExecutionKeepTryingAfterTimeout,
    )
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
    val ALWAYS_TRUE_PRECHECK = { _: Any ->
      PropertyTestResult(exitCode = 0, elapsedMilliseconds = 0)
    }
    val IDENTITY_POST_CHECK = { currentResult: PropertyTestResult, _: Any ->
      currentResult
    }
    val logger = FluentLogger.forEnclosingClass()
    const val MSG_SCRIPT_RUN_TOO_LONG = "One script execution took too much time"

    val DUMMY_PAYLOAD = object {}
  }
}
