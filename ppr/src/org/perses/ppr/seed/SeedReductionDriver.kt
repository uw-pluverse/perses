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
package org.perses.ppr.seed

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.OutputFlagGroup
import org.perses.cmd.ReductionControlFlagGroup
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.diff.PPRDiffUtils
import org.perses.program.PersesTokenFactory
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.program.TokenizedProgramFactory
import org.perses.reduction.AbstractProgramReductionDriver
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.ReductionConfiguration
import org.perses.reduction.SparTreeWithParsability
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.ListAlignment
import java.nio.file.Path

class SeedReductionDriver private constructor(
  cmd: SeedCmdOptions,
  ioManager: TokenReductionIOManager,
  tree: SparTreeWithParsability,
  configuration: ReductionConfiguration,
  extraListeners: ImmutableList<AbstractReductionListener>,
) : AbstractProgramReductionDriver(
  cmd,
  ioManager,
  tree,
  configuration,
  extraListeners,
) {

  companion object {

    fun createReductionInputs(
      parserFacadeFactory: AbstractParserFacadeFactory,
      inputFlags: SeedCmdOptions.SeedInputFlagGroup,
    ): SeedReductionInputs {
      val seedPath: Path = inputFlags.getSourceFile()
      val variantPath: Path = inputFlags.getVariantFile()
      val languageKind = parserFacadeFactory.computeLanguageKindOrThrow(seedPath)
      val seedFile = SourceFile(seedPath, languageKind)
      val variantFile = SourceFile(variantPath, languageKind)
      val testScript = ScriptFile(inputFlags.getTestScript().toAbsolutePath())

      require(seedFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
        "The seed file and the test script should reside in the same folder. " +
          "seedFile:$seedFile, testScript:$testScript"
      }
      require(variantFile.parentFile.toAbsolutePath() == testScript.parentFile.toAbsolutePath()) {
        "The variant file and the test script should reside in the same folder. " +
          "variantFile:$variantFile, testScript:$testScript"
      }
      return SeedReductionInputs(
        testScript = testScript,
        seedFile = seedFile,
        variantFile = variantFile,
      )
    }

    private fun createIOManager(
      reductionInputs: SeedReductionInputs,
      reductionControlFlags: ReductionControlFlagGroup,
      outputFlags: OutputFlagGroup,
      listAlignment: ListAlignment<PersesTokenFactory.PersesToken>,
      lexerAtnWrapper: LexerAtnWrapper<out Lexer>,
    ): TokenReductionIOManager {
      val workingDirectory = reductionInputs.seedFile.parentFile
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
      cmd: SeedCmdOptions,
      parserFacadeFactory: AbstractParserFacadeFactory,
      extraListeners: ImmutableList<AbstractReductionListener> = ImmutableList.of(),
    ): SeedReductionDriver {
      val reductionInputs = createReductionInputs(
        parserFacadeFactory,
        cmd.seedInputFlags,
      )

      // create a parserFacade to create the SparTree
      val languageKind = reductionInputs.mainDataKind
      val parserFacade = parserFacadeFactory.createParserFacade(languageKind)

      val seedTree = createSparTree(
        reductionInputs.seedFile,
        parserFacade,
      )
      val seedPersesTokens = seedTree.programSnapshot.tokens

      // parse variant file into tokens
      val variantTokens = parserFacade.parseIntoTokens(cmd.seedInputFlags.getVariantFile())
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
        cmd,
        ioManager,
        seedTree,
        reductionConfiguration,
        extraListeners,
      )
    }
  }
}
