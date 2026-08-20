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
package org.perses.grammar.dyck

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.OptCLexer
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTreeParserUtility

@RunWith(JUnit4::class)
class AdaptiveDyckParserFacadeTest {
  private val adaptive = AdaptiveDyckParserFacade(OptCLexer::class.java)

  private val pristineAdaptive = PristineAdaptiveDyckParserFacade(OptCLexer::class.java)

  @Test
  fun allKindsAreEnabledWhenTheyAllNest() {
    assertThat(delimiterTypesOf("a{b(c[d])}"))
      .containsExactly(
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.OPEN_PARENTHESIS,
        PnfLineAwareDyckParser.OPEN_BRACKET,
        PnfLineAwareDyckParser.CLOSE_BRACKET,
        PnfLineAwareDyckParser.CLOSE_PARENTHESIS,
        PnfLineAwareDyckParser.CLOSE_BRACE,
      ).inOrder()
  }

  @Test
  fun anUnbalancedKindIsDemotedWhileTheOthersKeepTheirStructure() {
    // The `}` has no opener -- an `#if`-style arm -- so braces become text; `()` and `[]` still nest.
    assertThat(delimiterTypesOf("a}b(c)[d]"))
      .containsExactly(
        PnfLineAwareDyckParser.OPEN_PARENTHESIS,
        PnfLineAwareDyckParser.CLOSE_PARENTHESIS,
        PnfLineAwareDyckParser.OPEN_BRACKET,
        PnfLineAwareDyckParser.CLOSE_BRACKET,
      ).inOrder()
  }

  @Test
  fun kindsThatPairByCountButInterleaveAreNotBothEnabled() {
    // `{ ( } )` pairs both kinds by count yet nests neither, so the two cannot be enabled together.
    // Braces win the tie-break, and the parentheses become text.
    assertThat(delimiterTypesOf("{a(b}c)"))
      .containsExactly(
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.CLOSE_BRACE,
      ).inOrder()
  }

  @Test
  fun aKindWhoseCloseComesFirstDoesNotPairEvenWhenTheCountsMatch() {
    // `} ... {` counts one open and one close, but the close has nothing to close.
    assertThat(delimiterTypesOf("a}b{c")).isEmpty()
  }

  @Test
  fun aKindDroppedForNotPairingIsGoneBeforeTheInterleavingIsResolved() {
    // `[` never pairs, so it is discarded outright; braces and parentheses each pair but interleave,
    // and the tie-break then keeps the braces.
    assertThat(delimiterTypesOf("{a(b}c)[d"))
      .containsExactly(
        PnfLineAwareDyckParser.OPEN_BRACE,
        PnfLineAwareDyckParser.CLOSE_BRACE,
      ).inOrder()
  }

  @Test
  fun everyKindIsDemotedWhenNoneNests() {
    assertThat(delimiterTypesOf("a}b)c]")).isEmpty()
    // A stream with no enabled delimiter is a flat OTHER run, which always parses.
    assertThat(parses("a}b)c]", adaptive)).isTrue()
  }

  @Test
  fun theChoiceIsMadePerInputRatherThanPerFacade() {
    assertThat(delimiterTypesOf("(a)"))
      .containsExactly(
        PnfLineAwareDyckParser.OPEN_PARENTHESIS,
        PnfLineAwareDyckParser.CLOSE_PARENTHESIS,
      ).inOrder()
    assertThat(delimiterTypesOf("(a")).isEmpty()
  }

  @Test
  fun aFileTheFixedFacadeCannotParseStillParsesAdaptively() {
    // The exact input a fixed brace+parenthesis+bracket facade rejects.
    val source = "int f(int x) {\n  if (x) }\n  return x;\n}\n"
    assertThat(parses(source, BraceParenthesisBracketDyckParserFacade(OptCLexer::class.java)))
      .isFalse()
    assertThat(parses(source, adaptive)).isTrue()
    assertThat(parses(source, pristineAdaptive)).isTrue()
  }

  @Test
  fun withNothingPairedTheGrammarDegradesToLines() {
    // Every kind is broken by a close that precedes its open -- the `#if 0` arm holds a bare
    // `) } ]` -- and the last two lines leave a `(` and a `[` unclosed on top of that. No fixed Dyck
    // facade can read this, in either grammar; the adaptive one demotes all three kinds, and what is
    // left is one line node per source line, with the delimiters among their plain-text leaves.
    val source =
      """
      #if 0
      ) } ]
      #endif
      int keep_MARKER = f ( dead_a ;
      int dead_b [ 3 ;
      """.trimIndent()
    val lexer = OptCLexer::class.java
    assertThat(parses(source, PristineBraceParenthesisBracketDyckParserFacade(lexer))).isFalse()
    assertThat(parses(source, BraceParenthesisBracketDyckParserFacade(lexer))).isFalse()
    assertThat(delimiterTypesOf(source)).isEmpty()
    assertThat(tokenTextsPerLineOf(source))
      .containsExactly(
        listOf("#", "if", "0"),
        listOf(")", "}", "]"),
        listOf("#", "endif"),
        listOf("int", "keep_MARKER", "=", "f", "(", "dead_a", ";"),
        listOf("int", "dead_b", "[", "3", ";"),
      ).inOrder()
  }

  /**
   * The leaf texts under each child of the grammar's `lines` node, in source order -- that is, one
   * entry per line the parse recognized. The `line` rule itself does not survive: it has a single
   * child here, so the tree simplifier collapses it into the PNF aux rule beneath it.
   */
  private fun tokenTextsPerLineOf(source: String): List<List<String>> {
    val tree =
      SparTreeParserUtility.buildSparTree(
        sourceCode = source,
        parserFacade = adaptive,
        specifiedSparTreeNodeFactory = null,
        simplifyTree = true,
        canonicalTokenCountComputer = { null },
        errorMode = ParseErrorHandling.STRICT,
      )
    val lineListNodes = ArrayList<AbstractSparTreeNode>()
    tree.realRoot.preOrderVisit { node ->
      if (node.ruleName == "lines") {
        lineListNodes.add(node)
      }
      node.immutableChildView
    }
    return lineListNodes.single().immutableChildView.map { line ->
      val texts = ArrayList<String>()
      line.preOrderVisit { node ->
        if (node is LexerRuleSparTreeNode) {
          texts.add(node.token.lexemeText)
        }
        node.immutableChildView
      }
      texts
    }
  }

  @Test
  fun theAdaptiveChoiceIsIndependentOfTheDyckGrammar() {
    assertThat(pristineAdaptive.tokenizeString("a}b(c)").map { it.type })
      .isEqualTo(adaptive.tokenizeString("a}b(c)").map { it.type })
  }

  private fun delimiterTypesOf(source: String): List<Int> =
    adaptive
      .tokenizeString(source)
      .map { it.type }
      .filter {
        it != PnfLineAwareDyckParser.OTHER &&
          it != PnfLineAwareDyckParser.FABRICATED_NEWLINE
      }

  private fun parses(
    source: String,
    facade: AbstractDyckParserFacade,
  ): Boolean =
    try {
      SparTreeParserUtility.buildSparTree(
        sourceCode = source,
        parserFacade = facade,
        specifiedSparTreeNodeFactory = null,
        simplifyTree = true,
        canonicalTokenCountComputer = { null },
        errorMode = ParseErrorHandling.STRICT,
      )
      true
    } catch (
      @Suppress("detekt:TooGenericExceptionCaught", "detekt:SwallowedException")
      e: RuntimeException,
    ) {
      false
    }
}
