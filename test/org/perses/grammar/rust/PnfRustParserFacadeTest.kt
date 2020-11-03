/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.grammar.rust

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import com.google.common.io.Files
import com.google.common.truth.Truth
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import java.io.File

@RunWith(JUnit4::class)
class PnfRustParserFacadeTest {

  val facade = PnfRustParserFacade()
  val workingDir = Files.createTempDir()

  @After
  fun teardown() {
    workingDir.deleteRecursively()
  }

  @Test
  fun testDefaultFormatterCmd() {
    assertThat(facade.language.defaultFormmaterCommand).isNotNull()
    val tempFile = File(workingDir, "to-be-formatted.rs")
    val unformatted = """
      |fn main() {
      |println!("Hello World!");}
    """
    tempFile.writeText(unformatted.trimMargin())

    facade.language.defaultFormmaterCommand!!.runWith(ImmutableList.of(tempFile.toString()))
    val formatted = tempFile.readText()
    assertThat(formatted).isNotEqualTo(unformatted)
    facade.language.defaultFormmaterCommand!!.runWith(ImmutableList.of(tempFile.toString()))
    assertThat(formatted).isEqualTo(tempFile.readText())
  }

  fun compareOrigAndPnfParsers(file: File) {
    val parseTreeFromOrigParser = facade.parseWithOrigRustParser(file)
    val tokensByOrigParser = TestUtility.extractTokens(parseTreeFromOrigParser.tree)

    val parseTreeWithPnfParser = facade.parseFile(file)
    val tokensByPnfParser = TestUtility.extractTokens(parseTreeWithPnfParser.tree)

    assertThat(tokensByPnfParser).containsExactlyElementsIn(tokensByOrigParser).inOrder()
  }

  fun testSingleFile(file: File) {
    try {
      compareOrigAndPnfParsers(file)
      Truth.assertWithMessage("Remove $file").that(failedTests).containsNoneIn(arrayOf(file.toString()))
    } catch (e: Throwable) {
      e.printStackTrace()
      assertThat(failedTests).contains(file.toString())
    }
  }

  @Test
  fun testShard1() {
    for (file in shard1) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard2() {
    for (file in shard2) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard3() {
    for (file in shard3) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard4() {
    for (file in shard4) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard5() {
    for (file in shard5) {
      testSingleFile(file)
    }
  }

  @Test
  fun testShard6() {
    for (file in shard6) {
      testSingleFile(file)
    }
  }

  @Test
  fun basicTest() {

    val program =
      """
    |fn main() {
    |  // Statements here are executed when the compiled binary is called
    |
    |  // Print text to the console
    |  println!("Hello World!");
    |}
    """.trimMargin()

    val file = File(workingDir, "test.rs")
    file.writeText(program)

    compareOrigAndPnfParsers(file)
  }

  @Test
  fun test_compiler_rustc_ast_src_mut_visit() {
    compareOrigAndPnfParsers(File("test_data/rust_programs/rust/compiler/rustc_ast/src/mut_visit.rs"))
    compareOrigAndPnfParsers(File("test_data/rust_programs/rust/compiler/rustc_ast/src/token.rs"))
    compareOrigAndPnfParsers(File("test_data/rust_programs/rust/compiler/rustc_ast/src/tokenstream.rs"))
  }

  // Collection for keeping track of the shards of tests we need to run
  private companion object {
    val shard1 = mutableListOf<File>()
    val shard2 = mutableListOf<File>()
    val shard3 = mutableListOf<File>()
    val shard4 = mutableListOf<File>()
    val shard5 = mutableListOf<File>()
    val shard6 = mutableListOf<File>()
    val failedTests = buildFailedTests()

    init {
      var counter = 0
      val shards = listOf(shard1, shard2, shard3, shard4, shard5, shard6)
      for (file in TestUtility.getRustTestFiles()) {
        val shard = shards.get(counter++ % shards.size)
        shard.add(file)
      }
    }

    private fun buildFailedTests() =
      File("test/org/perses/grammar/rust/golden_fail_list.txt")
        .readLines()
        .asSequence()
        .map { it.trim() }
        .filter { it.isNotBlank() }
        .fold(ImmutableSet.builder<String>(), { builder, f -> builder.add(f) })
        .build()

  }

}
