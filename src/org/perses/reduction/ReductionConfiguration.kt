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
package org.perses.reduction

import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.program.printer.PrinterRegistry
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Files
import java.nio.file.Path

/**
 * This is the internal configuration for Perses reducer.
 */
class ReductionConfiguration(
  val globalFixpoint: Boolean,
  val fixpointReductionForMainReducer: Boolean,
  val enableDeprecatedQueryCaching: Boolean,
  val fullyDeterministicMode: Boolean,
  val numOfReductionThreads: Int,
  val parserFacade: AbstractParserFacade,
  val persesNodeReducerConfig: PersesNodeReducerConfiguration,
  val listMinimizerConfig: ListMinimizerConfig,
  val vulcanConfig: VulcanConfig,
  val lprConfig: LPRConfig,
  val latraConfig: LatraConfig,
  val shaHashAlgorithm: EnumShaAlgorithm,
) {
  val originalFormatPrinter =
    PrinterRegistry.getPrinter(
      format = parserFacade.language.origCodeFormatControl,
      lexerAtnWrapper = parserFacade.lexerAtnWrapper,
    )

  init {
    require(numOfReductionThreads > 0) {
      "The number of reduction threads should be positive: $numOfReductionThreads"
    }
  }

  class PersesNodeReducerConfiguration(
    val maxEditCountForRegularRuleNode: Int,
    val maxBfsDepthForRegularRuleNode: Int,
    val stopAtFirstCompatibleChildren: Boolean,
  ) {
    init {
      require(maxEditCountForRegularRuleNode > 0)
      require(maxBfsDepthForRegularRuleNode > 0)
    }
  }

  class ListMinimizerConfig(
    val defaultListMinimizerTypeForKleene: EnumListMinimizerType,
    val defaultListMinimizerTypeForHdd: EnumListMinimizerType,
    val minSlidingWindowSize: Int,
    val maxSlidingWindowSize: Int,
  ) {
    init {
      require(0 < minSlidingWindowSize) { minSlidingWindowSize }
      require(minSlidingWindowSize <= maxSlidingWindowSize) {
        "$minSlidingWindowSize $maxSlidingWindowSize"
      }
    }
  }

  class LatraConfig(
    val listMinimizerForTransformations: EnumListMinimizerType,
  )

  class VulcanConfig(
    val nonDeletionIterationLimit: Int,
    val windowSizeForLocalExhaustivePatternReduction: Int,
    val vulcanFixpoint: Boolean,
  ) {
    init {
      require(nonDeletionIterationLimit > 0) {
        "Non deletion iteration limit: $nonDeletionIterationLimit"
      }
      require(windowSizeForLocalExhaustivePatternReduction > 0) {
        "$windowSizeForLocalExhaustivePatternReduction"
      }
    }
  }

  class LPRConfig(
    val llmClientPath: Path?,
    val lprFixpoint: Boolean,
  ) {
    init {
      require(llmClientPath == null || Files.isRegularFile(llmClientPath)) {
        "The script to invoke LLM is not a regular file: $llmClientPath"
      }
    }
  }
}
