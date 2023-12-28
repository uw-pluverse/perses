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
package org.perses.program.printer

import com.google.common.base.Joiner
import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.TestUtility.createTokenizedProgramFromString
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCLexer
import org.perses.grammar.rust.LanguageRust
import org.perses.grammar.rust.PnfRustLexer
import org.perses.grammar.smtlibv2.LanguageSmtLibV2
import org.perses.grammar.smtlibv2.PnfSMTLIBv2Lexer
import org.perses.program.EnumFormatControl
import org.perses.program.PersesTokenFactory
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import java.nio.charset.StandardCharsets
import java.nio.file.Paths
import java.util.stream.Collectors
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class TokenizedProgramPrinterTest {

  private val lexerAtnWrapperForC = LexerAtnWrapper(PnfCLexer::class.java)
  private val lexerAtnWrapperForRust = LexerAtnWrapper(PnfRustLexer::class.java)
  private val lexerAtnWrapperForSmtLibV2 = LexerAtnWrapper(PnfSMTLIBv2Lexer::class.java)

  @Test
  fun testCodeFormatRemains() {
    testCodeFormatRemains("test_data/java_helloworld/t.java")
    testCodeFormatRemains("test_data/parentheses/t.c")
  }

  @Test
  fun testPrintCodeInLines() {
    testTokenEquivalence("test_data/java_helloworld/t.java")
    testTokenEquivalence("test_data/parentheses/t.c")
  }

  @Test
  fun testCompactSourceCode() {
    val sourceCode =
      """int a = 0;
      |
      |int b = 0;
      |
      |int c = 0;
      """.trimMargin()
    val program = createTokenizedProgramFromString(sourceCode, LanguageC)
    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT)
        .print(program).sourceCode.trim(),
    ).isEqualTo(sourceCode.trim())

    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.COMPACT_ORIG_FORMAT)
        .print(program).sourceCode.trim(),
    ).isEqualTo(
      """int a = 0;
      |int b = 0;
      |int c = 0;
      """.trimMargin(),
    )
  }

  @Test
  fun testDeducedPositionProviderWithCCode() {
    val sourceCode = """
      int a, long_var, longlong_var ;
      
      ;
    """.trimIndent()
    val program = createTokenizedProgramFromString(sourceCode, LanguageC)
    val tokens = program.tokens
    val tokenInt = tokens[0]
    val tokenA = tokens[1]
    val tokenFirstComma = tokens[2]
    val tokenLongVar = tokens[3]
    val tokenSecondComma = tokens[4]
    val tokenLongLongVar = tokens[5]
    val tokenFirstSemicolon = tokens[6]
    val tokenSecondSemicolon = tokens[7]
    val newProgram = TokenizedProgram(
      ImmutableList.of(
        tokenInt,
        tokenLongLongVar,
        tokenSecondComma,
        tokenA,
        tokenFirstComma,
        tokenLongVar,
        tokenFirstSemicolon,
        tokenSecondSemicolon,
      ),
      program.factory,
    )
    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForC)
        .print(newProgram).sourceCode.trim(),
    ).isEqualTo(
      """
        int              longlong_var,a,long_var;
    
        ;
      """.trimIndent(),
    )
  }

  @Test
  fun testDeducedPositionProviderWithRustCode() {
    val sourceCode = """
      fn main() {
        let var = 0; let long_var = 0;
      }
    """.trimIndent()
    val program = createTokenizedProgramFromString(sourceCode, LanguageRust)
    val tokens = program.tokens
    val tokenFn = tokens[0]
    val tokenMain = tokens[1]
    val tokenLeftParen = tokens[2]
    val tokenRightParen = tokens[3]
    val tokenLeftBrace = tokens[4]
    val tokenLet = tokens[5]
    val tokenVar = tokens[6]
    val tokenEqual = tokens[7]
    val tokenZero = tokens[8]
    val tokenSemicolon = tokens[9]
    val tokenLet2 = tokens[10]
    val tokenLongVar = tokens[11]
    val tokenEqual2 = tokens[12]
    val tokenZero2 = tokens[13]
    val tokenSemicolon2 = tokens[14]
    val tokenRightBrace = tokens[15]
    val newProgram = TokenizedProgram(
      ImmutableList.of(
        tokenFn,
        tokenMain,
        tokenLeftParen,
        tokenRightParen,
        tokenLeftBrace,
        tokenLet2,
        tokenLongVar,
        tokenEqual2,
        tokenZero2,
        tokenSemicolon2,
        tokenLet,
        tokenVar,
        tokenEqual,
        tokenZero,
        tokenSemicolon,
        tokenRightBrace,
      ),
      program.factory,
    )
    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForRust)
        .print(newProgram).sourceCode.trim(),
    ).isEqualTo(
      """
        fn main() {
                       let long_var = 0;let var=0;
        }
      """.trimIndent(),
    )
  }

  @Test
  fun testDeducedPositionProviderWithSmtCode() {
    val sourceCode = """
      (declare-fun val () Int) (declare-fun long_val () Int)
    """.trimIndent()
    val program = createTokenizedProgramFromString(sourceCode, LanguageSmtLibV2)
    val tokens = program.tokens
    val tokenLeftParen = tokens[0]
    val tokenDeclareFun = tokens[1]
    val tokenVal = tokens[2]
    val tokenLeftParen2 = tokens[3]
    val tokenRightParen2 = tokens[4]
    val tokenInt = tokens[5]
    val tokenRightParen = tokens[6]
    val tokenLeftParen3 = tokens[7]
    val tokenDeclareFun2 = tokens[8]
    val tokenLongVal = tokens[9]
    val tokenLeftParen4 = tokens[10]
    val tokenRightParen4 = tokens[11]
    val tokenInt2 = tokens[12]
    val tokenRightParen3 = tokens[13]
    val newProgram = TokenizedProgram(
      ImmutableList.of(
        tokenLeftParen,
        tokenDeclareFun,
        tokenLongVal,
        tokenLeftParen2,
        tokenRightParen2,
        tokenInt,
        tokenRightParen,
        tokenLeftParen3,
        tokenDeclareFun2,
        tokenVal,
        tokenLeftParen4,
        tokenRightParen4,
        tokenInt2,
        tokenRightParen3,
      ),
      program.factory,
    )
    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForSmtLibV2)
        .print(newProgram).sourceCode.trim(),
    ).isEqualTo(
      """
        (declare-fun                          long_val()Int)(declare-fun val()Int)
      """.trimIndent(),
    )
  }

  @Test
  fun testCustomizePositionProviderAndTokenPlacementListener() {
    val program = createTokenizedProgramFromString("int a;", LanguageC)
    var printer = PrinterRegistry.getPrinter(
      EnumFormatControl.ORIG_FORMAT,
      object : AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider() {
        override fun getLine(token: PersesToken): Int {
          return when (token.text) {
            "int" -> 2
            "a" -> 4
            ";" -> 5
            else -> error(token.text)
          }
        }

        override fun getCharPositionInLine(
          token: PersesToken,
          currentCursorPositionInLine: Int,
          previousToken: PersesToken?,
        ): Int {
          return 2
        }
      },
    )
    val map = HashMap<String, PersesTokenFactory.TokenPosition>()
    val listener = object : AbstractTokenizedProgramPrinter.AbstractTokenPlacementListener() {
      override fun onTokenPlacement(token: PersesToken, line: Int, charPositionInLine: Int) {
        assertThat(map.containsKey(token.text)).isFalse()
        map[token.text] = PersesTokenFactory.TokenPosition(line, charPositionInLine)
      }
    }
    val printedSourceCode = printer.print(
      program,
      listener,
    ).sourceCode
    val goldenString = """
     |
     |  int
     |
     |  a
     |  ;
     |
    """.trimMargin()
    assertThat(printedSourceCode).isEqualTo(goldenString)
    printer = PrinterRegistry.getPrinter(
      EnumFormatControl.ORIG_FORMAT,
      object : AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider() {
        override fun getLine(token: PersesToken): Int {
          return map[token.text]!!.line
        }

        override fun getCharPositionInLine(
          token: PersesToken,
          currentCursorPositionInLine: Int,
          previousToken: PersesToken?,
        ): Int {
          return map[token.text]!!.charPositionInLine
        }
      },
    )
    val secondPrintedSourceCode = printer.print(
      program,
    ).sourceCode
    assertThat(printedSourceCode).isEqualTo(secondPrintedSourceCode)
  }

  @Test
  fun testCustomizedPositionProvider() {
    val sourceCode = "int a;"
    val program = createTokenizedProgramFromString(sourceCode, LanguageC)
    assertThat(
      PrinterRegistry.getPrinter(
        EnumFormatControl.ORIG_FORMAT,
        object : AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider() {
          override fun getLine(token: PersesToken): Int {
            return when (token.text) {
              "int" -> 1
              "a" -> 2
              ";" -> 3
              else -> error("unhandled")
            }
          }

          override fun getCharPositionInLine(
            token: PersesToken,
            currentCursorPositionInLine: Int,
            previousToken: PersesToken?,
          ): Int {
            return 0
          }
        },
      ).print(
        program,
      ).sourceCode.trim(),
    ).isEqualTo(
      """int
      |a
      |;
      """.trimMargin().trim(),
    )
  }

  @Test
  fun testFormattedPrintingShouldCrashOnSkewedTokens() {
    val sourceCode = "int a, long_var;"
    val program = createTokenizedProgramFromString(sourceCode, LanguageC)
    val first = program.tokens[0]
    val third = program.tokens[2]
    val fourth = program.tokens[3]

    val newProgram = TokenizedProgram(
      ImmutableList.of(first, fourth, third, fourth),
      program.factory,
    )
    Assert.assertThrows(IllegalStateException::class.java) {
      PrinterRegistry.getPrinter(EnumFormatControl.COMPACT_ORIG_FORMAT)
        .print(newProgram).sourceCode
    }
    Assert.assertThrows(java.lang.IllegalStateException::class.java) {
      PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT)
        .print(newProgram).sourceCode
    }
  }

  @Test
  fun testDeducedPositionProviderShouldWorkWithSkewedTokens() {
    val sourceCode = "int a, long_var, longlong_var ;"
    val program = createTokenizedProgramFromString(sourceCode, LanguageC)
    val tokens = program.tokens
    val newProgram = TokenizedProgram(
      ImmutableList.of(tokens[0], tokens[5], tokens[2], tokens[1], tokens[4], tokens[3], tokens[6]),
      program.factory,
    )
    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForC)
        .print(
          newProgram,
        ).sourceCode,
    ).isEqualTo("int              longlong_var,a,long_var;\n")
  }

  private fun testCodeFormatRemains(filepath: String) {
    val program = TestUtility.createTokenizedProgramFromFile(filepath)
    assertThat(
      PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT)
        .print(program).sourceCode.trim(),
    ).isEqualTo(Paths.get(filepath).readText(StandardCharsets.UTF_8).trim())
  }

  private fun testTokenEquivalence(filepath: String) {
    val program = Joiner.on("")
      .join(
        TestUtility.createTokenizedProgramFromFile(filepath).tokens.stream()
          .map { obj: PersesToken -> obj.text }
          .map { s: String -> s.replace("\\s|\n".toRegex(), "") }
          .collect(Collectors.toList<String>()),
      )

    val text = Paths.get(filepath)
      .readText(StandardCharsets.UTF_8)
      .replace("\\s|\n".toRegex(), "")
    assertThat(program).isEqualTo(text)
  }
}
