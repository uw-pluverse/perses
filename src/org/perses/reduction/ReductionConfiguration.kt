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
import org.perses.listminimizer.EnumListInputMinimizerType
import org.perses.program.EnumFormatControl
import org.perses.program.printer.PrinterRegistry

/**
 * This is the internal configuration for Perses reducer.
 */
class ReductionConfiguration(
  val fixpointReduction: Boolean,
  val enableTestScriptExecutionCaching: Boolean,
  val defaultDeltaDebuggerTypeForKleene: EnumListInputMinimizerType,
  val numOfReductionThreads: Int,
  val parserFacade: AbstractParserFacade,
  val persesNodeReducerConfig: PersesNodeReducerConfiguration,
  val vulcanConfig: VulcanConfig,
) {

  val originalFormatPrinter = PrinterRegistry.getPrinter(
    format = EnumFormatControl.ORIG_FORMAT,
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

  class VulcanConfig(
    val nonDeletionIterationLimit: Int,
    val windowSizeForLocalExhaustivePatternReduction: Int,
    val vulcanFixpoint: Boolean,
  ) {
    init {
      require(nonDeletionIterationLimit > 0)
      require(windowSizeForLocalExhaustivePatternReduction > 0)
    }
  }
}
