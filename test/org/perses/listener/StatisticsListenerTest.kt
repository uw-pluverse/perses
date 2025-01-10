/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.event.TestScriptExecutorServiceStatisticsSnapshot
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.util.FileStreamPool
import java.lang.ref.WeakReference
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import java.util.Properties
import kotlin.io.path.deleteIfExists

@RunWith(JUnit4::class)
class StatisticsListenerTest {

  private val resultFile: Path = Files.createTempFile("reduction-statistics", ".txt")
  private val streamPool = FileStreamPool()
  private val listener = StatisticsListener(
    streamPool.rentStream(resultFile, this::class.qualifiedName!!),
  )

  @After
  fun teardown() {
    check(resultFile.deleteIfExists())
    listener.close()
    streamPool.close()
  }

  @Test
  fun test() {
    val reducer = PersesNodePrioritizedDfsReducer.META
    val startEvent = ReductionStartEvent(
      currentTimeMillis = 300,
      tree = WeakReference(null),
      programSize = 100,
      commandLineOptions = "<cmd>",
    )
    val firstIterationStart = FixpointIterationStartEvent(
      startEvent,
      300,
      100,
      1,
      reducer,
      treeStructureDumper = { "" },
      testScriptStatistics = TestScriptExecutorServiceStatisticsSnapshot(
        scriptExecutionNumber = 0,
        externalCacheHitNumber = 0,
      ),
    )
    listener.onFixpointIterationStart(firstIterationStart)
    val firstTestExecutions = 100
    listener.onFixpointIterationEnd(
      FixpointIterationEndEvent(
        firstIterationStart,
        500,
        50,
        testScriptStatistics = TestScriptExecutorServiceStatisticsSnapshot(
          scriptExecutionNumber = firstTestExecutions,
          externalCacheHitNumber = 0,
        ),
      ),
    )
    val secondIterationStart = FixpointIterationStartEvent(
      startEvent,
      500,
      50,
      2,
      reducer,
      treeStructureDumper = { "" },
      testScriptStatistics = TestScriptExecutorServiceStatisticsSnapshot(
        scriptExecutionNumber = firstTestExecutions,
        externalCacheHitNumber = 0,
      ),
    )
    listener.onFixpointIterationStart(secondIterationStart)
    val secondTestExecutions = 150
    listener.onFixpointIterationEnd(
      FixpointIterationEndEvent(
        secondIterationStart,
        700,
        25,
        testScriptStatistics = TestScriptExecutorServiceStatisticsSnapshot(
          scriptExecutionNumber = secondTestExecutions + firstTestExecutions,
          externalCacheHitNumber = 0,
        ),
      ),
    )
    val endEvent =
      ReductionEndEvent(
        startEvent,
        currentTimeMillis = 1000,
        programSize = 25,
        TestScriptExecutorServiceStatisticsSnapshot(
          scriptExecutionNumber = firstTestExecutions + secondTestExecutions,
          externalCacheHitNumber = 0,
        ),
      )
    listener.onReductionEnd(endEvent)
    Files.newBufferedReader(resultFile, StandardCharsets.UTF_8).use { reader ->
      val p = Properties()
      p.load(reader)
      assertThat(p.getProperty("iterations")).isEqualTo("2")
      assertThat(p.getProperty("program_size_before.1")).isEqualTo("100")
      assertThat(p.getProperty("program_size_after.1")).isEqualTo("50")
      assertThat(p.getProperty("count_test_script_executions.1")).isEqualTo("100")
      assertThat(p.getProperty("elapsed_time_millis.1")).isEqualTo("200")
      assertThat(p.getProperty("program_size_before.2")).isEqualTo("50")
      assertThat(p.getProperty("program_size_after.2")).isEqualTo("25")
      assertThat(p.getProperty("count_test_script_executions.2")).isEqualTo("150")
      assertThat(p.getProperty("elapsed_time_millis.2")).isEqualTo("200")
    }
    val testFileContent =
      com.google.common.io.Files.asCharSource(resultFile.toFile(), StandardCharsets.UTF_8)
        .read()
        .trim { it <= ' ' }
    val goldenFileContent = com.google.common.io.Files.asCharSource(
      Paths.get("test/org/perses/listener/golden_statistics_listener_test.properties")
        .toFile(),
      StandardCharsets.UTF_8,
    ).read()
      .trim { it <= ' ' }
    assertThat(testFileContent).isEqualTo(goldenFileContent)
  }
}
