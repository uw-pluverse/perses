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

import com.google.common.collect.ImmutableList
import org.perses.delta.PristineDeltaDebugger
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTreeSimplifier

class PristineHDDReducer(
  reducerContext: ReducerContext,
) : AbstractTokenReducer(META, reducerContext) {

  /**
   * Need to remove
   *   1) optional nodes,
   *   2) kleene nodes which have only one child
   */
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    SparTreeSimplifier.simplify(tree)
    var currentLevel = ImmutableList.of(tree.root)
    while (currentLevel.isNotEmpty()) {
      val debugger = PristineDeltaDebugger(
        createDeltaArguments(
          needToTestEmpty = true,
          tree,
          actionsDescription = "[pristine-hdd]",
          input = currentLevel,
        ),
      )
      val reducedCurrentLevel = debugger.reduce()
      currentLevel = moveToNextLevel(reducedCurrentLevel)
    }
  }

  companion object {

    const val NAME = "pristine_hdd"

    @JvmStatic
    val META = object : ReducerAnnotation(
      shortName = NAME,
      description = "",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
      override fun create(reducerContext: ReducerContext) = ImmutableList.of<AbstractTokenReducer>(
        PristineHDDReducer(
          reducerContext,
        ),
      )
    }

    fun moveToNextLevel(
      current: ImmutableList<AbstractSparTreeNode>,
    ): ImmutableList<AbstractSparTreeNode> {
      val builder = ImmutableList.builder<AbstractSparTreeNode>()
      for (node in current) {
        val candidates = java.util.ArrayDeque<AbstractSparTreeNode>()
        node.forEachChild { candidates.addLast(it) }
        while (candidates.isNotEmpty()) {
          val candidate = candidates.pollFirst()
          when (candidate.childCount) {
            0 ->
              if (candidate.isTokenNode) {
                builder.add(candidate)
              } else {
                continue
              }

            1 -> candidates.addFirst(candidate.getChild(0))
            else -> builder.add(candidate)
          }
        }
      }
      return builder.build()
    }
  }
}
