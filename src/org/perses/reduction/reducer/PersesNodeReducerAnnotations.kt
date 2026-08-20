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
package org.perses.reduction.reducer

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.dyck.AdaptiveDyckParserFacade
import org.perses.grammar.dyck.PristineBraceParenthesisBracketDyckParserFacade
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.reducer.AbstractNodeReducer.IReductionQueueStrategy

/**
 * Annotations for Perses node reducers.
 */
object PersesNodeReducerAnnotations {
  /**
   * Base annotation for the [PersesNodeReducer] family: every member shares the same annotation
   * metadata and creates a single reducer, differing only in the queue strategy, the list-minimizer
   * type, and whether it reparses under a surrogate facade. [Mimir] uses a different reducer class and
   * so stays separate.
   */
  open class NodeReducerAnnotation(
    shortName: String,
    private val queueStrategy: IReductionQueueStrategy,
    private val listMinimizerType: EnumListMinimizerType? = null,
    private val facadeSelector: ((AbstractParserFacade) -> AbstractParserFacade)? = null,
  ) : ReducerAnnotation(
      shortName = shortName,
      description = "",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
    final override fun create(
      reducerContext: ReducerContext,
    ): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of<AbstractSparTreeReducer>(
        PersesNodeReducer(
          reducerAnnotation = this,
          reducerContext = reducerContext,
          reductionQueueStrategy = queueStrategy,
          defaultListMinimizerType = listMinimizerType,
          preferredParserFacade =
            facadeSelector?.invoke(reducerContext.configuration.canonicalParserFacade),
        ),
      )
  }

  /** Perses node reducer, with dfs delta debugging  */
  object Dfs : NodeReducerAnnotation(
    shortName = "node-dfs",
    queueStrategy = IReductionQueueStrategy.FOR_REGULAR_QUEUE,
  )

  /** Perses node reducer, with bfs delta debugging  */
  object Bfs : NodeReducerAnnotation(
    shortName = "node-bfs",
    queueStrategy = IReductionQueueStrategy.FOR_REGULAR_QUEUE,
    listMinimizerType = EnumListMinimizerType.BFS,
  )

  /** Perses node reducer, with prioritized dfs delta debugging  */
  object PrioritizedDfs : NodeReducerAnnotation(
    shortName = "node_priority",
    queueStrategy = IReductionQueueStrategy.FOR_PRIORITY_QUEUE,
  )

  /** Perses node reducer, with prioritized bfs delta debugging  */
  object PrioritizedBfs : NodeReducerAnnotation(
    shortName = "node_priority-bfs",
    queueStrategy = IReductionQueueStrategy.FOR_PRIORITY_QUEUE,
    listMinimizerType = EnumListMinimizerType.BFS,
  )

  object Mimir : ReducerAnnotation(
    shortName = "mimir",
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext) =
      ImmutableList.of<AbstractSparTreeReducer>(
        MimirNodeReducer(
          reducerAnnotation = this,
          reducerContext = reducerContext,
          reductionQueueStrategy = IReductionQueueStrategy.FOR_PRIORITY_QUEUE,
        ),
      )
  }

  /**
   * Perses node reducer that reparses the file under a Dyck grammar before reducing. The Dyck tree
   * nests balanced delimiter groups (e.g. a `{ ... }` pocket the real grammar could not place), so the
   * inherited node reduction can delete such a group as a single subtree -- structure the
   * tolerant-real spine leaves flat. See internal_doc/error_tolerant_multi_grammar_passes.md.
   */
  object Dyck : NodeReducerAnnotation(
    shortName = "dyck_node_reducer",
    queueStrategy = IReductionQueueStrategy.FOR_PRIORITY_QUEUE,
    facadeSelector = ::dyckFacadeFor,
  )

  /**
   * The line-oblivious counterpart of [Dyck]: it reparses the file under the *pristine* Dyck grammar,
   * which nests balanced delimiter groups purely by brackets with no per-line grouping. The inherited
   * node reduction can then delete such a group as a single subtree, without the line units the
   * line-aware Dyck grammar imposes.
   */
  object PristineDyck : NodeReducerAnnotation(
    shortName = "pristine_dyck_node_reducer",
    queueStrategy = IReductionQueueStrategy.FOR_PRIORITY_QUEUE,
    facadeSelector = ::pristineDyckFacadeFor,
  )

  /**
   * An adaptive Dyck facade over the file's real lexer: it picks the delimiter kinds per file, so a
   * program whose braces (or parentheses, or brackets) do not nest still yields a Dyck tree, built
   * from the kinds that do. A fixed brace+parenthesis+bracket facade has no parse for such a file at
   * all, and this pass runs precisely on the files the real grammar already rejected, where an
   * unbalanced delimiter is common.
   *
   * This pass exists to reduce under the Dyck grammar, so it builds the Dyck facade directly rather
   * than walking the tolerant fallback ladder (which would descend to Line once past the Dyck rungs).
   */
  @VisibleForTesting
  fun dyckFacadeFor(canonical: AbstractParserFacade): AdaptiveDyckParserFacade =
    AdaptiveDyckParserFacade(canonical.realLexerClass)

  /**
   * The pristine counterpart of [dyckFacadeFor], still on a fixed brace+parenthesis+bracket
   * configuration.
   */
  @VisibleForTesting
  fun pristineDyckFacadeFor(
    canonical: AbstractParserFacade,
  ): PristineBraceParenthesisBracketDyckParserFacade =
    PristineBraceParenthesisBracketDyckParserFacade(canonical.realLexerClass)
}
