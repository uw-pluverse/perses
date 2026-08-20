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
package org.perses.listener

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.PropertyTestResult
import org.perses.util.Util
import java.nio.file.Path
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class DifferentialEventsTest {
  val tempDir = Util.createTempDirForObject(this)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testSerializationAndDeserialization() {
    val tempFile: Path = tempDir.resolve("differential-events.yaml")
    val edits =
      ImmutableList.of(
        DifferentialEvents.Edit(
          contextualDescription = "context",
          structureDescription = "structure",
          propertyTestResult = PropertyTestResult.INTERESTING_RESULT,
          successfullyDeletedCode = "deleted code",
          deletedTokenCount = 1,
          startPersesTimeSeconds = 123,
        ),
      )
    val event =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 0,
        endPersesTimeSeconds = 1,
        nodeId = 1,
        ruleName = "rule",
        ruleType = null,
        childrenBeforeReduction = ImmutableList.of(2, 3),
        deletedTokenCount = 5,
        childrenAfterReduction = ImmutableList.of(4),
        editsTested = edits,
      )
    val events = ImmutableList.of(event)

    DifferentialEvents.writeToYamlFile(events, tempFile)
    val readEvents = DifferentialEvents.readFromYamlFile(tempFile)

    assertThat(readEvents).isEqualTo(events)
  }
}
