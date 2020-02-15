/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

import com.google.common.annotations.VisibleForTesting
import com.google.common.base.Joiner
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParserFacadeFactory
import org.perses.program.SourceFile
import org.perses.reduction.IPartitionReductionPolicy.MultiNodePartitionReductionPolicy
import org.perses.reduction.IPartitionReductionPolicy.SingleNodePartitionReductionPolicy
import org.perses.util.Util
import java.io.File
import java.time.LocalDateTime
import java.util.*

/**
 * This is the internal configuration for Perses reducer.
 *
 *
 * TODO: refactor this to a AutoValue class, or use the BUILDER pattern.
 */
class ReductionConfiguration(
    /** The working directory of the reduction.  */
    val workingFolder: File,
    testScriptFile: File,
    fileToReduce: File,
    val bestResultFile: File,
    private val statisticsFile: File?,
    private val progressDumpFile: File?,
    val keepOriginalCodeFormat: Boolean,
    val fixpointReduction: Boolean,
    val enableTestScriptExecutionCaching: Boolean,
    val useRealDeltaDebugger: Boolean,
    val maxReductionLevel: Int,
    val numOfReductionThreads: Int,
    val multiNodePartitionReductionPolicy: MultiNodePartitionReductionPolicy,
    val singleNodePartitionReductionPolicy: SingleNodePartitionReductionPolicy) {
  /** The test script for reduction  */
  val testScript: SourceFile
  /** The file to reduce  */
  val fileToReduce: SourceFile
  /** The parser facade.  */
  val parserFacade: AbstractParserFacade
  /** This file is used to store the best result of reduction.  */
  val tempRootFolder: File

  fun getStatisticsFile(): Optional<File> {
    return Optional.ofNullable(statisticsFile)
  }

  fun getProgressDumpFile(): Optional<File> {
    return Optional.ofNullable(progressDumpFile)
  }

  val testScriptStatisticsFile: Optional<File>
    get() = if (statisticsFile == null) {
      Optional.empty()
    } else Optional.of(
        File(statisticsFile.parentFile, "testscript-" + statisticsFile.name))

  fun getFixpointIterationResultFile(fixpointIteration: Int): File {
    val bestResultFile = bestResultFile
    return File(
        tempRootFolder, bestResultFile.name + "_fixpoint_iteration_" + fixpointIteration)
  }

  fun dumpConfiguration(): String {
    val builder = StringBuilder()
    try {
      for (field in ReductionConfiguration::class.java.declaredFields) {
        builder.append(field.name).append('=').append(field[this]).append('\n')
      }
    } catch (e: IllegalAccessException) {
      throw AssertionError(e)
    }
    return builder.toString()
  }

  companion object {
    private const val PERSES_TEMP_ROOT_PREFIX = "PersesTempRoot"
    @JvmStatic
    @VisibleForTesting
    fun getTempRootFolderName(
        fileNameForReduction: String?, testScriptName: String?, time: LocalDateTime?): String {
      return Joiner.on('_')
          .join(
              PERSES_TEMP_ROOT_PREFIX,
              fileNameForReduction,
              testScriptName,
              Util.formatDateForFileName(time))
    }
  }

  init {
    require(workingFolder.exists()) {
      "The working folder does not exist: $workingFolder"
    }
    require(workingFolder.isDirectory) {
      "The working folder is not a directory: $workingFolder"
    }
    require(maxReductionLevel > 0) {
      "The max reduction level should be positive: $maxReductionLevel"
    }
    require(numOfReductionThreads > 0) {
      "The number of reduction threads should be positive: $numOfReductionThreads"
    }
    testScript = SourceFile.createFromPath(testScriptFile)
    this.fileToReduce = SourceFile.createFromPath(fileToReduce)
    parserFacade = ParserFacadeFactory.SINGLETON.createParserFacade(this.fileToReduce.languageKind)

    tempRootFolder = File(
        workingFolder,
        getTempRootFolderName(
            fileToReduce.name, testScriptFile.name, LocalDateTime.now()))
  }


}