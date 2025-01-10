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
package org.perses.fuzzer

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.rust.LanguageRust
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class SystemTest {

  val tempDir = Files.createTempDirectory(javaClass.simpleName)
  val rustTestUtil = RustTestUtil()
  val configurationFile = tempDir.resolve("testing_configuration.yaml").apply {
    rustTestUtil.testingConfiguration.writeToYamlFile(this)
  }
  val commonOptionsForNormalFuzzing = arrayOf(
    "--random-seed", "1",
    "--seed-limit", "1",
    "--finding-folder", rustTestUtil.getFindingFolder().root.toString(),
    "--temp-folder", tempDir.resolve("temp_folder").toString(),
    "--threads", "1",
    "--shuffle-seed", "true",
    "--testing-config", configurationFile.toString(),
    "--timeout", "5",
    "--max-iterations", "1",
    "--enable-deleting-on-random-positions", "true",
    "--enable-inserting-on-random-positions", "true",
    "--enable-splicing", "false",
    "--enable-replacing-identifier", "false",
    "--language-model", "N_DEPTH_TREE_MODEL",
    "--generator", "GUIDED_GENERATOR",
  )
  val commonOptionsForOnlyGeneratingMutants = arrayOf(
    "--random-seed", "1",
    "--seed-limit", "1",
    "--finding-folder", rustTestUtil.getFindingFolder().root.toString(),
    "--temp-folder", tempDir.resolve("temp_folder").toString(),
    "--threads", "1",
    "--shuffle-seed", "true",
    "--testing-config", configurationFile.toString(),
    "--timeout", "5",
    "--max-iterations", "1",
    "--max-recursions", "5",
    "--generator", "RANDOM_GENERATOR",
    "--enable-deleting-on-continuous-positions", "true",
    "--enable-inserting-on-continuous-positions", "true",
    "--enable-splicing", "true",
    "--enable-replacing-identifier", "true",
    "--enable-replacing-same-type-token", "true",
    "--fuzzer-mode", "ONLY_GENERATE_MUTANTS",
  )

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
    rustTestUtil.close()
  }

  @Test
  fun test() {
    val main = Main(convertCmdObject(commonOptionsForNormalFuzzing))
    main.run()
    val facades = main.facades
    assertThat(facades).hasSize(1)
    val first = facades.first()
    assertThat(first.compilationActions).hasSize(1)
    assertThat(first.compilationActions.first().getLanguage()).isEqualTo(LanguageRust)
  }

  private fun convertCmdObject(args: Array<String>): CommandOptions {
    val processor = CommandLineProcessor<CommandOptions>(
      cmdCreator = { CommandOptions() },
      programName = "test",
      args,
    )
    processor.process()
    return processor.cmd
  }

  @Test
  fun testExtension() {
    val extensionScript = tempDir.resolve("extension-script.sh").apply {
      this.writeText(
        """#!/usr/bin/env bash
        FILE=${'$'}1
        FOLDER=${'$'}2
        echo "hello" > ${'$'}{FOLDER}/result.txt
        """.trimIndent(),
      )
      Util.setExecutable(this)
    }
    val extensionScriptResultFolder = tempDir.resolve("extension-script-result-folder").apply {
      Files.createDirectory(this)
    }
    for (
    options in listOf(
      commonOptionsForNormalFuzzing,
      commonOptionsForOnlyGeneratingMutants,
    )
    ) {
      extensionScriptResultFolder.resolve("result.txt").writeText("")
      val cmd = options +
        arrayOf(
          "--extension-script",
          extensionScript.toString(),
          "--extension-result-folder",
          extensionScriptResultFolder.toString(),
        )
      val main = Main(convertCmdObject(cmd))
      main.run()
      val result =
        extensionScriptResultFolder.resolve("result.txt").readText(StandardCharsets.UTF_8).trim()
      assertThat(result).contains("hello")
    }
  }
}
