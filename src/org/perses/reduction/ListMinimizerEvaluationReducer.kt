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

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.microbenchmark.RecordedProgramTokenizer
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ContextDescription
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.SparTree
import org.perses.util.Interval

/**
 * Runs one list minimizer over one list that was handed to it, and nothing else.
 *
 * Every other reducer computes its own worklist from the tree; this one is given the list, because
 * the list is the thing under measurement -- it was recorded from an earlier reduction and is being
 * replayed to a possibly different minimizer.
 *
 * Being an [AbstractSparTreeReducer] is the whole point. The minimizer is driven by
 * [runListMinimizerOverListsOfNodes], so it gets the production property tester, the production
 * arguments (weights, per-minimizer knobs, concurrency) and the production listener adaptor. A
 * measurement is therefore of the minimizer *as the reducers run it*, not of a faithful copy --
 * including that each accepted best is committed to the tree, so later queries are posed against the
 * same shifting baseline they would be online.
 *
 * Not registered with [ReducerFactory]: it cannot run without a recorded list, so it must not be
 * selectable by `--alg`. Its annotation is an instance field of the evaluation driver, closing over
 * the list.
 */
class ListMinimizerEvaluationReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  /**
   * One entry per recorded element: the character ranges it covers in the recorded program.
   *
   * Ranges, not resolved nodes. [callReducer] simplifies the tree immediately before running a
   * reducer, which can replace the very nodes a caller resolved earlier -- and deleting a node that
   * is no longer in the tree changes nothing, so the minimizer would see every candidate as
   * interesting and stop after one query. Resolving here binds to the tree actually being reduced.
   */
  private val rangesPerElement: List<Iterable<Interval>>,
  private val minimizerType: EnumListMinimizerType,
  /** Receives the 1-minimality of the result, once the minimizer has produced one. */
  private val reportOneMinimality: (OneMinimalityReport) -> Unit,
) : AbstractSparTreeReducer(reducerAnnotation, reducerContext) {
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    if (rangesPerElement.isEmpty()) {
      return
    }
    val tree = fixpointReductionState.inputRepresentation.tree
    val result =
      runListMinimizerOverListsOfNodes(
        // Testing the empty list is part of what an algorithm does, so a measurement lets it. Whether
        // the originating reducer would have allowed it is a property of that reducer, not of the
        // recorded problem, and is not recorded.
        needToTestEmpty = true,
        tree = tree,
        input =
          RecordedProgramTokenizer.resolveElements(
            tree = tree,
            rangesPerElement = rangesPerElement,
          ),
        fixpointReductionState = fixpointReductionState,
        actionsDescriptionPostfix = ContextDescription.of("[evaluation]"),
        specifiedMinimizerType = minimizerType,
      )
    reportOneMinimality(measureOneMinimality(tree, result))
  }

  /**
   * How many of the kept elements could still be deleted on their own.
   *
   * A result is 1-minimal when removing any single element breaks the property. Several minimizers
   * guarantee that by construction -- ONE_BY_ONE ends by trying exactly this, and ddmin runs to
   * granularity n -- while the windowed and probabilistic ones do not, so it is the axis on which
   * their results differ in quality rather than only in cost.
   *
   * Measured after the minimizer has finished, which is also after the listener's `endReduction`:
   * these probes are the price of the *metric*, not of the algorithm, and counting them in the
   * algorithm's script total would make a thorough minimizer look expensive for being checked.
   * The query cache answers for free any deletion the run already tried and rejected.
   */
  private fun measureOneMinimality(
    tree: SparTree,
    result: ImmutableList<ImmutableList<out AbstractSparTreeNode>>,
  ): OneMinimalityReport {
    var violations = 0
    for (element in result) {
      val actionSet =
        NodeDeletionActionSet
          .Builder("one-minimality probe")
          .deleteNodes(element)
          .build()
      val outcome = testOneTreeEditAndGetOutcome(tree.createNodeDeletionEdit(actionSet))
      if (outcome is CandidateOutcome.Interesting) {
        ++violations
      }
    }
    return OneMinimalityReport(violationCount = violations)
  }

  /** The 1-minimality of one measurement's result. */
  data class OneMinimalityReport(
    /**
     * Kept elements whose removal, **on its own**, still satisfies the oracle. Zero means the
     * result is 1-minimal.
     *
     * Not a size delta, and deliberately not named as one: individually removable is not jointly
     * removable. A result keeping two alternatives, either of which alone would do, scores two
     * violations but can only shrink by one.
     */
    val violationCount: Int,
  )
}
