/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
import org.perses.reduction.TestScriptExecutorService.OutputManagerCreatorResult.Proceed
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.ReductionFolderManager
import org.perses.util.DaemonThreadPool
import org.perses.util.shell.ExitCode
import java.io.Closeable
import java.nio.file.Path
import java.util.concurrent.Callable
import java.util.concurrent.CancellationException
import java.util.concurrent.atomic.AtomicInteger

/** An execution service for test script runs.  */
class TestScriptExecutorService(
  private val reductionFolderManager: ReductionFolderManager,
  val specifiedNumOfThreads: Int,
  private val scriptExecutionTimeoutInSeconds: Long,
  private val scriptExecutionKeepTryingAfterTimeout: Boolean = true,
  private val globalExecutionCache: AbstractGlobalExecutionCache,
) : Closeable {
  val statistics = Statistics()

  private val scriptExecutorService =
    DaemonThreadPool.create(
      numThreads = specifiedNumOfThreads,
      creatorObject = this,
    )
  private val outputManagerCreatorService =
    DaemonThreadPool.create(
      numThreads = specifiedNumOfThreads,
      creatorObject = this,
    )
  private val genericThreadPool =
    DaemonThreadPool.create(
      numThreads = specifiedNumOfThreads,
      creatorObject = this,
    )

  init {
    require(specifiedNumOfThreads > 0) {
      "The number of threads must be positive: $specifiedNumOfThreads"
    }
  }

  fun createReductionFolder(
    prefix: String,
    suffix: String,
  ) = reductionFolderManager.createNextFolder(prefix, suffix)

  /** A plain temp directory under the shared folder manager's root, for reducers that need scratch
   * space (e.g. the LPR reducer's LLM client). Routed through the shared folder manager so all of a
   * reduction's temp dirs live under one root rather than a separate per-IO-manager one. */
  fun createTempDirectory(
    prefix: String = "",
    postfix: String = "",
  ): Path = reductionFolderManager.createTempDirectory(prefix, postfix)

  @Override
  override fun close() {
    DaemonThreadPool.shutdownOrThrow(scriptExecutorService)
    DaemonThreadPool.shutdownOrThrow(outputManagerCreatorService)
    reductionFolderManager.deleteRootFolder()
  }

  fun interface IPostCheck<Payload> {
    fun perform(
      currentResult: TestScriptVerdict,
      payload: Payload,
    ): TestScriptVerdict
  }

  fun interface IPreCheck<Payload : Any> {
    fun perform(payload: Payload): TestScriptVerdict
  }

  fun <Payload : Any> testProgramAsync(
    preCheck: IPreCheck<Payload>,
    postCheck: IPostCheck<Payload>,
    outputManager: AbstractOutputManager,
    payload: Payload,
  ): TestScriptExecResult<Payload> =
    testProgramAsync(preCheck, postCheck, outputManagerCreator = {
      Proceed(outputManager, payload)
    })

  fun testProgramAsyncWithoutPayload(
    preCheck: IPreCheck<Any>,
    postCheck: IPostCheck<Any>,
    outputManager: AbstractOutputManager,
  ): TestScriptExecResult<Any> =
    testProgramAsync(preCheck, postCheck, outputManagerCreator = {
      Proceed(outputManager, DUMMY_PAYLOAD)
    })

  sealed class OutputManagerCreatorResult<Payload : Any> {
    class Skip<Payload : Any> : OutputManagerCreatorResult<Payload>()

    class Proceed<Payload : Any>(
      val outputManager: AbstractOutputManager,
      val payload: Payload,
    ) : OutputManagerCreatorResult<Payload>()
  }

  fun <Payload : Any> testProgramAsync(
    preCheck: IPreCheck<Payload>,
    postCheck: IPostCheck<Payload>,
    outputManagerCreator: () -> OutputManagerCreatorResult<Payload>,
  ): TestScriptExecResult<Payload> {
    val outputManagerCreatorFuture =
      createRestrictedFuture(
        outputManagerCreatorService.submit(
          Callable { outputManagerCreator() },
        ),
      )

    statistics.onSubmitTest()
    val workingDirectory = reductionFolderManager.createNextFolder()
    val testScriptExecFuture =
      createRestrictedFuture(
        scriptExecutorService.submit(
          Callable<TestScriptVerdict?> {
            if (outputManagerCreatorFuture.isCancelled()) {
              return@Callable null
            }
            val outputManagerWithPayload =
              try {
                when (val t = outputManagerCreatorFuture.getWithTimeoutWarnings()) {
                  is Proceed<Payload> -> t
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
            // TODO(cnsun): add the execution history here.
            // Note that we still write the files to the folder, for debugging purpose only.
            val outputManager = outputManagerWithPayload.outputManager
            outputManager.write(workingDirectory)
            val cachedResult =
              globalExecutionCache.getCachedResultOrNull(
                outputManager,
              )
            val result =
              if (cachedResult == null) {
                val result = workingDirectory.runTestScript()
                globalExecutionCache.cacheTestScriptResult(outputManager, result)
                result
              } else {
                statistics.onExternalCacheHit()
                cachedResult
              }
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

  private fun <T> createRestrictedFuture(future: ListenableFuture<T>): RestrictedFuture<T> =
    RestrictedFuture(
      future,
      defaultTimeoutInSeconds = scriptExecutionTimeoutInSeconds,
      defaultKeepTrying = scriptExecutionKeepTryingAfterTimeout,
    )

  class Statistics {
    private val submittedTestCounter = AtomicInteger()
    private val preCheckCounterCounter = AtomicInteger()
    private val scriptExecutionCounter = AtomicInteger()
    private val externalCacheHitCounter = AtomicInteger()

    internal fun onSubmitTest() {
      submittedTestCounter.incrementAndGet()
    }

    internal fun onExternalCacheHit() {
      externalCacheHitCounter.incrementAndGet()
    }

    internal fun onRunPrecheck() {
      preCheckCounterCounter.incrementAndGet()
    }

    internal fun onExecuteScript() {
      scriptExecutionCounter.incrementAndGet()
    }

    val submittedTestNumber: Int
      get() = submittedTestCounter.get()
    val precheckExecutionNumber: Int
      get() = preCheckCounterCounter.get()
    val scriptExecutionNumber: Int
      get() = scriptExecutionCounter.get()

    val externalCacheHitNumber: Int
      get() = externalCacheHitCounter.get()
  }

  companion object {
    val ALWAYS_TRUE_PRECHECK = { _: Any ->
      TestScriptVerdict(exitCode = ExitCode.ZERO, elapsedMillis = 0)
    }
    val IDENTITY_POST_CHECK = { currentResult: TestScriptVerdict, _: Any ->
      currentResult
    }
    val logger = FluentLogger.forEnclosingClass()
    const val MSG_SCRIPT_RUN_TOO_LONG = "One script execution took too much time"

    val DUMMY_PAYLOAD = object {}
  }
}
