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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.DescendantHoistingTreeEdit
import org.perses.spartree.LatraGeneralTreeEdit
import org.perses.spartree.NodeDeletionTreeEdit
import org.perses.spartree.NodeReplacementAction
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.Util.lazyAssert
import java.util.Queue

abstract class AbstractNodeReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  private val reductionQueueStrategy: IReductionQueueStrategy,
) : AbstractSparTreeReducer(reducerAnnotation, reducerContext) {
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val listenerManager = reducerContext.listenerManager
    val tree = fixpointReductionState.inputRepresentation.tree
    listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        "Starting to retrieve the semantics provider"
      },
    )
    val semanticsProvider = fixpointReductionState.inputRepresentation.semantics
    // The previous and following messages are for timing the creation of semantic provider.
    // The spent time can be calculated by looking at the timestamps of the log messages.
    listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        "Retrieved semantics provider $semanticsProvider"
      },
    )
    val root = tree.realRoot
    lazyAssert({ SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(root) }) {
      """The spar-tree was successfully simplified. 
        |
        |${tree.printTreeStructure()}
        |
      """.trimMargin()
    }
    if (persesConfig.enableTopDownReduction) {
      reduceFromRootToLeaves(
        fixpointReductionState,
        tree,
        listenerManager,
        semanticsProvider,
      )
    }
  }

  private fun reduceFromRootToLeaves(
    fixpointReductionState: FixpointReductionState,
    tree: SparTree,
    listenerManager: AsyncReductionListenerManager,
    semanticsProvider: ISemanticsProvider?,
  ) {
    val queue = createReductionQueue()
    initializeReductionQueue(queue, tree)
    while (!queue.isEmpty()) {
      val node = queue.poll()
      val pendingNodes =
        reduceOneNodeWithBoilerplateAndGetPendingNodes(
          fixpointReductionState,
          tree,
          node,
          listenerManager,
          semanticsProvider,
          queueSize = queue.size,
        )
      pendingNodes
        .onSuccess { pendingNodes ->
          queue.addAll(pendingNodes)
        }.onFailure {
          if (it is Exception) {
            listenerManager.onCriticalException(it)
          } else {
            throw it
          }
        }
    }
  }

  protected fun reduceOneNodeWithBoilerplateAndGetPendingNodes(
    fixpointReductionState: FixpointReductionState,
    tree: SparTree,
    node: AbstractSparTreeNode,
    listenerManager: AsyncReductionListenerManager,
    semanticsProvider: ISemanticsProvider?,
    queueSize: Int,
  ): Result<List<AbstractSparTreeNode>> {
    val nodeReductionStartEvent =
      fixpointReductionState.fixpointIterationStartEvent.createNodeReductionStartEvent(
        currentTimeMillis = System.currentTimeMillis(),
        perFileSizeMetrics = fixpointReductionState.inputRepresentation.computePerFileSizeMetrics(),
        program = tree.programSnapshot,
        node = node,
        outputCreator = createOutputCreator(),
      )
    listenerManager.onNodeReductionStart(nodeReductionStartEvent)
    val pendingNodes =
      runCatching {
        reduceOneNode(tree, node, semanticsProvider = semanticsProvider, fixpointReductionState)
      }.onFailure { listenerManager.onCriticalException(it as Exception) }
    listenerManager.onNodeReductionEnd(
      nodeReductionStartEvent.createEndEvent(
        currentTimeMillis = System.currentTimeMillis(),
        remainingQueueSize = queueSize,
        perFileSizeMetrics = fixpointReductionState.inputRepresentation.computePerFileSizeMetrics(),
      ),
    )
    return pendingNodes
  }

  protected open fun initializeReductionQueue(
    queue: Queue<AbstractSparTreeNode>,
    tree: SparTree,
  ) {
    queue.addAll(tree.realRoot.immutableChildView)
  }

  private fun createReductionQueue() = reductionQueueStrategy.createQueue()

  protected abstract fun reduceOneNode(
    tree: SparTree,
    node: AbstractSparTreeNode,
    semanticsProvider: ISemanticsProvider?,
    fixpointReductionState: FixpointReductionState,
  ): List<AbstractSparTreeNode>

  protected fun computePendingNodes(
    nodeBeingReduced: AbstractSparTreeNode,
    successfulEdit: AbstractSparTreeEdit<*>,
  ): ImmutableList<AbstractSparTreeNode> {
    if (!nodeBeingReduced.isPermanentlyDeleted) {
      // Children are changed, so work on the children later.
      return ImmutableList.copyOf(nodeBeingReduced.immutableChildView)
    }
    return when (successfulEdit) {
      is NodeDeletionTreeEdit -> {
        val nodeDeletionTreeEdit = successfulEdit.asNodeDeleteEdit()
        lazyAssert { nodeDeletionTreeEdit.isNodeATarget(nodeBeingReduced) }
        lazyAssert { nodeDeletionTreeEdit.numberOfActions == 1 }
        ImmutableList.of()
      }

      is DescendantHoistingTreeEdit -> {
        val nodeReplacementTreeEdit = successfulEdit.asNodeReplacementEdit()
        if (nodeReplacementTreeEdit.isNodeATarget(nodeBeingReduced)) {
          lazyAssert { nodeReplacementTreeEdit.numberOfActions == 1 }
          val onlyReplacementNode = nodeReplacementTreeEdit.onlyReplacementNode
          lazyAssert({ !onlyReplacementNode.isPermanentlyDeleted }) {
            onlyReplacementNode.printTreeStructure()
          }
          ImmutableList.of(onlyReplacementNode)
        } else {
          ImmutableList.copyOf(nodeBeingReduced.immutableChildView)
        }
      }

      is LatraGeneralTreeEdit -> {
        val latraEdit = successfulEdit.asLatraGeneralEdit()
        val actions = latraEdit.actionSet.actions
        check(actions.size == 1) { actions }
        val action = actions.single()
        check(action is NodeReplacementAction) { action }
        check(action.targetNode === nodeBeingReduced)
        ImmutableList.of(action.replacingNode)
      }

      else -> error("Unhandled edit type: ${successfulEdit::class}")
    }
  }

  companion object {
    const val DEFAULT_INITIAL_QUEUE_CAPACITY = 600
  }

  fun interface IReductionQueueStrategy {
    fun createQueue(): Queue<AbstractSparTreeNode>

    companion object {
      val FOR_REGULAR_QUEUE =
        IReductionQueueStrategy {
          java.util.ArrayDeque(DEFAULT_INITIAL_QUEUE_CAPACITY)
        }
      val FOR_PRIORITY_QUEUE =
        IReductionQueueStrategy {
          java.util.PriorityQueue(
            DEFAULT_INITIAL_QUEUE_CAPACITY,
            compareByDescending<AbstractSparTreeNode> { it.leafTokenCount }
              .thenByDescending { it.nodeId },
          )
        }
    }
  }
}
