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
package org.perses.grammar.adhoc

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import java.nio.file.Path

class CommandOptions : AbstractCommandOptions() {

  val compulsoryFlags = registerFlags(GrammarFlagGroup())

  @JvmField
  val outputFlags = registerFlags(OutputFlagGroup())

  fun computeAdhocGrammarConfiguration() =
    compulsoryFlags.createAdhocGrammarConfiguration()
}

class OutputFlagGroup : AbstractCommandLineFlagGroup(groupName = "Output") {

  @Parameter(
    names = ["--output"],
    description = "The path to save the generated JAR file. " +
      "Note that you should not use this flag if you want to install a new language for Perses.",
    required = false,
    hidden = true,
  )
  var output: Path? = null

  @Parameter(
    names = ["--print-language-kind-yaml-example"],
    description = "Print an example of a language kind",
    required = false,
    help = true,
  )
  var printLanguageKindExample = false

  override fun validate() {
  }
}

private object FlagOrder {
  const val COMPULSORY = 0
  const val HELP = 8000
}
