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
package org.perses.cmd

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.util.FileSystemUtil
import kotlin.io.path.createFile
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class ListMinimizerMicrobenchmarkingFlagGroupTest {
  private val tempDir = FileSystemUtil.createTempDirForObject(this)

  private val microbenchmarkFile = tempDir.resolve("microbenchmark.yaml").apply { createFile() }

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  private fun flags() = ListMinimizerMicrobenchmarkingFlagGroup()

  /** The failure [validate] raises, or null when it accepts the flags. */
  private fun failureOf(customize: ListMinimizerMicrobenchmarkingFlagGroup.() -> Unit): Throwable? {
    val flags = flags().apply(customize)
    return try {
      flags.validate()
      null
    } catch (failure: IllegalStateException) {
      failure
    }
  }

  @Test
  fun testUnsetModeIsTheDefaultAndValidates() {
    val flags = flags()

    assertThat(flags.mode).isNull()
    assertThat(failureOf {}).isNull()
  }

  /**
   * The hazard that moving the switch onto a mode flag introduces: a path flag alone used to enable
   * the feature, and would now run an ordinary reduction and leave an empty directory.
   */
  @Test
  fun testModeSpecificFlagWithNoModeIsRejected() {
    val failure = failureOf { microbenchmarkOutputDirectory = tempDir }

    assertThat(failure).isInstanceOf(IllegalStateException::class.java)
    assertThat(failure).hasMessageThat().contains("--list-minimizer-microbenchmark-output")
    assertThat(failure).hasMessageThat().contains("would have no effect")
  }

  @Test
  fun testNonDefaultSizeThresholdWithNoModeIsRejected() {
    assertThat(failureOf { minListSizeToRecord = 9 })
      .hasMessageThat()
      .contains("--min-list-size-to-record")
  }

  @Test
  fun testRecordModeRequiresItsOutputDirectory() {
    assertThat(failureOf { mode = EnumListMinimizerMicrobenchmarkingMode.RECORD })
      .hasMessageThat()
      .contains("--list-minimizer-microbenchmark-output")
  }

  @Test
  fun testRecordModeAcceptsItsOwnFlags() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.RECORD
        microbenchmarkOutputDirectory = tempDir
        minListSizeToRecord = 2
        maxMicrobenchmarksToRecord = 100
      },
    ).isNull()
  }

  @Test
  fun testRecordModeRejectsNonPositiveThresholdAndCap() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.RECORD
        microbenchmarkOutputDirectory = tempDir
        minListSizeToRecord = 0
      },
    ).hasMessageThat().contains("at least 1")

    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.RECORD
        microbenchmarkOutputDirectory = tempDir
        maxMicrobenchmarksToRecord = 0
      },
    ).hasMessageThat().contains("must be positive")
  }

  @Test
  fun testEvaluateModeRequiresProblemMinimizerAndOutput() {
    assertThat(failureOf { mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE })
      .hasMessageThat()
      .contains("--evaluation-microbenchmark")

    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
      },
    ).hasMessageThat().contains("--evaluation-minimizer")

    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
        minimizerUnderEvaluation = EnumListMinimizerType.CDD
      },
    ).hasMessageThat().contains("--evaluation-output")
  }

  @Test
  fun testEvaluateModeRejectsAMissingProblemFile() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = tempDir.resolve("absent.yaml")
        minimizerUnderEvaluation = EnumListMinimizerType.CDD
        evaluationOutputDirectory = tempDir
      },
    ).hasMessageThat().contains("is not a file")
  }

  @Test
  fun testEvaluateModeAcceptsItsOwnFlags() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
        minimizerUnderEvaluation = EnumListMinimizerType.CDD
        evaluationOutputDirectory = tempDir
      },
    ).isNull()
  }

  /** The two directions are mutually exclusive by construction, but their flags are not. */
  @Test
  fun testFlagsOfTheOtherModeAreRejected() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.RECORD
        microbenchmarkOutputDirectory = tempDir
        minimizerUnderEvaluation = EnumListMinimizerType.CDD
      },
    ).hasMessageThat().contains("EVALUATE flags cannot be combined")

    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
        minimizerUnderEvaluation = EnumListMinimizerType.CDD
        evaluationOutputDirectory = tempDir
        microbenchmarkOutputDirectory = tempDir
      },
    ).hasMessageThat().contains("RECORD flags cannot be combined")
  }
}
