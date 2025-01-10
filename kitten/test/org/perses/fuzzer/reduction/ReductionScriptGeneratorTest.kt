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
package org.perses.fuzzer.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compilers.ICompilerCrashDetector.AbstractResult
import org.perses.fuzzer.compilers.c.GccCrashDetector
import org.perses.util.shell.Shells
import java.io.File

@RunWith(JUnit4::class)
class ReductionScriptGeneratorTest {

  private val workingDirectory = java.nio.file.Files
    .createTempDirectory(javaClass.simpleName).toFile()
  private val crashDetector = GccCrashDetector()

  @After
  fun teardown() {
    workingDirectory.deleteRecursively()
  }

  @Test
  fun testEscapeString() {
    ReductionScriptGenerator.escapeString("\"").let {
      assertThat(it).isEqualTo("\\\"")
    }
  }

  @Test
  fun testCreateReductionScriptForSingleLineSignature() {
    testReductionScript("echo hello", listOf("hello"), 1)
    testReductionScript("(echo hello ; false)", listOf("hello"), 0)
    testReductionScript("echo a | false", listOf("hello"), 1)
  }

  @Test
  fun testCreateReductionScriptForMultiLineSignature() {
    testReductionScript(
      cmd = "(echo -e 'hello\\nworld' ; false)", // exit code is 1
      crashSignature = listOf("hello", "world"),
      expectedExitCode = 0,
    )
    testReductionScript(
      cmd = "(echo -e '\\${'$'}' ; false)", // exit code is 1
      crashSignature = listOf("${'$'}"),
      expectedExitCode = 0,
    )
    testReductionScript(
      cmd = "echo -e 'hello\\nworld'", // exit code is 0
      crashSignature = listOf("hello", "world"),
      expectedExitCode = 1,
    )
    testReductionScript(
      cmd = "echo -e 'hello'",
      crashSignature = listOf("hello", "world"),
      expectedExitCode = 1,
    )
  }

  private fun testReductionScript(
    cmd: String,
    crashSignature: List<String>,
    expectedExitCode: Int,
  ) {
    val generator = ReductionScriptGenerator(
      cmd,
      AbstractResult.CrashResult.create(
        crashDetector.javaClass,
        exitCode = 1,
        rawSignature = crashSignature,
      ),
    )
    val script = generator.generate()
    println(script)
    val file = File(workingDirectory, "t.sh")
    file.writeText(script, Charsets.UTF_8)
    check(file.setExecutable(true))

    val cmdOutput = Shells.singleton.run(
      file.absolutePath,
      captureOutput = true,
      environment = Shells.CURRENT_ENV,
    )
    assertThat(cmdOutput.exitCode.intValue).isEqualTo(expectedExitCode)
  }
}
