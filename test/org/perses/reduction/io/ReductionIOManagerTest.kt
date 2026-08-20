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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.SourceFile
import org.perses.reduction.io.AbstractReductionIOManager.Companion.getTempRootFolderName
import org.perses.util.toImmutableList
import java.nio.file.Files
import java.nio.file.Paths
import java.time.LocalDateTime
import kotlin.io.path.isDirectory
import kotlin.io.path.listDirectoryEntries
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ReductionIOManagerTest : CommonReductionIOManagerData(ReductionIOManagerTest::class.java) {
  @After
  fun teardown() {
    close()
  }

  // The reduction folder manager is no longer owned by the IO manager (AbstractMain owns the shared
  // one in production); these tests build a throwaway one over a fresh temp root.
  private fun newFolderManager(): ReductionFolderManager =
    ReductionFolderManager(inputs, Files.createTempDirectory(workingDir, "PersesTempRoot_"))

  @Test
  fun testWriteProgramToReductionFolder() {
    val manager = newFolderManager()
    val listDirEntries = { manager.rootFolder.listDirectoryEntries() }
    assertThat(listDirEntries()).isEmpty()
    val folder = manager.createNextFolder()
    assertThat(listDirEntries()).hasSize(1)

    val realFolder = folder.path
    val scriptFile = realFolder.listDirectoryEntries().single()
    assertThat(scriptFile.fileName.toString()).isEqualTo("r.sh")
    assertThat(Files.isExecutable(scriptFile))

    outputManagerFactory
      .createManagerFor(TestUtility.createTokenizedProgramFromString("int a;", LanguageC))
      .write(folder)
    assertThat(realFolder.listDirectoryEntries()).hasSize(2)
    val sourceFile = realFolder.resolve("t.c")
    assertThat(sourceFile.fileName.toString()).isEqualTo("t.c")
    assertThat(sourceFile.readText()).contains("int")
    assertThat(sourceFile.readText()).contains("a")
  }

  @Test
  fun testDigestOfOutputFilesWithoutMaterializingFiles() {
    val outputManager =
      outputManagerFactory.createManagerFor(
        TestUtility.createTokenizedProgramFromString("int a;", LanguageC),
      )
    val digest = outputManager.shaHashCode
    assertThat(digest.digest.toString()).isNotEmpty()
    assertThat(digest).isSameInstanceAs(outputManager.shaHashCode)
    outputManager.write(newFolderManager().createNextFolder())
    assertThat(digest).isSameInstanceAs(outputManager.shaHashCode)
  }

  @Test
  fun testWriteTestScriptTo() {
    val folder =
      tempDir.resolve("tmp").apply {
        Files.createDirectory(this)
      }
    assertThat(folder.listDirectoryEntries()).isEmpty()
    ioManager.originalReductionInputs.writeTestScriptTo(folder)

    val firstFile = folder.listDirectoryEntries().single()
    assertThat(firstFile.endsWith("r.sh")).isTrue()
    assertThat(Files.isExecutable(firstFile)).isTrue()
  }

  @Test
  fun testGetExistingInputFileRelativePathsInOmitsDeletedFiles() {
    val secondSourceFile =
      SourceFile(
        tempDir.resolve("another_t.c").apply { writeText("int b;") },
        LanguageC,
      )
    val multiFileReductionInputs =
      DefaultLanguageOriginalReductionInputs(
        testScript = script,
        mutableFiles = ImmutableList.of(sourceFile, secondSourceFile),
        immutableDependencyFiles = ImmutableList.of(),
      )

    class DummyReductionIOManager :
      AbstractReductionIOManager<String, DummyReductionIOManager>(
        workingDirectory = workingDir,
        originalReductionInputs = multiFileReductionInputs,
        resultFolder =
          ReductionFolder(
            multiFileReductionInputs,
            Files.createDirectories(tempDir.resolve("result_for_basenames")),
          ),
      )
    val ioManager = DummyReductionIOManager()
    ioManager.resultFolder
      .computeAbsPathForOrigFile(sourceFile)
      .writeText(sourceFile.textualFileContent)
    ioManager.resultFolder
      .computeAbsPathForOrigFile(secondSourceFile)
      .writeText(secondSourceFile.textualFileContent)

    // A full folder yields every input file (so the format pass behaves exactly as before).
    assertThat(
      ioManager.getExistingInputFileRelativePathsIn(ioManager.resultFolder).map { it.toString() },
    ).containsExactly("t.c", "another_t.c")

    // After a deletion the folder is a subset; the dropped file is omitted rather than asserted.
    ioManager.resultFolder.deleteMutableFile(sourceFile)
    assertThat(
      ioManager.getExistingInputFileRelativePathsIn(ioManager.resultFolder).map { it.toString() },
    ).containsExactly("another_t.c")
  }

  @Test
  fun testGetTempRootFolderName() {
    val expectedPrefix = "PersesTempRoot_t.c_r.sh_20000121_010203_"

    (0..10)
      .map {
        val time = LocalDateTime.of(2000, 1, 21, 1, 2, 3)
        val name =
          getTempRootFolderName(
            ImmutableList.of(Paths.get("t.c")),
            "r.sh",
            time,
            currentProcessID = 11,
          )
        assertThat(name).startsWith(expectedPrefix)
        assertThat(name.length).isGreaterThan(expectedPrefix.length)
        assertThat(name).contains("pid_11")
        name
      }.toImmutableList()
      .let {
        val set = it.toHashSet()
        assertThat(set).containsExactlyElementsIn(it)
      }
  }

  @Test
  fun testGetScriptFileBaseNameIn() {
    val manager = newFolderManager()
    val folder = manager.createNextFolder()
    assertThat(ioManager.getScriptFileBaseNameIn(folder)).isEqualTo("r.sh")
  }

  @Test
  fun testCreateOutputManagerForOriginalInput() {
    val folder = newFolderManager().createNextFolder()
    val originalOutputManager = outputManagerFactory.createOutputManagerForOriginalInput()
    originalOutputManager.write(folder)

    val sourceFileInFolder = folder.path.resolve(sourceFile.baseName)
    assertThat(Files.exists(sourceFileInFolder)).isTrue()
    assertThat(sourceFileInFolder.readText()).isEqualTo(sourceFile.textualFileContent)
  }

  @Test
  fun testUpdateBestResultFileWithProgram() {
    val bestFile = getBestFile()
    // The result folder is populated with the original inputs before any reduction.
    assertThat(Files.exists(bestFile)).isTrue()

    ioManager.saveBestProgram(
      outputManagerFactory.createManagerFor(
        TestUtility.createTokenizedProgramFromString("int a;", LanguageC),
      ),
    )
    assertThat(bestFile.readText().trim()).isEqualTo("int a;")
    // Assert that the best result snapshot folder should be deleted.
    assertThat(
      tempDir.listDirectoryEntries().filter { it.isDirectory() },
    ).containsExactly(outputDir, workingDir)
  }

  @Test
  fun testRejectsInPlaceOutputDirectory() {
    // tempDir holds t.c, so using it as the output dir maps t.c's slot back onto the input itself.
    val e =
      assertThrows(IllegalStateException::class.java) {
        inputs.checkOutputDirectoryIsNotInPlace(tempDir)
      }
    assertThat(e).hasMessageThat().contains("in-place")
  }

  @Test
  fun testAllowsOutputDirectoryNotContainingInputs() {
    // outputDir is a distinct directory (tempDir/output_dir), so no slot coincides with an input.
    inputs.checkOutputDirectoryIsNotInPlace(outputDir)
  }

  private fun getBestFile() = outputDir.resolve(sourceFile.baseName)
}
