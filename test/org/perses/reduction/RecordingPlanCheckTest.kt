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
import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.AbstractProgramReductionDriver.Companion.checkRecordingPlanRunsOnlyTheMainReducer
import org.perses.reduction.scheduler.ReducerExecutionPlan
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.atomic
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.concatenate
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.fixpoint

/** RECORD mode refuses a plan with any reducer but the main one, naming the others. */
@RunWith(JUnit4::class)
class RecordingPlanCheckTest {
  @Test
  fun testThePlanOfTheMainReducerAloneIsAccepted() {
    val plan =
      ReducerExecutionPlan(
        steps = fixpoint(continueCondition = smaller()) { atomic(MAIN) },
      )
    checkRecordingPlanRunsOnlyTheMainReducer(plan, MAIN)
  }

  @Test
  fun testAnyOtherReducerIsRefusedByName() {
    val plan =
      ReducerExecutionPlan(
        steps =
          concatenate(
            atomic(OTHER),
            fixpoint(continueCondition = smaller()) { atomic(MAIN) },
            atomic(ANOTHER),
          ),
      )
    val failure =
      assertThrows(IllegalStateException::class.java) {
        checkRecordingPlanRunsOnlyTheMainReducer(plan, MAIN)
      }
    assertThat(failure).hasMessageThat().contains("[other, another]")
    assertThat(failure).hasMessageThat().contains("--enable-trec false")
  }

  private fun smaller() = ReducerExecutionPlan.AbstractCondition.ContinueOnSmallSize.INSTANCE

  companion object {
    private val MAIN = fakeReducer("main")
    private val OTHER = fakeReducer("other")
    private val ANOTHER = fakeReducer("another")

    private fun fakeReducer(name: String) =
      object : ReducerAnnotation(
        shortName = name,
        description = name,
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
        override fun create(
          reducerContext: ReducerContext,
        ): ImmutableList<AbstractSparTreeReducer> =
          error("Never created: only the plan is checked.")
      }
  }
}
