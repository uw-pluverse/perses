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
package org.perses.ppr.diff.list

import org.perses.AbstractMain
import org.perses.PersesListenerManagerCreator
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.program.AbstractDataKind
import org.perses.program.BinaryReductionFile
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.transformToImmutableList

class ListDiffMain(
  cmd: ListDiffCmdOptions,
  globalContext: GlobalContext,
) : AbstractMain<ListDiffCmdOptions, ListDiffReductionDriver, ListDiffReductionInputs>(
  cmd,
  globalContext,
) {

  override fun createSequenceOfReductionDriverCreators(
    reductionInputs: ListDiffReductionInputs,
  ): Sequence<ReductionDriverCreator<ListDiffReductionDriver>> {
    val parserFacade = parserFacadeFactory.getParserFacadeListForOrNull(
      reductionInputs.initiallyDeterminedMainDataKind,
    )!!.defaultParserFacade.create()
    return sequenceOf(
      ReductionDriverCreator(
        creator = {
          ListDiffReductionDriver.create(
            cmd,
            reductionInputs,
            parserFacade,
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
  ): ListDiffReductionInputs {
    val inputFlags = cmd.listDiffInputFlags
    return ListDiffReductionInputs.create(
      seedPath = inputFlags.getSourceFile(),
      variantPath = inputFlags.getVariantFile(),
      testScriptPath = inputFlags.getTestScript(),
      immutableDependencyFiles = inputFlags.deps.transformToImmutableList { path ->
        BinaryReductionFile(path, AbstractDataKind.UnknownDataKind)
      },
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
      val processor = CommandLineProcessor<ListDiffCmdOptions>(
        cmdCreator = { ListDiffCmdOptions() },
        programName = ListDiffMain::class.qualifiedName!!,
        args = args,
      )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      Util.useResources(
        { GlobalContext() },
        { globalContext -> ListDiffMain(processor.cmd, globalContext) },
      ) { _, main ->
        main.run()
      }
    }
  }
}
