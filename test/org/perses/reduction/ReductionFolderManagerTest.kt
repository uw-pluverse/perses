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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCLexer
import org.perses.program.EnumFormatControl
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.RegularReductionInputs
import org.perses.reduction.io.token.RegularOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.AutoDeletableFolder
import java.nio.file.Files
import java.nio.file.Paths

@RunWith(JUnit4::class)
class ReductionFolderManagerTest {

  private val tempDir =
    AutoDeletableFolder.createTempDirWithClassNameAsPrefix(this)

  private val testScript = ScriptFile(Paths.get("test_data/delta_1/r.sh"))
  private val sourceFile = SourceFile(Paths.get("test_data/delta_1/t.c"), LanguageC)
  private val lexerAtnWrapper = LexerAtnWrapper(PnfCLexer::class.java)
  val reductionInputs = RegularReductionInputs(testScript, sourceFile)
  val outputManagerFactory = RegularOutputManagerFactory(
    reductionInputs,
    EnumFormatControl.COMPACT_ORIG_FORMAT,
    lexerAtnWrapper,
  )
  private val outputDir = tempDir.file.resolve("perses_output_dir")
  val ioManager = TokenReductionIOManager(
    workingFolder = tempDir.file,
    reductionInputs = reductionInputs,
    outputManagerFactory = outputManagerFactory,
    outputDirectory = outputDir,
  )
  private val manager = ioManager.lazilyInitializedReductionFolderManager

  @After
  fun teardown() {
    tempDir.close()
  }

  @Test
  fun test() {
    val rootFolder = manager.rootFolder
    assertThat(rootFolder.fileName.toString()).startsWith("PersesTempRoot_t.c_r.sh_")

    val firstFolder = manager.createNextFolder()
    assertThat(firstFolder.folder.fileName.toString()).isEqualTo("000000")
    testFolder(firstFolder)
    val secondFolder = manager.createNextFolder()
    testFolder(secondFolder)
    assertThat(secondFolder.folder.fileName.toString()).isEqualTo("000001")
  }

  @Test
  fun testDeleteAllOtherFiles() {
    val folder = manager.createNextFolder()
    Files.createFile(folder.folder.resolve(sourceFile.baseName))
    Files.createFile(folder.folder.resolve("extra"))
    assertThat(folder.folder.toFile().listFiles()!!).hasLength(3)
    folder.deleteAllOtherFiles()
    assertThat(
      folder.folder.toFile().listFiles()!!.map { it.name },
    ).containsExactly(
      sourceFile.baseName,
      testScript.baseName,
    )
  }

  @Test
  fun testComputeAbsPathForOrigFile() {
    val folder = manager.createNextFolder()
    val path = folder.computeAbsPathForOrigFile(sourceFile)
    assertThat(path).isEqualTo(folder.folder.resolve("t.c"))

    Assert.assertThrows(Exception::class.java) {
      folder.computeAbsPathForOrigFile(SourceFile(Paths.get("t.c"), LanguageC))
    }
  }

  private fun testFolder(folder: ReductionFolder) {
    assertThat(folder.folder.parent.toAbsolutePath())
      .isEqualTo(manager.rootFolder)

    assertThat(folder.testScript.scriptFile.parent.toAbsolutePath())
      .isEqualTo(folder.folder.toAbsolutePath())
    assertThat(folder.testScript.scriptFile.fileName.toString()).isEqualTo("r.sh")
  }
}
