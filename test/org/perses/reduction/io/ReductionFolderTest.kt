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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.AbstractDataKind
import org.perses.program.BinaryReductionFile
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.util.Util
import org.perses.util.shell.Shells
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList
import java.lang.Exception
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.name
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ReductionFolderTest {

  val tempDir = Files.createTempDirectory(this::class.java.canonicalName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testMultilevelInputs() {
    val root = Files.createDirectories(tempDir.resolve("root"))

    val fileA = Files.createFile(root.resolve("a.txt"))

    val dir1 = Files.createDirectories(root.resolve("dir-1"))
    val file1 = Files.createFile(dir1.resolve("z.txt"))

    val dir2 = Files.createDirectories(root.resolve("dir-2"))
    val file2 = Files.createFile(dir2.resolve("b.txt"))

    val depDir1 = Files.createDirectories(root.resolve("dep_dir_1"))
    val depFile1 = Files.createFile(depDir1.resolve("dep1.txt"))

    val depDir2 = Files.createDirectories(root.resolve("dep_dir_2"))
    val depFile2 = Files.createFile(depDir2.resolve("dep2.txt"))

    val testScript = createTestScript(root.resolve("r.sh"))

    class ReductionInputs : AbstractReductionInputs<LanguageKind, ReductionInputs>(
      testScript,
      initiallyDeterminedMainDataKind = LanguageC,
      rootDirectory = root,
      mutableFiles = sequenceOf(
        fileA,
        file1,
        file2,
      ).map { SourceFile(it, LanguageC) }.toImmutableList(),
      immutableDependencyFiles = ImmutableList.of(
        BinaryReductionFile(file = depFile1, dataKind = AbstractDataKind.UnknownDataKind),
        BinaryReductionFile(file = depFile2, dataKind = AbstractDataKind.UnknownDataKind),
      ),
    )

    val reductionInputs = ReductionInputs()

    val reductionFolder = ReductionFolder(
      reductionInputs = reductionInputs,
      folder = Files.createDirectories(tempDir.resolve("reduction-folder")),
    )
    assertThat(
      reductionFolder.folder.toFile().listFiles()?.map { it.name },
    ).containsExactly(
      testScript.baseName,
      depDir1.name,
      depDir2.name,
    )
    reductionInputs.computeAbsPathListWrt(
      reductionFolder.folder,
      reductionFileSelectionPredicate = {
        reductionInputs.mutableFiles.contains(it.origFile)
      },
    ).forEach {
      Files.createDirectories(it.parent)
      Files.createFile(it)
    }
    assertThat(
      reductionInputs.sequenceOfMutableFiles().transformToImmutableList {
        it.origFile.file.name
      },
    ).containsExactly(
      fileA.name,
      file1.name,
      file2.name,
    )
    val extraFileName = "extra.txt"
    Files.createFile(reductionFolder.folder.resolve(extraFileName))
    assertThat(reductionFolder.folder.toFile().listFiles()?.map { it.name })
      .containsExactly(
        testScript.baseName,
        dir1.name,
        dir2.name,
        depDir1.name,
        depDir2.name,
        fileA.name,
        extraFileName,
      )
    reductionFolder.deleteAllOtherFiles()
    assertThat(reductionFolder.folder.toFile().listFiles()?.map { it.name })
      .containsExactly(
        dir1.name,
        dir2.name,
        testScript.baseName,
        depDir1.name,
        depDir2.name,
        fileA.name,
      )

    assertThat(Files.isRegularFile(reductionFolder.folder.resolve("a.txt"))).isTrue()
    assertThat(Files.isRegularFile(reductionFolder.folder.resolve("${dir1.name}/z.txt"))).isTrue()
    assertThat(Files.isRegularFile(reductionFolder.folder.resolve("${dir2.name}/b.txt"))).isTrue()

    assertThat(Files.isRegularFile(reductionFolder.folder.resolve(testScript.baseName))).isTrue()

    assertThat(
      Files.isRegularFile(reductionFolder.folder.resolve("dep_dir_1/dep1.txt")),
    ).isTrue()
    assertThat(
      Files.isRegularFile(reductionFolder.folder.resolve("dep_dir_2/dep2.txt")),
    ).isTrue()
  }

  @Test
  fun testDeleteThisDirectoryRecursively() {
    val root = Files.createDirectories(tempDir.resolve("root"))
    val file = Files.createFile(root.resolve("a.txt"))
    val scriptFile = createTestScript(root.resolve("r.sh"))

    class ReductionInputs : AbstractReductionInputs<LanguageKind, ReductionInputs> (
      testScript = scriptFile,
      initiallyDeterminedMainDataKind = LanguageC,
      rootDirectory = root,
      mutableFiles = ImmutableList.of(SourceFile(file, LanguageC)),
      immutableDependencyFiles = ImmutableList.of(),
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
      initiallyDeterminedMainDataKind = LanguageC,
      rootDirectory = root,
      mutableFiles = ImmutableList.of(SourceFile(file, LanguageC)),
      immutableDependencyFiles = ImmutableList.of(),
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
        this.writeText(Shells.SHEBANG_BASH)
        Util.setExecutable(this)
      },
    )
  }
}
