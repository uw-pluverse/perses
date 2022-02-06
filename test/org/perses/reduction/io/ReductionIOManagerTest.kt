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
    Files.list(workingDir).filter { t -> t.fileName.toString().endsWith(".orig") }.use {
      assertThat(it.findFirst().isPresent).isFalse()
    }
    ioManager.backupMainFile()
    Files.list(workingDir).filter { t -> t.fileName.toString().endsWith(".orig") }.use {
      val newBackup = it.findAny()
      assertThat(newBackup.isPresent).isTrue()
      assertThat(Files.readAllBytes(newBackup.get())).isEqualTo(Files.readAllBytes(sourceFile.file))
    }
  }

  @Test
  fun testCreateReductionFolderManager() {
    Files.list(workingDir).use {
      assertThat(it.findFirst().isPresent).isFalse()
    }
    ioManager.createReductionFolderManager()
    Files.list(workingDir).use {
      val firstFile = it.findFirst()
      assertThat(firstFile.isPresent).isTrue()
      assertThat(firstFile.get().fileName.toString()).startsWith("PersesTempRoot_t.c_r.sh_")
    }
  }

  @Test
  fun testWriteProgramToReductionFolder() {
    val manager = ioManager.createReductionFolderManager()
    Files.list(manager.rootFolder).use {
      assertThat(it.findFirst().isPresent).isFalse()
    }
    val folder = manager.createNextFolder()
    Files.list(manager.rootFolder).use {
      assertThat(it.findFirst().isPresent).isTrue()
    }
    val realFolder = folder.folder
    Files.list(realFolder).use {
      val scriptFile = it.findFirst()
      assertThat(scriptFile.isPresent).isTrue()
      assertThat(scriptFile.get().fileName.toString()).isEqualTo("r.sh")
      assertThat(Files.isExecutable(scriptFile.get()))
    }

    outputManagerFactory.createManagerFor(
      TestUtility.createTokenizedProgramFromString("int a;", LanguageC)
    ).write(folder)
    Files.list(realFolder).sorted().use {
      val sourceFile = it.skip(1).findFirst().get()
      assertThat(sourceFile.fileName.toString()).isEqualTo("t.c")
      assertThat(sourceFile.readText()).contains("int")
      assertThat(sourceFile.readText()).contains("a")
    }
  }

  @Test
  fun testWriteTestScriptTo() {
    val folder = root.resolve("tmp").apply {
      Files.createDirectory(this)
    }
    Files.list(folder).use {
      assertThat(it.findAny().isPresent).isFalse()
    }
    ioManager.reductionInputs.writeTestScriptTo(folder)
    Files.list(folder).use {
      val firstFile = it.findFirst()
      assertThat(firstFile.isPresent).isTrue()
      assertThat(firstFile.get().endsWith("r.sh")).isTrue()
      assertThat(Files.isExecutable(firstFile.get())).isTrue()
    }
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
    val manager = ioManager.createReductionFolderManager()
    val folder = manager.createNextFolder()
    val program = TestUtility.createTokenizedProgramFromString("int a;", LanguageC)
    outputManagerFactory.createManagerFor(program).write(folder)
    val name = ioManager.getSingleSourceFileBaseName(folder)
    assertThat(name).isEqualTo("t.c")
  }

  @Test
  fun testGetScriptFileBaseNameIn() {
    val manager = ioManager.createReductionFolderManager()
    val folder = manager.createNextFolder()
    assertThat(ioManager.getScriptFileBaseNameIn(folder)).isEqualTo("r.sh")
  }

  @Test
  fun testUpdateBestResultFileWithProgram() {
    val bestFile = getBestFile()
    assertThat(Files.exists(bestFile)).isFalse()

    ioManager.updateBestResult(
      TestUtility.createTokenizedProgramFromString("int a;", LanguageC)
    )
    assertThat(bestFile.readText().trim()).isEqualTo("int a;")
  }

  private fun getBestFile() = outputDir.resolve(sourceFile.baseName)
}
