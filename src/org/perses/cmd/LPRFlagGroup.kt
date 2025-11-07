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
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import java.nio.file.Path
import kotlin.io.path.exists
import kotlin.io.path.isExecutable

class LPRFlagGroup : AbstractCommandLineFlagGroup(groupName = "LPR Reducer Control") {
  @Parameter(
    names = ["--enable-lpr"],
    description = "Enable LPR (LLM-based transformations to improve reduction results).",
    arity = 1,
    order = 0,
  )
  var enableLPR = false

  @Parameter(
    names = ["--lpr-fixpoint"],
    description =
      "Enable lpr fixpoint. Everytime a transformation makes progress, " +
        "go to the next transformation.",
    arity = 1,
    order = 1,
  )
  var lprFixpoint = false

  @Parameter(
    names = ["--llm-client-script"],
    description = "The script to invoke LLM.",
    arity = 1,
    order = 2,
  )
  var llmClientPath: Path? = null

  override fun validate() {
    llmClientPath?.let {
      check(it.exists()) { "The specified LLM client script does not exist: $it" }
      check(it.isExecutable()) { "The specified LLM client script is not executable: $it" }
    }
  }
}
