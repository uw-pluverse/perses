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
package org.perses.grammar.json

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.util.removeWhitespaces

@RunWith(JUnit4::class)
class JsonParserTest {
  val facade = JsonParserFacade()

  @Test
  fun testParsingFunction() {
    /* This program is obtained from
     * https://github.com/antlr/grammars-v4/blob/master/json/examples/example1.json
     */
    val funcProgram = """
        {
            "glossary": {
                "title": "example glossary",
                "GlossDiv": {
                    "title": "S",
                    "GlossList": {
                        "GlossEntry": {
                            "ID": "SGML",
                            "SortAs": "SGML",
                            "GlossTerm": "Standard Generalized Markup Language",
                            "Acronym": "SGML",
                            "Abbrev": "ISO 8879:1986",
                            "GlossDef": {
                                "para": "A meta-markup language, used to create markup languages such as DocBook.",
                                "GlossSeeAlso": ["GML", "XML"]
                            },
                            "GlossSee": "markup"
                        }
                    }
                }
            }
        }
    """.removeWhitespaces().toString()
    testProgram(funcProgram)
  }

  private fun testProgram(program: String) {
    val origParseTree = facade.parseString(program)
    val origTokens = TestUtility.extractTokenTexts(origParseTree.tree)
    assertThat(origTokens.joinToString(separator = ""))
      .isEqualTo(
        program.splitToSequence('\n')
          .map { it.removeWhitespaces() }
          .joinToString(separator = ""),
      )
  }
}
