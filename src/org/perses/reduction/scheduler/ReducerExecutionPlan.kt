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
package org.perses.reduction.scheduler

import com.google.common.collect.ImmutableList
import org.perses.reduction.ReducerAnnotation
import org.perses.util.toImmutableList

class ReducerExecutionPlan(
  val steps: AbstractExecutionPlanStep,
) {
  companion object {
    fun makeSureToWrapWithFixpoint(body: AbstractExecutionPlanStep): AbstractExecutionPlanStep {
      if (body is FixpointLoopStep) {
        return body
      }
      return fixpoint(AbstractCondition.ContinueOnSmallSize.INSTANCE) { body }
    }

    fun concatenate(steps: List<AbstractExecutionPlanStep>): AbstractExecutionPlanStep =
      when (steps.size) {
        0 -> error("Execution plan must have at least one step")
        1 -> steps.single()
        else -> UnconditionalSequentialSteps(reducers = steps.toImmutableList())
      }

    fun concatenate(vararg steps: AbstractExecutionPlanStep?): AbstractExecutionPlanStep =
      concatenate(steps.filterNotNull())

    fun fixpoint(
      continueCondition: AbstractCondition = AbstractCondition.ContinueOnSmallSize.INSTANCE,
      body: () -> AbstractExecutionPlanStep,
    ): FixpointLoopStep = FixpointLoopStep(body = body(), continueCondition = continueCondition)

    fun ifProgressed(
      condition: AbstractExecutionPlanStep,
      then: () -> AbstractExecutionPlanStep,
    ): IfProgressedThenStep =
      IfProgressedThenStep(
        condition = condition,
        then = then(),
      )

    fun ifProgressed(
      condition: ReducerAnnotation,
      then: () -> AbstractExecutionPlanStep,
    ): IfProgressedThenStep = ifProgressed(atomic(condition), then)

    fun atomic(reducer: ReducerAnnotation): AtomicReducerStep = AtomicReducerStep(reducer)
  }

  sealed class AbstractExecutionPlanStep {
    abstract fun toDefinition(): ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef
  }

  class FixpointLoopStep(
    val body: AbstractExecutionPlanStep,
    val continueCondition: AbstractCondition,
  ) : AbstractExecutionPlanStep() {
    override fun toDefinition(): ExecutionPlanYamlDefinition.FixpointLoopStepDef =
      ExecutionPlanYamlDefinition.FixpointLoopStepDef(
        body = body.toDefinition(),
        condition =
          when (continueCondition) {
            is AbstractCondition.ContinueOnSmallSize -> {
              "smaller"
            }

            is AbstractCondition.ContinueOnChange -> {
              continueCondition.maxCountOfAllowedChanges
                .toString()
            }
          },
      )
  }

  class AtomicReducerStep(
    val reducer: ReducerAnnotation,
  ) : AbstractExecutionPlanStep() {
    override fun toDefinition(): ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef =
      ExecutionPlanYamlDefinition.AtomicReducerStepDef(
        reducer = reducer.shortName,
      )
  }

  class IfProgressedThenStep(
    val condition: AbstractExecutionPlanStep,
    val then: AbstractExecutionPlanStep,
  ) : AbstractExecutionPlanStep() {
    override fun toDefinition(): ExecutionPlanYamlDefinition.IfProgressedThenStepDef =
      ExecutionPlanYamlDefinition.IfProgressedThenStepDef(
        condition = condition.toDefinition(),
        then = then.toDefinition(),
      )
  }

  class UnconditionalSequentialSteps(
    val reducers: ImmutableList<AbstractExecutionPlanStep>,
  ) : AbstractExecutionPlanStep() {
    init {
      require(reducers.size > 1) { reducers }
    }

    override fun toDefinition(): ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef =
      ExecutionPlanYamlDefinition.SequenceDef(
        reducers = reducers.map { it.toDefinition() },
      )
  }

  sealed class AbstractCondition {
    /**
     * Intentionally not using object but a regular class for YAML serialization.
     */
    class ContinueOnSmallSize : AbstractCondition() {
      companion object {
        val INSTANCE = ContinueOnSmallSize()
      }
    }

    class ContinueOnChange(
      val maxCountOfAllowedChanges: Int,
    ) : AbstractCondition()
  }
}
