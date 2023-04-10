/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.program.LanguageKind
import java.nio.file.Path
import kotlin.io.path.name

/**
 * This is the internal configuration for Perses reducer.
 *
 * TODO: refactor this to a AutoValue class, or use the BUILDER pattern.
 */
class ReductionConfiguration(
  languageKind: LanguageKind,
  val statisticsFile: Path?,
  val progressDumpFile: Path?,
  val fixpointReduction: Boolean,
  val enableTestScriptExecutionCaching: Boolean,
  val useRealDeltaDebugger: Boolean,
  val numOfReductionThreads: Int,
  parserFacadeFactory: AbstractParserFacadeFactory,
  val persesNodeReducerConfig: PersesNodeReducerConfiguration,
) {
  /** The parser facade.  */
  val parserFacade: AbstractParserFacade

  // TODO: convert the return type to File?
  val testScriptStatisticsFile: Path?
    get() = if (statisticsFile == null) {
      null
    } else {
      statisticsFile.parent.resolve("testscript-" + statisticsFile.name)
//      File(statisticsFile.parentFile, "testscript-" + statisticsFile.name)
    }

  fun dumpConfiguration(): String {
    val builder = StringBuilder()
    for (field in ReductionConfiguration::class.java.declaredFields) {
      builder.append(field.name).append('=').append(field[this]).append('\n')
    }
    return builder.toString()
  }

  init {

    require(numOfReductionThreads > 0) {
      "The number of reduction threads should be positive: $numOfReductionThreads"
    }
    parserFacade = parserFacadeFactory.createParserFacade(languageKind)
  }

  class PersesNodeReducerConfiguration(
    val maxEditCountForRegularRuleNode: Int,
    val maxBfsDepthForRegularRuleNode: Int,
    val stopAtFirstCompatibleChildren: Boolean,
  ) {
    init {
      require(maxEditCountForRegularRuleNode > 0)
      require(maxBfsDepthForRegularRuleNode > 0)
    }
  }
}
