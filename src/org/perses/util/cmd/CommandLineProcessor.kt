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
package org.perses.util.cmd

import com.google.common.flogger.FluentLogger
import org.perses.util.ktInfo

class CommandLineProcessor<Cmd : AbstractCommandOptions>(
  cmdCreator: () -> Cmd,
  val programName: String,
  args: Array<String>,
) {
  val cmd = cmdCreator()
  private val commander: AbstractCommandOptions.CmdUsagePrinter = cmd.parseArguments(
    programName,
    args,
  )

  fun process(): HelpRequestProcessingDecision {
    adjustLoggingLevel()
    logger.ktInfo {
      val keyValuePairs = commander.getLongestFlagNameToValueMap()
        .map { it.key + " " + '"' + it.value + '"' }
        .joinToString(separator = " ")
      "The command-line options are: $keyValuePairs"
    }
    return printCommonHelpMessageIfRequested()
  }

  private fun adjustLoggingLevel() {
    cmd.verbosityFlags.adjustLoggingLevel()
  }

  private fun printCommonHelpMessageIfRequested(): HelpRequestProcessingDecision {
    when {
      cmd.help -> {
        commander.printUsage()
        return HelpRequestProcessingDecision.EXIT
      }
      cmd.verbosityFlags.listVerbosity -> {
        cmd.verbosityFlags.printAllAllowedLoggingLevels()
        return HelpRequestProcessingDecision.EXIT
      }
      cmd.versionFlags.version -> {
        cmd.versionFlags.printVersionInfo(programName, System.out)
        return HelpRequestProcessingDecision.EXIT
      }
      else -> {
        return HelpRequestProcessingDecision.NO_EXIT
      }
    }
  }

  enum class HelpRequestProcessingDecision {
    EXIT, NO_EXIT
  }

  companion object {
    val logger = FluentLogger.forEnclosingClass()
  }
}
