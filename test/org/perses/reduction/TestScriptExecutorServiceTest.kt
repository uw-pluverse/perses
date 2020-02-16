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
import com.google.common.truth.Truth
import org.junit.After
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgram
import java.io.File
import java.io.IOException
import java.util.*
import java.util.concurrent.ExecutionException
import java.util.concurrent.Future
import java.util.concurrent.TimeUnit
import java.util.function.Consumer

/** Test for [TestScriptExecutorService]  */
@RunWith(JUnit4::class)
class TestScriptExecutorServiceTest {
  private var sourceFile: File? = null
  private var invalidSourceFile: File? = null
  private var testScript: File? = null
  private var program: TokenizedProgram? = null
  private var workingDirectory: File? = null
  @Before
  @Throws(IOException::class)
  fun setup() {
    workingDirectory = TestUtility.createCleanWorkingDirectory(TestScriptExecutorServiceTest::class.java)
    sourceFile = File(FOLDER + "t.c")
    testScript = File(FOLDER + "r.sh")
    invalidSourceFile = File("test_data/misc/t1.c")
    program = TestUtility.createSparTreeFromFile(sourceFile).programSnapshot
  }

  @After
  @Throws(IOException::class)
  fun teardown() {
    MoreFiles.deleteRecursively(workingDirectory!!.toPath(), RecursiveDeleteOption.ALLOW_INSECURE)
  }

  @Test
  @Throws(InterruptedException::class, ExecutionException::class, IOException::class)
  fun testThreadCount_1() {
    testTestScriptExecutor(1)
  }

  @Test
  @Throws(InterruptedException::class, ExecutionException::class, IOException::class)
  fun testThreadCount_4() {
    testTestScriptExecutor(4)
  }

  @Test
  @Throws(InterruptedException::class, ExecutionException::class, IOException::class)
  fun testThreadCount_10() {
    testTestScriptExecutor(10)
  }

  private fun createConfiguration(threadCount: Int): ReductionConfiguration {
    return ReductionConfiguration(
        workingFolder = workingDirectory!!,
        testScriptFile = testScript!!,
        fileToReduce = sourceFile!!,
        bestResultFile = sourceFile!!,
        statisticsFile = null,
        progressDumpFile = null,
        keepOriginalCodeFormat = true,
        fixpointReduction = true,
        enableTestScriptExecutionCaching = true,
        useRealDeltaDebugger = false,
        maxReductionLevel = 100,
        numOfReductionThreads = threadCount)
  }

  @Throws(IOException::class)
  private fun testTestScriptExecutor(threadCount: Int) {
    val stopwatch = Stopwatch.createStarted()
    val configuration = createConfiguration(threadCount)
    val service = TestScriptExecutorService(
        configuration.tempRootFolder,
        configuration.numOfReductionThreads,
        SourceFile.createFromPath(testScript),
        sourceFile!!.name)
    Truth.assertThat(configuration.numOfReductionThreads).isEqualTo(threadCount)
    // TODO: refine this test.
    run {
      val futureList: MutableList<Future<TestScript.TestResult>> = ArrayList()
      for (i in 0..49) {
        futureList.add(service.testProgram(program!!, true))
      }
      futureList.forEach(
          Consumer { future: Future<TestScript.TestResult> ->
            try {
              Truth.assertThat(future.get().isPass).isTrue()
            } catch (e: Throwable) {
              throw AssertionError(e)
            }
          })
    }
    run {
      val invalidProgram = TestUtility.createSparTreeFromFile(invalidSourceFile).programSnapshot
      val futureList: MutableList<Future<TestScript.TestResult>> = ArrayList()
      for (i in 0..49) {
        futureList.add(service.testProgram(invalidProgram, true))
      }
      futureList.forEach(
          Consumer { future: Future<TestScript.TestResult> ->
            try {
              Truth.assertThat(future.get().isPass).isFalse()
            } catch (e: Throwable) {
              throw AssertionError(e)
            }
          })
    }
    stopwatch.stop()
    println(
        "#threads=" + threadCount + ": time=" + stopwatch.elapsed(TimeUnit.SECONDS) + " seconds")
  }

  companion object {
    private const val FOLDER = "test_data/delta_1/"
  }
}