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
package org.perses.ui

import com.fasterxml.jackson.databind.JsonNode
import com.fasterxml.jackson.databind.ObjectMapper
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
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.TestScriptExecutorServiceStatisticsSnapshot
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.util.FileSystemUtil
import java.nio.file.Files

/**
 * Drives synthetic reduction events through [WebUiListener] against a capturing sink and asserts
 * the emitted SSE frames. This mirrors [org.perses.listener.ReducerStatisticsSummaryListenerTest]:
 * both listeners consume the same events, and the per-invocation numbers here must match that
 * listener's History table. Query counting and the transformation rollup depend on
 * onTestScriptExecution/onBestProgramUpdated, which need a real tree/edit to construct, so like
 * that test they are left to the integration goldens; this test covers the event-to-JSON mapping
 * and the token/character delta arithmetic.
 */
@RunWith(JUnit4::class)
class WebUiListenerTest {
  private class CapturingSink : ReductionEventSink {
    val frames = mutableListOf<Pair<String, String>>()

    override fun broadcast(eventName: String, jsonData: String) {
      frames.add(eventName to jsonData)
    }

    override fun close() {}
  }

  private val mapper = ObjectMapper()
  private val sink = CapturingSink()
  private val listener = WebUiListener(sink)

  private val root = FileSystemUtil.createTempDirForObject(this)
  private val originalReductionInputs =
    DefaultLanguageOriginalReductionInputs(
      testScript = ScriptFile(Files.writeString(root.resolve("r.sh"), "#!/bin/bash\ntrue\n")),
      mutableFiles =
        ImmutableList.of(SourceFile(Files.writeString(root.resolve("a.c"), "int a;"), LanguageC)),
      immutableDependencyFiles = ImmutableList.of(),
    )

  private val startEvent =
    ReductionStartEvent(
      currentTimeMillis = 0,
      perFileSizeMetrics = metrics(tokenCount = 100, nonBlankCharacterCount = 200),
      commandLineOptions = "<cmd>",
    )

  private val emptyStatistics =
    TestScriptExecutorServiceStatisticsSnapshot(scriptExecutionNumber = 0, externalCacheHitNumber = 0)

  @After
  fun teardown() {
    listener.close()
    root.toFile().deleteRecursively()
  }

  private fun metrics(tokenCount: Int, nonBlankCharacterCount: Int): PerFileSizeMetrics =
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

  private fun fireIteration(
    reducer: ReducerAnnotation,
    tokenBefore: Int,
    charBefore: Int,
    tokenAfter: Int,
    charAfter: Int,
  ) {
    val iterationStart =
      startEvent.nextFixpointIteration(
        perFileSizeMetrics = metrics(tokenBefore, charBefore),
        reducerClass = reducer,
        treeStructureDumper = { "" },
        testScriptStatistics = emptyStatistics,
      )
    listener.onFixpointIterationStart(iterationStart)
    listener.onFixpointIterationEnd(
      iterationStart.createEndEvent(
        currentTimeMillis = 0,
        perFileSizeMetrics = metrics(tokenAfter, charAfter),
        testScriptStatistics = emptyStatistics,
      ),
    )
  }

  private fun framesOf(eventName: String): List<JsonNode> =
    sink.frames.filter { it.first == eventName }.map { mapper.readTree(it.second) }

  @Test
  fun emitsStartFixpointInvocationAndEndFrames() {
    listener.onReductionStart(startEvent)
    fireIteration(
      PersesNodeReducerAnnotations.PrioritizedDfs,
      tokenBefore = 100,
      charBefore = 200,
      tokenAfter = 50,
      charAfter = 100,
    )
    fireIteration(
      PersesNodeReducerAnnotations.Dfs,
      tokenBefore = 50,
      charBefore = 100,
      tokenAfter = 48,
      charAfter = 96,
    )
    listener.onReductionEnd(
      startEvent.createEndEvent(
        perFileSizeMetrics = metrics(tokenCount = 48, nonBlankCharacterCount = 96),
        testScriptStatistics =
          TestScriptExecutorServiceStatisticsSnapshot(
            scriptExecutionNumber = 160,
            externalCacheHitNumber = 0,
          ),
      ),
    )

    val start = framesOf("reduction-start").single()
    assertThat(start.get("initialTokens").asInt()).isEqualTo(100)
    assertThat(start.get("initialChars").asInt()).isEqualTo(200)

    val fixpoints = framesOf("fixpoint")
    assertThat(fixpoints.map { it.get("reducer").asText() })
      .containsExactly("node_priority", "node-dfs")
    assertThat(fixpoints[0].get("tokens").asInt()).isEqualTo(100)

    // One reducer-invocation per fixpoint iteration; ids are chronological and the token/char
    // deltas match ReducerStatisticsSummaryListenerTest's History rows.
    val invocations = framesOf("reducer-invocation")
    assertThat(invocations).hasSize(2)
    assertThat(invocations[0].get("id").asInt()).isEqualTo(0)
    assertThat(invocations[0].get("reducer").asText()).isEqualTo("node_priority")
    assertThat(invocations[0].get("tokens").asInt()).isEqualTo(-50)
    assertThat(invocations[0].get("nonBlankChars").asInt()).isEqualTo(-100)
    assertThat(invocations[0].get("worked").asInt()).isEqualTo(0)
    assertThat(invocations[0].get("queries").asInt()).isEqualTo(0)
    assertThat(invocations[1].get("id").asInt()).isEqualTo(1)
    assertThat(invocations[1].get("reducer").asText()).isEqualTo("node-dfs")
    assertThat(invocations[1].get("tokens").asInt()).isEqualTo(-2)

    val end = framesOf("reduction-end").single()
    assertThat(end.get("finalTokens").asInt()).isEqualTo(48)
    assertThat(end.get("initialTokens").asInt()).isEqualTo(100)
    assertThat(end.get("executions").asInt()).isEqualTo(160)
  }
}
