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
package org.perses.grammar

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createSparTreeFromFile
import org.perses.TestUtility.createSparTreeFromString
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.program.LanguageKind
import org.perses.program.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.tree.spar.SparTreeBuilder
import java.io.File
import java.io.IOException

@RunWith(JUnit4::class)
class ParserFacadeTest {
  private val cFacade = CParserFacade()
  private val pnfcFacade = PnfCParserFacade()
  private val scalaFacade = PnfScalaParserFacade()

  private var scalaProgram: TokenizedProgram? = null

  @Before
  fun setup() {
    val scalaSourceCode =
      """
      |object Hello {
      |    def main(args: Array[String]) =
      |        println
      |        println("Hello world")
      |}
    """.trimMargin()
    scalaProgram = createSparTreeFromString(scalaSourceCode, LanguageKind.SCALA).programSnapshot
  }

  @Test
  @Throws(IOException::class)
  fun testTokenize() {
    val tokens = cFacade.parseIntoTokens(File("test_data/misc/t1.c"))
    val tokenTexts = tokens.stream().map { it.text }.collect(ImmutableList.toImmutableList())
    assertThat(tokenTexts)
      .containsExactly("int", "a", ";", "int", "b", ";", "int", "a", ",", "b", ";")
      .inOrder()
  }

  @Test
  fun testIsParsableForScala_true_case() {
    val program = scalaProgram!!
    assertThat(scalaFacade.isSourceCodeParsable(program.toSourceCodeInOrigFormatWithBlankLines()))
      .isTrue()
    assertThat(scalaFacade.isSourceCodeParsable(program.toCompactSourceCode())).isTrue()
    assertThat(scalaFacade.isSourceCodeParsable(program)).isTrue()
  }

  @Test
  fun testIsParsableForScala_false_case() {
    val program = scalaProgram!!
    run {
      val invalidProgram = projectProgram(program, "object", "Hello", "{")
      assertThat(invalidProgram.tokens).hasSize(3)
      assertThat(scalaFacade.isSourceCodeParsable(invalidProgram.toCompactSourceCode())).isFalse()
    }
  }

  @Test
  fun testIsParsable_true() {
    val program = createSparTreeFromFile("test_data/misc/t1.c").programSnapshot
    assertThat(cFacade.isSourceCodeParsable(program.toSourceCodeInOrigFormatWithBlankLines()))
      .isTrue()
//    assertThat(cFacade.isSourceCodeParsable(program)).isTrue()
    assertThat(pnfcFacade.isSourceCodeParsable(program.toSourceCodeInOrigFormatWithBlankLines()))
      .isTrue()
//    assertThat(pnfcFacade.isSourceCodeParsable(program)).isTrue()
    val invalidProgram = deriveInvalidProgram(program)
    assertThat(
      cFacade.isSourceCodeParsable(invalidProgram.toSourceCodeInOrigFormatWithBlankLines())
    )
      .isFalse()
//    assertThat(cFacade.isSourceCodeParsable(invalidProgram)).isFalse()
    assertThat(
      pnfcFacade.isSourceCodeParsable(
        invalidProgram.toSourceCodeInOrigFormatWithBlankLines()
      )
    )
      .isFalse()
//    assertThat(pnfcFacade.isSourceCodeParsable(invalidProgram)).isFalse()
  }

  @Test
  fun testParseTokenizedProgram_t1() {
    testParseTokenizedProgram("t1.c")
  }

  @Test
  fun testParseTokenizedProgram_t2() {
    testParseTokenizedProgram("t2.c")
  }

  @Test
  fun testParseTokenizedProgram_t3() {
    testParseTokenizedProgram("t3.c")
  }

  @Test
  fun testParseTokenizedProgram_t4() {
    testParseTokenizedProgram("t4.c")
  }

  @Test
  fun testParseTokenizedProgram_t5() {
    testParseTokenizedProgram("t5.c")
  }

  @Test
  fun testParseTokenizedProgram_t9() {
    testParseTokenizedProgram("t9.c")
  }

  private fun testParseTokenizedProgram(filename: String) {
    val sparTreeFromFile = createSparTreeFromFile("test_data/misc/$filename")
    val originalProgram = sparTreeFromFile.programSnapshot
    val originalTokens = toAntlrTokens(originalProgram.tokens)
    val factory = sparTreeFromFile.tokenizedProgramFactory
    run {
      val (tree1) = cFacade.parseTokenizedProgram(originalProgram)
      val tree = SparTreeBuilder(cFacade.ruleHierarchy, factory)
        .build(tree1)
      val tokens = toAntlrTokens(tree.programSnapshot.tokens)
      assertThat(tokens).containsExactlyElementsIn(originalTokens).inOrder()
    }
    run {
      val (tree) = pnfcFacade.parseTokenizedProgram(originalProgram)
      val treeFromPnfc = SparTreeBuilder(pnfcFacade.ruleHierarchy, factory)
        .build(tree)
      val tokens = toAntlrTokens(treeFromPnfc.programSnapshot.tokens)
      assertThat(tokens).containsExactlyElementsIn(originalTokens).inOrder()
    }
  }

  companion object {
    private fun toAntlrTokens(tokens: ImmutableList<PersesToken>): ImmutableList<String?> {
      return tokens.stream().map { it.text }.collect(ImmutableList.toImmutableList())
    }

    private fun projectProgram(
      program: TokenizedProgram,
      vararg lexemes: String
    ): TokenizedProgram {
      val builder = ImmutableList.builder<PersesToken>()
      var index = 0
      val tokens = program.tokens
      for (lexeme in lexemes) {
        while (index < tokens.size) {
          val persesToken = tokens[index]
          ++index
          if (persesToken.text == lexeme) {
            builder.add(persesToken)
            break
          }
        }
      }
      return TokenizedProgram(builder.build())
    }

    private fun deriveInvalidProgram(program: TokenizedProgram): TokenizedProgram {
      val builder = ImmutableList.builder<PersesToken>()
      for (t in program.tokens) {
        val lexeme = t.text
        if (lexeme == ";" || lexeme == "," || lexeme == ":") {
          continue
        }
        builder.add(t)
      }
      return TokenizedProgram(builder.build())
    }
  }
}
