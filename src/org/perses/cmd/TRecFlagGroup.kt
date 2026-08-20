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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup

class TRecFlagGroup : AbstractCommandLineFlagGroup(groupName = "T-Rec Reducer Control") {
  @JvmField
  @Parameter(
    names = ["--enable-trec"],
    description =
      "enable T-Rec (a lexical-syntax guided fine-grained reduction process to " +
        "reduce and canonicalize each token)",
    arity = 1,
    order = 1,
  )
  var enableTRec = true

  override fun validate() {
  }
}
