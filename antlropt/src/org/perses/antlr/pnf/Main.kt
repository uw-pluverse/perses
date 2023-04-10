/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.beust.jcommander.JCommander
import com.beust.jcommander.Parameter
import org.perses.antlr.ast.PersesAstBuilder.Companion.loadGrammarFromFile
import org.perses.antlr.ast.PersesAstBuilder.Companion.loadGrammarFromString
import org.perses.antlr.util.Util.extractGrammarNameFromGrammarFileName
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths
import kotlin.io.path.readText
import kotlin.io.path.writeText

object Main {

  @JvmStatic
  fun main(args: Array<String>) {
    val cmd = Options()
    val commander = JCommander(cmd)
    commander.parse(*args)
    if (cmd.help) {
      commander.usage()
      return
    }
    val sourceFile = Paths.get(cmd.sourceFile)
    require(Files.exists(sourceFile)) { sourceFile }
    require(Files.isRegularFile(sourceFile)) { sourceFile }
    val sourceAntlrFileContent = sourceFile.readText()
    val origGrammar = loadGrammarFromString(sourceAntlrFileContent)
      .copyWithNewName(extractGrammarNameFromGrammarFileName(cmd.outputFile!!))
    val lexerGrammar = cmd.lexerFile?.let {
      loadGrammarFromFile(it)
    }
    val passes = PnfPassManager()
    val processedGrammar = passes.process(origGrammar, cmd.startRuleName!!, lexerGrammar)
    val output = processedGrammar.sourceCode
    Paths.get(cmd.outputFile).writeText(output)
  }

  class Options {
    @Parameter(
      names = ["--source"],
      required = true,
      description = "The Antlr grammar file for processing.",
    )
    var sourceFile: String? = null

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

    @Parameter(names = ["--help"], description = "print help message", help = true)
    var help = false
  }
}
