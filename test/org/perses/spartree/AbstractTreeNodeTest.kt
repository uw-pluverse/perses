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
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy

@RunWith(JUnit4::class)
class AbstractTreeNodeTest {

  class Node(nodeId: Int) : AbstractTreeNode<Node, String>(nodeId) {

    fun addChild(node: Node) {
      addChild(node, createPayloadForNewChild())
    }

    private fun createPayloadForNewChild(): String {
      return nodeId.toString()
    }

    override fun checkNodeIntegrity(): ErrorMessage? {
      return null
    }

    override fun onChildRemoved(index: Int, child: Node) {
    }

    override fun internalCopyCurrentNode(computedNewNodeId: Int): Node {
      return Node(computedNewNodeId)
    }
  }

  val root = Node(0)

  val l1_n1_root = Node(1).apply { root.addChild(this) }
  val l1_n2_root = Node(2).apply { root.addChild(this) }
  val l1_n3_root = Node(3).apply { root.addChild(this) }

  val l2_n4_n1 = Node(4).apply { l1_n1_root.addChild(this) }
  val l2_n5_n1 = Node(5).apply { l1_n1_root.addChild(this) }

  val l2_n6_n2 = Node(6).apply { l1_n2_root.addChild(this) }
  val l2_n7_n2 = Node(7).apply { l1_n2_root.addChild(this) }

  val l2_n8_n3 = Node(8).apply { l1_n3_root.addChild(this) }
  val l2_n9_n3 = Node(9).apply { l1_n3_root.addChild(this) }

  val l3_n10_n9 = Node(10).apply { l2_n9_n3.addChild(this) }
  val l3_n11_n9 = Node(11).apply { l2_n9_n3.addChild(this) }

  @Test
  fun testDeepCopy() {
    val node = l3_n11_n9
    val copy = node.recursiveDeepCopy(ReuseNodeIdStrategy)
    assertThat(copy).isNotSameInstanceAs(node)
    assertThat(node.nodeId).isEqualTo(copy.nodeId)
  }

  @Test
  fun test_boundedBreadthFirstSearchForFirstQualifiedNodes_max_depth_1() {
    val result = root.boundedBreadthFirstSearchForFirstQualifiedNodes(
      { true },
      1,
    ).toList()
    assertThat(result).containsExactly(
      l1_n1_root,
      l1_n2_root,
      l1_n3_root,
    ).inOrder()
  }

  @Test
  fun test_immutable_children_view() {
    val node = Node(1)
    val view = node.immutableChildView
    assertThat(view).isEmpty()
    val child = Node(2)
    node.addChild(child)
    assertThat(view).containsExactly(child).inOrder()
  }

  @Test
  fun test_boundedBreadthFirstSearchForFirstQualifiedNodes_max_depth_2() {
    val result = root.boundedBreadthFirstSearchForFirstQualifiedNodes(
      { it !== l1_n1_root && it !== l1_n2_root && it !== l1_n3_root },
      2,
    ).toList()
    assertThat(result).containsExactly(
      l2_n4_n1,
      l2_n5_n1,
      l2_n6_n2,
      l2_n7_n2,
      l2_n8_n3,
      l2_n9_n3,
    ).inOrder()
  }

  @Test
  fun test_nodeId() {
    assertThat(l1_n1_root.nodeId).isEqualTo(1)
    assertThat(l3_n11_n9.nodeId).isEqualTo(11)
  }

  @Test
  fun test_getChildCount() {
    assertThat(l1_n1_root.childCount).isEqualTo(2)
    assertThat(l3_n11_n9.childCount).isEqualTo(0)
  }

  @Test
  fun test_compare() {
    assertThat(l1_n1_root.compareTo(l1_n1_root)).isEqualTo(0)
    assertThat(l1_n1_root.compareTo(l2_n4_n1)).isEqualTo(-1)
    assertThat(l2_n4_n1.compareTo(l1_n1_root)).isEqualTo(1)
  }

  @Test
  fun test_preOrderVisit() {
    val list = ArrayList<Node>()
    root.preOrderVisit { node ->
      list.add(node)
      node.immutableChildView
    }
    assertThat(list).containsExactly(
      root,
      l1_n1_root,
      l2_n4_n1,
      l2_n5_n1,
      l1_n2_root,
      l2_n6_n2,
      l2_n7_n2,
      l1_n3_root,
      l2_n8_n3,
      l2_n9_n3,
      l3_n10_n9,
      l3_n11_n9,
    ).inOrder()
  }

