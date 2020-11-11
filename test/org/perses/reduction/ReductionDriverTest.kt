/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.CommandOptions
import org.perses.grammar.ParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.program.EnumFormatControl
import org.perses.reduction.ReducerFactory.defaultReductionAlgName
import org.perses.reduction.ReductionDriver.Companion.booleanToEnabledOrDisabled
import org.perses.reduction.ReductionDriver.Companion.createConfiguration
import java.io.File

@RunWith(JUnit4::class)
class ReductionDriverTest {

  private val workDir = Files.createTempDir()

  @After
  fun teardown() {
    workDir.deleteRecursively()
  }

  @Test
  fun testBooleanToEnabledOrDisabled() {
    assertThat(booleanToEnabledOrDisabled(true)).isEqualTo("enabled")
    assertThat(booleanToEnabledOrDisabled(false)).isEqualTo("disabled")
  }

  @Test
  fun test() {
    val sourceFile = File(workDir, "t.c").apply { check(createNewFile()) }
    val scriptFile = File(workDir, "r.sh").apply {
      check(createNewFile())
      check(setExecutable(true))
      writeText("#!/usr/bin/env bash")
    }

    for (format in EnumFormatControl.values()) {
      val cmd = CommandOptions(defaultReductionAlgName).apply {
        compulsoryFlags.inputFile = sourceFile.absolutePath
        compulsoryFlags.testScript = scriptFile.absolutePath
        reductionControlFlags.codeFormat = format
        cacheControlFlags.nodeActionSetCaching = true
        cacheControlFlags.queryCaching = EnumQueryCachingControl.TRUE
      }
      val config = createConfiguration(cmd, builderWithBuiltinLanguages().build())
      assertThat(config.enableTestScriptExecutionCaching).isTrue()
    }

    for (format in EnumFormatControl.values()) {
      val cmd = CommandOptions(defaultReductionAlgName).apply {
        compulsoryFlags.inputFile = sourceFile.absolutePath
        compulsoryFlags.testScript = scriptFile.absolutePath
        reductionControlFlags.codeFormat = format
        cacheControlFlags.nodeActionSetCaching = true
        cacheControlFlags.queryCaching = EnumQueryCachingControl.FALSE
      }
      val config = createConfiguration(cmd, builderWithBuiltinLanguages().build())
      assertThat(config.enableTestScriptExecutionCaching).isFalse()
    }

    CommandOptions(defaultReductionAlgName).apply {
      compulsoryFlags.inputFile = sourceFile.absolutePath
      compulsoryFlags.testScript = scriptFile.absolutePath
      reductionControlFlags.codeFormat = EnumFormatControl.SINGLE_TOKEN_PER_LINE
      cacheControlFlags.nodeActionSetCaching = true
      cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
    }.let {
      val config = createConfiguration(it, builderWithBuiltinLanguages().build())
      assertThat(config.enableTestScriptExecutionCaching).isTrue()
    }

    CommandOptions(defaultReductionAlgName).apply {
      compulsoryFlags.inputFile = sourceFile.absolutePath
      compulsoryFlags.testScript = scriptFile.absolutePath
      reductionControlFlags.codeFormat = EnumFormatControl.COMPACT_ORIG_FORMAT
      cacheControlFlags.nodeActionSetCaching = true
      cacheControlFlags.queryCaching = EnumQueryCachingControl.AUTO
    }.let {
      val config = createConfiguration(it, builderWithBuiltinLanguages().build())
      assertThat(config.enableTestScriptExecutionCaching).isFalse()
    }
  }

  @Test
  fun testCreateConfigurationForNonExistingFiles() {
    val cmd = CommandOptions(defaultReductionAlgName)
    cmd.compulsoryFlags.inputFile = "t.c"
    cmd.compulsoryFlags.testScript = "r.sh"
    try {
      createConfiguration(
        cmd, builderWithBuiltinLanguages().build()
      )
    } catch (e: RuntimeException) {
      // Keep this. This is just capture a bug when only "t.c" and "r.sh" were given without parent
      // folders.
      assertThat(e.message).contains("The file should be a regular file")
    }
  }
}
