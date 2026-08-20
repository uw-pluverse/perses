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
package org.perses.mimir.lsp

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util
import org.perses.util.shell.ShellCommandOnPath
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class JavaLanguageServerTest {
  private val tempDir: Path = Util.createTempDirForObject(this)

  // Use the startup script from the runfiles
  private val jdtlsCommand =
    ShellCommandOnPath(
      "benchmark_v2/binaries/start_jdtls.sh",
    )

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testIncrementalAnalysis() {
    val sourceFile = tempDir.resolve("Test.java")
    sourceFile.writeText(
      """
      public class Test {
          public void foo() {
              int x = 1;
              int y = x + 1;
          }
      }
      """.trimIndent(),
    )

    MimirDependencyAnalyzer(
      languageServer = jdtlsCommand,
      sourceFile = sourceFile,
    ).use { analyzer ->
      val defUseMap = analyzer.defUseMap
      assertThat(defUseMap).isNotEmpty()

      val defs = defUseMap.keys.groupBy { it.lexeme }
      assertThat(defs).containsKey("x")
      assertThat(defs).containsKey("y")

      val xDef = defs["x"]!!.first()
      val xUses = defUseMap[xDef]!!
      assertThat(xUses).hasSize(1)
      assertThat(xUses.first().lexeme).isEqualTo("x")
    }
  }

  @Ignore("The Java file is too large to process.")
  @Test
  fun testAnalyzingCollectionsJavaSmall() {
    val collectionsJavaPath =
      Paths.get(
        "benchmark_v2/benchmark_java/checkerframework-691/CollectionsSmall.java",
      )
    assertThat(Files.exists(collectionsJavaPath)).isTrue()

    // Copy CollectionsSmall.java to the temp directory
    val packagePath = tempDir.resolve("com/example")
    Files.createDirectories(packagePath)
    val targetPath = packagePath.resolve("CollectionsSmall.java")
    Files.copy(collectionsJavaPath, targetPath)

    MimirDependencyAnalyzer(
      languageServer = jdtlsCommand,
      sourceFile = targetPath,
    ).use { analyzer ->
      val defUseMap = analyzer.defUseMap
      assertThat(defUseMap).isNotEmpty()

      val defs = defUseMap.keys.groupBy { it.lexeme }
      // Check for a few more known identifiers in a typical Collections.java
      assertThat(defs as Map<*, *>).containsKey("reverse")
      assertThat(defs as Map<*, *>).containsKey("sort")
    }
  }

  @Test
  fun testAnalyzingCollectionsJavaWithJLS() {
    val collectionsJavaPath =
      Paths.get(
        "benchmark_v2/benchmark_java/checkerframework-691/Collections.java",
      )
    assertThat(Files.exists(collectionsJavaPath)).isTrue()

    // Copy CollectionsSmall.java to the temp directory
    val packagePath = tempDir.resolve("com/example")
    Files.createDirectories(packagePath)
    val targetPath = packagePath.resolve("Collections.java")
    Files.copy(collectionsJavaPath, targetPath)

    val jlsCommand =
      ShellCommandOnPath(
        "benchmark_v2/binaries/start_jls.sh",
      )

    MimirDependencyAnalyzer(
      languageServer = jlsCommand,
      sourceFile = targetPath,
    ).use { analyzer ->
      val defUseMap = analyzer.defUseMap
      assertThat(defUseMap).isNotEmpty()
    }
  }
}
