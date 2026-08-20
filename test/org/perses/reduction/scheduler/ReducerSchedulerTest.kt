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
import com.google.common.truth.Truth
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.ProgramSize
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.ReducerResult
import org.perses.reduction.StatsOfFilesBeingReduced
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.AbstractExecutionPlanStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.AtomicReducerStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.FixpointLoopStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.IfProgressedThenStepDef
import org.perses.reduction.scheduler.ExecutionPlanYamlDefinition.SequenceDef
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractCondition.ContinueOnChange
import org.perses.reduction.scheduler.ReducerExecutionPlan.AbstractCondition.ContinueOnSmallSize
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.atomic
import org.perses.reduction.scheduler.ReducerExecutionPlan.Companion.fixpoint
import org.perses.reduction.scheduler.ReducerScheduler.FixpointDecision
import org.perses.util.hashing.EnumShaAlgorithm

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
                      body = AtomicReducerStepDef(reducer = "reducer-then"),
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

  @Test
  fun testAnUnchangedProgramStopsTheFixpoint() {
    val decision =
      decisionFor(
        before = stats(tokenCount = 114, characterCount = 505, fileContent = "same"),
        after = stats(tokenCount = 114, characterCount = 505, fileContent = "same"),
      )
    assertThat(decision).isEqualTo(FixpointDecision.STOP_NO_CHANGE_IN_RESULT)
    assertThat(decision.continueFixpoint).isFalse()
  }

  @Test
  fun testFewerTokensRefreshesTheNonDeletionBudget() {
    val decision =
      decisionFor(
        before = stats(tokenCount = 114, characterCount = 505, fileContent = "v0"),
        after = stats(tokenCount = 113, characterCount = 505, fileContent = "v1"),
      )
    assertThat(decision).isEqualTo(FixpointDecision.CONTINUE_FEWER_TOKENS)
    assertThat(decision.refreshesNonDeletionBudget).isTrue()
  }

  @Test
  fun testFewerCharactersAtTheSameTokenCountDoesNotRefreshTheNonDeletionBudget() {
    val decision =
      decisionFor(
        before = stats(tokenCount = 114, characterCount = 505, fileContent = "v0"),
        after = stats(tokenCount = 114, characterCount = 496, fileContent = "v1"),
      )
    // Smaller, so a ContinueOnSmallSize loop keeps going -- but the token count did not move, so
    // the budget a ContinueOnChange loop terminates on must not be handed back.
    assertThat(decision).isEqualTo(FixpointDecision.CONTINUE_FEWER_CHARACTERS_ONLY)
    assertThat(decision.continueFixpoint).isTrue()
    assertThat(decision.isSmaller).isTrue()
    assertThat(decision.refreshesNonDeletionBudget).isFalse()
  }

  @Test
  fun testAChangeThatShrinksNothingConsumesTheBudget() {
    val decision =
      decisionFor(
        before = stats(tokenCount = 114, characterCount = 496, fileContent = "v0"),
        after = stats(tokenCount = 114, characterCount = 505, fileContent = "v1"),
      )
    assertThat(decision).isEqualTo(FixpointDecision.CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER)
    assertThat(decision.refreshesNonDeletionBudget).isFalse()
  }

  /**
   * The scheduler orders snapshots by [ProgramSize.compareTo], which ranks the non-blank character
   * count ahead of the total. A rewrite that lengthens the code but drops more whitespace is
   * therefore not smaller -- while the old projection, which compared the total character count
   * alone, called it smaller and disagreed with the ordering used to pick the reduction result.
   */
  @Test
  fun testGainingNonBlankCharactersIsNotSmallerEvenWhenTheTotalShrinks() {
    val decision =
      decisionFor(
        before =
          stats(
            tokenCount = 114,
            characterCount = 505,
            fileContent = "v0",
            nonBlankCharacterCount = 400,
          ),
        after =
          stats(
            tokenCount = 114,
            characterCount = 500,
            fileContent = "v1",
            nonBlankCharacterCount = 410,
          ),
      )
    assertThat(decision).isEqualTo(FixpointDecision.CONTINUE_CHANGE_IN_RESULT_BUT_NOT_SMALLER)
    assertThat(decision.isSmaller).isFalse()
    assertThat(decision.refreshesNonDeletionBudget).isFalse()
  }

  @Test
  fun testOnlyATokenDecreaseRefreshesTheNonDeletionBudget() {
    assertThat(FixpointDecision.entries.filter { it.refreshesNonDeletionBudget })
      .containsExactly(FixpointDecision.CONTINUE_FEWER_TOKENS)
  }

  /**
   * The shape of https://github.com/chengniansun/perses-private/issues/1049: Vulcan's identifier and
   * subtree replacement hold the token count fixed and move the character count both ways, so a
   * ContinueOnChange loop over them sees an endless run of iterations that shrink characters only.
   * None of them may refresh the budget, or the loop never reaches its limit.
   */
  @Test
  fun testTokenNeutralCharacterOscillationExhaustsTheNonDeletionBudget() {
    val limit = 10
    val trace =
      (0..100).map {
        stats(
          tokenCount = 114,
          characterCount = if (it % 2 == 0) 505 else 496,
          fileContent = "v$it",
        )
      }
    var countOfNonDeletions = 0
    for ((before, after) in trace.zipWithNext()) {
      val decision = decisionFor(before = before, after = after)
      assertThat(decision.continueFixpoint).isTrue()
      assertThat(decision.refreshesNonDeletionBudget).isFalse()
      if (++countOfNonDeletions >= limit) {
        break
      }
    }
    assertThat(countOfNonDeletions).isEqualTo(limit)
  }

  @Test
  fun testTheLoopStopsWhenTheProgramStopsChanging() {
    val iterations =
      runFixpointLoop(
        continueCondition = ContinueOnChange(maxCountOfAllowedChanges = LIMIT),
        trace =
          listOf(
            stats(tokenCount = 114, characterCount = 505, fileContent = "v0"),
            stats(tokenCount = 114, characterCount = 505, fileContent = "v0"),
          ),
      )
    assertThat(iterations).isEqualTo(1)
  }

  /**
   * The loop half of https://github.com/chengniansun/perses-private/issues/1049. Every iteration
   * holds the token count and moves the character count, half of them downwards, so before the fix
   * every other iteration handed the budget back and the loop never reached its limit. The scripted
   * trace is finite, so a loop that fails to terminate fails the test instead of hanging it.
   */
  @Test
  fun testATokenNeutralCharacterOscillationExhaustsTheBudgetAndStopsTheLoop() {
    val iterations =
      runFixpointLoop(
        continueCondition = ContinueOnChange(maxCountOfAllowedChanges = LIMIT),
        trace =
          (0..(LIMIT * 3)).map {
            stats(
              tokenCount = 114,
              characterCount = if (it % 2 == 0) 505 else 496,
              fileContent = "v$it",
            )
          },
      )
    assertThat(iterations).isEqualTo(LIMIT)
  }

  @Test
  fun testEveryTokenDecreaseRefreshesTheBudgetSoTheLoopOutlivesTheLimit() {
    val tokenCounts = (0..(LIMIT * 2)).map { 200 - it }
    val iterations =
      runFixpointLoop(
        continueCondition = ContinueOnChange(maxCountOfAllowedChanges = LIMIT),
        trace =
          tokenCounts.map {
            stats(tokenCount = it, characterCount = 505, fileContent = "v$it")
          } +
            stats(
              tokenCount = tokenCounts.last(),
              characterCount = 505,
              fileContent = "v${tokenCounts.last()}",
            ),
      )
    // Every iteration hands the budget back, so the limit never bites; the loop runs until the
    // trace stops shrinking and then stops on the unchanged program.
    assertThat(iterations).isEqualTo(tokenCounts.size)
  }

  @Test
  fun testAContinueOnSmallSizeLoopStopsAsSoonAsTheProgramIsNotSmaller() {
    val iterations =
      runFixpointLoop(
        continueCondition = ContinueOnSmallSize.INSTANCE,
        trace =
          listOf(
            stats(tokenCount = 114, characterCount = 505, fileContent = "v0"),
            stats(tokenCount = 114, characterCount = 505, fileContent = "v1"),
          ),
      )
    assertThat(iterations).isEqualTo(1)
  }

  @Test
  fun testAContinueOnSmallSizeLoopKeepsRunningWhileOnlyCharactersShrink() {
    val iterations =
      runFixpointLoop(
        continueCondition = ContinueOnSmallSize.INSTANCE,
        trace =
          listOf(
            stats(tokenCount = 114, characterCount = 505, fileContent = "v0"),
            stats(tokenCount = 114, characterCount = 496, fileContent = "v1"),
            stats(tokenCount = 114, characterCount = 490, fileContent = "v2"),
            stats(tokenCount = 114, characterCount = 490, fileContent = "v2"),
          ),
      )
    assertThat(iterations).isEqualTo(3)
  }

  /**
   * Runs one fixpoint loop whose body is a single reducer, feeding it [trace] one snapshot per
   * reducer call, and returns how many times the body ran.
   */
  private fun runFixpointLoop(
    continueCondition: ReducerExecutionPlan.AbstractCondition,
    trace: List<StatsOfFilesBeingReduced>,
  ): Int {
    var callCount = 0
    var statsIndex = 0
    ReducerScheduler(
      reducerExecutionPlan =
        ReducerExecutionPlan(
          steps = fixpoint(continueCondition = continueCondition) { atomic(FAKE_REDUCER) },
        ),
      createReducers = { ImmutableList.of("the-only-reducer") },
      reducerAnnotationOf = { FAKE_REDUCER },
      computeStatistics = {
        check(statsIndex < trace.size) {
          "The fixpoint loop ran past the end of the scripted trace, i.e. it did not terminate."
        }
        trace[statsIndex++]
      },
      reducerRunner = {
        ++callCount
        ReducerResult.Skipped
      },
    ).runAndGetGlobalMinimalProgramSize()
    return callCount
  }

  private fun decisionFor(
    before: StatsOfFilesBeingReduced,
    after: StatsOfFilesBeingReduced,
  ) = ReducerScheduler.computeFixpointDecision(before = before, after = after)

  private fun stats(
    tokenCount: Int,
    characterCount: Int,
    fileContent: String,
    nonBlankCharacterCount: Int = characterCount,
  ) = StatsOfFilesBeingReduced(
    size =
      ProgramSize(
        payload = Unit,
        canonicalTokenCount = tokenCount,
        surrogateTokenCount = tokenCount,
        totalCharacterCount = characterCount,
        nonBlankCharacterCount = nonBlankCharacterCount,
      ),
    fileContents =
      ImmutableList.of(
        StatsOfFilesBeingReduced.FileNameAndContentDigestPair(
          fileName = "t.c",
          contentDigest = EnumShaAlgorithm.SHA256.createFromString(string = fileContent),
        ),
      ),
  )

  companion object {
    private const val LIMIT = 10

    /** Never asked to create anything: the scheduler under test is given the reducers directly. */
    private val FAKE_REDUCER =
      object : ReducerAnnotation(
        shortName = "fake",
        description = "fake",
        deterministic = true,
        reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
      ) {
        override fun create(
          reducerContext: ReducerContext,
        ): ImmutableList<AbstractSparTreeReducer> = error("Unused: see createReducers.")
      }
  }
}
