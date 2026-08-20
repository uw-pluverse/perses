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
import com.google.common.collect.Sets
import org.perses.util.transformToImmutableList

abstract class AbstractListMinimizer<T : Any, PropertyPayload>(
  protected val arguments: ListMinimizerArguments<T, PropertyPayload>,
  enableCache: Boolean = false,
  enableCacheRefresh: Boolean = false,
) {
  init {
    arguments.input.let { input ->
      require(Sets.newIdentityHashSet<T>().apply { addAll(input) }.size == input.size) {
        "The elements in input have to be distinct objects. $input"
      }
    }
  }

  protected lateinit var best: ImmutableList<ElementWrapper<T>>
    private set

  protected fun convertBestAsRawElements(): ImmutableList<T> =
    best.transformToImmutableList {
      it.element
    }

  val originalWrappedInput: ImmutableList<ElementWrapper<T>> by lazy {
    createWrappedElementList(arguments.input)
  }

  protected val cache: AbstractConfigCache<T> by lazy {
    if (enableCache) {
      RccConfigCache(originalWrappedInput)
    } else {
      NullConfigCache()
    }
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
    val elementsDeletedElsewhere =
      newBest.any {
        arguments.isElementDeletedElsewhere(it.element)
      }
    best =
      if (elementsDeletedElsewhere) {
        // TODO(cnsun): write tests for the following code.
        val builder = ImmutableList.builder<ElementWrapper<T>>()
        for (elementWrapper in newBest) {
          if (arguments.isElementDeletedElsewhere(elementWrapper.element)) {
            elementWrapper.markAsDeleted()
          } else {
            builder.add(elementWrapper)
          }
        }
        builder.build()
      } else {
        newBest
      }
    arguments.onBestUpdate(newBest, payload)
    cache.refreshAndUpdateBest(best)
  }

  protected fun testProperty(
    configuration: Candidate<T>,
  ): ListMinimizerPropertyTestResult<T, PropertyPayload> {
    val cacheKey = configuration.candidateWrappers
    if (cache.contains(cacheKey)) {
      return ListMinimizerPropertyTestResult.Skipped("Cached")
    }
    cache.add(cacheKey)
    return arguments.testProperty(
      configuration,
      sizeOfCurrentMinimizationResult = best.size,
    )
  }

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
          if (it is ListMinimizerPropertyTestResult.Completed && it.result.isInteresting) {
            updateBest(empty, it.payload)
            return convertBestAsRawElements()
          }
        }
        if (best.size == 1) {
          arguments.log {
            "There is only one element in the input, and the empty input has been tested."
          }
          return convertBestAsRawElements()
        }
      } else {
        arguments.log { "Testing the empty input is disabled." }
      }
      if (best.isNotEmpty()) {
        reduceNonEmptyInput()
      }
      return convertBestAsRawElements()
    } finally {
      arguments.endReduction(
        minimizationResult = best,
        listMinimizerClass = this::class,
      )
    }
  }

  protected abstract fun reduceNonEmptyInput()

  companion object {
    object NoPayload {
      override fun toString(): String = this::class.simpleName!!
    }
  }
}
