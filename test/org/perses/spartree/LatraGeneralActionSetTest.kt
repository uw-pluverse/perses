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
import org.junit.Assert
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createSparTreeFromFile
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import java.nio.file.Paths
import java.util.stream.Collectors

@RunWith(JUnit4::class)
class LatraGeneralActionSetTest {
  private var tree = createSparTreeFromFile(Paths.get("test_data/parentheses/t.c"))
  private var nodePrintf = tree.getTokenNodeForText("printf")[0]
  private var nodeSemicol = tree.getTokenNodeForText(";")[0].recursiveDeepCopy(ReuseNodeIdStrategy)
  private var nodeInt = tree.getTokenNodeForText("int")[0]
  private var nodeMain = tree.getTokenNodeForText("main")[0].recursiveDeepCopy(ReuseNodeIdStrategy)
  private lateinit var actionSet: LatraGeneralActionSet
  private lateinit var actionSet2: LatraGeneralActionSet
  private lateinit var actionSet3: LatraGeneralActionSet

  @Before
  fun setup() {
    run {
      val builder = LatraGeneralActionSet.Builder("test 1")
      builder.replaceNode(nodePrintf, nodeSemicol)
      builder.replaceNode(nodeInt, nodeMain)
      builder.deleteNode(nodeMain)
      actionSet = builder.build()!!
      assertThat(actionSet.actionsDescription).isEqualTo("test 1")
    }
    run {
      val builder = LatraGeneralActionSet.Builder("test 2")
      builder.replaceNode(nodePrintf, nodeSemicol)
      builder.replaceNode(nodeInt, nodeMain)
      builder.deleteNode(nodeMain)
      actionSet2 = builder.build()!!
      assertThat(actionSet2.actionsDescription).isEqualTo("test 2")
    }

    run {
      val builder = LatraGeneralActionSet.Builder("test 3")
      builder.replaceNode(nodePrintf, nodeSemicol)
      builder.replaceNode(nodeInt, nodeMain)
      actionSet3 = builder.build()!!
      assertThat(actionSet3.actionsDescription).isEqualTo("test 3")
    }
  }

  @Test
  fun testContainsNodeAsTarget() {
    assertThat(actionSet.containsNodeAsTarget(nodePrintf)).isTrue()
    assertThat(actionSet.containsNodeAsTarget(nodeInt)).isTrue()
    assertThat(actionSet.containsNodeAsTarget(nodeMain)).isTrue()
    assertThat(actionSet.containsNodeAsTarget(nodeSemicol)).isFalse()
  }

  @Test
  fun testActionsAreSortedAndDistinct() {
    assertThat(
      actionSet.actions.stream()
        .map { it.targetNode }
        .collect(Collectors.toList()),
    )
      .containsExactly(nodePrintf, nodeInt, nodeMain)
      .inOrder()
    assertThat(
      actionSet2.actions.stream()
        .map { it.targetNode }
        .collect(Collectors.toList()),
    )
      .containsExactly(nodePrintf, nodeInt, nodeMain)
      .inOrder()
  }

  @Test
  fun testActionSetEqualsAndHashcode() {
    assertThat(actionSet.actions).hasSize(3)
    assertThat(actionSet.actions[0]).isEqualTo(actionSet2.actions[0])
    assertThat(actionSet.actions[1]).isEqualTo(actionSet2.actions[1])
    assertThat(actionSet.actions[2]).isEqualTo(actionSet2.actions[2])
    assertThat(actionSet.equals(actionSet2)).isTrue()
    assertThat(actionSet.hashCode()).isEqualTo(actionSet2.hashCode())
    val set = HashSet<LatraGeneralActionSet?>()
    set.add(actionSet)
    assertThat(set).containsExactly(actionSet2)
  }

  @Test
  fun testActionSetNotEqual() {
    assertThat(actionSet).isNotEqualTo(actionSet3)
    assertThat(actionSet.hashCode()).isNotEqualTo(actionSet3.hashCode())
    assertThat(actionSet3.actionsDescription).isEqualTo("test 3")
  }

  @Test
  fun testReplaceNode() {
    // replace deleted node, expect to fail
    val builder1 = LatraGeneralActionSet.Builder("test 4")
    builder1.deleteNode(nodePrintf)
    Assert.assertThrows(Exception::class.java) {
      builder1.replaceNode(nodePrintf, nodeSemicol)
    }

    val builder2 = LatraGeneralActionSet.Builder("test 5")
    builder2.deleteNode(
      AbstractTreeNode.findLowestAncestor(nodePrintf, tree.getTokenNodeForText(";")[0]).parent!!,
    )
    Assert.assertThrows(Exception::class.java) {
      builder2.replaceNode(nodePrintf, nodeSemicol)
    }

    // replace not deleted node, expect to pass
    val builder3 = LatraGeneralActionSet.Builder("test 6")
    builder3.deleteNode(nodePrintf)
    builder3.replaceNode(nodeInt, nodeMain)
    assertThat(
      builder3.build()!!.actions.stream()
        .map { it.targetNode }
        .collect(Collectors.toList()),
    )
      .containsExactly(nodePrintf, nodeInt)
      .inOrder()
  }
}
