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

import com.beust.jcommander.JCommander
import com.beust.jcommander.ParameterException
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
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

  /** Drives the real JCommander, which is the only thing that can answer how a flag is spelled. */
  private fun parse(vararg args: String) =
    flags().also {
      JCommander
        .newBuilder()
        .addObject(it)
        .build()
        .parse(*args)
    }

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
    ).hasMessageThat().contains("--list-minimizers-to-evaluate")

    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
        listMinimizersToEvaluate = listOf(EnumListMinimizerType.CDD)
      },
    ).hasMessageThat().contains("--evaluation-output")
  }

  @Test
  fun testEvaluateModeRejectsAMissingProblemFile() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = tempDir.resolve("absent.yaml")
        listMinimizersToEvaluate = listOf(EnumListMinimizerType.CDD)
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
        listMinimizersToEvaluate = listOf(EnumListMinimizerType.CDD)
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
        listMinimizersToEvaluate = listOf(EnumListMinimizerType.CDD)
      },
    ).hasMessageThat().contains("EVALUATE flags cannot be combined")

    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
        listMinimizersToEvaluate = listOf(EnumListMinimizerType.CDD)
        evaluationOutputDirectory = tempDir
        microbenchmarkOutputDirectory = tempDir
      },
    ).hasMessageThat().contains("RECORD flags cannot be combined")
  }

  /**
   * The comma form is not a nicety: `perses.bzl` renders a golden test's extra flags from a dict,
   * which cannot hold a repeated key, so a golden test could not name two minimizers without it.
   */
  @Test
  fun testMinimizersCanBeGivenCommaSeparated() {
    assertThat(parse("--list-minimizers-to-evaluate", "WDD,CDD").listMinimizersToEvaluate)
      .containsExactly(EnumListMinimizerType.WDD, EnumListMinimizerType.CDD)
      .inOrder()
  }

  @Test
  fun testMinimizersCanBeGivenByRepeatingTheFlag() {
    assertThat(
      parse(
        "--list-minimizers-to-evaluate",
        "WDD",
        "--list-minimizers-to-evaluate",
        "CDD",
      ).listMinimizersToEvaluate,
    ).containsExactly(EnumListMinimizerType.WDD, EnumListMinimizerType.CDD).inOrder()
  }

  @Test
  fun testNoMinimizerIsRequestedByDefault() {
    assertThat(parse().listMinimizersToEvaluate).isEmpty()
  }

  @Test
  fun testAnUnknownMinimizerIsRejectedByTheParser() {
    // The sweep script mirrors this enum as a plain list of strings, and relies on a name it got
    // wrong failing here rather than being silently dropped out of a comma-separated value.
    val failure =
      assertThrows(ParameterException::class.java) {
        parse("--list-minimizers-to-evaluate", "WDD,NOT_A_MINIMIZER")
      }
    assertThat(failure).hasMessageThat().contains("--list-minimizers-to-evaluate")
  }

  @Test
  fun testEvaluateModeAcceptsSeveralMinimizers() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
        listMinimizersToEvaluate = listOf(EnumListMinimizerType.CDD, EnumListMinimizerType.WDD)
        evaluationOutputDirectory = tempDir
      },
    ).isNull()
  }

  /** Both runs would write to the same per-minimizer directory, so only the second would survive. */
  @Test
  fun testEvaluateModeRejectsARepeatedMinimizer() {
    assertThat(
      failureOf {
        mode = EnumListMinimizerMicrobenchmarkingMode.EVALUATE
        microbenchmarkFile = this@ListMinimizerMicrobenchmarkingFlagGroupTest.microbenchmarkFile
        listMinimizersToEvaluate =
          listOf(EnumListMinimizerType.CDD, EnumListMinimizerType.WDD, EnumListMinimizerType.CDD)
        evaluationOutputDirectory = tempDir
      },
    ).hasMessageThat().contains("CDD more than once")
  }
}
