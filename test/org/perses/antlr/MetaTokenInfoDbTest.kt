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
package org.perses.antlr

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.PnfCLexer
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class MetaTokenInfoDbTest {

  private lateinit var tempDir: Path

  @Before
  fun setup() {
    tempDir = Files.createTempDirectory(this::class.java.name)
  }

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  val lexerClass = PnfCLexer::class.java
  val mapping = LexerRuleNameAndTypeMapping(lexerClass)

  @Test
  fun testCGrammar() {
    assertThat(mapping.bimap.size).isEqualTo(123)

    val inputs = listOf(
      "And" to PnfCLexer.And,
      "AndAnd" to PnfCLexer.AndAnd,
      "For" to PnfCLexer.For,
      "Int" to PnfCLexer.Int,
      "Restrict" to PnfCLexer.Restrict,
      "Sizeof" to PnfCLexer.Sizeof,
    )

    for (token in inputs) {
      val type = mapping.getTokenType(token.first)
      assertThat(type).isEqualTo(token.second)
      val symbolicName = mapping.getSymbolicTokenName(token.second)
      assertThat(symbolicName).isEqualTo(token.first)
    }
  }

  @Test
  fun testAdhocGrammar() {
    val tokenNum = "Num"
    val tokenLetter = "Letter"
    val facade = TestUtility.generateAdhocFacade(
      combinedGrammarName = "Test",
      combinedGrammarContent = """
        $tokenLetter : 'a';
        $tokenNum : '9';
        start : $tokenLetter $tokenNum ;
      """.trimIndent(),
      startRule = "start",
      tokenNamesOfIdentifiers = listOf(),
      workingDir = tempDir,
      enablePnfNormalization = false,
    )
    val db = MetaTokenInfoDB.createFor(facade.lexerClass)
    assertThat(db.asSequence().count()).isEqualTo(2)
    db.getTokenInfoWithName(tokenLetter)!!.let {
      assertThat(it.ruleIndex.antlrRuleIndex).isEqualTo(0)
      assertThat(it.symbolicName).isEqualTo(tokenLetter)
      assertThat(it.literalLexeme).isEqualTo("a")
    }
    db.getTokenInfoWithName(tokenNum)!!.let {
      assertThat(it.ruleIndex.antlrRuleIndex).isEqualTo(1)
      assertThat(it.symbolicName).isEqualTo(tokenNum)
      assertThat(it.literalLexeme).isEqualTo("9")
    }
    assertThat(db.allLiteralLexemes).containsExactly("a", "9")
  }
}
