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
package org.perses.reduction.reducer.hdd

import org.perses.delta.xfs.Partition
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.ReductionLevel
import org.perses.reduction.event.LevelReductionStartEvent
import org.perses.reduction.partition.AbstractLevelPartitionPolicy
import org.perses.reduction.partition.SimpleLevelPartitionPolicy
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeReplacementAction
import org.perses.spartree.SparTree
import org.perses.util.Util.lazyAssert
import java.io.IOException
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Paths
import java.nio.file.StandardOpenOption

/** The base class for reducers that perform level-based reduction.  */
abstract class AbstractLevelBasedReducer protected constructor(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractTokenReducer(reducerAnnotation, reducerContext) {

  private val partitionPolicy: AbstractLevelPartitionPolicy = SimpleLevelPartitionPolicy()

  protected fun getInitialRegion(tree: SparTree): ReductionLevel {
    val level = ReductionLevel(1)
    tree.root.forEachChild { level.addNode(it) }
    return level
  }

  /**
   * TODO: if a node and all its children are irreducible, then avoid adding it to the next level.
   *
   * @param tree
   * @param level
   * @return
   */
  protected fun moveToNextLevel(
    level: ReductionLevel,
  ): ReductionLevel {
    val nextLevel = ReductionLevel(level.level + 1)
    // FIXME: need to make sure that single path cannot contain more than two nodes.
    //        Otherwise this algorithm will be very slow.
    level.forEachNode { it.forEachChild { node -> nextLevel.addNode(node) } }
    return nextLevel
  }

  protected fun reduceOneLevel(
    tree: SparTree,
    level: ReductionLevel,
    levelStartEvent: LevelReductionStartEvent,
  ) {
    var maxNodesPerPartition = getInitialMaxNodesPerPartition(level)
    while (maxNodesPerPartition > 0) {
      partitionLevelAndReduce(tree, level, maxNodesPerPartition, levelStartEvent)
      if (maxNodesPerPartition == 1) {
        break
      }
      maxNodesPerPartition = (maxNodesPerPartition + 1) / 2
    }
  }

  protected fun getInitialMaxNodesPerPartition(level: ReductionLevel): Int {
    // Usually reducing the whole level does not help, so use halves.
    return (level.nodeCount + 1) / 2
  }

  /**
   * Create a set of tree edits, by deleting the ndoes in the partition, or deleteing some child
   * nodes.
   */
  protected abstract fun createTreeEditListByDisablingPartition(
    partition: Partition<AbstractSparTreeNode>,
    tree: SparTree,
  ): List<AbstractSparTreeEdit<*>>

  private fun partitionLevelAndReduce(
    tree: SparTree,
    reductionLevel: ReductionLevel,
    maxNodesPerPartition: Int,
    levelStartEvent: LevelReductionStartEvent,
  ) {
    lazyAssert { maxNodesPerPartition > 0 }
    val oldTokenCount = tree.tokenCount
    val granularityReductionStartEvent = levelStartEvent.createGranularityReductionStartEvent(
      System.currentTimeMillis(),
      maxNodesPerPartition,
      oldTokenCount,
    )
    listenerManager.onLevelGranularityReductionStart(granularityReductionStartEvent)
    val partitions = partitionPolicy.partition(reductionLevel, maxNodesPerPartition)
    for (partition in partitions) {
      partition.removePermanentlyDeletedNodes { it.isPermanentlyDeleted }
      if (partition.isEmpty) {
        continue
      }
      val editList = createTreeEditListByDisablingPartition(partition, tree)
      if (editList.isEmpty()) {
        logEmptyEdits(partition)
      }
      val (treeEdit) = testAllTreeEditsAndReturnTheBest(editList) ?: continue
      tree.applyEdit(treeEdit)
      treeEdit.actionSet.actions.asSequence()
        .filter { it is NodeReplacementAction }
        .map { it as NodeReplacementAction }
        .filter { isReplacingNodeAtTheLevel(reductionLevel, it) }
        .forEach { reductionLevel.replaceNode(it.targetNode, it.replacingNode) }
    }
    val newTokenCount = tree.tokenCount
    val granularityReductionEndEvent = granularityReductionStartEvent.createEndEvent(
      System.currentTimeMillis(),
      newTokenCount,
      maxNodesPerPartition,
    )
    listenerManager.onLevelGranularityReductionEnd(granularityReductionEndEvent)
    reductionLevel.cleanDeletedNodes()
  }

  private fun logEmptyEdits(partition: Partition<AbstractSparTreeNode>) {
    Files.newBufferedWriter(
      Paths.get("temp_empty_edits_dump.txt"),
      StandardCharsets.UTF_8,
      StandardOpenOption.APPEND,
      StandardOpenOption.CREATE,
    ).use { sink ->
      sink.write("Empty partition: ")
      sink.write(partition.toString())
      sink.write("\n")
      sink.write("Tree:\n")
      partition.forEach { child: AbstractSparTreeNode ->

        sink.write(
          """
            ${child.parent!!.printTreeStructure()}
  
          """.trimIndent(),
        )
      }
    }
  }

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    val initialRegion = getInitialRegion(tree)
    var currentLevel = initialRegion
    while (!currentLevel.isEmpty) {
      lazyAssert({ currentLevel.nodeCount > 0 }) { "The level cannot be empty." }
      val preSize = tree.tokenCount
      val levelStartEvent = fixpointReductionState
        .fixpointIterationStartEvent
        .createLevelReductionStartEvent(
          System.currentTimeMillis(),
          preSize,
          currentLevel.level,
          currentLevel.nodeCount,
        )
      listenerManager.onLevelReductionStart(levelStartEvent)
      lazyAssert { !currentLevel.isEmpty }
      try {
        reduceOneLevel(tree, currentLevel, levelStartEvent)
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
      val postSize = tree.tokenCount
      listenerManager.onLevelReductionEnd(
        levelStartEvent.createEndEvent(System.currentTimeMillis(), postSize),
      )
      currentLevel = moveToNextLevel(currentLevel)
    }
  }

  companion object {
    private fun isReplacingNodeAtTheLevel(
      level: ReductionLevel,
      action: NodeReplacementAction,
    ): Boolean {
      return level.containsNode(action.targetNode)
    }
  }
}
