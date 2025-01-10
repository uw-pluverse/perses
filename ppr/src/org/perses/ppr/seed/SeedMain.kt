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

import org.perses.AbstractMain
import org.perses.PersesListenerManagerCreator
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor

class SeedMain(
  cmd: SeedCmdOptions,
  globalContext: GlobalContext,
) : AbstractMain<SeedCmdOptions, SeedReductionDriver, SeedReductionInputs>(
  cmd,
  globalContext,
) {

  override fun createSequenceOfReductionDriverCreators(
    reductionInputs: SeedReductionInputs,
  ): Sequence<ReductionDriverCreator<SeedReductionDriver>> {
    val parserFacade = parserFacadeFactory.getParserFacadeListForOrNull(
      reductionInputs.initiallyDeterminedMainDataKind,
    )!!.defaultParserFacade.create()
    return sequenceOf(
      ReductionDriverCreator(
        creator = {
          SeedReductionDriver.create(
            globalContext,
            cmd,
            parserFacade,
            reductionInputs,
            listenerManager,
          )
        },
        descriptor = {
          """
            ${parserFacade::class}
          """.trimIndent()
        },
      ),
    )
  }

  override fun createAsyncReductionListenerManager(): AsyncReductionListenerManager {
    return PersesListenerManagerCreator.createAsyncReductionListenerManager(
      cmd,
      globalContext.fileStreamPool,
    )
  }

  override fun createReductionInputs(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): SeedReductionInputs {
    val inputFlags = cmd.seedInputFlags
    return SeedReductionInputs.create(
      seedPath = inputFlags.inputFile!!,
      variantPath = inputFlags.variantFile!!,
      testScriptPath = inputFlags.testScript!!,
      languageKindComputer = { sourceFileAbsPath ->
        parserFacadeFactory.computeLanguage(
          cmd.languageControlFlags.languageName,
          sourceFileAbsPath,
        )
      },
    )
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor = CommandLineProcessor(
        cmdCreator = { SeedCmdOptions() },
        programName = SeedMain::class.qualifiedName!!,
        args = args,
      )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      Util.useResources(
        { GlobalContext() },
        { globalContext -> SeedMain(processor.cmd, globalContext) },
      ) { _, main ->
        main.run()
      }
    }
  }
}
