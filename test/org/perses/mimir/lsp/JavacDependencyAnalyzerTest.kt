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
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util
import org.perses.util.shell.ShellCommandOnPath
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class JavacDependencyAnalyzerTest {
  private val tempDir: Path = Util.createTempDirForObject(this)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testLocalVariablesAndParameters() {
    val sourceFile = tempDir.resolve("Test.java")
    sourceFile.writeText(
      """
      public class Test {
          public void foo(int p) {
              int x = p;
              int y = x + 1;
              System.out.println(y);
          }
      }
      """.trimIndent(),
    )

    val analyzer = JavacDependencyAnalyzer(sourceFile)
    val defUseMap = analyzer.defUseMap
    assertThat(defUseMap).isNotEmpty()

    val defs = defUseMap.keys.groupBy { it.lexeme }
    assertThat(defs).containsKey("p")
    assertThat(defs).containsKey("x")
    assertThat(defs).containsKey("y")

    // Check p usages
    val pDef = defs["p"]!!.first()
    val pUses = defUseMap[pDef]!!
    assertThat(pUses).hasSize(1)
    assertThat(pUses.first().lexeme).isEqualTo("p")

    // Check x usages
    val xDef = defs["x"]!!.first()
    val xUses = defUseMap[xDef]!!
    assertThat(xUses).hasSize(1)
    assertThat(xUses.first().lexeme).isEqualTo("x")

    // Check y usages
    val yDef = defs["y"]!!.first()
    val yUses = defUseMap[yDef]!!
    assertThat(yUses).hasSize(1)
    assertThat(yUses.first().lexeme).isEqualTo("y")
  }

  @Test
  fun testFieldsAndMethods() {
    val sourceFile = tempDir.resolve("Test.java")
    sourceFile.writeText(
      """
      public class Test {
          private int fieldBlock;
          public void setField(int val) {
              this.fieldBlock = val;
          }
          public int getField() {
              return fieldBlock;
          }
      }
      """.trimIndent(),
    )

    val analyzer = JavacDependencyAnalyzer(sourceFile)
    val defUseMap = analyzer.defUseMap
    assertThat(defUseMap).isNotEmpty()

    val defs = defUseMap.keys.groupBy { it.lexeme }
    assertThat(defs).containsKey("fieldBlock")
    assertThat(defs).containsKey("setField")
    assertThat(defs).containsKey("getField")

    val fieldDef = defs["fieldBlock"]!!.first()
    val fieldUses = defUseMap[fieldDef]!!
    assertThat(fieldUses).hasSize(2)
  }

  @Test
  fun testJavacAndJdtlsAnalyzersAreEqual() {
    val sourceFile = tempDir.resolve("ComparisonTest.java")
    sourceFile.writeText(
      """
      public class ComparisonTest {
          private int field1;
          private String field2;

          public void setFields(int p1, String p2) {
              int local1 = p1;
              String local2 = p2;
              this.field1 = local1;
              this.field2 = local2;
          }

          public int process(int input) {
              int factor = 10;
              int result = input * factor + field1;
              Helper h = new Helper();
              return h.compute(result);
          }
      }

      class Helper {
          public int compute(int x) {
              int base = 5;
              int offset = x + base;
              return offset * 2;
          }
      }
      """.trimIndent(),
    )

    val javacAnalyzer = JavacDependencyAnalyzer(sourceFile)
    val javacMap = normalizeMap(javacAnalyzer.defUseMap)

    val jdtlsCommand = ShellCommandOnPath("benchmark_v2/binaries/start_jdtls.sh")
    MimirDependencyAnalyzer(jdtlsCommand, sourceFile).use { jdtlsAnalyzer ->
      val jdtlsMap = normalizeMap(jdtlsAnalyzer.defUseMap)
      assertThat(javacMap).isEqualTo(jdtlsMap)
    }
  }

  private fun normalizeMap(
    map: Map<LspSemanticToken, List<LspSemanticToken>>,
  ): Map<String, List<String>> =
    map.entries
      .filter { it.key.lexeme != "<init>" }
      .associate { entry ->
        val def = entry.key
        val key = "${def.lexeme}@${def.position.line}:${def.position.character}"
        val values =
          entry.value
            .map { "${it.lexeme}@${it.position.line}:${it.position.character}" }
            .sorted()
        key to values
      }.filter { it.value.isNotEmpty() }
}
