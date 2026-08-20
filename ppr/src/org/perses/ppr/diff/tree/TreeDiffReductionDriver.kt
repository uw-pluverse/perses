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
package org.perses.ppr.diff.tree

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.ppr.diff.DiffOriginalReductionInputs
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.AbstractReductionFile
import org.perses.reduction.AbstractProgramReductionDriver
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.IReductionDriver
import org.perses.reduction.InputRepresentation
import org.perses.reduction.LanguageProfile
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerFactory
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.ktInfo
import java.nio.file.Path

class TreeDiffReductionDriver private constructor(
  globalContext: GlobalContext,
  cmd: TreeDiffCmdOptions,
  ioManager: TokenReductionIOManager,
  mainFile: AbstractReductionFile<*, *>,
  override var inputRepresentation: InputRepresentation,
  private val treeDiff: ImmutableList<AbstractSparTreeNode>,
  configuration: ReductionConfiguration,
  listenerManager: AsyncReductionListenerManager,
  queryCache: AbstractQueryCache,
  outputManagerFactory: AbstractTokenOutputManagerFactory,
  reductionStartEvent: ReductionStartEvent,
  executorService: TestScriptExecutorService,
) : AbstractProgramReductionDriver(
    globalContext = globalContext,
    cmd = cmd,
    ioManager = ioManager,
    mainFile = mainFile,
    configuration = configuration,
    listenerManager = listenerManager,
    languageProfile = LanguageProfile.DEFAULT,
    reducerFactory = ReducerFactory.DEFAULT,
    queryCache = queryCache,
    outputManagerFactory = outputManagerFactory,
    reductionStartEvent = reductionStartEvent,
    executorService = executorService,
  ) {
  override fun createMainReducerCreator(): ReducerAnnotation =
    CustomizedTreeNodesReducer.ExtendedReducerAnnotation(treeDiff)

  companion object {
    val logger: FluentLogger = FluentLogger.forEnclosingClass()

    private fun createIOManager(
      workingDirectory: Path,
      originalReductionInputs: DiffOriginalReductionInputs,
      resultFolder: ReductionFolder,
    ): TokenReductionIOManager =
      TokenReductionIOManager(
        workingDirectory,
        originalReductionInputs,
        // The result folder is already populated with the original inputs by the caller.
        resultFolder = resultFolder,
      )

    // The twin reduction needs one renderer factory per role, each bound to its represented file: the
    // seed pass renders the seed file from its program (and the variant file from the variant tree),
    // and vice versa.
    private fun createOutputManagerFactory(
      originalReductionInputs: DiffOriginalReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      seedInputRepresentation: InputRepresentation,
      variantInputRepresentation: InputRepresentation,
      lexerAtnWrapper: LexerAtnWrapper,
      shaAlgorithm: EnumShaAlgorithm,
      mainFile: AbstractReductionFile<*, *>,
    ): TreeDiffOutputManagerFactory {
      val languageKind = originalReductionInputs.initiallyDeterminedMainDataKind
      val programFormatControl =
        reductionControlFlags.codeFormat.let { codeFormat ->
          if (codeFormat != null) {
            check(languageKind.isCodeFormatAllowed(codeFormat)) {
              "$codeFormat is not allowed for language $languageKind"
            }
            codeFormat
          } else {
            languageKind.defaultCodeFormatControl
          }
        }
      return TreeDiffOutputManagerFactory(
        originalReductionInputs,
        programFormatControl,
        seedInputRepresentation,
        variantInputRepresentation,
        fileRepresentedByProgram = mainFile,
        lexerAtnWrapper,
        shaAlgorithm,
      )
    }

    @JvmStatic
    fun create(
      globalContext: GlobalContext,
      cmd: TreeDiffCmdOptions,
      workingDirectory: Path,
      resultFolder: ReductionFolder,
      originalReductionInputs: DiffOriginalReductionInputs,
      parserFacade: AbstractParserFacade,
      listenerManager: AsyncReductionListenerManager,
      queryCache: AbstractQueryCache,
      reductionStartEvent: ReductionStartEvent,
      executorService: TestScriptExecutorService,
    ): TreeDiffReductionTwinDriver {
      val seedInputRepresentation =
        createInputRepresentation(
          originalReductionInputs.seedFile,
          parserFacade,
          hideTimeStampsInLog = cmd.verbosityFlags.hideTimestamps,
          // TODO(cnsun): need to enable semantics for PPR.
          semanticsProviderCreator = null,
          enableNodeActionSetCache = cmd.cacheControlFlags.nodeActionSetCaching,
          originalReductionInputs = originalReductionInputs,
        )

      val variantInputRepresentation =
        createInputRepresentation(
          originalReductionInputs.variantFile,
          parserFacade,
          hideTimeStampsInLog = cmd.verbosityFlags.hideTimestamps,
          // TODO(cnsun): need to enable semantics for PPR.
          semanticsProviderCreator = null,
          enableNodeActionSetCache = cmd.cacheControlFlags.nodeActionSetCaching,
          originalReductionInputs = originalReductionInputs,
        )

      val realDiffNodesOnBothTrees =
        PPRDiffUtils.computeRealDiffNodesOnBothTrees(
          seedInputRepresentation.tree,
          variantInputRepresentation.tree,
        )
      val realDiffNodesOnSeed =
        realDiffNodesOnBothTrees.diffNodesOnSeed.also { nodes ->
          check(nodes.all { node -> !node.isPermanentlyDeleted }) {
            nodes
          }
        }
      val realDiffNodesOnVariant =
        realDiffNodesOnBothTrees.diffNodesOnVariant.also { nodes ->
          check(nodes.all { node -> !node.isPermanentlyDeleted }) {
            nodes
          }
        }

      logger.ktInfo { "${realDiffNodesOnSeed.size} real diff nodes on seed." }
      logger.ktInfo { "${realDiffNodesOnVariant.size} real diff nodes on variant." }

      // The twin reduction needs one IO manager per role, each bound to its represented file: the
      // seed pass renders the seed file from its program (and the variant file from the variant
      // tree), and vice versa. They share the same result folder and query cache.
      val seedIOManager =
        createIOManager(
          workingDirectory = workingDirectory,
          originalReductionInputs = originalReductionInputs,
          resultFolder = resultFolder,
        )
      val variantIOManager =
        createIOManager(
          workingDirectory = workingDirectory,
          originalReductionInputs = originalReductionInputs,
          resultFolder = resultFolder,
        )
      val seedOutputManagerFactory =
        createOutputManagerFactory(
          originalReductionInputs = originalReductionInputs,
          reductionControlFlags = cmd.reductionControlFlags,
          seedInputRepresentation = seedInputRepresentation,
          variantInputRepresentation = variantInputRepresentation,
          lexerAtnWrapper = parserFacade.lexerAtnWrapper,
          shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
          mainFile = originalReductionInputs.seedFile,
        )
      val variantOutputManagerFactory =
        createOutputManagerFactory(
          originalReductionInputs = originalReductionInputs,
          reductionControlFlags = cmd.reductionControlFlags,
          seedInputRepresentation = seedInputRepresentation,
          variantInputRepresentation = variantInputRepresentation,
          lexerAtnWrapper = parserFacade.lexerAtnWrapper,
          shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
          mainFile = originalReductionInputs.variantFile,
        )

      val reductionConfiguration =
        createConfiguration(
          cmd,
          parserFacade,
          seedOutputManagerFactory.defaultCodeFormatControl,
        )

      return TreeDiffReductionTwinDriver(
        ImmutableList.of(
          TreeDiffReductionDriver(
            globalContext = globalContext,
            cmd = cmd,
            ioManager = seedIOManager,
            mainFile = originalReductionInputs.seedFile,
            inputRepresentation = seedInputRepresentation,
            treeDiff = realDiffNodesOnSeed,
            configuration = reductionConfiguration,
            listenerManager = listenerManager,
            queryCache = queryCache,
            outputManagerFactory = seedOutputManagerFactory,
            reductionStartEvent = reductionStartEvent,
            executorService = executorService,
          ),
          TreeDiffReductionDriver(
            globalContext = globalContext,
            cmd = cmd,
            ioManager = variantIOManager,
            mainFile = originalReductionInputs.variantFile,
            inputRepresentation = variantInputRepresentation,
            treeDiff = realDiffNodesOnVariant,
            configuration = reductionConfiguration,
            listenerManager = listenerManager,
            queryCache = queryCache,
            outputManagerFactory = variantOutputManagerFactory,
            reductionStartEvent = reductionStartEvent,
            executorService = executorService,
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
