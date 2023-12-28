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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ChildHoistingActionSet
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.NodeDeletionTreeEdit
import org.perses.spartree.NodeReplacementTreeEdit
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.Util.lazyAssert
import java.util.Queue

abstract class AbstractNodeReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  private val reductionQueueStrategy: IReductionQueueStrategy,
  protected val requiresParsableTree: Boolean,
) : AbstractTokenReducer(reducerAnnotation, reducerContext) {

  final override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    if (requiresParsableTree && !fixpointReductionState.sparTree.parsable) {
      val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
      listenerManager.onReductionSkipped(
        fixpointReductionState.fixpointIterationStartEvent.createReductionSkippedEvent(
          System.currentTimeMillis(),
          tree.tokenCount,
          tree = tree,
          message = "The spar-tree is not parsable.",
        ),
      )
      return
    }
    val tree = fixpointReductionState.sparTree.getParsableTreeOrFail()
    val root = tree.root
    lazyAssert { SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(root) }
    val queue = createReductionQueue()
    initializeReductionQueue(queue, tree)
    while (!queue.isEmpty()) {
      val node = queue.poll()
      val nodeReductionStartEvent =
        fixpointReductionState.fixpointIterationStartEvent.createNodeReductionStartEvent(
          System.currentTimeMillis(),
          program = tree.programSnapshot,
          node = node,
        )
      listenerManager.onNodeReductionStart(nodeReductionStartEvent)
      val pendingNodes = reduceOneNode(tree, node)
      listenerManager.onNodeReductionEnd(
        nodeReductionStartEvent.createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          remainingQueueSize = queue.size,
          program = tree.programSnapshot,
        ),
      )
      queue.addAll(pendingNodes)
    }
  }

  protected open fun initializeReductionQueue(queue: Queue<AbstractSparTreeNode>, tree: SparTree) {
    queue.addAll(tree.root.immutableChildView)
  }

  private fun createReductionQueue() = reductionQueueStrategy.createQueue()

  protected abstract fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
  ): ImmutableList<AbstractSparTreeNode>

  protected fun testSparTreeEdit(edit: AbstractSparTreeEdit<*>) =
    testAllTreeEditsAndReturnTheBest(ImmutableList.of(edit))

  protected fun optionallyCreateDeletionEditAndLog(
    actionSet: NodeDeletionActionSet,
    tree: SparTree,
  ): NodeDeletionTreeEdit? {
    return if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
      null
    } else {
      tree.createNodeDeletionEdit(actionSet)
    }
  }

  protected fun optionallyCreateReplacementEditAndLog(
    actionSet: ChildHoistingActionSet,
    tree: SparTree,
  ): NodeReplacementTreeEdit? {
    return if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet)
      null
    } else {
      tree.createNodeReplacementEdit(actionSet)
    }
  }

  protected fun computePendingNodes(
    currentNode: AbstractSparTreeNode,
    bestEdit: AbstractSparTreeEdit<*>,
  ): ImmutableList<AbstractSparTreeNode> {
    if (!currentNode.isPermanentlyDeleted) { // Children are changed, so work on the children later.
      return ImmutableList.copyOf(currentNode.immutableChildView)
    }
    return if (bestEdit is NodeDeletionTreeEdit) {
      val nodeDeletionTreeEdit = bestEdit.asNodeDeleteEdit()
      lazyAssert { nodeDeletionTreeEdit.isNodeATarget(currentNode) }
      lazyAssert { nodeDeletionTreeEdit.numberOfActions == 1 }
      ImmutableList.of()
    } else if (bestEdit is NodeReplacementTreeEdit) {
      val nodeReplacementTreeEdit = bestEdit.asNodeReplacementEdit()
      if (nodeReplacementTreeEdit.isNodeATarget(currentNode)) {
        lazyAssert { nodeReplacementTreeEdit.numberOfActions == 1 }
        val onlyReplacementNode = nodeReplacementTreeEdit.onlyReplacementNode
        lazyAssert({ !onlyReplacementNode.isPermanentlyDeleted }) {
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
    const val DEFAULT_INITIAL_QUEUE_CAPACITY = 600
  }

  object TreeNodeComparatorInLeafTokenCount : Comparator<AbstractSparTreeNode> {
    private val comparator = compareByDescending<AbstractSparTreeNode> { it.leafTokenCount }
      .thenByDescending { it.nodeId }

    override fun compare(o1: AbstractSparTreeNode, o2: AbstractSparTreeNode): Int {
      val result = comparator.compare(o1, o2)
      lazyAssert({ result != 0 }) { "Cannot guarantee determinism." }
      return result
    }
  }

  fun interface IReductionQueueStrategy {
    fun createQueue(): Queue<AbstractSparTreeNode>

    companion object {
      val FOR_REGULAR_QUEUE = IReductionQueueStrategy {
        java.util.ArrayDeque(DEFAULT_INITIAL_QUEUE_CAPACITY)
      }
      val FOR_PRIORITY_QUEUE = IReductionQueueStrategy {
        java.util.PriorityQueue(
          DEFAULT_INITIAL_QUEUE_CAPACITY,
          TreeNodeComparatorInLeafTokenCount,
        )
      }
    }
  }
}