  @Test
  fun test_postOrderVisit() {
    val list = ArrayList<Node>()
    root.postOrderVisit { node ->
      list.add(node)
    }
    assertThat(list).containsExactly(
      l2_n4_n1,
      l2_n5_n1,
      l1_n1_root,
      l2_n6_n2,
      l2_n7_n2,
      l1_n2_root,
      l2_n8_n3,
      l3_n10_n9,
      l3_n11_n9,
      l2_n9_n3,
      l1_n3_root,
      root,
    ).inOrder()
  }

  @Test
  fun testPostOrderVisitWithSuccessorFunction() {
    val list = mutableListOf<Node>()
    root.postOrderVisit({
      if (it === root) {
        root.immutableChildView
      } else {
        emptyList()
      }
    }) {
      list.add(it)
    }
    assertThat(list).containsExactly(
      l1_n1_root,
      l1_n2_root,
      l1_n3_root,
      root,
    ).inOrder()
  }

  @Test
  fun test_delete_root() {
    assertThat(root.isPermanentlyDeleted).isFalse()
    root.delete()
    assertThat(root.isPermanentlyDeleted).isTrue()
  }

  @Test
  fun test_delete_child() {
    root.forEachChild {
      assertThat(it.isPermanentlyDeleted).isFalse()
    }
    root.forEachChild {
      it.delete()
    }
    root.forEachChild {
      assertThat(it.isPermanentlyDeleted).isTrue()
      assertThat(it.childCount).isEqualTo(0)
    }
    // The method `delete()` does not remove the node from its parent.
    assertThat(root.childCount).isEqualTo(3)
  }

  @Test
  fun test_parent_of_root() {
    assertThat(root.parent).isNull()
  }

  @Test
  fun test_parent_of_node() {
    assertThat(l1_n1_root.parent!!).isSameInstanceAs(root)
    assertThat(l1_n1_root.payload!!).isEqualTo(root.nodeId.toString())

    assertThat(l2_n4_n1.parent!!).isSameInstanceAs(l1_n1_root)
  }

  @Test
  fun test_find_lowest_ancestor() {
    val immutableList1: ImmutableList<Node> = ImmutableList.of(l2_n4_n1, l2_n5_n1)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList1)).isSameInstanceAs(l1_n1_root)

    val immutableList2: ImmutableList<Node> = ImmutableList.of(
      l2_n4_n1,
      l2_n5_n1,
      l2_n6_n2,
      l3_n10_n9,
      l2_n8_n3,
    )
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList2)).isSameInstanceAs(root)

    val immutableList3: ImmutableList<Node> = ImmutableList.of(l3_n10_n9, l2_n8_n3)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList3)).isSameInstanceAs(l1_n3_root)

    val immutableList4: ImmutableList<Node> = ImmutableList.of(l2_n4_n1)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList4)).isSameInstanceAs(l2_n4_n1)

    val immutableList5: ImmutableList<Node> = ImmutableList.of(l2_n4_n1, l2_n4_n1)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList5)).isSameInstanceAs(l2_n4_n1)

    val immutableList6: ImmutableList<Node> = ImmutableList.of()
    Assert.assertThrows(Exception::class.java) {
      AbstractTreeNode.findLowestAncestor(immutableList6)
    }
  }

  @Test
  fun test_find_lowest_ancestor_pair() {
    assertThat(AbstractTreeNode.findLowestAncestorPair(l2_n4_n1, l2_n4_n1)).isSameInstanceAs(
      l2_n4_n1,
    )
    assertThat(AbstractTreeNode.findLowestAncestorPair(l2_n4_n1, l2_n5_n1)).isSameInstanceAs(
      l1_n1_root,
    )
  }

  @Test
  fun test_replace_child() {
    val newNode1 = Node(13)
    Node(15).apply { newNode1.addChild(this) }
    l1_n1_root.replaceChild(l2_n4_n1, newNode1, l2_n4_n1.payload!!)
    assertThat(l1_n1_root.getChild(0)).isSameInstanceAs(newNode1)
    assertThat(newNode1.childCount == 1)

    val newNode2 = Node(14)
    Assert.assertThrows(Throwable::class.java) {
      l1_n1_root.replaceChild(l2_n4_n1, newNode2, l2_n4_n1.payload!!)
    }
  }

  @Test
  fun test_remove_child() {
    l1_n1_root.removeChild(l2_n4_n1)
    assertThat(l1_n1_root.childCount).isEqualTo(1)
    assertThat(l1_n1_root.getChild(0)).isSameInstanceAs(l2_n5_n1)

    Assert.assertThrows(Exception::class.java) {
      l1_n1_root.removeChild(root)
    }
  }
}
