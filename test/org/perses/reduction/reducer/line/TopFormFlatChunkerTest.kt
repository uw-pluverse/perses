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
package org.perses.reduction.reducer.line

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.PnfCParserFacade
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTreeParserUtility

@RunWith(JUnit4::class)
class TopFormFlatChunkerTest {
  private val cFacade = PnfCParserFacade()

  private fun tokensOf(sourceCode: String): ImmutableList<LexerRuleSparTreeNode> =
    SparTreeParserUtility
      .buildSparTree(
        sourceCode = sourceCode,
        parserFacade = cFacade,
        specifiedSparTreeNodeFactory = null,
        simplifyTree = true,
        canonicalTokenCountComputer = { null },
        errorMode = ParseErrorHandling.TOLERANT,
      ).remainingLexerRuleNodes

  /** Renders each chunk as its space-joined lexemes, so an expectation is just a list of strings. */
  private fun chunksOf(
    sourceCode: String,
    level: Int,
  ): List<String> =
    TopFormFlatChunker
      .computeChunks(tokensOf(sourceCode), level)
      .map { chunk -> chunk.joinToString(" ") { it.token.lexemeText } }

  @Test
  fun levelZeroKeepsEachTopLevelFormWhole() {
    assertThat(
      chunksOf("int f() { int y = 1; return y; } int g() { return 0; }", level = 0),
    ).containsExactly(
      "int f ( ) { int y = 1 ; return y ; }",
      "int g ( ) { return 0 ; }",
    ).inOrder()
  }

  @Test
  fun levelOneSplitsTopLevelFormsIntoStatements() {
    assertThat(
      chunksOf("int f() { int y = 1; return y; } int g() { return 0; }", level = 1),
    ).containsExactly(
      "int f ( ) {",
      "int y = 1 ;",
      "return y ;",
      "}",
      "int g ( ) {",
      "return 0 ;",
      "}",
    ).inOrder()
  }

  @Test
  fun nestedBlockStaysWholeUntilItsOwnLevelIsReached() {
    val source = "void f() { if (a) { g(); h(); } i(); }"
    assertThat(chunksOf(source, level = 1))
      .containsExactly(
        "void f ( ) {",
        "if ( a ) { g ( ) ; h ( ) ; }",
        "i ( ) ;",
        "}",
      ).inOrder()
    assertThat(chunksOf(source, level = 2))
      .containsExactly(
        "void f ( ) {",
        "if ( a ) {",
        "g ( ) ;",
        "h ( ) ;",
        "}",
        "i ( ) ;",
        "}",
      ).inOrder()
  }

  /**
   * The original lexes `}` and a following `;` as the single lexeme `"}"(";"?)`, so the pair is one
   * cut. As tokens they are separate, and a naive walk would cut twice and strand a lone `;` chunk.
   */
  @Test
  fun closeBraceAbsorbsAFollowingSemicolon() {
    assertThat(chunksOf("struct S { int x; }; int y;", level = 0))
      .containsExactly(
        "struct S { int x ; } ;",
        "int y ;",
      ).inOrder()
    assertThat(chunksOf("struct S { int x; }; int y;", level = 1))
      .containsExactly(
        "struct S {",
        "int x ;",
        "} ;",
        "int y ;",
      ).inOrder()
  }

  /**
   * topformflat counts braces only -- it is blind to parentheses -- so once the nesting is within
   * the threshold it cuts at the semicolons inside a `for` header too, making header fragments
   * independently deletable. Replicated deliberately; the deletion of such a fragment simply fails
   * the property test. Suppressing cuts inside `(` and `[` is a possible refinement.
   */
  @Test
  fun semicolonsInsideAForHeaderAreCutPointsToo() {
    assertThat(
      chunksOf("void f() { for (i = 0; i < n; i++) { g(); } }", level = 1),
    ).containsExactly(
      "void f ( ) {",
      "for ( i = 0 ;",
      "i < n ;",
      "i ++ ) { g ( ) ; }",
      "}",
    ).inOrder()
  }

  /** The token stream has already resolved quoting, so these braces are not brace tokens at all. */
  @Test
  fun bracesInsideLiteralsDoNotAffectNesting() {
    assertThat(
      chunksOf("""char *s = "}{"; char c = '}'; int x;""", level = 0),
    ).containsExactly(
      """char * s = "}{" ;""",
      """char c = '}' ;""",
      "int x ;",
    ).inOrder()
  }

  /**
   * Blank lines -- and layout in general -- do not affect the grouping, because whitespace never
   * reaches the token stream. The original behaves differently: its catch-all rule rewrites every
   * unmatched newline to a space, so a blank line is smeared into the joined line rather than
   * preserved or removed, and C-Reduce needs a separate blank-line pass to delete one. Grouping here
   * is a function of the tokens alone, so the same program laid out differently must group
   * identically.
   */
  @Test
  fun blankLinesAndLayoutDoNotAffectChunking() {
    val dense = "int f() { int y = 1; return y; } int g() { return 0; }"
    val sparse =
      """
      |
      |int f() {
      |
      |    int y = 1;
      |
      |
      |    return y;
      |
      |}
      |
      |
      |int g() { return 0; }
      |
      """.trimMargin()
    for (level in listOf(0, 1, 2)) {
      assertThat(chunksOf(sparse, level)).isEqualTo(chunksOf(dense, level))
    }
  }

  /** `nesting--` is unguarded in the original and may go negative; the partition stays well defined. */
  @Test
  fun unbalancedCloseBraceDoesNotCrash() {
    assertThat(chunksOf("} int x;", level = 0))
      .containsExactly(
        "}",
        "int x ;",
      ).inOrder()
  }

  @Test
  fun trailingTokensWithoutATerminatorStillFormAChunk() {
    assertThat(chunksOf("int x", level = 0)).containsExactly("int x")
  }

  @Test
  fun emptyInputYieldsNoChunks() {
    assertThat(TopFormFlatChunker.computeChunks(ImmutableList.of(), nestingThreshold = 0)).isEmpty()
  }

  @Test
  fun negativeThresholdIsRejected() {
    val e =
      org.junit.Assert.assertThrows(IllegalArgumentException::class.java) {
        TopFormFlatChunker.computeChunks(ImmutableList.of(), nestingThreshold = -1)
      }
    assertThat(e).hasMessageThat().contains("Must be non-negative")
  }
}
