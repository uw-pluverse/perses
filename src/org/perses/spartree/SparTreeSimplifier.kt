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

import org.perses.util.SimpleStack
import org.perses.util.Util.lazyAssert

/**
 * A utility class to simplify a spar-tree, e.g., removing empty rule node path, shrink
 * single-entry-single-exit path
 */
object SparTreeSimplifier {

  fun simplify(tree: SparTree) {
    simplify(tree.root)
  }

  fun simplify(root: AbstractSparTreeNode): AbstractSparTreeNode {
    removeEmptyAndDeletedRuleNodes(root)
    simplifySingleEntrySingleExitPath(root)
    return root
  }

  /** Remove empty rule nodes and deleted sub-trees from the given tree.  */
  fun removeEmptyAndDeletedRuleNodes(root: AbstractSparTreeNode) {
    root.postOrderVisit { node: AbstractSparTreeNode ->
      if (node.isPermanentlyDeleted || node.isTokenNode) {
        return@postOrderVisit
      }
      node.cleanDeletedImmediateChildren()
      if (node.childCount == 0) {
        node.delete()
      }
    }
  }

  @JvmStatic
  fun simplifySingleEntrySingleExitPath(tree: SparTree) {
    simplifySingleEntrySingleExitPath(tree.root)
  }

  /**
   * For a single-entry-single-exit path in a spar-tree, we do the following.
   *  * Keep all meta-nodes, (Kleene Star, Kleene Plus, Optional)
   *  * Keep the end node of the path (i.e., the fork node with in-degree=1 and out-degree>1
   *  * Delete all the rest nodes.
   *
   *
   * The simplification is performed in the tree.
   */
  fun simplifySingleEntrySingleExitPath(root: AbstractSparTreeNode) {
    val worklist = SimpleStack<AbstractSparTreeNode>()
    // We always keep the root, so push the immediate children to the stack.
    root.forEachChild { worklist.add(it) }
    while (!worklist.isEmpty()) {
      var current = worklist.remove()
      if (!isSESENode(current)) {
        current.forEachChild { worklist.add(it) }
        continue
      }

      lazyAssert { current.childCount == 1 && !current.isQuantifierNode }
      val parent = current.parent!!
      // Collapsing the SESE path.
      do {
        lazyAssert { isSESENode(current) }
        val childOfCurrent = current.getChild(0)
        val payload = current.payload!!.createByAppending(
          childOfCurrent.payload!!,
        )
        childOfCurrent.resetParent()
        childOfCurrent.resetPayload()
        parent.replaceChild(current, childOfCurrent, payload)
        current = childOfCurrent
      } while (isSESENode(current))
      worklist.add(current) // The child becomes the frontier.
    }
    lazyAssert({ assertSingleEntrySingleExitPathProperty(root) }) { root.printTreeStructure() }
  }

  private fun isSESENode(node: AbstractSparTreeNode): Boolean {
    check(!node.isPermanentlyDeleted)
    return when {
      node.isQuantifierNode -> false // Accept meta-node
      node.childCount > 1 -> false // a fork node, the end of an SESE path
      node.childCount == 0 -> {
        // A token node, the end of an SESE path.
        check(node.isTokenNode) { node }
        false
      }
      node.childCount == 1 -> true
      else -> error("not reachable")
    }
  }

  fun assertSingleEntrySingleExitPathProperty(
    root: AbstractSparTreeNode,
  ): Boolean {
    root.forEachChild { immediateChild: AbstractSparTreeNode ->
      immediateChild.preOrderVisit { node: AbstractSparTreeNode ->
        val result = node.immutableChildView
        if (node.isQuantifierNode) {
          return@preOrderVisit result
        }
        if (node.childCount == 0) {
          check(node.isTokenNode)
        }
        check(node.childCount != 1) {
          "count=${node.childCount}, node=$node, " +
            "immediateChild: ${immediateChild.printTreeStructure()}"
        }
        result
      }
    }
    return true
  }

  fun assertAllChildrenAreDeleted(node: AbstractSparTreeNode): Boolean {
    require(node.isPermanentlyDeleted)
    node.preOrderVisit { child: AbstractSparTreeNode ->
      check(child.isPermanentlyDeleted)
      child.immutableChildView
    }
    return true
  }
}
