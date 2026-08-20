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

import com.fasterxml.jackson.annotation.JsonIgnore
import com.fasterxml.jackson.annotation.JsonIgnoreProperties
import com.google.common.collect.ImmutableList
import org.perses.util.Interval
import org.perses.util.Serialization
import java.nio.file.Path

/**
 * One recorded microbenchmark: a program, and the input list a minimizer is measured on, whose
 * elements are character ranges into that program. Persisted as `microbenchmark.yaml` beside the
 * `input/` folder that holds the program and its test script, so the folder stays a valid Perses
 * input on its own.
 *
 * The list is reconstructible from the program alone: the evaluation side re-tokenizes the program
 * with the real lexer and resolves [RecordedElement.ranges] back to token nodes.
 */
data class ListMinimizationMicrobenchmark(
  val microbenchmarkId: String,
  /**
   * The mutable file the element ranges index into, as a path relative to the `input/` folder. A
   * base name would be ambiguous in a multi-file reduction, where two directories can hold files of
   * the same name, and would not locate a file in a subdirectory at all.
   *
   * A String rather than a [java.nio.file.Path]: Jackson absolutises a relative Path on the way out,
   * so the recording machine's working directory would be baked into every problem and the corpus
   * would not survive being moved.
   */
  val targetFilePath: String,
  val inputList: RecordedInputList,
  val recordingContext: RecordingContext,
) {
  fun writeTo(microbenchmarkFile: Path) {
    Serialization.toYamlFile(this, microbenchmarkFile)
  }

  companion object {
    const val MICROBENCHMARK_FILE_NAME = "microbenchmark.yaml"

    const val INPUT_FOLDER_NAME = "input"

    fun readFrom(microbenchmarkFile: Path): ListMinimizationMicrobenchmark =
      Serialization.fromYamlFile(microbenchmarkFile, TYPE_REFERENCE)
  }
}

/**
 * The list a minimizer is handed: what it receives as input, and the thing under measurement.
 *
 * A record of its own rather than a bare list of [elements], so the microbenchmark's own fields --
 * its id, its target file, its provenance -- stay clearly separate from what a minimizer actually
 * operates on.
 */
data class RecordedInputList(
  /** In the order the online minimizer saw them; order is part of the input. */
  val elements: ImmutableList<RecordedElement>,
) {
  // Derived values are @get:JsonIgnore throughout: Jackson would otherwise write them out and then
  // reject them as unknown properties on read.
  @get:JsonIgnore
  val elementCount: Int
    get() = elements.size

  /**
   * Whether the elements' ranges are pairwise disjoint. Nested elements are recorded on purpose, so
   * this is not an invariant -- it is worth segmenting the corpus on, because overlap changes what
   * "result size" means. Computed rather than recorded: deriving it keeps it from going stale
   * against the ranges it describes.
   */
  @get:JsonIgnore
  val elementsAreDisjoint: Boolean
    get() {
      val sorted = elements.flatMap { it.ranges }.sortedBy { it.leftInclusive }
      return sorted.zipWithNext().none { (left, right) ->
        right.leftInclusive < left.rightExclusive
      }
    }

  @get:JsonIgnore
  val elementsAreOffsetAscending: Boolean
    get() =
      elements
        .mapNotNull { element -> element.ranges.minOfOrNull { it.leftInclusive } }
        .zipWithNext()
        .all { (previous, next) -> previous <= next }
}

/**
 * One element of the list, as a set of character ranges. A set rather than a single span because
 * `runListMinimizerOverListsOfNodes` gives an element several tree nodes, which need not be
 * contiguous.
 *
 * Deliberately carries no token count. The weight the minimizers use comes from the tree the
 * evaluation builds (`NodeContainerForListMinimizer.tokenCount`), and a recorded count would be a
 * weaker integrity check than the one the ranges already support: every range boundary must
 * coincide with a token boundary, which a mismatched tokenization cannot satisfy even when the
 * counts happen to agree.
 *
 * [Interval.length] is derived, so Jackson would write it out and then reject it as unknown on read.
 * Suppressing it here rather than annotating [Interval] keeps that widely-reused leaf free of a
 * Jackson dependency.
 */
data class RecordedElement(
  @field:JsonIgnoreProperties("length")
  val ranges: ImmutableList<Interval>,
)

/**
 * The reduction that produced this problem: what is needed to interpret the recording, and what is
 * worth segmenting the corpus on during analysis.
 *
 * The first two fields are load-bearing. [languageName] and [parserFacadeClassName] select the
 * *real lexer* the FlatTokenList facade wraps, so getting them wrong tokenizes the program
 * differently; extension-based auto-detection is not enough whenever the original run overrode it,
 * and an unrecognized extension fails outright.
 *
 * The rest are labels: nothing in the evaluation reads them.
 *
 * The code format is deliberately absent. Ranges index the recorded file, and the evaluation lexes
 * that same file, so the printer that produced it does not enter range resolution. Nor can it change
 * a measurement: a minimizer's behaviour follows from the list, the token weights and the oracle's
 * answers, none of which formatting affects for the whitespace-insensitive languages in scope.
 * Recording it would be a field to keep correct for no reader. Revisit if Python or YAML come into
 * scope, where formatting is semantic.
 */
data class RecordingContext(
  val languageName: String,
  val parserFacadeClassName: String,
  val reducerClassName: String,
  /** The minimizer that actually ran online, i.e. the incumbent this problem was solved with. */
  val minimizerType: String,
  val contextDescription: String,
  val fixpointIteration: Int,
  /**
   * The perses invocation that recorded this problem: every flag and the value in force, defaults
   * included, as [org.perses.reduction.event.ReductionStartEvent.commandLineOptions] renders them.
   * Provenance -- a corpus outlives the memory of how it was made, and two corpora that differ
   * only in a flag are otherwise indistinguishable.
   */
  val commandLineOptions: String,
)

private val TYPE_REFERENCE =
  object : com.fasterxml.jackson.core.type.TypeReference<ListMinimizationMicrobenchmark>() {}
