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
package org.perses

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class ParseabilityMainTest {

  private val dir: Path = Files.createTempDirectory(this::class.java.simpleName)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    dir.deleteRecursively()
  }

  private fun write(name: String, content: String): String {
    Files.writeString(dir.resolve(name), content)
    return name
  }

  /** Runs the tool over [names] (resolved against the temp dir) and returns the parseable subset. */
  private fun run(vararg names: String, extraArgs: List<String> = emptyList()): List<String> {
    val list = dir.resolve("list.txt")
    Files.write(list, names.toList())
    val out = dir.resolve("out.txt")
    ParseabilityMain.main(
      arrayOf(
        "--file-list", list.toString(),
        "--base-dir", dir.toString(),
        "--output", out.toString(),
      ) + extraArgs,
    )
    return Files.readAllLines(out)
  }

  private val validC = "int main(void) { return 0; }\n"
  private val syntacticallyInvalidC = "int f(void) { return 1 }\n" // missing ';'

  @Test
  fun autoDetectsCFromExtensionAndParsesValidFile() {
    val ok = write("ok.c", validC)
    assertThat(run(ok)).containsExactly("ok.c")
  }

  @Test
  fun rejectsSyntacticallyInvalidFile() {
    val bad = write("bad.c", syntacticallyInvalidC)
    assertThat(run(bad)).isEmpty()
  }

  @Test
  fun keepsOnlyParseableFilesPreservingInputPaths() {
    write("a.c", validC)
    write("b.c", syntacticallyInvalidC)
    write("c.c", validC)
    // Output echoes the verbatim input lines for the subset that parses.
    assertThat(run("a.c", "b.c", "c.c")).containsExactly("a.c", "c.c").inOrder()
  }

  @Test
  fun resolvesPathsRelativeToBaseDir() {
    Files.createDirectory(dir.resolve("sub"))
    write("sub/nested.c", validC)
    assertThat(run("sub/nested.c")).containsExactly("sub/nested.c")
  }

  @Test
  fun honorsExplicitLangOverride() {
    val ok = write("ok.c", validC)
    assertThat(run(ok, extraArgs = listOf("--lang", "c"))).containsExactly("ok.c")
  }

  @Test
  fun unknownExtensionIsUnparseableWithoutCrashing() {
    // No language matches the extension, so detection fails; the file is simply not parseable.
    val unknown = write("mystery.zzz", validC)
    assertThat(run(unknown)).isEmpty()
  }

  @Test
  fun emptyListYieldsEmptyOutput() {
    assertThat(run()).isEmpty()
  }
}
