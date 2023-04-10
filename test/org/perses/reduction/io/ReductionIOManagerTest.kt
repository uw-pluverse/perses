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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.reduction.io.AbstractReductionIOManager.Companion.getTempRootFolderName
import java.nio.file.Files
import java.nio.file.Paths
import java.time.LocalDateTime
import kotlin.io.path.isDirectory
import kotlin.io.path.listDirectoryEntries
import kotlin.io.path.name
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class ReductionIOManagerTest : CommonReductionIOManagerData(ReductionIOManagerTest::class.java) {

  @After
  fun teardown() {
    close()
  }

  @Test
  fun testBackupBinaryFile() {
    Files.write(sourceFile.file, byteArrayOf(1))
    val getOrigFiles = { workingDir.listDirectoryEntries("*.orig") }
    assertThat(getOrigFiles()).isEmpty()
    ioManager.backupMainFile()
    val backupFile = getOrigFiles().single()
    assertThat(Files.readAllBytes(backupFile)).isEqualTo(Files.readAllBytes(sourceFile.file))
  }

  @Test
  fun testCreateCurrentBestResultFolder() {
    val folder = ioManager.createCurrentBestResultFolder()
    assertThat(folder.folder.name).contains("_best_result_snapshot_")
  }

  @Test
  fun testCreateReductionFolderManager() {
    assertThat(workingDir.listDirectoryEntries()).isEmpty()
    ioManager.lazilyInitializedReductionFolderManager
    assertThat(
      workingDir.listDirectoryEntries().single().name,
    ).startsWith("PersesTempRoot_t.c_r.sh_")
  }

  @Test
  fun testWriteProgramToReductionFolder() {
    val manager = ioManager.lazilyInitializedReductionFolderManager
    val listDirEntries = { manager.rootFolder.listDirectoryEntries() }
    assertThat(listDirEntries()).isEmpty()
    val folder = manager.createNextFolder()
    assertThat(listDirEntries()).hasSize(1)

    val realFolder = folder.folder
    val scriptFile = realFolder.listDirectoryEntries().single()
    assertThat(scriptFile.fileName.toString()).isEqualTo("r.sh")
    assertThat(Files.isExecutable(scriptFile))

    outputManagerFactory.createManagerFor(
      TestUtility.createTokenizedProgramFromString("int a;", LanguageC),
    ).write(folder)
    assertThat(realFolder.listDirectoryEntries()).hasSize(2)
    val sourceFile = realFolder.resolve("t.c")
    assertThat(sourceFile.fileName.toString()).isEqualTo("t.c")
    assertThat(sourceFile.readText()).contains("int")
    assertThat(sourceFile.readText()).contains("a")
  }

  @Test
  fun testWriteTestScriptTo() {
    val folder = root.resolve("tmp").apply {
      Files.createDirectory(this)
    }
    assertThat(folder.listDirectoryEntries()).isEmpty()
    ioManager.reductionInputs.writeTestScriptTo(folder)

    val firstFile = folder.listDirectoryEntries().single()
    assertThat(firstFile.endsWith("r.sh")).isTrue()
    assertThat(Files.isExecutable(firstFile)).isTrue()
  }

  @Test
  fun testBackupMainFile() {
    val file = ioManager.backupMainFile().single()
    assertThat(file.fileName.toString()).endsWith(".orig")
    assertThat(file.fileName.toString()).startsWith("t.c")
    assertThat(file.readText()).isEqualTo("int a;")
  }

  @Test
  fun testGetTempRootFolderName() {
    val time = LocalDateTime.of(2000, 1, 21, 1, 2, 3)
    assertThat(getTempRootFolderName(ImmutableList.of(Paths.get("t.c")), "r.sh", time))
      .isEqualTo("PersesTempRoot_t.c_r.sh_20000121_010203")
  }

  @Test
  fun testGetSingleSourceFileBaseName() {
    val manager = ioManager.lazilyInitializedReductionFolderManager
    val folder = manager.createNextFolder()
    val program = TestUtility.createTokenizedProgramFromString("int a;", LanguageC)
    outputManagerFactory.createManagerFor(program).write(folder)
    val name = ioManager.getSingleSourceFileBaseName(folder)
    assertThat(name).isEqualTo("t.c")
  }

  @Test
  fun testGetScriptFileBaseNameIn() {
    val manager = ioManager.lazilyInitializedReductionFolderManager
    val folder = manager.createNextFolder()
    assertThat(ioManager.getScriptFileBaseNameIn(folder)).isEqualTo("r.sh")
  }

  @Test
  fun testUpdateBestResultFileWithProgram() {
    val bestFile = getBestFile()
    assertThat(Files.exists(bestFile)).isFalse()

    ioManager.updateBestResult(
      TestUtility.createTokenizedProgramFromString("int a;", LanguageC),
    )
    assertThat(bestFile.readText().trim()).isEqualTo("int a;")
    // Assert that the best result snapshot folder should be deleted.
    assertThat(
      root.listDirectoryEntries().filter { it.isDirectory() },
    ).containsExactly(outputDir, workingDir)
  }

  private fun getBestFile() = outputDir.resolve(sourceFile.baseName)
}
