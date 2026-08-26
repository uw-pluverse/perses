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
package org.perses.reduction.reducer.sfc

import org.junit.After
import org.junit.Before
import org.perses.grammar.AbstractParserFacade
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

/**
 * A test whose grammar is written inline and compiled into a parser facade, which needs a
 * directory to generate the facade into.
 */
abstract class AbstractSfcTestWithGeneratedFacade {
  // A subclass cannot declare a "setup" of its own: Kotlin rejects a method that hides a
  // supertype member. Since every @Before method is named "setup" by convention, a subclass
  // creates what it needs lazily instead, once this setup has run.
  protected lateinit var tempDir: Path
    private set

  @Before
  fun setup() {
    tempDir = Files.createTempDirectory(this::class.java.simpleName)
  }

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  /**
   * A facade for [parserRules], generated into this test's own directory. The lexer rules are
   * supplied by default, because what an SFC test varies is the shape of the parser rules: the
   * identifier token and the skipped whitespace are the same in every one of these grammars.
   */
  protected fun createFacade(
    grammarName: String,
    parserRules: String,
    enablePnfNormalization: Boolean = false,
    startRule: String = "start",
    lexerRules: String = DEFAULT_LEXER_RULES,
    tokenNamesOfIdentifiers: List<String> = listOf("ID"),
  ): AbstractParserFacade =
    SfcTestUtility.createFacadeForGrammar(
      grammarName = grammarName,
      grammarContent = parserRules.trimIndent() + "\n" + lexerRules.trimIndent(),
      workingDir = tempDir,
      enablePnfNormalization = enablePnfNormalization,
      startRule = startRule,
      tokenNamesOfIdentifiers = tokenNamesOfIdentifiers,
    )

  companion object {
    val DEFAULT_LEXER_RULES =
      """
      ID : [a-z]+ ;
      WS : [ \t\r\n]+ -> skip ;
      """.trimIndent()
  }
}
