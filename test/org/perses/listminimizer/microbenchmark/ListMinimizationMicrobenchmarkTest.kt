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
import org.perses.util.FileSystemUtil
import org.perses.util.Interval
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ListMinimizationMicrobenchmarkTest {
  private val tempDir = FileSystemUtil.createTempDirForObject(this)

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
    assertThat(
      yaml,
    ).contains("tokenOffsets: \"0:3 4:5 6:7 8:9 10:11 12:13 14:15 16:17 18:19 20:21\"")
    assertThat(yaml).contains("leftInclusive: 1")
  }

  @Test
  fun testDerivedCounts() {
    val microbenchmark = createMicrobenchmark()

    assertThat(microbenchmark.inputList.elementCount).isEqualTo(2)
    assertThat(microbenchmark.tokenCount).isEqualTo(10)
    // The second element owns two non-contiguous runs, as a multi-node element does.
    assertThat(microbenchmark.inputList.elements[1].tokenRanges).hasSize(2)
    assertThat(
      microbenchmark.inputList.elements.map { it.tokenCount },
    ).containsExactly(1, 3).inOrder()
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
              RecordedElement(ImmutableList.of(Interval(1, 8))),
              // Nested inside the first element, as a parser node inside its ancestor would be.
              RecordedElement(ImmutableList.of(Interval(3, 5))),
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
              RecordedElement(ImmutableList.of(Interval(7, 9))),
              RecordedElement(ImmutableList.of(Interval(1, 3))),
            ),
          ),
      )
    assertThat(descending.inputList.elementsAreDisjoint).isTrue()
    assertThat(descending.inputList.elementsAreOffsetAscending).isFalse()
  }

  @Test
  fun testARecordingWithoutTheTokenizationIsRejected() {
    val microbenchmarkFile =
      tempDir.resolve(ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME)
    createMicrobenchmark().writeTo(microbenchmarkFile)
    microbenchmarkFile.writeText(
      microbenchmarkFile
        .readText()
        .lines()
        .filterNot { it.startsWith("tokenOffsets:") }
        .joinToString("\n"),
    )

    val failure =
      assertThrows(Exception::class.java) {
        ListMinimizationMicrobenchmark.readFrom(microbenchmarkFile)
      }
    assertThat(failure).hasMessageThat().contains("tokenOffsets")
  }

  @Test
  fun testTheTokenizationMustBeAscendingDisjointAndCoverEveryElement() {
    assertThrows(IllegalArgumentException::class.java) {
      createMicrobenchmark().copy(tokenOffsets = ImmutableList.of(Interval(0, 3), Interval(2, 5)))
    }
    assertThrows(IllegalArgumentException::class.java) {
      createMicrobenchmark().copy(tokenOffsets = ImmutableList.of(Interval(4, 5), Interval(0, 3)))
    }
    assertThrows(IllegalArgumentException::class.java) {
      createMicrobenchmark().copy(tokenOffsets = ImmutableList.of(Interval(0, 3), Interval(4, 4)))
    }
    assertThrows(IllegalArgumentException::class.java) {
      // Ten tokens recorded, but an element reaches the eleventh.
      createMicrobenchmark().copy(
        inputList =
          RecordedInputList(
            ImmutableList.of(RecordedElement(ImmutableList.of(Interval(9, 11)))),
          ),
      )
    }
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
      // Ten tokens: a three-character one, then single characters a space apart.
      tokenOffsets =
        ImmutableList.of(
          Interval(0, 3),
          Interval(4, 5),
          Interval(6, 7),
          Interval(8, 9),
          Interval(10, 11),
          Interval(12, 13),
          Interval(14, 15),
          Interval(16, 17),
          Interval(18, 19),
          Interval(20, 21),
        ),
      inputList =
        RecordedInputList(
          ImmutableList.of(
            RecordedElement(tokenRanges = ImmutableList.of(Interval(1, 2))),
            RecordedElement(tokenRanges = ImmutableList.of(Interval(3, 5), Interval(7, 8))),
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
