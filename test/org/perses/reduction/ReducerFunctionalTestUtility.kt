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
package org.perses.reduction

import com.google.common.truth.Truth
import com.google.common.truth.Truth.assertWithMessage
import org.perses.CommandOptions
import org.perses.Main
import org.perses.util.AutoDeletableFolder
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
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
  cmdCustomizer: (CommandOptions) -> Unit = {},
) : Closeable {
  val tempDir = AutoDeletableFolder(Util.createTempDirFor(this))

  val outputDir = tempDir.file.resolve("perses_output_dir")
  val cmd =
    CommandOptions().also {
      val tempSourceFile = tempDir.file.resolve(sourceFile)
      Files.copy(Paths.get(reductionFolder, sourceFile), tempSourceFile)
      val tempTestScript = tempDir.file.resolve(testScript)
      Files.copy(Paths.get(reductionFolder, testScript), tempTestScript)
      it.inputFlags.inputFile = tempSourceFile
      it.inputFlags.testScript = tempTestScript
      it.reductionControlFlags.fixpointForMainReducer = true
      it.trecFlags.enableTRec = false
      it.algorithmControlFlags.reductionAlgorithm = reducerAnnotation.shortName
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
  val persesMain = Main(cmd, globalContext)

  val reductionInputs = persesMain.reductionInputs
  val reductionDriver =
    persesMain
      .createSequenceOfReductionDriverCreators(reductionInputs)
      .first()
      .creator
      .invoke()

  val reducerContext = reductionDriver.reducerContext
  val sparTree = reductionDriver.tree.getTreeRegardlessOfParsability()

  fun createReducers() = reducerAnnotation.create(reducerContext)

  override fun close() {
    reductionDriver
    persesMain.close()
    globalContext.close()
    tempDir.close()
  }

  fun runReducerAndTest(expected: String) {
    val bestFile = outputDir.resolve(sourceFile)
    Truth.assertThat(Files.exists(bestFile)).isFalse()
    reductionDriver.reduce()
    val resultString =
      Files
        .lines(bestFile, StandardCharsets.UTF_8)
        .collect(Collectors.joining(System.lineSeparator()))
    assertWithMessage("reduction folder=%s, algorith=%s", reductionFolder, reducerAnnotation)
      .that(resultString.replace("\\s+".toRegex(), ""))
      .isEqualTo(expected.replace("\\s+".toRegex(), ""))
  }

  companion object {
    fun runBenchmarkSubject(
      reductionFolder: String,
      reducerAnnotation: ReducerAnnotation,
      cmdCustomizer: (CommandOptions) -> Unit = {},
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
      cmdCustomizer: (CommandOptions) -> Unit = {},
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
      cmdCustomizer: (CommandOptions) -> Unit = {},
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
      cmdCustomizer: (CommandOptions) -> Unit = {},
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
