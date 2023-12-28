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
package org.perses.spartree

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarHierarchy
import org.perses.antlr.RuleHierarchyEntry
import org.perses.spartree.AbstractNodePayload.Companion.concatenatePaylods
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class NodePayloadTest {

  val hierarchy = GrammarHierarchy.createFromString(
    """
      grammar T;
      a : 'a';
      b : 'b';
      c : 'c';
      d : 'd';
      e : 'e';
      f : 'f';
    """.trimIndent(),
  )

  val ruleA = hierarchy.getRuleHierarchyEntryWithNameOrThrow("a")
  val ruleB = hierarchy.getRuleHierarchyEntryWithNameOrThrow("b")
  val ruleC = hierarchy.getRuleHierarchyEntryWithNameOrThrow("c")
  val ruleD = hierarchy.getRuleHierarchyEntryWithNameOrThrow("d")
  val ruleE = hierarchy.getRuleHierarchyEntryWithNameOrThrow("e")
  val ruleF = hierarchy.getRuleHierarchyEntryWithNameOrThrow("f")

  @Test
  fun testConcatenatePayloadsNoOverlapping() {
    test(createPayload(ruleA), createPayload(ruleC), ruleA, ruleC)
  }

  @Test
  fun testConcatenatePayloadsNoOverlappingWithLongDescendant() {
    test(createPayload(ruleA), createPayload(ruleB, ruleC), ruleA, ruleC)
  }

  @Test
  fun testConcatenatePayloadsOverlapping() {
    test(createPayload(ruleA, ruleB), createPayload(ruleB, ruleC), ruleA, ruleB, ruleC)
    test(createPayload(ruleA, ruleB, ruleC), createPayload(ruleB, ruleC), ruleA, ruleB, ruleC)
    test(
      createPayload(ruleA, ruleB, ruleE, ruleC),
      createPayload(ruleB, ruleC),
      ruleA,
      ruleB,
      ruleC,
    )
  }

  fun test(
    ancestor: AbstractNodePayload,
    descendant: AbstractNodePayload,
    vararg expected: RuleHierarchyEntry,
  ) {
    assertThat(
      concatenatePaylods(ancestor, descendant).asSinglePayloadList.map { it.expectedAntlrRuleType },
    ).containsExactlyElementsIn(expected).inOrder()
  }

  private fun createPayload(vararg rules: RuleHierarchyEntry): AbstractNodePayload {
    require(rules.isNotEmpty())
    return AbstractNodePayload.create(
      rules
        .asSequence()
        .map { AbstractNodePayload.SinglePayload(it) }
        .toImmutableList(),
    )
  }
}
