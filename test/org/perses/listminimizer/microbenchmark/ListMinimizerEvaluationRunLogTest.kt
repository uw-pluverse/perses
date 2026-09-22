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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.util.FileSystemUtil
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readLines

@RunWith(JUnit4::class)
class ListMinimizerEvaluationRunLogTest {
  private val tempDir = FileSystemUtil.createTempDirForObject(this)

  private val logFile = tempDir.resolve(ListMinimizerEvaluationRunLog.RUN_LOG_FILE_NAME)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  private fun createLog(hideTimings: Boolean = true) =
    ListMinimizerEvaluationRunLog(logFile, hideTimings = hideTimings)

  @Test
  fun test_a_measured_minimizer_is_recorded_as_ok_with_no_failure() {
    createLog().use {
      it.recordSuccess(
        EnumListMinimizerType.WDD,
        wallClockMillis = 12,
        oneMinimalityViolationCount = 0,
        programTokensBefore = 100,
        programTokensAfter = 5,
      )
    }

    val records = logFile.readLines()
    assertThat(records).hasSize(1)
    assertThat(records.single()).contains("\"minimizer\":\"WDD\"")
    assertThat(records.single()).contains("\"status\":\"ok\"")
    assertThat(records.single()).contains("\"failure\":null")
  }

  @Test
  fun test_a_failure_records_the_type_and_message_but_not_the_stack() {
    createLog().use {
      it.recordFailure(
        EnumListMinimizerType.CDD,
        wallClockMillis = 3,
        failure = IllegalStateException("the tree went missing"),
      )
    }

    val record = logFile.readLines().single()
    assertThat(record).contains("\"status\":\"failed\"")
    assertThat(record).contains("IllegalStateException: the tree went missing")
    assertThat(record).doesNotContain("\\n")
  }

  @Test
  fun test_one_line_per_attempt_in_the_order_they_were_attempted() {
    createLog().use {
      it.recordSuccess(
        EnumListMinimizerType.WDD,
        wallClockMillis = 1,
        oneMinimalityViolationCount = 0,
        programTokensBefore = 100,
        programTokensAfter = 5,
      )
      it.recordFailure(EnumListMinimizerType.CDD, wallClockMillis = 2, failure = Exception("no"))
      it.recordSuccess(
        EnumListMinimizerType.DFS,
        wallClockMillis = 3,
        oneMinimalityViolationCount = 0,
        programTokensBefore = 100,
        programTokensAfter = 5,
      )
    }

    assertThat(
      logFile.readLines().map { it.substringAfter("\"minimizer\":\"").substringBefore('"') },
    ).containsExactly("WDD", "CDD", "DFS")
      .inOrder()
  }

  /**
   * The case this class exists for. A sweep that is killed mid-problem must still account for the
   * minimizers it had already measured, which it can only do if each record reached the file when
   * it was written rather than when the log was closed.
   */
  @Test
  fun test_every_record_is_readable_before_the_log_is_closed() {
    createLog().use { log ->
      log.recordSuccess(
        EnumListMinimizerType.WDD,
        wallClockMillis = 1,
        oneMinimalityViolationCount = 0,
        programTokensBefore = 100,
        programTokensAfter = 5,
      )
      assertThat(logFile.readLines()).hasSize(1)

      log.recordSuccess(
        EnumListMinimizerType.CDD,
        wallClockMillis = 2,
        oneMinimalityViolationCount = 0,
        programTokensBefore = 100,
        programTokensAfter = 5,
      )
      assertThat(logFile.readLines()).hasSize(2)
    }
  }

  /**
   * The quality axis, and the reason it is recorded separately from the result size: two results of
   * the same size are not equally good if one of them is keeping elements nothing needs.
   */
  @Test
  fun test_a_result_that_is_not_one_minimal_is_recorded_as_such() {
    createLog().use {
      it.recordSuccess(
        EnumListMinimizerType.WINDOWED_SLICER,
        wallClockMillis = 5,
        oneMinimalityViolationCount = 2,
        programTokensBefore = 300,
        programTokensAfter = 42,
      )
    }

    val record = logFile.readLines().single()
    assertThat(record).contains("\"oneMinimalityViolationCount\":2")
    assertThat(record).contains("\"programTokensBefore\":300")
    assertThat(record).contains("\"programTokensAfter\":42")
  }

  /** A failed measurement produced no result, so it has no size and no 1-minimality to report. */
  @Test
  fun test_a_failed_measurement_reports_no_result_size() {
    createLog().use {
      it.recordFailure(EnumListMinimizerType.CDD, wallClockMillis = 1, failure = Exception("no"))
    }

    val record = logFile.readLines().single()
    assertThat(record).contains("\"oneMinimalityViolationCount\":null")
    assertThat(record).contains("\"programTokensAfter\":null")
  }

  @Test
  fun test_durations_are_reported_when_timestamps_are_not_hidden() {
    createLog(hideTimings = false).use {
      it.recordSuccess(
        EnumListMinimizerType.WDD,
        wallClockMillis = 42,
        oneMinimalityViolationCount = 0,
        programTokensBefore = 100,
        programTokensAfter = 5,
      )
    }

    assertThat(logFile.readLines().single()).contains("\"wallClockMillis\":42")
  }

  /** Nulled rather than omitted, so the field set does not depend on the flag. */
  @Test
  fun test_durations_are_null_when_timestamps_are_hidden() {
    createLog(hideTimings = true).use {
      it.recordSuccess(
        EnumListMinimizerType.WDD,
        wallClockMillis = 42,
        oneMinimalityViolationCount = 0,
        programTokensBefore = 100,
        programTokensAfter = 5,
      )
    }

    assertThat(logFile.readLines().single()).contains("\"wallClockMillis\":null")
  }
}
