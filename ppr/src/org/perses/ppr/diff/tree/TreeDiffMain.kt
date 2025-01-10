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
package org.perses.ppr.diff.tree

import org.perses.AbstractMain
import org.perses.PersesListenerManagerCreator
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.ppr.diff.tree.TreeDiffReductionDriver.TreeDiffReductionTwinDriver
import org.perses.program.AbstractDataKind
import org.perses.program.BinaryReductionFile
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.transformToImmutableList

class TreeDiffMain(
  cmd: TreeDiffCmdOptions,
  globalContext: GlobalContext,
) : AbstractMain<TreeDiffCmdOptions, TreeDiffReductionTwinDriver, TreeDiffReductionInputs>(
  cmd,
  globalContext,
) {

  override fun createSequenceOfReductionDriverCreators(
    reductionInputs: TreeDiffReductionInputs,
  ): Sequence<ReductionDriverCreator<TreeDiffReductionTwinDriver>> {
    val parserFacade = parserFacadeFactory.getParserFacadeListForOrNull(
      reductionInputs.initiallyDeterminedMainDataKind,
    )!!.defaultParserFacade.create()
    return sequenceOf(
      ReductionDriverCreator(
        creator = {
          TreeDiffReductionDriver.create(
            globalContext,
            cmd,
            reductionInputs,
            parserFacade,
            listenerManager,
          )
        },
        descriptor = {
          """
          ${reductionInputs.initiallyDeterminedMainDataKind},
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
  ): TreeDiffReductionInputs {
    val inputFlags = cmd.treeDiffInputFlags
    return TreeDiffReductionInputs.create(
      seedPath = inputFlags.inputFile!!,
      variantPath = inputFlags.variantFile!!,
      testScriptPath = inputFlags.testScript!!,
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
      val processor = CommandLineProcessor<TreeDiffCmdOptions>(
        cmdCreator = { TreeDiffCmdOptions() },
        programName = TreeDiffMain::class.qualifiedName!!,
        args = args,
      )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      Util.useResources(
        { GlobalContext() },
        { globalContext -> TreeDiffMain(processor.cmd, globalContext) },
      ) { _, main ->
        main.run()
      }
    }
  }
}
