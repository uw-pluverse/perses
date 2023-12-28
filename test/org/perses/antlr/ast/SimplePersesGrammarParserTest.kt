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
package org.perses.antlr.ast

import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.AntlrGrammarParser
import java.nio.file.Paths
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class SimplePersesGrammarParserTest {

  @Test
  fun test() {
    val string =
      Paths.get("src/org/perses/grammar/sysverilog/SV3_1aParser.g4").readText()

    val grammar = PersesAstBuilder(
      AntlrGrammarParser.parseRawGrammarASTFromString(string),
    ).grammar // does not crash.
    println(grammar.sourceCode)
  }
}
