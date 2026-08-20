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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Interval
import org.perses.util.Util
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class ListMinimizationMicrobenchmarkTest {
  private val tempDir = Util.createTempDirForObject(this)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testRoundTripThroughYamlFile() {
    val microbenchmarkFile =
      tempDir.resolve(
        ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME,
      )
    createMicrobenchmark().writeTo(microbenchmarkFile)

    assertThat(
      ListMinimizationMicrobenchmark.readFrom(microbenchmarkFile),
    ).isEqualTo(createMicrobenchmark())
  }

  @Test
  fun testYamlIsHumanReadable() {
    val microbenchmarkFile =
      tempDir.resolve(
        ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME,
      )
    createMicrobenchmark().writeTo(microbenchmarkFile)

    val yaml = microbenchmarkFile.readText()
    assertThat(yaml).contains("microbenchmarkId: \"0000\"")
    assertThat(yaml).contains("targetFilePath: \"small.c\"")
    assertThat(yaml).contains("leftInclusive: 120")
  }

  @Test
  fun testDerivedCounts() {
    val microbenchmark = createMicrobenchmark()

    assertThat(microbenchmark.inputList.elementCount).isEqualTo(2)
    // The second element owns two non-contiguous spans, as a multi-node element does.
    assertThat(microbenchmark.inputList.elements[1].ranges).hasSize(2)
  }

  @Test
  fun testIntervalInvariantIsEnforcedByIntervalItself() {
    assertThrows(IllegalArgumentException::class.java) {
      Interval(leftInclusive = 9, rightExclusive = 4)
    }
  }

  @Test
  fun testDisjointnessAndOrderingAreDerivedFromTheRanges() {
    val microbenchmark = createMicrobenchmark()
    assertThat(microbenchmark.inputList.elementsAreDisjoint).isTrue()
    assertThat(microbenchmark.inputList.elementsAreOffsetAscending).isTrue()

    val overlapping =
      microbenchmark.copy(
        inputList =
          RecordedInputList(
            ImmutableList.of(
              RecordedElement(ImmutableList.of(Interval(10, 40))),
              // Nested inside the first element, as a parser node inside its ancestor would be.
              RecordedElement(ImmutableList.of(Interval(20, 30))),
            ),
          ),
      )
    assertThat(overlapping.inputList.elementsAreDisjoint).isFalse()
    assertThat(overlapping.inputList.elementsAreOffsetAscending).isTrue()

    val descending =
      microbenchmark.copy(
        inputList =
          RecordedInputList(
            ImmutableList.of(
              RecordedElement(ImmutableList.of(Interval(50, 60))),
              RecordedElement(ImmutableList.of(Interval(10, 20))),
            ),
          ),
      )
    assertThat(descending.inputList.elementsAreDisjoint).isTrue()
    assertThat(descending.inputList.elementsAreOffsetAscending).isFalse()
  }

  @Test
  fun testDerivedIntervalLengthIsNotWrittenToYaml() {
    val microbenchmarkFile =
      tempDir.resolve(
        ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME,
      )
    createMicrobenchmark().writeTo(microbenchmarkFile)

    // Interval.length is derived; persisting it would be noise that read-back then rejects.
    assertThat(microbenchmarkFile.readText()).doesNotContain("length:")
  }

  private fun createMicrobenchmark() =
    ListMinimizationMicrobenchmark(
      microbenchmarkId = "0000",
      targetFilePath = "small.c",
      inputList =
        RecordedInputList(
          ImmutableList.of(
            RecordedElement(
              ranges = ImmutableList.of(Interval(120, 123)),
            ),
            RecordedElement(
              ranges = ImmutableList.of(Interval(900, 905), Interval(1204, 1210)),
            ),
          ),
        ),
      recordingContext =
        RecordingContext(
          languageName = "c",
          parserFacadeClassName = "org.perses.grammar.c.CParserFacade",
          reducerClassName = "TokenSlicer",
          minimizerType = "WINDOWED_SLICER",
          contextDescription = "WINDOWED_SLICER in TokenSlicer(ReducingAllTokens)",
          fixpointIteration = 3,
          commandLineOptions = "alg: \"token_slicer\"\n",
        ),
    )
}
