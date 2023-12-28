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

class VulcanFlagGroup : AbstractCommandLineFlagGroup(groupName = "Vulcan Reducer Control") {
  @Parameter(
    names = ["--enable-vulcan"],
    description = "Enable vulcan (using auxiliary reducers to help produce " +
      "smaller reduction output).",
    arity = 1,
    order = 0,
  )
  var enableVulcan = false

  @Parameter(
    names = ["--non-deletion-iteration-limit"],
    description = "The maximum number of continuous non-deletion iterations allowed.",
    order = 1,
  )
  var nonDeletionIterationLimit = 10

  @Parameter(
    names = ["--window-size"],
    description = "The window size used to perform local exhaustive pattern reduction.",
    order = 2,
  )
  var windowSize = 4

  @Parameter(
    names = ["--vulcan-fixpoint"],
    description = "Enable vulcan fixpoint iteratively using auxiliary reducers until no " +
      "progress can be made",
    arity = 1,
    order = 3,
  )
  var vulcanFixpoint = false

  override fun validate() {
    check(nonDeletionIterationLimit > 0) {
      "--non-deletion-iteration-limit must be non-negative."
    }
    check(windowSize > 1) {
      "--window-size must be larger than 1."
    }
  }
}
