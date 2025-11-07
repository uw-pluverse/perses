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
package org.perses.reduction.scheduler

import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.AtomicReducerStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.FixpointLoopStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.IfProgressedThenStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.SequenceDef

@RunWith(JUnit4::class)
class ReducerSchedulerTest {
  @Test
  fun test() {
    val plan =
      FixpointLoopStepDef(
        body =
          SequenceDef(
            reducers =
              listOf(
                AtomicReducerStepDef(reducer = "reducer1"),
                AtomicReducerStepDef(reducer = "reducer2"),
                IfProgressedThenStepDef(
                  condition =
                    FixpointLoopStepDef(
                      body = AtomicReducerStepDef(reducer = "main"),
                      condition = "16",
                    ),
                  then =
                    FixpointLoopStepDef(
                      body = AtomicReducerStepDef("reducer-then"),
                      condition = "20",
                    ),
                ),
              ),
          ),
        condition = "smaller",
      )
    val copy = AbstractExecutionPlanStepDef.fromYamlString(plan.toYamlString())
    Truth.assertThat(plan.toYamlString()).isEqualTo(copy.toYamlString())
  }
}
