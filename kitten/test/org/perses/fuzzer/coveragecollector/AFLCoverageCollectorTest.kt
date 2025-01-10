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
package org.perses.fuzzer.coveragecollector

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth
import org.junit.After
import org.junit.Test
import org.perses.fuzzer.compilers.CommonCompilationAction
import org.perses.grammar.c.LanguageC
import org.perses.util.DaemonThreadPool
import org.perses.util.shell.ShellCommandOnPath
import java.io.File
import java.nio.file.Files
import java.util.concurrent.Executors
import java.util.concurrent.atomic.AtomicInteger
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

class AFLCoverageCollectorTest {

  private val tempDir = Files.createTempDirectory(this::class.java.canonicalName)

  private val resultFile = tempDir.resolve("coverage.temp")

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  private val aflCoverageCollector = AFLCoverageCollector(
    monitorInterval = 600,
    resultFile = resultFile,
  )

  private val action = CommonCompilationAction(
    compilerCmd = ShellCommandOnPath(
      "kitten/test/fuzzer_test_data/coverage_collector_test/afl_instrumented_binary",
    ),
    compilerFlags = ImmutableList.of(),
    versionPrintFlags = ImmutableList.of(),
    language = LanguageC,
  )

  private val testInputs = listOf(
    File("kitten/test/fuzzer_test_data/coverage_collector_test/test_input_1"),
    File("kitten/test/fuzzer_test_data/coverage_collector_test/test_input_2"),
    File("kitten/test/fuzzer_test_data/coverage_collector_test/test_input_3"),
  )

  @Test
  fun testAFLCoverageCollectionWithMultiThreads() {
    val blankReport = aflCoverageCollector.getCoverageReport()
    Truth.assertThat(blankReport.aflHitCount).isEqualTo(0)
    val index = AtomicInteger(0)
    val executor = Executors.newFixedThreadPool(1)
    // Simulate the workflow in FuzzerDriver
    executor.submit {
      aflCoverageCollector.registerForThread()
      aflCoverageCollector.executeActionWithCoverageCollection(
        action,
        testInputs[index.getAndIncrement()],
        Thread.currentThread().id,
      )
      assert(
        aflCoverageCollector.triggerNewEdge(
          aflCoverageCollector.getSharedMemoryIdWithThreadId()!!.buffer,
        ),
      )
    }
    DaemonThreadPool.shutdownOrThrow(executor)
    val newReport = aflCoverageCollector.getCoverageReport()
    Truth.assertThat(newReport.aflHitCount).isEqualTo(5)
  }

  @Test
  fun testAFLCoverageCollectionInSingleThread() {
    val sharedMemory = AFLCoverageCollector.createSharedMemory()
    for (testInput in testInputs) {
      sharedMemory.clean()
      Truth.assertThat(sharedMemory.getHitCount()).isEqualTo(0)
      action.compileWithExtraEnvironment(
        testInput,
        AFLCoverageCollector.getEnvironmentVariableForAFLSharedMemory(sharedMemory.id),
      )
      Truth.assertThat(sharedMemory.getHitCount()).isNotEqualTo(0)
    }
  }
}
