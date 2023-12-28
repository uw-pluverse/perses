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
package org.perses.antlr.reducer.codegen

import com.google.common.collect.ImmutableList
import com.google.common.io.MoreFiles
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.AbstractAntlrrdcTest

@RunWith(JUnit4::class)
class ReductionScriptTemplateTest : AbstractAntlrrdcTest() {

  val testJarFile = tempDir.resolve("test.jar").apply {
    MoreFiles.touch(this)
  }

  val testProgram1 = tempDir.resolve("t1.c").apply {
    MoreFiles.touch(this)
  }
  val testProgram2 = tempDir.resolve("t2.c").apply {
    MoreFiles.touch(this)
  }

  val classpathJar = tempDir.resolve("extra-classpath.jar").apply {
    MoreFiles.touch(this)
  }

  @After
  fun teardown() {
    close()
  }

  @Test
  fun test() {
    val template = ReductionScriptTemplate(
      jarFileName = testJarFile.fileName.toString(),
      mainClassFullName = "org.perses.Main",
      extraClasspath = ImmutableList.of(classpathJar),
    )
    val scriptFile = template.writeTo(tempDir.resolve("r.sh"))
    val lines = scriptFile.fileContent.split("\n")

    assertThat(
      lines.filter {
        it.contains("EXTRA_CLASSPATH")
      },
    ).hasSize(2)

    assertThat(
      lines.filter {
        it.contains("""java -cp "${testJarFile.fileName}""")
      },
    ).hasSize(1)

    assertThat(lines.filter { it.contains(testProgram1.toString()) }).hasSize(0)
    assertThat(lines.filter { it.contains(testProgram2.toString()) }).hasSize(0)
    assertThat(lines.filter { it.contains(testJarFile.fileName.toString()) }).hasSize(1)
  }
}
