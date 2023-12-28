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
import org.perses.antlr.ast.PersesAstBuilder.Companion.loadGrammarFromFile
import org.perses.antlr.util.Util.extractGrammarNameFromGrammarFileName
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import kotlin.io.path.writeText

class Main(args: Array<String>) : AbstractMain<Main.Options>(args) {
  override fun createCommandOptions() = Options()

  override fun internalRun() {
    val parserGrammar = loadGrammarFromFile(cmd.sourceFile!!)
      .copyWithNewName(extractGrammarNameFromGrammarFileName(cmd.outputFile!!))
    val lexerGrammar = cmd.lexerFile?.let {
      loadGrammarFromFile(it)
    }
    val origGrammar = GrammarPair(parserGrammar, lexerGrammar)
    val passes = PnfPassManager()
    val processedGrammar = passes.process(origGrammar, cmd.startRuleName!!)
    processedGrammar.parserGrammar?.let {
      Paths.get(cmd.outputFile!!).writeText(it.sourceCode)
    }
  }

  class Options : AbstractCommandOptions() {
    @Parameter(
      names = ["--source"],
      required = true,
      description = "The Antlr grammar file for processing.",
    )
    var sourceFile: Path? = null

    @Parameter(names = ["--lexer"], description = "The lexer definition for the parser grammar.")
    var lexerFile: Path? = null

    @Parameter(
      names = ["--output"],
      required = true,
      description = "The file to save the processed grammar.",
    )
    var outputFile: String? = null

    @Parameter(
      names = ["--start_rule_name"],
      required = true,
      description = "The name of the start rule in the source grammar.",
    )
    var startRuleName: String? = null

    override fun validateExtra() {
      check(sourceFile != null)
      check(Files.isRegularFile(sourceFile!!))
      check(outputFile != null)
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      Main(args).run()
    }
  }
}
