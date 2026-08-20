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

import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Token
import org.perses.TokenCounterMain
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.ppr.diff.list.ListDiffMain
import org.perses.ppr.diff.tree.TreeDiffMain
import org.perses.ppr.seed.SeedMain
import org.perses.reduction.GlobalContext
import org.perses.reduction.IReductionDriver
import org.perses.util.ListAlignment
import org.perses.util.Util
import org.perses.util.ktInfo
import java.nio.file.Path

class PPRMetaReductionDriver private constructor(
  val globalContext: GlobalContext,
  val cmd: PPRMainCommandOptions,
  val parserFacadeFactory: AbstractParserFacadeFactory,
) : IReductionDriver {
  override fun reduce() {
    // create a working folder
    val workingDir = cmd.resultOutputFlags.outputDir
    check(workingDir != null) {
      "Should specify the outputDir"
    }
    Util.ensureDirExists(workingDir)

    // compute new path in the working folder, and copy inputs to the path
    val seedPath =
      Util.copyFileToDirectory(
        cmd.overallInputFlags.computeInputFiles().single(),
        workingDir,
      )
    val variantPath = Util.copyFileToDirectory(cmd.overallInputFlags.variantFile!!, workingDir)
    val testPath = Util.copyFileToDirectory(cmd.overallInputFlags.getTestScript(), workingDir)
    val filesToBeKept = Util.listFilesInFolder(workingDir)

    // TODO(cnsun): need to move this logic to the Main class.
    val languageKind =
      parserFacadeFactory.computeLanguage(
        specifiedLanguageName = cmd.languageControlFlags.languageName,
        designatedParserFacadeClassName = cmd.languageControlFlags.designatedParserFacadeClassName,
        sourceFileAbsPath = seedPath,
      )

    val parserFacade =
      parserFacadeFactory
        .getParserFacadeListForOrNull(languageKind)!!
        .defaultParserFacade
        .create()

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
          cmd = flagGenerator.generateTreeDiffCmdOptions(seedPath, variantPath),
          globalContext = globalContext,
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
      val seedTokenList = parserFacade.tokenizeFile(seedPath)
      val variantTokenList = parserFacade.tokenizeFile(variantPath)
      val listAlignment =
        ListAlignment.create(
          seedTokenList,
          variantTokenList,
          PPRDiffUtils.EQUALIZER_ANTLR_TOKEN,
        )
      return ListAlignment.mergeIntoReplace(listAlignment)
    }

    @JvmStatic
    fun create(
      globalContext: GlobalContext,
      cmd: PPRMainCommandOptions,
      parserFacadeFactory: AbstractParserFacadeFactory,
    ): PPRMetaReductionDriver = PPRMetaReductionDriver(globalContext, cmd, parserFacadeFactory)
  }
}
