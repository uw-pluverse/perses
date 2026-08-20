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
package org.perses.reduction

import com.google.common.collect.ImmutableMap
import org.perses.PersesCommandOptions
import org.perses.grammar.AbstractParserFacade
import org.perses.program.AbstractReductionFile
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.reduction.scheduler.ReducerExecutionPlan
import org.perses.reduction.scheduler.ReducerExecutionPlan.AtomicReducerStep

/**
 * A [RegularProgramReductionDriver] that runs a single pass of just the main reducer: it overrides
 * [createReducerExecutionPlan] to return only the main-reducer step, dropping the fixpoint and all of
 * the cleanup/coarse/fine stages of the default plan. Everything else (IO manager, configuration,
 * spar tree, the [reduce] scaffolding) is inherited unchanged.
 *
 * Used by [PerFileReductionDriver] for the first sweep over a file set: each file is shrunk
 * once -- and its reduction published to the result folder -- before any file is taken to a fixpoint
 * with the full plan in the second sweep.
 */
class MainReducerOnlyOnceProgramReductionDriver private constructor(
  globalContext: GlobalContext,
  cmd: PersesCommandOptions,
  ioManager: TokenReductionIOManager,
  mainFile: AbstractReductionFile<*, *>,
  configuration: ReductionConfiguration,
  listenerManager: AsyncReductionListenerManager,
  languageProfile: LanguageProfile,
  reducerFactory: ReducerFactory,
  queryCache: AbstractQueryCache,
  outputManagerFactory: AbstractTokenOutputManagerFactory,
  reductionStartEvent: ReductionStartEvent,
  executorService: TestScriptExecutorService,
  otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
) : RegularProgramReductionDriver(
    globalContext = globalContext,
    cmd = cmd,
    ioManager = ioManager,
    mainFile = mainFile,
    configuration = configuration,
    listenerManager = listenerManager,
    languageProfile = languageProfile,
    reducerFactory = reducerFactory,
    queryCache = queryCache,
    outputManagerFactory = outputManagerFactory,
    reductionStartEvent = reductionStartEvent,
    executorService = executorService,
    otherMutableFileContents = otherMutableFileContents,
  ) {
  // Run the main reducer exactly once: ignore the cleanup step and every other pipeline stage that
  // the default plan would weave in.
  override fun createReducerExecutionPlan(
    atomicMainReducerStep: AtomicReducerStep,
    cleanupReducerStep: AtomicReducerStep,
  ): ReducerExecutionPlan = ReducerExecutionPlan(steps = atomicMainReducerStep)

  companion object {
    fun create(
      params: ReductionDriverParams,
      mainFile: AbstractReductionFile<*, *>,
      resolvedParserFacade: AbstractParserFacade,
    ): MainReducerOnlyOnceProgramReductionDriver {
      val components =
        RegularProgramReductionDriver.buildComponents(params, mainFile, resolvedParserFacade)
      return MainReducerOnlyOnceProgramReductionDriver(
        globalContext = params.globalContext,
        cmd = params.cmd,
        ioManager = components.ioManager,
        mainFile = mainFile,
        configuration = components.configuration,
        listenerManager = params.listenerManager,
        languageProfile = params.languageProfile,
        reducerFactory = params.reducerFactory,
        queryCache = params.queryCache,
        outputManagerFactory = components.outputManagerFactory,
        reductionStartEvent = params.reductionStartEvent,
        executorService = params.executorService,
        otherMutableFileContents = components.otherMutableFileContents,
      )
    }
  }
}
