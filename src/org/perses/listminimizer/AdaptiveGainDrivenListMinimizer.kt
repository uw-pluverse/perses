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
package org.perses.listminimizer

import java.util.PriorityQueue

class AdaptiveGainDrivenListMinimizer<T : Any, PropertyPayload>(
  arguments: ListMinimizerArguments<T, PropertyPayload>,
) : AbstractListMinimizer<T, PropertyPayload>(arguments) {
  override fun reduceNonEmptyInput() {
    val theseArguments =
      arguments.adaptiveGainDrivenMinimizerArguments
    val searchSpace = AbstractSearchSpaceNode.computeSearchSpace(best) ?: return
    searchSpace.updateExpectedGainAndElements(
      probabilityOfRelevance = theseArguments.computeProbabilityOfIndividualTokenRelevance(),
      weightProvider = arguments.weightProvider,
    )
    val priorityQueue =
      PriorityQueue(
        compareByDescending<AbstractSearchSpaceNode<T>> { it.expectedGain }
          .thenByDescending { it.weight }
          .thenByDescending {
            // The node is pre-order traversal.
            it.nodeId
          }.thenByDescending { it.elements!!.size },
      )
    searchSpace.preOrderVisit { node ->
      priorityQueue.add(node)
      node.immutableChildView
    }
    while (priorityQueue.isNotEmpty()) {
      val searchSpaceNode = priorityQueue.poll()
      if (!tryDeleting(searchSpaceNode.elements!!)) {
        continue
      }
      searchSpaceNode.parent?.removeChild(searchSpaceNode)
      searchSpaceNode.delete()
      // After the best is updated, so that the global total token count is up to date.
      recomputeExpectedGainAndUpdatePriorityQueue(searchSpace, priorityQueue)
    }
  }

  private fun recomputeExpectedGainAndUpdatePriorityQueue(
    searchSpace: AbstractSearchSpaceNode<T>,
    priorityQueue: PriorityQueue<AbstractSearchSpaceNode<T>>,
  ) {
    searchSpace.updateExpectedGainAndElements(
      probabilityOfRelevance =
        arguments.adaptiveGainDrivenMinimizerArguments
          .computeProbabilityOfIndividualTokenRelevance(),
      weightProvider = arguments.weightProvider,
    )
    val copy =
      mutableListOf<AbstractSearchSpaceNode<T>>().apply {
        while (priorityQueue.isNotEmpty()) {
          val searchSpaceNode = priorityQueue.poll()
          if (!searchSpaceNode.isPermanentlyDeleted && searchSpaceNode.elements!!.isNotEmpty()) {
            add(searchSpaceNode)
          }
        }
      }
    check(priorityQueue.isEmpty()) { "The priority queue should be empty." }
    priorityQueue.addAll(copy)
  }
}
