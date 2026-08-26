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
package org.perses.reduction.event

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.ProgramSize
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import org.perses.util.FileSystemUtil
import java.nio.file.Files

@RunWith(JUnit4::class)
class EventsTest {
  private val root = FileSystemUtil.createTempDirForObject(this)
  private val script = ScriptFile(Files.writeString(root.resolve("r.sh"), "#!/bin/bash\ntrue\n"))
  private val sourceFile = SourceFile(Files.writeString(root.resolve("a.c"), "int a;"), LanguageC)
  private val originalReductionInputs =
    DefaultLanguageOriginalReductionInputs(
      testScript = script,
      mutableFiles = ImmutableList.of(sourceFile),
      immutableDependencyFiles = ImmutableList.of(),
    )

  private fun metrics(tokenCount: Int): PerFileSizeMetrics =
    PerFileSizeMetrics(
      originalReductionInputs,
      ImmutableList.of(
        ProgramSize(
          payload = Unit,
          canonicalTokenCount = tokenCount,
          surrogateTokenCount = tokenCount,
          totalCharacterCount = 0,
          nonBlankCharacterCount = 0,
        ),
      ),
    )

  private val initialMetrics = metrics(3)

  private val tree = TestUtility.createSparTreeFromString("int a;", LanguageC)

  private val reductionStartEvent =
    ReductionStartEvent(
      currentTimeMillis = System.currentTimeMillis(),
      perFileSizeMetrics = initialMetrics,
      commandLineOptions = "<cmd>",
    )

  val firstIterationStart =
    reductionStartEvent.nextFixpointIteration(
      perFileSizeMetrics = metrics(2),
      reducerClass = ConcurrentTokenSlicer.getAnnotationForGranularity(granularity = 1),
      treeStructureDumper = { tree.printTreeStructure() },
      TestScriptExecutorServiceStatisticsSnapshot(
        scriptExecutionNumber = 1,
        externalCacheHitNumber = 0,
      ),
    )

  val nodeReductionStartEvent =
    firstIterationStart.createNodeReductionStartEvent(
      currentTimeMillis = System.currentTimeMillis(),
      perFileSizeMetrics = metrics(2),
      program = tree.programSnapshot,
      node = tree.realRoot,
      outputCreator = { ImmutableList.of() },
    )

  val nodeReductionEndEvent =
    nodeReductionStartEvent.createEndEvent(
      currentTimeMillis = System.currentTimeMillis(),
      perFileSizeMetrics = metrics(2),
      remainingQueueSize = 1000,
    )

  val firstIterationEnd =
    firstIterationStart.createEndEvent(
      currentTimeMillis = System.currentTimeMillis(),
      perFileSizeMetrics = metrics(2),
      testScriptStatistics =
        TestScriptExecutorServiceStatisticsSnapshot(
          scriptExecutionNumber = 2,
          externalCacheHitNumber = 2,
        ),
    )

  val reductionEndEvent =
    reductionStartEvent.createEndEvent(
      perFileSizeMetrics = metrics(1),
      testScriptStatistics =
        TestScriptExecutorServiceStatisticsSnapshot(
          scriptExecutionNumber = 100 + 2,
          externalCacheHitNumber = 2,
        ),
    )

  @After
  fun cleanup() {
    root.toFile().deleteRecursively()
  }

  @Test
  fun testReductionStartEvent() {
    assertThat(reductionStartEvent.initialPerFileSizeMetrics()).isSameInstanceAs(initialMetrics)
    assertThat(reductionStartEvent.perFileSizeMetrics)
      .isSameInstanceAs(reductionStartEvent.initialPerFileSizeMetrics())
  }

  @Test
  fun testNodeReductionStartEvent() {
    assertThat(nodeReductionStartEvent.initialPerFileSizeMetrics()).isSameInstanceAs(initialMetrics)
  }

  @Test
  fun testNodeReductionEndEvent() {
    assertThat(nodeReductionEndEvent.initialPerFileSizeMetrics()).isSameInstanceAs(initialMetrics)
  }

  @Test
  fun testReductionEndEvent() {
    assertThat(reductionEndEvent.initialPerFileSizeMetrics()).isSameInstanceAs(initialMetrics)
    assertThat(
      reductionEndEvent.testScriptExecutorServiceStatistics.scriptExecutionNumber,
    ).isEqualTo(102)
    assertThat(reductionEndEvent.startEvent).isSameInstanceAs(reductionStartEvent)
  }

  @Test
  fun testFixpointIterationStartEvent() {
    assertThat(firstIterationStart.initialPerFileSizeMetrics()).isSameInstanceAs(initialMetrics)
  }

  @Test
  fun testFixpointIterationEndEvent() {
    assertThat(firstIterationEnd.initialPerFileSizeMetrics()).isSameInstanceAs(initialMetrics)
  }
}
