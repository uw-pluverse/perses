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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.EditTestPayload
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.TestScriptExecResult
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Util
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

class LineBasedConcurrentTokenSlicer(
  reducerContext: ReducerContext,
  reducerAnnotation: LineBasedConcurrentTokenSlicerAnnotation,
) : AbstractConcurrentTokenSlicer(
    reducerAnnotation,
    reducerContext,
  ) {
  override fun createSequenceOfIndependentSlicingTasks(
    tokenSlicingGranularity: Int,
    tree: SparTree,
  ): Sequence<ListOfIndependentSlicingTasks> {
    val lines = computeLines(tree.remainingLexerRuleNodes)
    return sequenceOf(
      ListOfIndependentSlicingTasks(
        Util
          .slideReverseIfSlideable(
            lines,
            slidingWindowSize = tokenSlicingGranularity,
          ).transformToImmutableList { sublist ->
            LineSlicingTask(sublist.elements, tree)
          },
      ),
    )
  }

  inner class LineSlicingTask(
    linesToDelete: ImmutableList<ImmutableList<LexerRuleSparTreeNode>>,
    tree: SparTree,
  ) : AbstractSlicingTask(
      tree,
      reducerContext,
      this@LineBasedConcurrentTokenSlicer.executorService::testProgramAsync,
    ) {
    private val initialLineCount = linesToDelete.size

    private val linesToDelete =
      ArrayList<ImmutableList<LexerRuleSparTreeNode>?>().apply {
        addAll(linesToDelete)
      }

    override fun tryAsyncRunPreconditionCheck(): Boolean {
      removeAlreadyDeletedLines()
      return linesToDelete.isNotEmpty()
    }

    private fun removeAlreadyDeletedLines() {
      var hasDeletedLines = false
      for (index in 0 until linesToDelete.size) {
        val elements = linesToDelete[index] ?: continue
        if (elements.first().isPermanentlyDeleted) {
          hasDeletedLines = true
          check(elements.all { it.isPermanentlyDeleted }) {
            """The elements on this line should be all deleted. 
                  |
                  |${elements.map { element -> element.printTreeStructure() }}
            """.trimMargin()
          }
          linesToDelete[index] = null
        }
      }
      if (hasDeletedLines) {
        val oldSize = linesToDelete.size
        Util.removeNullFromList(linesToDelete)
        check(linesToDelete.size < oldSize)
      }
    }

    override fun createNodeDeletionActionSet(): NodeDeletionActionSet {
      val nodesToDelete = linesToDelete.filterNotNull().flatten().toImmutableList()
      return NodeDeletionActionSet.createByDeletingNodes(
        nodesToDelete,
        actionsDescription = "line slicer@$initialLineCount",
      )
    }

    override fun analyzeResultAndGetBest(futureResult: TestScriptExecResult<EditTestPayload>) =
      this@LineBasedConcurrentTokenSlicer
        .analyzeOneTestFutureAndGetBest(futureResult)
  }

  object CompositeReducerAnnotation : ReducerAnnotation(
    shortName = NAME_PREFIX,
    description = "",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      REDUCER_ANNOTATIONS
        .asSequence()
        .flatMap { it.create(reducerContext) }
        .toImmutableList()
  }

  companion object {
    private const val NAME_PREFIX = "line_based_concurrent_token_slicer"

    fun computeLines(
      tokens: ImmutableList<LexerRuleSparTreeNode>,
    ): ImmutableList<ImmutableList<LexerRuleSparTreeNode>> =
      Util.mergeContinuousElementsIntoRegions(tokens) { a, b ->
        a.token
          .asAntlrToken()
          .position.line ==
          b.token
            .asAntlrToken()
            .position.line
      }

    val REDUCER_ANNOTATIONS =
      IntRange(start = 1, endInclusive = 14)
        .asSequence()
        .map { LineBasedConcurrentTokenSlicerAnnotation(granularity = it) }
        .toImmutableList()
  }

  class LineBasedConcurrentTokenSlicerAnnotation internal constructor(
    granularity: Int,
  ) : AbstractTokenSlicerAnnotation(
      NAME_PREFIX,
      granularity,
      description = "line-based concurrent token slicer",
    ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      ImmutableList.of(LineBasedConcurrentTokenSlicer(reducerContext, this))
  }
}
