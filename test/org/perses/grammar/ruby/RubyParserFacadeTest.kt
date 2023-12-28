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
package org.perses.grammar.ruby

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.util.removeWhitespaces

@RunWith(JUnit4::class)
class RubyParserFacadeTest {

  private val facade = PnfRubyParserFacade()

  @Test
  fun testSimpleProgram() {
    val program = """
      puts "Start"
      var=1+2
      puts "End"

    """.trimIndent()
    testProgram(program)
  }

  @Test
  fun testParsingFunction() {
    val funcProgram = """
        def say_hello(name)
          var = "Hello," + name
            return var
        end
        var = say_hello "Name"
        var = say_hello("Name")
        puts say_hello "Name"
  
    """.trimIndent()
    testProgram(funcProgram)
  }

  @Test
  fun testNestedProgram() {
    val nestedProgram = """
        puts ("Start")
        var=(1+2)*(2+3)
        var=(1)+(-2)
        puts ("End")
  
    """.trimIndent()

    testProgram(nestedProgram)
  }

  private fun testProgram(program: String) {
    val origParseTree = facade.parseString(program)
    val origTokens = TestUtility.extractTokenTexts(origParseTree.tree)
    assertThat(origTokens.joinToString(separator = ""))
      .isEqualTo(
        program.splitToSequence('\n')
          .map { it.removeWhitespaces() }
          .joinToString(separator = "\n"),
      )
  }
}
