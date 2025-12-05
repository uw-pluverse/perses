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
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.CommandOptions
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.grammar.c.LanguageC
import org.perses.program.EnumFormatControl
import org.perses.reduction.AbstractProgramReductionDriver.Companion.createConfiguration
import org.perses.reduction.cache.EnumQueryCachingControl
import org.perses.reduction.io.RegularReductionInputs
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.reduction.scheduler.AbstractSchedulerEvent.ReducerCallEvent
import org.perses.reduction.scheduler.AbstractSchedulerEvent.StatsSnapshotEvent
import org.perses.reduction.scheduler.ReducerScheduler
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.shell.Shells
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.appendText
import kotlin.io.path.createFile
import kotlin.io.path.listDirectoryEntries
import kotlin.io.path.name
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class RegularProgramReductionDriverTest {
  private val workDir = Files.createTempDirectory("ReductionDriverTest_")
  private val sourceFile =
    workDir.resolve("t.c").apply {
      this.createFile()
      check(Files.exists(this))
    }
  private val scriptFile =
    workDir.resolve("r.sh").apply {
      this.createFile()
      check(Files.exists(this))
      Util.setExecutable(this)
      check(Files.isExecutable(this))
      this.writeText("${Shells.SHEBANG_BASH}\n")
    }
  private val facadeFactory = builderWithBuiltinLanguages().build()
  private val listenerManager =
    AsyncReductionListenerManager(
      listeners = ImmutableList.of(),
      synchronousMode = true,
    )
  private val globalContext =
    GlobalContext(
      enableGlobalCache = false,
      globalCacheFile = null,
      pathToSaveUpdatedGlobalCache = null,
      shaAlgorithm = EnumShaAlgorithm.SHA512,
    )

  @After
  fun teardown() {
    workDir.toFile().deleteRecursively()
    listenerManager.close()
    globalContext.close()
  }

  @Test
  fun testDoesNotThrowNpeWhenLanguageCannotBeDetected() {
    val cmd =
      CommandOptions().apply {
        inputFlags.inputFile = scriptFile
        inputFlags.testScript = scriptFile
      }
    val exception =
      assertThrows(IllegalStateException::class.java) {
        RegularReductionInputs.create(
          testScriptPath = cmd.inputFlags.getTestScript(),
          mainFilePath = cmd.inputFlags.getSourceFile(),
          dependencyFiles = ImmutableList.of(),
        ) {
          facadeFactory.computeLanguageKindOrThrow(it)
        }
      }
    assertThat(exception.message)
      .startsWith("Failed to detect the language kind for")
  }

  @Test
  fun testBackupMainFile() {
    val cmd =
      CommandOptions().apply {
        inputFlags.inputFile = sourceFile
        inputFlags.testScript = scriptFile
      }
    sourceFile.writeText("a;")
    scriptFile.appendText(
      """
      |grep "a" ${sourceFile.fileName}
      |
      """.trimMargin(),
    )
    val inputs =
      RegularReductionInputs.create(
        testScriptPath = cmd.inputFlags.getTestScript(),
        mainFilePath = cmd.inputFlags.getSourceFile(),
        dependencyFiles = ImmutableList.of(),
      ) {
        facadeFactory.computeLanguageKindOrThrow(it)
      }
    val parserFacade =
      facadeFactory
        .getParserFacadeListForOrNull(
          inputs.initiallyDeterminedMainDataKind,
        )!!
        .defaultParserFacade
        .create()
    val driver =
      RegularProgramReductionDriver.create(
        globalContext,
        cmd,
        inputs,
        parserFacade,
        codeFormatControl = inputs.initiallyDeterminedMainDataKind.defaultCodeFormatControl,
        listenerManager = listenerManager,
        shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
      )
    driver.reduce()
    val backup =
      sourceFile.parent.listDirectoryEntries().filter {
        it.name.startsWith(sourceFile.name) && it.name.endsWith(".orig")
      }
    assertThat(backup.size).isEqualTo(1)
    assertThat(backup[0].readText()).isEqualTo(sourceFile.readText())
  }

  private fun createConfigGivenCmd(cmd: CommandOptions): ReductionConfiguration {
    val inputs =
      RegularReductionInputs.create(
        testScriptPath = cmd.inputFlags.getTestScript(),
        mainFilePath = cmd.inputFlags.getSourceFile(),
        dependencyFiles = ImmutableList.of(),
      ) {
        facadeFactory.computeLanguageKindOrThrow(it)
      }
    val languageKind = inputs.initiallyDeterminedMainDataKind
    val lexerAtnWrapper =
      facadeFactory
        .getParserFacadeListForOrNull(languageKind)!!
        .defaultParserFacade
        .create()
        .lexerAtnWrapper
    val ioManager =
      RegularProgramReductionDriver.createIOManager(
        inputs,
        cmd.resultOutputFlags,
        codeFormatControl =
          cmd.reductionControlFlags.codeFormat
            ?: inputs.initiallyDeterminedMainDataKind.defaultCodeFormatControl,
        lexerAtnWrapper,
        shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
      )
    return createConfiguration(
      cmd,
      facadeFactory
        .getParserFacadeListForOrNull(languageKind)!!
        .defaultParserFacade
        .create(),
      ioManager.getDefaultProgramFormat(),
    )
  }

  @Test
  fun testEnableTestScriptExecutionCaching() {
    for (format in LanguageC.allowedCodeFormatControl) {
      val cmd =
        CommandOptions().apply {
          inputFlags.inputFile = sourceFile
          inputFlags.testScript = scriptFile
          reductionControlFlags.codeFormat = format
          cacheControlFlags.nodeActionSetCaching = true
          cacheControlFlags.queryCaching = EnumQueryCachingControl.TRUE
        }
      val config = createConfigGivenCmd(cmd)
      assertThat(config.enableDeprecatedQueryCaching).isTrue()
    }

    for (format in LanguageC.allowedCodeFormatControl) {
      val cmd =
        CommandOptions().apply {
          inputFlags.inputFile = sourceFile
          inputFlags.testScript = scriptFile
          reductionControlFlags.codeFormat = format
          cacheControlFlags.nodeActionSetCaching = true
          cacheControlFlags.queryCaching = EnumQueryCachingControl.FALSE
        }
      val config = createConfigGivenCmd(cmd)
      assertThat(config.enableDeprecatedQueryCaching).isFalse()
    }

    CommandOptions()
      .apply {
        inputFlags.inputFile = sourceFile
        inputFlags.testScript = scriptFile
        reductionControlFlags.codeFormat = EnumFormatControl.SINGLE_TOKEN_PER_LINE
        cacheControlFlags.nodeActionSetCaching = true
        cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
      }.let {
        val config = createConfigGivenCmd(it)
        assertThat(config.enableDeprecatedQueryCaching).isTrue()
      }

    CommandOptions()
      .apply {
        inputFlags.inputFile = sourceFile
        inputFlags.testScript = scriptFile
        reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
        cacheControlFlags.nodeActionSetCaching = true
        cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
      }.let {
        val config = createConfigGivenCmd(it)
        assertThat(config.enableDeprecatedQueryCaching).isFalse()
      }
  }

  @Test
  fun testStatsSnapshotEventEqualityAndHashcode() {
    val stats =
      StatsOfFilesBeingReduced(
        tokenCount = 1,
        characterCount = 1,
        fileContents = ImmutableList.of(),
      )
    val e1 =
      StatsSnapshotEvent(
        stats,
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      )
    val e2 =
      StatsSnapshotEvent(
        stats,
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      )
    assertThat(e1).isNotEqualTo(e2)
  }

  @Test
  fun testReducerCallEventEquality() {
    val reducer = PersesNodePrioritizedDfsReducer.META
    val e1 = ReducerCallEvent(reducer, exceptionStackTrace = null)
    val e2 = ReducerCallEvent(reducer, exceptionStackTrace = null)
    assertThat(e1).isNotEqualTo(e2)
  }

  @Test
  fun testReducerSchedulerGetAllReducerEventsBetween() {
    val stats =
      StatsOfFilesBeingReduced(
        tokenCount = 1,
        characterCount = 1,
        fileContents = ImmutableList.of(),
      )
    val reducer = PersesNodePrioritizedDfsReducer.META

    val history = ReducerScheduler.SchedulerEventHistory()
    val s1 =
      StatsSnapshotEvent(
        stats,
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      )
    val s2 =
      StatsSnapshotEvent(
        stats,
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      )
    val s3 =
      StatsSnapshotEvent(
        stats,
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      )
    val s4 =
      StatsSnapshotEvent(
        stats,
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      )

    val r1 = ReducerCallEvent(reducer, exceptionStackTrace = null)
    val r2 = ReducerCallEvent(reducer, exceptionStackTrace = null)
    val r3 = ReducerCallEvent(reducer, exceptionStackTrace = null)

    history.addStatsEvent(s1)
    history.addReducerCallEvent(r1, treeAfterReduction = null)
    history.addStatsEvent(s2)
    history.addReducerCallEvent(r2, treeAfterReduction = null)
    history.addStatsEvent(s3)
    history.addReducerCallEvent(r3, treeAfterReduction = null)
    history.addStatsEvent(s4)

    assertThat(history.findAllReducerEventsBetween(s1, s4)).containsExactly(r1, r2, r3).inOrder()
    assertThat(history.findAllReducerEventsBetween(s2, s3)).containsExactly(r2).inOrder()
  }

  @Test
  fun testTokenSizeCheckWorks() {
    val reducer =
      object : ReducerAnnotation(
        shortName = "fake",
        description = "fake",
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
        override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> {
          TODO("Not yet implemented")
        }
      }
    val history = ReducerScheduler.SchedulerEventHistory()
    history.addStatsEvent(
      StatsSnapshotEvent(
        StatsOfFilesBeingReduced(
          tokenCount = 1,
          characterCount = 1,
          fileContents = ImmutableList.of(),
        ),
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      ),
    )
    history.addReducerCallEvent(
      ReducerCallEvent(reducer, exceptionStackTrace = null),
      treeAfterReduction = null,
    )
    val exception =
      assertThrows(Exception::class.java) {
        history.addStatsEvent(
          StatsSnapshotEvent(
            StatsOfFilesBeingReduced(
              tokenCount = 100,
              characterCount = 100,
              fileContents = ImmutableList.of(),
            ),
            numberOfNonDeletionIterations = 0,
            fileContentChangedWrtPrevious = true,
          ),
        )
      }
    assertThat(exception.message).contains("The reducer cannot increase the token count")
  }

  @Test
  fun testCreateConfigurationForNonExistingFiles() {
    val cmd = CommandOptions()
    cmd.inputFlags.inputFile = Paths.get("t.c")
    cmd.inputFlags.testScript = Paths.get("r.sh")
    try {
      createConfigGivenCmd(cmd)
    } catch (e: RuntimeException) {
      // Keep this. This is just capture a bug when only "t.c" and "r.sh" were given without parent
      // folders.
      assertThat(e.message).contains("The file should be a regular file")
    }
  }
}
