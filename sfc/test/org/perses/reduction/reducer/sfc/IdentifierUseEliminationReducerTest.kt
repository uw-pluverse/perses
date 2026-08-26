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
package org.perses.reduction.reducer.sfc

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFactory
import org.perses.reduction.ReducerFunctionalTestUtility
import org.perses.reduction.reducer.sfc.SfcTestUtility.findNodeSpelling
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode

@RunWith(JUnit4::class)
class IdentifierUseEliminationReducerTest {
  private fun createUtility() =
    ReducerFunctionalTestUtility(
      reductionFolder =
        "sfc/test/org/perses/reduction/reducer/sfc/system_test_identifier_use_elimination",
      testScript = "r.sh",
      sourceFile = "t.c",
      reducerAnnotation = IdentifierUseEliminationReducer.META,
    )

  @Test
  fun reducerIsRegistered() {
    assertThat(ReducerFactory.DEFAULT.isValidReducerName(IdentifierUseEliminationReducer.NAME))
      .isTrue()
    assertThat(
      ReducerFactory.DEFAULT.getReductionAlgorithm(IdentifierUseEliminationReducer.NAME),
    ).isSameInstanceAs(IdentifierUseEliminationReducer.META)
  }

  @Test
  fun theUsesAreTheIdentifierTokensTheFacadeDeclares() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as IdentifierUseEliminationReducer
      val identifierTokenTypes =
        utility.reducerContext.configuration.canonicalParserFacade.fusedIdentifierTokenTypes

      val uses = reducer.identifierUsesOf(utility.sparTree)

      assertThat(uses.map { it.token.lexemeText }).containsAtLeast("main", "a", "b")
      uses.forEach {
        assertThat(identifierTokenTypes).contains(it.token.asAntlrToken().tokenType)
      }
    }
  }

  @Test
  fun theOccurrencesOfANameAreTriedFromTheLastToTheFirst() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as IdentifierUseEliminationReducer
      val everyIdentifierToken =
        utility.sparTree.realRoot
          .leafNodeSequence()
          .filter { it.token.lexemeText == "a" }
          .toList()

      val uses = reducer.identifierUsesOf(utility.sparTree).filter { it.token.lexemeText == "a" }

      // The first occurrence of a name is the likeliest to be its definition, and eliminating a
      // definition only wastes a property test, so it is tried last.
      assertThat(everyIdentifierToken).hasSize(uses.size)
      assertThat(uses).isEqualTo(everyIdentifierToken.asReversed())
    }
  }

  @Test
  fun noCandidateOfAnAncestorSpellsTheUseItGetsRidOf() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as IdentifierUseEliminationReducer
      val use = firstUseOf(utility.sparTree.realRoot, "a")

      val ancestorsWithCandidates =
        ancestorsOf(use).map { it to reducer.candidatesWithoutTheUse(it, use) }

      assertThat(ancestorsWithCandidates.any { (_, candidates) -> candidates.isNotEmpty() })
        .isTrue()
      ancestorsWithCandidates.forEach { (ancestor, candidates) ->
        candidates.forEach { candidate ->
          assertThat(candidate.leafTokenCount).isLessThan(ancestor.leafTokenCount)
          assertThat(candidate.tree.leafNodeSequence().none { it === use }).isTrue()
        }
      }
    }
  }

  @Test
  fun aCandidateOfAnAncestorKeepsWhatIsNotTheUse() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as IdentifierUseEliminationReducer
      val condition = utility.sparTree.findNodeSpelling("a && b")
      val use = condition.leafNodeSequence().first { it.token.lexemeText == "a" }

      val candidates = reducer.candidatesWithoutTheUse(condition, use)

      // Every candidate is smaller, spells no `a`, and at least one of them reuses `b`, which
      // is the only subtree of the condition left to build from.
      assertThat(candidates).isNotEmpty()
      candidates.forEach { assertThat(it.lexemes).doesNotContain("a") }
      assertThat(candidates.any { it.lexemes.contains("b") }).isTrue()
    }
  }

  private fun firstUseOf(
    root: AbstractSparTreeNode,
    lexeme: String,
  ): LexerRuleSparTreeNode = root.leafNodeSequence().first { it.token.lexemeText == lexeme }

  private fun ancestorsOf(node: AbstractSparTreeNode): List<AbstractSparTreeNode> {
    val result = ArrayList<AbstractSparTreeNode>()
    var ancestor = node.parent
    while (ancestor != null && !ancestor.isRootNode()) {
      result.add(ancestor)
      ancestor = ancestor.parent
    }
    return result
  }
}
