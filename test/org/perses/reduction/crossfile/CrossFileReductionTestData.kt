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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.program.AbstractReductionFile
import org.perses.program.ProgramSize
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.AbstractReductionTestData
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.io.ReductionFolderManager
import org.perses.reduction.io.SourceSpec
import org.perses.util.transformToImmutableList
import java.nio.file.Files

/**
 * The cross-file (whole-set) flavor of [AbstractReductionTestData]: a [CrossFileReductionIOManager]
 * over a set of mutable files, plus the `programOf` and `createDriver` helpers the cross-file tests
 * build on. Everything it creates -- driver, listener manager, global context, temp dir -- is closed
 * by [close].
 */
class CrossFileReductionTestData(
  testClass: Class<*>,
  scriptBody: String,
  vararg sources: SourceSpec,
) : AbstractReductionTestData(testClass, scriptBody, sources.toList()) {
  val outputManagerFactory = CrossFileOutputManagerFactory(inputs, shaAlgorithm)

  override val ioManager =
    CrossFileReductionIOManager(
      workingDirectory = workingDir,
      originalReductionInputs = inputs,
      resultFolder = createPopulatedResultFolder(),
    )

  /** Builds a whole-set program from (file, content) pairs. */
  fun programOf(vararg entries: Pair<AbstractReductionFile<*, *>, String>): CrossFileProgram {
    val builder = ImmutableMap.builder<AbstractReductionFile<*, *>, String>()
    entries.forEach { (file, content) -> builder.put(file, content) }
    return CrossFileProgram(builder.build())
  }

  /**
   * A driver running [transformations] then the file-deletion reducer over this set, mirroring what
   * Main's cross-file phases do (minus the two-driver split, which [createReducerDriver] exercises).
   * The driver and the listener manager and global context it needs are created here and closed by
   * [close].
   */
  fun createDriver(
    transformations: ImmutableList<out CrossFileProgramTransformation>,
  ): CrossFileReductionDriver =
    createReducerDriver(
      ImmutableList.of(
        CrossFileReductionDriver.transformationReducerFactory(transformations),
        CrossFileReductionDriver.FILE_DELETION_REDUCER_FACTORY,
      ),
    )

  /**
   * A driver running exactly [reducerFactories] over this set; closed by [close]. Each call mints a
   * fresh IO manager (its own temp root) sharing the populated result folder, exactly as Main does --
   * so callers can run several drivers in sequence (an executor service deletes its temp root on
   * close, so its IO manager cannot be reused by a later driver).
   */
  fun createReducerDriver(
    reducerFactories: ImmutableList<CrossFileReducerFactory>,
  ): CrossFileReductionDriver {
    val driverIoManager =
      CrossFileReductionIOManager(
        workingDirectory = workingDir,
        originalReductionInputs = inputs,
        resultFolder = ioManager.resultFolder,
      )
    val listenerManager =
      AsyncReductionListenerManager(listeners = ImmutableList.of(), synchronousMode = true)
    val globalContext =
      GlobalContext(
        enableGlobalCache = false,
        globalCacheFile = null,
        pathToSaveUpdatedGlobalCache = null,
        shaAlgorithm = shaAlgorithm,
      )
    // In production AbstractMain creates and owns the shared executor; here the test builds one (over
    // a fresh temp root, unique per call so several drivers can run in sequence) and closes it via
    // onClose.
    val executorService =
      TestScriptExecutorService(
        reductionFolderManager =
          ReductionFolderManager(inputs, Files.createTempDirectory(workingDir, "exec_root_")),
        specifiedNumOfThreads = 1,
        scriptExecutionTimeoutInSeconds = 600L,
        scriptExecutionKeepTryingAfterTimeout = false,
        globalExecutionCache = globalContext.globalExecutionCache,
      )
    val driver =
      CrossFileReductionDriver(
        globalContext = globalContext,
        ioManager = driverIoManager,
        outputManagerFactory = outputManagerFactory,
        reducerFactories = reducerFactories,
        listenerManager = listenerManager,
        executorService = executorService,
        hideTimestampsInLog = true,
        reductionStartEvent =
          ReductionStartEvent(
            currentTimeMillis = System.currentTimeMillis(),
            perFileSizeMetrics =
              PerFileSizeMetrics(
                inputs,
                inputs.mutableFiles.transformToImmutableList { ProgramSize.ZERO },
              ),
            commandLineOptions = "",
          ),
      )
    onClose { driver.close() }
    onClose { executorService.close() }
    onClose { listenerManager.close() }
    onClose { globalContext.close() }
    return driver
  }
}
