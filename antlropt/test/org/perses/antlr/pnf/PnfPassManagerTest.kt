/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.antlr.pnf

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility
import org.perses.antlr.GrammarTestingUtility.loadGrammarFromFile
import org.perses.antlr.ast.PersesGrammar
import org.perses.util.FileNameContentPair
import java.nio.file.Paths

@RunWith(JUnit4::class)
class PnfPassManagerTest : PnfLeftTestGrammar() {
  private val manager = PnfPassManager()

  private val nullLexer: FileNameContentPair? = null

  private val listener: PnfPassManager.Listener = object : PnfPassManager.Listener() {
    override fun start(grammar: PersesGrammar, startRuleName: String) {
      System.err.println("Starting...")
      System.err.println(grammar.sourceCode)
    }

    override fun afterPass(grammar: PersesGrammar, passClass: Class<*>, iteration: Int) {
      System.err.println("After pass $passClass")
      System.err.println(grammar.sourceCode)
    }
  }

  @Test
  fun test_assoc_right_recursive() {
    val grammar = loadGrammarFromFile("assoc_right_2.g4")
    val processed = manager.process(grammar, "start", nullLexer)
    println(processed.sourceCode)
  }

  @Test
  fun testConvertDuplicateAlternatives() {
    val grammar = GrammarTestingUtility.createPersesGrammarFromString(
      "start : A c | A d;",
      "c : B;",
      "d : B;"
    )
    val processed = manager.process(grammar, "start", nullLexer)
    println(processed.sourceCode)
  }

  @Test
  fun testRemoveAssociativity() {
    val grammar = GrammarTestingUtility.createPersesGrammarFromString(
      """
      start : <assoc=right> 'a';
      """.trimIndent()
    )
    val processed = manager.process(grammar, "start", nullLexer)
    assertThat(processed.flattenedAllRules).hasSize(1)
    assertThat(processed.flattenedAllRules.first().body.sourceCode).isEqualTo("'a'")
  }

  @Test
  fun testConvertC() {
    val grammar = loadGrammarFromFile("C.g4")
    val processed = manager.process(grammar, "compilationUnit", nullLexer)
    println(processed.sourceCode)
  }

  @Test
  fun testConvertPhp() {
    val lexer = FileNameContentPair.createFromFile(
      Paths.get("src/org/perses/grammar/php/PhpLexer.g4")
    )
    val grammar = GrammarTestingUtility.loadGrammarFromFile(
      Paths.get("src/org/perses/grammar/php/PhpParser.g4")
    )
    val processed = manager.process(grammar, "htmlDocument", lexer)
    println(processed.sourceCode)
  }

  @Test
  fun testConvertSystemVerilog() {
    val lexer = FileNameContentPair.createFromFile(
      Paths.get("antlropt/test/org/perses/antlr/pnf/grammars/SystemVerilogLexer.g4")
    )
    val grammar = GrammarTestingUtility.loadGrammarFromFile(
      Paths.get("antlropt/test/org/perses/antlr/pnf/grammars/SystemVerilogParser.g4")
    )
    val processed = manager.process(grammar, "source_text", lexer)
    println(processed.sourceCode)
  }

  @Test
  fun testConvertPrimaryExprOfGo_shouldNotCrash() {
    val grammar = loadGrammarFromFile("nested_alt_block_from_go.g4")
    val processed = manager.process(grammar, "primaryExpr", nullLexer, listener)
    val sourceCode = processed.sourceCode
    System.err.println(sourceCode)
  }
}
