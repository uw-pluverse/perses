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
package org.perses.ppr

import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Token
import org.perses.CommandOptions
import org.perses.TokenCounterMain
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.listminimizer.EnumListInputMinimizerType
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.ppr.diff.list.ListDiffCmdOptions
import org.perses.ppr.diff.list.ListDiffMain
import org.perses.ppr.diff.tree.TreeDiffCmdOptions
import org.perses.ppr.diff.tree.TreeDiffMain
import org.perses.ppr.seed.SeedCmdOptions
import org.perses.ppr.seed.SeedMain
import org.perses.reduction.GlobalContext
import org.perses.reduction.IReductionDriver
import org.perses.util.ListAlignment
import org.perses.util.Util
import org.perses.util.ktInfo
import java.nio.file.Path

class PPRMetaReductionDriver private constructor(
  val globalContext: GlobalContext,
  val cmd: CmdOptions,
  val parserFacadeFactory: AbstractParserFacadeFactory,
) : IReductionDriver {

  override val cachedSanityCheckResult: IReductionDriver.AbstractSanityCheckResult by lazy {
    // TODO(max): need to run sanity check
    IReductionDriver.PassingSanityCheckResult
  }

  override fun reduce() {
    // create a working folder
    val workingDir = cmd.resultOutputFlags.outputDir
    check(workingDir != null) {
      "Should specify the outputDir"
    }
    Util.ensureDirExists(workingDir)

    // compute new path in the working folder, and copy inputs to the path
    val seedPath = Util.copyFileToDirectory(cmd.overallInputFlags.getSourceFile(), workingDir)
    val variantPath = Util.copyFileToDirectory(cmd.overallInputFlags.variantFile!!, workingDir)
    val testPath = Util.copyFileToDirectory(cmd.overallInputFlags.getTestScript(), workingDir)
    val filesToBeKept = Util.listFilesInFolder(workingDir)

    val languageKind = parserFacadeFactory.computeLanguage(
      cmd.languageControlFlags.languageName,
      seedPath,
    )

    val parserFacade = parserFacadeFactory.getParserFacadeListForOrNull(languageKind)!!
      .defaultParserFacade.create()

    var seedSizeBefore: Int
    var variantSizeBefore: Int
    val initialSeedSize = TokenCounterMain.countTokensOfFile(seedPath, languageKind.name)
    var seedSizeCurrent = initialSeedSize
    val initialVariantSize = TokenCounterMain.countTokensOfFile(variantPath, languageKind.name)
    var variantSizeCurrent = initialVariantSize

    val flagGenerator = FlagGenerator(cmd, testPath, workingDir)
    var iteration = 1

    val iterationRecordList: ArrayList<IterationRecord> = ArrayList()

    do {
      seedSizeBefore = seedSizeCurrent
      variantSizeBefore = variantSizeCurrent

      val timestampStart = System.currentTimeMillis().toInt()

      if (cmd.overallInputFlags.minTDiff) {
        logger.ktInfo { "Start tree-based diff reduction on both trees." }
        printCurrentState(parserFacade, seedPath, variantPath, languageKind.name, iteration)
        TreeDiffMain(
          flagGenerator.generateTreeDiffCmdOptions(seedPath, variantPath),
          globalContext,
        ).use { it.run() }
      }

      if (cmd.overallInputFlags.minLDiff) {
        logger.ktInfo { "Start list-based diff reduction on seed." }
        printCurrentState(parserFacade, seedPath, variantPath, languageKind.name, iteration)
        ListDiffMain(
          flagGenerator.generateListDiffCmdOptions(seedPath, variantPath, enableListDiff = true),
          globalContext,
        ).use { it.run() }
        if (cmd.overallInputFlags.mirror) {
          logger.ktInfo { "Start list-based diff reduction on variant." }
          printCurrentState(parserFacade, seedPath, variantPath, languageKind.name, iteration)
          ListDiffMain(
            flagGenerator.generateListDiffCmdOptions(variantPath, seedPath, enableListDiff = true),
            globalContext,
          ).use { it.run() }
        }
      }

      if (cmd.overallInputFlags.minCommonality) {
        logger.ktInfo { "Start commonality reduction, from seed to variant." }
        printCurrentState(parserFacade, seedPath, variantPath, languageKind.name, iteration)
        SeedMain(
          flagGenerator.generateSeedCmdOptions(seedPath, variantPath),
          globalContext,
        ).use { it.run() }
        if (cmd.overallInputFlags.mirror) {
          logger.ktInfo { "Start commonality reduction, from variant to seed." }
          printCurrentState(parserFacade, seedPath, variantPath, languageKind.name, iteration)
          SeedMain(
            flagGenerator.generateSeedCmdOptions(variantPath, seedPath),
            globalContext,
          ).use { it.run() }
        }
      }

      seedSizeCurrent = TokenCounterMain.countTokensOfFile(seedPath, languageKind.name)
      variantSizeCurrent = TokenCounterMain.countTokensOfFile(variantPath, languageKind.name)
      val diffSizeCurrent = getListAlignment(parserFacade, seedPath, variantPath).onlyDiffs.size

      val timestampStop = System.currentTimeMillis().toInt()

      iterationRecordList.add(
        IterationRecord(
          iteration = iteration,
          seedSizeAfterIteration = seedSizeCurrent,
          variantSizeAfterIteration = variantSizeCurrent,
          diffSizeAfterIteration = diffSizeCurrent,
          (timestampStop - timestampStart) / 1000,
        ),
      )
      iteration++
    } while (seedSizeCurrent < seedSizeBefore || variantSizeCurrent < variantSizeBefore)

    logger.ktInfo { "PPR finished. Here is the summary of each iteration." }
    logger.ktInfo { "Initially, seed: $initialSeedSize, variant: $initialVariantSize" }
    iterationRecordList.forEach {
      logger.ktInfo {
        "After iteration ${it.iteration}, " +
          "seed: ${it.seedSizeAfterIteration}, " +
          "variant: ${it.variantSizeAfterIteration}, " +
          "diff: ${it.diffSizeAfterIteration}, " +
          "time: ${it.seconds} seconds"
      }
    }

    Util.deleteFilesConditionally(workingDir) { path ->
      !filesToBeKept.contains(path)
    }
  }

  override fun close() {}

  class FlagGenerator(
    private val originalCmd: CmdOptions,
    private val testPath: Path,
    val workingDir: Path,
  ) {

    private fun updateAlgorithmControlFlags(cmd: CommandOptions) {
      cmd.algorithmControlFlags.rebuildParseTreeEachIteration = false
      cmd.algorithmControlFlags.defaultDeltaDebuggerTypeForKleene =
        EnumListInputMinimizerType.PERSES_VARIANT_OF_PRISTINE
      cmd.algorithmControlFlags.reductionAlgorithm =
        originalCmd.algorithmControlFlags.reductionAlgorithm
    }

    private fun updateLanguageControlFlags(cmd: CommandOptions) {
      cmd.languageControlFlags.languageName = originalCmd.languageControlFlags.languageName
    }

    private fun updateReductionControlFlags(cmd: CommandOptions) {
      cmd.reductionControlFlags.fixpoint = false
      cmd.reductionControlFlags.setNumOfThreads(
        originalCmd.reductionControlFlags.getNumOfThreads(),
      )
      if (originalCmd.reductionControlFlags.codeFormat != null) {
        cmd.reductionControlFlags.codeFormat = originalCmd.reductionControlFlags.codeFormat
      }
    }

    private fun updateProfilingFlags(cmd: CommandOptions) {
      if (originalCmd.profilingFlags.progressDumpFile != null) {
        cmd.profilingFlags.progressDumpFile = originalCmd.profilingFlags.progressDumpFile
      }
      cmd.profilingFlags.appendToProgressDumpFile =
        originalCmd.profilingFlags.appendToProgressDumpFile
    }

    private fun updateOutputRefiningFlags(cmd: CommandOptions) {
      cmd.outputRefiningFlags.callFormatter = originalCmd.outputRefiningFlags.callFormatter
    }

    fun generateListDiffCmdOptions(
      seedPath: Path,
      variantPath: Path,
      enableListDiff: Boolean,
    ): ListDiffCmdOptions {
      val listDiffCmdOptions = ListDiffCmdOptions()
      listDiffCmdOptions.inputFlags.inputFile = seedPath
      listDiffCmdOptions.listDiffInputFlags.variantFile = variantPath.toString()
      listDiffCmdOptions.inputFlags.testScript = testPath
      listDiffCmdOptions.resultOutputFlags.outputDir = workingDir

      listDiffCmdOptions.listDiffInputFlags.enableDiffSlicer = enableListDiff
      listDiffCmdOptions.listDiffInputFlags.enableDiffDdmin = enableListDiff

      updateLanguageControlFlags(listDiffCmdOptions)
      updateAlgorithmControlFlags(listDiffCmdOptions)
      updateReductionControlFlags(listDiffCmdOptions)
      updateProfilingFlags(listDiffCmdOptions)
      updateOutputRefiningFlags(listDiffCmdOptions)

      return listDiffCmdOptions
    }

    fun generateTreeDiffCmdOptions(
      seedPath: Path,
      variantPath: Path,
    ): TreeDiffCmdOptions {
      val treeDiffCmdOptions = TreeDiffCmdOptions()
      treeDiffCmdOptions.inputFlags.inputFile = seedPath
      treeDiffCmdOptions.treeDiffInputFlags.variantFile = variantPath
      treeDiffCmdOptions.inputFlags.testScript = testPath
      treeDiffCmdOptions.resultOutputFlags.outputDir = workingDir

      updateLanguageControlFlags(treeDiffCmdOptions)
      updateAlgorithmControlFlags(treeDiffCmdOptions)
      updateReductionControlFlags(treeDiffCmdOptions)
      updateProfilingFlags(treeDiffCmdOptions)
      updateOutputRefiningFlags(treeDiffCmdOptions)

      return treeDiffCmdOptions
    }

    fun generateSeedCmdOptions(
      seedPath: Path,
      variantPath: Path,
    ): SeedCmdOptions {
      val seedCmdOptions = SeedCmdOptions()
      seedCmdOptions.inputFlags.inputFile = seedPath
      seedCmdOptions.seedInputFlags.variantFile = variantPath
      seedCmdOptions.inputFlags.testScript = testPath
      seedCmdOptions.resultOutputFlags.outputDir = workingDir

      updateLanguageControlFlags(seedCmdOptions)
      updateAlgorithmControlFlags(seedCmdOptions)
      updateReductionControlFlags(seedCmdOptions)
      updateProfilingFlags(seedCmdOptions)
      updateOutputRefiningFlags(seedCmdOptions)

      return seedCmdOptions
    }
  }

  data class IterationRecord(
    val iteration: Int,
    val seedSizeAfterIteration: Int,
    val variantSizeAfterIteration: Int,
    val diffSizeAfterIteration: Int,
    val seconds: Int,
  )

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    @JvmStatic
    fun printCurrentState(
      parserFacade: AbstractParserFacade,
      seedPath: Path,
      variantPath: Path,
      languageName: String,
      iteration: Int,
    ) {
      val seedSize = TokenCounterMain.countTokensOfFile(seedPath, languageName)
      val variantSize = TokenCounterMain.countTokensOfFile(variantPath, languageName)
      val listAlignment = getListAlignment(parserFacade, seedPath, variantPath)
      logger.ktInfo {
        "Iteration: $iteration, #Seed: $seedSize token(s), #Variant: $variantSize token(s), " +
          "#Insert: ${listAlignment.onlyInserts.size}, " +
          "#Delete: ${listAlignment.onlyDeletes.size}, " +
          "#Replace: ${listAlignment.onlyReplaces.size}."
      }
    }

    @JvmStatic
    private fun getListAlignment(
      parserFacade: AbstractParserFacade,
      seedPath: Path,
      variantPath: Path,
    ): ListAlignment<Token> {
      val seedTokenList = parserFacade.parseIntoTokens(seedPath)
      val variantTokenList = parserFacade.parseIntoTokens(variantPath)
      val listAlignment = ListAlignment.create(
        seedTokenList,
        variantTokenList,
        PPRDiffUtils.EQUALIZER_TOKEN,
      )
      return ListAlignment.mergeIntoReplace(listAlignment)
    }

    @JvmStatic
    fun create(
      globalContext: GlobalContext,
      cmd: CmdOptions,
      parserFacadeFactory: AbstractParserFacadeFactory,
    ): PPRMetaReductionDriver {
      return PPRMetaReductionDriver(globalContext, cmd, parserFacadeFactory)
    }
  }
}
