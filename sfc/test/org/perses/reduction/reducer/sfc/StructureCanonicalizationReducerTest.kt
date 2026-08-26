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
import org.perses.reduction.reducer.sfc.SfcTestUtility.spelling
import org.perses.spartree.AbstractSparTreeNode

@RunWith(JUnit4::class)
class StructureCanonicalizationReducerTest {
  private fun createUtility() =
    ReducerFunctionalTestUtility(
      reductionFolder =
        "sfc/test/org/perses/reduction/reducer/sfc/system_test_smaller_structure",
      testScript = "r.sh",
      sourceFile = "t.c",
      reducerAnnotation = StructureCanonicalizationReducer.META,
    )

  @Test
  fun reducerIsRegistered() {
    assertThat(ReducerFactory.DEFAULT.isValidReducerName(StructureCanonicalizationReducer.NAME))
      .isTrue()
    assertThat(
      ReducerFactory.DEFAULT.getReductionAlgorithm(StructureCanonicalizationReducer.NAME),
    ).isSameInstanceAs(StructureCanonicalizationReducer.META)
  }

  @Test
  fun everyCandidateSpellsAsManyTokensAsTheSubtree() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as StructureCanonicalizationReducer
      val nodesWithCandidates =
        nodesUnder(utility.sparTree.realRoot)
          .map { it to reducer.candidatesFor(it) }
          .filter { (_, candidates) -> candidates.isNotEmpty() }

      assertThat(nodesWithCandidates).isNotEmpty()
      nodesWithCandidates.forEach { (node, candidates) ->
        candidates.forEach { assertThat(it.leafTokenCount).isEqualTo(node.leafTokenCount) }
      }
    }
  }

  @Test
  fun everyCandidateComesFromAnAlternativeTheGrammarSpellsEarlier() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as StructureCanonicalizationReducer
      val paths =
        RuleAlternativePath(
          utility.reducerContext.configuration.canonicalParserFacade.ruleHierarchy,
        )

      nodesUnder(utility.sparTree.realRoot).forEach { node ->
        val payload = node.payload!!
        val expectedRule = payload.expectedAntlrRuleType ?: return@forEach
        val pathOfNode =
          paths.findSmallestPath(expectedRule, payload.actualAntlrRuleType!!) ?: return@forEach
        reducer.candidatesFor(node).forEach { candidate ->
          val pathOfCandidate =
            paths.findSmallestPath(expectedRule, candidate.template.rule)!! +
              candidate.template.alternativeIndex
          assertThat(RuleAlternativePath.LEXICOGRAPHIC_ORDER.compare(pathOfCandidate, pathOfNode))
            .isLessThan(0)
        }
      }
    }
  }

  @Test
  fun theCandidatesComeMostCanonicalFirst() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as StructureCanonicalizationReducer
      val paths =
        RuleAlternativePath(
          utility.reducerContext.configuration.canonicalParserFacade.ruleHierarchy,
        )

      nodesUnder(utility.sparTree.realRoot).forEach { node ->
        val expectedRule = node.payload!!.expectedAntlrRuleType ?: return@forEach
        val pathsOfCandidates =
          reducer.candidatesFor(node).map {
            paths.findSmallestPath(expectedRule, it.template.rule)!! + it.template.alternativeIndex
          }
        assertThat(pathsOfCandidates.sortedWith(RuleAlternativePath.LEXICOGRAPHIC_ORDER))
          .isEqualTo(pathsOfCandidates)
      }
    }
  }

  @Test
  fun aCanonicalizedSubtreeSpellsSomethingElse() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as StructureCanonicalizationReducer

      nodesUnder(utility.sparTree.realRoot).forEach { node ->
        reducer.candidatesFor(node).forEach {
          assertThat(it.tree.spelling).isNotEqualTo(node.spelling)
        }
      }
    }
  }

  private fun nodesUnder(root: AbstractSparTreeNode): List<AbstractSparTreeNode> {
    val result = ArrayList<AbstractSparTreeNode>()
    root.preOrderVisit { node ->
      if (node.payload?.actualAntlrRuleType != null) {
        result.add(node)
      }
      node.immutableChildView
    }
    return result
  }
}
