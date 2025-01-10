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
package org.perses.fuzzer.config

import com.google.common.truth.Truth
import org.junit.After
import org.junit.Test
import org.perses.fuzzer.compilers.DefaultCompilationConfigurationFacade
import org.perses.fuzzer.compilers.rust.RustcCrashDetector
import org.perses.grammar.SingleParserFacadeFactory
import java.io.File
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import kotlin.io.path.deleteRecursively

class RustcConfigurationTest {
  private val tempDir = Files.createTempDirectory(javaClass.simpleName)
  private var facade: DefaultCompilationConfigurationFacade
  private val parserFacadeFactory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
  init {
    val testingConfiguration = TestingConfiguration(
      language = "RUST",
      seedFolders = listOf(
        SeedFolder(
          path = File(tempDir.toFile(), "seed_folder").apply {
            check(mkdirs())
          }.absolutePath,
          fileExtentions = listOf(".rs"),
        ),
      ),
      programsUnderTest = listOf(
        ProgramUnderTest(
          command = "rustc",
          flagsToTest = listOf(CmdFlags.EMPTY),
          versionFlags = CmdFlags(listOf("--version", "--verbose")),
          crashDetectorClassName = RustcCrashDetector::class.java.canonicalName,
        ),
      ),
    )
    facade = DefaultCompilationConfigurationFacade(
      languageKind = parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(
        testingConfiguration.language,
      )!!,
      programUnderTest = testingConfiguration.programsUnderTest[0],
    )
  }

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testRustcCompilationActionCanCompile() {
    val rustFile = File(tempDir.toFile(), "test_program.rs")
    rustFile.writeText(
      """
        fn main() {
        }
      """.trimIndent(),
      StandardCharsets.UTF_8,
    )
    val cmdSet = HashSet<String>()
    val actions = facade.compilationActions
    for (action in actions) {
      val (cmdOutput, cmd) = action.compile(rustFile)
      Truth.assertWithMessage(cmd + "\n" + cmdOutput.stderr.combinedLines)
        .that(cmdOutput.exitCode.intValue).isEqualTo(0)
      cmdSet.add(cmd)
    }
    Truth.assertThat(cmdSet.size).isEqualTo(actions.size)
  }

  @Test
  fun testDefaultConstructCompileCmd() {
    val action = facade.compilationActions[0]
    val cmd = action.constructCompileCmd(File("test.rs"))
    Truth.assertThat(cmd.split(Regex("\\s+"))).containsExactly(
      "timeout",
      "-s",
      "9",
      "30",
      "rustc",
      "test.rs",
    ).inOrder()

    Truth.assertThat(action.getLanguage().name).isEqualTo("rust")
    Truth.assertThat(action.getVersion()).startsWith("rustc")
  }
}
