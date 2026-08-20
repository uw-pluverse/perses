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
package org.perses.analyzer.differential

import com.beust.jcommander.Parameter
import com.beust.jcommander.converters.PathConverter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import java.nio.file.Files
import java.nio.file.Path

class DifferentialAnalyzerCmdOptions : AbstractCommandOptions() {
  @JvmField
  val inputFlags = registerFlags(InputFlagGroup())

  class InputFlagGroup : AbstractCommandLineFlagGroup(groupName = "Input") {
    @Parameter(
      description = "the two input files to compare",
      required = false,
      converter = PathConverter::class,
    )
    var inputFiles: MutableList<Path> = mutableListOf()

    val input1: Path
      get() = inputFiles[0]

    val input2: Path
      get() = inputFiles[1]

    override fun validate() {
      if (inputFiles.isEmpty()) {
        return
      }
      require(inputFiles.size == 2) {
        "Exactly two input files must be specified, but ${inputFiles.size} were provided: $inputFiles"
      }
      require(Files.isRegularFile(input1)) { "input1 is not a regular file: $input1" }
      require(Files.isRegularFile(input2)) { "input2 is not a regular file: $input2" }
    }
  }
}
