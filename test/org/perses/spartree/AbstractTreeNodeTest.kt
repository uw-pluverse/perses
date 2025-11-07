/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
  class Node(
    nodeId: Int,
  ) : AbstractTreeNode<Node, String>(nodeId) {
    fun addChild(node: Node) {
      addChild(node, createPayloadForNewChild())
    }

    private fun createPayloadForNewChild(): String = nodeId.toString()

    override fun checkNodeIntegrity(): ErrorMessage? = null

    override fun onChildRemoved(
      index: Int,
      child: Node,
    ) {
    }

    override fun internalCopyCurrentNode(computedNewNodeId: Int): Node = Node(computedNewNodeId)
  }

  val root = Node(0)

  val l1N1Root = Node(1).apply { root.addChild(this) }
  val l1N2Root = Node(2).apply { root.addChild(this) }
  val l1N3Root = Node(3).apply { root.addChild(this) }

  val l2N4N1 = Node(4).apply { l1N1Root.addChild(this) }
  val l2N5N1 = Node(5).apply { l1N1Root.addChild(this) }

  val l2N6N2 = Node(6).apply { l1N2Root.addChild(this) }
  val l2N7N2 = Node(7).apply { l1N2Root.addChild(this) }

  val l2N8N3 = Node(8).apply { l1N3Root.addChild(this) }
  val l2N9N3 = Node(9).apply { l1N3Root.addChild(this) }

  val l3N10N9 = Node(10).apply { l2N9N3.addChild(this) }
  val l3N11N9 = Node(11).apply { l2N9N3.addChild(this) }

  @Test
  fun testDeepCopy() {
    val node = l3N11N9
    val copy = node.recursiveDeepCopy(ReuseNodeIdStrategy).result
    assertThat(copy).isNotSameInstanceAs(node)
    assertThat(node.nodeId).isEqualTo(copy.nodeId)
  }

  @Test
  fun test_boundedBreadthFirstSearchForFirstQualifiedNodes_max_depth_1() {
    val result =
      root
        .boundedBreadthFirstSearchForFirstQualifiedNodes(
          { true },
          1,
        ).toList()
    assertThat(result)
      .containsExactly(
        l1N1Root,
        l1N2Root,
        l1N3Root,
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
    val result =
      root
        .boundedBreadthFirstSearchForFirstQualifiedNodes(
          { it !== l1N1Root && it !== l1N2Root && it !== l1N3Root },
          2,
        ).toList()
    assertThat(result)
      .containsExactly(
        l2N4N1,
        l2N5N1,
        l2N6N2,
        l2N7N2,
        l2N8N3,
        l2N9N3,
      ).inOrder()
  }

  @Test
  fun test_nodeId() {
    assertThat(l1N1Root.nodeId).isEqualTo(1)
    assertThat(l3N11N9.nodeId).isEqualTo(11)
  }

  @Test
  fun test_getChildCount() {
    assertThat(l1N1Root.childCount).isEqualTo(2)
    assertThat(l3N11N9.childCount).isEqualTo(0)
  }

  @Test
  fun test_compare() {
    assertThat(l1N1Root.compareTo(l1N1Root)).isEqualTo(0)
    assertThat(l1N1Root.compareTo(l2N4N1)).isEqualTo(-1)
    assertThat(l2N4N1.compareTo(l1N1Root)).isEqualTo(1)
  }

  @Test
  fun test_preOrderVisit() {
    val list = ArrayList<Node>()
    root.preOrderVisit { node ->
      list.add(node)
      node.immutableChildView
    }
    assertThat(list)
      .containsExactly(
        root,
        l1N1Root,
        l2N4N1,
        l2N5N1,
        l1N2Root,
        l2N6N2,
        l2N7N2,
        l1N3Root,
        l2N8N3,
        l2N9N3,
        l3N10N9,
        l3N11N9,
      ).inOrder()
  }

  @Test
  fun test_postOrderVisit() {
    val list = ArrayList<Node>()
    root.postOrderVisit { node ->
      list.add(node)
    }
    assertThat(list)
      .containsExactly(
        l2N4N1,
        l2N5N1,
        l1N1Root,
        l2N6N2,
        l2N7N2,
        l1N2Root,
        l2N8N3,
        l3N10N9,
        l3N11N9,
        l2N9N3,
        l1N3Root,
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
    assertThat(list)
      .containsExactly(
        l1N1Root,
        l1N2Root,
        l1N3Root,
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
    assertThat(l1N1Root.parent!!).isSameInstanceAs(root)
    assertThat(l1N1Root.payload!!).isEqualTo(root.nodeId.toString())

    assertThat(l2N4N1.parent!!).isSameInstanceAs(l1N1Root)
  }

  @Test
  fun test_find_lowest_ancestor() {
    val immutableList1: ImmutableList<Node> = ImmutableList.of(l2N4N1, l2N5N1)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList1)).isSameInstanceAs(l1N1Root)

    val immutableList2: ImmutableList<Node> =
      ImmutableList.of(
        l2N4N1,
        l2N5N1,
        l2N6N2,
        l3N10N9,
        l2N8N3,
      )
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList2)).isSameInstanceAs(root)

    val immutableList3: ImmutableList<Node> = ImmutableList.of(l3N10N9, l2N8N3)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList3)).isSameInstanceAs(l1N3Root)

    val immutableList4: ImmutableList<Node> = ImmutableList.of(l2N4N1)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList4)).isSameInstanceAs(l2N4N1)

    val immutableList5: ImmutableList<Node> = ImmutableList.of(l2N4N1, l2N4N1)
    assertThat(AbstractTreeNode.findLowestAncestor(immutableList5)).isSameInstanceAs(l2N4N1)

    val immutableList6: ImmutableList<Node> = ImmutableList.of()
    Assert.assertThrows(Exception::class.java) {
      AbstractTreeNode.findLowestAncestor(immutableList6)
    }
  }

  @Test
  fun test_find_lowest_ancestor_pair() {
    assertThat(AbstractTreeNode.findLowestAncestorPair(l2N4N1, l2N4N1)).isSameInstanceAs(
      l2N4N1,
    )
    assertThat(AbstractTreeNode.findLowestAncestorPair(l2N4N1, l2N5N1)).isSameInstanceAs(
      l1N1Root,
    )
  }

  @Test
  fun test_replace_child() {
    val newNode1 = Node(13)
    Node(15).apply { newNode1.addChild(this) }
    l1N1Root.replaceChild(l2N4N1, newNode1, l2N4N1.payload!!)
    assertThat(l1N1Root.getChild(0)).isSameInstanceAs(newNode1)
    assertThat(newNode1.childCount == 1)

    val newNode2 = Node(14)
    Assert.assertThrows(Throwable::class.java) {
      l1N1Root.replaceChild(l2N4N1, newNode2, l2N4N1.payload!!)
    }
  }

  @Test
  fun test_remove_child() {
    l1N1Root.removeChild(l2N4N1)
    assertThat(l1N1Root.childCount).isEqualTo(1)
    assertThat(l1N1Root.getChild(0)).isSameInstanceAs(l2N5N1)

    Assert.assertThrows(Exception::class.java) {
      l1N1Root.removeChild(root)
    }
  }

  @Test
  fun test_addChildBeforeExistingChild() {
    val newChild = Node(100)
    l2N9N3.addChildBeforeExistingChild(l3N11N9, newChild, l3N11N9.payload!!)

    assertThat(l2N9N3.childCount).isEqualTo(3)
    assertThat(l2N9N3.getChild(0)).isSameInstanceAs(l3N10N9)
    assertThat(l2N9N3.getChild(1)).isSameInstanceAs(newChild)
    assertThat(l2N9N3.getChild(2)).isSameInstanceAs(l3N11N9)
  }

  @Test
  fun test_addChildAfterExistingChild_existingTree() {
    val newChild = Node(101)
    l1N2Root.addChildAfterExistingChild(l2N6N2, newChild, "payload")

    assertThat(l1N2Root.childCount).isEqualTo(3)
    assertThat(l1N2Root.getChild(0)).isSameInstanceAs(l2N6N2)
    assertThat(l1N2Root.getChild(1)).isSameInstanceAs(newChild)
    assertThat(l1N2Root.getChild(2)).isSameInstanceAs(l2N7N2)
  }
}
