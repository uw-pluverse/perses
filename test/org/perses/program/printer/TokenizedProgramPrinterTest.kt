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
package org.perses.program.printer

import com.google.common.base.Joiner
import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
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
import org.perses.program.AbstractPersesToken
import org.perses.program.EnumFormatControl
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.util.transformToImmutableList
import java.nio.charset.StandardCharsets
import java.nio.file.Paths
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class TokenizedProgramPrinterTest {
  private val lexerAtnWrapperForC =
    LexerAtnWrapper.createLexerWrapperFromLexerClass(PnfCLexer::class.java)
  private val lexerAtnWrapperForRust =
    LexerAtnWrapper.createLexerWrapperFromLexerClass(PnfRustLexer::class.java)
  private val lexerAtnWrapperForSmtLibV2 =
    LexerAtnWrapper.createLexerWrapperFromLexerClass(PnfSMTLIBv2Lexer::class.java)

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
      PrinterRegistry
        .getPrinter(EnumFormatControl.ORIG_FORMAT)
        .print(program)
        .sourceCode
        .trim(),
    ).isEqualTo(sourceCode.trim())

    assertThat(
      PrinterRegistry
        .getPrinter(EnumFormatControl.COMPACT_ORIG_FORMAT)
        .print(program)
        .sourceCode
        .trim(),
    ).isEqualTo(
      """int a = 0;
      |int b = 0;
      |int c = 0;
      """.trimMargin(),
    )
  }

  @Test
  fun testDeducedPositionProviderWithCCode() {
    val sourceCode =
      """
      |int a, long_var, longlong_var ;
      |
      |;
      """.trimMargin()
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
    TokenizedProgram(
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
    ).let {
      val printedCode =
        PrinterRegistry
          .getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForC)
          .print(it)
          .sourceCode
          .trim()
      assertThat(printedCode).isEqualTo(
        """
      |int              longlong_var,a, long_var               ;
      |
      |;
        """.trimMargin(),
      )
    }
    val spaceToken = PersesTokenFactory.createPlainTextToken(" ")
    TokenizedProgram(
      ImmutableList.of(
        tokenInt,
        spaceToken,
        tokenLongLongVar,
        spaceToken,
        tokenSecondComma,
        spaceToken,
        tokenA,
        spaceToken,
        tokenFirstComma,
        spaceToken,
        tokenLongVar,
        spaceToken,
        tokenFirstSemicolon,
        tokenSecondSemicolon,
      ),
    ).let {
      val printedCode =
        PrinterRegistry
          .getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForC)
          .print(it)
          .sourceCode
          .trim()
      assertThat(printedCode).isEqualTo(
        """
      |int               longlong_var , a , long_var ;
      |
      |;
        """.trimMargin(),
      )
    }
  }

  @Test
  fun testDeducedPositionProviderWithRustCode() {
    val tokenPlacementRecorder = TokenPlacementRecorder()
    val sourceCode =
      """
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
    val newProgram =
      TokenizedProgram(
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
      )
    val printedSourceCode =
      PrinterRegistry
        .getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForRust)
        .print(newProgram, tokenPlacementRecorder)
        .sourceCode
        .trim()
    assertThat(
      printedSourceCode,
    ).isEqualTo(
      """
      fn main() {
                     let long_var = 0;let var = 0;
      }
      """.trimIndent(),
    )
    val printedProgram = createTokenizedProgramFromString(printedSourceCode, LanguageRust)
    validateTokenPlacementRecorder(
      originalProgram = newProgram,
      printedProgram = printedProgram,
      tokenPlacementRecorder,
    )
  }

  private fun validateTokenPlacementRecorder(
    originalProgram: TokenizedProgram,
    printedProgram: TokenizedProgram,
    tokenPlacementRecorder: TokenPlacementRecorder,
  ) {
    assertThat(originalProgram.tokens).hasSize(printedProgram.tokens.size)
    assertThat(originalProgram.tokens).isNotEmpty()
    originalProgram.tokens.zip(printedProgram.tokens).forEach { (original, new) ->
      assertThat(original.asAntlrToken().lexemeText).isEqualTo(new.asAntlrToken().lexemeText)
      assertThat(original).isNotSameInstanceAs(new)
      val originalPosition = tokenPlacementRecorder.getPositionOrNull(original)!!
      assertThat(originalPosition).isEqualTo(new.asAntlrToken().position)
    }
  }

  @Test
  fun testDeducedPositionProviderWithSmtCode() {
    val tokenPlacementRecorder = TokenPlacementRecorder()
    val sourceCode =
      """
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
    val newProgram =
      TokenizedProgram(
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
      )
    val printedSourceCode =
      PrinterRegistry
        .getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForSmtLibV2)
        .print(newProgram, tokenPlacementRecorder)
        .sourceCode
        .trim()
    assertThat(
      printedSourceCode,
    ).isEqualTo(
      "(declare-fun                          long_val() Int) " +
        "(declare-fun val                               () Int)",
    )
    validateTokenPlacementRecorder(
      originalProgram = newProgram,
      printedProgram = createTokenizedProgramFromString(printedSourceCode, LanguageSmtLibV2),
      tokenPlacementRecorder,
    )
  }

  @Test
  fun testCustomizePositionProviderAndTokenPlacementListener() {
    val program = createTokenizedProgramFromString("int a;", LanguageC)
    var printer =
      PrinterRegistry.getPrinter(
        EnumFormatControl.ORIG_FORMAT,
        object : AbstractTokenPositionProvider() {
          override fun getLine(token: AbstractPersesToken): Int =
            when (token.lexemeText) {
              "int" -> 2
              "a" -> 4
              ";" -> 5
              else -> error(token.lexemeText)
            }

          override fun getCharPositionInLine(
            token: AbstractPersesToken,
            currentCursorPositionInLine: Int,
            previousToken: AbstractPersesToken?,
          ): Int = 2
        },
      )
    val listener = TokenPlacementRecorder()
    val printedSourceCode = printer.print(program, listener).sourceCode
    val goldenString =
      """
     |
     |  int
     |
     |  a
     |  ;
     |
      """.trimMargin()
    assertThat(printedSourceCode).isEqualTo(goldenString)
    printer =
      PrinterRegistry.getPrinter(
        EnumFormatControl.ORIG_FORMAT,
        object : AbstractTokenPositionProvider() {
          override fun getLine(token: AbstractPersesToken): Int =
            listener.getPositionOrNull(token)!!.line

          override fun getCharPositionInLine(
            token: AbstractPersesToken,
            currentCursorPositionInLine: Int,
            previousToken: AbstractPersesToken?,
          ): Int = listener.getPositionOrNull(token)!!.charPositionInLine
        },
      )
    val secondPrintedSourceCode =
      printer
        .print(
          program,
        ).sourceCode
    assertThat(printedSourceCode).isEqualTo(secondPrintedSourceCode)
  }

  @Test
  fun testCustomizedPositionProvider() {
    val sourceCode = "int a;"
    val program = createTokenizedProgramFromString(sourceCode, LanguageC)
    assertThat(
      PrinterRegistry
        .getPrinter(
          EnumFormatControl.ORIG_FORMAT,
          object : AbstractTokenPositionProvider() {
            override fun getLine(token: AbstractPersesToken): Int =
              when (token.lexemeText) {
                "int" -> 1
                "a" -> 2
                ";" -> 3
                else -> error("unhandled")
              }

            override fun getCharPositionInLine(
              token: AbstractPersesToken,
              currentCursorPositionInLine: Int,
              previousToken: AbstractPersesToken?,
            ): Int = 0
          },
        ).print(
          program,
        ).sourceCode
        .trim(),
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

    val newProgram =
      TokenizedProgram(
        ImmutableList.of(first, fourth, third, fourth),
      )
    PrinterRegistry
      .getPrinter(EnumFormatControl.COMPACT_ORIG_FORMAT)
      .print(newProgram)
      .sourceCode
      .let {
        assertThat(it).isEqualTo("int    long_var, long_var\n")
      }
    PrinterRegistry
      .getPrinter(EnumFormatControl.ORIG_FORMAT)
      .print(newProgram)
      .sourceCode
      .let {
        assertThat(it).isEqualTo("int    long_var, long_var\n")
      }
  }

  @Test
  fun testDeducedPositionProviderShouldWorkWithSkewedTokens() {
    val sourceCode = "int a, long_var, longlong_var ;"
    val program = createTokenizedProgramFromString(sourceCode, LanguageC)
    val tokens = program.tokens
    val newProgram =
      TokenizedProgram(
        ImmutableList.of(
          tokens[0],
          tokens[5],
          tokens[2],
          tokens[1],
          tokens[4],
          tokens[3],
          tokens[6],
        ),
      )
    assertThat(
      PrinterRegistry
        .getPrinter(EnumFormatControl.ORIG_FORMAT, lexerAtnWrapperForC)
        .print(
          newProgram,
        ).sourceCode,
    ).isEqualTo("int              longlong_var,a          ,long_var               ;\n")
  }

  private fun testCodeFormatRemains(filepath: String) {
    val program = TestUtility.createTokenizedProgramFromFile(filepath)
    assertThat(
      PrinterRegistry
        .getPrinter(EnumFormatControl.ORIG_FORMAT)
        .print(program)
        .sourceCode
        .trim(),
    ).isEqualTo(Paths.get(filepath).readText(StandardCharsets.UTF_8).trim())
  }

  private fun testTokenEquivalence(filepath: String) {
    val program =
      Joiner
        .on("")
        .join(
          TestUtility
            .createTokenizedProgramFromFile(filepath)
            .tokens
            .transformToImmutableList {
              it.lexemeText.replace("\\s|\n".toRegex(), "")
            },
        )

    val text =
      Paths
        .get(filepath)
        .readText(StandardCharsets.UTF_8)
        .replace("\\s|\n".toRegex(), "")
    assertThat(program).isEqualTo(text)
  }
}
