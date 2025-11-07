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
import kotlin.reflect.KClass

data class ListMinimizerArguments<T : Any, PropertyPayload>(
  val needToTestEmpty: Boolean,
  val input: ImmutableList<out T>,
  private val propertyTester: IPropertyTester<T, PropertyPayload>,
  private val onBestUpdateHandler: OnBestUpdateHandler<T, PropertyPayload>,
  val descriptionPrefix: String,
  val partitionComplementControl: PartitionComplementControl =
    PartitionComplementControl(
      enableReducingPartitions = true,
      enableReducingComplements = true,
    ),
  val weightProvider: IWeightProvider<T> = IWeightProvider { 1 },
  private val listener: AbstractListMinimizerListener = NullListMinimizerListener,
  val windowedSlicerSpecificArguments: WindowedSlicerSpecificArguments? = null,
  val localExhaustMinimizerArguments: LocalExhaustMinimizerArguments? = null,
) {
  fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
  ) {
    listener.startReduction(originalInput, listMinimizerClass)
  }

  fun log(msg: () -> String) {
    listener.log(msg)
  }

  fun endReduction(
    minimizationResult: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
  ) {
    listener.endReduction(minimizationResult, listMinimizerClass, sizeOfOriginalInput = input.size)
  }

  fun onBestUpdate(
    newBest: ImmutableList<ElementWrapper<T>>,
    payload: PropertyPayload,
  ) {
    onBestUpdateHandler.invoke(newBest, payload)
    listener.onBestUpdate(newBest)
  }

  fun testProperty(
    configuration: Candidate<T>,
    sizeOfCurrentMinimizationResult: Int,
  ): LMPropertyTestResult<T, PropertyPayload> =
    propertyTester.testProperty(configuration).also { result ->
      listener.onPropertyTest(
        configuration,
        result,
        sizeOfOriginalList = input.size,
        sizeOfCurrentMinimizationResult = sizeOfCurrentMinimizationResult,
      )
    }
}

fun interface IWeightProvider<T : Any> {
  fun weight(element: T): Int
}

data class PartitionComplementControl(
  val enableReducingPartitions: Boolean,
  val enableReducingComplements: Boolean,
  val countOfInitialPartitions: (input: List<*>) -> Int = { 2 },
)

fun interface OnBestUpdateHandler<T : Any, PropertyPayload> {
  fun invoke(
    newBest: ImmutableList<ElementWrapper<T>>,
    payload: PropertyPayload,
  )
}

data class WindowedSlicerSpecificArguments(
  val minSlidingWindowSize: Int,
  val maxSlidingWindowSize: Int,
) {
  init {
    require(minSlidingWindowSize in 1..maxSlidingWindowSize) {
      "0<minSlidingWindowSize($minSlidingWindowSize)<=maxSlidingWindowSize($maxSlidingWindowSize)."
    }
  }
}

data class LocalExhaustMinimizerArguments(
  val windowSize: Int,
) {
  init {
    require(windowSize > 2) {
      "Window size must be greater than 2 ($windowSize)"
    }
  }
}
