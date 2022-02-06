/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.reduction.ReducerFactory.defaultReductionAlgName
import org.perses.reduction.cache.EnumQueryCachingControl
import org.perses.reduction.io.token.TokenReductionIOManager
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
      createIOManager(cmd)
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
    """.trimMargin()
    )
    val driver = RegularProgramReductionDriver.create(cmd, facadeFactory)
    driver.reduce()
    val backup = sourceFile.parent.listDirectoryEntries().filter {
      it.name.startsWith(sourceFile.name) && it.name.endsWith(".orig")
    }
    assertThat(backup.size).isEqualTo(1)
    assertThat(backup[0].readText()).isEqualTo(sourceFile.readText())
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
      val ioManager = createIOManager(cmd)
      val config = createConfiguration(
        cmd,
        facadeFactory,
        ioManager.reductionInputs.mainLanguage,
        ioManager.getDefaultProgramFormat()
      )
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
      val ioManager = createIOManager(cmd)
      val config = createConfiguration(
        cmd,
        facadeFactory,
        ioManager.reductionInputs.mainLanguage,
        ioManager.getDefaultProgramFormat()
      )
      assertThat(config.enableTestScriptExecutionCaching).isFalse()
    }

    CommandOptions(defaultReductionAlgName).apply {
      inputFlags.inputFile = sourceFile.absolutePathString()
      inputFlags.testScript = scriptFile.absolutePathString()
      reductionControlFlags.codeFormat = EnumFormatControl.SINGLE_TOKEN_PER_LINE
      cacheControlFlags.nodeActionSetCaching = true
      cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
    }.let {
      val ioManager = createIOManager(it)
      val config = createConfiguration(
        it,
        facadeFactory,
        ioManager.reductionInputs.mainLanguage,
        ioManager.getDefaultProgramFormat()
      )
      assertThat(config.enableTestScriptExecutionCaching).isTrue()
    }

    CommandOptions(defaultReductionAlgName).apply {
      inputFlags.inputFile = sourceFile.absolutePathString()
      inputFlags.testScript = scriptFile.absolutePathString()
      reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      cacheControlFlags.nodeActionSetCaching = true
      cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
    }.let {
      val factory = builderWithBuiltinLanguages().build()
      val ioManager = createIOManager(it)
      val config = createConfiguration(
        it,
        factory,
        ioManager.reductionInputs.mainLanguage,
        ioManager.getDefaultProgramFormat()
      )
      assertThat(config.enableTestScriptExecutionCaching).isFalse()
    }
  }

  @Test
  fun testCreateConfigurationForNonExistingFiles() {
    val cmd = CommandOptions(defaultReductionAlgName)
    cmd.inputFlags.inputFile = "t.c"
    cmd.inputFlags.testScript = "r.sh"
    try {
      val factory = builderWithBuiltinLanguages().build()
      val ioManager = createIOManager(cmd)
      createConfiguration(
        cmd,
        factory,
        ioManager.reductionInputs.mainLanguage,
        ioManager.getDefaultProgramFormat()
      )
    } catch (e: RuntimeException) {
      // Keep this. This is just capture a bug when only "t.c" and "r.sh" were given without parent
      // folders.
      assertThat(e.message).contains("The file should be a regular file")
    }
  }

  fun createIOManager(cmd: CommandOptions): TokenReductionIOManager {
    val inputs = RegularProgramReductionDriver.createReductionInputs(
      facadeFactory, cmd.inputFlags
    )
    return RegularProgramReductionDriver.createIOManager(
      inputs,
      cmd.reductionControlFlags,
      cmd.resultOutputFlags
    )
  }
}
