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
package org.perses.fuzzer.rust

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compilers.DefaultCompilationConfigurationFacade
import org.perses.fuzzer.compilers.rust.RustcCrashDetector
import org.perses.fuzzer.compilers.rust.RustcVersion
import org.perses.fuzzer.config.CmdFlags
import org.perses.fuzzer.config.ProgramUnderTest
import org.perses.fuzzer.config.SeedFolder
import org.perses.fuzzer.config.TestingConfiguration
import org.perses.grammar.SingleParserFacadeFactory
import java.io.File
import java.nio.file.Files
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class RustcVersionTest {

  private val workingDir = Files.createTempDirectory(javaClass.simpleName)
  private val parserFacadeFactory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()

  @After
  fun teardown() {
    workingDir.deleteRecursively()
  }

  @Test
  fun testVersionStrings() {
    assertThat(RustcVersion.VERSION_STRINGS).isNotEmpty()
    assertThat(RustcVersion.VERSIONS.size).isEqualTo(RustcVersion.VERSION_STRINGS.size)

    val file = File(workingDir.toFile(), "t.rs").apply {
      writeText("fn main() {}")
    }

    val first = RustcVersion.VERSIONS.firstOrNull { version ->
      try {
        val versionPrintFlag = version.versionFlag
        val testingConfiguration = TestingConfiguration(
          language = "RUST",
          seedFolders = listOf(
            SeedFolder(
              path = File(workingDir.toFile(), version.versionString).apply {
                check(mkdirs())
              }.absolutePath,
              fileExtentions = listOf(".rs"),
            ),
          ),
          programsUnderTest = listOf(
            ProgramUnderTest(
              command = "rustc",
              flagsToTest = listOf(CmdFlags.EMPTY),
              versionFlags = CmdFlags(listOf(versionPrintFlag, "--version", "--verbose")),
              crashDetectorClassName = RustcCrashDetector::class.java.canonicalName,
            ),
          ),
        )
        val facade = DefaultCompilationConfigurationFacade(
          languageKind = parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(
            testingConfiguration.language,
          )!!,
          programUnderTest = testingConfiguration.programsUnderTest[0],
        )
        val action = facade.compilationActions[0]
        val (cmdOutput, _) = action.compile(file)
        assertThat(cmdOutput.exitCode.intValue).isEqualTo(0)
        assertThat(action.getVersion()).contains(version.versionString)
        true
      } catch (e: java.lang.RuntimeException) {
        false
      }
    }
    assertThat(first).isNotNull()
  }

  @Test
  fun testParse() {
    assertThat(RustcVersion.parse("rustc +nightly").versionString)
      .isEqualTo("nightly")

    val firstAvailable = RustcVersion.getAllStables().firstOrNull {
      try {
        RustcVersion.parse(it.commandWithVersion)
        true
      } catch (e: RuntimeException) {
        e.printStackTrace()
        false
      }
    }
    check(firstAvailable != null) {
      RustcVersion.getAllStables().joinToString(separator = "\n")
    }
    val parsed = RustcVersion.parse(firstAvailable.commandWithVersion)
    assertThat(parsed.commandWithVersion).isEqualTo(firstAvailable.commandWithVersion)
  }
}
