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
package org.perses.ppr

import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Token
import org.perses.TokenCounterMain
import org.perses.delta.EnumDeltaDebuggerType
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.ppr.diff.list.ListDiffMain
import org.perses.ppr.diff.tree.TreeDiffMain
import org.perses.ppr.seed.SeedMain
import org.perses.reduction.IReductionDriver
import org.perses.util.ListAlignment
import org.perses.util.Util
import org.perses.util.ktInfo
import java.nio.file.Path

class PPRMetaReductionDriver private constructor(
  val cmd: CmdOptions,
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
    val seedPath = Util.copyFileToDirectory(cmd.overallInputFlags.getSourceFile(), workingDir)
    val variantPath = Util.copyFileToDirectory(cmd.overallInputFlags.variantFile!!, workingDir)
    val testPath = Util.copyFileToDirectory(cmd.overallInputFlags.getTestScript(), workingDir)

    val languageKind = parserFacadeFactory.computeLanguageKindWithFileName(seedPath)
    val parserFacade = parserFacadeFactory.createParserFacade(languageKind!!)

    var seedSizeBefore: Int
    var variantSizeBefore: Int
    val initialSeedSize = TokenCounterMain.countTokensOfFile(seedPath)
    var seedSizeCurrent = initialSeedSize
    val initialVariantSize = TokenCounterMain.countTokensOfFile(variantPath)
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
        printCurrentState(parserFacade, seedPath, variantPath, iteration)
        TreeDiffMain.main(
          flagGenerator.generate(seedPath, variantPath, enableListDiff = false),
        )
      }

      if (cmd.overallInputFlags.minLDiff) {
        logger.ktInfo { "Start list-based diff reduction on seed." }
        printCurrentState(parserFacade, seedPath, variantPath, iteration)
        ListDiffMain.main(
          flagGenerator.generate(seedPath, variantPath, enableListDiff = true),
        )
        if (cmd.overallInputFlags.mirror) {
          logger.ktInfo { "Start list-based diff reduction on variant." }
          printCurrentState(parserFacade, seedPath, variantPath, iteration)
          ListDiffMain.main(
            flagGenerator.generate(variantPath, seedPath, enableListDiff = true),
          )
        }
      }

      if (cmd.overallInputFlags.minCommonality) {
        logger.ktInfo { "Start commonality reduction, from seed to variant." }
        printCurrentState(parserFacade, seedPath, variantPath, iteration)
        SeedMain.main(
          flagGenerator.generate(seedPath, variantPath, enableListDiff = false),
        )
        if (cmd.overallInputFlags.mirror) {
          logger.ktInfo { "Start commonality reduction, from variant to seed." }
          printCurrentState(parserFacade, seedPath, variantPath, iteration)
          SeedMain.main(
            flagGenerator.generate(variantPath, seedPath, enableListDiff = false),
          )
        }
      }

      seedSizeCurrent = TokenCounterMain.countTokensOfFile(seedPath)
      variantSizeCurrent = TokenCounterMain.countTokensOfFile(variantPath)
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
  }

  override fun close() {}

  class FlagGenerator(
    private val cmd: CmdOptions,
    private val testPath: Path,
    val workingDir: Path,
  ) {

    fun generate(seedPath: Path, variantPath: Path, enableListDiff: Boolean): Array<String> {
      val flagList = mutableListOf(
        "--input",
        seedPath.toString(),
        "--variant",
        variantPath.toString(),
        "--test",
        testPath.toString(),
        "--output-dir",
        workingDir.toString(),
        "--reparse-each-iteration",
        "false",
        "--fixpoint",
        "false",
        "--default-delta-debugger-for-kleene",
        EnumDeltaDebuggerType.PERSES_VARIANT_OF_PRISTINE.name,
        "--call-formatter",
        cmd.outputRefiningFlags.callFormatter.toString(),
      )
      if (cmd.reductionControlFlags.codeFormat != null) {
        flagList.add("--code-format")
        flagList.add(cmd.reductionControlFlags.codeFormat.toString())
      }
      if (cmd.algorithmControlFlags.reductionAlgorithm != null) {
        flagList.add("--alg")
        flagList.add(cmd.algorithmControlFlags.reductionAlgorithm.toString())
      }
      if (cmd.profilingFlags.progressDumpFile != null) {
        flagList.add("--progress-dump-file")
        flagList.add(cmd.profilingFlags.progressDumpFile.toString())
      }
      if (cmd.profilingFlags.appendToProgressDumpFile) {
        flagList.add("--append-to-progress-dump-file")
        flagList.add("true")
      }
      if (enableListDiff) {
        flagList.add("--enable-diff-slicer")
        flagList.add(cmd.overallInputFlags.enableDiffSlicer.toString())
        flagList.add("--enable-diff-ddmin")
        flagList.add(cmd.overallInputFlags.enableDiffDdmin.toString())
      }
      flagList.add("--threads")
      flagList.add(cmd.reductionControlFlags.getNumOfThreads().toString())
      return flagList.toTypedArray()
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
      iteration: Int,
    ) {
      val seedSize = TokenCounterMain.countTokensOfFile(seedPath)
      val variantSize = TokenCounterMain.countTokensOfFile(variantPath)
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
      cmd: CmdOptions,
      parserFacadeFactory: AbstractParserFacadeFactory,
    ): PPRMetaReductionDriver {
      return PPRMetaReductionDriver(cmd, parserFacadeFactory)
    }
  }
}
