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
package org.perses.analyzer.differential

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.perses.antlr.RuleType
import org.perses.listener.DifferentialEvents
import org.perses.reduction.TestScriptVerdict
import org.perses.util.shell.ExitCode

class EventDiffStatisticsTest {
  @Test
  fun testCalculateStatistics() {
    val edit1 =
      DifferentialEvents.Edit(
        contextualDescription = "Interesting edit",
        structureDescription = "",
        propertyTestResult = TestScriptVerdict(ExitCode.ZERO, 100),
        successfullyDeletedCode = "",
        deletedTokenCount = 0,
        startPersesTimeSeconds = 101,
      )
    val edit2 =
      DifferentialEvents.Edit(
        contextualDescription = "Not interesting edit",
        structureDescription = "",
        propertyTestResult = TestScriptVerdict(ExitCode.ONE, 200),
        successfullyDeletedCode = "",
        deletedTokenCount = 3,
        startPersesTimeSeconds = 105,
      )
    val edit3 =
      DifferentialEvents.Edit(
        contextualDescription = "Another interesting edit",
        structureDescription = "",
        propertyTestResult = TestScriptVerdict(ExitCode.ZERO, 150),
        successfullyDeletedCode = "",
        deletedTokenCount = 0,
        startPersesTimeSeconds = 125,
      )

    val event1 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 100,
        endPersesTimeSeconds = 110,
        nodeId = 1,
        ruleName = "Rule1",
        ruleType = RuleType.KLEENE_PLUS,
        childrenBeforeReduction = ImmutableList.of(),
        deletedTokenCount = 50,
        childrenAfterReduction = ImmutableList.of(),
        editsTested = ImmutableList.of(edit1, edit2),
      )

