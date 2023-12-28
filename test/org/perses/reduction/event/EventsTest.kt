/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.reduction.event

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import java.lang.ref.WeakReference

@RunWith(JUnit4::class)
class EventsTest {

  private val INITIAL_PROGRAM_SIZE = 3

  private val tree = TestUtility.createSparTreeFromString("int a;", LanguageC)

  private val reductionStartEvent = ReductionStartEvent(
    currentTimeMillis = System.currentTimeMillis(),
    tree = WeakReference(tree),
    programSize = INITIAL_PROGRAM_SIZE,
  )

  val firstIterationStart = reductionStartEvent.nextFixpointIteration(
    programSize = 2,
    reducerClass = ConcurrentTokenSlicer.getAnnotationForGranularity(granularity = 1),
    tree,
    TestScriptExecutorServiceStatisticsSnapshot(
      scriptExecutionNumber = 1,
      externalCacheHitNumber = 0,
    ),
  )

  val nodeReductionStartEvent = firstIterationStart.createNodeReductionStartEvent(
    currentTimeMillis = System.currentTimeMillis(),
    program = tree.programSnapshot,
    node = tree.root,
  )

  val nodeReductionEndEvent = nodeReductionStartEvent.createEndEvent(
    currentTimeMillis = System.currentTimeMillis(),
    program = tree.programSnapshot,
    remainingQueueSize = 1000,
  )

  val firstIterationEnd = firstIterationStart.createEndEvent(
    currentTimeMillis = System.currentTimeMillis(),
    programSize = 2,
    testScriptStatistics = TestScriptExecutorServiceStatisticsSnapshot(
      scriptExecutionNumber = 2,
      externalCacheHitNumber = 2,
    ),
  )

  val reductionEndEvent = reductionStartEvent.createEndEvent(
    programSize = 1,
    testScriptStatistics = TestScriptExecutorServiceStatisticsSnapshot(
      scriptExecutionNumber = 100 + 2,
      externalCacheHitNumber = 2,
    ),
  )

  @Test
  fun testReductionStartEvent() {
    assertThat(reductionStartEvent.initialProgramSize()).isEqualTo(INITIAL_PROGRAM_SIZE)
    assertThat(reductionStartEvent.programSize).isEqualTo(reductionStartEvent.initialProgramSize())
  }

  @Test
  fun testNodeReductionStartEvent() {
    assertThat(nodeReductionStartEvent.initialProgramSize()).isEqualTo(INITIAL_PROGRAM_SIZE)
  }

  @Test
  fun testNodeReductionEndEvent() {
    assertThat(nodeReductionEndEvent.initialProgramSize()).isEqualTo(INITIAL_PROGRAM_SIZE)
  }

  @Test
  fun testReductionEndEvent() {
    assertThat(reductionEndEvent.initialProgramSize()).isEqualTo(INITIAL_PROGRAM_SIZE)
    assertThat(
      reductionEndEvent.testScriptExecutorServiceStatistics.scriptExecutionNumber,
    ).isEqualTo(102)
    assertThat(reductionEndEvent.startEvent).isSameInstanceAs(reductionStartEvent)
  }

  @Test
  fun testFixpointIterationStartEvent() {
    assertThat(firstIterationStart.initialProgramSize()).isEqualTo(INITIAL_PROGRAM_SIZE)
  }

  @Test
  fun testFixpointIterationEndEvent() {
    assertThat(firstIterationEnd.initialProgramSize()).isEqualTo(INITIAL_PROGRAM_SIZE)
  }
}
