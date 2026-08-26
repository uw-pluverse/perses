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
package org.perses.listminimizer.microbenchmark

import com.google.common.annotations.VisibleForTesting
import org.perses.listminimizer.AbstractListMinimizer
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.Candidate
import org.perses.listminimizer.ElementWrapper
import org.perses.listminimizer.IWeightProvider
import org.perses.reduction.CandidateOutcome
import org.perses.util.IoUtil
import org.perses.util.Serialization
import org.perses.util.TimeSpan
import java.io.PrintStream
import java.nio.file.Path
import kotlin.reflect.KClass

/**
 * Records what a list minimizer did, as two JSON Lines files meant to be concatenated across a
 * corpus and read by the analysis scripts.
 *
 * This is a listener rather than instrumentation inside the minimizers because the four callbacks
 * already carry everything the metrics need, so measuring an algorithm does not modify it -- and a
 * newly added minimizer is measurable without being told about this class.
 *
 * The fields are deliberately limited to what a listener can *observe*. Whether the final result
 * is still interesting, and whether it is 1-minimal, are answers only the oracle can give; they
 * belong to the evaluation runner that owns one, not here.
 *
 * TODO(cnsun): revisit this field set once the whole pipeline is in place. It was chosen before
 * the runner and the analysis scripts existed, so which fields actually discriminate between
 * minimizers -- and which features a hybrid dispatcher would need -- is still a guess.
 */
