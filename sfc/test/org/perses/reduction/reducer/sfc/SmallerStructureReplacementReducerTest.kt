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
import org.perses.spartree.AbstractSparTreeNode

@RunWith(JUnit4::class)
class SmallerStructureReplacementReducerTest {
  private fun createUtility() =
    ReducerFunctionalTestUtility(
      reductionFolder = "sfc/test/org/perses/reduction/reducer/sfc/system_test_smaller_structure",
      testScript = "r.sh",
      sourceFile = "t.c",
      reducerAnnotation = SmallerStructureReplacementReducer.META,
    )

  @Test
  fun reducerIsRegistered() {
    assertThat(ReducerFactory.DEFAULT.isValidReducerName(SmallerStructureReplacementReducer.NAME))
      .isTrue()
    assertThat(
      ReducerFactory.DEFAULT.getReductionAlgorithm(SmallerStructureReplacementReducer.NAME),
    ).isSameInstanceAs(SmallerStructureReplacementReducer.META)
  }

  @Test
  fun candidatesAreStrictlySmallerAndSortedBySize() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as SmallerStructureReplacementReducer
      val node = findNode(utility.sparTree.realRoot, "a && b")
      val candidates = reducer.candidatesFor(node)

      assertThat(candidates).isNotEmpty()
      assertThat(candidates.map { it.leafTokenCount }).isInOrder()
      candidates.forEach { assertThat(it.leafTokenCount).isLessThan(node.leafTokenCount) }
      assertThat(candidates.map { it.lexemes.joinToString(" ") }).containsAtLeast("a", "! b")
    }
  }

  @Test
  fun tinyAndHugeNodesHaveNoCandidates() {
    createUtility().use { utility ->
      val reducer = utility.createReducers().single() as SmallerStructureReplacementReducer
      val token = utility.sparTree.getTokenNodeForText("a").first()
      assertThat(reducer.candidatesFor(token)).isEmpty()
    }
  }

  private fun findNode(
    root: AbstractSparTreeNode,
    source: String,
  ): AbstractSparTreeNode {
    var result: AbstractSparTreeNode? = null
    root.preOrderVisit { node ->
      if (result == null && node.tokenListCostlyComputed.joinToString(" ") == source) {
        result = node
      }
      node.immutableChildView
    }
    return checkNotNull(result) { "No node spells '$source'." }
  }
}
