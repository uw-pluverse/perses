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
import org.perses.reduction.CandidateOutcome
import kotlin.reflect.KClass

data class ListMinimizerArguments<T : Any, PropertyPayload>(
  val needToTestEmpty: Boolean,
  val input: ImmutableList<out T>,
  val isElementDeletedElsewhere: (T) -> Boolean,
  val propertyTester: IPropertyTester<T, PropertyPayload>,
  val onBestUpdateHandler: OnBestUpdateHandler<T, PropertyPayload>,
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
  val oneByOneMinimizerArguments: OneByOneMinimizerArguments? =
    null,
  val adaptiveGainDrivenMinimizerArguments: AdaptiveGainDrivenMinimizerArguments =
    AdaptiveGainDrivenMinimizerArguments.NULL,
  // The number of property tests a concurrency-capable minimizer may keep in flight. Values greater
  // than 1 only help when [propertyTester] overrides IPropertyTester.submitProperty to be truly
  // asynchronous.
  val concurrency: Int = 1,
) {
  fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
  ) {
    listener.startReduction(originalInput, listMinimizerClass, descriptionPrefix)
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
  ): CandidateOutcome<PropertyPayload> =
    propertyTester.testProperty(configuration).get().also { result ->
      listener.onPropertyTest(
        configuration,
        result,
        sizeOfOriginalList = input.size,
        sizeOfCurrentMinimizationResult = sizeOfCurrentMinimizationResult,
      )
    }

  fun submitProperty(
    configuration: Candidate<T>,
    sizeOfCurrentMinimizationResult: Int,
  ): PropertyTestHandle<T, PropertyPayload> {
    val handle = propertyTester.testProperty(configuration)
    return object : PropertyTestHandle<T, PropertyPayload> {
      override fun get(): CandidateOutcome<PropertyPayload> =
        handle.get().also { result ->
          listener.onPropertyTest(
            configuration,
            result,
            sizeOfOriginalList = input.size,
            sizeOfCurrentMinimizationResult = sizeOfCurrentMinimizationResult,
          )
        }

      override fun requestToCancel() {
        handle.requestToCancel()
      }
    }
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

// TODO(cnsun): need to parameterize this argument class.
data class OneByOneMinimizerArguments(
  val deleteFromFrontToBack: Boolean = false,
  val repeatForFixpoint: Boolean = false,
)

data class AdaptiveGainDrivenMinimizerArguments(
  val getCurrentTotalTokenCount: () -> Int,
  val anticipatedTokenCountInResult: Int,
) {
  fun computeProbabilityOfIndividualTokenRelevance(): Double {
    val total = getCurrentTotalTokenCount()
    if (total == 0) {
      return 0.0
    }
    return (anticipatedTokenCountInResult.toDouble() / total).coerceAtMost(1.0)
  }

  companion object {
    val NULL =
      AdaptiveGainDrivenMinimizerArguments(
        getCurrentTotalTokenCount = { 0 },
        anticipatedTokenCountInResult = 0,
      )
  }
}
