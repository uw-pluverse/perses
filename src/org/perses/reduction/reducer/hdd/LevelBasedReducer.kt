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
package org.perses.reduction.reducer.hdd

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.ReductionLevel
import org.perses.reduction.reducer.AbstractMimirStrategy.MimirReductionContext
import org.perses.reduction.reducer.MimirStrategyFactory
import org.perses.spartree.ContextDescription
import org.perses.spartree.NodeReplacementAction
import org.perses.spartree.SparTree

/**
 * The base class for reducers that perform level-based reduction.
 **/
class LevelBasedReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  val enableMimir: Boolean,
) : AbstractSparTreeReducer(reducerAnnotation, reducerContext) {
  protected val mimirConfig = reducerContext.configuration.mimirConfig

  private val mimirStrategy = MimirStrategyFactory.create(mimirConfig.mimirReductionAlgorithm)

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    var currentLevel = getInitialRegion(tree)
    while (!currentLevel.isEmpty) {
      check(currentLevel.nodeCount > 0) { "The level cannot be empty." }
      val levelStartEvent =
        fixpointReductionState
          .fixpointIterationStartEvent
          .createLevelReductionStartEvent(
            currentTimeMillis = System.currentTimeMillis(),
            perFileSizeMetrics =
              fixpointReductionState.inputRepresentation
                .computePerFileSizeMetrics(),
            level = currentLevel.level,
            nodeCountOnLevel = currentLevel.nodeCount,
          )
      reducerContext.listenerManager.onLevelReductionStart(levelStartEvent)
      check(!currentLevel.isEmpty)
      reduceOneLevel(tree, currentLevel, fixpointReductionState)
      reducerContext.listenerManager.onLevelReductionEnd(
        levelStartEvent.createEndEvent(
          currentTimeMillis = System.currentTimeMillis(),
          perFileSizeMetrics =
            fixpointReductionState.inputRepresentation
              .computePerFileSizeMetrics(),
        ),
      )
      currentLevel = currentLevel.createNextLevel()
    }
  }

  protected fun getInitialRegion(tree: SparTree): ReductionLevel {
    val level = ReductionLevel(level = 1)
    tree.realRoot.forEachChild { level.addNode(it) }
    return level
  }

  override fun computeDefaultListMinimizerType(): EnumListMinimizerType =
    reducerContext.configuration.levelBasedReducerConfig.defaultListMinimizerType

  protected fun reduceOneLevel(
    tree: SparTree,
    level: ReductionLevel,
    fixpointReductionState: FixpointReductionState,
  ) {
    val levelDescription = ContextDescription.of("Level${level.level}:${level.nodeCount}")
    val input = level.toImmutableList()
    val semanticsProvider = fixpointReductionState.inputRepresentation.semantics
    if (enableMimir && semanticsProvider != null) {
      val depGraph = semanticsProvider.buildScopedDependencyGraph(input)
      mimirStrategy.reduce(
        MimirReductionContext(
          // Level-based reducer doesn't have a single parent node for all nodes in the level.
          kleeneNode = null,
          semanticsProvider = semanticsProvider,
          depGraph = depGraph,
          tree = tree,
          fixpointReductionState = fixpointReductionState,
          commonPostfix = levelDescription,
          mimirConfig = mimirConfig,
          runListMinimizerOverNodes = this::runListMinimizerOverNodes,
          runListMinimizerOverListsOfNodes = this::runListMinimizerOverListsOfNodes,
          testAndApplyDeletionEditIfInteresting =
            { actionSet, tree -> testAndApplyDeletionEditIfInteresting(actionSet, tree) },
          testWhetherToUseADifferentMinimizerIfInputIsSmall =
            this::testWhetherToUseADifferentMinimizerIfInputIsSmall,
        ),
      )
    } else {
      runListMinimizerOverNodes(
        needToTestEmpty = true,
        tree = tree,
        fixpointReductionState = fixpointReductionState,
        input = input,
        actionsDescriptionPostfix = levelDescription,
      )
    }
    level.cleanDeletedNodes()
  }

  private fun testWhetherToUseADifferentMinimizerIfInputIsSmall(
    input: ImmutableList<*>,
  ): EnumListMinimizerType? {
    if (!enableMimir) {
      // This method should be enabled only if Mimir is enabled, so that we do
      // not change the existing behavior of Perses.
      return null
    }
    return if (input.size <= mimirConfig.nodeCountThresholdToUseOneByOne) {
      EnumListMinimizerType.ONE_BY_ONE
    } else {
      null
    }
  }

  companion object {
    private fun isReplacingNodeAtTheLevel(
      level: ReductionLevel,
      action: NodeReplacementAction,
    ): Boolean = level.containsNode(action.targetNode)
  }
}
