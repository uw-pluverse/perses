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
package org.perses.ppr.seed

import org.antlr.v4.runtime.Token
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.ppr.diff.DiffOriginalReductionInputs
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.AbstractPersesToken
import org.perses.program.AbstractReductionFile
import org.perses.program.TokenizedProgram
import org.perses.reduction.AbstractProgramReductionDriver
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.InputRepresentation
import org.perses.reduction.LanguageProfile
import org.perses.reduction.ReducerFactory
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.ListAlignment
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Path

class SeedReductionDriver private constructor(
  globalContext: GlobalContext,
  cmd: SeedCmdOptions,
  ioManager: TokenReductionIOManager,
  mainFile: AbstractReductionFile<*, *>,
  override var inputRepresentation: InputRepresentation,
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
  companion object {
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

    private fun createOutputManagerFactory(
      originalReductionInputs: DiffOriginalReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      listAlignment: ListAlignment<AbstractPersesToken>,
      lexerAtnWrapper: LexerAtnWrapper,
      shaAlgorithm: EnumShaAlgorithm,
    ): SeedOutputManagerFactory {
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
      return SeedOutputManagerFactory(
        originalReductionInputs,
        programFormatControl,
        listAlignment,
        lexerAtnWrapper,
        shaAlgorithm,
      )
    }

    @JvmStatic
    fun create(
      globalContext: GlobalContext,
      cmd: SeedCmdOptions,
      workingDirectory: Path,
      resultFolder: ReductionFolder,
      parserFacade: AbstractParserFacade,
      originalReductionInputs: DiffOriginalReductionInputs,
      listenerManager: AsyncReductionListenerManager,
      queryCache: AbstractQueryCache,
      reductionStartEvent: ReductionStartEvent,
      executorService: TestScriptExecutorService,
    ): SeedReductionDriver {
      // create a parserFacade to create the SparTree
      val seedTree =
        createInputRepresentation(
          fileToReduce = originalReductionInputs.seedFile,
          parserFacade = parserFacade,
          hideTimeStampsInLog = cmd.verbosityFlags.hideTimestamps,
          // TODO(cnsun): need to enable semantics for PPR.
          semanticsProviderCreator = null,
          enableNodeActionSetCache = cmd.cacheControlFlags.nodeActionSetCaching,
          originalReductionInputs = originalReductionInputs,
        )
      val seedPersesTokens = seedTree.tree.programSnapshot.payload.tokens

      // parse variant file into tokens
      val variantTokens =
        parserFacade
          .tokenizeFile(cmd.seedInputFlags.variantFile!!)
          .filter { it.channel == Token.DEFAULT_CHANNEL }
      val variantPersesTokens =
        TokenizedProgram
          .createForFreshAntlrLexemes(variantTokens)
          .tokens

      val listAlignment =
        ListAlignment.create(
          seedPersesTokens,
          variantPersesTokens,
          PPRDiffUtils.EQUALIZER_PERSES_TOKEN,
        )
      val ioManager =
        createIOManager(
          workingDirectory = workingDirectory,
          originalReductionInputs = originalReductionInputs,
          resultFolder = resultFolder,
        )
      // pass listAlignment to the renderer factory
      val outputManagerFactory =
        createOutputManagerFactory(
          originalReductionInputs = originalReductionInputs,
          reductionControlFlags = cmd.reductionControlFlags,
          listAlignment = listAlignment,
          lexerAtnWrapper = parserFacade.lexerAtnWrapper,
          shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
        )
      val reductionConfiguration =
        createConfiguration(
          cmd,
          parserFacade,
          outputManagerFactory.defaultCodeFormatControl,
        )

      return SeedReductionDriver(
        globalContext,
        cmd,
        ioManager,
        mainFile = originalReductionInputs.seedFile,
        seedTree,
        reductionConfiguration,
        listenerManager,
        queryCache = queryCache,
        outputManagerFactory = outputManagerFactory,
        reductionStartEvent = reductionStartEvent,
        executorService = executorService,
      )
    }
  }
}
