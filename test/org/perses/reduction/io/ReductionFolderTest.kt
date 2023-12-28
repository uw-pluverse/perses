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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.util.Util
import org.perses.util.toImmutableList
import java.lang.Exception
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ReductionFolderTest {

  val tempDir = Files.createTempDirectory(this::class.java.canonicalName)

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testMultilevelInputs() {
    val root = Files.createDirectories(tempDir.resolve("root"))

    val fileA = Files.createFile(root.resolve("a.txt"))

    val dir1 = Files.createDirectories(root.resolve("1"))
    val file1 = Files.createFile(dir1.resolve("z.txt"))

    val dir2 = Files.createDirectories(root.resolve("2"))
    val file2 = Files.createFile(dir2.resolve("b.txt"))

    val testScript = createTestScript(root.resolve("r.sh"))

    class ReductionInputs : AbstractReductionInputs<LanguageKind, ReductionInputs>(
      testScript,
      mainDataKind = LanguageC,
      rootDirectory = root,
      programFiles = sequenceOf(
        fileA,
        file1,
        file2,
      ).map { SourceFile(it, LanguageC) }.toImmutableList(),
    )

    val reductionInputs = ReductionInputs()

    val reductionFolder = ReductionFolder(
      reductionInputs = reductionInputs,
      folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
    )
    assertThat(reductionFolder.folder.toFile().listFiles()).hasLength(1)
    reductionInputs.computeAbsPathListWrt(reductionFolder.folder).forEach {
      Files.createDirectories(it.parent)
      Files.createFile(it)
    }
    Files.createFile(reductionFolder.folder.resolve("extra.txt"))
    assertThat(reductionFolder.folder.toFile().listFiles()).hasLength(5)
    reductionFolder.deleteAllOtherFiles()
    assertThat(reductionFolder.folder.toFile().listFiles()).hasLength(4)

    assertThat(Files.isRegularFile(reductionFolder.folder.resolve("a.txt"))).isTrue()
    assertThat(Files.isRegularFile(reductionFolder.folder.resolve("1/z.txt"))).isTrue()
    assertThat(Files.isRegularFile(reductionFolder.folder.resolve("2/b.txt"))).isTrue()
    assertThat(Files.isRegularFile(reductionFolder.folder.resolve(testScript.baseName))).isTrue()
  }

  @Test
  fun testDeleteThisDirectoryResurviely() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val file = Files.createFile(root.resolve("a.txt"))
    val scriptFile = createTestScript(root.resolve("r.sh"))

    class ReductionInputs : AbstractReductionInputs<LanguageKind, ReductionInputs> (
      testScript = scriptFile,
      mainDataKind = LanguageC,
      rootDirectory = root,
      programFiles = ImmutableList.of(SourceFile(file, LanguageC)),
    )

    val folderPath = Files.createDirectories(tempDir.resolve("reduction-folder"))
    val reductionFolder = ReductionFolder(
      ReductionInputs(),
      folder = folderPath,
    )

    assertThat(Files.exists(folderPath)).isTrue()
    reductionFolder.deleteThisDirectoryRecursively()
    assertThat(Files.exists(folderPath)).isFalse()
    assertThrows(Exception::class.java) { reductionFolder.deleteThisDirectoryRecursively() }
    assertThrows(Exception::class.java) { reductionFolder.deleteAllOtherFiles() }
    assertThrows(Exception::class.java) { reductionFolder.runTestScript() }
  }

  @Test
  fun testCopyTo() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val file = Files.createFile(root.resolve("a.txt"))
    val scriptFile = createTestScript(root.resolve("r.sh"))
    val dir1 = Files.createDirectories(root.resolve("1"))
    val dir2 = Files.createDirectories(root.resolve("2"))
    val file1 = Files.createFile(dir1.resolve("a.txt"))
    file1.writeText("file1")
    val file2 = Files.createFile(dir1.resolve("b.txt"))
    file2.writeText("file2")

    val subdir = Files.createDirectories(dir1.resolve("subdir"))
    val file3 = Files.createFile(subdir.resolve("c.txt"))
    file3.writeText("file3")

    class ReductionInputs : AbstractReductionInputs<LanguageKind, ReductionInputs> (
      testScript = scriptFile,
      mainDataKind = LanguageC,
      rootDirectory = root,
      programFiles = ImmutableList.of(SourceFile(file, LanguageC)),
    )

    val reductionFolder1 = ReductionFolder(
      ReductionInputs(),
      folder = dir1,
    )
    val reductionFolder2 = ReductionFolder(
      ReductionInputs(),
      folder = dir2,
    )

    reductionFolder1.copyTo(reductionFolder2)

    val copyedFile1 = dir2.resolve(file1.fileName)
    val copyedFile2 = dir2.resolve(file2.fileName)
    val copyedSubdir = dir2.resolve(subdir.fileName)
    val copyedFile3 = copyedSubdir.resolve(file3.fileName)
    assertThat(Files.exists(copyedFile1)).isTrue()
    assertThat(Files.exists(copyedFile2)).isTrue()
    assertThat(Files.exists(copyedSubdir)).isTrue()
    assertThat(copyedFile1.readText()).isEqualTo(file1.readText())
    assertThat(copyedFile2.readText()).isEqualTo(file2.readText())
    assertThat(copyedFile3.readText()).isEqualTo(file3.readText())
  }

  private fun createTestScript(path: Path): ScriptFile {
    return ScriptFile(
      Files.createFile(path).apply {
        this.writeText("#!/usr/bin/env bash")
        Util.setExecutable(this)
      },
    )
  }
}
