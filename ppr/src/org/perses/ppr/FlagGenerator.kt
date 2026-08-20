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
package org.perses.ppr

import org.perses.PersesCommandOptions
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.ppr.diff.list.ListDiffCmdOptions
import org.perses.ppr.diff.tree.TreeDiffCmdOptions
import org.perses.ppr.seed.SeedCmdOptions
import java.nio.file.Path

class FlagGenerator(
  private val originalCmd: PPRMainCommandOptions,
  private val testPath: Path,
  val workingDir: Path,
) {
  fun generateListDiffCmdOptions(
    seedPath: Path,
    variantPath: Path,
    enableListDiff: Boolean,
  ): ListDiffCmdOptions {
    val listDiffCmdOptions = ListDiffCmdOptions()
    listDiffCmdOptions.copyParameterValuesFrom(originalCmd)

    // TRec is not compatible with PPR.
    listDiffCmdOptions.inputFlags.setInputFiles(listOf(seedPath))
    listDiffCmdOptions.listDiffInputFlags.variantFile = variantPath
    listDiffCmdOptions.inputFlags.testScript = testPath
    listDiffCmdOptions.resultOutputFlags.outputDir = workingDir

    listDiffCmdOptions.listDiffInputFlags.enableDiffSlicer = enableListDiff
    listDiffCmdOptions.listDiffInputFlags.enableDiffDdmin = enableListDiff

    updateAlgorithmControlFlags(listDiffCmdOptions)
    updateReductionControlFlags(listDiffCmdOptions)

    return listDiffCmdOptions
  }

  fun generateTreeDiffCmdOptions(
    seedPath: Path,
    variantPath: Path,
  ): TreeDiffCmdOptions {
    val treeDiffCmdOptions = TreeDiffCmdOptions()
    treeDiffCmdOptions.copyParameterValuesFrom(originalCmd)
    // TRec is not compatible with PPR.
    treeDiffCmdOptions.inputFlags.setInputFiles(listOf(seedPath))
    treeDiffCmdOptions.treeDiffInputFlags.variantFile = variantPath
    treeDiffCmdOptions.inputFlags.testScript = testPath
    treeDiffCmdOptions.resultOutputFlags.outputDir = workingDir

    updateAlgorithmControlFlags(treeDiffCmdOptions)
    updateReductionControlFlags(treeDiffCmdOptions)

    return treeDiffCmdOptions
  }

  fun generateSeedCmdOptions(
    seedPath: Path,
    variantPath: Path,
  ): SeedCmdOptions {
    val seedCmdOptions = SeedCmdOptions()
    seedCmdOptions.copyParameterValuesFrom(originalCmd)
    // TRec is not compatible with PPR.
    seedCmdOptions.trecFlags.enableTRec = false
    seedCmdOptions.latraFlags.enableLatra = false
    seedCmdOptions.inputFlags.setInputFiles(listOf(seedPath))
    seedCmdOptions.seedInputFlags.variantFile = variantPath
    seedCmdOptions.inputFlags.testScript = testPath
    seedCmdOptions.resultOutputFlags.outputDir = workingDir

    updateAlgorithmControlFlags(seedCmdOptions)
    updateReductionControlFlags(seedCmdOptions)

    return seedCmdOptions
  }

  private fun updateAlgorithmControlFlags(cmd: PersesCommandOptions) {
    cmd.algorithmControlFlags.rebuildParseTreeEachIteration = false
    cmd.persesFlags.listMinimizerTypeForKleene =
      EnumListMinimizerType.PERSES_VARIANT_OF_PRISTINE
  }

  private fun updateReductionControlFlags(cmd: PersesCommandOptions) {
    cmd.reductionControlFlags.fixpointForMainReducer = false
  }
}
