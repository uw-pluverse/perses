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

import com.google.common.base.Preconditions
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compilers.rust.RustcCrashDetector
import org.perses.fuzzer.config.CmdFlags
import org.perses.fuzzer.config.ProgramUnderTest
import org.perses.fuzzer.config.SeedFolder
import org.perses.fuzzer.config.TestingConfiguration
import org.perses.fuzzer.reduction.DeltaFolder
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.rust.LanguageRust
import org.perses.program.LanguageKind
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.shell.Shells
import java.io.File
import java.io.IOException
import java.io.UncheckedIOException

@RunWith(JUnit4::class)
class FuzzerDriverTest {

  private val workingDirectory = java.nio.file.Files.createTempDirectory(javaClass.simpleName)
    .toFile()

  @After
  fun teardown() {
    workingDirectory.deleteRecursively()
  }

  @Test
  fun test_system_testing_for_rustc_mock_1() {
    val rustcMock = "kitten/test/org/perses/fuzzer/rust/rustc_mock_1.sh"
    systemTestingWithRustcMock(rustcMock)
  }

  @Test
  fun test_system_testing_for_rustc_mock_2() {
    val rustcMock = "kitten/test/org/perses/fuzzer/rust/rustc_mock_2.sh"
    systemTestingWithRustcMock(rustcMock)
  }

  private fun systemTestingWithRustcMock(rustcMock: String) {
    val cmdOptions = CommandOptions()
    cmdOptions.compilerFlags.testingConfiguration = TestingConfiguration(
      language = "RUST",
      seedFolders = listOf(
        SeedFolder(
          path = File(workingDirectory, "seeds").apply {
            check(mkdirs())
          }.absolutePath,
          fileExtentions = listOf(".rs"),
        ),
      ),
      programsUnderTest = listOf(
        ProgramUnderTest(
          command = File(rustcMock).absolutePath,
          flagsToTest = listOf(CmdFlags.EMPTY),
          versionFlags = CmdFlags(listOf("--version", "--verbose")),
          crashDetectorClassName = RustcCrashDetector::class.java.canonicalName,
        ),
      ),
    )

    val findingsFolder = File(workingDirectory, "findings").apply {
      check(mkdirs())
    }

    cmdOptions.generalFlags.setFindingFolder(findingsFolder.absoluteFile)

    val driver = FuzzerDriver(
      cmdOptions,
      AdditionalFuzzerControl(1),
    )
    val facade = driver.facades.first()
    val action = facade.compilationActions.first()
    val mutantFile = File(workingDirectory, "t.rs").apply { createNewFile() }
    val seedFile = File(workingDirectory, "seed.rs").apply { createNewFile() }
    val seedProgram = getTokenizedProgram(seedFile, LanguageRust)

    assertThat(findingsFolder.list()).isEmpty()
    driver.testActionOnMutant(action, mutantFile, seedFile, seedProgram, facade.crashDetector)

    assertThat(driver.findingFolder.getAllCrashInstances()).hasSize(1)
    assertThat(findingsFolder.list()).hasLength(1)

    val foundBugFolder = findingsFolder.listFiles()[0]
    val crashInstance = CrashInstanceFolder(foundBugFolder)
    val deltaFolder = DeltaFolder(File(foundBugFolder, crashInstance.info().deltaFolderName))
    val reductionScriptFile = deltaFolder.scriptFile
    println(reductionScriptFile.readText())
    val cmdOutput = Shells.singleton.run(
      "./${deltaFolder.info().scriptFileName}",
      deltaFolder.folder.toPath(),
      captureOutput = true,
      environment = Shells.CURRENT_ENV,
    )
    assertThat(cmdOutput.exitCode.intValue).isEqualTo(0)
  }

  @Test
  fun test_collectSeedFilesRecursively() {
    val fa = createFile(workingDirectory, "a.rs")
    val fb = createFile(workingDirectory, "b.cc")

    val da = createDirectory(workingDirectory, "dir_a")
    val fc = createFile(da, "c.rs")
    val fd = createFile(da, "d.cc")

    val rsFiles = FuzzerDriver.collectSeedFilesRecursively(
      listOf(SeedFolder(workingDirectory.absolutePath, listOf(".rs"))),
    )
    assertThat(rsFiles).hasSize(2)
    assertThat(rsFiles).containsExactly(fa, fc).inOrder()

    val ccFiles = FuzzerDriver.collectSeedFilesRecursively(
      listOf(SeedFolder(workingDirectory.absolutePath, listOf(".cc"))),
    )
    assertThat(ccFiles).hasSize(2)
    assertThat(ccFiles).containsExactly(fb, fd).inOrder()
  }

  @Test
  fun testGetMutantFileName() {
    assertThat(FuzzerDriver.getMutantFileName("a.cc"))
      .isEqualTo("mutant.cc")
  }

  companion object {

    private fun createDirectory(parent: File, name: String): File {
      val file = File(parent, name)
      Preconditions.checkState(file.mkdir())
      return file
    }

    private fun createFile(parent: File, name: String): File {
      return try {
        val file = File(parent, name)
        Preconditions.checkState(file.createNewFile())
        file
      } catch (e: IOException) {
        throw UncheckedIOException(e)
      }
    }

    fun getTokenizedProgram(file: File, language: LanguageKind): TokenizedProgram {
      val parserFacade = SingleParserFacadeFactory
        .builderWithBuiltinLanguages()
        .build()
        .getParserFacadeListForOrNull(language)!!
        .defaultParserFacade.create()

      val treeByOpt = parserFacade.parseFile(file.toPath())
      val tokens = AbstractParserFacade.getTokens(treeByOpt.tree)
      val tokenizedProgramFactory = TokenizedProgramFactory.createFactory(
        tokens,
        parserFacade.language,
      )
      val sparTreeNodeFactory = SparTreeNodeFactory(
        parserFacade.metaTokenInfoDb,
        tokenizedProgramFactory,
        parserFacade.ruleHierarchy,
      )
      val sparTree = SparTreeBuilder(
        sparTreeNodeFactory,
        treeByOpt,
      ).result

      return sparTree.programSnapshot
    }
  }
}
