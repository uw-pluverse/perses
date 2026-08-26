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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict
import java.util.concurrent.Callable
import java.util.concurrent.Executors

@RunWith(JUnit4::class)
class SpeculativeGreedyDriverTest {
  private fun wrap(values: List<Int>): ImmutableList<ElementWrapper<Int>> =
    ImmutableList.copyOf(values.mapIndexed { index, value -> ElementWrapper(index, value, "") })

  /**
   * A single forward pass over [original], yielding each still-present element as a one-element
   * deletion. It never restarts (onCommitted is a no-op), so it relies on the driver's respawn to
   * retry the followers of a committed candidate.
   */
  private class SingleDeletionCursor(
    private val original: ImmutableList<ElementWrapper<Int>>,
    private val currentBest: () -> ImmutableList<ElementWrapper<Int>>,
  ) : DeletionCandidateCursor<Int> {
    private var index = 0

    override fun next(): Candidate<Int>? {
      while (index < original.size) {
        val element = original[index]
        ++index
        if (!element.deleted) {
          return Candidate.DeletionsFromOriginal(
            original = currentBest(),
            deleted_ = ImmutableList.of(element),
          )
        }
      }
      return null
    }

    override fun onCommitted() {
    }
  }

  private data class Run(
    val finalBest: List<Int>,
    val committedOrder: List<Int>,
  )

  private fun run(
    input: List<Int>,
    required: Set<Int>,
    concurrency: Int,
  ): Run {
    val original = wrap(input)
    var best = original
    val committed = mutableListOf<Int>()
    val pool = Executors.newFixedThreadPool(concurrency)
    try {
      val maxValue = input.max()
      SpeculativeGreedyDriver<Int, String>(
        concurrency = concurrency,
        currentBest = { best },
        submit = { candidate ->
          val value = candidate.deletedElements.single()
          val future =
            pool.submit(
              Callable {
                // Make earlier-submitted (smaller) values finish last, so completion order differs
                // from submission order; the committed sequence must still be submission-ordered.
                Thread.sleep(5L * (maxValue - value))
                if (value !in required) {
                  CandidateOutcome.Interesting<String>(
                    payload = "",
                    testScriptVerdict = TestScriptVerdict.INTERESTING,
                  )
                } else {
                  CandidateOutcome.Uninteresting.Rejected(
                    testScriptVerdict = TestScriptVerdict.NON_INTERESTING,
                  )
                }
              },
            )
          object : PropertyTestHandle<Int, String> {
            override fun get(): CandidateOutcome<String> = future.get()

            override fun requestToCancel() {
              future.cancel(true)
            }
          }
        },
        commit = { candidate, _ ->
          candidate.deletedWrappers.forEach { it.markAsDeleted() }
          committed.add(candidate.deletedElements.single())
          best = candidate.candidateWrappers
        },
      ).run(SingleDeletionCursor(original) { best })
      return Run(best.map { it.element }, committed)
    } finally {
      pool.shutdownNow()
    }
  }

  @Test
  fun resultAndCommitOrderAreIndependentOfConcurrency() {
    val input = (1..8).toList()
    val required = setOf(2, 5, 7)

    val baseline = run(input, required, concurrency = 1)
    assertThat(baseline.finalBest).containsExactly(2, 5, 7).inOrder()
    assertThat(baseline.committedOrder).containsExactly(1, 3, 4, 6, 8).inOrder()

    for (concurrency in listOf(2, 3, 4, 8, 16)) {
      val result = run(input, required, concurrency)
      assertThat(result.finalBest).containsExactlyElementsIn(baseline.finalBest).inOrder()
      assertThat(result.committedOrder).containsExactlyElementsIn(baseline.committedOrder).inOrder()
    }
  }

  @Test
  fun everythingDeletableReducesToEmpty() {
    for (concurrency in listOf(1, 4, 8)) {
      val result = run((1..6).toList(), required = emptySet(), concurrency = concurrency)
      assertThat(result.finalBest).isEmpty()
      assertThat(result.committedOrder).containsExactly(1, 2, 3, 4, 5, 6).inOrder()
    }
  }
}
