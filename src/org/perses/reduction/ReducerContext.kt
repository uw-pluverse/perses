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

import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.microbenchmark.ListMinimizationMicrobenchmarkWriter
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.ImmutableIntArray

class ReducerContext(
  ioManager: TokenReductionIOManager,
  val configuration: ReductionConfiguration,
  executorService: TestScriptExecutorService,
  fileUnderReduction: AbstractReductionFile<*, *>,
  val listenerManager: AsyncReductionListenerManager,
  val queryCache: AbstractQueryCache,
  val globalQueryCache: AbstractGlobalExecutionCache,
  val actionSetProfiler: AbstractActionSetProfiler,
  val sparTreeNodeFactory: SparTreeNodeFactory,
  val listMinimizerListener: AbstractListMinimizerListener,
  /** Set only in RECORD mode; shared across this reduction's drivers. Null on the normal path. */
  val listMinimizationMicrobenchmarkWriter: ListMinimizationMicrobenchmarkWriter?,
  /** The whole mutable-file set's current sizes; the active file's slot reflects the live tree. */
  private val perFileSizeMetricsSupplier: () -> PerFileSizeMetrics,
  val inputRepresentationCreator: (
    preferredParserFacade: AbstractParserFacade?,
  ) -> InputRepresentation?,
  /**
   * The currently active output-manager factory (the renderer; carries the code format). A provider,
   * not a fixed factory, because the driver may adapt the code format mid-reduction (it swaps the
   * factory it owns); reducers render through this, so they always use the active format.
   */
  private val outputManagerFactoryProvider: () -> AbstractTokenOutputManagerFactory,
) : AbstractReducerContext<TokenizedProgram, TokenReductionIOManager, ReducerContext>(
    ioManager,
    executorService,
    fileUnderReduction,
  ) {
  /** Render [program] as the file under reduction, using the active code format. Reducers call this
   * instead of the IO manager, so rendering is owned by the factory (via the context), not the IO
   * manager. */
  fun createOutputManager(program: TokenizedProgram): AbstractOutputManager =
    outputManagerFactoryProvider().createManagerFor(program)

  /** The original input rendered in the active code format. */
  fun createOutputManagerForOriginalInput(): AbstractOutputManager =
    outputManagerFactoryProvider().createOutputManagerForOriginalInput()

  /** The active code format (the one the driver currently renders through; may have been adapted). */
  fun getDefaultProgramFormat(): EnumFormatControl =
    outputManagerFactoryProvider().defaultCodeFormatControl

  /**
   * The whole-set per-file non-blank character counts the query cache stores for eviction, with
   * [candidate]'s count in the file-under-reduction slot and the siblings' current counts elsewhere.
   */
  fun perFileNonBlankCharacterCountsForCandidate(candidate: TokenizedProgram): ImmutableIntArray =
    perFileSizeMetricsSupplier()
      .replacing(
        fileUnderReduction,
        candidate.computeSize(payload = Unit, canonicalTokenCount = null),
      ).perFileNonBlankCharacterCounts()
}
