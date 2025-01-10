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
package org.perses.ppr.seed

import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.OutputFlagGroup
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractProgramReductionDriver
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.SparTreeWithParsability
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.ListAlignment

class SeedReductionDriver private constructor(
  globalContext: GlobalContext,
  cmd: SeedCmdOptions,
  ioManager: TokenReductionIOManager,
  tree: SparTreeWithParsability,
  configuration: ReductionConfiguration,
  listenerManager: AsyncReductionListenerManager,
) : AbstractProgramReductionDriver(
  globalContext,
  cmd,
  ioManager,
  tree,
  configuration,
  listenerManager,
) {

  companion object {

    private fun createIOManager(
      reductionInputs: SeedReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      outputFlags: OutputFlagGroup,
      listAlignment: ListAlignment<PersesTokenFactory.PersesToken>,
      lexerAtnWrapper: LexerAtnWrapper<out Lexer>,
    ): TokenReductionIOManager {
      val workingDirectory = reductionInputs.seedFile.parentFile
      val languageKind = reductionInputs.initiallyDeterminedMainDataKind
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
        outputManagerFactory = SeedOutputManagerFactory(
          reductionInputs,
          programFormatControl,
          listAlignment,
          lexerAtnWrapper,
        ),
        outputDirectory = outputFlags.outputDir,
      )
    }

    @JvmStatic
    fun create(
      globalContext: GlobalContext,
      cmd: SeedCmdOptions,
      parserFacade: AbstractParserFacade,
      reductionInputs: SeedReductionInputs,
      listenerManager: AsyncReductionListenerManager,
    ): SeedReductionDriver {
      // create a parserFacade to create the SparTree
      val languageKind = reductionInputs.initiallyDeterminedMainDataKind

      val seedTree = createSparTree(
        reductionInputs.seedFile,
        parserFacade,
      )
      val seedPersesTokens = seedTree.programSnapshot.tokens

      // parse variant file into tokens
      val variantTokens = parserFacade.parseIntoTokens(cmd.seedInputFlags.variantFile!!)
        .filter { it.channel == Token.DEFAULT_CHANNEL }
      val variantTokenizedProgramFactory = TokenizedProgramFactory
        .createFactory(variantTokens, languageKind)
      val variantPersesTokens = variantTokenizedProgramFactory.create(variantTokens).tokens

      val listAlignment = ListAlignment.create(
        seedPersesTokens,
        variantPersesTokens,
        PPRDiffUtils.EQUALIZER_TOKEN,
      )
      // pass listAlignment to IOManager
      val ioManager = createIOManager(
        reductionInputs,
        cmd.reductionControlFlags,
        cmd.resultOutputFlags,
        listAlignment,
        parserFacade.lexerAtnWrapper,
      )
      val reductionConfiguration = createConfiguration(
        cmd,
        parserFacade,
        ioManager.getDefaultProgramFormat(),
      )

      return SeedReductionDriver(
        globalContext,
        cmd,
        ioManager,
        seedTree,
        reductionConfiguration,
        listenerManager,
      )
    }
  }
}
