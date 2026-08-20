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
import org.perses.program.ProgramSize
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.AbstractReductionDriver
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.createSnapshot
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.util.toImmutableList

/**
 * Builds a cross-file reducer from the runtime dependencies the driver owns (the IO manager, the
 * executor service that creating one requires, and the renderer). Lets a caller decide which reducers
 * a driver runs without constructing them itself -- the executor service does not exist until the
 * driver does -- so a driver can be configured as e.g. "transformations only" or "empty-file deletion
 * only" (see [CrossFileReductionDriver.transformationReducerFactory] /
 * [CrossFileReductionDriver.FILE_DELETION_REDUCER_FACTORY]).
 */
typealias CrossFileReducerFactory = (
  CrossFileReductionIOManager,
  TestScriptExecutorService,
  AbstractOutputManagerFactory<CrossFileProgram>,
) -> AbstractCrossFileReducer

/**
 * The driver for true multi-file reduction: it builds the initial whole-set program from the
 * (populated) result folder, runs the [reducerFactories]' reducers over it to a fixpoint, and emits
 * the reduction/fixpoint events for progress reporting -- mirroring the ppr `ListDiffReductionDriver`.
 *
 * The reducers are injected (as factories, since they need the executor service this driver creates)
 * rather than hardcoded, so the file-set-changing [CrossFileFileDeletionReducer] can be run in its
 * **own** driver placed strictly last (see `Main`). That keeps a file deletion -- which leaves the
 * result folder with fewer files than `originalReductionInputs.mutableFiles` -- from ever preceding a content
 * pass that re-reads the folder by iterating the full mutable-file set, an invariant a single driver
 * running both reducers could not guarantee once the content phase grows a big fixpoint.
 *
 * The result folder is the single source of truth: the reduction state's listener writes each
 * accepted improvement back via `ioManager.saveBestProgram`, and the size metrics are read from the
 * folder.
 */
class CrossFileReductionDriver(
  globalContext: GlobalContext,
  ioManager: CrossFileReductionIOManager,
  // The renderer (carries the code format) this driver owns, rather than the IO manager: it renders
  // candidates for the Layer-2 sanity check, hands it to the reducers, and renders each accepted best
  // before saving. The cross-file stack does not adapt the format, so this is a fixed factory.
  private val outputManagerFactory: CrossFileOutputManagerFactory,
  private val reducerFactories: ImmutableList<CrossFileReducerFactory>,
  private val listenerManager: AsyncReductionListenerManager,
  executorService: TestScriptExecutorService,
  hideTimestampsInLog: Boolean,
  // The single whole-reduction start event, created once by AbstractMain and shared by every driver;
  // this cross-file pass reuses it for its fixpoint-iteration messages rather than creating its own.
  private val reductionStartEvent: ReductionStartEvent,
) : AbstractReductionDriver<CrossFileProgram, CrossFileReductionIOManager>(
    globalContext,
    ioManager,
    executorService,
    hideTimestampsInLog,
  ) {
  override fun reduce() {
    printStartTime()

    val reductionState =
      CrossFileReductionState(
        CrossFileProgram(ioManager.resultFolder.readLiveMutableFileContents()),
      ) { ioManager.saveBestProgram(outputManagerFactory.createManagerFor(it)) }

    for (reducer in createReducers()) {
      val fixpointStartEvent =
        reductionStartEvent.nextFixpointIteration(
          perFileSizeMetrics = perFileSizeMetrics(reductionState.bestProgram),
          reducerClass = reducer.nameAndDesc,
          treeStructureDumper = { dumpFileSet(reductionState.bestProgram) },
          testScriptStatistics = executorService.statistics.createSnapshot(),
        )
      listenerManager.onFixpointIterationStart(fixpointStartEvent)

      try {
        // Layer-2 sanity check: the current best program (the whole mutable-file set) is the
        // reducer's input representation; verify it still passes the test before the reducer runs.
        checkRepresentationPreservesPropertyOrThrow(
          outputManagerFactory.createManagerFor(reductionState.bestProgram),
          reducer.nameAndDesc.shortName,
        )
        reducer.reduce(reductionState)
      } catch (e: Exception) {
        listenerManager.onCriticalException(e)
      }

      listenerManager.onFixpointIterationEnd(
        fixpointStartEvent.createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          perFileSizeMetrics = perFileSizeMetrics(reductionState.bestProgram),
          testScriptStatistics = executorService.statistics.createSnapshot(),
        ),
      )
    }
  }

  private fun createReducers(): ImmutableList<AbstractCrossFileReducer> =
    reducerFactories
      .map { factory -> factory(ioManager, executorService, outputManagerFactory) }
      .toImmutableList()

  // Per-file sizes of the current best [program]. One slot per mutable file is required, so a file
  // dropped from the live set (absent from [program]) reports an empty content -- size 0 -- which is
  // accurate (it is physically gone). Token counts are left null (this layer does not parse), so they
  // fall back to the non-blank character count -- the size the reducer drives by.
  private fun perFileSizeMetrics(program: CrossFileProgram): PerFileSizeMetrics {
    val contents = program.fileContents
    return PerFileSizeMetrics(
      ioManager.originalReductionInputs,
      ioManager.originalReductionInputs.mutableFiles
        .map { file ->
          val content = contents[file] ?: ""
          val nonBlank = content.count { !Character.isWhitespace(it) }
          ProgramSize(
            payload = Unit,
            canonicalTokenCount = null,
            surrogateTokenCount = nonBlank,
            totalCharacterCount = content.length,
            nonBlankCharacterCount = nonBlank,
          )
        }.toImmutableList(),
    )
  }

  // Only the live files of [program] -- a file dropped from the set is omitted, so the dump shows the
  // shrunken corpus.
  private fun dumpFileSet(program: CrossFileProgram): String =
    program.fileContents.entries.joinToString("\n") { (file, content) ->
      "${file.baseName}: ${content.length} characters"
    }

  companion object {
    private val REDUCER_NAME_AND_DESC =
      object : AbstractReducerNameAndDesc(
        shortName = "multi-file-transformation",
        description = "Drives cross-file transformations over the whole mutable-file set.",
      ) {}

    private val FILE_DELETION_NAME_AND_DESC =
      object : AbstractReducerNameAndDesc(
        shortName = "multi-file-deletion",
        description = "Drops a whole mutable file from the set when it proves unnecessary.",
      ) {}

    /** A factory for the content reducer that rewrites file content via [transformations]. */
    fun transformationReducerFactory(
      transformations: ImmutableList<out CrossFileProgramTransformation>,
    ): CrossFileReducerFactory =
      { ioManager, executorService, outputManagerFactory ->
        CrossFileTransformationReducer(
          REDUCER_NAME_AND_DESC,
          ioManager,
          executorService,
          outputManagerFactory,
          transformations,
        )
      }

    /**
     * A factory for the file-set reducer that drops whole, unnecessary files. Run it in its own
     * driver placed strictly last (see the class KDoc), never alongside a content reducer.
     */
    val FILE_DELETION_REDUCER_FACTORY: CrossFileReducerFactory =
      { ioManager, executorService, outputManagerFactory ->
        CrossFileFileDeletionReducer(
          FILE_DELETION_NAME_AND_DESC,
          ioManager,
          executorService,
          outputManagerFactory,
        )
      }
  }
}
