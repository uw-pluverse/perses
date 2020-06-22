/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.reduction

import com.google.common.base.Stopwatch
import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.program.EnumFormatControl.ORIG_FORMAT
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.TestScriptExecutorService.Companion.ALWAYS_TRUE_PRECHECK
import java.io.File
import java.util.ArrayList
import java.util.concurrent.Future
import java.util.concurrent.TimeUnit
import java.util.function.Consumer

/** Test for [TestScriptExecutorService]  */
@RunWith(JUnit4::class)
class TestScriptExecutorServiceTest {
  companion object {
    private const val FOLDER = "test_data/delta_1/"
  }

  private val sourceFile = SourceFile(File(FOLDER, "t.c"))
  private val invalidSourceFile = SourceFile(File("test_data/misc/t1.c"))
  private val testScript = ScriptFile(File(FOLDER, "r.sh"))
  private val program = TestUtility.createSparTreeFromFile(sourceFile.file).programSnapshot

  private var workingDirectory: File? = null

  @Before
  fun setup() {
    workingDirectory =
      TestUtility.createCleanWorkingDirectory(TestScriptExecutorServiceTest::class.java)
  }

  @After
  fun teardown() {
    MoreFiles.deleteRecursively(workingDirectory!!.toPath(), RecursiveDeleteOption.ALLOW_INSECURE)
    workingDirectory = null
  }

  @Test
  fun testThreadCount_1() {
    testTestScriptExecutor(threadCount = 1)
  }

  @Test
  fun testThreadCount_4() {
    testTestScriptExecutor(threadCount = 4)
  }

  private fun createConfiguration(threadCount: Int): ReductionConfiguration {
    return ReductionConfiguration(
      workingFolder = workingDirectory!!,
      testScript = testScript,
      fileToReduce = sourceFile,
      bestResultFile = sourceFile.file,
      statisticsFile = null,
      progressDumpFile = null,
      programFormatControl = ORIG_FORMAT,
      fixpointReduction = true,
      enableTestScriptExecutionCaching = true,
      useRealDeltaDebugger = false,
      numOfReductionThreads = threadCount
    )
  }

  private fun testTestScriptExecutor(threadCount: Int) {
    val stopwatch = Stopwatch.createStarted()
    val configuration = createConfiguration(threadCount)
    assertThat(configuration.numOfReductionThreads).isEqualTo(threadCount)
    TestScriptExecutorService(
      configuration.tempRootFolder,
      configuration.numOfReductionThreads,
      testScript,
      sourceFile.file.name
    ).use {
      // TODO: refine this test.
      testPassing(it)
      testFailing(it)
      testPrecheckFailing(it)
      stopwatch.stop()
      println(
        "#threads=" + threadCount + ": time=" + stopwatch.elapsed(TimeUnit.SECONDS) + " seconds"
      )
    }
  }

  private fun testPrecheckFailing(it: TestScriptExecutorService) {
    val invalidProgram = TestUtility.createSparTreeFromFile(invalidSourceFile.file)
      .programSnapshot
    val futureList: MutableList<Future<TestScript.TestResult>> = ArrayList()
    for (i in 0..49) {
      futureList.add(
        it.testProgram(
          { TestScript.TestResult(exitCode = 1, elapsedMilliseconds = 1) },
          invalidProgram,
          ORIG_FORMAT
        )
      )
    }
    futureList.forEach(
      Consumer {
        try {
          assertThat(it.get().isPass).isFalse()
        } catch (e: Throwable) {
          throw AssertionError(e)
        }
      }
    )
  }

  private fun testFailing(it: TestScriptExecutorService) {
    val invalidProgram = TestUtility.createSparTreeFromFile(invalidSourceFile.file)
      .programSnapshot
    val futureList: MutableList<Future<TestScript.TestResult>> = ArrayList()
    for (i in 0..49) {
      futureList.add(
        it.testProgram(
          ALWAYS_TRUE_PRECHECK,
          invalidProgram,
          ORIG_FORMAT
        )
      )
    }
    futureList.forEach(
      Consumer {
        try {
          assertThat(it.get().isPass).isFalse()
        } catch (e: Throwable) {
          throw AssertionError(e)
        }
      }
    )
  }

  private fun testPassing(service: TestScriptExecutorService) {
    val futureList: MutableList<Future<TestScript.TestResult>> = ArrayList()
    for (i in 0..49) {
      futureList.add(
        service.testProgram(
          ALWAYS_TRUE_PRECHECK,
          program!!,
          ORIG_FORMAT
        )
      )
    }
    futureList.forEach(
      Consumer {
        try {
          assertThat(it.get().isPass).isTrue()
        } catch (e: Throwable) {
          throw AssertionError(e)
        }
      }
    )
  }
}
