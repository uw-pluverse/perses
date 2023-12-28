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
package org.perses.util.cmd

import org.perses.util.DefaultLoggingConfigurations

abstract class AbstractMain<Cmd : AbstractCommandOptions>(args: Array<String>) {
  companion object {
    init {
      DefaultLoggingConfigurations.configureLogManager("INFO")
    }
  }

  protected val commander: AbstractCommandOptions.CmdUsagePrinter

  @JvmField
  protected val cmd: Cmd

  protected abstract fun createCommandOptions(): Cmd

  fun run() {
    if (cmd.help) {
      commander.printUsage()
      return
    }
    if (cmd.verbosityFlags.listVerbosity) {
      cmd.verbosityFlags.printAllAllowedLoggingLevels()
      return
    }
    if (cmd.versionFlags.version) {
      cmd.versionFlags.printVersionInfo("perses", System.out)
      return
    }
    if (processHelpRequests() == HelpRequestProcessingDecision.EXIT) {
      return
    }
    validateCommandOptions()

    internalRun()
  }

  protected abstract fun internalRun()

  protected enum class HelpRequestProcessingDecision {
    EXIT, NO_EXIT
  }

  protected open fun processHelpRequests(): HelpRequestProcessingDecision {
    return HelpRequestProcessingDecision.NO_EXIT
  }

  protected open fun validateCommandOptions() {
    cmd.validate()
  }

  init {
    cmd = createCommandOptions()
    commander = cmd.parseArguments(javaClass.canonicalName, args)

    // This method should be called as early as possible, to avoid triggering initialization of
    // logger objects.
    cmd.verbosityFlags.adjustLoggingLevel()
  }
}
