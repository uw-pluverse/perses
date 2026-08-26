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
package org.perses.listener

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.ProgramSize
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.TestScriptExecutorServiceStatisticsSnapshot
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.util.FileStreamPool
import org.perses.util.FileSystemUtil
import java.nio.file.Files
import java.nio.file.Path

/**
 * Verifies that the listener aggregates per-reducer statistics across the *whole* run -- multiple
 * fixpoint iterations of the same reducer (which, before this listener, were each reported
 * separately per driver) collapse into one row, and multiple reducers each get their own row.
 */
@RunWith(JUnit4::class)
class ReducerStatisticsSummaryListenerTest {
  private val root = FileSystemUtil.createTempDirForObject(this)
  private val originalReductionInputs =
    DefaultLanguageOriginalReductionInputs(
      testScript = ScriptFile(Files.writeString(root.resolve("r.sh"), "#!/bin/bash\ntrue\n")),
      mutableFiles =
        ImmutableList.of(SourceFile(Files.writeString(root.resolve("a.c"), "int a;"), LanguageC)),
      immutableDependencyFiles = ImmutableList.of(),
    )

  private val resultFile: Path = Files.createTempFile("reducer-statistics", ".txt")
  private val streamPool = FileStreamPool()
  private val capturedSummary = StringBuilder()
  private val listener =
    ReducerStatisticsSummaryListener(
      dedicatedStream = streamPool.rentStream(resultFile, this::class.qualifiedName!!),
      additionalSinks = listOf({ summary -> capturedSummary.append(summary) }),
      hideTimestamps = true,
    )

  private val startEvent =
    ReductionStartEvent(
      currentTimeMillis = 0,
      perFileSizeMetrics = metrics(tokenCount = 100, nonBlankCharacterCount = 200),
      commandLineOptions = "<cmd>",
    )

  @After
  fun teardown() {
    listener.close()
    streamPool.close()
    Files.deleteIfExists(resultFile)
    root.toFile().deleteRecursively()
  }

  private fun metrics(
    tokenCount: Int,
    nonBlankCharacterCount: Int,
  ): PerFileSizeMetrics =
    PerFileSizeMetrics(
      originalReductionInputs,
      ImmutableList.of(
        ProgramSize(
          payload = Unit,
          canonicalTokenCount = tokenCount,
          surrogateTokenCount = tokenCount,
          totalCharacterCount = nonBlankCharacterCount,
          nonBlankCharacterCount = nonBlankCharacterCount,
        ),
      ),
    )

  // The Queries column counts onTestScriptExecution events, which require a real tree/edit to
  // construct, so this test fires none (Queries is 0 everywhere here); the deterministic query
  // counting is covered by the astra/latra/node-reducer integration goldens.
  private val emptyStatistics =
    TestScriptExecutorServiceStatisticsSnapshot(
      scriptExecutionNumber = 0,
      externalCacheHitNumber = 0,
    )

  /** Drives one fixpoint iteration of [reducer] through the listener. */
  private fun fireIteration(
    reducer: ReducerAnnotation,
    iteration: Int,
    tokenBefore: Int,
    charBefore: Int,
    tokenAfter: Int,
    charAfter: Int,
  ) {
    val iterationStart =
      FixpointIterationStartEvent(
        startEvent,
        0,
        metrics(tokenBefore, charBefore),
        iteration,
        reducer,
        treeStructureDumper = { "" },
        testScriptStatistics = emptyStatistics,
      )
    listener.onFixpointIterationStart(iterationStart)
    listener.onFixpointIterationEnd(
      FixpointIterationEndEvent(
        iterationStart,
        0,
        metrics(tokenAfter, charAfter),
        testScriptStatistics = emptyStatistics,
      ),
    )
  }

  @Test
  fun aggregatesAcrossIterationsAndReducers() {
    // node_priority runs twice; only the first iteration shrinks the program.
    fireIteration(
      PersesNodeReducerAnnotations.PrioritizedDfs,
      iteration = 1,
      tokenBefore = 100,
      charBefore = 200,
      tokenAfter = 50,
      charAfter = 100,
    )
    fireIteration(
      PersesNodeReducerAnnotations.PrioritizedDfs,
      iteration = 2,
      tokenBefore = 50,
      charBefore = 100,
      tokenAfter = 50,
      charAfter = 100,
    )
    // node-dfs runs once.
    fireIteration(
      PersesNodeReducerAnnotations.Dfs,
      iteration = 3,
      tokenBefore = 50,
      charBefore = 100,
      tokenAfter = 48,
      charAfter = 96,
    )

    listener.onReductionEnd(
      ReductionEndEvent(
        startEvent,
        currentTimeMillis = 0,
        perFileSizeMetrics = metrics(tokenCount = 48, nonBlankCharacterCount = 96),
        TestScriptExecutorServiceStatisticsSnapshot(
          scriptExecutionNumber = 160,
          externalCacheHitNumber = 0,
        ),
      ),
    )

    val report = capturedSummary.toString()
    val rows =
      report
        .trim()
        .lines()
        .map { line -> line.trim().split(Regex("\\s+")) }
    assertThat(report).contains("History")
    assertThat(report).contains("Summary")
    // History: one row per invocation, in chronological order. Queries is 0 (no executions fired).
    // Columns: ID, Reducer, Worked, #NonDeletions, #Tokens, #NonBlankChars, Queries, Duration(sec).
    assertThat(
      rows,
    ).contains(listOf("0", "node_priority", "0", "0", "-50", "-100", "0", "time-hidden"))
    assertThat(rows).contains(listOf("1", "node_priority", "0", "0", "0", "0", "0", "time-hidden"))
    assertThat(rows).contains(listOf("2", "node-dfs", "0", "0", "-2", "-4", "0", "time-hidden"))
    // Summary: aggregated per reducer, sorted by token delta ascending (node_priority before node-dfs).
    // Columns: Reducer, Times, Worked, #NonDeletions, #Tokens, #NonBlankChars, Queries, Duration(sec).
    assertThat(
      rows,
    ).contains(listOf("node_priority", "2", "0", "0", "-50", "-100", "0", "time-hidden"))
    assertThat(rows).contains(listOf("node-dfs", "1", "0", "0", "-2", "-4", "0", "time-hidden"))
    // The dedicated file receives the same report.
    assertThat(Files.readString(resultFile).trim()).isEqualTo(report.trim())
  }
}