class ListMinimizerMetricsCollector(
  private val microbenchmarkId: String,
  /**
   * The same provider the minimizer was given, so `deletedWeight` is in the units the weighted
   * minimizers actually optimized. Elements arrive as [Any] because the listener API is
   * type-erased; the caller knows the element type and casts.
   */
  private val weightProvider: IWeightProvider<Any>,
  /**
   * Report every duration as null instead of a measurement, from `--hide-timestamps`.
   *
   * Durations are the only nondeterministic fields these files carry, so suppressing them makes
   * both byte-for-byte reproducible and therefore goldenable. Null rather than a placeholder like
   * the statistics summary's "time-hidden": the fields stay numeric, so a reader never has to
   * special-case a sentinel, and `pandas` reads them as NaN.
   */
  private val hideTimings: Boolean,
  /**
   * The [org.perses.listminimizer.EnumListMinimizerType] name, i.e. what `--evaluation-minimizer`
   * was given. Reported alongside the minimizer's qualified class name because they answer
   * different questions: this is the dimension a sweep groups by, the class name is what ran.
   */
  private val minimizerTypeName: String,
  /**
   * How many test scripts the executor has run for this measurement, read at [endReduction].
   *
   * A listener cannot see this -- it is the executor's statistic, owned by the driver -- so it
   * arrives as a supplier rather than being written to a second file by the caller. It is the
   * executor's cumulative total; this class brackets it across the minimizer's lifetime, so that it
   * covers the same window as the observed queries and the two stay comparable. Bracketing it
   * anywhere earlier would include the driver's own pre-reducer script executions, which are not
   * queries -- and a constant offset would defeat the comparison this field exists for.
   */
  private val scriptExecutionCountSupplier: () -> Int,
  queryJsonlFile: Path,
  summaryJsonlFile: Path,
) : AbstractListMinimizerListener() {
  private val queryStream = IoUtil.createNonAppendablePrintStream(path = queryJsonlFile)
  private val summaryStream = IoUtil.createNonAppendablePrintStream(path = summaryJsonlFile)

  private lateinit var minimizerName: String
  private lateinit var timeSpanBuilder: TimeSpan.Builder
  private var originalElementCount = 0
  private var originalWeight = 0
  private var querySeq = 0
  private var interestingCount = 0
  private var uninterestingCount = 0
  private var totalOracleMillis = 0L
  private var scriptExecutionsAtStart = 0

  /**
   * How many property tests this listener saw during the current reduction. A caller that also
   * knows how many scripts actually ran can compare the two and detect queries that never reached
   * a listener at all.
   */
  val observedQueryCount: Int
    get() = querySeq

  /**
   * How many minimizer runs this listener saw complete. A measurement is of one minimizer on one
   * list, so a caller can assert this is exactly 1: every run past the first silently appends
   * another well-formed `summary.jsonl` record -- the per-run fields are reset in [startReduction] -- so
   * a fixpoint that crept back would double-count rather than fail.
   */
  var completedReductionCount = 0
    private set

  /**
   * The query at which the best last improved. Together with the total query count this separates a
   * minimizer that converged early and then spent its budget confirming 1-minimality from one that
   * was still making progress when it stopped.
   */
  private var querySeqOfLastBestUpdate = 0

  override fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    descriptionPrefix: String,
  ) {
    minimizerName = listMinimizerClass.qualifiedName!!
    timeSpanBuilder = TimeSpan.Builder.start(nowInMillis = System.currentTimeMillis())
    originalElementCount = originalInput.size
    originalWeight = weightOf(elements = originalInput)
    querySeq = 0
    interestingCount = 0
    uninterestingCount = 0
    totalOracleMillis = 0
    querySeqOfLastBestUpdate = 0
    scriptExecutionsAtStart = scriptExecutionCountSupplier()
  }

  override fun onPropertyTest(
    configuration: Candidate<*>,
    result: CandidateOutcome<*>,
    sizeOfOriginalList: Int,
    sizeOfCurrentMinimizationResult: Int,
  ) {
    ++querySeq
    val deleted = configuration.deletedWrappers
    // Interesting or not -- there is no third outcome, and the result hierarchy now says so: every
    // way of not surviving is a CandidateOutcome.Uninteresting.
    val outcome =
      if (result is CandidateOutcome.Interesting) {
        ++interestingCount
        "interesting"
      } else {
        ++uninterestingCount
        "uninteresting"
      }
    // Cost is orthogonal to outcome, so it comes from the oracle verdict rather than from which
    // branch above was taken: a rejected candidate is the expensive case, and an interesting one
    // can be free (deleting nothing runs no script).
    val testScriptVerdict = result.testScriptVerdict
    val elapsedMillis =
      if (testScriptVerdict != null) {
        totalOracleMillis += testScriptVerdict.elapsedMillis
        // Null under [hideTimings] too. The two are not worth distinguishing: when durations
        // are suppressed, no cost in the file means anything.
        if (hideTimings) null else testScriptVerdict.elapsedMillis
      } else {
        // Null rather than zero: a query that ran no script has no cost to report, and a zero
        // would be averaged in as if the script had run instantly.
        null
      }
    printRecord(
      stream = queryStream,
      record =
        QueryRecord(
          microbenchmarkId = microbenchmarkId,
          minimizer = minimizerName,
          querySeq = querySeq,
          outcome = outcome,
          bestSizeBefore = sizeOfCurrentMinimizationResult,
          deletedCount = deleted.size,
          deletedWeight = weightOf(elements = deleted),
          deletedRunCount = clusterIdsIntoRanges(deleted).size,
          minElementIndex = deleted.minOfOrNull { it.index },
          maxElementIndex = deleted.maxOfOrNull { it.index },
          elapsedMillis = elapsedMillis,
        ),
    )
  }

  override fun onBestUpdate(newBest: List<ElementWrapper<*>>) {
    querySeqOfLastBestUpdate = querySeq
  }

  override fun endReduction(
    minimizationResult: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    sizeOfOriginalInput: Int,
  ) {
    ++completedReductionCount
    printRecord(
      stream = summaryStream,
      record =
        RunSummaryRecord(
          microbenchmarkId = microbenchmarkId,
          minimizer = minimizerName,
          minimizerType = minimizerTypeName,
          originalElementCount = originalElementCount,
          originalWeight = originalWeight,
          resultElementCount = minimizationResult.size,
          resultWeight = weightOf(elements = minimizationResult),
          totalQueries = querySeq,
          interestingCount = interestingCount,
          uninterestingCount = uninterestingCount,
          querySeqOfLastBestUpdate = querySeqOfLastBestUpdate,
          totalOracleMillis = if (hideTimings) null else totalOracleMillis,
          wallClockMillis =
            timeSpanBuilder
              .end(nowInMillis = System.currentTimeMillis())
              .elapsedTimeInMillis
              .takeUnless { hideTimings },
          scriptExecutionCount = scriptExecutionCountSupplier() - scriptExecutionsAtStart,
        ),
    )
  }

  /**
   * Discarded. Rendering the human-readable trace is ListMinimizerProgressListener's job, and free
   * text written into either stream here would corrupt the record stream. Both listeners can observe the same
   * run via [AbstractListMinimizerListener.smartCombine].
   */
  override fun log(msg: () -> String) {
  }

  override fun close() {
    queryStream.use {
      summaryStream.close()
    }
  }

  private fun weightOf(elements: List<ElementWrapper<*>>) =
    elements.sumOf { weightProvider.weight(it.element) }

  /** One property test. */
  data class QueryRecord(
    val microbenchmarkId: String,
    val minimizer: String,
    val querySeq: Int,
    val outcome: String,
    val bestSizeBefore: Int,
    val deletedCount: Int,
    val deletedWeight: Int,
    /**
     * How many maximal runs of consecutive indices the attempt spans: 1 means a contiguous chunk, n
     * means n scattered elements. The distinction is the whole difference between ddmin-style and
     * slicing-style attempts, and is invisible in [deletedCount] alone.
     */
    val deletedRunCount: Int,
    val minElementIndex: Int?,
    val maxElementIndex: Int?,
    /**
     * Null when no cost was measured: no script ran (the candidate was already cached, no edit
     * could be built, or the deletion was empty), or [hideTimings] is set. A candidate the oracle
     * ran and rejected reports its real cost here.
     */
    val elapsedMillis: Int?,
  )

  /** One completed minimizer run. */
  data class RunSummaryRecord(
    val microbenchmarkId: String,
    /** The minimizer's qualified class name. `queries.jsonl` joins to this. */
    val minimizer: String,
    /** The `--evaluation-minimizer` value, e.g. `WINDOWED_SLICER`. */
    val minimizerType: String,
    val originalElementCount: Int,
    val originalWeight: Int,
    val resultElementCount: Int,
    val resultWeight: Int,
    val totalQueries: Int,
    val interestingCount: Int,
    val uninterestingCount: Int,
    val querySeqOfLastBestUpdate: Int,
    /**
     * Summed over every query whose oracle actually ran, rejections included, so this is the real
     * script cost of the run rather than the cost of its successes.
     */
    val totalOracleMillis: Long?,
    val wallClockMillis: Long?,
    /**
     * Every query runs a script except one that deletes nothing, so this should equal
     * [totalQueries] plus those shortcuts. *Fewer* observed queries than script executions means
     * queries never reached the listener -- a minimizer that enabled its own config cache, say --
     * and therefore a `queries.jsonl` that undercounts.
     */
    val scriptExecutionCount: Int,
  )

  companion object {
    const val QUERY_JSONL_FILE_NAME = "queries.jsonl"
    const val SUMMARY_JSONL_FILE_NAME = "summary.jsonl"

    /**
     * One JSON object per line (JSON Lines), rather than a CSV row or one JSON document per file.
     *
     * A record carries its own field names, so the two hand-synchronized lists a CSV needs -- a
     * header and a row that must stay in the same order -- collapse into one data class that cannot
     * drift; and a field holding a comma or a quote can no longer corrupt the file, which a
     * hand-joined row could.
     *
     * Line-delimited rather than a JSON array because these files are shards: a sweep runs one
     * process per (microbenchmark, minimizer) and concatenates the results, and only this form
     * survives `cat`. It is also what `pandas.read_json(..., lines=True)` reads directly.
     */
    @VisibleForTesting
    internal fun printRecord(
      stream: PrintStream,
      record: Any,
    ) {
      stream.println(Serialization.toJsonString(record))
    }
  }
}
