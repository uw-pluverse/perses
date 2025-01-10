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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth
import com.google.common.truth.Truth.assertWithMessage
import org.perses.CommandOptions
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.reduction.io.RegularReductionInputs
import org.perses.util.AutoDeletableFolder
import org.perses.util.Util
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import java.util.stream.Collectors

/** The base class for testing the functionality of reducers.  */
abstract class AbstractReducerFunctionalTest {

  protected fun test(
    reductionFolder: String,
    testScript: String,
    sourceFile: String,
    algorithmType: ReducerAnnotation,
    cmdCustomizer: (CommandOptions) -> Unit,
    expected: String,
  ) {
    val parserFacadeFactory = builderWithBuiltinLanguages().build()
    Util.useResources(
      { AsyncReductionListenerManager(listeners = ImmutableList.of()) },
      { AutoDeletableFolder(Files.createTempDirectory(javaClass.simpleName)) },
      { _, _ -> GlobalContext() },
    ) { listenerManager, folder, globalContext ->
      val cmd = CommandOptions()
      val tempSourceFile = folder.file.resolve(sourceFile)
      Files.copy(Paths.get(reductionFolder, sourceFile), tempSourceFile)
      val tempTestScript = folder.file.resolve(testScript)
      Files.copy(Paths.get(reductionFolder, testScript), tempTestScript)
      cmd.inputFlags.inputFile = tempSourceFile
      cmd.inputFlags.testScript = tempTestScript
      cmd.reductionControlFlags.fixpoint = true
      cmd.algorithmControlFlags.reductionAlgorithm = algorithmType.shortName
      val outputDir = folder.file.resolve("perses_output_dir")
      cmd.resultOutputFlags.outputDir = outputDir
      cmdCustomizer.invoke(cmd)
      val reductionInput = RegularReductionInputs.create(
        testScriptPath = cmd.inputFlags.getTestScript(),
        mainFilePath = cmd.inputFlags.getSourceFile(),
        dependencyFiles = ImmutableList.of(),
      ) {
        parserFacadeFactory.computeLanguageKindOrThrow(it)
      }
      val parserFacade = parserFacadeFactory.getParserFacadeListForOrNull(
        reductionInput.initiallyDeterminedMainDataKind,
      )!!.defaultParserFacade.create()
      RegularProgramReductionDriver.create(
        globalContext,
        cmd,
        reductionInput,
        parserFacade,
        codeFormatControl = reductionInput.initiallyDeterminedMainDataKind.defaultCodeFormatControl,
        listenerManager,
      ).use { driver ->
        val bestFile = outputDir.resolve(tempSourceFile.fileName)
        Truth.assertThat(Files.exists(bestFile)).isFalse()
        driver.reduce()
        val resultString = Files.lines(bestFile, StandardCharsets.UTF_8)
          .collect(Collectors.joining(System.lineSeparator()))
        assertWithMessage("reduction folder=%s, algorith=%s", reductionFolder, algorithmType)
          .that(resultString.replace("\\s+".toRegex(), ""))
          .isEqualTo(expected.replace("\\s+".toRegex(), ""))
      }
    }
  }

  protected fun runBenchmarkSubject(
    reductionFolder: String,
    algorithmType: ReducerAnnotation,
    cmdCustomizer: (CommandOptions) -> Unit,
    expected: String,
  ) {
    test(reductionFolder, "r.sh", "small.c", algorithmType, cmdCustomizer, expected)
  }

  protected fun runCTestSubject(
    reductionFolder: String,
    algorithmType: ReducerAnnotation,
    expected: String,
  ) {
    runCTestSubject(reductionFolder, algorithmType, { }, expected)
  }

  protected fun runCTestSubject(
    reductionFolder: String,
    algorithmType: ReducerAnnotation,
    cmdCustomizer: (CommandOptions) -> Unit,
    expected: String,
  ) {
    test(reductionFolder, "r.sh", "t.c", algorithmType, cmdCustomizer, expected)
  }

  protected fun runJavaTestSubject(
    reductionFolder: String,
    algorithmType: ReducerAnnotation,
    expected: String,
  ) {
    test(reductionFolder, "r.sh", "t.java", algorithmType, { }, expected)
  }

  protected fun runScalaTestSubject(
    reductionFolder: String,
    algorithmType: ReducerAnnotation,
    expected: String,
  ) {
    test(reductionFolder, "r.sh", "t.sc", algorithmType, { }, expected)
  }
}
