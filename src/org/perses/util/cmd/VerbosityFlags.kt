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
package org.perses.util.cmd

import com.beust.jcommander.Parameter
import org.perses.util.DefaultLoggingConfigurations

class VerbosityFlags : ICommandLineFlags {
  @JvmField
  @Parameter(
    names = ["--verbosity"],
    description = "verbosity of logging",
    order = CommonCmdOptionGroupOrder.VERBOSITY_CONTROL + 10
  )
  var verbosity = "INFO"

  @JvmField
  @Parameter(
    names = ["--list-verbosity-levels"],
    description = "list all verbosity levels",
    help = true,
    order = CommonCmdOptionGroupOrder.VERBOSITY_CONTROL + 20
  )
  var listVerbosity = false

  override fun validate() {
    val allowedLoggingLevels = DefaultLoggingConfigurations.ALLOWED_LOGGING_LEVELS

    check(allowedLoggingLevels.contains(verbosity)) {
      "The specified versobity $verbosity is not valid. Valid ones are $allowedLoggingLevels"
    }
  }

  fun printAllAllowedLoggingLevels() {
    DefaultLoggingConfigurations.printAllAllowedLoggingLevels()
  }

  fun adjustLoggingLevel() {
    validate()
    DefaultLoggingConfigurations.configureLogManager(verbosity.uppercase())
  }
}
