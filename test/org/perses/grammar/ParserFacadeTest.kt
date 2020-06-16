package org.perses.grammar

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth
import org.antlr.v4.runtime.Token
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.PnfCParserFacade
import org.perses.program.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.tree.spar.SparTreeBuilder
import java.io.File
import java.io.IOException

@RunWith(JUnit4::class)
class ParserFacadeTest {
  private val facade = CParserFacade()
  private val pnfcFacade = PnfCParserFacade()

  @Test
  @Throws(IOException::class)
  fun testTokenize() {
    val tokens = facade.parseIntoTokens(File("test_data/misc/t1.c"))
    val tokenTexts = tokens.stream().map { obj: Token -> obj.text }.collect(ImmutableList.toImmutableList())
    Truth.assertThat(tokenTexts)
      .containsExactly("int", "a", ";", "int", "b", ";", "int", "a", ",", "b", ";")
      .inOrder()
  }

  @Test
  fun testIsParsable_true() {
    val program = TestUtility.createSparTreeFromFile("test_data/misc/t1.c").programSnapshot
    Truth.assertThat(facade.isSourceCodeParsable(program.toSourceCodeInOrigFormatWithBlankLines()))
      .isTrue()
    Truth.assertThat(facade.isSourceCodeParsable(program)).isTrue()
    Truth.assertThat(pnfcFacade.isSourceCodeParsable(program.toSourceCodeInOrigFormatWithBlankLines()))
      .isTrue()
    Truth.assertThat(pnfcFacade.isSourceCodeParsable(program)).isTrue()
    val invalidProgram = deriveInvalidProgram(program)
    Truth.assertThat(facade.isSourceCodeParsable(invalidProgram.toSourceCodeInOrigFormatWithBlankLines()))
      .isFalse()
    Truth.assertThat(facade.isSourceCodeParsable(invalidProgram)).isFalse()
    Truth.assertThat(
      pnfcFacade.isSourceCodeParsable(
        invalidProgram.toSourceCodeInOrigFormatWithBlankLines()))
      .isFalse()
    Truth.assertThat(pnfcFacade.isSourceCodeParsable(invalidProgram)).isFalse()
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
    val sparTreeFromFile = TestUtility.createSparTreeFromFile("test_data/misc/$filename")
    val originalProgram = sparTreeFromFile.programSnapshot
    val originalTokens = toAntlrTokens(originalProgram.tokens)
    val factory = sparTreeFromFile.tokenizedProgramFactory
    run {
      val (tree1) = facade.parseTokenizedProgram(originalProgram)
      val tree = SparTreeBuilder(facade.ruleHierarchy, factory)
        .build(tree1)
      val tokens = toAntlrTokens(tree.programSnapshot.tokens)
      Truth.assertThat(tokens).containsExactlyElementsIn(originalTokens).inOrder()
    }
    run {
      val (tree) = pnfcFacade.parseTokenizedProgram(originalProgram)
      val treeFromPnfc = SparTreeBuilder(pnfcFacade.ruleHierarchy, factory)
        .build(tree)
      val tokens = toAntlrTokens(treeFromPnfc.programSnapshot.tokens)
      Truth.assertThat(tokens).containsExactlyElementsIn(originalTokens).inOrder()
    }
  }

  companion object {
    private fun toAntlrTokens(tokens: ImmutableList<PersesToken>): ImmutableList<String?> {
      return tokens.stream().map { obj: PersesToken -> obj.text }.collect(ImmutableList.toImmutableList())
    }

    private fun deriveInvalidProgram(program: TokenizedProgram): TokenizedProgram {
      val builder = ImmutableList.builder<PersesToken>()
      for (t in program.tokens) {
        val lexeme = t.text
        if (lexeme == ";" || lexeme == ",") {
          continue
        }
        builder.add(t)
      }
      return TokenizedProgram(builder.build())
    }
  }
}