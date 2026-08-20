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
package org.perses

import com.google.common.collect.ImmutableList
import org.perses.listener.ActionSetEffectProfiler
import org.perses.listener.DifferentialAnalysisProfiler
import org.perses.listener.ExceptionRecorder
import org.perses.listener.LoggingListener
import org.perses.listener.ProgramSizeTrendProfiler
import org.perses.listener.ProgressMonitorForNodeReducer
import org.perses.listener.ReducerStatisticsSummaryListener
import org.perses.listener.StatisticsListener
import org.perses.listener.TestScriptExecutionListener
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.ui.WebUiListener
import org.perses.util.FileStreamPool
import java.nio.file.Path
import kotlin.io.path.name

object PersesListenerManagerCreator {
  fun createAsyncReductionListenerManager(
    cmd: PersesCommandOptions,
    fileStreamPool: FileStreamPool,
    outputDirectory: Path,
  ): AsyncReductionListenerManager {
    val builder = ImmutableList.builder<AbstractReductionListener>()
    builder.add(LoggingListener(hideTimestamps = cmd.verbosityFlags.hideTimestamps))
    // Rented here (not at the ProgressMonitorForNodeReducer site below) so the run-level statistics
    // summary can be echoed into the same progress dump. ProgressMonitorForNodeReducer owns the
    // rental and returns it on close; the summary listener only borrows the instance to write.
    val progressDumpStream: FileStreamPool.ManagedPrintStream? =
      cmd.profilingFlags.progressDumpFile?.let {
        fileStreamPool.rentStream(
          path = it,
          description = ProgressMonitorForNodeReducer::class.toString(),
        )
      }
    builder.add(
      ReducerStatisticsSummaryListener(
        dedicatedStream =
          fileStreamPool.rentStream(
            path = outputDirectory.resolve("perses_reducer_statistics.txt"),
            description = ReducerStatisticsSummaryListener::class.toString(),
          ),
        additionalSinks =
          buildList<(String) -> Unit> {
            add { summary -> println(summary) }
            progressDumpStream?.let { stream -> add { summary -> stream.println(summary) } }
          },
        hideTimestamps = cmd.verbosityFlags.hideTimestamps,
      ),
    )
    cmd.profilingFlags.statDumpFile?.let {
      builder.add(
        StatisticsListener(
          fileStreamPool.rentStream(
            path = it,
            description = StatisticsListener::class.toString(),
          ),
        ),
      )
    }
    progressDumpStream?.let {
      builder.add(
        ProgressMonitorForNodeReducer(it),
      )
    }
    cmd.profilingFlags.actionsetEffectProfile?.let {
      val stream =
        fileStreamPool.rentStream(
          path = it,
          description = ActionSetEffectProfiler::class.toString(),
        )
      builder.add(
        ActionSetEffectProfiler(stream),
      )
    }
    cmd.profilingFlags.statDumpFile
      ?.parent
      ?.resolve(
        "testscript-" + cmd.profilingFlags.statDumpFile?.name,
      )?.let {
        builder.add(
          TestScriptExecutionListener(
            fileStreamPool.rentStream(
              path = it,
              description = TestScriptExecutionListener::class.toString(),
            ),
          ),
        )
      }
    cmd.profilingFlags.profileProgramSizeTrend.let { userSpecified ->
      val finalPath: Path =
        userSpecified ?: outputDirectory.resolve("perses_reduction_result_size_trend.csv")
      builder.add(
        ProgramSizeTrendProfiler(
          stream =
            fileStreamPool.rentStream(
              path = finalPath,
              description = ProgramSizeTrendProfiler::class.toString(),
            ),
        ),
      )
    }
    cmd.profilingFlags.profileReductionProcessDifferentialAnalysis?.let { path ->
      builder.add(
        DifferentialAnalysisProfiler(
          stream =
            fileStreamPool.rentStream(
              path = path,
              description = DifferentialAnalysisProfiler::class.toString(),
            ),
          hideTimestamp = cmd.verbosityFlags.hideTimestamps,
        ),
      )
    }
    if (cmd.profilingFlags.enableWebUi) {
      builder.add(WebUiListener.create(requestedPort = cmd.profilingFlags.webUiPort))
    }
    builder.add(ExceptionRecorder())
    return AsyncReductionListenerManager(
      listeners = builder.build(),
      synchronousMode = cmd.verbosityFlags.fullyDeterministicMode,
    )
  }
}
