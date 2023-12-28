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
package org.perses.grammar.rust

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import com.google.common.truth.Truth
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.program.LanguageKindTestUtil
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import kotlin.io.path.readLines
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class PnfRustParserFacadeTest {

  val facade = PnfRustParserFacade()
  val workingDir = Files.createTempDirectory("PnfRustParserFacadeTest_")

  @After
  fun teardown() {
    workingDir.toFile().deleteRecursively()
  }

  @Test
  fun testRustVersions() {
    assertThat(LanguageRust.stableVersionStrings).isNotEmpty()
    assertThat(LanguageRust.stableVersionStrings).contains("1.57.2")
  }

  @Test
  fun testDefaultFormatterCmd() {
    assertThat(facade.language.getDefaultWorkingFormatter()).isNotNull()
    val tempFile = workingDir.resolve("to-be-formatted.rs")
    val unformatted = """
      |fn main() {
      |println!("Hello World!");}
    """
    tempFile.writeText(unformatted.trimMargin())

    facade.language.getDefaultWorkingFormatter()!!.runWith(ImmutableList.of(tempFile.toString()))
    val formatted = tempFile.readText()
    assertThat(formatted).isNotEqualTo(unformatted)
    facade.language.getDefaultWorkingFormatter()!!.runWith(ImmutableList.of(tempFile.toString()))
    assertThat(formatted).isEqualTo(tempFile.readText())
  }

  fun compareOrigAndPnfParsers(file: Path) {
    val parseTreeFromOrigParser = OrigRustParserFacade().parseFile(file)
    val tokensByOrigParser = TestUtility.extractTokenTexts(parseTreeFromOrigParser.tree)

    val parseTreeWithPnfParser = facade.parseFile(file)
    val tokensByPnfParser = TestUtility.extractTokenTexts(parseTreeWithPnfParser.tree)

    assertThat(tokensByPnfParser).containsExactlyElementsIn(tokensByOrigParser).inOrder()
  }

  fun testSingleFile(file: Path) {
    try {
      compareOrigAndPnfParsers(file)
      Truth.assertWithMessage("Remove $file")
        .that(failedTests)
        .containsNoneIn(arrayOf(file.toString()))
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

    val file = workingDir.resolve("test.rs")
    file.writeText(program)

    compareOrigAndPnfParsers(file)
  }

  @Test
  fun testLanguageRustCodeFormat() {
    LanguageKindTestUtil.assertCodeFormatsDoNotProduceSyntacticallyInvalidPrograms(
      facade,
      Paths.get("test_data/rust_programs/rust/compiler/rustc_ast/src/mut_visit.rs"),
    )
  }

  @Test
  fun test_compiler_rustc_ast_src_mut_visit() {
    val compilerFolder = "test_data/rust_programs/rust/compiler"
    val libraryFolder = "test_data/rust_programs/rust/library"
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_ast/src/mut_visit.rs"))
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_ast/src/token.rs"))
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_ast/src/tokenstream.rs"))
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_ast/src/attr/mod.rs"))
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_builtin_macros/src/deriving/mod.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_data_structures/src/sip128/tests.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_data_structures/src/tagged_ptr/copy.rs"),
    )
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_index/src/bit_set.rs"))
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_mir/src/borrow_check/diagnostics/conflict_errors.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_mir/src/borrow_check/diagnostics/region_errors.rs"),
    )
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_mir/src/borrow_check/nll.rs"))
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_mir/src/borrow_check/nll.rs"))
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_mir/src/borrow_check/region_infer/mod.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_mir/src/borrow_check/region_infer/opaque_types.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_mir/src/borrow_check/type_check/free_region_relations.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_mir/src/borrow_check/type_check/mod.rs"),
    )
    compareOrigAndPnfParsers(Paths.get("$compilerFolder/rustc_mir_build/src/build/into.rs"))
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_mir/src/borrow_check/diagnostics/explain_borrow.rs"),
    )
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/android/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/dragonfly/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/emscripten/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/freebsd/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/haiku/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/illumos/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/ios/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/linux/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/macos/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/netbsd/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/openbsd/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/redox/fs.rs"))
    compareOrigAndPnfParsers(Paths.get("$libraryFolder/std/src/os/solaris/fs.rs"))
    compareOrigAndPnfParsers(
      Paths.get("$libraryFolder/std/src/sys/sgx/abi/usercalls/alloc.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_data_structures/src/tagged_ptr.rs"),
    )
    compareOrigAndPnfParsers(
      Paths.get("$compilerFolder/rustc_middle/src/mir/interpret/pointer.rs"),
    )
  }

  // Collection for keeping track of the shards of tests we need to run
  private companion object {
    val shard1 = mutableListOf<Path>()
    val shard2 = mutableListOf<Path>()
    val shard3 = mutableListOf<Path>()
    val shard4 = mutableListOf<Path>()
    val shard5 = mutableListOf<Path>()
    val shard6 = mutableListOf<Path>()
    val failedTests = buildFailedTests()

    init {
      var counter = 0
      val shards = listOf(shard1, shard2, shard3, shard4, shard5, shard6)
      for (file in TestUtility.rustTestFiles) {
        val shard = shards.get(counter++ % shards.size)
        shard.add(file)
      }
    }

    private fun buildFailedTests() =
      Paths.get("test/org/perses/grammar/rust/golden_fail_list.txt")
        .readLines()
        .asSequence()
        .map { it.trim() }
        .filter { it.isNotBlank() }
        .fold(ImmutableSet.builder<String>(), { builder, f -> builder.add(f) })
        .build()
  }
}
