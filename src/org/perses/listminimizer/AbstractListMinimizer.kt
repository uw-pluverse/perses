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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import com.google.common.collect.Sets
import org.perses.util.transformToImmutableList

abstract class AbstractListMinimizer<T : Any, PropertyPayload>(
  protected val arguments: ListMinimizerArguments<T, PropertyPayload>,
) {
  init {
    arguments.input.let { input ->
      input
        .fold(
          Sets.newIdentityHashSet<T>(),
        ) { acc, element ->
          acc.add(element)
          acc
        }.let {
          require(it.size == input.size) {
            "The elements in input have to be distinct objects. $input"
          }
        }
    }
  }

  protected lateinit var best: ImmutableList<ElementWrapper<T>>
    private set

  val originalWrappedInput: ImmutableList<ElementWrapper<T>> by lazy {
    createWrappedElementList(arguments.input)
  }

  private fun createWrappedElementList(
    originalInput: ImmutableList<out T>,
  ): ImmutableList<ElementWrapper<T>> =
    originalInput.withIndex().transformToImmutableList {
      createElementWrapperFor(it.index, it.value)
    }

  protected open fun createElementWrapperFor(
    index: Int,
    element: T,
  ): ElementWrapper<T> = ElementWrapper(index, element, NoPayload)

  protected fun updateBest(
    newBest: ImmutableList<ElementWrapper<T>>,
    payload: PropertyPayload,
  ) {
    best = newBest
    arguments.onBestUpdate(newBest, payload)
  }

  protected fun testProperty(
    configuration: Candidate<T>,
  ): LMPropertyTestResult<T, PropertyPayload> =
    arguments.testProperty(
      configuration,
      sizeOfCurrentMinimizationResult = best.size,
    )

  fun reduce(): ImmutableList<out T> {
    if (originalWrappedInput.isEmpty()) {
      best = originalWrappedInput
      return arguments.input
    }
    check(originalWrappedInput.isNotEmpty()) {
      "The input is empty, but the following code assumes the original input is non-empty."
    }
    try {
      arguments.startReduction(originalWrappedInput, this::class)
      best = originalWrappedInput
      // test whether the entire input can be deleted.
      if (arguments.needToTestEmpty) {
        arguments.log { "Testing the empty input." }
        val empty = ImmutableList.of<ElementWrapper<T>>()
        testProperty(
          Candidate.SublistFromOriginal(original = best, candidate_ = empty),
        ).let {
          if (it is LMPropertyTestResult.Completed && it.result.isInteresting) {
            updateBest(empty, it.payload)
            return best.transformToImmutableList { it.element }
          }
        }
      } else {
        arguments.log { "Testing the empty input is disabled." }
      }
      reduceNonEmptyInput()
      return best.transformToImmutableList { it.element }
    } finally {
      arguments.endReduction(
        minimizationResult = best,
        listMinimizerClass = this::class,
      )
    }
  }

  protected abstract fun reduceNonEmptyInput()

  companion object {
    object NoPayload
  }
}
