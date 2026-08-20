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
package org.perses.reduction.reducer.vulcan

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.PnfCParserFacade
import org.perses.reduction.ReducerFunctionalTestUtility

@RunWith(JUnit4::class)
class SubTreeReplacementReducerTest {
  @Test
  fun testFindAllAlternativeRulesInPayload() {
    val facade = PnfCParserFacade()
    val sparTree =
      TestUtility.createSparTreeFromString(
        sourceCode =
          """
        |int a = !!!!!!!!!!!!!b;
          """.trimMargin(),
        facade = facade,
        simplifyTree = true,
      )
    sparTree.printTreeStructureToStdout()
    val tokenB = sparTree.getTokenNodeForText("b").single()
    val result =
      SubTreeReplacementReducer.findAllAlternativeRulesInPayload(
        tokenB,
      )
    assertThat(result.size).isGreaterThan(1)
  }

  @Test
  fun test() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/reduction/reducer/vulcan/bug_for_subtree_on_wat",
      testScript = "r.sh",
      sourceFile = "small.wat",
      reducerAnnotation = SubTreeReplacementReducer.META,
    ).use { utility ->
      val reducer = utility.createReducers().single() as SubTreeReplacementReducer
      val tree = utility.sparTree
      // Should not crash
      val edits = reducer.sequenceOfCandidates(tree).toList()
      edits.forEach { edit ->
        val action = edit.actionSet.actions.single()
        val targetNode = action.targetNode
        val replacementNode = action.replacingNode
        assertThat(targetNode.tokenListCostlyComputed.size)
          .isAtLeast(replacementNode.tokenListCostlyComputed.size)
      }
    }
  }
}
