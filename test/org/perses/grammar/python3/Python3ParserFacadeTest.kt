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
package org.perses.grammar.python3

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.antlr.toTokenType
import org.perses.program.printer.PrinterRegistry

@RunWith(JUnit4::class)
class Python3ParserFacadeTest {

  private val facade = Python3ParserFacade()

  @Test
  fun test() {
    val program = """
      |
      |
      |
      |def f():
      |    pass
      |a = True
      |if a:
      |    print("%s" % a)
      |    if a:
      |        print("hello")
      |def main():
      |    pass    
    """.trimMargin()

    val origParseTree = facade.parseString(program)
    val antlrTokens = TestUtility.extractTokens(origParseTree.tree)
    assertThat(antlrTokens).isNotEmpty()
    antlrTokens.forEach {
      System.err.println(
        it.text + ": " +
          facade.metaTokenInfoDb.getTokenInfoWithType(it.type.toTokenType())?.symbolicName +
          "  @" + it.line + ":" + it.charPositionInLine,
      )
    }

    val sparTree = TestUtility.createSparTreeFromString(program, LanguagePython3)
    val tokenProgram = sparTree.programSnapshot
    val code = PrinterRegistry.printToStringInPythonFormat(tokenProgram)
    assertThat(code.trim()).isEqualTo(program.trim())
  }
}
