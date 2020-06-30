/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TreeEditWithItsResult
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.ChildHoistingActionSet
import org.perses.tree.spar.NodeDeletionActionSet
import org.perses.tree.spar.NodeDeletionTreeEdit
import org.perses.tree.spar.NodeReplacementTreeEdit
import org.perses.tree.spar.SparTree
import org.perses.tree.spar.SparTreeSimplifier
import java.util.Optional
import java.util.Queue

abstract class AbstractNodeReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext
) : AbstractReducer(reducerAnnotation, reducerContext) {

  override fun internalReduce(tree: SparTree) {
    val root = tree.root
    assert(SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(root))
    val queue = createReductionQueue()
    queue.addAll(root.immutableChildView)
    while (!queue.isEmpty()) {
      val node = queue.poll()
      val oldTokenCount = tree.tokenCount
      listenerManager.onNodeReductionStart(tree, node, oldTokenCount)
      val pendingNodes = reduceOneNode(tree, node)
      val newTokenCount = tree.tokenCount
      listenerManager.onNodeReductionEnd(tree, node, queue.size, newTokenCount)
      queue.addAll(pendingNodes)
    }
  }

  protected abstract fun createReductionQueue(): Queue<AbstractSparTreeNode>

  protected abstract fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode
  ): ImmutableList<AbstractSparTreeNode>

  protected fun testSparTreeEdit(edit: AbstractSparTreeEdit): Optional<TreeEditWithItsResult> {
    return try {
      testAllTreeEditsAndReturnTheBest(ImmutableList.of(edit))
    } catch (e: Exception) {
      throw RuntimeException(e)
    }
  }

  protected fun addDeletionEditToEditListAndLog(
    actionSet: NodeDeletionActionSet,
    editList: MutableList<in AbstractSparTreeEdit>,
    tree: SparTree
  ) {
    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
    } else {
      editList.add(tree.createNodeDeletionEdit(actionSet))
    }
  }

  protected fun addEditToEditListAndLog(
    actionSet: ChildHoistingActionSet,
    editList: MutableList<in AbstractSparTreeEdit>,
    tree: SparTree
  ) {
    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
    } else {
      editList.add(tree.createNodeReplacementEdit(actionSet))
    }
  }

  protected fun computePendingNodes(
    currentNode: AbstractSparTreeNode,
    bestEdit: AbstractSparTreeEdit
  ): ImmutableList<AbstractSparTreeNode> {
    if (!currentNode.isPermanentlyDeleted) { // Children are changed, so work on the children later.
      return ImmutableList.copyOf(currentNode.immutableChildView)
    }
    return if (bestEdit is NodeDeletionTreeEdit) {
      val nodeDeletionTreeEdit = bestEdit.asNodeDeleteEdit()
      assert(nodeDeletionTreeEdit.isNodeATarget(currentNode))
      assert(nodeDeletionTreeEdit.numberOfActions == 1)
      ImmutableList.of()
    } else if (bestEdit is NodeReplacementTreeEdit) {
      val nodeReplacementTreeEdit = bestEdit.asNodeReplacementEdit()
      if (nodeReplacementTreeEdit.isNodeATarget(currentNode)) {
        assert(nodeReplacementTreeEdit.numberOfActions == 1)
        val onlyReplacementNode = nodeReplacementTreeEdit.onlyReplacementNode
        assert(!onlyReplacementNode.isPermanentlyDeleted) {
          onlyReplacementNode.printTreeStructure()
        }
        ImmutableList.of(onlyReplacementNode)
      } else {
        ImmutableList.copyOf(currentNode.immutableChildView)
      }
    } else {
      throw RuntimeException("Unreachable.")
    }
  }

  companion object {
    internal const val DEFAULT_INITIAL_QUEUE_CAPACITY = 600
  }
}
