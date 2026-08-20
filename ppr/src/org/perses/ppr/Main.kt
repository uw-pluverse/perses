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

import com.google.common.collect.ImmutableList
import org.perses.AbstractMain
import org.perses.HelperForPersesMain
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.diff.DiffOriginalReductionInputs
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.event.ReductionStartEvent
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor
import java.nio.file.Path

class Main(
  cmd: PPRMainCommandOptions,
  globalContext: GlobalContext,
) : AbstractMain<PPRMainCommandOptions, PPRMetaReductionDriver, DiffOriginalReductionInputs>(
    cmd,
    globalContext,
  ) {
  override fun createReductionDriver(
    originalReductionInputs: DiffOriginalReductionInputs,
    // Unused: the PPR meta-driver runs sub-mains (TreeDiff/ListDiff/Seed), each of which creates and
    // fires its own reduction lifecycle event in its own internalRun.
    reductionStartEvent: ReductionStartEvent,
  ): PPRMetaReductionDriver = PPRMetaReductionDriver.create(globalContext, cmd, parserFacadeFactory)

  override fun computeLanguageAndParserConfiguration(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): LanguageAndParserConfiguration =
    HelperForPersesMain.computeLanguageAndParserConfiguration(
      parserFacadeFactory,
      cmd.languageControlFlags,
    )

  override fun computeWorkingDirectory(): Path = originalReductionInputs.seedFile.parentFile

  override fun createAsyncReductionListenerManager(): AsyncReductionListenerManager =
    AsyncReductionListenerManager(
      listeners = ImmutableList.of(),
      synchronousMode = false,
    )

  override fun createOriginalReductionInputs(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): DiffOriginalReductionInputs {
    val inputFlags = cmd.overallInputFlags
    return DiffOriginalReductionInputs.create(
      seedPath = inputFlags.computeInputFiles().single(),
      variantPath = inputFlags.variantFile!!,
      testScriptPath = inputFlags.testScript!!,
      immutableDependencyFiles = ImmutableList.of(),
      languageKindComputer = { sourceFileAbsPath ->
        computeLanguageForFile(sourceFileAbsPath)
      },
    )
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor<PPRMainCommandOptions>(
          cmdCreator = { PPRMainCommandOptions() },
          programName = Main::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      val cmd = processor.cmd
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
