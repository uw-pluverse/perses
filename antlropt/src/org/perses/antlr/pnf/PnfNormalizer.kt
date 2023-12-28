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

import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.util.Util
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.readText
import kotlin.io.path.writeText

class PnfNormalizer(
  source: Path,
  lexer: Path?,
  private val startRuleName: String,
  private val outputFile: Path,
) {
  init {
    require(Files.isRegularFile(source)) {
      "source file is not valid"
    }
    require(lexer == null || Files.isRegularFile(lexer))
  }

  private val sourceAntlrFileContent = source.readText()

  private val origGrammar =
    PersesAstBuilder.loadGrammarFromString(sourceAntlrFileContent)
      .copyWithNewName(Util.extractGrammarNameFromGrammarFileName(outputFile.toString()))

  private val lexerGrammar = lexer?.let {
    PersesAstBuilder.loadGrammarFromFile(it).also { grammar ->
      check(grammar.grammarName + ".g4" == it.fileName.toString())
    }
  }

  fun run() {
    val passes = PnfPassManager()
    val processedGrammar = passes.process(
      GrammarPair(parserGrammar = origGrammar, lexerGrammar = lexerGrammar),
      startRuleName,
    ).parserGrammar!!
    val output = processedGrammar.sourceCode
    outputFile.writeText(output)
  }
}
