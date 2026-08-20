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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.PersesCommandOptions
import org.perses.cmd.CacheControlFlagGroup
import org.perses.cmd.ProfilingFlagGroup
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.grammar.c.LanguageC
import org.perses.program.ProgramSize
import org.perses.reduction.AbstractProgramReductionDriver.Companion.createConfiguration
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.reduction.scheduler.AbstractSchedulerEvent.ReducerCallEvent
import org.perses.reduction.scheduler.AbstractSchedulerEvent.StatsSnapshotEvent
import org.perses.reduction.scheduler.ReducerScheduler
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.shell.Shells
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.createFile
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class RegularProgramReductionDriverTest {
  private val workDir = Util.createTempDirForObject(this)
  private val outputDir =
    workDir.resolve("default_test_output_dir").apply {
      Util.ensureDirExists(this)
    }
  private val inputDir =
    workDir.resolve("input_dir").apply {
      Util.ensureDirExists(this)
    }
  private val sourceFile =
    inputDir.resolve("t.c").apply {
      this.createFile()
      check(Files.exists(this))
    }
  private val scriptFile =
    inputDir.resolve("r.sh").apply {
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

  // The query cache the per-file driver is given; this test owns it (the driver does not), so it is
  // closed in teardown -- before globalContext, whose stream pool asserts every stream was returned.
  // Caching uses default settings (the cache depends only on these flag groups, not the inputs).
  private val queryCacheManager =
    QueryCacheManager.create(ProfilingFlagGroup(), CacheControlFlagGroup(), globalContext)

  @After
  fun teardown() {
    queryCacheManager.close()
    workDir.toFile().deleteRecursively()
    listenerManager.close()
    globalContext.close()
  }

  @Test
  fun testDoesNotThrowNpeWhenLanguageCannotBeDetected() {
    val cmd =
      PersesCommandOptions().apply {
        inputFlags.setInputFiles(listOf(scriptFile))
        inputFlags.testScript = scriptFile
      }
    val exception =
      assertThrows(IllegalStateException::class.java) {
        DefaultLanguageOriginalReductionInputs.create(
          testScriptPath = cmd.inputFlags.getTestScript(),
          // This test deliberately reduces the test script itself (a file whose language cannot be
          // detected). computeInputFiles would exclude the test script, so use the path directly.
          sourceFilePaths = ImmutableList.of(scriptFile),
          dependencyFiles = ImmutableList.of(),
        ) {
          facadeFactory.computeLanguageKindOrThrow(it)
        }
      }
    assertThat(exception.message)
      .startsWith("Failed to detect the language kind for")
  }

  private fun createConfigGivenCmd(cmd: PersesCommandOptions): ReductionConfiguration {
    val inputs =
      DefaultLanguageOriginalReductionInputs.create(
        testScriptPath = cmd.inputFlags.getTestScript(),
        sourceFilePaths = ImmutableList.of(cmd.inputFlags.computeInputFiles().single()),
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
    val outputManagerFactory =
      RegularProgramReductionDriver.createOutputManagerFactory(
        originalReductionInputs = inputs,
        codeFormatControl =
          cmd.reductionControlFlags.codeFormat
            ?: inputs.initiallyDeterminedMainDataKind.defaultCodeFormatControl,
        lexerAtnWrapper = lexerAtnWrapper,
        shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
        mainFile = inputs.mutableFiles.single(),
        // Single mutable file under reduction, so there are no siblings.
        otherMutableFileContents = ImmutableMap.of(),
      )
    return createConfiguration(
      cmd,
      facadeFactory
        .getParserFacadeListForOrNull(languageKind)!!
        .defaultParserFacade
        .create(),
      outputManagerFactory.defaultCodeFormatControl,
    )
  }

  @Test
  fun testEnableTestScriptExecutionCaching() {
    for (format in LanguageC.allowedCodeFormatControl) {
      val cmd =
        PersesCommandOptions().apply {
          inputFlags.setInputFiles(listOf(sourceFile))
          inputFlags.testScript = scriptFile
          reductionControlFlags.codeFormat = format
          cacheControlFlags.nodeActionSetCaching = true
          cacheControlFlags.queryCaching = true
        }
      val config = createConfigGivenCmd(cmd)
      assertThat(config.enableDeprecatedQueryCaching).isTrue()
    }

    for (format in LanguageC.allowedCodeFormatControl) {
      val cmd =
        PersesCommandOptions().apply {
          inputFlags.setInputFiles(listOf(sourceFile))
          inputFlags.testScript = scriptFile
          reductionControlFlags.codeFormat = format
          cacheControlFlags.nodeActionSetCaching = true
          cacheControlFlags.queryCaching = false
        }
      val config = createConfigGivenCmd(cmd)
      assertThat(config.enableDeprecatedQueryCaching).isFalse()
    }
  }

  @Test
  fun testStatsSnapshotEventEqualityAndHashcode() {
    val stats =
      StatsOfFilesBeingReduced(
        size =
          ProgramSize(
            payload = Unit,
            canonicalTokenCount = 1,
            surrogateTokenCount = 1,
            totalCharacterCount = 1,
            nonBlankCharacterCount = 1,
          ),
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
    val reducer = PersesNodeReducerAnnotations.PrioritizedDfs
    val e1 = ReducerCallEvent(reducer, exceptionStackTrace = null)
    val e2 = ReducerCallEvent(reducer, exceptionStackTrace = null)
    assertThat(e1).isNotEqualTo(e2)
  }

  @Test
  fun testReducerSchedulerGetAllReducerEventsBetween() {
    val stats =
      StatsOfFilesBeingReduced(
        size =
          ProgramSize(
            payload = Unit,
            canonicalTokenCount = 1,
            surrogateTokenCount = 1,
            totalCharacterCount = 1,
            nonBlankCharacterCount = 1,
          ),
        fileContents = ImmutableList.of(),
      )
    val reducer = PersesNodeReducerAnnotations.PrioritizedDfs

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
    history.addReducerCallEvent(r1, programSizeAfterReduction = null)
    history.addStatsEvent(s2)
    history.addReducerCallEvent(r2, programSizeAfterReduction = null)
    history.addStatsEvent(s3)
    history.addReducerCallEvent(r3, programSizeAfterReduction = null)
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
        override fun create(
          reducerContext: ReducerContext,
        ): ImmutableList<AbstractSparTreeReducer> {
          TODO("Not yet implemented")
        }
      }
    val history = ReducerScheduler.SchedulerEventHistory()
    history.addStatsEvent(
      StatsSnapshotEvent(
        StatsOfFilesBeingReduced(
          size =
            ProgramSize(
              payload = Unit,
              canonicalTokenCount = 1,
              surrogateTokenCount = 1,
              totalCharacterCount = 1,
              nonBlankCharacterCount = 1,
            ),
          fileContents = ImmutableList.of(),
        ),
        numberOfNonDeletionIterations = 0,
        fileContentChangedWrtPrevious = true,
      ),
    )
    history.addReducerCallEvent(
      ReducerCallEvent(reducer, exceptionStackTrace = null),
      programSizeAfterReduction = null,
    )
    val exception =
      assertThrows(Exception::class.java) {
        history.addStatsEvent(
          StatsSnapshotEvent(
            StatsOfFilesBeingReduced(
              size =
                ProgramSize(
                  payload = Unit,
                  canonicalTokenCount = 100,
                  surrogateTokenCount = 100,
                  totalCharacterCount = 100,
                  nonBlankCharacterCount = 100,
                ),
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
    val cmd = PersesCommandOptions()
    cmd.inputFlags.setInputFiles(listOf(Paths.get("t.c")))
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
