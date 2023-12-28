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
package org.perses.ppr.diff.tree

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Lexer
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.OutputFlagGroup
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.AbstractProgramReductionDriver
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.IReductionDriver
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.SparTreeWithParsability
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.ktInfo
import java.nio.file.Path

class TreeDiffReductionDriver private constructor(
  cmd: TreeDiffCmdOptions,
  ioManager: TokenReductionIOManager,
  sparTreeToBeReduced: SparTreeWithParsability,
  private val treeDiff: ImmutableList<AbstractSparTreeNode>,
  configuration: ReductionConfiguration,
  extraListeners: ImmutableList<AbstractReductionListener>,
) : AbstractProgramReductionDriver(
  cmd,
  ioManager,
  tree = sparTreeToBeReduced,
  configuration,
  extraListeners,
) {

  override fun createMainReducer(): ReducerAnnotation {
    return CustomizedTreeNodesReducer.Companion.ExtendedReducerAnnotation(treeDiff)
  }

  companion object {
    val logger: FluentLogger = FluentLogger.forEnclosingClass()

    private fun createReductionInputs(
      parserFacadeFactory: AbstractParserFacadeFactory,
      inputFlags: TreeDiffCmdOptions.TreeDiffInputFlagGroup,
    ): TreeDiffReductionInputs {
      val absoluteSeedFilePath: Path = inputFlags.getSourceFile().toAbsolutePath()
      val absoluteVariantFilePath: Path = inputFlags.getVariantFile().toAbsolutePath()
      val languageKind = parserFacadeFactory.computeLanguageKindOrThrow(absoluteSeedFilePath)
      val seedFile = SourceFile(absoluteSeedFilePath, languageKind)
      val variantFile = SourceFile(absoluteVariantFilePath, languageKind)
      val testScript = ScriptFile(inputFlags.getTestScript().toAbsolutePath())

      require(seedFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
        "The seed file and the test script should reside in the same folder. " +
          "seedFile:$seedFile, testScript:$testScript"
      }
      require(variantFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
        "The variant file and the test script should reside in the same folder. " +
          "variantFile:$variantFile, testScript:$testScript"
      }
      return TreeDiffReductionInputs(
        testScript = testScript,
        seedFile = seedFile,
        variantFile = variantFile,
      )
    }

    private fun createIOManager(
      reductionInputs: TreeDiffReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      outputFlags: OutputFlagGroup,
      sparTreeToBeKept: SparTreeWithParsability,
      lexerAtnWrapper: LexerAtnWrapper<out Lexer>,
    ): TokenReductionIOManager {
      val workingDirectory = reductionInputs.rootDirectory
      val languageKind = reductionInputs.mainDataKind
      val programFormatControl = reductionControlFlags.codeFormat.let { codeFormat ->
        if (codeFormat != null) {
          check(languageKind.isCodeFormatAllowed(codeFormat)) {
            "$codeFormat is not allowed for language $languageKind"
          }
          codeFormat
        } else {
          languageKind.defaultCodeFormatControl
        }
      }
      return TokenReductionIOManager(
        workingDirectory,
        reductionInputs,
        outputManagerFactory = TreeDiffOutputManagerFactory(
          reductionInputs,
          programFormatControl,
          sparTreeToBeKept,
          lexerAtnWrapper,
        ),
        outputDirectory = outputFlags.outputDir,
      )
    }

    @JvmStatic
    fun create(
      cmd: TreeDiffCmdOptions,
      parserFacadeFactory: AbstractParserFacadeFactory,
      extraListeners: ImmutableList<AbstractReductionListener> = ImmutableList.of(),
    ): TreeDiffReductionTwinDriver {
      val reductionInputs = createReductionInputs(
        parserFacadeFactory,
        cmd.treeDiffInputFlags,
      )

      val languageKind = reductionInputs.mainDataKind
      val parserFacade = parserFacadeFactory.createParserFacade(languageKind)

      val seedSparTree = createSparTree(
        reductionInputs.seedFile,
        parserFacade,
      )

      val variantSparTree = createSparTree(
        reductionInputs.variantFile,
        parserFacade,
      )

      val realDiffNodesOnBothTrees = PPRDiffUtils.computeRealDiffNodesOnBothTrees(
        seedSparTree.getTreeRegardlessOfParsability(),
        variantSparTree.getTreeRegardlessOfParsability(),
      )
      val realDiffNodesOnSeed = realDiffNodesOnBothTrees.diffNodesOnSeed
      val realDiffNodesOnVariant = realDiffNodesOnBothTrees.diffNodesOnVariant

      logger.ktInfo { "${realDiffNodesOnSeed.size} real diff nodes on seed." }
      logger.ktInfo { "${realDiffNodesOnVariant.size} real diff nodes on variant." }

      val ioManagerForSeedReduction = createIOManager(
        reductionInputs,
        cmd.reductionControlFlags,
        cmd.resultOutputFlags,
        variantSparTree,
        parserFacade.lexerAtnWrapper,
      )

      val ioManagerForVariantReduction = createIOManager(
        reductionInputs.copyBySwappingSeedAndVariant(),
        cmd.reductionControlFlags,
        cmd.resultOutputFlags,
        seedSparTree,
        parserFacade.lexerAtnWrapper,
      )

      val reductionConfigurationForSeed = createConfiguration(
        cmd,
        parserFacade,
        ioManagerForSeedReduction.getDefaultProgramFormat(),
      )

      val reductionConfigurationForVariant = createConfiguration(
        cmd,
        parserFacade,
        ioManagerForVariantReduction.getDefaultProgramFormat(),
      )

      return TreeDiffReductionTwinDriver(
        ImmutableList.of(
          TreeDiffReductionDriver(
            cmd,
            ioManagerForSeedReduction,
            seedSparTree,
            realDiffNodesOnSeed,
            reductionConfigurationForSeed,
            extraListeners,
          ),
          TreeDiffReductionDriver(
            cmd,
            ioManagerForVariantReduction,
            variantSparTree,
            realDiffNodesOnVariant,
            reductionConfigurationForVariant,
            extraListeners,
          ),
        ),
      )
    }
  }

  class TreeDiffReductionTwinDriver(
    private val treeDiffReductionDrivers: ImmutableList<TreeDiffReductionDriver>,
  ) : IReductionDriver {

    override fun reduce() {
      treeDiffReductionDrivers.forEach { it.reduce() }
    }

    override fun close() {
      treeDiffReductionDrivers.forEach { it.close() }
    }
  }
}
