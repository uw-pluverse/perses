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
package org.perses.listener

import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.event.AbstractTestScriptExecutionEvent
import org.perses.reduction.event.BestProgramUpdateEvent
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.util.FileStreamPool
import org.perses.util.TableForTextPrinting
import org.perses.util.padBothEnds
import java.util.IdentityHashMap

/**
 * Records every reducer invocation over the whole reduction and, at the end, prints both the exact
 * per-invocation History and the per-reducer aggregated Summary -- the way c-reduce and c-vise print
 * their pass statistics.
 *
 * This deliberately replaces the old scheduler-built history/statistics report, which was printed
 * once per [org.perses.reduction.AbstractProgramReductionDriver]
 * invocation -- i.e. once per file per sweep -- and so never reported a run-level total. A single
 * instance of this listener instead lives on the shared listener manager: [org.perses.AbstractMain]
 * fires onReductionStart/onReductionEnd exactly once around all the per-file and cross-file drivers,
 * so this listener observes every reducer invocation across the entire pipeline and reports both the
 * unbroken history and the aggregate.
 *
 * The History and Summary are per reducer. Every committed edit also carries a transformation name --
 * a named sub-transformation for reducers that have them (astra: the transformation class; latra: the
 * definition name) or the edit's operation kind otherwise (e.g. "Deletion", "Replacement") -- so all
 * commits are additionally rolled up into a Transformations table keyed "<reducer>.<transformation>",
 * the c-reduce/c-vise per-pass view. Only commit-derived columns are reported per transformation
 * (Worked/#NonDeletions/#Tokens/#NonBlankChars); Times/Queries/Duration remain per reducer because a
 * reducer runs as one fixpoint iteration. The table is omitted only when nothing was committed.
 */
