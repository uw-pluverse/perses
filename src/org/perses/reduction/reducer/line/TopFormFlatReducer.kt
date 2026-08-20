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
package org.perses.reduction.reducer.line

import com.google.common.base.Objects
import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.dyck.AbstractDyckParserFacade
import org.perses.grammar.flattokenlist.FlatTokenListParserFacade
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.ContextDescription
import org.perses.util.toImmutableList

/**
 * Berkeley delta's reduction, expressed in Perses: [TopFormFlatChunker] groups the tokens into the
 * chunks `topformflat` would have put on separate lines at a given brace-nesting level, and the
 * list minimizer deletes chunks.
 *
 * One reducer instance handles one nesting level. Sweeping the levels coarse-to-fine is what gives
 * delta its power -- level 0 deletes whole top-level forms, higher levels the statements inside
 * them -- so the levels are registered as separate algorithms plus a composite that runs the whole
 * ladder; see [CompositeReducerAnnotation].
 *
 * [computeDefaultListMinimizerType] is deliberately not overridden: the base class returns the
 * `--default-list-minimizer-for-kleene` flag, which makes the list minimizer swappable and lets the
 * same chunking be compared across ddmin, ProbDD, CDD, the windowed slicer, and the rest.
 */
class TopFormFlatReducer(
  reducerContext: ReducerContext,
  private val annotation: TopFormFlatLevelAnnotation,
) : AbstractSparTreeReducer(annotation, reducerContext) {
  /**
   * Reduce over a flat list of the real tokens, one node per token directly under `start`. This is
   * the shape `topformflat`/`delta` operate on: the chunker's cut points fall on sibling boundaries
   * so any chunk deletes cleanly, independent of how the real grammar would have nested the tokens.
   */
  override fun getPreferredParserFacade(): AbstractParserFacade =
    flatTokenListFacadeFor(reducerContext.configuration.canonicalParserFacade)

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.inputRepresentation.tree
    runListMinimizerOverListsOfNodes(
      needToTestEmpty = true,
      tree = tree,
      input =
        TopFormFlatChunker.computeChunks(
          tokens = tree.remainingLexerRuleNodes,
          nestingThreshold = annotation.level,
        ),
      fixpointReductionState = fixpointReductionState,
      actionsDescriptionPostfix = ContextDescription.of("$NAME_PREFIX@${annotation.level}"),
      specifiedMinimizerType = null,
    )
  }

  class TopFormFlatLevelAnnotation internal constructor(
    val level: Int,
  ) : ReducerAnnotation(
      shortName = "$NAME_PREFIX@$level",
      description = "topformflat chunking at brace-nesting level $level",
      deterministic = true,
      reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
    ) {
    init {
      require(level >= 0) {
        "Invalid nesting level $level. Must be non-negative."
      }
    }

    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(TopFormFlatReducer(reducerContext, this))

    final override fun hashCode(): Int = Objects.hashCode(this::class.java, level)

    final override fun equals(other: Any?): Boolean {
      if (other == null || other::class.java != this::class.java) {
        return false
      }
      return level == (other as TopFormFlatLevelAnnotation).level
    }
  }

  object CompositeReducerAnnotation : ReducerAnnotation(
    shortName = NAME_PREFIX,
    description = "topformflat chunking, swept over C-Reduce's brace-nesting levels",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      REDUCER_ANNOTATIONS
        .asSequence()
        .flatMap { it.create(reducerContext) }
        .toImmutableList()
  }

  companion object {
    private const val NAME_PREFIX = "topformflat"

    /** The flat-token-list facade must reuse the file's real lexer, not whatever adaptor wraps it. */
    fun flatTokenListFacadeFor(canonical: AbstractParserFacade): FlatTokenListParserFacade =
      FlatTokenListParserFacade(canonical.realLexerClass)

    /** C-Reduce's ladder (creduce/pass_lines.pm), which skips 5, 7 and 9. */
    val LEVELS: ImmutableList<Int> = ImmutableList.of(0, 1, 2, 3, 4, 6, 8, 10)

    val REDUCER_ANNOTATIONS: ImmutableList<TopFormFlatLevelAnnotation> =
      LEVELS
        .asSequence()
        .map { TopFormFlatLevelAnnotation(level = it) }
        .toImmutableList()
  }
}