    val event2 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 120,
        endPersesTimeSeconds = 135,
        nodeId = 2,
        ruleName = "Rule2",
        ruleType = null,
        childrenBeforeReduction = ImmutableList.of(),
        deletedTokenCount = 30,
        childrenAfterReduction = ImmutableList.of(),
        editsTested = ImmutableList.of(edit3),
      )

    val events = listOf(event1, event2)
    val stats = EventDiffStatistics.calculate(events)

    assertThat(stats.totalTokensDeleted).isEqualTo(80)
    assertThat(stats.totalTimeSeconds).isEqualTo(35) // 135 - 100
    assertThat(stats.totalReductionSpeed).isWithin(0.01).of(2.28) // 80 / 35
    assertThat(stats.totalEditTimeStats.minTimeMs).isEqualTo(100)
    assertThat(stats.totalEditTimeStats.maxTimeMs).isEqualTo(200)
    assertThat(stats.totalEditTimeStats.avgTimeMs).isEqualTo(150)
    assertThat(stats.totalEditTimeStats.medianTimeMs).isEqualTo(150)
    assertThat(stats.totalEditTimeStats.stdDevMs).isWithin(0.01).of(40.82)
    assertThat(stats.totalSuccessRate).isWithin(0.01).of(0.66)
    assertThat(stats.totalTokensPerInterestedEdit).isEqualTo(40.0)
    assertThat(stats.totalTimePerInterestingEdit).isEqualTo(125.0)
    assertThat(stats.totalTimePerUninterestingEdit).isEqualTo(200.0)

    assertThat(stats.iterationStats).hasSize(1)
    val iter1 = stats.iterationStats[0]
    assertThat(iter1.iteration).isEqualTo(1)
    assertThat(iter1.totalEvents).isEqualTo(2)
    assertThat(iter1.totalTokensDeleted).isEqualTo(80)
    assertThat(iter1.totalEdits).isEqualTo(3)
    assertThat(iter1.interestingEdits).isEqualTo(2)
    assertThat(iter1.totalTimeSeconds).isEqualTo(35)
    assertThat(iter1.reductionSpeed).isWithin(0.01).of(2.28)
    assertThat(iter1.editTimeStats.avgTimeMs).isEqualTo(150)
    assertThat(iter1.successRate).isWithin(0.01).of(0.66)
    assertThat(iter1.tokensPerInterestedEdit).isEqualTo(40.0)
    assertThat(iter1.timePerInterestingEdit).isEqualTo(125.0)
    assertThat(iter1.timePerUninterestingEdit).isEqualTo(200.0)
  }

  @Test
  fun testIterationGrouping() {
    val edit1 =
      DifferentialEvents.Edit(
        contextualDescription = "",
        structureDescription = "",
        propertyTestResult = TestScriptVerdict(ExitCode.ZERO, 50),
        successfullyDeletedCode = "",
        deletedTokenCount = 0,
        startPersesTimeSeconds = 12,
      )
    val edit2 =
      DifferentialEvents.Edit(
        contextualDescription = "",
        structureDescription = "",
        propertyTestResult = TestScriptVerdict(ExitCode.ZERO, 150),
        successfullyDeletedCode = "",
        deletedTokenCount = 0,
        startPersesTimeSeconds = 35,
      )

    val event1 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 10,
        endPersesTimeSeconds = 20,
        nodeId = 1,
        ruleName = "R1",
        ruleType = null,
        childrenBeforeReduction = ImmutableList.of(),
        deletedTokenCount = 10,
        childrenAfterReduction = ImmutableList.of(),
        editsTested = ImmutableList.of(edit1),
      )
    val event2 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 2,
        startPersesTimeSeconds = 30,
        endPersesTimeSeconds = 40,
        nodeId = 2,
        ruleName = "R2",
        ruleType = null,
        childrenBeforeReduction = ImmutableList.of(),
        deletedTokenCount = 20,
        childrenAfterReduction = ImmutableList.of(),
        editsTested = ImmutableList.of(edit2),
      )

    val stats = EventDiffStatistics.calculate(listOf(event1, event2))
    assertThat(stats.iterationStats).hasSize(2)

    val iter1 = stats.iterationStats.find { it.iteration == 1 }!!
    assertThat(iter1.totalEvents).isEqualTo(1)
    assertThat(iter1.totalTokensDeleted).isEqualTo(10)
    assertThat(iter1.totalTimeSeconds).isEqualTo(10)
    assertThat(iter1.reductionSpeed).isWithin(0.01).of(1.0)
    assertThat(iter1.editTimeStats.avgTimeMs).isEqualTo(50)
    assertThat(iter1.successRate).isEqualTo(1.0)
    assertThat(iter1.timePerInterestingEdit).isEqualTo(50.0)

    val iter2 = stats.iterationStats.find { it.iteration == 2 }!!
    assertThat(iter2.totalEvents).isEqualTo(1)
    assertThat(iter2.totalTokensDeleted).isEqualTo(20)
    assertThat(iter2.totalTimeSeconds).isEqualTo(10)
    assertThat(iter2.reductionSpeed).isWithin(0.01).of(2.0)
    assertThat(iter2.editTimeStats.avgTimeMs).isEqualTo(150)
    assertThat(iter2.successRate).isEqualTo(1.0)
    assertThat(iter2.timePerInterestingEdit).isEqualTo(150.0)
  }

  @Test
  fun testEmptyEvents() {
    val stats = EventDiffStatistics.calculate(emptyList())
    assertThat(stats.totalTokensDeleted).isEqualTo(0)
    assertThat(stats.totalTimeSeconds).isEqualTo(0)
    assertThat(stats.totalEvents).isEqualTo(0)
    assertThat(stats.totalEdits).isEqualTo(0)
    assertThat(stats.interestingEdits).isEqualTo(0)
    assertThat(stats.totalReductionSpeed).isWithin(0.01).of(0.0)
    assertThat(stats.totalEditTimeStats.avgTimeMs).isEqualTo(0)
    assertThat(stats.totalSuccessRate).isEqualTo(0.0)
    assertThat(stats.iterationStats).isEmpty()
  }
}