class ReducerStatisticsSummaryListener(
  // Owned: rented for this listener and returned in [close]. Holds the dedicated statistics file.
  private val dedicatedStream: FileStreamPool.ManagedPrintStream,
  // Borrowed write destinations the same report is also echoed to (e.g. stdout and the shared
  // progress-dump stream). These are owned by someone else; this listener only writes to them.
  private val additionalSinks: List<(String) -> Unit>,
  private val hideTimestamps: Boolean,
) : AbstractReductionListener() {
  private class ReducerInvocationRecord(
    val id: Int,
    val reducerName: String,
    val improvementCount: Long,
    val nonDeletionCount: Long,
    val canonicalTokenDelta: Long,
    val nonBlankCharacterDelta: Long,
    val testScriptExecutionCount: Long,
    val durationMillis: Long,
  )

  /** Counts accumulated while one reducer invocation (fixpoint iteration) is in flight. */
  private class InFlightIterationCounts {
    var committedEdits = 0L

    // Committed edits that did not reduce the canonical token count -- i.e. non-deletion
    // transformations (e.g. vulcan identifier/subtree replacement that rewrites without shrinking).
    var nonDeletionEdits = 0L

    // Completed test-script executions, counted exactly as ProgressMonitorForNodeReducer counts
    // "#test success"/"#test failure" (one per onTestScriptExecution). This is deterministic, unlike
    // the executor's raw scriptExecutionNumber, which also counts speculative executions that get
    // cancelled (a run-varying amount) and so cannot appear in a golden-compared table.
    var completedTestExecutions = 0L
  }

  /**
   * Commit-derived statistics for one named transformation (keyed "<reducer>.<transformation>").
   * Only the commit-derived columns are tracked: a reducer that runs named sub-transformations does
   * so within a single fixpoint iteration, so Times/Queries/Duration stay per-reducer in [Summary].
   */
  private class TransformationStatistics {
    var committedEdits = 0L
    var nonDeletionEdits = 0L
    var canonicalTokenDelta = 0L
    var nonBlankCharacterDelta = 0L
  }

  // One row per reducer invocation, in chronological order. Single-threaded event dispatch (see
  // AsyncReductionListenerManager) means no synchronization is needed.
  private val invocationRecords = mutableListOf<ReducerInvocationRecord>()

  // Counts for an in-flight iteration, keyed by the identity of its start event; drained when that
  // iteration ends. Dispatch is serial, so at most one is ever in flight, but keying by identity
  // keeps best-program attribution exact regardless.
  private val countsByStartEvent =
    IdentityHashMap<FixpointIterationStartEvent, InFlightIterationCounts>()

  // The iteration currently in flight. Test-script-execution events do not reference their iteration,
  // so they are attributed to this; null outside an iteration (e.g. during the initial sanity check),
  // so those executions are correctly not counted against any reducer.
  private var currentInFlightStartEvent: FixpointIterationStartEvent? = null

  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    countsByStartEvent[event] = InFlightIterationCounts()
    currentInFlightStartEvent = event
  }

  override fun onTestScriptExecution(
    event: AbstractTestScriptExecutionEvent.TestScriptExecutionEvent,
  ) {
    currentInFlightStartEvent?.let { countsByStartEvent.getValue(it).completedTestExecutions += 1 }
  }

  // Per-transformation statistics, keyed "<reducer>.<transformation>". Every committed edit carries a
  // transformation name (a named sub-transformation for astra/latra, else its operation kind), so all
  // reducers appear here. Insertion order is stable; the printed table is sorted explicitly.
  private val transformationStatisticsByKey = LinkedHashMap<String, TransformationStatistics>()

  override fun onBestProgramUpdated(event: BestProgramUpdateEvent) {
    // Fires on every committed spar-tree edit (see AbstractProgramReductionDriver's edit listener),
    // not only size-shrinking ones, so the before/after token counts classify each commit as a
    // deletion or a non-deletion.
    val isNonDeletion =
      event.programSizeAfter.canonicalTokenCount >= event.programSizeBefore.canonicalTokenCount
    val counts =
      countsByStartEvent.getOrPut(event.currentFixpointIteration) {
        InFlightIterationCounts()
      }
    counts.committedEdits += 1
    if (isNonDeletion) {
      counts.nonDeletionEdits += 1
    }

    val transformationName = event.appliedEdit.actionSet.transformationName
    val key = "${event.currentFixpointIteration.reducerClass.shortName}.$transformationName"
    val statistics = transformationStatisticsByKey.getOrPut(key) { TransformationStatistics() }
    statistics.committedEdits += 1
    if (isNonDeletion) {
      statistics.nonDeletionEdits += 1
    }
    statistics.canonicalTokenDelta +=
      (event.programSizeAfter.canonicalTokenCount - event.programSizeBefore.canonicalTokenCount)
        .toLong()
    statistics.nonBlankCharacterDelta +=
      (
        event.programSizeAfter.nonBlankCharacterCount -
          event.programSizeBefore.nonBlankCharacterCount
      ).toLong()
  }

  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    val startEvent = event.startEvent
    val sizeBefore = startEvent.perFileSizeMetrics
    val sizeAfter = event.perFileSizeMetrics
    val counts = countsByStartEvent.remove(startEvent) ?: InFlightIterationCounts()
    currentInFlightStartEvent = null
    invocationRecords.add(
      ReducerInvocationRecord(
        id = invocationRecords.size,
        reducerName = startEvent.reducerClass.shortName,
        improvementCount = counts.committedEdits,
        nonDeletionCount = counts.nonDeletionEdits,
        canonicalTokenDelta =
          (sizeAfter.totalCanonicalTokenCount - sizeBefore.totalCanonicalTokenCount).toLong(),
        nonBlankCharacterDelta =
          (sizeAfter.totalNonBlankCharacterCount - sizeBefore.totalNonBlankCharacterCount).toLong(),
        testScriptExecutionCount = counts.completedTestExecutions,
        durationMillis = event.currentTimeMillis - startEvent.currentTimeMillis,
      ),
    )
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    val report = buildReport()
    dedicatedStream.println(report)
    additionalSinks.forEach { sink -> sink(report) }
  }

  override fun close() {
    dedicatedStream.close()
  }

  private fun buildReport(): String {
    val width = 80
    return buildString {
      appendLine(
        " Reduction History and Statistics ".padBothEnds(desiredLength = width, padChar = '-'),
      )
      appendLine(" History ".padBothEnds(desiredLength = width, padChar = '-'))
      appendLine(TableForTextPrinting(buildHistoryTable()).print())
      appendLine()
      appendLine(" Summary ".padBothEnds(desiredLength = width, padChar = '-'))
      appendLine(TableForTextPrinting(buildSummaryTable()).print())
      // Only reducers that run named sub-transformations (astra/latra today) populate this, so the
      // section is omitted entirely when no commit carried a transformation name.
      if (transformationStatisticsByKey.isNotEmpty()) {
        appendLine()
        appendLine(" Transformations ".padBothEnds(desiredLength = width, padChar = '-'))
        appendLine(TableForTextPrinting(buildTransformationTable()).print())
      }
      append(" End ".padBothEnds(desiredLength = width, padChar = '-'))
    }
  }

  private fun buildTransformationTable(): List<List<String>> {
    val table =
      mutableListOf(
        listOf("Transformation", "Worked", "#NonDeletions", "#Tokens", "#NonBlankChars"),
      )
    transformationStatisticsByKey.entries
      .sortedWith(compareBy({ it.value.canonicalTokenDelta }, { it.key }))
      .forEach { (key, statistics) ->
        table.add(
          listOf(
            key,
            statistics.committedEdits.toString(),
            statistics.nonDeletionEdits.toString(),
            statistics.canonicalTokenDelta.toString(),
            statistics.nonBlankCharacterDelta.toString(),
          ),
        )
      }
    return table
  }

  private fun formatDuration(millis: Long): String =
    if (hideTimestamps) "time-hidden" else (millis / 1000).toString()

  private fun buildHistoryTable(): List<List<String>> {
    val table =
      mutableListOf(
        listOf(
          "ID",
          "Reducer",
          "Worked",
          "#NonDeletions",
          "#Tokens",
          "#NonBlankChars",
          "Queries",
          "Duration(sec)",
        ),
      )
    invocationRecords.forEach { record ->
      table.add(
        listOf(
          record.id.toString(),
          record.reducerName,
          record.improvementCount.toString(),
          record.nonDeletionCount.toString(),
          record.canonicalTokenDelta.toString(),
          record.nonBlankCharacterDelta.toString(),
          record.testScriptExecutionCount.toString(),
          formatDuration(record.durationMillis),
        ),
      )
    }
    return table
  }

  private fun buildSummaryTable(): List<List<String>> {
    val table =
      mutableListOf(
        listOf(
          "Reducer",
          "Times",
          "Worked",
          "#NonDeletions",
          "#Tokens",
          "#NonBlankChars",
          "Queries",
          "Duration(sec)",
        ),
      )
    invocationRecords
      .groupBy { it.reducerName }
      .map { (reducerName, records) ->
        SummaryRow(
          reducerName = reducerName,
          times = records.size.toLong(),
          improvementCount = records.sumOf { it.improvementCount },
          nonDeletionCount = records.sumOf { it.nonDeletionCount },
          canonicalTokenDelta = records.sumOf { it.canonicalTokenDelta },
          nonBlankCharacterDelta = records.sumOf { it.nonBlankCharacterDelta },
          testScriptExecutionCount = records.sumOf { it.testScriptExecutionCount },
          durationMillis = records.sumOf { it.durationMillis },
        )
      }
      // Most-reducing reducer first (most negative token delta), mirroring c-vise's "bytes reduced"
      // ordering; ties broken by name so the table is deterministic for golden comparison.
      .sortedWith(compareBy({ it.canonicalTokenDelta }, { it.reducerName }))
      .forEach { row ->
        table.add(
          listOf(
            row.reducerName,
            row.times.toString(),
            row.improvementCount.toString(),
            row.nonDeletionCount.toString(),
            row.canonicalTokenDelta.toString(),
            row.nonBlankCharacterDelta.toString(),
            row.testScriptExecutionCount.toString(),
            formatDuration(row.durationMillis),
          ),
        )
      }
    return table
  }

  private class SummaryRow(
    val reducerName: String,
    val times: Long,
    val improvementCount: Long,
    val nonDeletionCount: Long,
    val canonicalTokenDelta: Long,
    val nonBlankCharacterDelta: Long,
    val testScriptExecutionCount: Long,
    val durationMillis: Long,
  )
}
