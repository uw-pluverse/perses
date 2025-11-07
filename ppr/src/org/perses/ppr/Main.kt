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

import com.google.common.collect.ImmutableList
import org.perses.AbstractMain
import org.perses.HelperForPersesMain
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.seed.SeedReductionInputs
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor

class Main(
  cmd: CmdOptions,
  globalContext: GlobalContext,
) : AbstractMain<CmdOptions, PPRMetaReductionDriver, SeedReductionInputs>(
    cmd,
    globalContext,
  ) {
  override fun createSequenceOfReductionDriverCreators(
    reductionInputs: SeedReductionInputs,
  ): Sequence<ReductionDriverCreator<PPRMetaReductionDriver>> =
    sequenceOf(
      ReductionDriverCreator(
        creator = {
          PPRMetaReductionDriver.create(globalContext, cmd, parserFacadeFactory)
        },
        descriptor = { "" },
      ),
    )

  override fun computeLanguageAndParserConfiguration(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): LanguageAndParserConfiguration =
    HelperForPersesMain.computeLanguageAndParserConfiguration(
      parserFacadeFactory,
      cmd.languageControlFlags,
    )

  override fun createAsyncReductionListenerManager(): AsyncReductionListenerManager =
    AsyncReductionListenerManager(listeners = ImmutableList.of())

  override fun createReductionInputs(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): SeedReductionInputs {
    val inputFlags = cmd.overallInputFlags
    return SeedReductionInputs.create(
      seedPath = inputFlags.inputFile!!,
      variantPath = inputFlags.variantFile!!,
      testScriptPath = inputFlags.testScript!!,
      languageKindComputer = { sourceFileAbsPath ->
        computeLanguageForFile(sourceFileAbsPath)
      },
    )
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor<CmdOptions>(
          cmdCreator = { CmdOptions() },
          programName = Main::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      val cmd = processor.cmd
      // The token reducer is not compatible with PPR, so we need to disable TRec.
      cmd.trecFlags.enableTRec = false
      // TODO(cnsun): need to have a systematic way to disable flags and copy flags for PPR.
      cmd.latraFlags.enableLatra = false
      Util.useResources(
        {
          GlobalContext(
            enableGlobalCache = cmd.cacheControlFlags.enableGlobalCache,
            globalCacheFile = cmd.cacheControlFlags.globalCacheFile,
            pathToSaveUpdatedGlobalCache = cmd.cacheControlFlags.pathToSaveUpdatedGlobalCache,
            shaAlgorithm = cmd.cacheControlFlags.defaultShaAlgorithm,
          )
        },
        { globalContext -> Main(cmd, globalContext) },
      ) { _, main ->
        main.run()
      }
    }
  }
}
