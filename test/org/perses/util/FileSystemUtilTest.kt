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
package org.perses.util

import com.google.common.collect.ImmutableSet
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.FileSystemUtil.ensureDirExists
import org.perses.util.FileSystemUtil.globWithFileNameExts
import org.perses.util.FileSystemUtil.isEmptyDirectory
import org.perses.util.FileSystemUtil.setExecutable
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.exists
import kotlin.io.path.name
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class FileSystemUtilTest {
  private var tempDir: Path = Files.createTempDirectory(this::class.qualifiedName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @OptIn(ExperimentalPathApi::class)
  @Test
  fun testCreateTempDir() {
    val dir = FileSystemUtil.createTempDirForObject(this)
    try {
      assertThat(dir.name).startsWith(this::class.java.canonicalName)
    } finally {
      dir.deleteRecursively()
    }
  }

  @Test
  fun testIsEmptyDirectory() {
    assertThat(isEmptyDirectory(tempDir)).isTrue()
    Files.createFile(tempDir.resolve("temp.txt"))
    assertThat(isEmptyDirectory(tempDir)).isFalse()
  }

  @Test
  fun testEnsureDirExistsForNewFile() {
    val folder = tempDir.resolve("temp")
    assertThat(Files.isDirectory(folder)).isFalse()
    assertThat(Files.isDirectory(ensureDirExists(folder))).isTrue()
    assertThat(Files.isDirectory(ensureDirExists(folder))).isTrue()
  }

  @Test
  fun testEnsureDirExistsExceptionCase() {
    Files.createFile(tempDir.resolve("a"))
    val folder = tempDir.resolve("a")
    val exception =
      assertThrows(Exception::class.java) {
        ensureDirExists(folder)
      }
    assertThat(exception.message).startsWith("Fail")
  }

  @Test
  fun testSetExecutable() {
    val tempFile = Files.createFile(tempDir.resolve("temp.sh"))
    assertThat(Files.isExecutable(tempFile)).isFalse()
    setExecutable(tempFile)
    assertThat(Files.isExecutable(tempFile)).isTrue()
  }

  @Test
  fun testGlobFiles() {
    Files.createFile(tempDir.resolve("a.c"))
    Files.createFile(tempDir.resolve("b.c"))
    Files.createFile(tempDir.resolve("a.java"))

    val dir1 = Files.createDirectories(tempDir.resolve("dir1"))
    Files.createFile(dir1.resolve("dir1.java"))
    Files.createFile(dir1.resolve("dir1.c"))

    val dir2 = Files.createDirectories(tempDir.resolve("dir2"))
    Files.createFile(dir2.resolve("dir2.java"))
    Files.createFile(dir2.resolve("dir2.c"))

    globWithFileNameExts(tempDir, ".c")
      .map { it.fileName.toString() }
      .let {
        assertThat(it).containsExactly("a.c", "b.c", "dir1.c", "dir2.c")
      }

    globWithFileNameExts(tempDir, ".java")
      .map { it.fileName.toString() }
      .toList()
      .let {
        assertThat(it).containsExactly("a.java", "dir1.java", "dir2.java")
      }

    globWithFileNameExts(tempDir, ".rs").let {
      assertThat(it).isEmpty()
    }

    FileSystemUtil.globWithRegex(tempDir, Regex("^.*\\.java${"$"}")).let {
      assertThat(it.map { it.fileName.toString() }).containsExactly(
        "a.java",
        "dir1.java",
        "dir2.java",
      )
    }
  }

  @Test
  fun testGlobWithFilterListsAllRegularFilesRecursively() {
    Files.createFile(tempDir.resolve("b.txt"))
    Files.createFile(tempDir.resolve("a.txt"))
    val sub = Files.createDirectories(tempDir.resolve("sub").resolve("nested"))
    Files.createFile(sub.resolve("c.txt"))

    val result = FileSystemUtil.globWithFilter(tempDir) { true }
    // Recursive: every regular file under the directory tree, no directories.
    assertThat(result.map { tempDir.relativize(it).toString() })
      .containsExactly("a.txt", "b.txt", "sub/nested/c.txt")
  }

  @Test
  fun testGlobWithFilterIsDeterministicallySorted() {
    // Create files in a non-sorted creation order; the result must be sorted by path.
    for (name in listOf("zeta.txt", "alpha.txt", "mid.txt", "beta.txt")) {
      Files.createFile(tempDir.resolve(name))
    }
    val result = FileSystemUtil.globWithFilter(tempDir) { true }
    assertThat(result).isEqualTo(result.sortedBy { it.toAbsolutePath().normalize().toString() })
    assertThat(result.map { it.fileName.toString() })
      .containsExactly("alpha.txt", "beta.txt", "mid.txt", "zeta.txt")
      .inOrder()
  }

  @Test
  fun testGlobWithFilterOnEmptyDirectory() {
    assertThat(FileSystemUtil.globWithFilter(tempDir) { true }).isEmpty()
  }

  @Test
  fun testReplaceFileExtSingleFileName() {
    val orig = "a.txt"
    val new = FileSystemUtil.replaceFileExtension(orig, "exe")
    assertThat(new).isEqualTo("a.exe")
  }

  @Test
  fun testReplaceFileExtLongFileName() {
    val orig = "a/b/c.txt"
    val new = FileSystemUtil.replaceFileExtension(orig, "exec")
    assertThat(new).isEqualTo("a/b/c.exec")
  }

  @Test
  fun testCreateDirsAndWriteText() {
    val file = tempDir.resolve("a/b/c/d/e.txt")
    FileSystemUtil.createDirsAndWriteText(file, "hello")
    assertThat(file.readText()).isEqualTo("hello")
  }

  @Test
  fun test_copyFileToDirectory() {
    val srcFilePath =
      Files.createTempFile(tempDir, "test_copy_file", ".txt").also {
        it.writeText("test content", StandardCharsets.UTF_8)
      }
    val destDir = Files.createTempDirectory(tempDir, "test_copy_file")
    val destFilePath = FileSystemUtil.copyFileToDirectory(srcFilePath, destDir)

    // Verify the new file exists in the working directory,
    // and its content is same as the original file
    assertThat(destFilePath.exists()).isTrue()
    assertThat(srcFilePath.readText(StandardCharsets.UTF_8)).isEqualTo(
      destFilePath.readText(StandardCharsets.UTF_8),
    )
  }

  @Test
  fun testCopyFileToDirectoryThrow() {
    val originalFile =
      Files.createTempFile(tempDir, "test_copy_file", ".txt").also {
        it.writeText("test content", StandardCharsets.UTF_8)
      }
    val exception =
      assertThrows(IllegalArgumentException::class.java) {
        FileSystemUtil.copyFileToDirectory(originalFile, tempDir)
      }
    assertThat(exception.message)
      .contains("Destination path cannot be the same as the original path.")
  }

  @Test
  fun testListFilesInFolder() {
    val folder = Files.createDirectories(tempDir.resolve("folderToTestListFilesInFolder"))
    Files.createDirectories(folder.resolve("a"))
    Files.createDirectories(folder.resolve("b"))
    Files.createFile(folder.resolve("c"))
    Files.createFile(folder.resolve("d"))
    val fileSet = FileSystemUtil.listFilesInFolder(folder)

    assertThat(fileSet.size).isEqualTo(4)
    assertThat(fileSet).contains(folder.resolve("a"))
    assertThat(fileSet).contains(folder.resolve("b"))
    assertThat(fileSet).contains(folder.resolve("c"))
    assertThat(fileSet).contains(folder.resolve("d"))
  }

  @Test
  fun testDeleteFilesConditionally1() {
    val folder = Files.createDirectories(tempDir.resolve("folderToTestDeleteFilesNotInList"))
    Files.createDirectories(folder.resolve("a"))
    Files.createDirectories(folder.resolve("b"))
    Files.createFile(folder.resolve("c"))
    Files.createFile(folder.resolve("d"))
    val fileSet = FileSystemUtil.listFilesInFolder(folder)
    FileSystemUtil.deleteFilesConditionally(folder) { path: Path ->
      !fileSet.contains(path)
    }

    assertThat(fileSet.size).isEqualTo(4)
    assertThat(fileSet).contains(folder.resolve("a"))
    assertThat(fileSet).contains(folder.resolve("b"))
    assertThat(fileSet).contains(folder.resolve("c"))
    assertThat(fileSet).contains(folder.resolve("d"))
  }

  @Test
  fun testDeleteFilesConditionally2() {
    val folder = Files.createDirectories(tempDir.resolve("folderToTestDeleteFilesNotInList"))
    Files.createDirectories(folder.resolve("a"))
    Files.createDirectories(folder.resolve("b"))
    Files.createFile(folder.resolve("c"))
    Files.createFile(folder.resolve("d"))

    // remove "b" and "d"
    val fileSetWithoutDBuilder = ImmutableSet.builder<Path>()
    fileSetWithoutDBuilder.add(folder.resolve("a"))
    fileSetWithoutDBuilder.add(folder.resolve("c"))
    val fileSetWithoutD = fileSetWithoutDBuilder.build()

    // delete files that are not in fileSetWithoutD, i.e., delete "b" and "d"
    FileSystemUtil.deleteFilesConditionally(folder) { path: Path ->
      !fileSetWithoutD.contains(path)
    }

    val updatedFileSet = FileSystemUtil.listFilesInFolder(folder)

    assertThat(updatedFileSet.size).isEqualTo(2)
    assertThat(updatedFileSet).contains(folder.resolve("a"))
    assertThat(updatedFileSet).contains(folder.resolve("c"))
  }
}
