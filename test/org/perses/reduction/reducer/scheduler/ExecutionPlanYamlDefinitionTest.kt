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
package org.perses.reduction.reducer.scheduler

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.AtomicReducerStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.FixpointLoopStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.IfProgressedThenStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.SequenceDef

@RunWith(JUnit4::class)
class ExecutionPlanYamlDefinitionTest {
  @Test
  fun testPrettyPrintAtomc() {
    assertThat(AtomicReducerStepDef("test").prettyPrint()).isEqualTo("test")
  }

  @Test
  fun testPrettyPrintSequence() {
    val def = SequenceDef(listOf(AtomicReducerStepDef("a"), AtomicReducerStepDef(("b"))))
    assertThat(def.prettyPrint()).isEqualTo(
      """a
        |b
      """.trimMargin(),
    )
  }

  @Test
  fun testPrettyPrintIf() {
    val def =
      IfProgressedThenStepDef(
        condition = AtomicReducerStepDef("condition"),
        then = AtomicReducerStepDef("body"),
      )
    assertThat(def.prettyPrint()).isEqualTo(
      """if (condition) {
        |    body
        |}
      """.trimMargin(),
    )
  }

  @Test
  fun testPrettyPrintFixpoint() {
    val def =
      FixpointLoopStepDef(
        body =
          IfProgressedThenStepDef(
            condition = AtomicReducerStepDef("if_condition"),
            then = AtomicReducerStepDef("if_body"),
          ),
        condition = "smaller",
      )
    assertThat(def.prettyPrint()).isEqualTo(
      """fixpoint (smaller) {
        |    if (if_condition) {
        |        if_body
        |    }
        |}
      """.trimMargin(),
    )
  }

  @Test
  fun testPrettyPrintSequenceAndFixpoint() {
    val step1 =
      FixpointLoopStepDef(
        body = AtomicReducerStepDef("a"),
        condition = "smaller",
      )
    val step2 =
      FixpointLoopStepDef(
        body =
          SequenceDef(
            listOf(
              IfProgressedThenStepDef(
                condition = AtomicReducerStepDef("b"),
                then =
                  FixpointLoopStepDef(
                    body = AtomicReducerStepDef("c"),
                    condition = "smaller",
                  ),
              ),
              IfProgressedThenStepDef(
                condition = AtomicReducerStepDef("d"),
                then =
                  FixpointLoopStepDef(
                    condition = "smaller",
                    body = AtomicReducerStepDef("f"),
                  ),
              ),
            ),
          ),
        condition = "smaller",
      )
    val def = SequenceDef(listOf(step1, step2))
    assertThat(def.prettyPrint()).isEqualTo(
      """fixpoint (smaller) {
        |    a
        |}
        |fixpoint (smaller) {
        |    if (b) {
        |        fixpoint (smaller) {
        |            c
        |        }
        |    }
        |    if (d) {
        |        fixpoint (smaller) {
        |            f
        |        }
        |    }
        |}
      """.trimMargin(),
    )
  }
}
