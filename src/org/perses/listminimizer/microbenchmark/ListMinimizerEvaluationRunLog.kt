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

import org.perses.listminimizer.EnumListMinimizerType
import org.perses.util.IoUtil
import org.perses.util.Serialization
import java.io.Closeable
import java.nio.file.Path

/**
 * What became of each minimizer a process was asked to measure: one JSON Lines record per
 * attempt, written to `runs.jsonl` beside the per-minimizer metrics directories.
 *
 * This is the answer to a question the metrics files cannot answer. A sweep needs to distinguish
 * "this minimizer was measured" from "this minimizer failed" from "the process never got to it",
 * and the presence of a `summary.jsonl` does not say: [ListMinimizerMetricsCollector] opens its
 * streams when it is constructed, so a run that dies mid-measurement leaves an **empty but
 * existing** file. A reader checking for the file would count that as a success.
 *
 * Every record is flushed as it is written, because the case this exists for is a sweep that was
 * killed: the minimizers already measured must still be attributable afterwards.
 */
class ListMinimizerEvaluationRunLog(
  file: Path,
  /**
   * Report every duration as null instead of a measurement, from `--hide-timestamps`. Durations are
   * the only nondeterministic field here, so suppressing them makes this file goldenable -- the
   * same trade [ListMinimizerMetricsCollector] makes, for the same reason.
   */
  private val hideTimings: Boolean,
) : Closeable {
  private val stream = IoUtil.createNonAppendablePrintStream(path = file)

  fun recordSuccess(
    minimizerType: EnumListMinimizerType,
    wallClockMillis: Long,
    oneMinimalityViolationCount: Int,
    programTokensBefore: Int,
    programTokensAfter: Int,
  ) {
    record(
      minimizerType,
      STATUS_OK,
      wallClockMillis,
      failure = null,
      oneMinimalityViolationCount = oneMinimalityViolationCount,
      programTokensBefore = programTokensBefore,
      programTokensAfter = programTokensAfter,
    )
  }

  fun recordFailure(
    minimizerType: EnumListMinimizerType,
    wallClockMillis: Long,
    failure: Throwable,
  ) {
    // The type and message, not the stack: the stack is already on the process log through
    // onCriticalException, and a record a sweep reads should stay one line.
    record(
      minimizerType,
      STATUS_FAILED,
      wallClockMillis,
      failure = "${failure::class.simpleName}: ${failure.message}",
      oneMinimalityViolationCount = null,
      programTokensBefore = null,
      programTokensAfter = null,
    )
  }

  private fun record(
    minimizerType: EnumListMinimizerType,
    status: String,
    wallClockMillis: Long,
    failure: String?,
    oneMinimalityViolationCount: Int?,
    programTokensBefore: Int?,
    programTokensAfter: Int?,
  ) {
    stream.println(
      Serialization.toJsonString(
        RunRecord(
          minimizer = minimizerType.name,
          status = status,
          wallClockMillis = wallClockMillis.takeUnless { hideTimings },
          failure = failure,
          oneMinimalityViolationCount = oneMinimalityViolationCount,
          programTokensBefore = programTokensBefore,
          programTokensAfter = programTokensAfter,
        ),
      ),
    )
    stream.flush()
  }

  override fun close() {
    stream.close()
  }

  /** One attempted measurement. */
  data class RunRecord(
    val minimizer: String,
    /** [STATUS_OK] or [STATUS_FAILED]. A minimizer never reached has no record at all. */
    val status: String,
    val wallClockMillis: Long?,
    /** The failure's type and message, or null when the measurement succeeded. */
    val failure: String?,
    /**
     * Kept elements whose removal, on its own, still satisfies the oracle: zero means the result is
     * 1-minimal. Null when the measurement failed.
     *
     * The quality axis. Several minimizers guarantee 1-minimality by construction and several do
     * not, so two results of the same size are not equally good and cost alone does not rank them.
     * Not a size delta -- see [org.perses.reduction.ListMinimizerEvaluationReducer.OneMinimalityReport].
     *
     * How large the result is belongs to summary.jsonl, which reports what the minimizer's listener
     * saw; this file reports what had to be measured afterwards, with the oracle and the tree.
     */
    val oneMinimalityViolationCount: Int?,
    /** The program's token count when the measurement started. Null when it failed. */
    val programTokensBefore: Int?,
    /** And when it finished -- the whole program, not just the kept elements' tokens. */
    val programTokensAfter: Int?,
  )

  companion object {
    const val RUN_LOG_FILE_NAME = "runs.jsonl"

    const val STATUS_OK = "ok"

    const val STATUS_FAILED = "failed"
  }
}
