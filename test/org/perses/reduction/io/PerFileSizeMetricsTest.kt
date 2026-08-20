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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.ProgramSize
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.util.ImmutableIntArray
import org.perses.util.Util
import java.nio.file.Files
import java.nio.file.Path

@RunWith(JUnit4::class)
class PerFileSizeMetricsTest {
  private val root: Path = Util.createTempDirForObject(this)

  private fun writeFile(
    name: String,
    content: String,
  ): Path = Files.writeString(root.resolve(name), content)

  private val script = ScriptFile(writeFile("r.sh", "#!/bin/bash\ntrue\n"))
  private val fileA = SourceFile(writeFile("a.c", "int a;"), LanguageC)
  private val fileB = SourceFile(writeFile("b.c", "int b;"), LanguageC)

  private val inputs =
    DefaultLanguageOriginalReductionInputs(
      testScript = script,
      mutableFiles = ImmutableList.of(fileA, fileB),
      immutableDependencyFiles = ImmutableList.of(),
    )

  private val sizeOfA =
    ProgramSize(
      payload = Unit,
      canonicalTokenCount = 3,
      surrogateTokenCount = 5,
      totalCharacterCount = 6,
      nonBlankCharacterCount = 5,
    )

  private val sizeOfB =
    ProgramSize(
      payload = Unit,
      canonicalTokenCount = 30,
      surrogateTokenCount = 50,
      totalCharacterCount = 60,
      nonBlankCharacterCount = 50,
    )

  private val metrics = PerFileSizeMetrics(inputs, ImmutableList.of(sizeOfA, sizeOfB))

  @After
  fun cleanup() {
    root.toFile().deleteRecursively()
  }

  @Test
  fun indexOfMutableFile_returnsTheSlotOfEachMutableFile() {
    assertThat(inputs.indexOfMutableFile(fileA)).isEqualTo(0)
    assertThat(inputs.indexOfMutableFile(fileB)).isEqualTo(1)
  }

  @Test
  fun indexOfMutableFile_rejectsAFileThatIsNotMutable() {
    val foreign = SourceFile(writeFile("c.c", "int c;"), LanguageC)
    assertThrows(IllegalStateException::class.java) {
      inputs.indexOfMutableFile(foreign)
    }
  }

  @Test
  fun constructionRequiresOneSlotPerMutableFile() {
    assertThrows(IllegalStateException::class.java) {
      PerFileSizeMetrics(inputs, ImmutableList.of(sizeOfA))
    }
  }

  @Test
  fun everySlotHoldsTheSizeTheCallerProvided() {
    assertThat(metrics.sizeAt(0)).isSameInstanceAs(sizeOfA)
    assertThat(metrics.sizeAt(1)).isSameInstanceAs(sizeOfB)
    assertThat(metrics.sizeOf(fileA)).isSameInstanceAs(sizeOfA)
    assertThat(metrics.sizeOf(fileB)).isSameInstanceAs(sizeOfB)
  }

  @Test
  fun totals_sumEveryMetricAcrossAllFiles() {
    assertThat(metrics.totalCanonicalTokenCount).isEqualTo(33)
    assertThat(metrics.totalSurrogateTokenCount).isEqualTo(55)
    assertThat(metrics.totalCharacterCount).isEqualTo(66)
    assertThat(metrics.totalNonBlankCharacterCount).isEqualTo(55)
  }

  @Test
  fun replacing_updatesTheSlotOfTheGivenFileAndKeepsTheOriginalInstanceUnchanged() {
    val newSizeOfB =
      ProgramSize(
        payload = "the best program of b",
        canonicalTokenCount = 7,
        surrogateTokenCount = 8,
        totalCharacterCount = 20,
        nonBlankCharacterCount = 18,
      )

    val updated = metrics.replacing(fileB, newSizeOfB)

    assertThat(updated.sizeOf(fileB)).isSameInstanceAs(newSizeOfB)
    assertThat(updated.sizeOf(fileA)).isSameInstanceAs(sizeOfA)
    // The original instance is unchanged.
    assertThat(metrics.sizeOf(fileB)).isSameInstanceAs(sizeOfB)
  }

  @Test
  fun replacingAt_rejectsAnOutOfRangeIndex() {
    assertThrows(IllegalArgumentException::class.java) {
      metrics.replacingAt(2, sizeOfA)
    }
  }

  @Test
  fun perFileNonBlankCharacterCounts_projectsTheCacheVectorInSlotOrder() {
    val vector = metrics.perFileNonBlankCharacterCounts()

    assertThat(vector.contentEquals(ImmutableIntArray.of(5, 50))).isTrue()
  }
}
