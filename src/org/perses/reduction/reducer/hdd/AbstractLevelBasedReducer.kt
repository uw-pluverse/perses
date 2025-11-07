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
package org.perses.reduction.reducer.hdd

import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.ReductionLevel
import org.perses.spartree.NodeReplacementAction
import org.perses.spartree.SparTree

/**
 * The base class for reducers that perform level-based reduction.
 **/
abstract class AbstractLevelBasedReducer protected constructor(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractTokenReducer(reducerAnnotation, reducerContext) {
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    var currentLevel = getInitialRegion(tree)
    while (!currentLevel.isEmpty) {
      check(currentLevel.nodeCount > 0) { "The level cannot be empty." }
      val levelStartEvent =
        fixpointReductionState
          .fixpointIterationStartEvent
          .createLevelReductionStartEvent(
            System.currentTimeMillis(),
            tree.tokenCount,
            currentLevel.level,
            currentLevel.nodeCount,
          )
      reducerContext.listenerManager.onLevelReductionStart(levelStartEvent)
      check(!currentLevel.isEmpty)
      reduceOneLevel(tree, currentLevel, fixpointReductionState)
      reducerContext.listenerManager.onLevelReductionEnd(
        levelStartEvent.createEndEvent(System.currentTimeMillis(), tree.tokenCount),
      )
      currentLevel = currentLevel.createNextLevel()
    }
  }

  protected fun getInitialRegion(tree: SparTree): ReductionLevel {
    val level = ReductionLevel(level = 1)
    tree.realRoot.forEachChild { level.addNode(it) }
    return level
  }

  override fun computeListMinimizerType(): EnumListMinimizerType =
    reducerContext.configuration.listMinimizerConfig.defaultListMinimizerTypeForHdd

  protected fun reduceOneLevel(
    tree: SparTree,
    level: ReductionLevel,
    fixpointReductionState: FixpointReductionState,
  ) {
    runListMinimizerOverNodes(
      tree = tree,
      fixpointReductionState = fixpointReductionState,
      input = level.toImmutableList(),
    )
    level.cleanDeletedNodes()
  }

  companion object {
    private fun isReplacingNodeAtTheLevel(
      level: ReductionLevel,
      action: NodeReplacementAction,
    ): Boolean = level.containsNode(action.targetNode)
  }
}
