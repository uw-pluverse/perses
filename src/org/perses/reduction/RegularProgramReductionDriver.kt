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
package org.perses.reduction

import org.perses.CommandOptions
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.cmd.OutputFlagGroup
import org.perses.grammar.AbstractParserFacade
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import org.perses.program.SourceFile
import org.perses.reduction.io.AbstractSingleFileReductionInputs
import org.perses.reduction.io.token.RegularOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.hashing.EnumShaAlgorithm

/**
 * This is the main entry to invoke Perses reducer. It does not have a main, but is the main entry
 * as a reduction library.
 */
class RegularProgramReductionDriver private constructor(
  globalContext: GlobalContext,
  cmd: CommandOptions,
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
    fun createIOManager(
      reductionInputs: AbstractSingleFileReductionInputs<LanguageKind, SourceFile, *>,
      outputFlags: OutputFlagGroup,
      codeFormatControl: EnumFormatControl,
      lexerAtnWrapper: LexerAtnWrapper,
      shaAlgorithm: EnumShaAlgorithm,
    ): TokenReductionIOManager {
      val workingDirectory = reductionInputs.mainFile.parentFile
      return TokenReductionIOManager(
        workingDirectory,
        reductionInputs,
        outputManagerFactory =
          RegularOutputManagerFactory(
            reductionInputs,
            codeFormatControl,
            lexerAtnWrapper,
            shaAlgorithm = shaAlgorithm,
          ),
        outputDirectory = outputFlags.outputDir,
      )
    }

    fun create(
      globalContext: GlobalContext,
      cmd: CommandOptions,
      reductionInputs: AbstractSingleFileReductionInputs<LanguageKind, SourceFile, *>,
      parserFacade: AbstractParserFacade,
      codeFormatControl: EnumFormatControl,
      listenerManager: AsyncReductionListenerManager,
      shaAlgorithm: EnumShaAlgorithm,
    ): RegularProgramReductionDriver {
      val ioManager =
        createIOManager(
          reductionInputs,
          cmd.resultOutputFlags,
          codeFormatControl,
          parserFacade.lexerAtnWrapper,
          shaAlgorithm,
        )
      val reductionConfiguration =
        createConfiguration(
          cmd,
          parserFacade,
          ioManager.getDefaultProgramFormat(),
        )
      val tree =
        createSparTree(
          fileToReduce = reductionInputs.mainFile,
          parserFacade = reductionConfiguration.parserFacade,
          hideTimeStampsInLog = cmd.verbosityFlags.hideTimestamps,
        )

      return RegularProgramReductionDriver(
        globalContext,
        cmd,
        ioManager,
        tree,
        reductionConfiguration,
        listenerManager,
      )
    }
  }
}
