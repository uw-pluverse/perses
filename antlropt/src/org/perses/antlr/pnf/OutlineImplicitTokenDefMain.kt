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
import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.PersesAstBuilder.Companion.loadGrammarFromFile
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.cmd.AbstractMain
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.writeText

class OutlineImplicitTokenDefMain(
  args: Array<String>,
) : AbstractMain<OutlineImplicitTokenDefMain.CommandFlags>(args) {

  override fun createCommandOptions(): CommandFlags {
    return CommandFlags()
  }

  override fun internalRun() {
    val parserGrammar = loadGrammarFromFile(cmd.parserFile!!)
    val lexerGrammar = cmd.lexerFile?.let { loadGrammarFromFile(it) }
    val original = GrammarPair(parserGrammar, lexerGrammar)
    val passManager = PnfPassManager(
      repetitivePassCreator = { ImmutableList.of(OutlineImplicitTokenDefPass()) },
      finalizingPassCreator = { ImmutableList.of() },
    )
    val after = passManager.process(original, cmd.startRuleName.trim())
    after.parserGrammar!!.let {
      cmd.parserOutput!!.writeText(it.sourceCode)
    }
    after.lexerGrammar?.let {
      cmd.lexerOutput!!.writeText(it.sourceCode)
    }
  }

  class CommandFlags : AbstractCommandOptions() {

    @Parameter(
      names = ["--start_rule_name"],
      required = true,
      description = "The start rule of the grammar.",
    )
    var startRuleName: String = ""

    @Parameter(
      names = ["--parser-input"],
      required = true,
      description = "The parser file to process.",
    )
    var parserFile: Path? = null

    @Parameter(
      names = ["--lexer-input"],
      required = false,
      description = "The lexer file to process.",
    )
    var lexerFile: Path? = null

    @Parameter(
      names = ["--parser-output"],
      required = true,
      description = "The file to save the processed parser grammar.",
    )
    var parserOutput: Path? = null

    @Parameter(
      names = ["--lexer-output"],
      required = false,
      description = "The file to save the processed lexer grammar.",
    )
    var lexerOutput: Path? = null

    override fun validateExtra() {
      super.validateExtra()
      check(parserFile != null)
      check(Files.isRegularFile(parserFile!!))
      check(parserOutput != null)
      lexerFile?.let {
        check(Files.isRegularFile(it))
        check(lexerOutput != null)
      }
      check(startRuleName.isNotBlank())
    }
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      OutlineImplicitTokenDefMain(args).run()
    }
  }
}
