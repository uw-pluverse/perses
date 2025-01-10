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
package org.perses.fuzzer

import com.google.common.collect.ImmutableList
import org.perses.program.printer.SingleTokenPerLinePrinter
import org.perses.spartree.AbstractSparTreeGenerator
import org.perses.spartree.SparTree
import java.util.Random

class MutationOperatorExecutor(
  private val mutationControlFlags: CommandOptions.MutationControl,
  private val random: Random,
  private val generator: AbstractSparTreeGenerator?,
  private val scheduler: FuzzingScheduler,
) {
  private val tokenLevelMutationOperators = createTokenLevelMutationOperators()
  private val treeLevelMutationOperators = createTreeLevelMutationOperators()
  private val mutationOperatorsWithoutSavingTreeStructure =
    createAllMutationOperatorsWithoutSavingTreeStructure()

  init {
    assert(tokenLevelMutationOperators != null || treeLevelMutationOperators != null)
  }

  data class MutationResult(
    val mutatedSource: String,
    val mutatedSparTree: SparTree?,
  )

  fun mutateWithoutSavingTreeStructure(treeFuzzer: SparTreeFuzzer): MutatedProgram? {
    return mutationOperatorsWithoutSavingTreeStructure!!.sample(random).invoke(treeFuzzer)
  }

  fun mutateWithTokenLevelMutation(treeFuzzer: SparTreeFuzzer): MutationResult? {
    val mutatedProgram = tokenLevelMutationOperators?.sample(random)?.invoke(treeFuzzer)
      ?: return null
    val mutatedSource = mutatedProgram.program
    return MutationResult(mutatedSource, mutatedSparTree = null)
  }

  fun mutateWithTreeLevelMutation(treeFuzzer: SparTreeFuzzer): MutationResult? {
    val sparTree = treeLevelMutationOperators?.sample(random)?.invoke(treeFuzzer) ?: return null
    val mutatedSource =
      SingleTokenPerLinePrinter.print(sparTree.programSnapshot).sourceCode
    return MutationResult(mutatedSource, sparTree)
  }

  // Can only generate MutatedProgram, the tree structure won't be saved
  private fun createAllMutationOperatorsWithoutSavingTreeStructure():
    DistributionTable<(SparTreeFuzzer) -> MutatedProgram?>? {
    val builder = ImmutableList.builder<
      DistributionTable.Entry<(SparTreeFuzzer) -> MutatedProgram?>,
      >()
    if (mutationControlFlags.enableReplacingIdentifier) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingIdentifier(random)
        },
      )
    }
    if (mutationControlFlags.enableReplacingSameTypeToken) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingSameToken(random)
        },
      )
    }
    if (mutationControlFlags.maxRecursionDepth > 0) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          @Suppress("DEPRECATION")
          it.createMutantByRepeatingRecursion(random, mutationControlFlags.maxRecursionDepth)
        },
      )
    }
    if (mutationControlFlags.enableReplacingOnRandomPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingTokensOnRandomPositions(random)
        },
      )
    }
    if (mutationControlFlags.enableReplacingOnContinuousPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingARangeOfTokens(random)
        },
      )
    }
    if (mutationControlFlags.enableDeletingOnRandomPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByDeletingTokensOnRandomPositions(random)
        },
      )
    }
    if (mutationControlFlags.enableDeletingOnContinuousPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByDeletingARangeOfTokens(random)
        },
      )
    }
    if (mutationControlFlags.enableInsertingChildrenOfKleeneNode && generator != null) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByInsertingChildrenToKleeneStarOrPlusNode(random, generator)
        },
      )
    }
    if (mutationControlFlags.enableInsertingOnRandomPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByInsertingTokensOnRandomPositions(random)
        },
      )
    }
    if (mutationControlFlags.enableInsertingOnContinuousPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByInsertingARangeOfTokens(random)
        },
      )
    }
    if (mutationControlFlags.enableSplicing) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          val another = scheduler.fuzzerInstances.getRandomFuzzer(random)
          @Suppress("DEPRECATION")
          it.createMutantBySplicing(another, random)
        },
      )
    }
    if (generator != null && mutationControlFlags.enableReplacingWithGeneratedNode) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          @Suppress("DEPRECATION")
          it.createMutantByReplacingWithGeneratedNode(random, generator)
        },
      )
    }
    if (builder.build().isEmpty()) {
      return null
    }
    return DistributionTable(builder.build())
  }

  private fun createTokenLevelMutationOperators():
    DistributionTable<(SparTreeFuzzer) -> MutatedProgram?>? {
    val builder = ImmutableList.builder<
      DistributionTable.Entry<(SparTreeFuzzer) -> MutatedProgram?>,
      >()
    if (mutationControlFlags.enableReplacingIdentifier) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingIdentifier(random)
        },
      )
    }
    if (mutationControlFlags.enableReplacingSameTypeToken) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingSameToken(random)
        },
      )
    }
    // TODO: should be moved to treeLevelMutationOperators
    if (mutationControlFlags.maxRecursionDepth > 0) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          @Suppress("DEPRECATION")
          it.createMutantByRepeatingRecursion(random, mutationControlFlags.maxRecursionDepth)
        },
      )
    }
    if (mutationControlFlags.enableReplacingOnRandomPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingTokensOnRandomPositions(random)
        },
      )
    }
    if (mutationControlFlags.enableReplacingOnContinuousPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByReplacingARangeOfTokens(random)
        },
      )
    }
    if (mutationControlFlags.enableDeletingOnRandomPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByDeletingTokensOnRandomPositions(random)
        },
      )
    }
    if (mutationControlFlags.enableDeletingOnContinuousPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByDeletingARangeOfTokens(random)
        },
      )
    }
    if (mutationControlFlags.enableInsertingOnRandomPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByInsertingTokensOnRandomPositions(random)
        },
      )
    }
    if (mutationControlFlags.enableInsertingOnContinuousPositions) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByInsertingARangeOfTokens(random)
        },
      )
    }
    if (mutationControlFlags.enableInsertingChildrenOfKleeneNode && generator != null) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutantByInsertingChildrenToKleeneStarOrPlusNode(random, generator)
        },
      )
    }
    if (builder.build().isEmpty()) {
      return null
    }
    return DistributionTable(builder.build())
  }

  private fun createTreeLevelMutationOperators(): DistributionTable<
    (SparTreeFuzzer) -> SparTree?,
    >? {
    val builder = ImmutableList.builder<
      DistributionTable.Entry<(SparTreeFuzzer) -> SparTree?>,
      >()
    if (mutationControlFlags.enableSplicing) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          val another = scheduler.fuzzerInstances.getRandomFuzzer(random)
          it.createMutatedTreeBySplicing(another, random, scheduler.model)
        },
      )
    }
    if (generator != null && mutationControlFlags.enableReplacingWithGeneratedNode) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutatedTreeByReplacingWithGeneratedNode(random, generator, scheduler.model)
        },
      )
    }
    if (mutationControlFlags.enableDeletingChildrenOfKleeneNode) {
      builder.add(
        DistributionTable.Entry(weight = 25) {
          it.createMutatedTreeByDeletingChildrenOfKleeneStarOrPlusNode(random)
        },
      )
    }
    if (builder.build().isEmpty()) {
      return null
    }
    return DistributionTable(builder.build())
  }

  private fun treeLevelMutationIsSelected(random: Random): Boolean {
    return random.nextInt(
      (treeLevelMutationOperators?.totalWeight ?: 0) +
        (tokenLevelMutationOperators?.totalWeight ?: 0),
    ) < (treeLevelMutationOperators?.totalWeight ?: 0)
  }
}
