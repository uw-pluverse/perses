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
package org.perses.delta

import com.google.common.collect.ImmutableList
import com.google.common.collect.Sets
import org.perses.delta.AbstractDeltaDebuggerListener.NullDeltaDebuggerListener
import org.perses.util.transformToImmutableList

abstract class AbstractDeltaDebugger<T, PropertyPayload>(
  protected val arguments: Arguments<T, PropertyPayload>,
) {

  init {
    arguments.input.let { input ->
      input.fold(
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

  val originalInput: ImmutableList<ElementWrapper<T>> by lazy {
    createWrappedElementList(arguments.input)
  }

  private fun createWrappedElementList(
    originalInput: ImmutableList<T>,
  ): ImmutableList<ElementWrapper<T>> {
    return originalInput.withIndex().transformToImmutableList {
      createElementWrapperFor(it.index, it.value)
    }
  }

  protected open fun createElementWrapperFor(index: Int, element: T): ElementWrapper<T> {
    return ElementWrapper(index, element, NoPayload)
  }

  protected fun updateBest(
    newBest: ImmutableList<ElementWrapper<T>>,
    payload: PropertyPayload,
  ) {
    best = newBest
    arguments.onBestUpdateHandler.invoke(newBest, payload)
    arguments.listener.onBestUpdate(best)
  }

  protected fun testProperty(
    configuration: Configuration<T>,
  ): AbstractPropertyTestResultWithPayload<PropertyPayload> {
    return arguments.propertyTester.testProperty(configuration).also {
      arguments.listener.onPropertyTest(configuration, it)
    }
  }

  fun reduce(): ImmutableList<T> {
    try {
      arguments.listener.startReduction(originalInput)
      best = originalInput
      // test whether the entire input can be deleted.
      if (arguments.needToTestEmpty) {
        arguments.listener.log { "Testing the empty input." }
        val empty = ImmutableList.of<ElementWrapper<T>>()
        testProperty(
          Configuration(currentBest = best, candidate_ = empty, deleted_ = null),
        ).let {
          if (it is PropertyTestResultWithPayload && it.result.isInteresting) {
            updateBest(empty, it.payload)
            return best.transformToImmutableList { it.element }
          }
        }
      } else {
        arguments.listener.log { "Testing the empty input is disabled." }
      }
      reduceNonEmptyInput()
      return best.transformToImmutableList { it.element }
    } finally {
      arguments.listener.endReduction()
    }
  }

  protected fun log(msg: () -> String) {
    arguments.listener.log(msg)
  }

  protected abstract fun reduceNonEmptyInput()

  fun interface OnBestUpdateHandler<T, PropertyPayload> {
    fun invoke(newBest: ImmutableList<ElementWrapper<T>>, payload: PropertyPayload)
  }

  data class Arguments<T, PropertyPayload>(
    val needToTestEmpty: Boolean,
    val input: ImmutableList<T>,
    val propertyTester: IPropertyTester<T, PropertyPayload>,
    val onBestUpdateHandler: OnBestUpdateHandler<T, PropertyPayload>,
    val descriptionPrefix: String,
    val partitionComplementControl: PartitionComplementControl = PartitionComplementControl(
      enableReducingPartitions = true,
      enableReducingComplements = true,
    ),
    val listener: AbstractDeltaDebuggerListener = NullDeltaDebuggerListener,
  )

  class ElementWrapper<T>(
    val index: Int,
    val element: T,
    var elementPayload: Any,
  ) : Comparable<ElementWrapper<T>> {
    override fun compareTo(other: ElementWrapper<T>): Int {
      return index.compareTo(other.index)
    }
  }

  data class PartitionComplementControl(
    val enableReducingPartitions: Boolean,
    val enableReducingComplements: Boolean,
  )

  companion object {
    object NoPayload
  }
}
