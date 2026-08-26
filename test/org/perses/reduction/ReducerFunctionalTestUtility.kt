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
package org.perses.reduction

import com.google.common.truth.Truth
import com.google.common.truth.Truth.assertWithMessage
import org.perses.Main
import org.perses.PersesCommandOptions
import org.perses.program.ProgramSize
import org.perses.program.SourceFile
import org.perses.reduction.LanguageProfile
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.util.AutoDeletableFolder
import org.perses.util.FileSystemUtil
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.transformToImmutableList
import java.io.Closeable
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import java.util.stream.Collectors

/** The base class for testing the functionality of reducers.  */
class ReducerFunctionalTestUtility(
  val reductionFolder: String,
  val testScript: String,
  val sourceFile: String,
  val reducerAnnotation: ReducerAnnotation,
  cmdCustomizer: (PersesCommandOptions) -> Unit = {},
) : Closeable {
  val tempDir = AutoDeletableFolder(FileSystemUtil.createTempDirForObject(this))

  val outputDir = tempDir.file.resolve("perses_output_dir")
  val cmd =
    PersesCommandOptions().also {
      val tempSourceFile = tempDir.file.resolve(sourceFile)
      Files.copy(Paths.get(reductionFolder, sourceFile), tempSourceFile)
      val tempTestScript = tempDir.file.resolve(testScript)
      Files.copy(Paths.get(reductionFolder, testScript), tempTestScript)
      it.inputFlags.setInputFiles(listOf(tempSourceFile))
      it.inputFlags.testScript = tempTestScript
      it.reductionControlFlags.fixpointForMainReducer = true
      it.trecFlags.enableTRec = false
      it.algorithmControlFlags.mainReductionAlgorithm = reducerAnnotation.shortName
      it.resultOutputFlags.outputDir = outputDir
      cmdCustomizer.invoke(it)
    }
  val globalContext =
    GlobalContext(
      enableGlobalCache = false,
      globalCacheFile = null,
      pathToSaveUpdatedGlobalCache = null,
      shaAlgorithm = EnumShaAlgorithm.SHA512,
    )
  val persesMain = Main(cmd, globalContext, LanguageProfile.DEFAULT)

  val originalReductionInputs = persesMain.originalReductionInputs

  // These tests are single-file and white-box: they reduce one source file and inspect the
  // single-file driver's spar tree / reducer context. The orchestrator now owns per-file driver
  // creation, so ask it for the driver of the (only) mutable file.
  val reductionDriver =
    persesMain
      .createReductionDriver(
        originalReductionInputs,
        ReductionStartEvent(
          currentTimeMillis = System.currentTimeMillis(),
          perFileSizeMetrics =
            PerFileSizeMetrics(
              originalReductionInputs,
              originalReductionInputs.mutableFiles.transformToImmutableList { ProgramSize.ZERO },
            ),
          commandLineOptions = "",
        ),
      ).createReductionDriverFor(originalReductionInputs.mutableFiles.single() as SourceFile)

  val reducerContext = reductionDriver.reducerContext
  val sparTree = reductionDriver.inputRepresentation.tree

  fun createReducers() = reducerAnnotation.create(reducerContext)

  override fun close() {
    reductionDriver
    persesMain.close()
    globalContext.close()
    tempDir.close()
  }

  /**
   * Runs the reduction and hands the reduced result to [assertion], so callers can express
   * arbitrary expectations on the actual output (e.g. equality, containment, token counts) rather
   * than just whole-string equality.
   */
  fun runReducerAndAssert(assertion: (actualResult: String) -> Unit) {
    val bestFile = outputDir.resolve(sourceFile)
    // The result folder is seeded with the original input before reduction starts, so the best file
    // begins as the original program; reduce() then overwrites it with the reduced result.
    Truth
      .assertThat(Files.readString(bestFile))
      .isEqualTo(Files.readString(Paths.get(reductionFolder, sourceFile)))
    reductionDriver.reduce()
    val resultString =
      Files
        .lines(bestFile, StandardCharsets.UTF_8)
        .collect(Collectors.joining(System.lineSeparator()))
    assertion(resultString)
  }

  /** Convenience assertion that the reduced result equals [expected], ignoring whitespace. */
  fun runReducerAndTest(expected: String) {
    runReducerAndAssert { actualResult ->
      assertWithMessage("reduction folder=%s, algorith=%s", reductionFolder, reducerAnnotation)
        .that(actualResult.replace("\\s+".toRegex(), ""))
        .isEqualTo(expected.replace("\\s+".toRegex(), ""))
    }
  }

  companion object {
    fun runBenchmarkSubject(
      reductionFolder: String,
      reducerAnnotation: ReducerAnnotation,
      cmdCustomizer: (PersesCommandOptions) -> Unit = {},
      expected: String,
    ) {
      ReducerFunctionalTestUtility(
        reductionFolder = reductionFolder,
        testScript = "r.sh",
        sourceFile = "small.c",
        reducerAnnotation = reducerAnnotation,
        cmdCustomizer = cmdCustomizer,
      ).use { utility ->
        utility.runReducerAndTest(expected)
      }
    }

    fun runCTestSubject(
      reductionFolder: String,
      reducerAnnotation: ReducerAnnotation,
      cmdCustomizer: (PersesCommandOptions) -> Unit = {},
      expected: String,
    ) {
      ReducerFunctionalTestUtility(
        reductionFolder = reductionFolder,
        testScript = "r.sh",
        sourceFile = "t.c",
        reducerAnnotation = reducerAnnotation,
        cmdCustomizer = cmdCustomizer,
      ).use { utility ->
        utility.runReducerAndTest(expected)
      }
    }

    fun runJavaTestSubject(
      reductionFolder: String,
      reducerAnnotation: ReducerAnnotation,
      cmdCustomizer: (PersesCommandOptions) -> Unit = {},
      expected: String,
    ) {
      ReducerFunctionalTestUtility(
        reductionFolder = reductionFolder,
        testScript = "r.sh",
        sourceFile = "t.java",
        reducerAnnotation = reducerAnnotation,
        cmdCustomizer = cmdCustomizer,
      ).use {
        it.runReducerAndTest(expected)
      }
    }

    fun runScalaTestSubject(
      reductionFolder: String,
      reducerAnnotation: ReducerAnnotation,
      cmdCustomizer: (PersesCommandOptions) -> Unit = {},
      expected: String,
    ) {
      ReducerFunctionalTestUtility(
        reductionFolder = reductionFolder,
        testScript = "r.sh",
        sourceFile = "t.sc",
        reducerAnnotation = reducerAnnotation,
        cmdCustomizer = cmdCustomizer,
      ).use {
        it.runReducerAndTest(expected)
      }
    }
  }
}
