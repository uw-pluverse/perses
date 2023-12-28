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
package org.perses.antlr.reducer

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.AbstractAntlrrdcTest
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class E2ETest : AbstractAntlrrdcTest() {

  val outputDir = tempDir.resolve("perses_antlr_output")

  @After
  fun teardown() {
    close()
  }

  @Test
  fun test_action() {
    val content = process(parserWithActions)
    assertThat(content).doesNotContain("""{System.out.println("action");}""")
    assertThat(content).doesNotContain("""{System.out.println("");}""")
    assertThat(content).contains("ID ID+ EOF")
  }

  @Test
  fun test_locals() {
    val content = process(parserWithLocals)
    assertThat(content).doesNotContain("locals")
  }

  @Test
  fun test_semantic_predicate() {
    val content = process(parserWithSemanticPredicate)
    assertThat(content).doesNotContain("""{true}?""")
  }

  @Test
  fun test_returns() {
    val content = process(parserWithReturns)
    assertThat(content).doesNotContain("""returns""")
  }

  @Test
  fun test_arguments() {
    val content = process(parserWithArguments)
    assertThat(content).doesNotContain("""[int i]""")
    assertThat(content).doesNotContain("[1]")
  }

  @Test
  fun test_labels() {
    val content = process(parserWithLabels)
    assertThat(content).doesNotContain("arguments")
    assertThat(content).doesNotContain("second")
    assertThat(content).doesNotContain("name")
    assertThat(content).contains("ID ID+")
  }

  @Ignore
  @Test
  fun test_remove_labels_from_solidity_grammar() {
    val origParser = Paths.get("src/org/perses/grammar/solidity/preprocessed/Solidity.g4")
    val origLexer = Paths.get("src/org/perses/grammar/solidity/preprocessed/SolidityLexer.g4")

    val parser = tempDir.resolve(origParser.fileName)
    val lexer = tempDir.resolve(origLexer.fileName)
    val corpusPath = Paths.get("test_data/solidity_programs")
    Files.copy(origParser, parser)
    Files.copy(origLexer, lexer)
    val flags = listOf(
      "--parser",
      parser.toString(),
      "--lexer",
      lexer.toString(),
      "--start",
      "sourceUnit",
      "--corpus",
      corpusPath.toString(),
      "--file-ext",
      ".sol",
      "--enable-action-remover",
      "false",
      "--enable-argument-remover",
      "false",
      "--enable-local-remover",
      "false",
      "--enable-return-remover",
      "false",
      "--output-dir",
      outputDir.toString(),
    )
    Main.main(flags.toTypedArray())
    val content = outputDir.resolve(parser.fileName)
    assertThat(content).isEmpty()
  }

  fun process(parserFile: Path): String {
    Main.main(createFlags(parserFile).toTypedArray())

    val outputFile = outputDir.resolve(parserFile.fileName.toString())
    return outputFile.readText()
  }

  fun createFlags(parserFile: Path): List<String> {
    return listOf(
      "--parser",
      parserFile.toString(),
      "--lexer",
      lexerGrammarPath.toString(),
      "--start",
      "start",
      "--corpus",
      tempDir.toString(),
      "--file-ext",
      ".input",
      "--output-dir",
      outputDir.toString(),
    )
  }
}
