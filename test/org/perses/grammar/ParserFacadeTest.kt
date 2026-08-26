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
package org.perses.grammar
import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createSparTreeFromFile
import org.perses.TestUtility.createSparTreeFromString
import org.perses.grammar.AntlrFailureException
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.scala.LanguageScala
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.program.AbstractPersesToken
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.util.FileSystemUtil
import org.perses.util.transformToImmutableList
import java.nio.file.Files
import java.nio.file.Paths

@RunWith(JUnit4::class)
class ParserFacadeTest {
  private val cFacade = CParserFacade()
  private val pnfcFacade = PnfCParserFacade()
  private val scalaFacade = PnfScalaParserFacade()
  private val tempDir = FileSystemUtil.createTempDirForObject(this)

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
    scalaProgram = createSparTreeFromString(scalaSourceCode, LanguageScala).programSnapshot.payload
  }

  @After
  fun teardown() {
    tempDir.toFile().deleteRecursively()
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
  fun testCountTokensInString() {
    assertThat(cFacade.countTokensInString("a b c")).isEqualTo(3)
    assertThat(cFacade.countTokensInString("(0, 0, 0);")).isEqualTo(8)
    assertThat(cFacade.countTokensInString("int a; int b; int a, b;")).isEqualTo(11)
  }

  @Test
  fun testCountTokensInEmptyString() {
    assertThat(cFacade.countTokensInString("")).isEqualTo(0)
    assertThat(cFacade.countTokensInString("   \n\t  ")).isEqualTo(0)
  }

  @Test
  fun testCountTokensInStringExcludesHiddenChannelTokens() {
    // Comments and whitespace are not on the default channel and must not be counted.
    val withComments = "int /* block */ a ; // line comment\nint b ;"
    assertThat(cFacade.countTokensInString(withComments)).isEqualTo(6)
  }

  @Test
  fun testComputeProgramSizeOfFile() {
    val file = tempDir.resolve("t.c")
    Files.writeString(file, "int aaa ;\n// a comment\nint bb ;\n")

    val size = cFacade.computeProgramSizeOf(file)

    // The 6 tokens are: int aaa ; int bb ;
    assertThat(size.surrogateTokenCount).isEqualTo(6)
    // No canonical count is specified, so it falls back to the surrogate count.
    assertThat(size.canonicalTokenCount).isEqualTo(6)
    // Character counts are over token lexemes: whitespace and comments do not count.
    assertThat(size.totalCharacterCount).isEqualTo("intaaa;intbb;".length)
    assertThat(size.nonBlankCharacterCount).isEqualTo("intaaa;intbb;".length)
    assertThat(size.payload).isEqualTo(Unit)
  }

  @Test
  fun testComputeProgramSizeOfStringContent() {
    val size = cFacade.computeProgramSizeOf(content = "int a ; // c\n")

    assertThat(size.canonicalTokenCount).isEqualTo(3)
    assertThat(size.totalCharacterCount).isEqualTo("inta;".length)
  }

  @Test
  fun testCountTokensInStringMatchesTokenizeStringSize() {
    val programs =
      listOf(
        "",
        "a b c",
        "(0, 0, 0);",
        "int a; int b; int a, b;",
        "struct Student { char name[50]; int age; };",
        "int /* c */ a ; // x\nint b ;",
      )
    for (facade in listOf(cFacade, pnfcFacade)) {
      for (program in programs) {
        assertThat(facade.countTokensInString(program))
          .isEqualTo(facade.tokenizeString(program).size)
      }
    }
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
    val program = createSparTreeFromFile("test_data/misc/t1.c").programSnapshot.payload
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
        errorMode = ParseErrorHandling.STRICT,
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
        errorMode = ParseErrorHandling.STRICT,
      )
    assertThat(result.isInputCompletelyConsumed()).isTrue()
  }

  @Test
  fun testCountTokensOnCleanCodeMatchesTheLexer() {
    val code = "int main(void) { int x = 1; x += 2; return x; }"
    assertThat(pnfcFacade.countTokensInString(code))
      .isEqualTo(pnfcFacade.tokenizeString(code).size)
  }

  @Test
  fun testCountTokensDoesNotThrowOnAnUnlexableCharacter() {
    // Counting is not parsing. `#` has no token in the preprocessed C grammar; a strict count used
    // to throw here, and that exception escaped through the reduction driver as "the program is not
    // parsable by its preferred parser facade", skipping the Dyck reducer on exactly the programs
    // the tolerant fallback exists for. See benchmark_toys/c_unlexable_char_blocks_dyck.
    assertThat(pnfcFacade.countTokensInString("#if 0\nint x;\n")).isGreaterThan(0)
  }

  @Test
  fun testCountTokensMatchesTheLeavesOfTheTolerantTree() {
    // The count has to describe the program the reducer actually works on: the tolerant parse
    // splices every dropped character run back in as a leaf (insertDroppedCharacters), so the count
    // must equal the tree's leaf count, not merely the tokens the lexer managed to match.
    for (code in listOf(
      "int x = 1;",
      "#if 0\nint x;\n#endif\n",
      "int x = 1; @ int y = 2;",
      "int x = 1; @@@ int y = 2;",
      "st\\\natic int f(void) { return 0; }",
    )) {
      val tree = pnfcFacade.parseString(code, errorMode = ParseErrorHandling.TOLERANT).tree
      assertThat(pnfcFacade.countTokensInString(code)).isEqualTo(countLeaves(tree))
    }
  }

  @Test
  fun testCountTokensCountsACharacterTheGrammarCannotLex() {
    val without = pnfcFacade.countTokensInString("int x = 1;  int y = 2;")
    assertThat(pnfcFacade.countTokensInString("int x = 1; @ int y = 2;")).isEqualTo(without + 1)
    assertThat(pnfcFacade.countTokensInString("int x = 1; @@@ int y = 2;")).isEqualTo(without + 3)
  }

  /** Terminals only: an ANTLR rule node that matched nothing is childless but is not a token. */
  private fun countLeaves(tree: org.antlr.v4.runtime.tree.ParseTree): Int =
    when {
      tree is org.antlr.v4.runtime.tree.TerminalNode ->
        if (tree.symbol.type == org.antlr.v4.runtime.Token.EOF) 0 else 1
      else -> (0 until tree.childCount).sumOf { countLeaves(tree.getChild(it)) }
    }

  companion object {
    private fun projectProgram(
      program: TokenizedProgram,
      vararg lexemes: String,
    ): TokenizedProgram {
      val builder = ImmutableList.builder<AbstractPersesToken.AntlrToken>()
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
      return TokenizedProgram(builder.build())
    }

    private fun deriveInvalidProgram(program: TokenizedProgram): TokenizedProgram {
      val builder = ImmutableList.builder<AbstractPersesToken>()
      for (t in program.tokens) {
        val lexeme = t.lexemeText
        if (lexeme == ";" || lexeme == "," || lexeme == ":") {
          continue
        }
        builder.add(t)
      }
      return TokenizedProgram(builder.build())
    }
  }
}
