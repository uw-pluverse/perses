/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.reduction.io

import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCLexer
import org.perses.program.EnumFormatControl
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.AbstractExternalTestScriptExecutionCachePolicy.NullExternalTestScriptExecutionCachePolicy
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.io.token.RegularOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.Util
import java.nio.file.Files
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

open class CommonReductionIOManagerData(val testClass: Class<*>) : AutoCloseable {

  val root = Files.createTempDirectory(testClass.simpleName + "_data")

  override fun close() {
    if (executorServiceDelegate.isInitialized()) {
      executorService.close()
    }
    root.deleteRecursively()
  }

  val script = ScriptFile(
    root.resolve("r.sh").apply {
      Files.createFile(this)
      Util.setExecutable(this)
      writeText(
        """#!/usr/bin/env bash
      test
        """.trimIndent(),
      )
    },
  )
  val sourceFile = SourceFile(
    root.resolve("t.c").apply {
      Files.createFile(this)
      this.writeText("int a;")
    },
    LanguageC,
  )
  val inputs = RegularReductionInputs(
    testScript = script,
    mainFile = sourceFile,
  )
  val outputDir = root.resolve("output_dir").apply {
    Files.createDirectory(this)
  }
  val workingDir = root.resolve("working_dir").apply {
    Files.createDirectory(this)
  }
  val outputManagerFactory = RegularOutputManagerFactory(
    inputs,
    EnumFormatControl.ORIG_FORMAT,
    LexerAtnWrapper(PnfCLexer::class.java),
  )
  val ioManager = TokenReductionIOManager(
    workingFolder = workingDir,
    reductionInputs = inputs,
    outputManagerFactory = outputManagerFactory,
    outputDirectory = outputDir,
  )

  // This field has to be lazy, because the constructor has side effects, and creates files
  // in the workingFolder.
  private val executorServiceDelegate = lazy {
    TestScriptExecutorService(
      ioManager.lazilyInitializedReductionFolderManager,
      specifiedNumOfThreads = 1,
      scriptExecutionTimeoutInSeconds = 600L,
      externalTestScriptExecutionCachePolicyCreator = {
        NullExternalTestScriptExecutionCachePolicy()
      },
    )
  }
  val executorService: TestScriptExecutorService by executorServiceDelegate
}
