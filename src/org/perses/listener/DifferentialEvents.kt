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

import com.fasterxml.jackson.core.type.TypeReference
import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.reduction.TestScriptVerdict
import org.perses.util.Serialization
import java.nio.file.Path

object DifferentialEvents {
  data class NodeReductionEvent(
    val fixpointIteration: Int,
    val startPersesTimeSeconds: Int,
    val endPersesTimeSeconds: Int,
    val nodeId: Int,
    val ruleName: String,
    val ruleType: RuleType?,
    val childrenBeforeReduction: ImmutableList<Int>,
    val deletedTokenCount: Int,
    val childrenAfterReduction: ImmutableList<Int>,
    val editsTested: ImmutableList<Edit>,
  )

  data class Edit(
    val contextualDescription: String,
    val structureDescription: String,
    val propertyTestResult: TestScriptVerdict,
    val successfullyDeletedCode: String,
    val deletedTokenCount: Int,
    val startPersesTimeSeconds: Int,
  )

  fun writeToYamlFile(
    events: ImmutableList<NodeReductionEvent>,
    file: Path,
  ) {
    Serialization.toYamlFile(events, file)
  }

  fun readFromYamlFile(file: Path): ImmutableList<NodeReductionEvent> =
    Serialization.fromYamlFile(
      file,
      object : TypeReference<ImmutableList<NodeReductionEvent>>() {},
    )
}
