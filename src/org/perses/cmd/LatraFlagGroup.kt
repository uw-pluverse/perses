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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.util.cmd.AbstractCommandLineFlagGroup

class LatraFlagGroup : AbstractCommandLineFlagGroup(groupName = "Latra Reducer Control") {
  @Parameter(
    names = ["--enable-latra"],
    description =
      "Enable Latra (language-specific transformations to produce " +
        "smaller reduction output).",
    arity = 1,
    order = 0,
  )
  var enableLatra = true

  @Parameter(
    names = ["--latra-fixpoint"],
    description = "Enable fixpoint mode for running Latra reducers.",
    arity = 1,
    order = 100,
  )
  var enableFixpoint = true

  @Parameter(
    names = ["--latra-transformation-list-minimizer"],
    description = "The list minimizer algorithm to reduce with the found transformations",
    arity = 1,
    order = 200,
  )
  var transformationListMinimizer = EnumListMinimizerType.WPROBDD

  override fun validate() {
  }
}
