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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.TestUtility.createSparTreeFromFile
import org.perses.grammar.c.LanguageC
import org.perses.spartree.AbstractNodePayload.CollapsingPayload
import org.perses.spartree.AbstractNodePayload.SinglePayload
import org.perses.spartree.SparTreeSimplifier.simplifySingleEntrySingleExitPath
import org.perses.util.toImmutableList
import java.nio.file.Paths

@RunWith(JUnit4::class)
class SparTreeSimplifierTest {

  @Test
  fun testSESESimplification() {
    val tree = createSparTreeFromFile(Paths.get("test_data/misc/t10.c"))
    simplifySingleEntrySingleExitPath(tree)
    assertThat(SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(tree.root)).isTrue()
  }

  @Test
  fun testPayloadsShouldBeEquivalentBeforeAndAfterSimplification() {
    val tree = TestUtility.createSparTreeFromString(
      """
        int a = 1 + 2;
        int b = a++ * a;
      """.trimIndent(),
      LanguageC,
      simplifyTree = false,
    )
    assertThrows(Exception::class.java) {
      SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(tree.root)
    }
    val payloadsBeforeSimplification = ArrayList<SinglePayload>()
    tree.root.preOrderVisit {
      it.payload?.let {
        payloadsBeforeSimplification.addAll(it.asSinglePayloadList)
      }
      it.immutableChildView
    }
    SparTreeSimplifier.simplify(tree)
    SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(tree.root)
    val payloadsAfterSimplification = ArrayList<SinglePayload>()
    tree.root.preOrderVisit {
      it.payload?.let {
        payloadsAfterSimplification.addAll(it.asSinglePayloadList)
      }
      it.immutableChildView
    }
    assertThat(payloadsBeforeSimplification).isEqualTo(payloadsAfterSimplification)
  }

  @Test
  fun testCollapsingPayload() {
    val tree = TestUtility.createSparTreeFromString(
      """
        int a = 1 + 2;
      """.trimIndent(),
      LanguageC,
      simplifyTree = false,
    )
    tree.printTreeStructureToStdout()
    val two = tree.getTokenNodeForText("2").single()
    val typeTwo = two.payload!!
    val plus = tree.getTokenNodeForText("+").single()
    val typePlus = plus.payload!!

    assertThat(
      two.payload,
    ).isInstanceOf(SinglePayload::class.java)
    assertThat(
      plus.payload,
    ).isInstanceOf(SinglePayload::class.java)

    val lowestCommonAncestor = AbstractTreeNode.findLowestAncestor(two, plus)
    val nodesBetweenLcaAndTwo = getNodesBetween(
      ancestor = lowestCommonAncestor,
      descendant = two,
    ).map { it.payload!! }
    val nodesBetweenLcaAndPlus = getNodesBetween(
      ancestor = lowestCommonAncestor,
      descendant = plus,
    ).map { it.payload!! }
    assertThat(nodesBetweenLcaAndPlus).isNotEmpty()
    assertThat(nodesBetweenLcaAndTwo).isNotEmpty()

    SparTreeSimplifier.simplify(tree)
    assertThat(
      getNodesBetween(
        ancestor = lowestCommonAncestor,
        descendant = two,
      ),
    ).isEmpty()
    assertThat(
      getNodesBetween(
        ancestor = lowestCommonAncestor,
        descendant = plus,
      ),
    ).isEmpty()

    run {
      val payloadTwo = two.payload as CollapsingPayload
      assertThat(
        payloadTwo.collapsedAncestorsFromTop,
      ).hasSize(nodesBetweenLcaAndTwo.size + 1)
      assertThat(
        payloadTwo.expectedAntlrRuleType,
      ).isEqualTo(nodesBetweenLcaAndTwo.first().expectedAntlrRuleType)
      assertThat(
        payloadTwo.actualAntlrRuleType,
      ).isEqualTo(typeTwo.expectedAntlrRuleType)

      payloadTwo.collapsedAncestorsFromTop.zip(nodesBetweenLcaAndTwo).forEach {
        assertThat(it.first.expectedAntlrRuleType).isEqualTo(it.second.expectedAntlrRuleType)
      }
    }
    run {
      val payloadPlus = plus.payload as CollapsingPayload
      assertThat(
        payloadPlus.collapsedAncestorsFromTop,
      ).hasSize(nodesBetweenLcaAndPlus.size + 1)
      assertThat(
        payloadPlus.expectedAntlrRuleType,
      ).isEquivalentAccordingToCompareTo(nodesBetweenLcaAndPlus.first().expectedAntlrRuleType)
      assertThat(
        payloadPlus.actualAntlrRuleType,
      ).isEquivalentAccordingToCompareTo(typePlus.expectedAntlrRuleType)

      payloadPlus.collapsedAncestorsFromTop.zip(nodesBetweenLcaAndPlus).forEach {
        assertThat(it.first.expectedAntlrRuleType).isEqualTo(it.second.expectedAntlrRuleType)
      }
    }
  }

  private fun getNodesBetween(
    ancestor: AbstractSparTreeNode,
    descendant: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode> {
    val result = ArrayList<AbstractSparTreeNode>()
    var current = descendant.parent!!
    while (current != ancestor) {
      result.add(current)
      current = current.parent!!
    }
    result.reverse()
    return result.toImmutableList()
  }
}
