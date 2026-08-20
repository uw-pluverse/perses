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
package org.perses.analyzer.sizetrend

import com.beust.jcommander.Parameter
import com.beust.jcommander.converters.PathConverter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import java.nio.file.Files
import java.nio.file.Path

class SizeTrendCmdOptions : AbstractCommandOptions() {
  @JvmField
  val inputFlags = registerFlags(InputFlagGroup())

  class InputFlagGroup : AbstractCommandLineFlagGroup(groupName = "Input") {
    @Parameter(
      description = "CSV files to plot",
      required = true,
      converter = PathConverter::class,
    )
    var inputFiles: MutableList<Path> = mutableListOf()

    override fun validate() {
      require(inputFiles.isNotEmpty()) {
        "At least one input file or directory must be specified."
      }
      inputFiles.forEach { path ->
        require(Files.exists(path)) { "Input does not exist: $path" }
      }
    }
  }
}
