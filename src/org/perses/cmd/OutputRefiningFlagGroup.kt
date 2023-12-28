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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.shell.ShellCommandOnPath

class OutputRefiningFlagGroup : AbstractCommandLineFlagGroup(
  groupName = "Output Refining Control",
) {
  @Parameter(
    names = ["--call-formatter"],
    description = "call a formatter on the final result",
    arity = 1,
    order = 0,
  )
  var callFormatter = false

  @Parameter(
    names = ["--format-cmd"],
    description = "the command to format the reduced source file",
    order = 100,
  )
  var formatCmd = ""

  @Parameter(
    names = ["--call-creduce"],
    description = "call C-Reduce when Perses is done.",
    arity = 1,
    order = 200,
  )
  var callCReduce = false

  @Parameter(
    names = ["--creduce-cmd"],
    description = "the C-Reduce command name or path",
    order = 300,
  )
  var creduceCmd = "creduce"

  override fun validate() {
    if (callCReduce) {
      ShellCommandOnPath.normalizeAndCheckExecutability(creduceCmd)
    }
    check(formatCmd.isBlank()) {
      "Does not support customized format command yet. $formatCmd"
    }
  }
}
