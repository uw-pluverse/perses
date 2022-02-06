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

import com.google.common.io.MoreFiles
import com.google.common.io.RecursiveDeleteOption
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.util.Util
import org.perses.util.toImmutableList
import java.nio.file.Files
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class ReductionFolderTest {

  val tempDir = Files.createTempDirectory(this::class.java.canonicalName)

  @After
  fun teardown() {
    MoreFiles.deleteRecursively(tempDir, RecursiveDeleteOption.ALLOW_INSECURE)
  }

  @Test
  fun testMultilevelInputs() {
    val root = Files.createDirectories(tempDir.resolve("root"))

    val fileA = Files.createFile(root.resolve("a.txt"))

    val dir1 = Files.createDirectories(root.resolve("1"))
    val file1 = Files.createFile(dir1.resolve("z.txt"))

    val dir2 = Files.createDirectories(root.resolve("2"))
    val file2 = Files.createFile(dir2.resolve("b.txt"))

    val testScript = ScriptFile(
      Files.createFile(root.resolve("r.sh")).apply {
        this.writeText("#!/usr/bin/env bash")
        Util.setExecutable(this)
      }
    )

    val reductionInputs = object : AbstractReductionInputs(
      testScript,
      mainLanguage = LanguageC,
      rootDirectory = root,
      files = sequenceOf(fileA, file1, file2).map { SourceFile(it, LanguageC) }.toImmutableList()
    ) {}
    val reductionFolder = ReductionFolder(
      reductionInputs = reductionInputs,
      folder = Files.createDirectories(tempDir.resolve("reduction-folder"))
    )
    assertThat(reductionFolder.folder.toFile().listFiles()).hasLength(1)
    reductionInputs.computeAbsolutePathListWRT(reductionFolder.folder).forEach {
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
}
