package org.perses.antlr.util

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class LexerParserCombinerTest {
  @Test
  fun test() {
    val lexerDef =
      """lexer grammar ToyLexer;
      | BREAK: 'break';
      | NIL_LIT: 'nil';
      | fragment DECIMALS
      |  : [0-9]+
      |  ;
    """.trimMargin()

    val parserDef =
      """parser grammar ToyParser;
      | options {
      |     tokenVocab = ToyLexer;
      |     superClass = ToyParserBase;
      | }
      | 
      | start: BREAK NIL_LIT;
    """.trimMargin()

    val combined = removeWhitespaces(
      LexerParserCombiner.combineLexerAndParser(lexerDef, parserDef, "Toy")
    )

    val expected = removeWhitespaces(
      """// Combined by org.perses.antlr.util.LexerParserCombiner
      // DO NOT MODIFY.
      grammar Toy;
      BREAK : 'break' ;
      NIL_LIT : 'nil' ;
      fragment DECIMALS : [0-9]+;
      start : BREAK NIL_LIT ;
      """.trimIndent()
    )
    Truth.assertThat(combined).isEqualTo(expected)
  }

  companion object {
    fun removeWhitespaces(string: String) = string.replace(Regex(pattern = "\\s+"), "")
  }
}
