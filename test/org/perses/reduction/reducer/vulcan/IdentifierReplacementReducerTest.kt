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
package org.perses.reduction.reducer.vulcan

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.spartree.LexerRuleSparTreeNode

@RunWith(JUnit4::class)
class IdentifierReplacementReducerTest {

  private val parserFacade = TestUtility.getFacade(LanguageC)

  val tokens = createTokens(
    """
        int f();
        int a();
        int b();
        int a;
    """.trimIndent(),
  )

  internal val candidates = IdentifierReplacementReducer.Candidates.compute(
    { tokens.asSequence() },
    { it.type in parserFacade.identifierTokenTypes },
  )

  @Test
  fun testOrderInCandidates() {
    assertThat(candidates.lexerNodeClusterWithSameLexemes).hasSize(3)
    candidates.lexerNodeClusterWithSameLexemes.first().let {
      assertThat(it.lexeme).isEqualTo("b")
    }
    candidates.lexerNodeClusterWithSameLexemes[1].let {
      assertThat(it.lexeme).isEqualTo("f")
    }
    candidates.lexerNodeClusterWithSameLexemes.last().let {
      assertThat(it.lexeme).isEqualTo("a")
      assertThat(it.lexerNodes).containsExactlyElementsIn(
        tokens.filter { t -> t.token.text == "a" },
      )
    }
  }

  @Test
  fun testComputeRelacementCandidates() {
    val a = candidates.getClusterWithName("a")!!
    assertThat(a.lexeme).isEqualTo("a")
    candidates.computeReplacementCandidates(a).let { cluster ->
      assertThat(cluster).hasSize(2)
      assertThat(cluster.map { it.lexeme }).containsExactly("f", "b")
    }

    val b = candidates.getClusterWithName("b")!!
    assertThat(b.lexeme).isEqualTo("b")
    candidates.computeReplacementCandidates(b).let { cluster ->
      assertThat(cluster).hasSize(2)
      assertThat(cluster.map { it.lexeme }).containsExactly("a", "f").inOrder()
    }
  }

  private fun createTokens(sourceCode: String): ImmutableList<LexerRuleSparTreeNode> {
    val tree = TestUtility.createSparTreeFromString(
      sourceCode,
      parserFacade.language,
    )
    return tree.remainingLexerRuleNodes
  }
}
