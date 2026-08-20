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

import com.beust.jcommander.Parameter
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import java.nio.file.Files
import java.nio.file.Path

/**
 * Records list-minimization problems from a real reduction, and evaluates one minimizer against one
 * recorded problem. See `internal_doc/list_minimizer_microbenchmarking.md`.
 *
 * A group of its own rather than more knobs on [ProfilingFlagGroup]: this is a self-contained
 * research feature with its own validation rules, and that group is already ten unrelated dump-file
 * paths.
 */
class ListMinimizerMicrobenchmarkingFlagGroup :
  AbstractCommandLineFlagGroup(groupName = "List Minimizer Microbenchmarking") {
  @Parameter(
    names = ["--list-minimizer-microbenchmarking-mode"],
    description =
      "RECORD captures each list minimization problem encountered. EVALUATE runs one minimizer " +
        "against one recorded problem and reports its cost and result. Unset (the default) runs " +
        "a normal reduction.",
    order = 0,
  )
  var mode: EnumListMinimizerMicrobenchmarkingMode? = null

  @Parameter(
    names = ["--list-minimizer-microbenchmark-output"],
    description = "RECORD: the directory to write recorded microbenchmarks to, one folder each.",
    order = 10,
  )
  var microbenchmarkOutputDirectory: Path? = null

  @Parameter(
    names = ["--min-list-size-to-record"],
    description =
      "RECORD: skip problems whose list is shorter than this. Lists of one or two elements " +
        "leave a minimizer no room to differ, so they say nothing about which one to prefer.",
    order = 20,
  )
  var minListSizeToRecord = DEFAULT_MIN_LIST_SIZE_TO_RECORD

  @Parameter(
    names = ["--max-microbenchmarks-to-record"],
    description = "RECORD: stop recording after this many microbenchmarks. Unset means no bound.",
    order = 30,
  )
  var maxMicrobenchmarksToRecord: Int? = null

  @Parameter(
    names = ["--evaluation-microbenchmark"],
    description = "EVALUATE: the microbenchmark.yaml of the recorded problem to evaluate.",
    order = 40,
  )
  var microbenchmarkFile: Path? = null

  @Parameter(
    names = ["--evaluation-minimizer"],
    description = "EVALUATE: the list minimizer to evaluate. Exactly one per invocation.",
    order = 50,
  )
  var minimizerUnderEvaluation: EnumListMinimizerType? = null

  @Parameter(
    names = ["--evaluation-output"],
    description = "EVALUATE: the directory to write the metrics CSVs to.",
    order = 60,
  )
  var evaluationOutputDirectory: Path? = null

  override fun validate() {
    when (mode) {
      null -> checkNoModeSpecificFlagIsSet()
      EnumListMinimizerMicrobenchmarkingMode.RECORD -> validateRecordMode()
      EnumListMinimizerMicrobenchmarkingMode.EVALUATE -> validateEvaluateMode()
    }
  }

  /**
   * Without this, `--list-minimizer-microbenchmark-output` on its own would run an ordinary reduction and
   * leave an empty directory -- the silent no-op that moving the switch onto a mode flag introduces.
   */
  private fun checkNoModeSpecificFlagIsSet() {
    val setFlags =
      buildList {
        microbenchmarkOutputDirectory?.let { add("--list-minimizer-microbenchmark-output") }
        maxMicrobenchmarksToRecord?.let { add("--max-microbenchmarks-to-record") }
        microbenchmarkFile?.let { add("--evaluation-microbenchmark") }
        minimizerUnderEvaluation?.let { add("--evaluation-minimizer") }
        evaluationOutputDirectory?.let { add("--evaluation-output") }
        if (minListSizeToRecord != DEFAULT_MIN_LIST_SIZE_TO_RECORD) {
          add("--min-list-size-to-record")
        }
      }
    check(setFlags.isEmpty()) {
      "$setFlags require --list-minimizer-microbenchmarking-mode, which is unset, so they " +
        "would have no effect."
    }
  }

  private fun validateRecordMode() {
    check(microbenchmarkOutputDirectory != null) {
      "RECORD requires --list-minimizer-microbenchmark-output."
    }
    check(minListSizeToRecord >= 1) {
      "--min-list-size-to-record must be at least 1, but is $minListSizeToRecord."
    }
    maxMicrobenchmarksToRecord?.let {
      check(it > 0) { "--max-microbenchmarks-to-record must be positive, but is $it." }
    }
    checkEvaluateFlagsAreUnset()
  }

  private fun validateEvaluateMode() {
    val problem = microbenchmarkFile
    check(problem != null) { "EVALUATE requires --evaluation-microbenchmark." }
    check(Files.isRegularFile(problem)) {
      "The problem file $problem is not a file."
    }
    check(minimizerUnderEvaluation != null) {
      "EVALUATE requires --evaluation-minimizer."
    }
    check(evaluationOutputDirectory != null) {
      "EVALUATE requires --evaluation-output."
    }
    check(microbenchmarkOutputDirectory == null && maxMicrobenchmarksToRecord == null) {
      "RECORD flags cannot be combined with --list-minimizer-microbenchmarking-mode EVALUATE."
    }
  }

  private fun checkEvaluateFlagsAreUnset() {
    check(
      microbenchmarkFile == null &&
        minimizerUnderEvaluation == null &&
        evaluationOutputDirectory == null,
    ) {
      "EVALUATE flags cannot be combined with --list-minimizer-microbenchmarking-mode RECORD."
    }
  }

  companion object {
    /**
     * Small lists barely distinguish one algorithm from another -- a one-element list offers a
     * single decision -- and they dominate a real corpus: recording clang-22382 at a threshold of
     * 4 yielded 50 of its 71 problems with exactly 4 elements, so most of that corpus could not
     * answer the question it was recorded for.
     */
    const val DEFAULT_MIN_LIST_SIZE_TO_RECORD = 6
  }
}
