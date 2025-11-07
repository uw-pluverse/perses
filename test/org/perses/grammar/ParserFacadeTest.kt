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
package org.perses.grammar

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createSparTreeFromFile
import org.perses.TestUtility.createSparTreeFromString
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.scala.LanguageScala
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.program.EnumFormatControl
import org.perses.program.PersesTokenFactory
import org.perses.program.PersesTokenFactory.PersesAntlrToken
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.util.transformToImmutableList
import java.nio.file.Paths

@RunWith(JUnit4::class)
class ParserFacadeTest {
  private val cFacade = CParserFacade()
  private val pnfcFacade = PnfCParserFacade()
  private val scalaFacade = PnfScalaParserFacade()

  private var scalaProgram: TokenizedProgram? = null

  private val printerSingleLine =
    PrinterRegistry.getPrinter(EnumFormatControl.SINGLE_TOKEN_PER_LINE)
  private val printerCompact =
    PrinterRegistry.getPrinter(EnumFormatControl.COMPACT_ORIG_FORMAT)
  private val printerOrig =
    PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT)

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
    scalaProgram = createSparTreeFromString(scalaSourceCode, LanguageScala).programSnapshot
  }

  @Test
  fun testTokenizedCCode() {
    val tokens = pnfcFacade.tokenizeString("(0, 0, 0);", fileName = "empty")
    assertThat(tokens.map { it.text }).containsExactly("(", "0", ",", "0", ",", "0", ")", ";")
  }

  @Test
  fun testParserFacadeTag() {
    assertThrows(Exception::class.java) { ParserFacadeTag.create("pnf") }
    assertThrows(Exception::class.java) { ParserFacadeTag.create("original") }
    assertThrows(Exception::class.java) { ParserFacadeTag.create("PNF") }

    ParserFacadeTag.create("test").let {
      assertThat(it).isEqualTo(ParserFacadeTag.create("test"))
      assertThat(it).isNotEqualTo(ParserFacadeTag.create("t"))
    }
  }

  @Test
  fun testTokenizeFile() {
    val tokens = cFacade.tokenizeFile(Paths.get("test_data/misc/t1.c"))
    val tokenTexts = tokens.transformToImmutableList { it.text }
    assertThat(tokenTexts)
      .containsExactly("int", "a", ";", "int", "b", ";", "int", "a", ",", "b", ";")
      .inOrder()
  }

  @Test
  fun testTokenizeString() {
    val tokens =
      cFacade.tokenizeString(
        content = "a b c",
        fileName = "<in-memory>",
      )
    assertThat(tokens.map { it.text }).containsExactly("a", "b", "c").inOrder()
  }

  @Test
  fun testTokenizeEmptyString() {
    val tokens =
      cFacade.tokenizeString(
        content = "",
        fileName = "<in-memory>",
      )
    assertThat(tokens).isEmpty()
  }

  @Test
  fun testTransformLiteralIntoSingleToken() {
    val token = cFacade.transformLiteralIntoSingleToken(";")
    assertThat(token.text).isEqualTo(";")
  }

  @Test
  fun testIsParsableForScalaTrueCase() {
    val program = scalaProgram!!
    assertThat(
      scalaFacade.isSourceCodeParsable(
        printerOrig.print(program).sourceCode,
      ),
    ).isTrue()
    assertThat(
      scalaFacade.isSourceCodeParsable(
        printerCompact.print(program).sourceCode,
      ),
    ).isTrue()
  }

  @Test
  fun testIsParsableForScalaFalseCase() {
    val program = scalaProgram!!
    run {
      val invalidProgram = projectProgram(program, "object", "Hello", "{")
      assertThat(invalidProgram.tokens).hasSize(3)
      assertThat(
        scalaFacade.isSourceCodeParsable(
          printerCompact.print(invalidProgram).sourceCode,
        ),
      ).isFalse()
    }
  }

  @Test
  fun testIsParsableTrue() {
    val program = createSparTreeFromFile("test_data/misc/t1.c").programSnapshot
    assertThat(
      cFacade.isSourceCodeParsable(
        printerOrig.print(program).sourceCode,
      ),
    ).isTrue()
    assertThat(
      pnfcFacade.isSourceCodeParsable(
        printerOrig.print(program).sourceCode,
      ),
    ).isTrue()
    val invalidProgram = deriveInvalidProgram(program)
    assertThat(
      cFacade.isSourceCodeParsable(
        printerOrig.print(invalidProgram).sourceCode,
      ),
    ).isFalse()
    assertThat(
      pnfcFacade.isSourceCodeParsable(
        printerOrig.print(invalidProgram).sourceCode,
      ),
    ).isFalse()
  }

  @Test
  fun testPartialParsing() {
    val result =
      cFacade.parseString(
        string = "int a; int b;",
        filename = "",
        startRuleName = "declaration",
      )
    assertThat(result.lazyAllTokens.map { it.text }.joinToString(separator = " ")).isEqualTo(
      "int a ; int b ;",
    )
    assertThat(result.isInputCompletelyConsumed()).isFalse()
  }

  @Test
  fun testCompleteParsing() {
    val result =
      cFacade.parseString(
        string =
          """
          struct Student {
            char name[50];
            int age;
          };
          """.trimIndent(),
        filename = "",
        startRuleName = null,
      )
    assertThat(result.isInputCompletelyConsumed()).isTrue()
  }

  companion object {
    private fun projectProgram(
      program: TokenizedProgram,
      vararg lexemes: String,
    ): TokenizedProgram {
      val builder = ImmutableList.builder<PersesAntlrToken>()
      var index = 0
      val tokens = program.tokens
      for (lexeme in lexemes) {
        while (index < tokens.size) {
          val persesToken = tokens[index].asAntlrToken()
          ++index
          if (persesToken.lexemeText == lexeme) {
            builder.add(persesToken)
            break
          }
        }
      }
      return TokenizedProgram(builder.build(), program.factory)
    }

    private fun deriveInvalidProgram(program: TokenizedProgram): TokenizedProgram {
      val builder = ImmutableList.builder<PersesTokenFactory.AbstractPersesToken>()
      for (t in program.tokens) {
        val lexeme = t.lexemeText
        if (lexeme == ";" || lexeme == "," || lexeme == ":") {
          continue
        }
        builder.add(t)
      }
      return TokenizedProgram(builder.build(), program.factory)
    }
  }
}
