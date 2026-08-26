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
package org.perses.cmd

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.FileSystemUtil
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class InputFlagGroupTest {
  private val tempDir: Path = FileSystemUtil.createTempDirForObject(this)

  private val testScript: Path =
    tempDir.resolve("r.sh").also {
      Files.createFile(it)
      it.toFile().setExecutable(true)
    }

  @After
  fun teardown() {
    @OptIn(kotlin.io.path.ExperimentalPathApi::class)
    tempDir.deleteRecursively()
  }

  private fun touch(relative: String): Path {
    val path = tempDir.resolve(relative)
    Files.createDirectories(path.parent)
    Files.createFile(path)
    return path
  }

  private fun newGroup(): InputFlagGroup = InputFlagGroup().also { it.testScript = testScript }

  private fun relNames(paths: List<Path>): List<String> =
    paths.map { tempDir.relativize(it).toString() }

  @Test
  fun plainFilesKeepCommandLineOrder() {
    val a = touch("a.c")
    val b = touch("b.c")
    // Explicit file arguments are not reordered: the user's command-line order is preserved.
    val group = newGroup().apply { setInputFiles(listOf(b, a)) }
    assertThat(relNames(group.computeInputFiles())).containsExactly("b.c", "a.c").inOrder()
  }

  @Test
  fun directoryIsExpandedRecursivelyAndSorted() {
    touch("dir/z.c")
    touch("dir/a.c")
    touch("dir/nested/m.c")
    val group = newGroup().apply { setInputFiles(listOf(tempDir.resolve("dir"))) }
    assertThat(relNames(group.computeInputFiles()))
      .containsExactly("dir/a.c", "dir/nested/m.c", "dir/z.c")
      .inOrder()
  }

  @Test
  fun testScriptUnderInputDirectoryIsExcluded() {
    // The test script lives inside the input directory (tempDir).
    val a = touch("a.c")
    val group = newGroup().apply { setInputFiles(listOf(tempDir)) }
    val inputs = group.computeInputFiles()
    assertThat(inputs).contains(a)
    assertThat(inputs).doesNotContain(testScript)
  }

  @Test
  fun dependencyFilesUnderInputDirectoryAreExcludedFromInputs() {
    val a = touch("a.c")
    val b = touch("b.c")
    val dep = touch("lib/dep.txt")
    val group =
      newGroup().apply {
        setInputFiles(listOf(tempDir))
        // Deps given as a directory.
        deps = listOf(tempDir.resolve("lib"))
      }
    val inputs = group.computeInputFiles()
    assertThat(inputs).containsExactly(a, b)
    assertThat(inputs).doesNotContain(dep)
    assertThat(group.computeDeps()).containsExactly(dep)
  }

  @Test
  fun dependencyGivenAsFileIsAlsoExcludedFromInputs() {
    val a = touch("a.c")
    val dep = touch("lib/dep.txt")
    val group =
      newGroup().apply {
        setInputFiles(listOf(tempDir))
        deps = listOf(dep)
      }
    assertThat(group.computeInputFiles()).containsExactly(a)
    assertThat(group.computeDeps()).containsExactly(dep)
  }

  @Test
  fun mixOfFileAndDirectoryIsDeduplicated() {
    val a = touch("dir/a.c")
    touch("dir/b.c")
    val group =
      newGroup().apply {
        // The same file reached both via the directory and explicitly.
        setInputFiles(listOf(tempDir.resolve("dir"), a))
      }
    assertThat(relNames(group.computeInputFiles())).containsExactly("dir/a.c", "dir/b.c").inOrder()
  }

  @Test
  fun computeDepsExpandsDirectoriesAndKeepsFiles() {
    touch("deps/d2.txt")
    touch("deps/d1.txt")
    val standalone = touch("standalone.txt")
    val group =
      newGroup().apply {
        setInputFiles(listOf(touch("a.c")))
        deps = listOf(tempDir.resolve("deps"), standalone)
      }
    assertThat(relNames(group.computeDeps()))
      .containsExactly("deps/d1.txt", "deps/d2.txt", "standalone.txt")
      .inOrder()
  }

  @Test
  fun validateAcceptsDirectoryInputsAndDeps() {
    touch("dir/a.c")
    touch("deps/dep.txt")
    val group =
      newGroup().apply {
        setInputFiles(listOf(tempDir.resolve("dir")))
        deps = listOf(tempDir.resolve("deps"))
      }
    // Should not throw.
    group.validate()
  }

  @Test
  fun validateRejectsNonExistentInput() {
    val group = newGroup().apply { setInputFiles(listOf(tempDir.resolve("does_not_exist"))) }
    val exception = assertThrows(IllegalStateException::class.java) { group.validate() }
    assertThat(exception.message).contains("neither a file nor a directory")
  }

  @Test
  fun validateRejectsInputDirectoryThatExpandsToZeroFiles() {
    val emptyDir = Files.createDirectories(tempDir.resolve("empty"))
    val group = newGroup().apply { setInputFiles(listOf(emptyDir)) }
    val exception = assertThrows(IllegalStateException::class.java) { group.validate() }
    assertThat(exception.message).contains("No input files were found")
  }

  @Test
  fun validateRejectsInputDirectoryContainingOnlyTheTestScript() {
    // tempDir contains only the test script; expansion excludes it, leaving nothing to reduce.
    val group = newGroup().apply { setInputFiles(listOf(tempDir)) }
    val exception = assertThrows(IllegalStateException::class.java) { group.validate() }
    assertThat(exception.message).contains("No input files were found")
  }
}
