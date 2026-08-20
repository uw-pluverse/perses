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

import com.google.common.collect.ImmutableList
import org.perses.spartree.AbstractTreeNode
import org.perses.spartree.ErrorMessage
import org.perses.util.toImmutableList
import kotlin.math.pow

/**
 * TODO(cnsun): Should use the tree api to refactor this class.
 */
sealed class AbstractSearchSpaceNode<T : Any>(
  nodeId: Int,
) : AbstractTreeNode<AbstractSearchSpaceNode<T>, Nothing?>(nodeId) {
  var elements: ImmutableList<ElementWrapper<T>>? = null
  var weight: Int? = null
  var expectedGain: Double = Double.NaN

  abstract fun updateExpectedGainAndElements(
    probabilityOfRelevance: Double,
    weightProvider: IWeightProvider<T>,
  )

  override fun onChildRemoved(
    index: Int,
    child: AbstractSearchSpaceNode<T>,
  ) {
    // No specific action needed on child removal for now
  }

  override fun checkNodeIntegrity(): ErrorMessage? = null

  data class Leaf<T : Any>(
    val elementWrapper: ElementWrapper<T>,
    val id: Int,
  ) : AbstractSearchSpaceNode<T>(id) {
    override fun updateExpectedGainAndElements(
      probabilityOfRelevance: Double,
      weightProvider: IWeightProvider<T>,
    ) {
      val weight = weightProvider.weight(elementWrapper.element)
      this.expectedGain = weight * (1 - probabilityOfRelevance).pow(weight)
      this.weight = weight
      elements = ImmutableList.of(elementWrapper)
    }

    override fun internalCopyCurrentNode(computedNewNodeId: Int): AbstractSearchSpaceNode<T> =
      Leaf(elementWrapper, computedNewNodeId)
  }

  data class Intermediate<T : Any>(
    val id: Int,
  ) : AbstractSearchSpaceNode<T>(id) {
    override fun updateExpectedGainAndElements(
      probabilityOfRelevance: Double,
      weightProvider: IWeightProvider<T>,
    ) {
      forEachChild { child ->
        child.updateExpectedGainAndElements(probabilityOfRelevance, weightProvider)
      }
      val weight = childSequence().sumOf { it.weight!! }
      this.weight = weight
      this.expectedGain = weight.toDouble() * (1 - probabilityOfRelevance).pow(weight)
      elements = childSequence().flatMap { it.elements ?: emptyList() }.toImmutableList()
    }

    override fun internalCopyCurrentNode(computedNewNodeId: Int): AbstractSearchSpaceNode<T> =
      Intermediate(computedNewNodeId)
  }

  companion object {
    /**
     * Compute a binary search space tree for the given list of elements.
     * The leaves of the tree are individual elements.
     */
    @JvmStatic
    fun <T : Any> computeSearchSpace(
      elements: ImmutableList<ElementWrapper<T>>,
    ): AbstractSearchSpaceNode<T>? {
      var nextId = 0

      fun computeInternal(
        elements: ImmutableList<ElementWrapper<T>>,
      ): AbstractSearchSpaceNode<T>? {
        if (elements.isEmpty()) {
          return null
        }
        if (elements.size == 1) {
          return Leaf<T>(elementWrapper = elements[0], id = nextId++).apply {
            this.elements = elements
          }
        }
        val mid = elements.size / 2
        val leftList = elements.subList(0, mid)
        val rightList = elements.subList(mid, elements.size)
        val left = computeInternal(elements = leftList)!!
        val right = computeInternal(elements = rightList)!!

        val intermediate = Intermediate<T>(id = nextId++)
        intermediate.elements = elements
        intermediate.addChild(left, null)
        intermediate.addChild(right, null)
        return intermediate
      }

      return computeInternal(elements)
    }
  }
}
