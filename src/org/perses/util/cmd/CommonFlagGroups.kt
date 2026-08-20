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
package org.perses.util.cmd

import com.beust.jcommander.Parameter
import com.beust.jcommander.converters.PathConverter
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.absolute

class OutputOnlyFlagGroup : AbstractCommandLineFlagGroup(groupName = "Output") {
  @Parameter(
    names = ["--output"],
    description = "output file",
    required = true,
    converter = PathConverter::class,
  )
  var outputFile: Path? = null

  override fun validate() {
    requireNotNull(outputFile)
  }
}

class InputOnlyFlagGroup : AbstractCommandLineFlagGroup(groupName = "Input") {
  @Parameter(
    names = ["--input"],
    description = "input file",
    required = true,
    converter = PathConverter::class,
  )
  var inputFile: Path? = null

  override fun validate() {
    requireNotNull(inputFile) { "input file must be specified" }
    inputFile!!.let { inputFile ->
      require(Files.isRegularFile(inputFile)) {
        """input file does not exist: $inputFile.
        |
        |The absolute path is ${inputFile.absolute()}
        |${org.perses.util.Util.listFilesInFolder(inputFile.parent)}
        """.trimMargin()
      }
    }
  }
}

class HelpFlagGroup : AbstractCommandLineFlagGroup(groupName = "Help") {
  @Parameter(
    names = ["-h", "--help"],
    description = "print help message",
    help = true,
  )
  var help: Boolean = false

  override fun validate() {
  }
}

class OutputOnlyCommandOptions : AbstractCommandOptions() {
  val flags = registerFlags(OutputOnlyFlagGroup())
}

class InputOnlyCommandOptions : AbstractCommandOptions() {
  val flags = registerFlags(InputOnlyFlagGroup())
}

class InputOutputOnlyCommandOptions : AbstractCommandOptions() {
  val inputFlags = registerFlags(InputOnlyFlagGroup())
  val outputFlags = registerFlags(OutputOnlyFlagGroup())
}
