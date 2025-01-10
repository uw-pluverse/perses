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

import org.perses.util.DefaultLoggingConfigurations
import org.perses.util.cmd.CommandLineProcessor.HelpRequestProcessingDecision

abstract class AbstractMain<Cmd : AbstractCommandOptions>(
  protected val cmd: Cmd,
) {
  companion object {
    init {
      DefaultLoggingConfigurations.configureLogManager("INFO")
    }
  }

  fun run() {
    if (processOtherHelpRequests() == HelpRequestProcessingDecision.EXIT) {
      return
    }
    validateCommandOptions()
    internalRun()
  }

  protected abstract fun internalRun()

  protected open fun processOtherHelpRequests(): HelpRequestProcessingDecision {
    return HelpRequestProcessingDecision.NO_EXIT
  }

  protected open fun validateCommandOptions() {
    cmd.validate()
  }

  init {
    // This method should be called as early as possible, to avoid triggering initialization of
    // logger objects.
    cmd.verbosityFlags.adjustLoggingLevel()
  }
}
