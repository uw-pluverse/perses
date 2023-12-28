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
import org.perses.reduction.AbstractProgramReductionDriver.Companion.boolToString
import org.perses.reduction.AbstractProgramReductionDriver.Companion.createConfiguration
import org.perses.reduction.AbstractProgramReductionDriver.StatsOfFilesBeingReduced
import org.perses.reduction.ReducerFactory.defaultReductionAlgName
import org.perses.reduction.ReducerScheduler.ReducerCallEvent
import org.perses.reduction.ReducerScheduler.StatsSnapshotEvent
import org.perses.reduction.cache.EnumQueryCachingControl
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.util.Util
import java.nio.file.Files
import kotlin.io.path.absolutePathString
import kotlin.io.path.appendText
import kotlin.io.path.createFile
import kotlin.io.path.listDirectoryEntries
import kotlin.io.path.name
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class RegularProgramReductionDriverTest {

  private val workDir = Files.createTempDirectory("ReductionDriverTest_")
  private val sourceFile = workDir.resolve("t.c").apply {
    this.createFile()
    check(Files.exists(this))
  }
  private val scriptFile = workDir.resolve("r.sh").apply {
    this.createFile()
    check(Files.exists(this))
    Util.setExecutable(this)
    check(Files.isExecutable(this))
    this.writeText("#!/usr/bin/env bash\n")
  }
  private val facadeFactory = builderWithBuiltinLanguages().build()

  @After
  fun teardown() {
    workDir.toFile().deleteRecursively()
  }

  @Test
  fun testBooleanToEnabledOrDisabled() {
    assertThat(boolToString(true)).isEqualTo("enabled")
    assertThat(boolToString(false)).isEqualTo("disabled")
  }

  @Test
  fun test_does_not_npe_when_language_cannot_be_detected() {
    val cmd = CommandOptions(defaultReductionAlgName).apply {
      inputFlags.inputFile = scriptFile.absolutePathString()
      inputFlags.testScript = scriptFile.absolutePathString()
    }
    val exception = assertThrows(IllegalStateException::class.java) {
      val inputs = RegularProgramReductionDriver.createReductionInputs(
        facadeFactory,
        cmd.inputFlags,
      )
      val lexerAtnWrapper = facadeFactory.createParserFacade(inputs.mainDataKind).lexerAtnWrapper
      RegularProgramReductionDriver.createIOManager(
        inputs,
        cmd.reductionControlFlags,
        cmd.resultOutputFlags,
        lexerAtnWrapper,
      )
    }
    assertThat(exception.message)
      .startsWith("Failed to detect the language kind for")
  }

  @Test
  fun test_backupMainFile() {
    val cmd = CommandOptions(defaultReductionAlgName).apply {
      inputFlags.inputFile = sourceFile.absolutePathString()
      inputFlags.testScript = scriptFile.absolutePathString()
    }
    sourceFile.writeText("a;")
    scriptFile.appendText(
      """
      |grep "a" ${sourceFile.fileName}
      |
      """.trimMargin(),
    )
    val driver = RegularProgramReductionDriver.create(cmd, facadeFactory)
    driver.reduce()
    val backup = sourceFile.parent.listDirectoryEntries().filter {
      it.name.startsWith(sourceFile.name) && it.name.endsWith(".orig")
    }
    assertThat(backup.size).isEqualTo(1)
    assertThat(backup[0].readText()).isEqualTo(sourceFile.readText())
  }

  private fun createConfigGivenCmd(cmd: CommandOptions): ReductionConfiguration {
    val inputs = RegularProgramReductionDriver.createReductionInputs(
      facadeFactory,
      cmd.inputFlags,
    )
    val languageKind = inputs.mainDataKind
    val lexerAtnWrapper = facadeFactory.createParserFacade(languageKind).lexerAtnWrapper
    val ioManager = RegularProgramReductionDriver.createIOManager(
      inputs,
      cmd.reductionControlFlags,
      cmd.resultOutputFlags,
      lexerAtnWrapper,
    )
    return createConfiguration(
      cmd,
      facadeFactory.createParserFacade(languageKind),
      ioManager.getDefaultProgramFormat(),
    )
  }

  @Test
  fun test_enableTestScriptExecutionCaching() {
    for (format in LanguageC.allowedCodeFormatControl) {
      val cmd = CommandOptions(defaultReductionAlgName).apply {
        inputFlags.inputFile = sourceFile.absolutePathString()
        inputFlags.testScript = scriptFile.absolutePathString()
        reductionControlFlags.codeFormat = format
        cacheControlFlags.nodeActionSetCaching = true
        cacheControlFlags.queryCaching = EnumQueryCachingControl.TRUE
      }
      val config = createConfigGivenCmd(cmd)
      assertThat(config.enableTestScriptExecutionCaching).isTrue()
    }

    for (format in LanguageC.allowedCodeFormatControl) {
      val cmd = CommandOptions(defaultReductionAlgName).apply {
        inputFlags.inputFile = sourceFile.absolutePathString()
        inputFlags.testScript = scriptFile.absolutePathString()
        reductionControlFlags.codeFormat = format
        cacheControlFlags.nodeActionSetCaching = true
        cacheControlFlags.queryCaching = EnumQueryCachingControl.FALSE
      }
      val config = createConfigGivenCmd(cmd)
      assertThat(config.enableTestScriptExecutionCaching).isFalse()
    }

    CommandOptions(defaultReductionAlgName).apply {
      inputFlags.inputFile = sourceFile.absolutePathString()
      inputFlags.testScript = scriptFile.absolutePathString()
      reductionControlFlags.codeFormat = EnumFormatControl.SINGLE_TOKEN_PER_LINE
      cacheControlFlags.nodeActionSetCaching = true
      cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
    }.let {
      val config = createConfigGivenCmd(it)
      assertThat(config.enableTestScriptExecutionCaching).isTrue()
    }

    CommandOptions(defaultReductionAlgName).apply {
      inputFlags.inputFile = sourceFile.absolutePathString()
      inputFlags.testScript = scriptFile.absolutePathString()
      reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      cacheControlFlags.nodeActionSetCaching = true
      cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
    }.let {
      val config = createConfigGivenCmd(it)
      assertThat(config.enableTestScriptExecutionCaching).isFalse()
    }
  }

  @Test
  fun testStatsSnapshotEventEqualityAndHashcode() {
    val stats = StatsOfFilesBeingReduced(
      tokenCount = 1,
      fileContents = ImmutableList.of(),
    )
    val e1 = StatsSnapshotEvent(stats)
    val e2 = StatsSnapshotEvent(stats)
    assertThat(e1).isNotEqualTo(e2)
  }

  @Test
  fun testReducerCallEventEquality() {
    val reducer = PersesNodePrioritizedDfsReducer.META
    val e1 = ReducerCallEvent(reducer)
    val e2 = ReducerCallEvent(reducer)
    assertThat(e1).isNotEqualTo(e2)
  }

  @Test
  fun testReducerSchedulerGetAllReducerEventsBetween() {
    val stats = StatsOfFilesBeingReduced(
      tokenCount = 1,
      fileContents = ImmutableList.of(),
    )
    val reducer = PersesNodePrioritizedDfsReducer.META

    val history = ReducerScheduler.SchedulerEventHistory()
    val s1 = StatsSnapshotEvent(stats)
    val s2 = StatsSnapshotEvent(stats)
    val s3 = StatsSnapshotEvent(stats)
    val s4 = StatsSnapshotEvent(stats)

    val r1 = ReducerCallEvent(reducer)
    val r2 = ReducerCallEvent(reducer)
    val r3 = ReducerCallEvent(reducer)

    history.add(s1)
    history.add(r1)
    history.add(s2)
    history.add(r2)
    history.add(s3)
    history.add(r3)
    history.add(s4)

    assertThat(history.getAllReducerEventsBetween(s1, s4)).containsExactly(r1, r2, r3).inOrder()
    assertThat(history.getAllReducerEventsBetween(s2, s3)).containsExactly(r2).inOrder()
  }

  @Test
  fun testTokenSizeCheckWorks() {
    val reducer = object : ReducerAnnotation(
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
    history.add(
      StatsSnapshotEvent(
        StatsOfFilesBeingReduced(tokenCount = 1, fileContents = ImmutableList.of()),
      ),
    )
    history.add(ReducerCallEvent(reducer))
    val exception = assertThrows(Exception::class.java) {
      history.add(
        StatsSnapshotEvent(
          StatsOfFilesBeingReduced(tokenCount = 100, fileContents = ImmutableList.of()),
        ),
      )
    }
    assertThat(exception.message).contains("The reducer cannot increase the token count")
  }

  @Test
  fun testCreateConfigurationForNonExistingFiles() {
    val cmd = CommandOptions(defaultReductionAlgName)
    cmd.inputFlags.inputFile = "t.c"
    cmd.inputFlags.testScript = "r.sh"
    try {
      createConfigGivenCmd(cmd)
    } catch (e: RuntimeException) {
      // Keep this. This is just capture a bug when only "t.c" and "r.sh" were given without parent
      // folders.
      assertThat(e.message).contains("The file should be a regular file")
    }
  }
}
