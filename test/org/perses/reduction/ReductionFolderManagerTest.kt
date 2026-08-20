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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.io.AbstractReductionIOManager
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.ReductionFolderManager
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.AutoDeletableFolder
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Files
import java.nio.file.Paths

@RunWith(JUnit4::class)
class ReductionFolderManagerTest {
  private val tempDir =
    AutoDeletableFolder.createTempDirWithClassNameAsPrefix(this)

  private val testScript = ScriptFile(Paths.get("test_data/delta_1/r.sh"))
  private val sourceFile = SourceFile(Paths.get("test_data/delta_1/t.c"), LanguageC)
  val originalReductionInputs =
    DefaultLanguageOriginalReductionInputs(
      testScript,
      mutableFiles = ImmutableList.of(sourceFile),
      immutableDependencyFiles = ImmutableList.of(),
    )
  private val outputDir =
    tempDir.file.resolve("perses_output_dir").apply {
      Util.ensureDirExists(this)
    }
  val ioManager =
    TokenReductionIOManager(
      workingFolder = tempDir.file,
      originalReductionInputs = originalReductionInputs,
      resultFolder =
        AbstractReductionIOManager.createPopulatedResultFolder(
          originalReductionInputs,
          EnumShaAlgorithm.SHA512,
          outputDir,
        ),
    )
  private val manager =
    ReductionFolderManager(
      originalReductionInputs,
      Files.createTempDirectory(tempDir.file, "PersesTempRoot_"),
    )

  @After
  fun teardown() {
    tempDir.close()
  }

  @Test
  fun testCreateTempDirectory() {
    val prefix = "prefix"
    val postfix = "suffix"
    val result =
      (1..5)
        .map {
          manager.createTempDirectory(prefix, postfix)
        }.toList()
    result.forEach {
      assertThat(it.fileName.toString()).startsWith(prefix)
      assertThat(it.fileName.toString()).endsWith(postfix)
      assertThat(Util.isEmptyDirectory(it)).isTrue()
    }
  }

  @Test
  fun test() {
    val firstFolder = manager.createNextFolder()
    assertThat(firstFolder.path.fileName.toString()).isEqualTo("000000")
    testFolder(firstFolder)
    val secondFolder = manager.createNextFolder()
    testFolder(secondFolder)
    assertThat(secondFolder.path.fileName.toString()).isEqualTo("000001")
  }

  @Test
  fun testDeleteAllOtherFiles() {
    val folder = manager.createNextFolder()
    Files.createFile(folder.path.resolve(sourceFile.baseName))
    Files.createFile(folder.path.resolve("extra"))
    assertThat(folder.path.toFile().listFiles()!!).hasLength(3)
    folder.deleteAllOtherFiles()
    assertThat(
      folder.path
        .toFile()
        .listFiles()!!
        .map { it.name },
    ).containsExactly(
      sourceFile.baseName,
      testScript.baseName,
    )
  }

  @Test
  fun testComputeAbsPathForOrigFile() {
    val folder = manager.createNextFolder()
    val path = folder.computeAbsPathForOrigFile(sourceFile)
    assertThat(path).isEqualTo(folder.path.resolve("t.c"))

    Assert.assertThrows(Exception::class.java) {
      folder.computeAbsPathForOrigFile(SourceFile(Paths.get("t.c"), LanguageC))
    }
  }

  private fun testFolder(folder: ReductionFolder) {
    assertThat(folder.path.parent.toAbsolutePath())
      .isEqualTo(manager.rootFolder)

    assertThat(
      folder.testScript.scriptFile.parent
        .toAbsolutePath(),
    ).isEqualTo(folder.path.toAbsolutePath())
    assertThat(
      folder.testScript.scriptFile.fileName
        .toString(),
    ).isEqualTo("r.sh")
  }
}
