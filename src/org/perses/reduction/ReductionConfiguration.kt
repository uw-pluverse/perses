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
package org.perses.reduction

import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.program.printer.PrinterRegistry
import org.perses.reduction.reducer.EnumMimirReductionAlgorithm
import org.perses.reduction.semantics.ISemanticsProviderCreator
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Files
import java.nio.file.Path

/**
 * This is the internal configuration for Perses reducer.
 */
class ReductionConfiguration(
  val globalFixpoint: Boolean,
  val mainReducerAnnotation: AbstractReducerNameAndDesc,
  val cleanupReducerAnnotation: AbstractReducerNameAndDesc?,
  val fixpointReductionForMainReducer: Boolean,
  val enableDeprecatedQueryCaching: Boolean,
  val fullyDeterministicMode: Boolean,
  val numOfReductionThreads: Int,
  val canonicalParserFacade: AbstractParserFacade,
  val persesConfig: PersesConfig,
  val listMinimizerConfig: ListMinimizerConfig,
  val vulcanConfig: VulcanConfig,
  val lprConfig: LPRConfig,
  val latraConfig: LatraConfig,
  val sfcConfig: SfcConfig,
  val levelBasedReducerConfig: LevelBasedReducerConfig,
  val mimirConfig: MimirConfig,
  val shaHashAlgorithm: EnumShaAlgorithm,
) {
  val originalFormatPrinter =
    PrinterRegistry.getPrinter(
      format = canonicalParserFacade.language.origCodeFormatControl,
      lexerAtnWrapper = canonicalParserFacade.lexerAtnWrapper,
    )

  init {
    require(numOfReductionThreads > 0) {
      "The number of reduction threads should be positive: $numOfReductionThreads"
    }
  }

  // Need to generate hashcode and equals.
  data class PersesConfig(
    val enableTopDownReduction: Boolean,
    val enableReducingRegularRuleNode: Boolean,
    val enableReducingKleeneOptionalNode: Boolean,
    val maxEditCountForRegularRuleNode: Int,
    val maxBfsDepthForRegularRuleNode: Int,
    val stopAtFirstCompatibleChildren: Boolean,
    val enableLiteralReplacementForListMinimizer: Boolean,
    val enableLiteralReplacementForRegularRuleNode: Boolean,
    val listMinimizerTypeForKleene: EnumListMinimizerType,
    val anticipatedFinalTokenCount: Int,
  ) {
    init {
      require(maxEditCountForRegularRuleNode > 0)
      require(maxBfsDepthForRegularRuleNode > 0)
      require(anticipatedFinalTokenCount >= 0) { "Anticipated token count must be at least 0" }
    }
  }

  // Need to generate hashcode and equals.
  data class ListMinimizerConfig(
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

  // Need to generate hashcode and equals.
  data class LevelBasedReducerConfig(
    val defaultListMinimizerType: EnumListMinimizerType,
  )

  // Need to generate hashcode and equals.
  data class LatraConfig(
    val listMinimizerForTransformations: EnumListMinimizerType,
  )

  // Need to generate hashcode and equals.
  data class SfcConfig(
    /**
     * A subtree of more tokens than this is left alone: the number of structures a subtree can
     * be converted into grows with the number of subtrees under it that can be reused.
     */
    val subtreeTokenCountLimit: Int,
    /** How many of a subtree's candidates are tested before moving on to the next subtree. */
    val candidateLimit: Int,
  )

  // Need to generate hashcode and equals.
  class MimirConfig(
    val semanticsProviderCreator: ISemanticsProviderCreator?,
    val nodeCountThresholdToUseOneByOne: Int,
    val enableBottomUpReductionAfterMainReductionLoop: Boolean,
    val bottomUpReductionMaxDepth: Int,
    val mimirReductionAlgorithm: EnumMimirReductionAlgorithm,
    val enableMimirForRegularRuleNodes: Boolean,
    /*
     * Delete a definition node, with all its concrete uses.
     * By doing this, we can guarantee we do not introduce use-without-def errors.
     */
    val deleteDefWithAllItsConcreteUses: Boolean,
  ) {
    init {
      require(nodeCountThresholdToUseOneByOne >= 0) {
        "The nodeCount threshold must be greater than or equal to 0"
      }
    }
  }

  // Need to generate hashcode and equals.
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

  // Need to generate hashcode and equals.
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
