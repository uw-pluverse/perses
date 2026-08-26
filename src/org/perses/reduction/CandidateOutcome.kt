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

import com.google.common.base.MoreObjects

/**
 * What became of one candidate.
 *
 * The hierarchy splits on the candidate's *fate*, not on whether a [TestScriptVerdict] happens to
 * be at hand. Fate is the only thing a caller asks about, and a split on availability let one event
 * be reported two ways depending on which tester produced it: a synchronous tester expressed "the
 * oracle rejected this" by carrying a rejecting verdict, while the spar-tree tester expressed it by
 * carrying no verdict at all. Anything keying off the type then had to special-case the tester,
 * which is how the list-minimizer microbenchmark came to report a rejected candidate as free.
 *
 * Cost is orthogonal to fate and lives in [testScriptVerdict]: an interesting candidate can be
 * free (deleting nothing runs no script) and an uninteresting one is usually the expensive case.
 *
 * [Payload] is what a caller adopts when the candidate survives, so it exists only on [Interesting].
 * That is what lets [Uninteresting] be a `CandidateOutcome<Nothing>`: a rejection is the same
 * value whatever the payload type, so it crosses between layers that disagree about [Payload] --
 * the reducer's edit bundle and a list minimizer's own payload -- without being rebuilt.
 */
sealed interface CandidateOutcome<out Payload> {
  /** The verdict of the test script that ran, or null when no script ran and there is no cost. */
  val testScriptVerdict: TestScriptVerdict?

  fun toShortString(): String

  /** The candidate survived, and [payload] is what the caller adopts. */
  class Interesting<out Payload>(
    val payload: Payload,
    /** Null for a candidate that is interesting without a script having run. */
    override val testScriptVerdict: TestScriptVerdict? = null,
  ) : CandidateOutcome<Payload> {
    init {
      require(testScriptVerdict == null || testScriptVerdict.isInteresting) {
        "An interesting outcome carries an uninteresting verdict: $testScriptVerdict"
      }
    }

    override fun toShortString(): String = "Interesting"

    override fun toString(): String =
      MoreObjects.toStringHelper(this).add("testScriptVerdict", testScriptVerdict).toString()
  }

  /**
   * The candidate did not survive. A caller takes the same next step either way, so the split below
   * exists for the cost model: [Rejected] spent a script execution and [NotTested] did not.
   */
  sealed interface Uninteresting : CandidateOutcome<Nothing> {
    /** A script ran for this candidate and the oracle rejected it. */
    class Rejected(
      override val testScriptVerdict: TestScriptVerdict,
    ) : Uninteresting {
      init {
        require(testScriptVerdict.isNotInteresting) {
          "A rejected outcome carries an interesting verdict: $testScriptVerdict"
        }
      }

      override fun toShortString(): String = "Uninteresting"

      override fun toString(): String =
        MoreObjects.toStringHelper(this).add("testScriptVerdict", testScriptVerdict).toString()
    }

    /**
     * No script ran for this candidate, so the query cost nothing. That covers every reason the
     * answer was already settled or the work was abandoned: a cache that already held the verdict,
     * the same deletion having been tried before, a duplicate program within one batch, a cancelled
     * speculative test, and an edit that could not be built at all.
     *
     * [reason] is the label the reduction log prints, not a value anything branches on.
     */
    class NotTested(
      val reason: String,
    ) : Uninteresting {
      override val testScriptVerdict: TestScriptVerdict?
        get() = null

      override fun toShortString(): String = reason

      override fun toString(): String = MoreObjects.toStringHelper(this).addValue(reason).toString()
    }
  }
}
