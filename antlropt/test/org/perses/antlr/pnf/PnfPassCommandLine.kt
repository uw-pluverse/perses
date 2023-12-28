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
package org.perses.antlr.pnf

import com.beust.jcommander.Parameter
import com.google.common.base.Strings
import org.perses.antlr.GrammarTestingUtility.loadGrammarFromFile
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.writeText

class PnfPassCommandLine(
  args: Array<String>,
) : AbstractMain<PnfPassCommandLine.CommandOptions>(args) {
  override fun createCommandOptions(): CommandOptions {
    return CommandOptions()
  }

  override fun internalRun() {
    val parserGramamr = loadGrammarFromFile(cmd.flags.input!!)

    @Suppress("UNCHECKED_CAST")
    val passClass = Class.forName(cmd.flags.pass) as Class<AbstractPnfPass>
    val startRuleName = cmd.flags.startRuleName
    val pass = if (Strings.isNullOrEmpty(startRuleName)) {
      passClass.getConstructor().newInstance()
    } else {
      passClass.getConstructor(String::class.java).newInstance(startRuleName)
    }
    val grammar = GrammarPair(parserGramamr, lexerGrammar = null)
    val output = pass.processGrammar(grammar)
    output.parserGrammar?.let {
      cmd.flags.output!!.writeText(it.sourceCode)
    }
  }

  class CommandOptions : AbstractCommandOptions() {
    val flags = registerFlags(RequiredFlagGroup())

    class RequiredFlagGroup : AbstractCommandLineFlagGroup(groupName = "PNF Pass Control") {
      @Parameter(names = ["--input"], required = true, description = "Input.")
      var input: Path? = null

      @Parameter(names = ["--output"], required = true, description = "Output.")
      var output: Path? = null

      @Parameter(names = ["--pass"], required = true, description = "A PNF pass.")
      var pass: String? = null

      @Parameter(
        names = ["--start-rule-name"],
        description = "The name of the start rule in the input",
      )
      var startRuleName: String? = null
      override fun validate() {
        require(Files.isRegularFile(input!!))
        require(pass != null && pass!!.trim().isNotEmpty())
        require(startRuleName == null || startRuleName!!.trim().isNotEmpty())
      }
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      PnfPassCommandLine(args).run()
    }
  }
}
